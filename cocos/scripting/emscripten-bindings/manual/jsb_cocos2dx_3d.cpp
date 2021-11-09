#include "scripting/emscripten-bindings/CCScriptBindings.h"
#include "scripting/emscripten-bindings/manual/jsb_cocos2dx_3d.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

bool val_to_TerrainData(const val& v, cocos2d::Terrain::TerrainData& data)
{
  data._heightMapSrc = v["heightMap"].as<std::string>();
  data._alphaMapSrc = v["alphaMap"].as<std::string>();
  data._chunkSize = v["chunkSize"].as<Size>();
  data._mapHeight = v["mapHeight"].as<float>();
  data._mapScale = v["mapScale"].as<float>();
  for(unsigned i = 0; i < v["detailMap"]["length"].as<unsigned>(); i++)
  {
    data._detailMaps[i]._detailMapSrc = v["detailMap"][i]["file"].as<std::string>();
    data._detailMaps[i]._detailMapSize = v["detailMap"][i]["size"].as<float>();
  }

  return true;
}

COCOS_BINDINGS(jsb_cocos2dx_3d) {


  value_object<AABB>("_.AABB")
    .field("min", &AABB::_min)
    .field("max", &AABB::_max)
    ;

  class_<Animation3D>("jsb.Animation3D")
    .constructor(&cc_bindings_constructor<Animation3D>, allow_raw_pointers())
    .function("initWithFile", &Animation3D::initWithFile)
    .function("init", &Animation3D::init)
    .function("getBoneCurveByName", &Animation3D::getBoneCurveByName, allow_raw_pointers())
    .function("getDuration", &Animation3D::getDuration)
    // from manual
    .class_function("create", &Animation3D::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](std::string arg0, std::string arg1){
        return Animation3D::create(arg0, arg1);
      }), allow_raw_pointers())
    // end of manual
    .property("_className",  optional_override([](const Animation3D& _) -> std::string {return "Animation3D";}))    
    ;


  class_<Animate3D, base<ActionInterval>>("jsb.Animate3D")
    .constructor(&cc_bindings_constructor<Animate3D>, allow_raw_pointers())
    .function("setKeyFrameUserInfo", &Animate3D::setKeyFrameUserInfo)
    .function("getSpeed", &Animate3D::getSpeed)
    .function("setQuality", &Animate3D::setQuality)
    .function("setWeight", &Animate3D::setWeight)
    .function("removeFromMap", &Animate3D::removeFromMap)
    .function("initWithFrames", &Animate3D::initWithFrames, allow_raw_pointers())
    .function("getOriginInterval", &Animate3D::getOriginInterval)
    .function("setSpeed", &Animate3D::setSpeed)
    .function("init", select_overload<bool(cocos2d::Animation3D*, float, float)>(&Animate3D::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Animation3D*)>(&Animate3D::init), allow_raw_pointers())
    .function("setOriginInterval", &Animate3D::setOriginInterval)
    .function("getWeight", &Animate3D::getWeight)
    .function("getQuality", &Animate3D::getQuality)
    .class_function("create", select_overload<cocos2d::Animate3D*(cocos2d::Animation3D*, float, float)>(&Animate3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Animate3D*(cocos2d::Animation3D*)>(&Animate3D::create), allow_raw_pointers())
    .class_function("getTransitionTime", &Animate3D::getTransitionTime)
    .class_function("createWithFrames", &Animate3D::createWithFrames, allow_raw_pointers())
    .class_function("createWithFrames", optional_override(
      [](cocos2d::Animation3D* arg0, int arg1, int arg2){
        return Animate3D::createWithFrames(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("setTransitionTime", &Animate3D::setTransitionTime)
    .property("_className",  optional_override([](const Animate3D& _) -> std::string {return "Animate3D";}))
    .allow_subclass<wrapper<Animate3D>>("jsb.Animate3D._extend")    
    ;


  class_<TextureCube, base<Texture2D>>("jsb.TextureCube")
    .constructor(&cc_bindings_constructor<TextureCube>, allow_raw_pointers())
    .function("reloadTexture", &TextureCube::reloadTexture)
    // from manual
    .function("setTexParameters", optional_override(
      [](TextureCube& this_, GLuint arg0, GLuint arg1, GLuint arg2, GLuint arg3){
        Texture2D::TexParams param = { arg0, arg1, arg2, arg3 };
        this_.setTexParameters(param);
      }))
    // end of manual
    .class_function("create", &TextureCube::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureCube& _) -> std::string {return "TextureCube";}))    
    ;


  class_<AttachNode, base<Node>>("jsb.AttachNode")
    .constructor(&cc_bindings_constructor<AttachNode>, allow_raw_pointers())
    .class_function("create", &AttachNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AttachNode& _) -> std::string {return "AttachNode";}))    
    ;


  class_<BillBoard, base<Sprite>>("jsb.BillBoard")
    .constructor(&cc_bindings_constructor<BillBoard>, allow_raw_pointers())
    .function("getMode", &BillBoard::getMode)
    .function("setMode", &BillBoard::setMode)
    .class_function("create", optional_override(
        [](const std::string& arg0, const val& arg1){
		  if (arg1.isNumber())
		  {
			return BillBoard::create(arg0, arg1.as<cocos2d::BillBoard::Mode>());
		  } else 
		  {
			return BillBoard::create(arg0, arg1.as<Rect>());
		  }
        }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](const val& arg0){
      if (!arg0.isString())
      {
        return BillBoard::create(arg0.as<cocos2d::BillBoard::Mode>());
      } else 
      {
        return BillBoard::create(arg0.as<std::string>());
      }
      }), allow_raw_pointers())
    .class_function("create", optional_override(
        [](){
            return BillBoard::create();
        }), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::BillBoard*(const std::string&, const cocos2d::Rect&, cocos2d::BillBoard::Mode)>(&BillBoard::create), allow_raw_pointers())
    .class_function("createWithTexture", &BillBoard::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return BillBoard::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const BillBoard& _) -> std::string {return "BillBoard";}))
    .allow_subclass<wrapper<BillBoard>>("jsb.BillBoard._extend")    
    ;


  class_<Mesh>("jsb.Mesh")
    .constructor(&cc_bindings_constructor<Mesh>, allow_raw_pointers())
    .function("getSkin", &Mesh::getSkin, allow_raw_pointers())
    .function("getMaterial", &Mesh::getMaterial, allow_raw_pointers())
    .function("getVertexSizeInBytes", &Mesh::getVertexSizeInBytes)
    .function("setMaterial", &Mesh::setMaterial, allow_raw_pointers())
    .function("getName", &Mesh::getName)
    .function("getIndexFormat", &Mesh::getIndexFormat)
    .function("getGLProgramState", &Mesh::getGLProgramState, allow_raw_pointers())
    .function("getVertexBuffer", &Mesh::getVertexBuffer)
    .function("calculateAABB", &Mesh::calculateAABB)
    .function("hasVertexAttrib", &Mesh::hasVertexAttrib)
    .function("getBlendFunc", &Mesh::getBlendFunc)
    .function("getMeshIndexData", &Mesh::getMeshIndexData, allow_raw_pointers())
    .function("setName", &Mesh::setName)
    .function("getIndexCount", &Mesh::getIndexCount)
    .function("setMeshIndexData", &Mesh::setMeshIndexData, allow_raw_pointers())
    .function("getMeshVertexAttribCount", &Mesh::getMeshVertexAttribCount)
    .function("setBlendFunc", &Mesh::setBlendFunc)
    .function("setForce2DQueue", &Mesh::setForce2DQueue)
    .function("getPrimitiveType", &Mesh::getPrimitiveType)
    .function("setSkin", &Mesh::setSkin, allow_raw_pointers())
    .function("isVisible", &Mesh::isVisible)
    .function("getIndexBuffer", &Mesh::getIndexBuffer)
    .function("setGLProgramState", &Mesh::setGLProgramState, allow_raw_pointers())
    .function("setVisible", &Mesh::setVisible)
    // from manual
    .function("getMeshVertexAttribute", &Mesh::getMeshVertexAttribute)
    // end of manual
    .property("_className",  optional_override([](const Mesh& _) -> std::string {return "Mesh";}))    
    ;


  class_<Skeleton3D>("jsb.Skeleton3D")
    .constructor(&cc_bindings_constructor<Skeleton3D>, allow_raw_pointers())
    .function("removeAllBones", &Skeleton3D::removeAllBones)
    .function("addBone", &Skeleton3D::addBone, allow_raw_pointers())
    .function("getBoneByName", &Skeleton3D::getBoneByName, allow_raw_pointers())
    .function("getRootBone", &Skeleton3D::getRootBone, allow_raw_pointers())
    .function("updateBoneMatrix", &Skeleton3D::updateBoneMatrix)
    .function("getBoneByIndex", &Skeleton3D::getBoneByIndex, allow_raw_pointers())
    .function("getRootCount", &Skeleton3D::getRootCount)
    .function("getBoneIndex", &Skeleton3D::getBoneIndex, allow_raw_pointers())
    .function("getBoneCount", &Skeleton3D::getBoneCount)
    .property("_className",  optional_override([](const Skeleton3D& _) -> std::string {return "Skeleton3D";}))    
    ;


  class_<Skybox, base<Node>>("jsb.Skybox")
    .constructor(&cc_bindings_constructor<Skybox>, allow_raw_pointers())
    .function("reload", &Skybox::reload)
    .function("setTexture", &Skybox::setTexture, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Skybox*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&Skybox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Skybox*()>(&Skybox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Skybox& _) -> std::string {return "Skybox";}))
    .allow_subclass<wrapper<Skybox>>("jsb.Skybox._extend")    
    ;


  class_<Sprite3D, base<Node>>("jsb.Sprite3D")
    .constructor(&cc_bindings_constructor<Sprite3D>, allow_raw_pointers())
    .function("setCullFaceEnabled", &Sprite3D::setCullFaceEnabled)
    .function("setTexture", optional_override(
      [](Sprite3D& this_, const val& arg0){
      if (arg0.isString())
      {
        return this_.setTexture(arg0.as<std::string>());
      } else 
      {
        return this_.setTexture(arg0.as<cocos2d::Texture2D*>(allow_raw_pointers()));
      }
    }))
    .function("getLightMask", &Sprite3D::getLightMask)
    .function("createAttachSprite3DNode", &Sprite3D::createAttachSprite3DNode, allow_raw_pointers())
    .function("loadFromFile", &Sprite3D::loadFromFile, allow_raw_pointers())
    .function("getMaterial", &Sprite3D::getMaterial, allow_raw_pointers())
    .function("setCullFace", &Sprite3D::setCullFace)
    .function("getMeshes", &Sprite3D::getMeshes)
    .function("addMesh", &Sprite3D::addMesh, allow_raw_pointers())
    .function("removeAllAttachNode", &Sprite3D::removeAllAttachNode)
    .function("setMaterial", select_overload<void(cocos2d::Material*, int)>(&Sprite3D::setMaterial), allow_raw_pointers())
    .function("setMaterial", select_overload<void(cocos2d::Material*)>(&Sprite3D::setMaterial), allow_raw_pointers())
    .function("getMesh", &Sprite3D::getMesh, allow_raw_pointers())
    .function("createSprite3DNode", &Sprite3D::createSprite3DNode, allow_raw_pointers())
    .function("getMeshCount", &Sprite3D::getMeshCount)
    .function("onAABBDirty", &Sprite3D::onAABBDirty)
    .function("getMeshByIndex", &Sprite3D::getMeshByIndex, allow_raw_pointers())
    .function("createNode", &Sprite3D::createNode, allow_raw_pointers())
    .function("isForceDepthWrite", &Sprite3D::isForceDepthWrite)
    .function("getBlendFunc", &Sprite3D::getBlendFunc)
    .function("getMeshIndexData", &Sprite3D::getMeshIndexData, allow_raw_pointers())
    .function("setLightMask", &Sprite3D::setLightMask)
    .function("afterAsyncLoad", &Sprite3D::afterAsyncLoad, allow_raw_pointers())
    .function("loadFromCache", &Sprite3D::loadFromCache)
    .function("initFrom", &Sprite3D::initFrom)
    .function("getAttachNode", &Sprite3D::getAttachNode, allow_raw_pointers())
    .function("initWithFile", &Sprite3D::initWithFile)
    .function("setBlendFunc", &Sprite3D::setBlendFunc)
    .function("setForce2DQueue", &Sprite3D::setForce2DQueue)
    .function("genMaterial", &Sprite3D::genMaterial)
    .function("genMaterial", optional_override(
        [](Sprite3D& this_){
        return this_.genMaterial();
      }))
    .function("removeAttachNode", &Sprite3D::removeAttachNode)
    .function("getSkeleton", &Sprite3D::getSkeleton, allow_raw_pointers())
    .function("setForceDepthWrite", &Sprite3D::setForceDepthWrite)
    .function("getMeshByName", &Sprite3D::getMeshByName, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*(const std::string&)>(&Sprite3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*()>(&Sprite3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*(const std::string&, const std::string&)>(&Sprite3D::create), allow_raw_pointers())
    // from manual
    .function("getAABB", &Sprite3D::getAABB)
    .class_function("createAsync", optional_override(
      [](const std::string &modelPath, const val& callback, const val& thisv, const val& callbackparam){
        ValHolder* valHolder = new ValHolder(callbackparam);
        auto lambda = [callback, thisv](Sprite3D* sprite3D, void* larg1) -> void{
            callback.call<void>("call", thisv, val(sprite3D), ((ValHolder*)larg1)->getVal());
            delete (ValHolder*)larg1;
        };
        Sprite3D::createAsync(modelPath, lambda, valHolder);
      }))
    .class_function("createAsync", optional_override(
      [](const std::string &modelPath, const std::string &texturePath, const val& callback, const val& thisv, const val& callbackparam){
        ValHolder* valHolder = new ValHolder(callbackparam);
        auto lambda = [callback, thisv](Sprite3D* sprite3D, void* larg1) -> void{
            callback.call<void>("call", thisv, val(sprite3D), ((ValHolder*)larg1)->getVal());
            delete (ValHolder*)larg1;
        };
        Sprite3D::createAsync(modelPath, texturePath, lambda, valHolder);
      }))
    // end of manual
    .property("_className",  optional_override([](const Sprite3D& _) -> std::string {return "Sprite3D";}))    
    .allow_subclass<wrapper<Sprite3D>>("jsb.Sprite3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<Sprite3DCache>("jsb.Sprite3DCache")
    .function("removeSprite3DData", &Sprite3DCache::removeSprite3DData)
    .function("removeAllSprite3DData", &Sprite3DCache::removeAllSprite3DData)
    .class_function("destroyInstance", &Sprite3DCache::destroyInstance)
    .class_function("getInstance", &Sprite3DCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Sprite3DCache& _) -> std::string {return "Sprite3DCache";}))    
    ;


  class_<Terrain, base<Node>>("jsb.Terrain")
    .constructor(&cc_bindings_constructor<Terrain>, allow_raw_pointers())
    .function("initHeightMap", &Terrain::initHeightMap)
    .function("setMaxDetailMapAmount", &Terrain::setMaxDetailMapAmount)
    .function("setDrawWire", &Terrain::setDrawWire)
    .function("setDetailMap", &Terrain::setDetailMap)
    .function("resetHeightMap", &Terrain::resetHeightMap)
    .function("setLightDir", &Terrain::setLightDir)
    .function("setAlphaMap", &Terrain::setAlphaMap, allow_raw_pointers())
    .function("setSkirtHeightRatio", &Terrain::setSkirtHeightRatio)
    .function("convertToTerrainSpace", &Terrain::convertToTerrainSpace)
    .function("initTextures", &Terrain::initTextures)
    .function("initProperties", &Terrain::initProperties)
    .function("getHeight", optional_override(
        [](Terrain& this_, const cocos2d::Vec2& arg0){
            return this_.getHeight(arg0);
        }))
    .function("getHeight", optional_override(
        [](Terrain& this_, const val& arg0, const val& arg1){
            if(arg0.isNumber())
            {
            	return this_.getHeight(arg0.as<float>(), arg1.as<float>());
            }
            else
            {
            	return this_.getHeight(arg0.as<Vec2>(), arg1.as<cocos2d::Vec3*>(allow_raw_pointers()));
            }
        }))
    .function("getHeight", select_overload<float(float, float, cocos2d::Vec3*) const>(&Terrain::getHeight), allow_raw_pointers())
    .function("initWithTerrainData", &Terrain::initWithTerrainData)
    .function("setLODDistance", &Terrain::setLODDistance)
    .function("getTerrainSize", &Terrain::getTerrainSize)
    .function("getIntersectionPoint", select_overload<bool(const cocos2d::Ray&, cocos2d::Vec3&) const>(&Terrain::getIntersectionPoint))
    .function("getIntersectionPoint", select_overload<cocos2d::Vec3(const cocos2d::Ray&) const>(&Terrain::getIntersectionPoint))
    .function("getNormal", &Terrain::getNormal)
    .function("reload", &Terrain::reload)
    .function("getImageHeight", &Terrain::getImageHeight)
    .function("setLightMap", &Terrain::setLightMap)
    .function("setIsEnableFrustumCull", &Terrain::setIsEnableFrustumCull)
    .function("getMinHeight", &Terrain::getMinHeight)
    .function("getMaxHeight", &Terrain::getMaxHeight)
    // from manual
    .function("getHeightData", &Terrain::getHeightData)
    .class_function("create", optional_override(
      [](const val& parameter){
        cocos2d::Terrain::TerrainData data;
        val_to_TerrainData(parameter, data);
        return Terrain::create(data);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](const val& parameter, cocos2d::Terrain::CrackFixedType fixedType){
        cocos2d::Terrain::TerrainData data;
        val_to_TerrainData(parameter, data);
        return Terrain::create(data, fixedType);
      }), allow_raw_pointers())
    // end of manual
    .property("_className",  optional_override([](const Terrain& _) -> std::string {return "Terrain";}))
    .allow_subclass<wrapper<Terrain>>("jsb.Terrain._extend")    
    ;


  class_<Bundle3D>("jsb.Bundle3D")
    .constructor(&cc_bindings_constructor<Bundle3D>, allow_raw_pointers())
    // TODO: Emscripten cannot automatically call destructor.
    .function("load", &Bundle3D::load)
    .function("loadSkinData", &Bundle3D::loadSkinData, allow_raw_pointers())
    .function("clear", &Bundle3D::clear)
    .function("loadMaterials", &Bundle3D::loadMaterials)
    .function("loadMeshDatas", &Bundle3D::loadMeshDatas)
    .function("loadNodes", &Bundle3D::loadNodes)
    .function("loadAnimationData", &Bundle3D::loadAnimationData, allow_raw_pointers())
    // from manual
    .class_function("getTrianglesList", &Bundle3D::getTrianglesList)
    // end of manual
    .class_function("createBundle", &Bundle3D::createBundle, allow_raw_pointers())
    .class_function("destroyBundle", &Bundle3D::destroyBundle, allow_raw_pointers())
    .class_function("loadObj", &Bundle3D::loadObj, allow_raw_pointers())
    .class_function("loadObj", optional_override(
      [](cocos2d::MeshDatas& arg0, cocos2d::MaterialDatas& arg1, cocos2d::NodeDatas& arg2, const std::string& arg3){
        return Bundle3D::loadObj(arg0, arg1, arg2, arg3);
      }))
    .property("_className",  optional_override([](const Bundle3D& _) -> std::string {return "Bundle3D";}))    
    ;
}