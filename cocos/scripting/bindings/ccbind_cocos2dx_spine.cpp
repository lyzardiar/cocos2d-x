#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_spine.hpp"
#include "editor-support/spine/spine-cocos2dx.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace spine;

COCOS_BINDINGS(ccbind_cocos2dx_spine) {


  class_<SkeletonRenderer, base<Node>>("sp.Skeleton")
        // TODO: overloaded constructor
    .function("setTimeScale", &SkeletonRenderer::setTimeScale)
    .function("getDebugSlotsEnabled", &SkeletonRenderer::getDebugSlotsEnabled)
    .function("setAttachment", select_overload<bool(const std::string&, const char*)>(&SkeletonRenderer::setAttachment), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setBonesToSetupPose", &SkeletonRenderer::setBonesToSetupPose)
    .function("initWithData", &SkeletonRenderer::initWithData, allow_raw_pointers())
    .function("initWithData", optional_override(
        [](SkeletonRenderer& this_, spSkeletonData* arg0){
        return this_.initWithData(arg0);
      }), allow_raw_pointers())
    .function("setDebugSlotsEnabled", &SkeletonRenderer::setDebugSlotsEnabled)
    .function("initWithJsonFile", select_overload<void(const std::string&, const std::string&, float)>(&SkeletonRenderer::initWithJsonFile))
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setSlotsToSetupPose", &SkeletonRenderer::setSlotsToSetupPose)
    .function("initWithBinaryFile", select_overload<void(const std::string&, const std::string&, float)>(&SkeletonRenderer::initWithBinaryFile))
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
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
    .function("setSkin", select_overload<bool(const char*)>(&SkeletonRenderer::setSkin), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("updateWorldTransform", &SkeletonRenderer::updateWorldTransform)
    .function("getSkeleton", &SkeletonRenderer::getSkeleton, allow_raw_pointers())
    .function("drawDebug", &SkeletonRenderer::drawDebug, allow_raw_pointers())
    .class_function("create", select_overload<spine::SkeletonRenderer*(const std::string&, spAtlas*, float)>(&SkeletonRenderer::createWithFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<spine::SkeletonRenderer*()>(&SkeletonRenderer::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const SkeletonRenderer& _) -> std::string {return "SkeletonRenderer";}))    
    ;


  class_<SkeletonAnimation, base<SkeletonRenderer>>("sp.SkeletonAnimation")
    .constructor<>()
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
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("createWithBinaryFile", select_overload<spine::SkeletonAnimation*(const std::string&, const std::string&, float)>(&SkeletonAnimation::createWithBinaryFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithJsonFile", select_overload<spine::SkeletonAnimation*(const std::string&, const std::string&, float)>(&SkeletonAnimation::createWithJsonFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const SkeletonAnimation& _) -> std::string {return "SkeletonAnimation";}))    
    .allow_subclass<emscripten::wrapper<SkeletonAnimation>>("_subclass.sp.SkeletonAnimation")
    ;
}
