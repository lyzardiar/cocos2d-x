#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_studio.hpp"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCComExtensionData.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocostudio;
using namespace cocostudio::timeline;

CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::BoneData);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::Armature);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::FrameData);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::Bone);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::Tween);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::DisplayManager);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::ArmatureData);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::BatchNode);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::ArmatureAnimation);
#if ENABLE_PHYSICS_BOX2D_DETECT || ENABLE_PHYSICS_CHIPMUNK_DETECT
    CC_BINDINGS_ALLOW_RAW_POINTERS(cocostudio::ColliderFilter);
#endif

COCOS_BINDINGS(jsb_cocos2dx_studio) {

  value_object<AnimationInfo>("_.AnimationInfo")
    .field("startIndex", &AnimationInfo::startIndex)
    .field("endIndex", &AnimationInfo::endIndex)
    .field("name", &AnimationInfo::name)
    ;

  class_<ActionObject>("ccs.ActionObject")
    .constructor(&cc_bindings_constructor<ActionObject>, allow_raw_pointers())
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
    // from manual
    .function("initWithDictionaryEx", optional_override(
      [](ActionManagerEx& this_, const std::string& arg0, const std::string& arg1, Ref* arg2)
      {
        rapidjson::Document arg1Jsondoc;
        arg1Jsondoc.Parse<0>(arg1.c_str());
        if (arg1Jsondoc.HasParseError())
        {
            CCLOG("GetParseError %d\n",arg1Jsondoc.GetParseError());
        }
        this_.initWithDictionary(arg0.c_str(), arg1Jsondoc, arg2);
      }
    ), allow_raw_pointers())
    .function("initWithDictionaryEx", optional_override(
      [](ActionManagerEx& this_, const std::string& arg0, const std::string& arg1, Ref* arg2, int version)
      {
        rapidjson::Document arg1Jsondoc;
        arg1Jsondoc.Parse<0>(arg1.c_str());
        if (arg1Jsondoc.HasParseError())
        {
            CCLOG("GetParseError %d\n",arg1Jsondoc.GetParseError());
        }
        this_.initWithDictionary(arg0.c_str(), arg1Jsondoc, arg2, version);
      }
    ), allow_raw_pointers())
    // end of manual
    .class_function("destroyInstance", &ActionManagerEx::destroyInstance)
    .class_function("getInstance", &ActionManagerEx::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionManagerEx& _) -> std::string {return "ActionManagerEx";}))    
    ;


  class_<BaseData>("ccs.BaseData")
    .constructor(&cc_bindings_constructor<BaseData>, allow_raw_pointers())
    .function("getColor", &BaseData::getColor)
    .function("setColor", &BaseData::setColor)
    // from manaul
    .property("x", &BaseData::x)
    .property("y", &BaseData::y)
    .property("zOrder", &BaseData::zOrder)
    .property("skewX", &BaseData::skewX)
    .property("skewY", &BaseData::skewY)
    .property("scaleX", &BaseData::scaleX)
    .property("scaleY", &BaseData::scaleY)
    .property("tweenRotate", &BaseData::tweenRotate)
    .property("isUseColorInfo", &BaseData::isUseColorInfo)
    .property("a", &BaseData::a)
    .property("r", &BaseData::r)
    .property("g", &BaseData::g)
    .property("b", &BaseData::b)
    // end of manual
    .class_function("create", &BaseData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BaseData& _) -> std::string {return "BaseData";}))    
    ;


  class_<MovementData>("ccs.MovementData")
    .constructor(&cc_bindings_constructor<MovementData>, allow_raw_pointers())
    .function("getMovementBoneData", &MovementData::getMovementBoneData, allow_raw_pointers())
    .function("addMovementBoneData", &MovementData::addMovementBoneData, allow_raw_pointers())
    // from manaul
    .property("name", &MovementData::name)
    .property("duration", &MovementData::duration)
    .property("scale", &MovementData::scale)
    .property("durationTo", &MovementData::durationTo)
    .property("durationTween", &MovementData::durationTween)
    .property("loop", &MovementData::loop)
    .property("tweenEasing", &MovementData::tweenEasing)
    // end of manual
    .class_function("create", &MovementData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const MovementData& _) -> std::string {return "MovementData";}))    
    ;


  class_<AnimationData>("ccs.AnimationData")
    .constructor(&cc_bindings_constructor<AnimationData>, allow_raw_pointers())
    .function("getMovement", &AnimationData::getMovement, allow_raw_pointers())
    .function("getMovementCount", &AnimationData::getMovementCount)
    .function("addMovement", &AnimationData::addMovement, allow_raw_pointers())
    // from manaul
    .property("name", &AnimationData::name)
    .property("movementNames", &AnimationData::movementNames)
    .property("movementDataDic", &AnimationData::movementDataDic)
    // end of manual
    .class_function("create", &AnimationData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationData& _) -> std::string {return "AnimationData";}))    
    ;


  class_<ContourData>("ccs.ContourData")
    .constructor(&cc_bindings_constructor<ContourData>, allow_raw_pointers())
    .function("init", &ContourData::init)
    .function("addVertex", &ContourData::addVertex)
    // from manaul
    // NOTE: typo "vertextList"
    .property("vertextList", &ContourData::vertexList)
    // end of manual
    .class_function("create", &ContourData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ContourData& _) -> std::string {return "ContourData";}))    
    ;


  class_<TextureData>("ccs.TextureData")
    .constructor(&cc_bindings_constructor<TextureData>, allow_raw_pointers())
    .function("getContourData", &TextureData::getContourData, allow_raw_pointers())
    .function("init", &TextureData::init)
    .function("addContourData", &TextureData::addContourData, allow_raw_pointers())
    // from manaul
    .property("contourDataList", &TextureData::contourDataList)
    .property("name", &TextureData::name)
    .property("width", &TextureData::width)
    .property("height", &TextureData::height)
    .property("pivotX", &TextureData::pivotX)
    .property("pivotY", &TextureData::pivotY)
    // end of manual
    .class_function("create", &TextureData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureData& _) -> std::string {return "TextureData";}))    
    ;


  class_<ProcessBase>("ccs.ProcessBase")
    .constructor(&cc_bindings_constructor<ProcessBase>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<Tween>, allow_raw_pointers())
    .function("getAnimation", &Tween::getAnimation, allow_raw_pointers())
    .function("gotoAndPause", &Tween::gotoAndPause)
    .function("play", select_overload<void(MovementBoneData *, int, int, int, int)>(&Tween::play), allow_raw_pointers())
    .function("gotoAndPlay", &Tween::gotoAndPlay)
    .function("init", &Tween::init, allow_raw_pointers())
    .function("setAnimation", &Tween::setAnimation, allow_raw_pointers())
    .class_function("create", &Tween::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Tween& _) -> std::string {return "Tween";}))
    .allow_subclass<wrapper<Tween>>("ccs.Tween._extend")    
    ;

  class_<ColliderFilter>("ccs.ColliderFilter")
    .property("_className",  optional_override([](const ColliderFilter& _) -> std::string {return "ColliderFilter";}))    
    ;

  class_<ColliderBody>("ccs.ColliderBody")
    // from manual
    .function("getCalculatedVertexList", &ColliderBody::getCalculatedVertexList)
    // end of manual
    .property("_className",  optional_override([](const ColliderBody& _) -> std::string {return "ColliderBody";}))    
    ;

  auto colliderDetectorClazz = class_<ColliderDetector>("ccs.ColliderDetector")
    .function("getBone", &ColliderDetector::getBone, allow_raw_pointers())
    .function("getActive", &ColliderDetector::getActive)
    .function("getColliderBodyList", &ColliderDetector::getColliderBodyList)
    .function("updateTransform", &ColliderDetector::updateTransform)
    .function("removeAll", &ColliderDetector::removeAll)
    .function("init", select_overload<bool(cocostudio::Bone*)>(&ColliderDetector::init), allow_raw_pointers())
    .function("init", select_overload<bool()>(&ColliderDetector::init))
    .function("setActive", &ColliderDetector::setActive)
    .function("setBone", &ColliderDetector::setBone, allow_raw_pointers())
    .property("active", optional_override([](const ColliderDetector& this_)
      {
        return const_cast<ColliderDetector&>(this_).getActive();
      }), &ColliderDetector::setActive)
    .class_function("create", select_overload<cocostudio::ColliderDetector*(cocostudio::Bone*)>(&ColliderDetector::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ColliderDetector*()>(&ColliderDetector::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ColliderDetector& _) -> std::string {return "ColliderDetector";}))
    .allow_subclass<wrapper<ColliderDetector>>("ccs.ColliderDetector._extend")    
    ;
#if ENABLE_PHYSICS_BOX2D_DETECT || ENABLE_PHYSICS_CHIPMUNK_DETECT
    colliderDetectorClazz
      .property("body", &ColliderDetector::getBody, &ColliderDetector::setBody)
      .property("colliderFilter", optional_override([](const ColliderDetector& this_)
      {
        return const_cast<ColliderDetector&>(this_).getColliderFilter();
      }), &ColliderDetector::setColliderFilter);
#endif

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
    .allow_subclass<wrapper<DecorativeDisplay>>("ccs.DecorativeDisplay._extend")    
    ;


  class_<DisplayManager>("ccs.DisplayManager")
    .constructor(&cc_bindings_constructor<DisplayManager>, allow_raw_pointers())
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
    .function("addDisplay", optional_override(
      [](DisplayManager& this_, const val& arg0, int arg1){
      if (arg0["_className"].as<std::string>() != "Node")
      {
        return this_.addDisplay(arg0.as<cocostudio::DisplayData*>(allow_raw_pointers()), arg1);
      } else 
      {
        return this_.addDisplay(arg0.as<cocos2d::Node*>(allow_raw_pointers()), arg1);
      }
    }), allow_raw_pointers())
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
    .allow_subclass<wrapper<DisplayManager>>("ccs.DisplayManager._extend")    
    ;


  auto boneClazz = class_<Bone, base<Node>>("ccs.Bone")
    .constructor(&cc_bindings_constructor<Bone>, allow_raw_pointers())
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
    .function("addDisplay", optional_override(
      [](Bone& this_, const val& arg0, int arg1){
      if (arg0["_className"].as<std::string>() != "Node")
      {
        return this_.addDisplay(arg0.as<cocostudio::DisplayData*>(allow_raw_pointers()), arg1);
      } else 
      {
        return this_.addDisplay(arg0.as<cocos2d::Node*>(allow_raw_pointers()), arg1);
      }
    }), allow_raw_pointers())
    .function("setIgnoreMovementBoneData", &Bone::setIgnoreMovementBoneData)
    .function("getBlendFunc", &Bone::getBlendFunc)
    .function("removeFromParent", select_overload<void(bool)>(&Bone::removeFromParent))
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
    .property("boneData", &Bone::getBoneData, &Bone::setBoneData)
    .property("armature", &Bone::getArmature, &Bone::setArmature)
    .property("parentBone", optional_override([](const Bone& this_)
      {
        return const_cast<Bone&>(this_).getParentBone();
      }), &Bone::setParentBone)
    .property("childArmature", &Bone::getChildArmature, &Bone::setChildArmature)
    // cocos2d-js only
    // .property("childrenBone", &Bone::getChildrenBone)
    .property("tween", optional_override([](const Bone& this_)
      {
        return const_cast<Bone&>(this_).getTween();
      }))
    .property("tweenData", &Bone::getTweenData)
    .property("transformDirty", optional_override([](const Bone& this_)
      {
        return const_cast<Bone&>(this_).isTransformDirty();
      }), &Bone::setTransformDirty)
    .property("displayManager", &Bone::getDisplayManager)
    .property("ignoreMovementBoneData", &Bone::getIgnoreMovementBoneData, &Bone::setIgnoreMovementBoneData)
    .property("name", &Bone::getName, &Bone::setName)
    .property("blendDirty", optional_override([](const Bone& this_)
      {
        return const_cast<Bone&>(this_).isBlendDirty();
      }), &Bone::setBlendDirty)
    .class_function("create", select_overload<cocostudio::Bone*(const std::string&)>(&Bone::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Bone*()>(&Bone::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Bone& _) -> std::string {return "Bone";}))
    .allow_subclass<wrapper<Bone>>("ccs.Bone._extend")    
    ;
#if ENABLE_PHYSICS_BOX2D_DETECT || ENABLE_PHYSICS_CHIPMUNK_DETECT
    boneClazz.property("colliderFilter", optional_override([](const Bone& this_)
      {
        return const_cast<Bone&>(this_).getColliderFilter();
      }), &Bone::setColliderFilter);
#endif

  class_<BatchNode, base<Node>>("ccs.BatchNode")
    .class_function("create", &BatchNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BatchNode& _) -> std::string {return "BatchNode";}))
    .allow_subclass<wrapper<BatchNode>>("ccs.BatchNode._extend")    
    ;


  class_<ArmatureAnimation, base<ProcessBase>>("ccs.ArmatureAnimation")
    .constructor(&cc_bindings_constructor<ArmatureAnimation>, allow_raw_pointers())
    .function("getSpeedScale", &ArmatureAnimation::getSpeedScale)
    .function("play", select_overload<void(const std::string&, int, int)>(&ArmatureAnimation::play))
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
    // from manual
    .function("setMovementEventCallFunc", optional_override([](ArmatureAnimation& this_, const val& callback)
    {
      if (callback.isNull() || callback.isUndefined())
      {
        this_.setMovementEventCallFunc(nullptr);
      }
      else
      {
        this_.setMovementEventCallFunc([callback](Armature *armature, MovementEventType movementType, const std::string& movementID)
        {
          callback.call<void>("call", val::undefined(), val(armature), val(movementType), val(movementID));
        });
      }
    }))
    .function("setMovementEventCallFunc", optional_override([](ArmatureAnimation& this_, const val& callback, const val& thisv)
    {
      if (callback.isNull() || callback.isUndefined())
      {
        this_.setMovementEventCallFunc(nullptr);
      }
      else
      {
        this_.setMovementEventCallFunc([callback, thisv](Armature *armature, MovementEventType movementType, const std::string& movementID)
        {
          callback.call<void>("call", thisv, val(armature), val(movementType), val(movementID));
        });
      }
    }))
    .function("setFrameEventCallFunc", optional_override([](ArmatureAnimation& this_, const val& callback)
    {
      if (callback.isNull() || callback.isUndefined())
      {
        this_.setFrameEventCallFunc(nullptr);
      }
      else
      {
        this_.setFrameEventCallFunc([callback](Bone *bone, const std::string& frameEventName, int originFrameIndex, int currentFrameIndex)
        {
          callback.call<void>("call", val::undefined(), val(bone), val(frameEventName), val(originFrameIndex), val(currentFrameIndex));
        });
      }
    }))
    .function("setFrameEventCallFunc", optional_override([](ArmatureAnimation& this_, const val& callback, const val& thisv)
    {
      if (callback.isNull() || callback.isUndefined())
      {
        this_.setFrameEventCallFunc(nullptr);
      }
      else
      {
        this_.setFrameEventCallFunc([callback, thisv](Bone *bone, const std::string& frameEventName, int originFrameIndex, int currentFrameIndex)
        {
          callback.call<void>("call", thisv, val(bone), val(frameEventName), val(originFrameIndex), val(currentFrameIndex));
        });
      }
    }))
    // end of manual
    .class_function("create", &ArmatureAnimation::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ArmatureAnimation& _) -> std::string {return "ArmatureAnimation";}))
    .allow_subclass<wrapper<ArmatureAnimation>>("ccs.ArmatureAnimation._extend")    
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
    // from manual
    .function("addArmatureFileInfoAsync", optional_override([](ArmatureDataManager& this_, const std::string& arg0, const val& callback, const val& thisv)
    {
      SelectorWrapper* wrapper = SelectorWrapper::create(callback, thisv);
      this_.addArmatureFileInfoAsync(arg0, wrapper, schedule_selector(SelectorWrapper::schedule_callback));
    }))
    .function("addArmatureFileInfoAsync", optional_override([](ArmatureDataManager& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, const val& callback, const val& thisv)
    {
      SelectorWrapper* wrapper = SelectorWrapper::create(callback, thisv);
      this_.addArmatureFileInfoAsync(arg0, arg1, arg2, wrapper, schedule_selector(SelectorWrapper::schedule_callback));
    }))
    // end of manual
    .class_function("destroyInstance", &ArmatureDataManager::destroyInstance)
    .class_function("getInstance", &ArmatureDataManager::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const ArmatureDataManager& _) -> std::string {return "ArmatureDataManager";}))    
    ;


  auto armatureClazz = class_<Armature, base<Node>>("ccs.Armature")
    .constructor(&cc_bindings_constructor<Armature>, allow_raw_pointers())
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
    .property("parentBone", &Armature::getParentBone, &Armature::setParentBone)
    .property("animation", &Armature::getAnimation, &Armature::setAnimation)
    .property("armatureData", &Armature::getArmatureData, &Armature::setArmatureData)
    .property("name", &Armature::getName, &Armature::setName)
    .property("batchNode", &Armature::getBatchNode, &Armature::setBatchNode)
    .property("version", &Armature::getVersion, &Armature::setVersion)
    .class_function("create", select_overload<cocostudio::Armature*(const std::string&)>(&Armature::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Armature*()>(&Armature::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Armature*(const std::string&, cocostudio::Bone*)>(&Armature::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Armature& _) -> std::string {return "Armature";}))    
    .allow_subclass<wrapper<Armature>>("ccs.Armature._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;
#if ENABLE_PHYSICS_BOX2D_DETECT || ENABLE_PHYSICS_CHIPMUNK_DETECT
    armatureClazz
      .property("body", &Armature::getBody, &Armature::setBody)
      .property("colliderFilter", optional_override([](const Armature& this_)
      {
        CCLOG("Armature.colliderFilter is write-only");
        return nullptr;
      }), &Armature::setColliderFilter);
#endif

  class_<Skin, base<Sprite>>("ccs.Skin")
    .constructor(&cc_bindings_constructor<Skin>, allow_raw_pointers())
    .function("getBone", &Skin::getBone, allow_raw_pointers())
    .function("getNodeToWorldTransformAR", &Skin::getNodeToWorldTransformAR)
    .function("getDisplayName", &Skin::getDisplayName)
    .function("updateArmatureTransform", &Skin::updateArmatureTransform)
    .function("setBone", &Skin::setBone, allow_raw_pointers())
    .property("skinData", &Skin::getSkinData, &Skin::setSkinData)
    .property("bone", &Skin::getBone, &Skin::setBone)
    .property("displayName", &Skin::getDisplayName)
    .class_function("create", select_overload<cocostudio::Skin*(const std::string&)>(&Skin::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::Skin*()>(&Skin::create), allow_raw_pointers())
    .class_function("createWithSpriteFrameName", &Skin::createWithSpriteFrameName, allow_raw_pointers())
    .property("_className",  optional_override([](const Skin& _) -> std::string {return "Skin";}))
    .allow_subclass<wrapper<Skin>>("ccs.Skin._extend")    
    ;


  class_<ComAttribute, base<Component>>("ccs.ComAttribute")
    .constructor(&cc_bindings_constructor<ComAttribute>, allow_raw_pointers())
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
    .allow_subclass<wrapper<ComAttribute>>("ccs.ComAttribute._extend")    
    ;


  class_<ComAudio, base<Component>>("ccs.ComAudio")
    .constructor(&cc_bindings_constructor<ComAudio>, allow_raw_pointers())
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
    .allow_subclass<wrapper<ComAudio>>("ccs.ComAudio._extend")    
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
    .constructor(&cc_bindings_constructor<ComController>, allow_raw_pointers())
    .class_function("create", &ComController::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComController& _) -> std::string {return "ComController";}))    
    .allow_subclass<wrapper<ComController>>("ccs.ComController._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ComRender, base<Component>>("ccs.ComRender")
        // TODO: overloaded constructor
    .function("setNode", &ComRender::setNode, allow_raw_pointers())
    .function("getNode", &ComRender::getNode, allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ComRender*(cocos2d::Node*, const char*)>(&ComRender::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::ComRender*()>(&ComRender::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ComRender& _) -> std::string {return "ComRender";}))
    .allow_subclass<wrapper<ComRender>>("ccs.ComRender._extend")    
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
    // from manual
    .function("setEasingParams", &Frame::setEasingParams)
    .function("getEasingParams", &Frame::getEasingParams)
    // end of manual
    .property("_className",  optional_override([](const Frame& _) -> std::string {return "Frame";}))    
    ;


  class_<VisibleFrame, base<Frame>>("ccs.VisibleFrame")
    .constructor(&cc_bindings_constructor<VisibleFrame>, allow_raw_pointers())
    .function("isVisible", &VisibleFrame::isVisible)
    .function("setVisible", &VisibleFrame::setVisible)
    .class_function("create", &VisibleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const VisibleFrame& _) -> std::string {return "VisibleFrame";}))    
    ;


  class_<TextureFrame, base<Frame>>("ccs.TextureFrame")
    .constructor(&cc_bindings_constructor<TextureFrame>, allow_raw_pointers())
    .function("getTextureName", &TextureFrame::getTextureName)
    .function("setTextureName", &TextureFrame::setTextureName)
    .class_function("create", &TextureFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureFrame& _) -> std::string {return "TextureFrame";}))    
    ;


  class_<RotationFrame, base<Frame>>("ccs.RotationFrame")
    .constructor(&cc_bindings_constructor<RotationFrame>, allow_raw_pointers())
    .function("setRotation", &RotationFrame::setRotation)
    .function("getRotation", &RotationFrame::getRotation)
    .class_function("create", &RotationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RotationFrame& _) -> std::string {return "RotationFrame";}))    
    ;


  class_<SkewFrame, base<Frame>>("ccs.SkewFrame")
    .constructor(&cc_bindings_constructor<SkewFrame>, allow_raw_pointers())
    .function("getSkewY", &SkewFrame::getSkewY)
    .function("setSkewX", &SkewFrame::setSkewX)
    .function("setSkewY", &SkewFrame::setSkewY)
    .function("getSkewX", &SkewFrame::getSkewX)
    .class_function("create", &SkewFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewFrame& _) -> std::string {return "SkewFrame";}))    
    ;


  class_<RotationSkewFrame, base<SkewFrame>>("ccs.RotationSkewFrame")
    .constructor(&cc_bindings_constructor<RotationSkewFrame>, allow_raw_pointers())
    .class_function("create", &RotationSkewFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RotationSkewFrame& _) -> std::string {return "RotationSkewFrame";}))    
    ;


  class_<PositionFrame, base<Frame>>("ccs.PositionFrame")
    .constructor(&cc_bindings_constructor<PositionFrame>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<ScaleFrame>, allow_raw_pointers())
    .function("setScaleY", &ScaleFrame::setScaleY)
    .function("setScaleX", &ScaleFrame::setScaleX)
    .function("getScaleY", &ScaleFrame::getScaleY)
    .function("getScaleX", &ScaleFrame::getScaleX)
    .function("setScale", &ScaleFrame::setScale)
    .class_function("create", &ScaleFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleFrame& _) -> std::string {return "ScaleFrame";}))    
    ;


  class_<AnchorPointFrame, base<Frame>>("ccs.AnchorPointFrame")
    .constructor(&cc_bindings_constructor<AnchorPointFrame>, allow_raw_pointers())
    .function("setAnchorPoint", &AnchorPointFrame::setAnchorPoint)
    .function("getAnchorPoint", &AnchorPointFrame::getAnchorPoint)
    .class_function("create", &AnchorPointFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnchorPointFrame& _) -> std::string {return "AnchorPointFrame";}))    
    ;


  class_<InnerActionFrame, base<Frame>>("ccs.InnerActionFrame")
    .constructor(&cc_bindings_constructor<InnerActionFrame>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<ColorFrame>, allow_raw_pointers())
    .function("getColor", &ColorFrame::getColor)
    .function("setColor", &ColorFrame::setColor)
    .class_function("create", &ColorFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ColorFrame& _) -> std::string {return "ColorFrame";}))    
    ;


  class_<AlphaFrame, base<Frame>>("ccs.AlphaFrame")
    .constructor(&cc_bindings_constructor<AlphaFrame>, allow_raw_pointers())
    .function("getAlpha", &AlphaFrame::getAlpha)
    .function("setAlpha", &AlphaFrame::setAlpha)
    .class_function("create", &AlphaFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AlphaFrame& _) -> std::string {return "AlphaFrame";}))    
    ;


  class_<EventFrame, base<Frame>>("ccs.EventFrame")
    .constructor(&cc_bindings_constructor<EventFrame>, allow_raw_pointers())
    .function("setEvent", &EventFrame::setEvent)
    .function("init", &EventFrame::init)
    .function("getEvent", &EventFrame::getEvent)
    .class_function("create", &EventFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventFrame& _) -> std::string {return "EventFrame";}))    
    ;


  class_<ZOrderFrame, base<Frame>>("ccs.ZOrderFrame")
    .constructor(&cc_bindings_constructor<ZOrderFrame>, allow_raw_pointers())
    .function("getZOrder", &ZOrderFrame::getZOrder)
    .function("setZOrder", &ZOrderFrame::setZOrder)
    .class_function("create", &ZOrderFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ZOrderFrame& _) -> std::string {return "ZOrderFrame";}))    
    ;


  class_<BlendFuncFrame, base<Frame>>("ccs.BlendFuncFrame")
    .constructor(&cc_bindings_constructor<BlendFuncFrame>, allow_raw_pointers())
    .function("getBlendFunc", &BlendFuncFrame::getBlendFunc)
    .function("setBlendFunc", &BlendFuncFrame::setBlendFunc)
    .class_function("create", &BlendFuncFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const BlendFuncFrame& _) -> std::string {return "BlendFuncFrame";}))    
    ;


  class_<Timeline>("ccs.Timeline")
    .constructor(&cc_bindings_constructor<Timeline>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<ActionTimelineData>, allow_raw_pointers())
    .function("setActionTag", &ActionTimelineData::setActionTag)
    .function("init", &ActionTimelineData::init)
    .function("getActionTag", &ActionTimelineData::getActionTag)
    .class_function("create", &ActionTimelineData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTimelineData& _) -> std::string {return "ActionTimelineData";}))
    .allow_subclass<wrapper<ActionTimelineData>>("ccs.ActionTimelineData._extend")    
    ;


  class_<ActionTimeline, base<Action>>("ccs.ActionTimeline")
    .constructor(&cc_bindings_constructor<ActionTimeline>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<BoneNode>, allow_raw_pointers())
    .function("getDebugDrawWidth", &BoneNode::getDebugDrawWidth)
    .function("getChildBones", select_overload<cocos2d::Vector<cocostudio::timeline::BoneNode *>&()>(&BoneNode::getChildBones))
    .function("getBlendFunc", &BoneNode::getBlendFunc)
    .function("getAllSubBones", &BoneNode::getAllSubBones)
    .function("setBlendFunc", &BoneNode::setBlendFunc)
    .function("setDebugDrawEnabled", &BoneNode::setDebugDrawEnabled)
    .function("getVisibleSkinsRect", &BoneNode::getVisibleSkinsRect)
    .function("getAllSubSkins", &BoneNode::getAllSubSkins)
    .function("displaySkin", optional_override(
      [](BoneNode& this_, const val& arg0, bool arg1){
      if (!arg0.isString())
      {
        return this_.displaySkin(arg0.as<cocos2d::Node*>(allow_raw_pointers()), arg1);
      } else 
      {
        return this_.displaySkin(arg0.as<std::string>(), arg1);
      }
    }), allow_raw_pointers())
    .function("isDebugDrawEnabled", &BoneNode::isDebugDrawEnabled)
    .function("addSkin", select_overload<void(cocos2d::Node*, bool, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("addSkin", select_overload<void(cocos2d::Node*, bool)>(&BoneNode::addSkin), allow_raw_pointers())
    .function("getRootSkeletonNode", &BoneNode::getRootSkeletonNode, allow_raw_pointers())
    .function("setDebugDrawLength", &BoneNode::setDebugDrawLength)
    .function("getSkins", select_overload<cocos2d::Vector<cocos2d::Node *>&()>(&BoneNode::getSkins))
    .function("getVisibleSkins", &BoneNode::getVisibleSkins)
    .function("setDebugDrawWidth", &BoneNode::setDebugDrawWidth)
    .function("getDebugDrawLength", &BoneNode::getDebugDrawLength)
    .function("setDebugDrawColor", &BoneNode::setDebugDrawColor)
    .function("getDebugDrawColor", &BoneNode::getDebugDrawColor)
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*(int)>(&BoneNode::create), allow_raw_pointers())
    .class_function("create", select_overload<cocostudio::timeline::BoneNode*()>(&BoneNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const BoneNode& _) -> std::string {return "BoneNode";}))    
    .allow_subclass<wrapper<BoneNode>>("ccs.BoneNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<SkeletonNode, base<BoneNode>>("ccs.SkeletonNode")
    .constructor(&cc_bindings_constructor<SkeletonNode>, allow_raw_pointers())
    .function("getBoneNode", &SkeletonNode::getBoneNode, allow_raw_pointers())
    .function("changeSkins", optional_override(
      [](SkeletonNode& this_, const val& arg0){
      if (!arg0.isString())
      {
        return this_.changeSkins(arg0.as<const std::map<std::string, std::string>&>());
      } else 
      {
        return this_.changeSkins(arg0.as<std::string>());
      }
    }))
    .function("addSkinGroup", &SkeletonNode::addSkinGroup)
    .function("getAllSubBonesMap", &SkeletonNode::getAllSubBonesMap)
    .class_function("create", &SkeletonNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkeletonNode& _) -> std::string {return "SkeletonNode";}))    
    .allow_subclass<wrapper<SkeletonNode>>("ccs.SkeletonNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ComExtensionData, base<Component>>("ccs.ComExtensionData")
    .constructor(&cc_bindings_constructor<ComExtensionData>, allow_raw_pointers())
    .function("setActionTag", &ComExtensionData::setActionTag)
    .function("getCustomProperty", &ComExtensionData::getCustomProperty)
    .function("getActionTag", &ComExtensionData::getActionTag)
    .function("setCustomProperty", &ComExtensionData::setCustomProperty)
    .class_function("create", &ComExtensionData::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ComExtensionData& _) -> std::string {return "ComExtensionData";}))
    .allow_subclass<wrapper<ComExtensionData>>("ccs.ComExtensionData._extend")    
    ;
}

CC_BINDINGS_BYPASS_DESTRUCTOR(ArmatureDataManager);
CC_BINDINGS_BYPASS_DESTRUCTOR(Frame);
