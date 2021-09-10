#include "MeshHelper.h"

Sprite3D* MeshHelper::createBox(
  float width, 
  float height, 
  float depth,
  unsigned int widthSegments,
  unsigned int heightSegments,
  unsigned int depthSegments)
{
  std::vector<float> vertices;
  std::vector<float> normals;
  std::vector<float> uvs;
  MeshData::IndexArray indices;

  unsigned int numberOfVertices = 0;

  auto buildPlane = [&vertices, &normals, &uvs, &indices, &numberOfVertices]( 
    char u, 
    char v,
    char w, 
    float udir, 
    float vdir, 
    float width, 
    float height, 
    float depth,
    unsigned int gridX, 
    unsigned int gridY, 
    unsigned int materialIndex ) {

			float segmentWidth = width / gridX;
			float segmentHeight = height / gridY;

			float widthHalf = width / 2;
			float heightHalf = height / 2;
			float depthHalf = depth / 2;

			unsigned int gridX1 = gridX + 1;
			unsigned int gridY1 = gridY + 1;

			unsigned int vertexCounter = 0;

			std::map<char, float> vector;

			// generate vertices, normals and uvs

			for ( unsigned int iy = 0; iy < gridY1; iy ++ ) {

				float y = iy * segmentHeight - heightHalf;

				for ( unsigned int ix = 0; ix < gridX1; ix ++ ) {

					float x = ix * segmentWidth - widthHalf;

					// set values to correct vector component

					vector[ u ] = x * udir;
					vector[ v ] = y * vdir;
					vector[ w ] = depthHalf;

					// now apply vector to vertex buffer

					vertices.push_back( vector['x'] );
          vertices.push_back( vector['y'] );
          vertices.push_back( vector['z'] );
					// set values to correct vector component

					vector[ u ] = 0;
					vector[ v ] = 0;
					vector[ w ] = depth > 0 ? 1 : - 1;

					// now apply vector to normal buffer

          normals.push_back( vector['x'] );
          normals.push_back( vector['y'] );
          normals.push_back( vector['z'] );

					// uvs

					uvs.push_back( ((float)ix) / gridX );
					uvs.push_back( 1 - ( ((float)iy) / gridY ) );

					// counters

					vertexCounter += 1;

				}

			}

			// indices

			// 1. you need three indices to draw a single face
			// 2. a single segment consists of two faces
			// 3. so we need to generate six (2*3) indices per segment

			for ( unsigned int iy = 0; iy < gridY; iy ++ ) {

				for ( unsigned int ix = 0; ix < gridX; ix ++ ) {

					unsigned int a = numberOfVertices + ix + gridX1 * iy;
					unsigned int b = numberOfVertices + ix + gridX1 * ( iy + 1 );
					unsigned int c = numberOfVertices + ( ix + 1 ) + gridX1 * ( iy + 1 );
					unsigned int d = numberOfVertices + ( ix + 1 ) + gridX1 * iy;

					// faces

					indices.push_back( a );
          indices.push_back( b );
          indices.push_back( d );
					indices.push_back( b );
          indices.push_back( c );
          indices.push_back( d );
				}

			}

			// update total number of vertices

			numberOfVertices += vertexCounter;

		};
		// build each side of the box geometry

		buildPlane( 'z', 'y', 'x', - 1, - 1, depth, height, width, depthSegments, heightSegments, 0 ); // px
		buildPlane( 'z', 'y', 'x', 1, - 1, depth, height, - width, depthSegments, heightSegments, 1 ); // nx
		buildPlane( 'x', 'z', 'y', 1, 1, width, depth, height, widthSegments, depthSegments, 2 ); // py
		buildPlane( 'x', 'z', 'y', 1, - 1, width, depth, - height, widthSegments, depthSegments, 3 ); // ny
		buildPlane( 'x', 'y', 'z', 1, - 1, width, height, depth, widthSegments, heightSegments, 4 ); // pz
		buildPlane( 'x', 'y', 'z', - 1, - 1, width, height, - depth, widthSegments, heightSegments, 5 ); // nz
    Mesh* mesh = Mesh::create(vertices, normals, uvs, indices);
		Material* mat = Sprite3DMaterial::createBuiltInMaterial(Sprite3DMaterial::MaterialType::UNLIT_NOTEX, false);
		mesh->setMaterial(mat);
		Sprite3D* sprite = Sprite3D::create();
		sprite->addMesh(mesh);
		return sprite;
}

