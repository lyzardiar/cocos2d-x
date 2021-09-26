#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_studio.hpp"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCComExtensionData.h"
#include "scripting/js-bindings/manual/cocostudio/jsb_cocos2dx_studio_conversions.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_studio) {


  class_<ActionObject>("ccs.ActionObject")
    .constructor<>()
    .function("setCurrentTime", &ActionObject::setCurrentTime, allow_raw_pointers())
    .function("pause", &ActionObject::pause, allow_raw_pointers())
    .function("setName", &ActionObject::setName, allow_raw_pointers())
    .function("setUnitTime", &ActionObject::setUnitTime, allow_raw_pointers())
    .function("getTotalTime", &ActionObject::getTotalTime, allow_raw_pointers())
    .function("getName", &ActionObject::getName, allow_raw_pointers())
    .function("stop", &ActionObject::stop, allow_raw_pointers())
    .function("play", select_overload<void(cocos2d::CallFunc*)>(&ActionObject::play), allow_raw_pointers())
    .function("play", select_overload<void()>(&ActionObject::play), allow_raw_pointers())
    .function("getCurrentTime", &ActionObject::getCurrentTime, allow_raw_pointers())
    .function("removeActionNode", &ActionObject::removeActionNode, allow_raw_pointers())
    .function("getLoop", &ActionObject::getLoop, allow_raw_pointers())
    .function("initWithBinary", &ActionObject::initWithBinary, allow_raw_pointers())
    .function("addActionNode", &ActionObject::addActionNode, allow_raw_pointers())
    .function("getUnitTime", &ActionObject::getUnitTime, allow_raw_pointers())
    .function("isPlaying", &ActionObject::isPlaying, allow_raw_pointers())
    .function("updateToFrameByTime", &ActionObject::updateToFrameByTime, allow_raw_pointers())
    .function("setLoop", &ActionObject::setLoop, allow_raw_pointers())
    .function("simulationActionUpdate", &ActionObject::simulationActionUpdate, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionObject& _) -> std::string {return "ActionObject";}))    
    ;

  class_<ActionManagerEx>("ccs.ActionManager")
    .function("stopActionByName", &ActionManagerEx::stopActionByName, allow_raw_pointers())
    .function("getActionByName", &ActionManagerEx::getActionByName, allow_raw_pointers())
    .function("getStudioVersionNumber", &ActionManagerEx::getStudioVersionNumber, allow_raw_pointers())
    .function("initWithBinary", &ActionManagerEx::initWithBinary, allow_raw_pointers())
    .function("playActionByName", select_overload<cocostudio::ActionObject*(const char*, const char*, cocos2d::CallFunc*)>(&ActionManagerEx::playActionByName), allow_raw_pointers())
    .function("playActionByName", select_overload<cocostudio::ActionObject*(const char*, const char*)>(&ActionManagerEx::playActionByName), allow_raw_pointers())
    .function("releaseActions", &ActionManagerEx::releaseActions, allow_raw_pointers())
    .class_function("destroyInstance", &ActionManagerEx::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &ActionManagerEx::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionManagerEx& _) -> std::string {return "ActionManagerEx";}))    
    ;


  class_<BaseData>("ccs.BaseData")
    .constructor<>()
    .function("getColor", &BaseData::getColor, allow_raw_pointers())
    .function("setColor", &BaseData::setColor, allow_raw_pointers())
    .class_function("create", &BaseData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BaseData& _) -> std::string {return "BaseData";}))    
    ;


  class_<MovementData>("ccs.MovementData")
    .constructor<>()
    .function("getMovementBoneData", &MovementData::getMovementBoneData, allow_raw_pointers())
    .function("addMovementBoneData", &MovementData::addMovementBoneData, allow_raw_pointers())
    .class_function("create", &MovementData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const MovementData& _) -> std::string {return "MovementData";}))    
    ;


  class_<AnimationData>("ccs.AnimationData")
    .constructor<>()
    .function("getMovement", &AnimationData::getMovement, allow_raw_pointers())
    .function("getMovementCount", &AnimationData::getMovementCount, allow_raw_pointers())
    .function("addMovement", &AnimationData::addMovement, allow_raw_pointers())
    .class_function("create", &AnimationData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationData& _) -> std::string {return "AnimationData";}))    
    ;


  class_<ContourData>("ccs.ContourData")
    .constructor<>()
    .function("init", &ContourData::init, allow_raw_pointers())
    .function("addVertex", &ContourData::addVertex, allow_raw_pointers())
    .class_function("create", &ContourData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ContourData& _) -> std::string {return "ContourData";}))    
    ;


  class_<TextureData>("ccs.TextureData")
    .constructor<>()
    .function("getContourData", &TextureData::getContourData, allow_raw_pointers())
    .function("init", &TextureData::init, allow_raw_pointers())
    .function("addContourData", &TextureData::addContourData, allow_raw_pointers())
    .class_function("create", &TextureData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureData& _) -> std::string {return "TextureData";}))    
    ;


  class_<ProcessBase>("ccs.ProcessBase")
    .constructor<>()
    .function("play", &ProcessBase::play, allow_raw_pointers())
    .function("pause", &ProcessBase::pause, allow_raw_pointers())
    .function("getRawDuration", &ProcessBase::getRawDuration, allow_raw_pointers())
    .function("resume", &ProcessBase::resume, allow_raw_pointers())
    .function("setIsComplete", &ProcessBase::setIsComplete, allow_raw_pointers())
    .function("stop", &ProcessBase::stop, allow_raw_pointers())
    .function("update", &ProcessBase::update, allow_raw_pointers())
    .function("getCurrentFrameIndex", &ProcessBase::getCurrentFrameIndex, allow_raw_pointers())
    .function("isComplete", &ProcessBase::isComplete, allow_raw_pointers())
    .function("getCurrentPercent", &ProcessBase::getCurrentPercent, allow_raw_pointers())
    .function("setIsPause", &ProcessBase::setIsPause, allow_raw_pointers())
    .function("getProcessScale", &ProcessBase::getProcessScale, allow_raw_pointers())
    .function("isPause", &ProcessBase::isPause, allow_raw_pointers())
    .function("isPlaying", &ProcessBase::isPlaying, allow_raw_pointers())
    .function("setProcessScale", &ProcessBase::setProcessScale, allow_raw_pointers())
    .function("setIsPlaying", &ProcessBase::setIsPlaying, allow_raw_pointers())
    .property("_className",  optional_override([](const ProcessBase& _) -> std::string {return "ProcessBase";}))    
    ;


  class_<Tween, base<ProcessBase>>("ccs.Tween")
    .constructor<>()
    .function("getAnimation", &Tween::getAnimation, allow_raw_pointers())
    .function("gotoAndPause", &Tween::gotoAndPause, allow_raw_pointers())
    .function("play", &Tween::play, allow_raw_pointers())
    .function("gotoAndPlay", &Tween::gotoAndPlay, allow_raw_pointers())
    .function("init", &Tween::init, allow_raw_pointers())
    .function("setAnimation", &Tween::setAnimation, allow_raw_pointers())
    .class_function("create", &Tween::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Tween& _) -> std::string {return "Tween";}))    
    ;

  class_<ColliderFilter>("ccs.ColliderFilter")
    .property("_className",  optional_override([](const ColliderFilter& _) -> std::string {return "ColliderFilter";}))    
    ;

  class_<ColliderBody>("ccs.ColliderBody")
    .property("_className",  optional_override([](const ColliderBody& _) -> std::string {return "ColliderBody";}))    
    ;

  class_<ColliderDetector>("ccs.ColliderDetector")
    .function("getBone", &ColliderDetector::getBone, allow_raw_pointers())
    .function("getActive", &ColliderDetector::getActive, allow_raw_pointers())
    .function("getColliderBodyList", &ColliderDetector::getColliderBodyList, allow_raw_pointers())
    .function("updateTransform", &ColliderDetector::updateTransform, allow_raw_pointers())
    .function("removeAll", &ColliderDetector::removeAll, allow_raw_pointers())
    .function("init", select_overload<bool(cocostudio::Bone*)>(&ColliderDetector::init), allow_raw_pointers())
    .function("init", select_overload<bool()>(&ColliderDetector::init), allow_raw_pointers())
    .function("setActive", &ColliderDetector::setActive, allow_raw_pointers())
    .function("setBone", &ColliderDetector::setBone, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ColliderDetector*(cocostudio::Bone*)>(&ColliderDetector::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ColliderDetector*()>(&ColliderDetector::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ColliderDetector& _) -> std::string {return "ColliderDetector";}))    
    ;

  class_<DecorativeDisplay>("ccs.DecorativeDisplay")
    .function("getColliderDetector", &DecorativeDisplay::getColliderDetector, allow_raw_pointers())
    .function("getDisplay", &DecorativeDisplay::getDisplay, allow_raw_pointers())
    .function("setDisplay", &DecorativeDisplay::setDisplay, allow_raw_pointers())
    .function("init", &DecorativeDisplay::init, allow_raw_pointers())
    .function("setDisplayData", &DecorativeDisplay::setDisplayData, allow_raw_pointers())
    .function("getDisplayData", &DecorativeDisplay::getDisplayData, allow_raw_pointers())
    .function("setColliderDetector", &DecorativeDisplay::setColliderDetector, allow_raw_pointers())
    .class_function("create", &DecorativeDisplay::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DecorativeDisplay& _) -> std::string {return "DecorativeDisplay";}))    
    ;


  class_<DisplayManager>("ccs.DisplayManager")
    .constructor<>()
    .function("getCurrentDecorativeDisplay", &DisplayManager::getCurrentDecorativeDisplay, allow_raw_pointers())
    .function("getDisplayRenderNode", &DisplayManager::getDisplayRenderNode, allow_raw_pointers())
    .function("getAnchorPointInPoints", &DisplayManager::getAnchorPointInPoints, allow_raw_pointers())
    .function("setCurrentDecorativeDisplay", &DisplayManager::setCurrentDecorativeDisplay, allow_raw_pointers())
    .function("getDisplayRenderNodeType", &DisplayManager::getDisplayRenderNodeType, allow_raw_pointers())
    .function("removeDisplay", &DisplayManager::removeDisplay, allow_raw_pointers())
    .function("setForceChangeDisplay", &DisplayManager::setForceChangeDisplay, allow_raw_pointers())
    .function("init", &DisplayManager::init, allow_raw_pointers())
    .function("getContentSize", &DisplayManager::getContentSize, allow_raw_pointers())
    .function("getBoundingBox", &DisplayManager::getBoundingBox, allow_raw_pointers())
    .function("addDisplay", select_overload<void(cocos2d::Node*, int)>(&DisplayManager::addDisplay), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("containPoint", select_overload<bool(float, float)>(&DisplayManager::containPoint), allow_raw_pointers())
    .function("containPoint", select_overload<bool(cocos2d::Vec2&)>(&DisplayManager::containPoint), allow_raw_pointers())
    .function("initDisplayList", &DisplayManager::initDisplayList, allow_raw_pointers())
    .function("changeDisplayWithIndex", &DisplayManager::changeDisplayWithIndex, allow_raw_pointers())
    .function("changeDisplayWithName", &DisplayManager::changeDisplayWithName, allow_raw_pointers())
    .function("isForceChangeDisplay", &DisplayManager::isForceChangeDisplay, allow_raw_pointers())
    .function("getDecorativeDisplayByIndex", &DisplayManager::getDecorativeDisplayByIndex, allow_raw_pointers())
    .function("getCurrentDisplayIndex", &DisplayManager::getCurrentDisplayIndex, allow_raw_pointers())
    .function("getAnchorPoint", &DisplayManager::getAnchorPoint, allow_raw_pointers())
    .function("getDecorativeDisplayList", &DisplayManager::getDecorativeDisplayList, allow_raw_pointers())
    .function("isVisible", &DisplayManager::isVisible, allow_raw_pointers())
    .function("setVisible", &DisplayManager::setVisible, allow_raw_pointers())
    .class_function("create", &DisplayManager::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DisplayManager& _) -> std::string {return "DisplayManager";}))    
    ;


  class_<Bone, base<Node>>("ccs.Bone")
    .constructor<>()
    .function("isTransformDirty", &Bone::isTransformDirty, allow_raw_pointers())
    .function("setBlendFunc", &Bone::setBlendFunc, allow_raw_pointers())
    .function("isIgnoreMovementBoneData", &Bone::isIgnoreMovementBoneData, allow_raw_pointers())
    .function("updateZOrder", &Bone::updateZOrder, allow_raw_pointers())
    .function("getDisplayRenderNode", &Bone::getDisplayRenderNode, allow_raw_pointers())
    .function("isBlendDirty", &Bone::isBlendDirty, allow_raw_pointers())
    .function("addChildBone", &Bone::addChildBone, allow_raw_pointers())
    .function("getWorldInfo", &Bone::getWorldInfo, allow_raw_pointers())
    .function("getTween", &Bone::getTween, allow_raw_pointers())
    .function("getParentBone", &Bone::getParentBone, allow_raw_pointers())
    .function("setTransformDirty", &Bone::setTransformDirty, allow_raw_pointers())
    .function("getDisplayRenderNodeType", &Bone::getDisplayRenderNodeType, allow_raw_pointers())
    .function("removeDisplay", &Bone::removeDisplay, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&)>(&Bone::init), allow_raw_pointers())
    .function("addDisplay", select_overload<void(cocos2d::Node*, int)>(&Bone::addDisplay), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setIgnoreMovementBoneData", &Bone::setIgnoreMovementBoneData, allow_raw_pointers())
    .function("getBlendFunc", &Bone::getBlendFunc, allow_raw_pointers())
    .function("removeFromParent", &Bone::removeFromParent, allow_raw_pointers())
    .function("getColliderDetector", &Bone::getColliderDetector, allow_raw_pointers())
    .function("setParentBone", &Bone::setParentBone, allow_raw_pointers())
    .function("getChildArmature", &Bone::getChildArmature, allow_raw_pointers())
    .function("changeDisplayWithIndex", &Bone::changeDisplayWithIndex, allow_raw_pointers())
    .function("changeDisplayWithName", &Bone::changeDisplayWithName, allow_raw_pointers())
    .function("setBoneData", &Bone::setBoneData, allow_raw_pointers())
    .function("setArmature", &Bone::setArmature, allow_raw_pointers())
    .function("setBlendDirty", &Bone::setBlendDirty, allow_raw_pointers())
    .function("removeChildBone", &Bone::removeChildBone, allow_raw_pointers())
    .function("setChildArmature", &Bone::setChildArmature, allow_raw_pointers())
    .function("getNodeToArmatureTransform", &Bone::getNodeToArmatureTransform, allow_raw_pointers())
    .function("getDisplayManager", &Bone::getDisplayManager, allow_raw_pointers())
    .function("getArmature", &Bone::getArmature, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Bone*(const std::string&)>(&Bone::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Bone*()>(&Bone::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Bone& _) -> std::string {return "Bone";}))    
    ;

  class_<BatchNode, base<Node>>("ccs.BatchNode")
    .class_function("create", &BatchNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BatchNode& _) -> std::string {return "BatchNode";}))    
    ;


  class_<ArmatureAnimation, base<ProcessBase>>("ccs.ArmatureAnimation")
    .constructor<>()
    .function("playWithIndexes", &ArmatureAnimation::playWithIndexes, allow_raw_pointers())
    .function("playWithIndexes", optional_override(
        [](ArmatureAnimation& this_, const std::vector<int>& arg0){
        return this_.playWithIndexes(arg0);
      }), allow_raw_pointers())
    .function("playWithIndexes", optional_override(
        [](ArmatureAnimation& this_, const std::vector<int>& arg0, int arg1){
        return this_.playWithIndexes(arg0, arg1);
      }), allow_raw_pointers())
    .function("getSpeedScale", &ArmatureAnimation::getSpeedScale, allow_raw_pointers())
    .function("setSpeedScale", &ArmatureAnimation::setSpeedScale, allow_raw_pointers())
    .function("init", &ArmatureAnimation::init, allow_raw_pointers())
    .function("play", &ArmatureAnimation::play, allow_raw_pointers())
    .function("play", optional_override(
        [](ArmatureAnimation& this_, const std::string& arg0){
        return this_.play(arg0);
      }), allow_raw_pointers())
    .function("play", optional_override(
        [](ArmatureAnimation& this_, const std::string& arg0, int arg1){
        return this_.play(arg0, arg1);
      }), allow_raw_pointers())
    .function("gotoAndPause", &ArmatureAnimation::gotoAndPause, allow_raw_pointers())
    .function("getAnimationData", &ArmatureAnimation::getAnimationData, allow_raw_pointers())
    .function("playWithIndex", &ArmatureAnimation::playWithIndex, allow_raw_pointers())
    .function("playWithIndex", optional_override(
        [](ArmatureAnimation& this_, int arg0){
        return this_.playWithIndex(arg0);
      }), allow_raw_pointers())
    .function("playWithIndex", optional_override(
        [](ArmatureAnimation& this_, int arg0, int arg1){
        return this_.playWithIndex(arg0, arg1);
      }), allow_raw_pointers())
    .function("getCurrentMovementID", &ArmatureAnimation::getCurrentMovementID, allow_raw_pointers())
    .function("setAnimationData", &ArmatureAnimation::setAnimationData, allow_raw_pointers())
    .function("gotoAndPlay", &ArmatureAnimation::gotoAndPlay, allow_raw_pointers())
    .function("playWithNames", &ArmatureAnimation::playWithNames, allow_raw_pointers())
    .function("playWithNames", optional_override(
        [](ArmatureAnimation& this_, const std::vector<std::string>& arg0){
        return this_.playWithNames(arg0);
      }), allow_raw_pointers())
    .function("playWithNames", optional_override(
        [](ArmatureAnimation& this_, const std::vector<std::string>& arg0, int arg1){
        return this_.playWithNames(arg0, arg1);
      }), allow_raw_pointers())
    .function("getMovementCount", &ArmatureAnimation::getMovementCount, allow_raw_pointers())
    .class_function("create", &ArmatureAnimation::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ArmatureAnimation& _) -> std::string {return "ArmatureAnimation";}))    
    ;

  class_<ArmatureDataManager>("ccs.ArmatureDataManager")
    .function("getAnimationDatas", &ArmatureDataManager::getAnimationDatas, allow_raw_pointers())
    .function("removeAnimationData", &ArmatureDataManager::removeAnimationData, allow_raw_pointers())
    .function("addArmatureData", &ArmatureDataManager::addArmatureData, allow_raw_pointers())
    .function("addArmatureData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::ArmatureData* arg1){
        return this_.addArmatureData(arg0, arg1);
      }), allow_raw_pointers())
    .function("addArmatureFileInfo", select_overload<void(const std::string&, const std::string&, const std::string&)>(&ArmatureDataManager::addArmatureFileInfo), allow_raw_pointers())
    .function("addArmatureFileInfo", select_overload<void(const std::string&)>(&ArmatureDataManager::addArmatureFileInfo), allow_raw_pointers())
    .function("removeArmatureFileInfo", &ArmatureDataManager::removeArmatureFileInfo, allow_raw_pointers())
    .function("getTextureData", &ArmatureDataManager::getTextureData, allow_raw_pointers())
    .function("getArmatureData", &ArmatureDataManager::getArmatureData, allow_raw_pointers())
    .function("getAnimationData", &ArmatureDataManager::getAnimationData, allow_raw_pointers())
    .function("addAnimationData", &ArmatureDataManager::addAnimationData, allow_raw_pointers())
    .function("addAnimationData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::AnimationData* arg1){
        return this_.addAnimationData(arg0, arg1);
      }), allow_raw_pointers())
    .function("init", &ArmatureDataManager::init, allow_raw_pointers())
    .function("removeArmatureData", &ArmatureDataManager::removeArmatureData, allow_raw_pointers())
    .function("getArmatureDatas", &ArmatureDataManager::getArmatureDatas, allow_raw_pointers())
    .function("removeTextureData", &ArmatureDataManager::removeTextureData, allow_raw_pointers())
    .function("addTextureData", &ArmatureDataManager::addTextureData, allow_raw_pointers())
    .function("addTextureData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::TextureData* arg1){
        return this_.addTextureData(arg0, arg1);
      }), allow_raw_pointers())
    .function("isAutoLoadSpriteFile", &ArmatureDataManager::isAutoLoadSpriteFile, allow_raw_pointers())
    .function("addSpriteFrameFromFile", &ArmatureDataManager::addSpriteFrameFromFile, allow_raw_pointers())
    .function("addSpriteFrameFromFile", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, const std::string& arg1){
        return this_.addSpriteFrameFromFile(arg0, arg1);
      }), allow_raw_pointers())
    .class_function("destroyInstance", &ArmatureDataManager::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &ArmatureDataManager::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const ArmatureDataManager& _) -> std::string {return "ArmatureDataManager";}))    
    ;


  class_<Armature, base<Node>>("ccs.Armature")
    .constructor<>()
    .function("getBone", &Armature::getBone, allow_raw_pointers())
    .function("changeBoneParent", &Armature::changeBoneParent, allow_raw_pointers())
    .function("setAnimation", &Armature::setAnimation, allow_raw_pointers())
    .function("getBoneAtPoint", &Armature::getBoneAtPoint, allow_raw_pointers())
    .function("getArmatureTransformDirty", &Armature::getArmatureTransformDirty, allow_raw_pointers())
    .function("setVersion", &Armature::setVersion, allow_raw_pointers())
    .function("updateOffsetPoint", &Armature::updateOffsetPoint, allow_raw_pointers())
    .function("getParentBone", &Armature::getParentBone, allow_raw_pointers())
    .function("removeBone", &Armature::removeBone, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&)>(&Armature::init), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, cocostudio::Bone*)>(&Armature::init), allow_raw_pointers())
    .function("setParentBone", &Armature::setParentBone, allow_raw_pointers())
    .function("setBatchNode", &Armature::setBatchNode, allow_raw_pointers())
    .function("setArmatureData", &Armature::setArmatureData, allow_raw_pointers())
    .function("addBone", &Armature::addBone, allow_raw_pointers())
    .function("getArmatureData", &Armature::getArmatureData, allow_raw_pointers())
    .function("getVersion", &Armature::getVersion, allow_raw_pointers())
    .function("getAnimation", &Armature::getAnimation, allow_raw_pointers())
    .function("getOffsetPoints", &Armature::getOffsetPoints, allow_raw_pointers())
    .function("getBoneDic", &Armature::getBoneDic, allow_raw_pointers())
    .function("getBatchNode", &Armature::getBatchNode, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Armature>, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Armature*(const std::string&)>(&Armature::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Armature*()>(&Armature::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Armature*(const std::string&, cocostudio::Bone*)>(&Armature::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Armature& _) -> std::string {return "Armature";}))    
    // TODO: assign cc.Class.extend to ccs.Armature.extend
    ;


  class_<Skin, base<Sprite>>("ccs.Skin")
    .constructor<>()
    .function("getBone", &Skin::getBone, allow_raw_pointers())
    .function("getNodeToWorldTransformAR", &Skin::getNodeToWorldTransformAR, allow_raw_pointers())
    .function("getDisplayName", &Skin::getDisplayName, allow_raw_pointers())
    .function("updateArmatureTransform", &Skin::updateArmatureTransform, allow_raw_pointers())
    .function("setBone", &Skin::setBone, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Skin*(const std::string&)>(&Skin::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Skin*()>(&Skin::create), allow_raw_pointers())
    .class_function("createWithSpriteFrameName", &Skin::createWithSpriteFrameName, allow_raw_pointers())
    .property("_className",  optional_override([](const Skin& _) -> std::string {return "Skin";}))    
    ;


  class_<ComAttribute, base<Component>>("ccs.ComAttribute")
    .constructor<>()
    .function("getFloat", &ComAttribute::getFloat, allow_raw_pointers())
    .function("getFloat", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getFloat(arg0);
      }), allow_raw_pointers())
    .function("getBool", &ComAttribute::getBool, allow_raw_pointers())
    .function("getBool", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getBool(arg0);
      }), allow_raw_pointers())
    .function("getString", &ComAttribute::getString, allow_raw_pointers())
    .function("getString", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getString(arg0);
      }), allow_raw_pointers())
    .function("setFloat", &ComAttribute::setFloat, allow_raw_pointers())
    .function("setString", &ComAttribute::setString, allow_raw_pointers())
    .function("setInt", &ComAttribute::setInt, allow_raw_pointers())
    .function("parse", &ComAttribute::parse, allow_raw_pointers())
    .function("getInt", &ComAttribute::getInt, allow_raw_pointers())
    .function("getInt", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getInt(arg0);
      }), allow_raw_pointers())
    .function("setBool", &ComAttribute::setBool, allow_raw_pointers())
    .class_function("create", &ComAttribute::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComAttribute& _) -> std::string {return "ComAttribute";}))    
    ;


  class_<ComAudio, base<Component>>("ccs.ComAudio")
    .constructor<>()
    .function("stopAllEffects", &ComAudio::stopAllEffects, allow_raw_pointers())
    .function("getEffectsVolume", &ComAudio::getEffectsVolume, allow_raw_pointers())
    .function("stopEffect", &ComAudio::stopEffect, allow_raw_pointers())
    .function("getBackgroundMusicVolume", &ComAudio::getBackgroundMusicVolume, allow_raw_pointers())
    .function("willPlayBackgroundMusic", &ComAudio::willPlayBackgroundMusic, allow_raw_pointers())
    .function("setBackgroundMusicVolume", &ComAudio::setBackgroundMusicVolume, allow_raw_pointers())
    .function("end", &ComAudio::end, allow_raw_pointers())
    .function("stopBackgroundMusic", select_overload<void()>(&ComAudio::stopBackgroundMusic), allow_raw_pointers())
    .function("stopBackgroundMusic", select_overload<void(bool)>(&ComAudio::stopBackgroundMusic), allow_raw_pointers())
    .function("pauseBackgroundMusic", &ComAudio::pauseBackgroundMusic, allow_raw_pointers())
    .function("isBackgroundMusicPlaying", &ComAudio::isBackgroundMusicPlaying, allow_raw_pointers())
    .function("isLoop", &ComAudio::isLoop, allow_raw_pointers())
    .function("pauseAllEffects", &ComAudio::pauseAllEffects, allow_raw_pointers())
    .function("preloadBackgroundMusic", &ComAudio::preloadBackgroundMusic, allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void(const char*)>(&ComAudio::playBackgroundMusic), allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void(const char*, bool)>(&ComAudio::playBackgroundMusic), allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void()>(&ComAudio::playBackgroundMusic), allow_raw_pointers())
    .function("playEffect", select_overload<unsigned int(const char*)>(&ComAudio::playEffect), allow_raw_pointers())
    .function("playEffect", select_overload<unsigned int(const char*, bool)>(&ComAudio::playEffect), allow_raw_pointers())
    .function("playEffect", select_overload<unsigned int()>(&ComAudio::playEffect), allow_raw_pointers())
    .function("resumeAllEffects", &ComAudio::resumeAllEffects, allow_raw_pointers())
    .function("setLoop", &ComAudio::setLoop, allow_raw_pointers())
    .function("unloadEffect", &ComAudio::unloadEffect, allow_raw_pointers())
    .function("rewindBackgroundMusic", &ComAudio::rewindBackgroundMusic, allow_raw_pointers())
    .function("preloadEffect", &ComAudio::preloadEffect, allow_raw_pointers())
    .function("pauseEffect", &ComAudio::pauseEffect, allow_raw_pointers())
    .function("resumeBackgroundMusic", &ComAudio::resumeBackgroundMusic, allow_raw_pointers())
    .function("setFile", &ComAudio::setFile, allow_raw_pointers())
    .function("setEffectsVolume", &ComAudio::setEffectsVolume, allow_raw_pointers())
    .function("getFile", &ComAudio::getFile, allow_raw_pointers())
    .function("resumeEffect", &ComAudio::resumeEffect, allow_raw_pointers())
    .class_function("create", &ComAudio::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComAudio& _) -> std::string {return "ComAudio";}))    
    ;

  class_<InputDelegate>("ccs.InputDelegate")
    .function("isKeypadEnabled", &InputDelegate::isKeypadEnabled, allow_raw_pointers())
    .function("getTouchMode", &InputDelegate::getTouchMode, allow_raw_pointers())
    .function("setAccelerometerEnabled", &InputDelegate::setAccelerometerEnabled, allow_raw_pointers())
    .function("isTouchEnabled", &InputDelegate::isTouchEnabled, allow_raw_pointers())
    .function("setTouchEnabled", &InputDelegate::setTouchEnabled, allow_raw_pointers())
    .function("setTouchMode", &InputDelegate::setTouchMode, allow_raw_pointers())
    .function("isAccelerometerEnabled", &InputDelegate::isAccelerometerEnabled, allow_raw_pointers())
    .function("setTouchPriority", &InputDelegate::setTouchPriority, allow_raw_pointers())
    .function("getTouchPriority", &InputDelegate::getTouchPriority, allow_raw_pointers())
    .function("setKeypadEnabled", &InputDelegate::setKeypadEnabled, allow_raw_pointers())
    .property("_className",  optional_override([](const InputDelegate& _) -> std::string {return "InputDelegate";}))    
    ;


  class_<ComController, base<Component>>("ccs.ComController")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<ComController>, allow_raw_pointers())
    .class_function("create", &ComController::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComController& _) -> std::string {return "ComController";}))    
    // TODO: assign cc.Class.extend to ccs.ComController.extend
    ;


  class_<ComRender, base<Component>>("ccs.ComRender")
        // TODO: overloaded constructor
    .function("setNode", &ComRender::setNode, allow_raw_pointers())
    .function("getNode", &ComRender::getNode, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ComRender*(cocos2d::Node*, const char*)>(&ComRender::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ComRender*()>(&ComRender::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ComRender& _) -> std::string {return "ComRender";}))    
    ;

  class_<Frame>("ccs.Frame")
    .function("clone", &Frame::clone, allow_raw_pointers())
    .function("setTweenType", &Frame::setTweenType, allow_raw_pointers())
    .function("setNode", &Frame::setNode, allow_raw_pointers())
    .function("setTimeline", &Frame::setTimeline, allow_raw_pointers())
    .function("isEnterWhenPassed", &Frame::isEnterWhenPassed, allow_raw_pointers())
    .function("getTweenType", &Frame::getTweenType, allow_raw_pointers())
    .function("getFrameIndex", &Frame::getFrameIndex, allow_raw_pointers())
    .function("apply", &Frame::apply, allow_raw_pointers())
    .function("isTween", &Frame::isTween, allow_raw_pointers())
    .function("setFrameIndex", &Frame::setFrameIndex, allow_raw_pointers())
    .function("setTween", &Frame::setTween, allow_raw_pointers())
    .function("getTimeline", &Frame::getTimeline, allow_raw_pointers())
    .function("getNode", &Frame::getNode, allow_raw_pointers())
    .property("_className",  optional_override([](const Frame& _) -> std::string {return "Frame";}))    
    ;


  class_<VisibleFrame, base<Frame>>("ccs.VisibleFrame")
    .constructor<>()
    .function("setVisible", &VisibleFrame::setVisible, allow_raw_pointers())
    .function("isVisible", &VisibleFrame::isVisible, allow_raw_pointers())
    .class_function("create", &VisibleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const VisibleFrame& _) -> std::string {return "VisibleFrame";}))    
    ;


  class_<TextureFrame, base<Frame>>("ccs.TextureFrame")
    .constructor<>()
    .function("getTextureName", &TextureFrame::getTextureName, allow_raw_pointers())
    .function("setTextureName", &TextureFrame::setTextureName, allow_raw_pointers())
    .class_function("create", &TextureFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureFrame& _) -> std::string {return "TextureFrame";}))    
    ;


  class_<RotationFrame, base<Frame>>("ccs.RotationFrame")
    .constructor<>()
    .function("setRotation", &RotationFrame::setRotation, allow_raw_pointers())
    .function("getRotation", &RotationFrame::getRotation, allow_raw_pointers())
    .class_function("create", &RotationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RotationFrame& _) -> std::string {return "RotationFrame";}))    
    ;


  class_<SkewFrame, base<Frame>>("ccs.SkewFrame")
    .constructor<>()
    .function("getSkewY", &SkewFrame::getSkewY, allow_raw_pointers())
    .function("getSkewX", &SkewFrame::getSkewX, allow_raw_pointers())
    .function("setSkewX", &SkewFrame::setSkewX, allow_raw_pointers())
    .function("setSkewY", &SkewFrame::setSkewY, allow_raw_pointers())
    .class_function("create", &SkewFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewFrame& _) -> std::string {return "SkewFrame";}))    
    ;


  class_<RotationSkewFrame, base<SkewFrame>>("ccs.RotationSkewFrame")
    .constructor<>()
    .class_function("create", &RotationSkewFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RotationSkewFrame& _) -> std::string {return "RotationSkewFrame";}))    
    ;


  class_<PositionFrame, base<Frame>>("ccs.PositionFrame")
    .constructor<>()
    .function("getX", &PositionFrame::getX, allow_raw_pointers())
    .function("getY", &PositionFrame::getY, allow_raw_pointers())
    .function("setPosition", &PositionFrame::setPosition, allow_raw_pointers())
    .function("setX", &PositionFrame::setX, allow_raw_pointers())
    .function("setY", &PositionFrame::setY, allow_raw_pointers())
    .function("getPosition", &PositionFrame::getPosition, allow_raw_pointers())
    .class_function("create", &PositionFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PositionFrame& _) -> std::string {return "PositionFrame";}))    
    ;


  class_<ScaleFrame, base<Frame>>("ccs.ScaleFrame")
    .constructor<>()
    .function("setScaleY", &ScaleFrame::setScaleY, allow_raw_pointers())
    .function("setScaleX", &ScaleFrame::setScaleX, allow_raw_pointers())
    .function("getScaleY", &ScaleFrame::getScaleY, allow_raw_pointers())
    .function("getScaleX", &ScaleFrame::getScaleX, allow_raw_pointers())
    .function("setScale", &ScaleFrame::setScale, allow_raw_pointers())
    .class_function("create", &ScaleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleFrame& _) -> std::string {return "ScaleFrame";}))    
    ;


  class_<AnchorPointFrame, base<Frame>>("ccs.AnchorPointFrame")
    .constructor<>()
    .function("setAnchorPoint", &AnchorPointFrame::setAnchorPoint, allow_raw_pointers())
    .function("getAnchorPoint", &AnchorPointFrame::getAnchorPoint, allow_raw_pointers())
    .class_function("create", &AnchorPointFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnchorPointFrame& _) -> std::string {return "AnchorPointFrame";}))    
    ;


  class_<InnerActionFrame, base<Frame>>("ccs.InnerActionFrame")
    .constructor<>()
    .function("getEndFrameIndex", &InnerActionFrame::getEndFrameIndex, allow_raw_pointers())
    .function("getStartFrameIndex", &InnerActionFrame::getStartFrameIndex, allow_raw_pointers())
    .function("getInnerActionType", &InnerActionFrame::getInnerActionType, allow_raw_pointers())
    .function("setStartFrameIndex", &InnerActionFrame::setStartFrameIndex, allow_raw_pointers())
    .function("setEndFrameIndex", &InnerActionFrame::setEndFrameIndex, allow_raw_pointers())
    .function("setEnterWithName", &InnerActionFrame::setEnterWithName, allow_raw_pointers())
    .function("setSingleFrameIndex", &InnerActionFrame::setSingleFrameIndex, allow_raw_pointers())
    .function("getSingleFrameIndex", &InnerActionFrame::getSingleFrameIndex, allow_raw_pointers())
    .function("setInnerActionType", &InnerActionFrame::setInnerActionType, allow_raw_pointers())
    .function("setAnimationName", &InnerActionFrame::setAnimationName, allow_raw_pointers())
    .class_function("create", &InnerActionFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const InnerActionFrame& _) -> std::string {return "InnerActionFrame";}))    
    ;


  class_<ColorFrame, base<Frame>>("ccs.ColorFrame")
    .constructor<>()
    .function("setColor", &ColorFrame::setColor, allow_raw_pointers())
    .function("getColor", &ColorFrame::getColor, allow_raw_pointers())
    .class_function("create", &ColorFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ColorFrame& _) -> std::string {return "ColorFrame";}))    
    ;


  class_<AlphaFrame, base<Frame>>("ccs.AlphaFrame")
    .constructor<>()
    .function("getAlpha", &AlphaFrame::getAlpha, allow_raw_pointers())
    .function("setAlpha", &AlphaFrame::setAlpha, allow_raw_pointers())
    .class_function("create", &AlphaFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AlphaFrame& _) -> std::string {return "AlphaFrame";}))    
    ;


  class_<EventFrame, base<Frame>>("ccs.EventFrame")
    .constructor<>()
    .function("setEvent", &EventFrame::setEvent, allow_raw_pointers())
    .function("init", &EventFrame::init, allow_raw_pointers())
    .function("getEvent", &EventFrame::getEvent, allow_raw_pointers())
    .class_function("create", &EventFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventFrame& _) -> std::string {return "EventFrame";}))    
    ;


  class_<ZOrderFrame, base<Frame>>("ccs.ZOrderFrame")
    .constructor<>()
    .function("getZOrder", &ZOrderFrame::getZOrder, allow_raw_pointers())
    .function("setZOrder", &ZOrderFrame::setZOrder, allow_raw_pointers())
    .class_function("create", &ZOrderFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ZOrderFrame& _) -> std::string {return "ZOrderFrame";}))    
    ;


  class_<BlendFuncFrame, base<Frame>>("ccs.BlendFuncFrame")
    .constructor<>()
    .function("getBlendFunc", &BlendFuncFrame::getBlendFunc, allow_raw_pointers())
    .function("setBlendFunc", &BlendFuncFrame::setBlendFunc, allow_raw_pointers())
    .class_function("create", &BlendFuncFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BlendFuncFrame& _) -> std::string {return "BlendFuncFrame";}))    
    ;


  class_<Timeline>("ccs.Timeline")
    .constructor<>()
    .function("clone", &Timeline::clone, allow_raw_pointers())
    .function("gotoFrame", &Timeline::gotoFrame, allow_raw_pointers())
    .function("setNode", &Timeline::setNode, allow_raw_pointers())
    .function("getActionTimeline", &Timeline::getActionTimeline, allow_raw_pointers())
    .function("insertFrame", &Timeline::insertFrame, allow_raw_pointers())
    .function("setActionTag", &Timeline::setActionTag, allow_raw_pointers())
    .function("addFrame", &Timeline::addFrame, allow_raw_pointers())
    .function("getFrames", &Timeline::getFrames, allow_raw_pointers())
    .function("getActionTag", &Timeline::getActionTag, allow_raw_pointers())
    .function("getNode", &Timeline::getNode, allow_raw_pointers())
    .function("removeFrame", &Timeline::removeFrame, allow_raw_pointers())
    .function("setActionTimeline", &Timeline::setActionTimeline, allow_raw_pointers())
    .function("stepToFrame", &Timeline::stepToFrame, allow_raw_pointers())
    .class_function("create", &Timeline::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Timeline& _) -> std::string {return "Timeline";}))    
    ;


  class_<ActionTimelineData>("ccs.ActionTimelineData")
    .constructor<>()
    .function("setActionTag", &ActionTimelineData::setActionTag, allow_raw_pointers())
    .function("init", &ActionTimelineData::init, allow_raw_pointers())
    .function("getActionTag", &ActionTimelineData::getActionTag, allow_raw_pointers())
    .class_function("create", &ActionTimelineData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTimelineData& _) -> std::string {return "ActionTimelineData";}))    
    ;


  class_<ActionTimeline, base<Action>>("ccs.ActionTimeline")
    .constructor<>()
    .function("setFrameEventCallFunc", &ActionTimeline::setFrameEventCallFunc, allow_raw_pointers())
    .function("clearFrameEndCallFuncs", &ActionTimeline::clearFrameEndCallFuncs, allow_raw_pointers())
    .function("setAnimationEndCallFunc", &ActionTimeline::setAnimationEndCallFunc, allow_raw_pointers())
    .function("addTimeline", &ActionTimeline::addTimeline, allow_raw_pointers())
    .function("getCurrentFrame", &ActionTimeline::getCurrentFrame, allow_raw_pointers())
    .function("getStartFrame", &ActionTimeline::getStartFrame, allow_raw_pointers())
    .function("pause", &ActionTimeline::pause, allow_raw_pointers())
    .function("init", &ActionTimeline::init, allow_raw_pointers())
    .function("removeTimeline", &ActionTimeline::removeTimeline, allow_raw_pointers())
    .function("setLastFrameCallFunc", &ActionTimeline::setLastFrameCallFunc, allow_raw_pointers())
    .function("isAnimationInfoExists", &ActionTimeline::IsAnimationInfoExists, allow_raw_pointers())
    .function("getTimelines", &ActionTimeline::getTimelines, allow_raw_pointers())
    .function("play", &ActionTimeline::play, allow_raw_pointers())
    .function("getAnimationInfo", &ActionTimeline::getAnimationInfo, allow_raw_pointers())
    .function("resume", &ActionTimeline::resume, allow_raw_pointers())
    .function("addFrameEndCallFunc", &ActionTimeline::addFrameEndCallFunc, allow_raw_pointers())
    .function("removeAnimationInfo", &ActionTimeline::removeAnimationInfo, allow_raw_pointers())
    .function("getTimeSpeed", &ActionTimeline::getTimeSpeed, allow_raw_pointers())
    .function("addAnimationInfo", &ActionTimeline::addAnimationInfo, allow_raw_pointers())
    .function("getDuration", &ActionTimeline::getDuration, allow_raw_pointers())
    .function("gotoFrameAndPause", &ActionTimeline::gotoFrameAndPause, allow_raw_pointers())
    .function("isPlaying", &ActionTimeline::isPlaying, allow_raw_pointers())
    .function("removeFrameEndCallFuncs", &ActionTimeline::removeFrameEndCallFuncs, allow_raw_pointers())
    .function("gotoFrameAndPlay", select_overload<void(int, bool)>(&ActionTimeline::gotoFrameAndPlay), allow_raw_pointers())
    .function("gotoFrameAndPlay", select_overload<void(int)>(&ActionTimeline::gotoFrameAndPlay), allow_raw_pointers())
    .function("gotoFrameAndPlay", select_overload<void(int, int, bool)>(&ActionTimeline::gotoFrameAndPlay), allow_raw_pointers())
    .function("gotoFrameAndPlay", select_overload<void(int, int, int, bool)>(&ActionTimeline::gotoFrameAndPlay), allow_raw_pointers())
    .function("clearFrameEventCallFunc", &ActionTimeline::clearFrameEventCallFunc, allow_raw_pointers())
    .function("getEndFrame", &ActionTimeline::getEndFrame, allow_raw_pointers())
    .function("setTimeSpeed", &ActionTimeline::setTimeSpeed, allow_raw_pointers())
    .function("clearLastFrameCallFunc", &ActionTimeline::clearLastFrameCallFunc, allow_raw_pointers())
    .function("setDuration", &ActionTimeline::setDuration, allow_raw_pointers())
    .function("setCurrentFrame", &ActionTimeline::setCurrentFrame, allow_raw_pointers())
    .function("removeFrameEndCallFunc", &ActionTimeline::removeFrameEndCallFunc, allow_raw_pointers())
    .class_function("create", &ActionTimeline::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTimeline& _) -> std::string {return "ActionTimeline";}))    
    ;


  class_<BoneNode, base<Node>>("ccs.BoneNode")
    .constructor<>()
    .function("getDebugDrawLength", &BoneNode::getDebugDrawLength, allow_raw_pointers())
    .function("getDebugDrawWidth", &BoneNode::getDebugDrawWidth, allow_raw_pointers())
    .function("displaySkin", select_overload<void(const std::string&, bool)>(&BoneNode::displaySkin), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getSkins", select_overload<cocos2d::Vector<cocos2d::Node *>&()>(&BoneNode::getSkins), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setDebugDrawEnabled", &BoneNode::setDebugDrawEnabled, allow_raw_pointers())
    .function("getRootSkeletonNode", &BoneNode::getRootSkeletonNode, allow_raw_pointers())
    .function("getAllSubSkins", &BoneNode::getAllSubSkins, allow_raw_pointers())
    .function("setDebugDrawColor", &BoneNode::setDebugDrawColor, allow_raw_pointers())
    .function("getDebugDrawColor", &BoneNode::getDebugDrawColor, allow_raw_pointers())
    .function("getVisibleSkinsRect", &BoneNode::getVisibleSkinsRect, allow_raw_pointers())
    .function("getChildBones", select_overload<cocos2d::Vector<cocostudio::timeline::BoneNode *>&()>(&BoneNode::getChildBones), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setDebugDrawWidth", &BoneNode::setDebugDrawWidth, allow_raw_pointers())
    .function("addSkin", select_overload<void(cocos2d::Node*, bool, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("addSkin", select_overload<void(cocos2d::Node*, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("getVisibleSkins", &BoneNode::getVisibleSkins, allow_raw_pointers())
    .function("getAllSubBones", &BoneNode::getAllSubBones, allow_raw_pointers())
    .function("isDebugDrawEnabled", &BoneNode::isDebugDrawEnabled, allow_raw_pointers())
    .function("setDebugDrawLength", &BoneNode::setDebugDrawLength, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<BoneNode>, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*(int)>(&BoneNode::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*()>(&BoneNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const BoneNode& _) -> std::string {return "BoneNode";}))    
    // TODO: assign cc.Class.extend to ccs.BoneNode.extend
    ;


  class_<SkeletonNode, base<BoneNode>>("ccs.SkeletonNode")
    .constructor<>()
    .function("getAllSubBonesMap", &SkeletonNode::getAllSubBonesMap, allow_raw_pointers())
    .function("changeSkins", select_overload<void(const std::string&)>(&SkeletonNode::changeSkins), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("addSkinGroup", &SkeletonNode::addSkinGroup, allow_raw_pointers())
    .function("getBoneNode", &SkeletonNode::getBoneNode, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SkeletonNode>, allow_raw_pointers())
    .class_function("create", &SkeletonNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkeletonNode& _) -> std::string {return "SkeletonNode";}))    
    // TODO: assign cc.Class.extend to ccs.SkeletonNode.extend
    ;


  class_<ComExtensionData, base<Component>>("ccs.ComExtensionData")
    .constructor<>()
    .function("setActionTag", &ComExtensionData::setActionTag, allow_raw_pointers())
    .function("getCustomProperty", &ComExtensionData::getCustomProperty, allow_raw_pointers())
    .function("getActionTag", &ComExtensionData::getActionTag, allow_raw_pointers())
    .function("setCustomProperty", &ComExtensionData::setCustomProperty, allow_raw_pointers())
    .class_function("create", &ComExtensionData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComExtensionData& _) -> std::string {return "ComExtensionData";}))    
    ;}