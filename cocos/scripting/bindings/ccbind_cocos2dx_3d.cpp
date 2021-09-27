#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_3d.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_3d) {


  class_<Animation3D>("jsb.Animation3D")
    .constructor<>()
    .function("initWithFile", &Animation3D::initWithFile, allow_raw_pointers())
    .function("init", &Animation3D::init, allow_raw_pointers())
    .function("getBoneCurveByName", &Animation3D::getBoneCurveByName, allow_raw_pointers())
    .function("getDuration", &Animation3D::getDuration, allow_raw_pointers())
    .property("_className",  optional_override([](const Animation3D& _) -> std::string {return "Animation3D";}))    
    ;


  class_<Animate3D, base<ActionInterval>>("jsb.Animate3D")
    .constructor<>()
    .function("getOriginInterval", &Animate3D::getOriginInterval, allow_raw_pointers())
    .function("setOriginInterval", &Animate3D::setOriginInterval, allow_raw_pointers())
    .function("removeFromMap", &Animate3D::removeFromMap, allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Animation3D*, float, float)>(&Animate3D::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Animation3D*)>(&Animate3D::init), allow_raw_pointers())
    .function("getWeight", &Animate3D::getWeight, allow_raw_pointers())
    .function("getQuality", &Animate3D::getQuality, allow_raw_pointers())
    .function("setKeyFrameUserInfo", &Animate3D::setKeyFrameUserInfo, allow_raw_pointers())
    .function("setWeight", &Animate3D::setWeight, allow_raw_pointers())
    .function("setSpeed", &Animate3D::setSpeed, allow_raw_pointers())
    .function("getSpeed", &Animate3D::getSpeed, allow_raw_pointers())
    .function("setQuality", &Animate3D::setQuality, allow_raw_pointers())
    .function("initWithFrames", &Animate3D::initWithFrames, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Animate3D*(cocos2d::Animation3D*, float, float)>(&Animate3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Animate3D*(cocos2d::Animation3D*)>(&Animate3D::create), allow_raw_pointers())
    .class_function("getTransitionTime", &Animate3D::getTransitionTime, allow_raw_pointers())
    .class_function("createWithFrames", &Animate3D::createWithFrames, allow_raw_pointers())
    .class_function("createWithFrames", optional_override(
      [](cocos2d::Animation3D* arg0, int arg1, int arg2){
        return Animate3D::createWithFrames(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("setTransitionTime", &Animate3D::setTransitionTime, allow_raw_pointers())
    .property("_className",  optional_override([](const Animate3D& _) -> std::string {return "Animate3D";}))    
    ;


  class_<TextureCube, base<Texture2D>>("jsb.TextureCube")
    .constructor<>()
    .function("reloadTexture", &TextureCube::reloadTexture, allow_raw_pointers())
    .class_function("create", &TextureCube::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureCube& _) -> std::string {return "TextureCube";}))    
    ;


  class_<AttachNode, base<Node>>("jsb.AttachNode")
    .constructor<>()
    .class_function("create", &AttachNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AttachNode& _) -> std::string {return "AttachNode";}))    
    ;


  class_<BillBoard, base<Sprite>>("jsb.BillBoard")
    .constructor<>()
    .function("getMode", &BillBoard::getMode, allow_raw_pointers())
    .function("setMode", &BillBoard::setMode, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::BillBoard*(const std::string&, cocos2d::BillBoard::Mode)>(&BillBoard::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::BillBoard*(cocos2d::BillBoard::Mode)>(&BillBoard::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::BillBoard*(const std::string&, const cocos2d::Rect&, cocos2d::BillBoard::Mode)>(&BillBoard::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithTexture", &BillBoard::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return BillBoard::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const BillBoard& _) -> std::string {return "BillBoard";}))    
    ;


  class_<Mesh>("jsb.Mesh")
    .constructor<>()
    .function("getSkin", &Mesh::getSkin, allow_raw_pointers())
    .function("getMaterial", &Mesh::getMaterial, allow_raw_pointers())
    .function("getVertexSizeInBytes", &Mesh::getVertexSizeInBytes, allow_raw_pointers())
    .function("setMaterial", &Mesh::setMaterial, allow_raw_pointers())
    .function("getName", &Mesh::getName, allow_raw_pointers())
    .function("getIndexFormat", &Mesh::getIndexFormat, allow_raw_pointers())
    .function("getGLProgramState", &Mesh::getGLProgramState, allow_raw_pointers())
    .function("getVertexBuffer", &Mesh::getVertexBuffer, allow_raw_pointers())
    .function("calculateAABB", &Mesh::calculateAABB, allow_raw_pointers())
    .function("hasVertexAttrib", &Mesh::hasVertexAttrib, allow_raw_pointers())
    .function("getBlendFunc", &Mesh::getBlendFunc, allow_raw_pointers())
    .function("getMeshIndexData", &Mesh::getMeshIndexData, allow_raw_pointers())
    .function("setName", &Mesh::setName, allow_raw_pointers())
    .function("getIndexCount", &Mesh::getIndexCount, allow_raw_pointers())
    .function("setMeshIndexData", &Mesh::setMeshIndexData, allow_raw_pointers())
    .function("getMeshVertexAttribCount", &Mesh::getMeshVertexAttribCount, allow_raw_pointers())
    .function("setBlendFunc", &Mesh::setBlendFunc, allow_raw_pointers())
    .function("setForce2DQueue", &Mesh::setForce2DQueue, allow_raw_pointers())
    .function("getPrimitiveType", &Mesh::getPrimitiveType, allow_raw_pointers())
    .function("setSkin", &Mesh::setSkin, allow_raw_pointers())
    .function("isVisible", &Mesh::isVisible, allow_raw_pointers())
    .function("getIndexBuffer", &Mesh::getIndexBuffer, allow_raw_pointers())
    .function("setGLProgramState", &Mesh::setGLProgramState, allow_raw_pointers())
    .function("setVisible", &Mesh::setVisible, allow_raw_pointers())
    .property("_className",  optional_override([](const Mesh& _) -> std::string {return "Mesh";}))    
    ;


  class_<Skeleton3D>("jsb.Skeleton3D")
    .constructor<>()
    .function("removeAllBones", &Skeleton3D::removeAllBones, allow_raw_pointers())
    .function("addBone", &Skeleton3D::addBone, allow_raw_pointers())
    .function("getBoneByName", &Skeleton3D::getBoneByName, allow_raw_pointers())
    .function("getRootBone", &Skeleton3D::getRootBone, allow_raw_pointers())
    .function("updateBoneMatrix", &Skeleton3D::updateBoneMatrix, allow_raw_pointers())
    .function("getBoneByIndex", &Skeleton3D::getBoneByIndex, allow_raw_pointers())
    .function("getRootCount", &Skeleton3D::getRootCount, allow_raw_pointers())
    .function("getBoneIndex", &Skeleton3D::getBoneIndex, allow_raw_pointers())
    .function("getBoneCount", &Skeleton3D::getBoneCount, allow_raw_pointers())
    .property("_className",  optional_override([](const Skeleton3D& _) -> std::string {return "Skeleton3D";}))    
    ;


  class_<Skybox, base<Node>>("jsb.Skybox")
    .constructor<>()
    .function("reload", &Skybox::reload, allow_raw_pointers())
    .function("setTexture", &Skybox::setTexture, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&Skybox::init), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Skybox*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&Skybox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Skybox*()>(&Skybox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Skybox& _) -> std::string {return "Skybox";}))    
    ;


  class_<Sprite3D, base<Node>>("jsb.Sprite3D")
    .constructor<>()
    .function("setCullFaceEnabled", &Sprite3D::setCullFaceEnabled, allow_raw_pointers())
    .function("setTexture", select_overload<void(cocos2d::Texture2D*)>(&Sprite3D::setTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getLightMask", &Sprite3D::getLightMask, allow_raw_pointers())
    .function("createAttachSprite3DNode", &Sprite3D::createAttachSprite3DNode, allow_raw_pointers())
    .function("getMesh", &Sprite3D::getMesh, allow_raw_pointers())
    .function("loadFromFile", &Sprite3D::loadFromFile, allow_raw_pointers())
    .function("getMaterial", &Sprite3D::getMaterial, allow_raw_pointers())
    .function("setCullFace", &Sprite3D::setCullFace, allow_raw_pointers())
    .function("getMeshes", &Sprite3D::getMeshes, allow_raw_pointers())
    .function("addMesh", &Sprite3D::addMesh, allow_raw_pointers())
    .function("removeAllAttachNode", &Sprite3D::removeAllAttachNode, allow_raw_pointers())
    .function("setMaterial", select_overload<void(cocos2d::Material*, int)>(&Sprite3D::setMaterial), allow_raw_pointers())
    .function("setMaterial", select_overload<void(cocos2d::Material*)>(&Sprite3D::setMaterial), allow_raw_pointers())
    .function("createSprite3DNode", &Sprite3D::createSprite3DNode, allow_raw_pointers())
    .function("getMeshCount", &Sprite3D::getMeshCount, allow_raw_pointers())
    .function("onAABBDirty", &Sprite3D::onAABBDirty, allow_raw_pointers())
    .function("getMeshByIndex", &Sprite3D::getMeshByIndex, allow_raw_pointers())
    .function("createNode", &Sprite3D::createNode, allow_raw_pointers())
    .function("isForceDepthWrite", &Sprite3D::isForceDepthWrite, allow_raw_pointers())
    .function("getMeshIndexData", &Sprite3D::getMeshIndexData, allow_raw_pointers())
    .function("setLightMask", &Sprite3D::setLightMask, allow_raw_pointers())
    .function("afterAsyncLoad", &Sprite3D::afterAsyncLoad, allow_raw_pointers())
    .function("loadFromCache", &Sprite3D::loadFromCache, allow_raw_pointers())
    .function("initFrom", &Sprite3D::initFrom, allow_raw_pointers())
    .function("getAttachNode", &Sprite3D::getAttachNode, allow_raw_pointers())
    .function("setForceDepthWrite", &Sprite3D::setForceDepthWrite, allow_raw_pointers())
    .function("initWithFile", &Sprite3D::initWithFile, allow_raw_pointers())
    .function("setForce2DQueue", &Sprite3D::setForce2DQueue, allow_raw_pointers())
    .function("genMaterial", &Sprite3D::genMaterial, allow_raw_pointers())
    .function("genMaterial", optional_override(
        [](Sprite3D& this_){
        return this_.genMaterial();
      }), allow_raw_pointers())
    .function("removeAttachNode", &Sprite3D::removeAttachNode, allow_raw_pointers())
    .function("getSkeleton", &Sprite3D::getSkeleton, allow_raw_pointers())
    .function("getMeshByName", &Sprite3D::getMeshByName, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Sprite3D>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*(const std::string&)>(&Sprite3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*()>(&Sprite3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Sprite3D*(const std::string&, const std::string&)>(&Sprite3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Sprite3D& _) -> std::string {return "Sprite3D";}))    
    // TODO: assign cc.Class.extend to jsb.Sprite3D.extend
    ;

  class_<Sprite3DCache>("jsb.Sprite3DCache")
    .function("removeSprite3DData", &Sprite3DCache::removeSprite3DData, allow_raw_pointers())
    .function("removeAllSprite3DData", &Sprite3DCache::removeAllSprite3DData, allow_raw_pointers())
    .class_function("destroyInstance", &Sprite3DCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &Sprite3DCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Sprite3DCache& _) -> std::string {return "Sprite3DCache";}))    
    ;


  class_<Terrain, base<Node>>("jsb.Terrain")
    .constructor<>()
    .function("initHeightMap", &Terrain::initHeightMap, allow_raw_pointers())
    .function("setMaxDetailMapAmount", &Terrain::setMaxDetailMapAmount, allow_raw_pointers())
    .function("setDrawWire", &Terrain::setDrawWire, allow_raw_pointers())
    .function("setDetailMap", &Terrain::setDetailMap, allow_raw_pointers())
    .function("resetHeightMap", &Terrain::resetHeightMap, allow_raw_pointers())
    .function("setLightDir", &Terrain::setLightDir, allow_raw_pointers())
    .function("setAlphaMap", &Terrain::setAlphaMap, allow_raw_pointers())
    .function("setSkirtHeightRatio", &Terrain::setSkirtHeightRatio, allow_raw_pointers())
    .function("convertToTerrainSpace", &Terrain::convertToTerrainSpace, allow_raw_pointers())
    .function("initTextures", &Terrain::initTextures, allow_raw_pointers())
    .function("initProperties", &Terrain::initProperties, allow_raw_pointers())
    .function("getHeight", select_overload<float(const cocos2d::Vec2&, cocos2d::Vec3*) const>(&Terrain::getHeight), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getHeight", select_overload<float(float, float, cocos2d::Vec3*) const>(&Terrain::getHeight), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTerrainData", &Terrain::initWithTerrainData, allow_raw_pointers())
    .function("setLODDistance", &Terrain::setLODDistance, allow_raw_pointers())
    .function("getTerrainSize", &Terrain::getTerrainSize, allow_raw_pointers())
    .function("getIntersectionPoint", select_overload<bool(const cocos2d::Ray&, cocos2d::Vec3&) const>(&Terrain::getIntersectionPoint), allow_raw_pointers())
    .function("getIntersectionPoint", select_overload<cocos2d::Vec3(const cocos2d::Ray&) const>(&Terrain::getIntersectionPoint), allow_raw_pointers())
    .function("getNormal", &Terrain::getNormal, allow_raw_pointers())
    .function("reload", &Terrain::reload, allow_raw_pointers())
    .function("getImageHeight", &Terrain::getImageHeight, allow_raw_pointers())
    .function("setLightMap", &Terrain::setLightMap, allow_raw_pointers())
    .function("setIsEnableFrustumCull", &Terrain::setIsEnableFrustumCull, allow_raw_pointers())
    .function("getMinHeight", &Terrain::getMinHeight, allow_raw_pointers())
    .function("getMaxHeight", &Terrain::getMaxHeight, allow_raw_pointers())
    .property("_className",  optional_override([](const Terrain& _) -> std::string {return "Terrain";}))    
    ;


  class_<Bundle3D>("jsb.Bundle3D")
    .constructor<>()
    // TODO: Emscripten cannot automatically call destructor.
    .function("load", &Bundle3D::load, allow_raw_pointers())
    .function("loadSkinData", &Bundle3D::loadSkinData, allow_raw_pointers())
    .function("clear", &Bundle3D::clear, allow_raw_pointers())
    .function("loadMaterials", &Bundle3D::loadMaterials, allow_raw_pointers())
    .function("loadMeshDatas", &Bundle3D::loadMeshDatas, allow_raw_pointers())
    .function("loadNodes", &Bundle3D::loadNodes, allow_raw_pointers())
    .function("loadAnimationData", &Bundle3D::loadAnimationData, allow_raw_pointers())
    .class_function("createBundle", &Bundle3D::createBundle, allow_raw_pointers())
    .class_function("destroyBundle", &Bundle3D::destroyBundle, allow_raw_pointers())
    .class_function("loadObj", &Bundle3D::loadObj, allow_raw_pointers())
    .class_function("loadObj", optional_override(
      [](cocos2d::MeshDatas& arg0, cocos2d::MaterialDatas& arg1, cocos2d::NodeDatas& arg2, const std::string& arg3){
        return Bundle3D::loadObj(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Bundle3D& _) -> std::string {return "Bundle3D";}))    
    ;
}
