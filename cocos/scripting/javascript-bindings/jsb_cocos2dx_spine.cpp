#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_spine.hpp"
#include "editor-support/spine/spine-cocos2dx.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace spine;

CC_BINDINGS_ALLOW_RAW_POINTERS(spEventData)
CC_BINDINGS_ALLOW_RAW_POINTERS(spBoneData)
CC_BINDINGS_ALLOW_RAW_POINTERS(spBone)
CC_BINDINGS_ALLOW_RAW_POINTERS(spColor)
CC_BINDINGS_ALLOW_RAW_POINTERS(spAttachment)
CC_BINDINGS_ALLOW_RAW_POINTERS(spSlotData)
CC_BINDINGS_ALLOW_RAW_POINTERS(spSkeletonData)

COCOS_BINDINGS(jsb_cocos2dx_spine) {
  // NOTE: we don't cache since we use getter here. Property only got boxed in js object when you read it.
  value_object<spEventData>("_.spEventData")
    .field("name", 
      optional_override([](const spEventData& this_) -> std::string {return this_.name;}), 
      optional_override([](spEventData& this_, const val& arg0) {CCLOG("spEventData.name is read-only");}))
    .field("intValue", &spEventData::intValue)
    .field("floatValue", &spEventData::floatValue)
    .field("stringValue", 
      optional_override([](const spEventData& this_) -> std::string {return this_.name;}), 
      optional_override([](spEventData& this_, const val& arg0) {CCLOG("spEventData.stringValue is read-only");}))
    ;

  value_object<spEvent>("_.spEvent")
    .field("data",
      optional_override([](const spEvent& this_) {return this_.data;}), 
      optional_override([](spEvent& this_, const val& arg0) {CCLOG("spEvent.data is read-only");}))
    .field("intValue", &spEvent::intValue)
    .field("floatValue", &spEvent::floatValue)
    .field("stringValue", 
      optional_override([](const spEvent& this_) -> std::string {return this_.stringValue;}), 
      optional_override([](spEvent& this_, const val& arg0) {CCLOG("spEvent.stringValue is read-only");}))
    ;

  value_object<spBoneData>("_.spBoneData")
    .field("parent", 
      optional_override([](const spBoneData& this_) {return this_.parent;}), 
      optional_override([](spBoneData& this_, const val& arg0) {CCLOG("spBoneData.parent is read-only");}))
    .field("index", 
      optional_override([](const spBoneData& this_) {return this_.index;}),
      optional_override([](spBoneData& this_, const val& arg0) {CCLOG("spBoneData.index is read-only");}))
    .field("name", 
      optional_override([](const spBoneData& this_) -> std::string {return this_.name;}), 
      optional_override([](spBoneData& this_, const val& arg0) {CCLOG("spBoneData.name is read-only");}))
    .field("length", &spBoneData::length)
    .field("x", &spBoneData::x)
    .field("y", &spBoneData::y)
    .field("rotation", &spBoneData::rotation)
    .field("scaleX", &spBoneData::scaleX)
    .field("scaleY", &spBoneData::scaleY)
    .field("shearX", &spBoneData::shearX)
    .field("shearY", &spBoneData::shearY)
    .field("transformMode", &spBoneData::transformMode)
    ;

  value_object<spBone>("_.spBone")
    .field("data",
      optional_override([](const spBone& this_) {return this_.data;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.data is read-only");}))
    .field("parent",
      optional_override([](const spBone& this_) {return this_.parent;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.parent is read-only");}))
    .field("x", &spBone::x)
    .field("y", &spBone::y)
    .field("rotation", &spBone::rotation)
    .field("scaleX", &spBone::scaleX)
    .field("scaleY", &spBone::scaleY)
    .field("shearX", &spBone::shearX)
    .field("shearY", &spBone::shearY)
    .field("m00", 
      optional_override([](const spBone& this_) {return this_.a;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.m00 is read-only");}))
    .field("m01", 
      optional_override([](const spBone& this_) {return this_.b;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.m01 is read-only");}))
    .field("worldX", 
      optional_override([](const spBone& this_) {return this_.worldX;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.worldX is read-only");}))
    .field("m10", 
      optional_override([](const spBone& this_) {return this_.c;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.m10 is read-only");}))
    .field("m11", 
      optional_override([](const spBone& this_) {return this_.d;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.m11 is read-only");}))
    .field("worldY", 
      optional_override([](const spBone& this_) {return this_.worldY;}), 
      optional_override([](spBone& this_, const val& arg0) {CCLOG("spBone.worldY is read-only");}))
    ;

  value_object<spSkeleton>("_.spSkeleton")
    .field("x", &spSkeleton::x)
    .field("y", &spSkeleton::y)
    .field("flipX", &spSkeleton::flipX)
    .field("flipY", &spSkeleton::flipY)
    .field("time", &spSkeleton::time)
    .field("boneCount", &spSkeleton::bonesCount)
    .field("slotCount", &spSkeleton::slotsCount)
    ;

  value_object<spAttachment>("_.spAttachment")
    .field("name", 
      optional_override([](const spAttachment& this_) -> std::string {return this_.name;}), 
      optional_override([](spAttachment& this_, const val& arg0) {CCLOG("spAttachment.name is read-only");}))
    .field("type",
      optional_override([](const spAttachment& this_) {return this_.type;}), 
      optional_override([](spAttachment& this_, const val& arg0) {CCLOG("spAttachment.type is read-only");}))
    ;

  value_object<spColor>("_.spColor")
    .field("r", &spColor::r)
    .field("g", &spColor::g)
    .field("b", &spColor::b)
    ;

  value_object<spSlotData>("_.spSlotData")
    .field("name", 
      optional_override([](const spSlotData& this_) -> std::string {return this_.name;}), 
      optional_override([](spSlotData& this_, const val& arg0) {CCLOG("spSlotData.name is read-only");}))
    .field("attachmentName", 
      optional_override([](const spSlotData& this_) -> std::string {return this_.attachmentName;}), 
      optional_override([](spSlotData& this_, const val& arg0) {CCLOG("spSlotData.attachmentName is read-only");}))
    .field("color", &spSlotData::color)
    .field("darkColor", &spSlotData::darkColor)
    .field("blendMode", &spSlotData::blendMode)
    .field("boneData", 
      optional_override([](const spSlotData& this_) {return const_cast<spBoneData*>(this_.boneData);}), 
      optional_override([](spSlotData& this_, const val& arg0) {CCLOG("spSlotData.boneData is read-only");}))
    .field("index", 
      optional_override([](const spSlotData& this_) {return this_.index;}), 
      optional_override([](spSlotData& this_, const val& arg0) {CCLOG("spSlotData.index is read-only");}))
    ;

  value_object<spSlot>("_.spSlot")
    .field("color", &spSlot::color)
    .field("darkColor", &spSlot::darkColor)
    .field("bone", 
      optional_override([](const spSlot& this_) {return this_.bone;}), 
      optional_override([](spSlot& this_, const val& arg0) {CCLOG("spSlot.bone is read-only");}))
    .field("attachment",
      optional_override([](const spSlot& this_) {return this_.attachment;}), 
      optional_override([](spSlot& this_, const val& arg0) {CCLOG("spSlot.attachment is read-only");}))
    .field("data", 
      optional_override([](const spSlot& this_) {return this_.data;}), 
      optional_override([](spSlot& this_, const val& arg0) {CCLOG("spSlot.data is read-only");}))
    .field("attachmentVerticesCapacity", &spSlot::attachmentVerticesCapacity)
    .field("attachmentVerticesCount", &spSlot::attachmentVerticesCount)
    .field("attachmentVertices", 
      optional_override(
        [](const spSlot& this_)
        {
          std::vector<float> ret(this_.attachmentVertices, this_.attachmentVertices + this_.attachmentVerticesCount);
          return ret;
        }
      ), 
      optional_override([](spSlot& this_, const val& arg0) {CCLOG("spSlot.attachmentVertices is read-only");}))
    ;

  value_object<spTimeline>("_.spTimeline")
    .field("type", 
      optional_override([](const spTimeline& this_) {return this_.type;}), 
      optional_override([](spTimeline& this_, const val& arg0) {CCLOG("spTimeline.type is read-only");}))
    ;

  value_object<spAnimationState>("_.spAnimationState")
    .field("timeScale", &spAnimationState::timeScale)
    .field("trackCount", &spAnimationState::tracksCount)
    ;

  value_object<spAnimation>("_.spAnimation")
    .field("duration", &spAnimation::duration)
    .field("timelineCount", &spAnimation::timelinesCount)
    .field("name", 
      optional_override([](const spAnimation& this_) -> std::string {return this_.name;}), 
      optional_override([](spAnimation& this_, const val& arg0) {CCLOG("spAnimation.name is read-only");}))
    .field("timelines", 
      optional_override(
        [](const spAnimation& this_)
        {
          std::vector<spTimeline*> ret(this_.timelines, this_.timelines + this_.timelinesCount);
          return ret;
        }
      ), 
      optional_override([](spAnimation& this_, const val& arg0) {CCLOG("spAnimation.timelines is read-only");}))
    ;

  class_<SkeletonRenderer, base<Node>>("sp.Skeleton")
    .constructor<>()
    .constructor(optional_override(
    [](const val& arg0, const val& arg1){
      if (!arg0.isString())
      {
        return new SkeletonRenderer(arg0.as<spSkeletonData*>(), arg1.as<bool>());
      }
      else if (arg1.isString())
      {
        return new SkeletonRenderer(arg0.as<std::string>(), arg1.as<std::string>());
      }
      else 
      {
        return new SkeletonRenderer(arg0.as<std::string>(), arg1.as<spAtlas*>(allow_raw_pointers()));
      }
    }), allow_raw_pointers())
    .constructor(optional_override(
    [](spSkeletonData* skeletonData){
      return new SkeletonRenderer(skeletonData);
    }), allow_raw_pointers())
    .constructor(optional_override(
      [](const std::string& arg0, const val& arg1, float arg2){
      if (arg1.isString())
      {
        return new SkeletonRenderer(arg0, arg1.as<std::string>(), arg2);
      } else 
      {
        return new SkeletonRenderer(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      }
      }), allow_raw_pointers())
    .function("setTimeScale", &SkeletonRenderer::setTimeScale)
    .function("getDebugSlotsEnabled", &SkeletonRenderer::getDebugSlotsEnabled)
    .function("setAttachment", select_overload<bool(const std::string&, const std::string&)>(&SkeletonRenderer::setAttachment), allow_raw_pointers())
    .function("setBonesToSetupPose", &SkeletonRenderer::setBonesToSetupPose)
    .function("initWithData", &SkeletonRenderer::initWithData, allow_raw_pointers())
    .function("initWithData", optional_override(
        [](SkeletonRenderer& this_, spSkeletonData* arg0){
        return this_.initWithData(arg0);
      }), allow_raw_pointers())
    .function("setDebugSlotsEnabled", &SkeletonRenderer::setDebugSlotsEnabled)
    .function("initWithJsonFile", optional_override(
        [](SkeletonRenderer& this_, const std::string& arg0, const val& arg1){
          if (!arg1.isString())
      {
      return this_.initWithJsonFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()));
      } else 
      {
      return this_.initWithJsonFile(arg0, arg1.as<std::string>());
      }
        }))
    .function("initWithJsonFile", optional_override(
      [](SkeletonRenderer& this_, const std::string& arg0, const val& arg1, float arg2){
      if (!arg1.isString())
      {
        return this_.initWithJsonFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      } else 
      {
        return this_.initWithJsonFile(arg0, arg1.as<std::string>(), arg2);
      }
    }), allow_raw_pointers())
    .function("setSlotsToSetupPose", &SkeletonRenderer::setSlotsToSetupPose)
    .function("initWithBinaryFile", optional_override(
        [](SkeletonRenderer& this_, const std::string& arg0, const val& arg1){
          if (!arg1.isString())
      {
      return this_.initWithBinaryFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()));
      } else 
      {
      return this_.initWithBinaryFile(arg0, arg1.as<std::string>());
      }
        }))
    .function("initWithBinaryFile", optional_override(
      [](SkeletonRenderer& this_, const std::string& arg0, const val& arg1, float arg2){
      if (!arg1.isString())
      {
        return this_.initWithBinaryFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      } else 
      {
        return this_.initWithBinaryFile(arg0, arg1.as<std::string>(), arg2);
      }
    }), allow_raw_pointers())
    .function("setToSetupPose", &SkeletonRenderer::setToSetupPose)
    .function("setDebugMeshesEnabled", &SkeletonRenderer::setDebugMeshesEnabled)
    .function("isTwoColorTint", &SkeletonRenderer::isTwoColorTint)
    .function("getBlendFunc", &SkeletonRenderer::getBlendFunc)
    .function("initialize", &SkeletonRenderer::initialize)
    .function("setDebugBonesEnabled", &SkeletonRenderer::setDebugBonesEnabled)
    .function("getDebugBonesEnabled", &SkeletonRenderer::getDebugBonesEnabled)
    .function("getTimeScale", &SkeletonRenderer::getTimeScale)
    .function("setTwoColorTint", &SkeletonRenderer::setTwoColorTint)
    .function("getDebugMeshesEnabled", &SkeletonRenderer::getDebugMeshesEnabled)
    .function("setBlendFunc", &SkeletonRenderer::setBlendFunc)
    .function("setVertexEffect", &SkeletonRenderer::setVertexEffect, allow_raw_pointers())
    .function("setSkin", optional_override(
      [](SkeletonRenderer& this_, const val& arg0){
      if (arg0.isString())
      {
        return this_.setSkin(arg0.as<std::string>());
      } else 
      {
        return this_.setSkin(arg0.as<const char*>(allow_raw_pointers()));
      }
    }))
    .function("updateWorldTransform", &SkeletonRenderer::updateWorldTransform)
    .function("getSkeleton", &SkeletonRenderer::getSkeleton, allow_raw_pointers())
    .function("drawDebug", &SkeletonRenderer::drawDebug, allow_raw_pointers())
    // from manual
    .function("findBone", &SkeletonRenderer::findBone, allow_raw_pointers())
    .function("findSlot", &SkeletonRenderer::findSlot, allow_raw_pointers())
    .function("setDebugBones", &SkeletonRenderer::setDebugBonesEnabled)
    .function("setDebugSolots", &SkeletonRenderer::setDebugSlotsEnabled)
    .function("getAttachment", &SkeletonRenderer::getAttachment, allow_raw_pointers())
    // end of manual
    .class_function("create", optional_override(
        [](const std::string& arg0, const val& arg1){
      if (arg1.isString())
      {
      return SkeletonRenderer::createWithFile(arg0, arg1.as<std::string>());
      } else 
      {
      return SkeletonRenderer::createWithFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()));
      }
        }), allow_raw_pointers())
    .class_function("create", select_overload<spine::SkeletonRenderer*()>(&SkeletonRenderer::create), allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0, const val& arg1, float arg2){
      if (arg1.isString())
      {
        return SkeletonRenderer::createWithFile(arg0, arg1.as<std::string>(), arg2);
      } else 
      {
        return SkeletonRenderer::createWithFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      }
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const SkeletonRenderer& _) -> std::string {return "SkeletonRenderer";}))    
    ;


  class_<SkeletonAnimation, base<SkeletonRenderer>>("sp.SkeletonAnimation")
    .constructor(&cc_bindings_constructor<SkeletonAnimation>, allow_raw_pointers())
    .function("setTrackCompleteListener", &SkeletonAnimation::setTrackCompleteListener, allow_raw_pointers())
    .function("findAnimation", &SkeletonAnimation::findAnimation, allow_raw_pointers())
    .function("setCompleteListener", &SkeletonAnimation::setCompleteListener)
    .function("setMix", &SkeletonAnimation::setMix)
    .function("setTrackStartListener", &SkeletonAnimation::setTrackStartListener, allow_raw_pointers())
    .function("addEmptyAnimation", &SkeletonAnimation::addEmptyAnimation, allow_raw_pointers())
    .function("addEmptyAnimation", optional_override(
        [](SkeletonAnimation& this_, int arg0, float arg1){
        return this_.addEmptyAnimation(arg0, arg1);
      }), allow_raw_pointers())
    .function("setDisposeListener", &SkeletonAnimation::setDisposeListener)
    .function("setTrackInterruptListener", &SkeletonAnimation::setTrackInterruptListener, allow_raw_pointers())
    .function("onTrackEntryEvent", &SkeletonAnimation::onTrackEntryEvent, allow_raw_pointers())
    .function("setEndListener", &SkeletonAnimation::setEndListener)
    .function("getState", &SkeletonAnimation::getState, allow_raw_pointers())
    .function("setTrackDisposeListener", &SkeletonAnimation::setTrackDisposeListener, allow_raw_pointers())
    .function("setEventListener", &SkeletonAnimation::setEventListener)
    .function("setEmptyAnimation", &SkeletonAnimation::setEmptyAnimation, allow_raw_pointers())
    .function("setTrackEventListener", &SkeletonAnimation::setTrackEventListener, allow_raw_pointers())
    .function("clearTrack", &SkeletonAnimation::clearTrack)
    .function("clearTrack", optional_override(
        [](SkeletonAnimation& this_){
        return this_.clearTrack();
      }))
    .function("setInterruptListener", &SkeletonAnimation::setInterruptListener)
    .function("onAnimationStateEvent", &SkeletonAnimation::onAnimationStateEvent, allow_raw_pointers())
    .function("setEmptyAnimations", &SkeletonAnimation::setEmptyAnimations)
    .function("clearTracks", &SkeletonAnimation::clearTracks)
    .function("setTrackEndListener", &SkeletonAnimation::setTrackEndListener, allow_raw_pointers())
    .function("setStartListener", &SkeletonAnimation::setStartListener)
    // from manual
    .function("getCurrent", &SkeletonAnimation::getCurrent, allow_raw_pointers())
    .function("setAnimation", &SkeletonAnimation::setAnimation, allow_raw_pointers())
    .function("addAnimation", &SkeletonAnimation::addAnimation, allow_raw_pointers())
    // end of manual
    .class_function("createWithBinaryFile", optional_override(
        [](const std::string& arg0, const val& arg1){
      if (!arg1.isString())
      {
      return SkeletonAnimation::createWithBinaryFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()));
      } else 
      {
      return SkeletonAnimation::createWithBinaryFile(arg0, arg1.as<std::string>());
      }
        }), allow_raw_pointers())
    .class_function("createWithBinaryFile", optional_override(
      [](const std::string& arg0, const val& arg1, float arg2){
      if (!arg1.isString())
      {
        return SkeletonAnimation::createWithBinaryFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      } else 
      {
        return SkeletonAnimation::createWithBinaryFile(arg0, arg1.as<std::string>(), arg2);
      }
      }), allow_raw_pointers())
    .class_function("createWithJsonFile", optional_override(
        [](const std::string& arg0, const val& arg1){
      if (!arg1.isString())
      {
      return SkeletonAnimation::createWithJsonFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()));
      } else 
      {
      return SkeletonAnimation::createWithJsonFile(arg0, arg1.as<std::string>());
      }
        }), allow_raw_pointers())
    .class_function("createWithJsonFile", optional_override(
      [](const std::string& arg0, const val& arg1, float arg2){
      if (!arg1.isString())
      {
        return SkeletonAnimation::createWithJsonFile(arg0, arg1.as<spAtlas*>(allow_raw_pointers()), arg2);
      } else 
      {
        return SkeletonAnimation::createWithJsonFile(arg0, arg1.as<std::string>(), arg2);
      }
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const SkeletonAnimation& _) -> std::string {return "SkeletonAnimation";}))    
    .allow_subclass<wrapper<SkeletonAnimation>>("sp.SkeletonAnimation._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;
}