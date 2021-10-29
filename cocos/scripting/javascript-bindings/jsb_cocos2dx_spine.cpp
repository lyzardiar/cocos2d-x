#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_spine.hpp"
#include "editor-support/spine/spine-cocos2dx.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace spine;

COCOS_BINDINGS(jsb_cocos2dx_spine) {

  value_object<spEventData>("_.spEventData")
    .field("name", 
      optional_override([](const spEventData& this_) -> std::string {return this_.name;}), 
      optional_override([](const spEventData& this_, const std::string& arg0) {CCLOG("spEventData.name is read-only");}))
    .field("intValue", &spEventData::intValue)
    .field("floatValue", &spEventData::floatValue)
    .field("stringValue", 
      optional_override([](const spEventData& this_) -> std::string {return this_.name;}), 
      optional_override([](const spEventData& this_, const std::string& arg0) {CCLOG("spEventData.stringValue is read-only");}))
    ;
/*
  value_object<spEvent>("_.spEvent")
    .field("data", &spEvent::data)
    .field("intValue", &spEvent::intValue)
    .field("floatValue", &spEvent::floatValue)
    .field("stringValue", &spEvent::stringValue)
    ;

  value_object<spBoneData>("_.spBoneData")
    .field("parent", &spBoneData::parent)
    .field("index", &spBoneData::index)
    .field("name", &spBoneData::name)
    .field("parent", &spBoneData::parent)
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
    .field("data", &spBone::data)
    .field("parent", &spBone::parent)
    .field("x", &spBone::x)
    .field("y", &spBone::y)
    .field("rotation", &spBone::rotation)
    .field("scaleX", &spBone::scaleX)
    .field("scaleY", &spBone::scaleY)
    .field("shearX", &spBone::shearX)
    .field("shearY", &spBone::shearY)
    .field("m00", &spBone::a)
    .field("m01", &spBone::b)
    .field("worldX", &spBone::worldX)
    .field("m10", &spBone::c)
    .field("m11", &spBone::d)
    .field("worldY", &spBone::worldY)
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
    .field("name", &spAttachment::name)
    .field("type", &spAttachment::type)
    ;

  value_object<spColor>("_.spColor")
    .field("r", &spColor::r)
    .field("g", &spColor::g)
    .field("b", &spColor::b)
    ;

  value_object<spSlotData>("_.spSlotData")
    .field("name", &spSlotData::name)
    .field("attachmentName", &spSlotData::attachmentName)
    .field("color", &spSlotData::color)
    .field("darkColor", &spSlotData::darkColor)
    .field("blendMode", &spSlotData::blendMode)
    .field("boneData", &spSlotData::boneData)
    .field("index", &spSlotData::index)
    ;

  value_object<spSlot>("_.spSlot")
    .field("color", &spSlot::color)
    .field("darkColor", &spSlot::darkColor)
    .field("bone", &spSlot::bone)
    .field("attachment", &spSlot::attachment)
    .field("data", &spSlot::data)
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
    optional_override(
      [](const spSlot& this_, const std::vector<float> arg0)
      {
        
      }
    )
    )
    ;

  value_object<spTimeline>("_.spTimeline")
    .field("type", &spTimeline::type)
    ;

  value_object<spAnimationState>("_.spAnimationState")
    .field("timeScale", &spAnimationState::timeScale)
    .field("trackCount", &spAnimationState::tracksCount)
    ;

  value_object<spAnimation>("_.spAnimation")
    .field("duration", &spAnimation::duration)
    .field("timelineCount", &spAnimation::timelinesCount)
    .field("name", &spAnimation::name)
    .field("timelines", &spAnimation::timelines)
    ;
*/

  class_<SkeletonRenderer, base<Node>>("sp.Skeleton")
        // TODO: overloaded constructor
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