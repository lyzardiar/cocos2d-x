#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_spine.hpp"
#include "editor-support/spine/spine-cocos2dx.h"
#include "scripting/js-bindings/manual/spine/jsb_cocos2dx_spine_manual.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_spine) {


  class_<SkeletonRenderer, base<Node>>("sp.Skeleton")
        // TODO: overloaded constructor
    .function("setTimeScale", &SkeletonRenderer::setTimeScale, allow_raw_pointers())
    .function("getDebugSlotsEnabled", &SkeletonRenderer::getDebugSlotsEnabled, allow_raw_pointers())
    .function("setAttachment", select_overload<bool(const std::string&, const char*)>(&SkeletonRenderer::setAttachment), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setBonesToSetupPose", &SkeletonRenderer::setBonesToSetupPose, allow_raw_pointers())
    .function("initWithData", &SkeletonRenderer::initWithData, allow_raw_pointers())
    .function("initWithData", optional_override(
        [](SkeletonRenderer& this_, spSkeletonData* arg0){
        return this_.initWithData(arg0);
      }), allow_raw_pointers())
    .function("setDebugSlotsEnabled", &SkeletonRenderer::setDebugSlotsEnabled, allow_raw_pointers())
    .function("initWithJsonFile", select_overload<void(const std::string&, const std::string&, float)>(&SkeletonRenderer::initWithJsonFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setSlotsToSetupPose", &SkeletonRenderer::setSlotsToSetupPose, allow_raw_pointers())
    .function("initWithBinaryFile", select_overload<void(const std::string&, const std::string&, float)>(&SkeletonRenderer::initWithBinaryFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setToSetupPose", &SkeletonRenderer::setToSetupPose, allow_raw_pointers())
    .function("setDebugMeshesEnabled", &SkeletonRenderer::setDebugMeshesEnabled, allow_raw_pointers())
    .function("isTwoColorTint", &SkeletonRenderer::isTwoColorTint, allow_raw_pointers())
    .function("initialize", &SkeletonRenderer::initialize, allow_raw_pointers())
    .function("setDebugBonesEnabled", &SkeletonRenderer::setDebugBonesEnabled, allow_raw_pointers())
    .function("getDebugBonesEnabled", &SkeletonRenderer::getDebugBonesEnabled, allow_raw_pointers())
    .function("getTimeScale", &SkeletonRenderer::getTimeScale, allow_raw_pointers())
    .function("setTwoColorTint", &SkeletonRenderer::setTwoColorTint, allow_raw_pointers())
    .function("getDebugMeshesEnabled", &SkeletonRenderer::getDebugMeshesEnabled, allow_raw_pointers())
    .function("setVertexEffect", &SkeletonRenderer::setVertexEffect, allow_raw_pointers())
    .function("setSkin", select_overload<bool(const char*)>(&SkeletonRenderer::setSkin), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("updateWorldTransform", &SkeletonRenderer::updateWorldTransform, allow_raw_pointers())
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
    .function("setCompleteListener", &SkeletonAnimation::setCompleteListener, allow_raw_pointers())
    .function("setMix", &SkeletonAnimation::setMix, allow_raw_pointers())
    .function("setTrackStartListener", &SkeletonAnimation::setTrackStartListener, allow_raw_pointers())
    .function("addEmptyAnimation", &SkeletonAnimation::addEmptyAnimation, allow_raw_pointers())
    .function("addEmptyAnimation", optional_override(
        [](SkeletonAnimation& this_, int arg0, float arg1){
        return this_.addEmptyAnimation(arg0, arg1);
      }), allow_raw_pointers())
    .function("setDisposeListener", &SkeletonAnimation::setDisposeListener, allow_raw_pointers())
    .function("setTrackInterruptListener", &SkeletonAnimation::setTrackInterruptListener, allow_raw_pointers())
    .function("onTrackEntryEvent", &SkeletonAnimation::onTrackEntryEvent, allow_raw_pointers())
    .function("setEndListener", &SkeletonAnimation::setEndListener, allow_raw_pointers())
    .function("getState", &SkeletonAnimation::getState, allow_raw_pointers())
    .function("setTrackDisposeListener", &SkeletonAnimation::setTrackDisposeListener, allow_raw_pointers())
    .function("setEventListener", &SkeletonAnimation::setEventListener, allow_raw_pointers())
    .function("setEmptyAnimation", &SkeletonAnimation::setEmptyAnimation, allow_raw_pointers())
    .function("setTrackEventListener", &SkeletonAnimation::setTrackEventListener, allow_raw_pointers())
    .function("clearTrack", &SkeletonAnimation::clearTrack, allow_raw_pointers())
    .function("clearTrack", optional_override(
        [](SkeletonAnimation& this_){
        return this_.clearTrack();
      }), allow_raw_pointers())
    .function("setInterruptListener", &SkeletonAnimation::setInterruptListener, allow_raw_pointers())
    .function("onAnimationStateEvent", &SkeletonAnimation::onAnimationStateEvent, allow_raw_pointers())
    .function("setEmptyAnimations", &SkeletonAnimation::setEmptyAnimations, allow_raw_pointers())
    .function("clearTracks", &SkeletonAnimation::clearTracks, allow_raw_pointers())
    .function("setTrackEndListener", &SkeletonAnimation::setTrackEndListener, allow_raw_pointers())
    .function("setStartListener", &SkeletonAnimation::setStartListener, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SkeletonAnimation>, allow_raw_pointers())
    .class_function("createWithBinaryFile", select_overload<spine::SkeletonAnimation*(const std::string&, const std::string&, float)>(&SkeletonAnimation::createWithBinaryFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<spine::SkeletonAnimation*()>(&SkeletonAnimation::create), allow_raw_pointers())
    .class_function("createWithJsonFile", select_overload<spine::SkeletonAnimation*(const std::string&, const std::string&, float)>(&SkeletonAnimation::createWithJsonFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const SkeletonAnimation& _) -> std::string {return "SkeletonAnimation";}))    
    // TODO: assign cc.Class.extend to sp.SkeletonAnimation.extend
    ;}