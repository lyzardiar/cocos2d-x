#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_studio.hpp"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCComExtensionData.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocostudio;
using namespace cocostudio::timeline;

COCOS_BINDINGS(ccbind_cocos2dx_studio) {


  class_<ActionObject>("ccs.ActionObject")
    .constructor<>()
    .function("setCurrentTime", &ActionObject::setCurrentTime)
    .function("pause", &ActionObject::pause)
    .function("setName", &ActionObject::setName, allow_raw_pointers())
    .function("setUnitTime", &ActionObject::setUnitTime)
    .function("getTotalTime", &ActionObject::getTotalTime)
    .function("getName", &ActionObject::getName, allow_raw_pointers())
    .function("stop", &ActionObject::stop)
    .function("play", select_overload<void(cocos2d::CallFunc*)>(&ActionObject::play), allow_raw_pointers())
    .function("play", select_overload<void()>(&ActionObject::play))
    .function("getCurrentTime", &ActionObject::getCurrentTime)
    .function("removeActionNode", &ActionObject::removeActionNode, allow_raw_pointers())
    .function("getLoop", &ActionObject::getLoop)
    .function("initWithBinary", &ActionObject::initWithBinary, allow_raw_pointers())
    .function("addActionNode", &ActionObject::addActionNode, allow_raw_pointers())
    .function("getUnitTime", &ActionObject::getUnitTime)
    .function("isPlaying", &ActionObject::isPlaying)
    .function("updateToFrameByTime", &ActionObject::updateToFrameByTime)
    .function("setLoop", &ActionObject::setLoop)
    .function("simulationActionUpdate", &ActionObject::simulationActionUpdate)
    .property("_className",  optional_override([](const ActionObject& _) -> std::string {return "ActionObject";}))    
    ;

  class_<ActionManagerEx>("ccs.ActionManager")
    .function("stopActionByName", &ActionManagerEx::stopActionByName, allow_raw_pointers())
    .function("getActionByName", &ActionManagerEx::getActionByName, allow_raw_pointers())
    .function("getStudioVersionNumber", &ActionManagerEx::getStudioVersionNumber)
    .function("initWithBinary", &ActionManagerEx::initWithBinary, allow_raw_pointers())
    .function("playActionByName", select_overload<cocostudio::ActionObject*(const char*, const char*, cocos2d::CallFunc*)>(&ActionManagerEx::playActionByName), allow_raw_pointers())
    .function("playActionByName", select_overload<cocostudio::ActionObject*(const char*, const char*)>(&ActionManagerEx::playActionByName), allow_raw_pointers())
    .function("releaseActions", &ActionManagerEx::releaseActions)
    .class_function("destroyInstance", &ActionManagerEx::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &ActionManagerEx::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionManagerEx& _) -> std::string {return "ActionManagerEx";}))    
    ;


  class_<BaseData>("ccs.BaseData")
    .constructor<>()
    .function("getColor", &BaseData::getColor)
    .function("setColor", &BaseData::setColor)
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
    .function("getMovementCount", &AnimationData::getMovementCount)
    .function("addMovement", &AnimationData::addMovement, allow_raw_pointers())
    .class_function("create", &AnimationData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationData& _) -> std::string {return "AnimationData";}))    
    ;


  class_<ContourData>("ccs.ContourData")
    .constructor<>()
    .function("init", &ContourData::init)
    .function("addVertex", &ContourData::addVertex)
    .class_function("create", &ContourData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ContourData& _) -> std::string {return "ContourData";}))    
    ;


  class_<TextureData>("ccs.TextureData")
    .constructor<>()
    .function("getContourData", &TextureData::getContourData, allow_raw_pointers())
    .function("init", &TextureData::init)
    .function("addContourData", &TextureData::addContourData, allow_raw_pointers())
    .class_function("create", &TextureData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureData& _) -> std::string {return "TextureData";}))    
    ;


  class_<ProcessBase>("ccs.ProcessBase")
    .constructor<>()
    .function("play", &ProcessBase::play)
    .function("pause", &ProcessBase::pause)
    .function("getRawDuration", &ProcessBase::getRawDuration)
    .function("resume", &ProcessBase::resume)
    .function("setIsComplete", &ProcessBase::setIsComplete)
    .function("stop", &ProcessBase::stop)
    .function("update", &ProcessBase::update)
    .function("getCurrentFrameIndex", &ProcessBase::getCurrentFrameIndex)
    .function("isComplete", &ProcessBase::isComplete)
    .function("getCurrentPercent", &ProcessBase::getCurrentPercent)
    .function("setIsPause", &ProcessBase::setIsPause)
    .function("getProcessScale", &ProcessBase::getProcessScale)
    .function("isPause", &ProcessBase::isPause)
    .function("isPlaying", &ProcessBase::isPlaying)
    .function("setProcessScale", &ProcessBase::setProcessScale)
    .function("setIsPlaying", &ProcessBase::setIsPlaying)
    .property("_className",  optional_override([](const ProcessBase& _) -> std::string {return "ProcessBase";}))    
    ;


  class_<Tween, base<ProcessBase>>("ccs.Tween")
    .constructor<>()
    .function("getAnimation", &Tween::getAnimation, allow_raw_pointers())
    .function("gotoAndPause", &Tween::gotoAndPause)
    .function("play", select_overload<void (MovementBoneData *, int, int, int, int)>(&Tween::play), allow_raw_pointers())
    .function("gotoAndPlay", &Tween::gotoAndPlay)
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
    .function("getActive", &ColliderDetector::getActive)
    .function("getColliderBodyList", &ColliderDetector::getColliderBodyList)
    .function("updateTransform", &ColliderDetector::updateTransform)
    .function("removeAll", &ColliderDetector::removeAll)
    .function("init", select_overload<bool(cocostudio::Bone*)>(&ColliderDetector::init), allow_raw_pointers())
    .function("init", select_overload<bool()>(&ColliderDetector::init))
    .function("setActive", &ColliderDetector::setActive)
    .function("setBone", &ColliderDetector::setBone, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ColliderDetector*(cocostudio::Bone*)>(&ColliderDetector::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ColliderDetector*()>(&ColliderDetector::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ColliderDetector& _) -> std::string {return "ColliderDetector";}))    
    ;

  class_<DecorativeDisplay>("ccs.DecorativeDisplay")
    .function("getColliderDetector", &DecorativeDisplay::getColliderDetector, allow_raw_pointers())
    .function("getDisplay", &DecorativeDisplay::getDisplay, allow_raw_pointers())
    .function("setDisplay", &DecorativeDisplay::setDisplay, allow_raw_pointers())
    .function("init", &DecorativeDisplay::init)
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
    .function("getAnchorPointInPoints", &DisplayManager::getAnchorPointInPoints)
    .function("setCurrentDecorativeDisplay", &DisplayManager::setCurrentDecorativeDisplay, allow_raw_pointers())
    .function("getDisplayRenderNodeType", &DisplayManager::getDisplayRenderNodeType)
    .function("removeDisplay", &DisplayManager::removeDisplay)
    .function("setForceChangeDisplay", &DisplayManager::setForceChangeDisplay)
    .function("init", &DisplayManager::init, allow_raw_pointers())
    .function("getContentSize", &DisplayManager::getContentSize)
    .function("getBoundingBox", &DisplayManager::getBoundingBox)
    .function("addDisplay", select_overload<void(cocos2d::Node*, int)>(&DisplayManager::addDisplay), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("containPoint", select_overload<bool(float, float)>(&DisplayManager::containPoint))
    .function("containPoint", select_overload<bool(cocos2d::Vec2&)>(&DisplayManager::containPoint))
    .function("initDisplayList", &DisplayManager::initDisplayList, allow_raw_pointers())
    .function("changeDisplayWithIndex", &DisplayManager::changeDisplayWithIndex)
    .function("changeDisplayWithName", &DisplayManager::changeDisplayWithName)
    .function("isForceChangeDisplay", &DisplayManager::isForceChangeDisplay)
    .function("getDecorativeDisplayByIndex", &DisplayManager::getDecorativeDisplayByIndex, allow_raw_pointers())
    .function("getCurrentDisplayIndex", &DisplayManager::getCurrentDisplayIndex)
    .function("getAnchorPoint", &DisplayManager::getAnchorPoint)
    .function("getDecorativeDisplayList", &DisplayManager::getDecorativeDisplayList)
    .function("isVisible", &DisplayManager::isVisible)
    .function("setVisible", &DisplayManager::setVisible)
    .class_function("create", &DisplayManager::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DisplayManager& _) -> std::string {return "DisplayManager";}))    
    ;


  class_<Bone, base<Node>>("ccs.Bone")
    .constructor<>()
    .function("isTransformDirty", &Bone::isTransformDirty)
    .function("setBlendFunc", &Bone::setBlendFunc)
    .function("isIgnoreMovementBoneData", &Bone::isIgnoreMovementBoneData)
    .function("updateZOrder", &Bone::updateZOrder)
    .function("getDisplayRenderNode", &Bone::getDisplayRenderNode, allow_raw_pointers())
    .function("isBlendDirty", &Bone::isBlendDirty)
    .function("addChildBone", &Bone::addChildBone, allow_raw_pointers())
    .function("getWorldInfo", &Bone::getWorldInfo, allow_raw_pointers())
    .function("getTween", &Bone::getTween, allow_raw_pointers())
    .function("getParentBone", &Bone::getParentBone, allow_raw_pointers())
    .function("updateColor", &Bone::updateColor)
    .function("setTransformDirty", &Bone::setTransformDirty)
    .function("getDisplayRenderNodeType", &Bone::getDisplayRenderNodeType)
    .function("removeDisplay", &Bone::removeDisplay)
    .function("setBoneData", &Bone::setBoneData, allow_raw_pointers())
    .function("setParentBone", &Bone::setParentBone, allow_raw_pointers())
    .function("addDisplay", select_overload<void(cocos2d::Node*, int)>(&Bone::addDisplay), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setIgnoreMovementBoneData", &Bone::setIgnoreMovementBoneData)
    .function("getBlendFunc", &Bone::getBlendFunc)
    .function("removeFromParent", select_overload<void (bool)>(&Bone::removeFromParent))
    .function("getColliderDetector", &Bone::getColliderDetector, allow_raw_pointers())
    .function("getChildArmature", &Bone::getChildArmature, allow_raw_pointers())
    .function("changeDisplayWithIndex", &Bone::changeDisplayWithIndex)
    .function("changeDisplayWithName", &Bone::changeDisplayWithName)
    .function("setArmature", &Bone::setArmature, allow_raw_pointers())
    .function("setBlendDirty", &Bone::setBlendDirty)
    .function("removeChildBone", &Bone::removeChildBone, allow_raw_pointers())
    .function("setChildArmature", &Bone::setChildArmature, allow_raw_pointers())
    .function("getNodeToArmatureTransform", &Bone::getNodeToArmatureTransform)
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
    .function("getSpeedScale", &ArmatureAnimation::getSpeedScale)
    .function("play", select_overload<void (const std::string&, int, int)>(&ArmatureAnimation::play))
    .function("play", optional_override(
        [](ArmatureAnimation& this_, const std::string& arg0){
        return this_.play(arg0);
      }))
    .function("play", optional_override(
        [](ArmatureAnimation& this_, const std::string& arg0, int arg1){
        return this_.play(arg0, arg1);
      }))
    .function("gotoAndPause", &ArmatureAnimation::gotoAndPause)
    .function("playWithIndexes", &ArmatureAnimation::playWithIndexes)
    .function("playWithIndexes", optional_override(
        [](ArmatureAnimation& this_, const std::vector<int>& arg0){
        return this_.playWithIndexes(arg0);
      }))
    .function("playWithIndexes", optional_override(
        [](ArmatureAnimation& this_, const std::vector<int>& arg0, int arg1){
        return this_.playWithIndexes(arg0, arg1);
      }))
    .function("setAnimationData", &ArmatureAnimation::setAnimationData, allow_raw_pointers())
    .function("setSpeedScale", &ArmatureAnimation::setSpeedScale)
    .function("getAnimationData", &ArmatureAnimation::getAnimationData, allow_raw_pointers())
    .function("gotoAndPlay", &ArmatureAnimation::gotoAndPlay)
    .function("init", &ArmatureAnimation::init, allow_raw_pointers())
    .function("playWithNames", &ArmatureAnimation::playWithNames)
    .function("playWithNames", optional_override(
        [](ArmatureAnimation& this_, const std::vector<std::string>& arg0){
        return this_.playWithNames(arg0);
      }))
    .function("playWithNames", optional_override(
        [](ArmatureAnimation& this_, const std::vector<std::string>& arg0, int arg1){
        return this_.playWithNames(arg0, arg1);
      }))
    .function("getMovementCount", &ArmatureAnimation::getMovementCount)
    .function("playWithIndex", &ArmatureAnimation::playWithIndex)
    .function("playWithIndex", optional_override(
        [](ArmatureAnimation& this_, int arg0){
        return this_.playWithIndex(arg0);
      }))
    .function("playWithIndex", optional_override(
        [](ArmatureAnimation& this_, int arg0, int arg1){
        return this_.playWithIndex(arg0, arg1);
      }))
    .function("getCurrentMovementID", &ArmatureAnimation::getCurrentMovementID)
    .class_function("create", &ArmatureAnimation::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ArmatureAnimation& _) -> std::string {return "ArmatureAnimation";}))    
    ;

  class_<ArmatureDataManager>("ccs.ArmatureDataManager")
    .function("getAnimationDatas", &ArmatureDataManager::getAnimationDatas)
    .function("removeAnimationData", &ArmatureDataManager::removeAnimationData)
    .function("addArmatureData", &ArmatureDataManager::addArmatureData, allow_raw_pointers())
    .function("addArmatureData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::ArmatureData* arg1){
        return this_.addArmatureData(arg0, arg1);
      }), allow_raw_pointers())
    .function("addArmatureFileInfo", select_overload<void(const std::string&, const std::string&, const std::string&)>(&ArmatureDataManager::addArmatureFileInfo))
    .function("addArmatureFileInfo", select_overload<void(const std::string&)>(&ArmatureDataManager::addArmatureFileInfo))
    .function("removeArmatureFileInfo", &ArmatureDataManager::removeArmatureFileInfo)
    .function("getTextureData", &ArmatureDataManager::getTextureData, allow_raw_pointers())
    .function("getArmatureData", &ArmatureDataManager::getArmatureData, allow_raw_pointers())
    .function("getAnimationData", &ArmatureDataManager::getAnimationData, allow_raw_pointers())
    .function("addAnimationData", &ArmatureDataManager::addAnimationData, allow_raw_pointers())
    .function("addAnimationData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::AnimationData* arg1){
        return this_.addAnimationData(arg0, arg1);
      }), allow_raw_pointers())
    .function("init", &ArmatureDataManager::init)
    .function("removeArmatureData", &ArmatureDataManager::removeArmatureData)
    .function("getArmatureDatas", &ArmatureDataManager::getArmatureDatas)
    .function("removeTextureData", &ArmatureDataManager::removeTextureData)
    .function("addTextureData", &ArmatureDataManager::addTextureData, allow_raw_pointers())
    .function("addTextureData", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, cocostudio::TextureData* arg1){
        return this_.addTextureData(arg0, arg1);
      }), allow_raw_pointers())
    .function("isAutoLoadSpriteFile", &ArmatureDataManager::isAutoLoadSpriteFile)
    .function("addSpriteFrameFromFile", &ArmatureDataManager::addSpriteFrameFromFile)
    .function("addSpriteFrameFromFile", optional_override(
        [](ArmatureDataManager& this_, const std::string& arg0, const std::string& arg1){
        return this_.addSpriteFrameFromFile(arg0, arg1);
      }))
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
    .function("getArmatureTransformDirty", &Armature::getArmatureTransformDirty)
    .function("setVersion", &Armature::setVersion)
    .function("updateOffsetPoint", &Armature::updateOffsetPoint)
    .function("getParentBone", &Armature::getParentBone, allow_raw_pointers())
    .function("removeBone", &Armature::removeBone, allow_raw_pointers())
    .function("getBatchNode", &Armature::getBatchNode, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, cocostudio::Bone*)>(&Armature::init), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&)>(&Armature::init))
    .function("setParentBone", &Armature::setParentBone, allow_raw_pointers())
    .function("setBatchNode", &Armature::setBatchNode, allow_raw_pointers())
    .function("getBlendFunc", &Armature::getBlendFunc)
    .function("setArmatureData", &Armature::setArmatureData, allow_raw_pointers())
    .function("addBone", &Armature::addBone, allow_raw_pointers())
    .function("getArmatureData", &Armature::getArmatureData, allow_raw_pointers())
    .function("boundingBox", &Armature::getBoundingBox)
    .function("getVersion", &Armature::getVersion)
    .function("getAnimation", &Armature::getAnimation, allow_raw_pointers())
    .function("getOffsetPoints", &Armature::getOffsetPoints)
    .function("setBlendFunc", &Armature::setBlendFunc)
    .function("getBoneDic", &Armature::getBoneDic)
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
    .function("getNodeToWorldTransformAR", &Skin::getNodeToWorldTransformAR)
    .function("getDisplayName", &Skin::getDisplayName)
    .function("updateArmatureTransform", &Skin::updateArmatureTransform)
    .function("setBone", &Skin::setBone, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Skin*(const std::string&)>(&Skin::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Skin*()>(&Skin::create), allow_raw_pointers())
    .class_function("createWithSpriteFrameName", &Skin::createWithSpriteFrameName, allow_raw_pointers())
    .property("_className",  optional_override([](const Skin& _) -> std::string {return "Skin";}))    
    ;


  class_<ComAttribute, base<Component>>("ccs.ComAttribute")
    .constructor<>()
    .function("getFloat", &ComAttribute::getFloat)
    .function("getFloat", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getFloat(arg0);
      }))
    .function("getBool", &ComAttribute::getBool)
    .function("getBool", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getBool(arg0);
      }))
    .function("getString", &ComAttribute::getString)
    .function("getString", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getString(arg0);
      }))
    .function("setFloat", &ComAttribute::setFloat)
    .function("setString", &ComAttribute::setString)
    .function("setInt", &ComAttribute::setInt)
    .function("parse", &ComAttribute::parse)
    .function("getInt", &ComAttribute::getInt)
    .function("getInt", optional_override(
        [](ComAttribute& this_, const std::string& arg0){
        return this_.getInt(arg0);
      }))
    .function("setBool", &ComAttribute::setBool)
    .class_function("create", &ComAttribute::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComAttribute& _) -> std::string {return "ComAttribute";}))    
    ;


  class_<ComAudio, base<Component>>("ccs.ComAudio")
    .constructor<>()
    .function("stopAllEffects", &ComAudio::stopAllEffects)
    .function("getEffectsVolume", &ComAudio::getEffectsVolume)
    .function("stopEffect", &ComAudio::stopEffect)
    .function("getBackgroundMusicVolume", &ComAudio::getBackgroundMusicVolume)
    .function("willPlayBackgroundMusic", &ComAudio::willPlayBackgroundMusic)
    .function("setBackgroundMusicVolume", &ComAudio::setBackgroundMusicVolume)
    .function("end", &ComAudio::end)
    .function("start", &ComAudio::start)
    .function("stopBackgroundMusic", select_overload<void()>(&ComAudio::stopBackgroundMusic))
    .function("stopBackgroundMusic", select_overload<void(bool)>(&ComAudio::stopBackgroundMusic))
    .function("pauseBackgroundMusic", &ComAudio::pauseBackgroundMusic)
    .function("isBackgroundMusicPlaying", &ComAudio::isBackgroundMusicPlaying)
    .function("isLoop", &ComAudio::isLoop)
    .function("resumeAllEffects", &ComAudio::resumeAllEffects)
    .function("pauseAllEffects", &ComAudio::pauseAllEffects)
    .function("preloadBackgroundMusic", &ComAudio::preloadBackgroundMusic, allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void(const char*)>(&ComAudio::playBackgroundMusic), allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void(const char*, bool)>(&ComAudio::playBackgroundMusic), allow_raw_pointers())
    .function("playBackgroundMusic", select_overload<void()>(&ComAudio::playBackgroundMusic))
    .function("stop", &ComAudio::stop)
    .function("playEffect", select_overload<unsigned int(const char*)>(&ComAudio::playEffect), allow_raw_pointers())
    .function("playEffect", select_overload<unsigned int(const char*, bool)>(&ComAudio::playEffect), allow_raw_pointers())
    .function("playEffect", select_overload<unsigned int()>(&ComAudio::playEffect))
    .function("preloadEffect", &ComAudio::preloadEffect, allow_raw_pointers())
    .function("setLoop", &ComAudio::setLoop)
    .function("unloadEffect", &ComAudio::unloadEffect, allow_raw_pointers())
    .function("rewindBackgroundMusic", &ComAudio::rewindBackgroundMusic)
    .function("pauseEffect", &ComAudio::pauseEffect)
    .function("resumeBackgroundMusic", &ComAudio::resumeBackgroundMusic)
    .function("setFile", &ComAudio::setFile, allow_raw_pointers())
    .function("setEffectsVolume", &ComAudio::setEffectsVolume)
    .function("getFile", &ComAudio::getFile, allow_raw_pointers())
    .function("resumeEffect", &ComAudio::resumeEffect)
    .class_function("create", &ComAudio::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComAudio& _) -> std::string {return "ComAudio";}))    
    ;

  class_<InputDelegate>("ccs.InputDelegate")
    .function("isAccelerometerEnabled", &InputDelegate::isAccelerometerEnabled)
    .function("setKeypadEnabled", &InputDelegate::setKeypadEnabled)
    .function("getTouchMode", &InputDelegate::getTouchMode)
    .function("setAccelerometerEnabled", &InputDelegate::setAccelerometerEnabled)
    .function("isKeypadEnabled", &InputDelegate::isKeypadEnabled)
    .function("isTouchEnabled", &InputDelegate::isTouchEnabled)
    .function("setTouchPriority", &InputDelegate::setTouchPriority)
    .function("getTouchPriority", &InputDelegate::getTouchPriority)
    .function("setTouchEnabled", &InputDelegate::setTouchEnabled)
    .function("setTouchMode", &InputDelegate::setTouchMode)
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
    .function("setTweenType", &Frame::setTweenType)
    .function("setNode", &Frame::setNode, allow_raw_pointers())
    .function("setTimeline", &Frame::setTimeline, allow_raw_pointers())
    .function("isEnterWhenPassed", &Frame::isEnterWhenPassed)
    .function("getTweenType", &Frame::getTweenType)
    .function("getFrameIndex", &Frame::getFrameIndex)
    .function("apply", &Frame::apply)
    .function("isTween", &Frame::isTween)
    .function("setFrameIndex", &Frame::setFrameIndex)
    .function("setTween", &Frame::setTween)
    .function("getTimeline", &Frame::getTimeline, allow_raw_pointers())
    .function("getNode", &Frame::getNode, allow_raw_pointers())
    .property("_className",  optional_override([](const Frame& _) -> std::string {return "Frame";}))    
    ;


  class_<VisibleFrame, base<Frame>>("ccs.VisibleFrame")
    .constructor<>()
    .function("isVisible", &VisibleFrame::isVisible)
    .function("setVisible", &VisibleFrame::setVisible)
    .class_function("create", &VisibleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const VisibleFrame& _) -> std::string {return "VisibleFrame";}))    
    ;


  class_<TextureFrame, base<Frame>>("ccs.TextureFrame")
    .constructor<>()
    .function("getTextureName", &TextureFrame::getTextureName)
    .function("setTextureName", &TextureFrame::setTextureName)
    .class_function("create", &TextureFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureFrame& _) -> std::string {return "TextureFrame";}))    
    ;


  class_<RotationFrame, base<Frame>>("ccs.RotationFrame")
    .constructor<>()
    .function("setRotation", &RotationFrame::setRotation)
    .function("getRotation", &RotationFrame::getRotation)
    .class_function("create", &RotationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RotationFrame& _) -> std::string {return "RotationFrame";}))    
    ;


  class_<SkewFrame, base<Frame>>("ccs.SkewFrame")
    .constructor<>()
    .function("getSkewY", &SkewFrame::getSkewY)
    .function("setSkewX", &SkewFrame::setSkewX)
    .function("setSkewY", &SkewFrame::setSkewY)
    .function("getSkewX", &SkewFrame::getSkewX)
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
    .function("getX", &PositionFrame::getX)
    .function("getY", &PositionFrame::getY)
    .function("setPosition", &PositionFrame::setPosition)
    .function("setX", &PositionFrame::setX)
    .function("setY", &PositionFrame::setY)
    .function("getPosition", &PositionFrame::getPosition)
    .class_function("create", &PositionFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PositionFrame& _) -> std::string {return "PositionFrame";}))    
    ;


  class_<ScaleFrame, base<Frame>>("ccs.ScaleFrame")
    .constructor<>()
    .function("setScaleY", &ScaleFrame::setScaleY)
    .function("setScaleX", &ScaleFrame::setScaleX)
    .function("getScaleY", &ScaleFrame::getScaleY)
    .function("getScaleX", &ScaleFrame::getScaleX)
    .function("setScale", &ScaleFrame::setScale)
    .class_function("create", &ScaleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleFrame& _) -> std::string {return "ScaleFrame";}))    
    ;


  class_<AnchorPointFrame, base<Frame>>("ccs.AnchorPointFrame")
    .constructor<>()
    .function("setAnchorPoint", &AnchorPointFrame::setAnchorPoint)
    .function("getAnchorPoint", &AnchorPointFrame::getAnchorPoint)
    .class_function("create", &AnchorPointFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnchorPointFrame& _) -> std::string {return "AnchorPointFrame";}))    
    ;


  class_<InnerActionFrame, base<Frame>>("ccs.InnerActionFrame")
    .constructor<>()
    .function("getEndFrameIndex", &InnerActionFrame::getEndFrameIndex)
    .function("getStartFrameIndex", &InnerActionFrame::getStartFrameIndex)
    .function("getInnerActionType", &InnerActionFrame::getInnerActionType)
    .function("setEndFrameIndex", &InnerActionFrame::setEndFrameIndex)
    .function("setEnterWithName", &InnerActionFrame::setEnterWithName)
    .function("setSingleFrameIndex", &InnerActionFrame::setSingleFrameIndex)
    .function("setStartFrameIndex", &InnerActionFrame::setStartFrameIndex)
    .function("getSingleFrameIndex", &InnerActionFrame::getSingleFrameIndex)
    .function("setInnerActionType", &InnerActionFrame::setInnerActionType)
    .function("setAnimationName", &InnerActionFrame::setAnimationName)
    .class_function("create", &InnerActionFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const InnerActionFrame& _) -> std::string {return "InnerActionFrame";}))    
    ;


  class_<ColorFrame, base<Frame>>("ccs.ColorFrame")
    .constructor<>()
    .function("getColor", &ColorFrame::getColor)
    .function("setColor", &ColorFrame::setColor)
    .class_function("create", &ColorFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ColorFrame& _) -> std::string {return "ColorFrame";}))    
    ;


  class_<AlphaFrame, base<Frame>>("ccs.AlphaFrame")
    .constructor<>()
    .function("getAlpha", &AlphaFrame::getAlpha)
    .function("setAlpha", &AlphaFrame::setAlpha)
    .class_function("create", &AlphaFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AlphaFrame& _) -> std::string {return "AlphaFrame";}))    
    ;


  class_<EventFrame, base<Frame>>("ccs.EventFrame")
    .constructor<>()
    .function("setEvent", &EventFrame::setEvent)
    .function("init", &EventFrame::init)
    .function("getEvent", &EventFrame::getEvent)
    .class_function("create", &EventFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventFrame& _) -> std::string {return "EventFrame";}))    
    ;


  class_<ZOrderFrame, base<Frame>>("ccs.ZOrderFrame")
    .constructor<>()
    .function("getZOrder", &ZOrderFrame::getZOrder)
    .function("setZOrder", &ZOrderFrame::setZOrder)
    .class_function("create", &ZOrderFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ZOrderFrame& _) -> std::string {return "ZOrderFrame";}))    
    ;


  class_<BlendFuncFrame, base<Frame>>("ccs.BlendFuncFrame")
    .constructor<>()
    .function("getBlendFunc", &BlendFuncFrame::getBlendFunc)
    .function("setBlendFunc", &BlendFuncFrame::setBlendFunc)
    .class_function("create", &BlendFuncFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BlendFuncFrame& _) -> std::string {return "BlendFuncFrame";}))    
    ;


  class_<Timeline>("ccs.Timeline")
    .constructor<>()
    .function("clone", &Timeline::clone, allow_raw_pointers())
    .function("gotoFrame", &Timeline::gotoFrame)
    .function("setNode", &Timeline::setNode, allow_raw_pointers())
    .function("getActionTimeline", &Timeline::getActionTimeline, allow_raw_pointers())
    .function("insertFrame", &Timeline::insertFrame, allow_raw_pointers())
    .function("setActionTag", &Timeline::setActionTag)
    .function("addFrame", &Timeline::addFrame, allow_raw_pointers())
    .function("getFrames", &Timeline::getFrames)
    .function("getActionTag", &Timeline::getActionTag)
    .function("getNode", &Timeline::getNode, allow_raw_pointers())
    .function("removeFrame", &Timeline::removeFrame, allow_raw_pointers())
    .function("setActionTimeline", &Timeline::setActionTimeline, allow_raw_pointers())
    .function("stepToFrame", &Timeline::stepToFrame)
    .class_function("create", &Timeline::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Timeline& _) -> std::string {return "Timeline";}))    
    ;


  class_<ActionTimelineData>("ccs.ActionTimelineData")
    .constructor<>()
    .function("setActionTag", &ActionTimelineData::setActionTag)
    .function("init", &ActionTimelineData::init)
    .function("getActionTag", &ActionTimelineData::getActionTag)
    .class_function("create", &ActionTimelineData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTimelineData& _) -> std::string {return "ActionTimelineData";}))    
    ;


  class_<ActionTimeline, base<Action>>("ccs.ActionTimeline")
    .constructor<>()
    .function("setFrameEventCallFunc", &ActionTimeline::setFrameEventCallFunc)
    .function("clearFrameEndCallFuncs", &ActionTimeline::clearFrameEndCallFuncs)
    .function("setAnimationEndCallFunc", &ActionTimeline::setAnimationEndCallFunc)
    .function("addTimeline", &ActionTimeline::addTimeline, allow_raw_pointers())
    .function("getCurrentFrame", &ActionTimeline::getCurrentFrame)
    .function("getStartFrame", &ActionTimeline::getStartFrame)
    .function("pause", &ActionTimeline::pause)
    .function("start", &ActionTimeline::start)
    .function("init", &ActionTimeline::init)
    .function("removeTimeline", &ActionTimeline::removeTimeline, allow_raw_pointers())
    .function("setLastFrameCallFunc", &ActionTimeline::setLastFrameCallFunc)
    .function("isAnimationInfoExists", &ActionTimeline::IsAnimationInfoExists)
    .function("getTimelines", &ActionTimeline::getTimelines)
    .function("play", &ActionTimeline::play)
    .function("getAnimationInfo", &ActionTimeline::getAnimationInfo)
    .function("resume", &ActionTimeline::resume)
    .function("addFrameEndCallFunc", &ActionTimeline::addFrameEndCallFunc)
    .function("removeAnimationInfo", &ActionTimeline::removeAnimationInfo)
    .function("getTimeSpeed", &ActionTimeline::getTimeSpeed)
    .function("addAnimationInfo", &ActionTimeline::addAnimationInfo)
    .function("getDuration", &ActionTimeline::getDuration)
    .function("gotoFrameAndPause", &ActionTimeline::gotoFrameAndPause)
    .function("isPlaying", &ActionTimeline::isPlaying)
    .function("removeFrameEndCallFuncs", &ActionTimeline::removeFrameEndCallFuncs)
    .function("gotoFrameAndPlay", select_overload<void(int, bool)>(&ActionTimeline::gotoFrameAndPlay))
    .function("gotoFrameAndPlay", select_overload<void(int)>(&ActionTimeline::gotoFrameAndPlay))
    .function("gotoFrameAndPlay", select_overload<void(int, int, bool)>(&ActionTimeline::gotoFrameAndPlay))
    .function("gotoFrameAndPlay", select_overload<void(int, int, int, bool)>(&ActionTimeline::gotoFrameAndPlay))
    .function("clearFrameEventCallFunc", &ActionTimeline::clearFrameEventCallFunc)
    .function("getEndFrame", &ActionTimeline::getEndFrame)
    .function("setTimeSpeed", &ActionTimeline::setTimeSpeed)
    .function("clearLastFrameCallFunc", &ActionTimeline::clearLastFrameCallFunc)
    .function("setDuration", &ActionTimeline::setDuration)
    .function("setCurrentFrame", &ActionTimeline::setCurrentFrame)
    .function("removeFrameEndCallFunc", &ActionTimeline::removeFrameEndCallFunc)
    .class_function("create", &ActionTimeline::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTimeline& _) -> std::string {return "ActionTimeline";}))    
    ;


  class_<BoneNode, base<Node>>("ccs.BoneNode")
    .constructor<>()
    .function("getDebugDrawWidth", &BoneNode::getDebugDrawWidth)
    .function("getChildBones", select_overload<cocos2d::Vector<cocostudio::timeline::BoneNode *>&()>(&BoneNode::getChildBones))
    // TODO: Only support function overloading with different number of parameters
    .function("getBlendFunc", &BoneNode::getBlendFunc)
    .function("getAllSubBones", &BoneNode::getAllSubBones)
    .function("setBlendFunc", &BoneNode::setBlendFunc)
    .function("setDebugDrawEnabled", &BoneNode::setDebugDrawEnabled)
    .function("getVisibleSkinsRect", &BoneNode::getVisibleSkinsRect)
    .function("getAllSubSkins", &BoneNode::getAllSubSkins)
    .function("displaySkin", select_overload<void(const std::string&, bool)>(&BoneNode::displaySkin))
    // TODO: Only support function overloading with different number of parameters
    .function("isDebugDrawEnabled", &BoneNode::isDebugDrawEnabled)
    .function("addSkin", select_overload<void(cocos2d::Node*, bool, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("addSkin", select_overload<void(cocos2d::Node*, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("getRootSkeletonNode", &BoneNode::getRootSkeletonNode, allow_raw_pointers())
    .function("setDebugDrawLength", &BoneNode::setDebugDrawLength)
    .function("getSkins", select_overload<cocos2d::Vector<cocos2d::Node *>&()>(&BoneNode::getSkins))
    // TODO: Only support function overloading with different number of parameters
    .function("getVisibleSkins", &BoneNode::getVisibleSkins)
    .function("setDebugDrawWidth", &BoneNode::setDebugDrawWidth)
    .function("getDebugDrawLength", &BoneNode::getDebugDrawLength)
    .function("setDebugDrawColor", &BoneNode::setDebugDrawColor)
    .function("getDebugDrawColor", &BoneNode::getDebugDrawColor)
    .function("ctor", &cc_bindings_ctor<BoneNode>, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*(int)>(&BoneNode::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*()>(&BoneNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const BoneNode& _) -> std::string {return "BoneNode";}))    
    // TODO: assign cc.Class.extend to ccs.BoneNode.extend
    ;


  class_<SkeletonNode, base<BoneNode>>("ccs.SkeletonNode")
    .constructor<>()
    .function("getBoneNode", &SkeletonNode::getBoneNode, allow_raw_pointers())
    .function("changeSkins", select_overload<void(const std::string&)>(&SkeletonNode::changeSkins))
    // TODO: Only support function overloading with different number of parameters
    .function("addSkinGroup", &SkeletonNode::addSkinGroup)
    .function("getAllSubBonesMap", &SkeletonNode::getAllSubBonesMap)
    .function("ctor", &cc_bindings_ctor<SkeletonNode>, allow_raw_pointers())
    .class_function("create", &SkeletonNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkeletonNode& _) -> std::string {return "SkeletonNode";}))    
    // TODO: assign cc.Class.extend to ccs.SkeletonNode.extend
    ;


  class_<ComExtensionData, base<Component>>("ccs.ComExtensionData")
    .constructor<>()
    .function("setActionTag", &ComExtensionData::setActionTag)
    .function("getCustomProperty", &ComExtensionData::getCustomProperty)
    .function("getActionTag", &ComExtensionData::getActionTag)
    .function("setCustomProperty", &ComExtensionData::setCustomProperty)
    .class_function("create", &ComExtensionData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComExtensionData& _) -> std::string {return "ComExtensionData";}))    
    ;
}
