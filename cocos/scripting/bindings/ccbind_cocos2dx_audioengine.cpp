#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_audioengine.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_EMSCRIPTEN)
#include "audio/include/AudioEngine.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::experimental;

COCOS_BINDINGS(ccbind_cocos2dx_audioengine) {


  class_<AudioProfile>("jsb.AudioProfile")
    .constructor<>()
    // TODO: Emscripten cannot automatically call destructor.
    .property("name", &AudioProfile::name)
    .property("maxInstances", &AudioProfile::maxInstances)
    .property("minDelay", &AudioProfile::minDelay)
    .property("_className",  optional_override([](const AudioProfile& _) -> std::string {return "AudioProfile";}))    
    ;

  class_<AudioEngine>("jsb.AudioEngine")
    .class_function("lazyInit", &AudioEngine::lazyInit, allow_raw_pointers())
    .class_function("setCurrentTime", &AudioEngine::setCurrentTime, allow_raw_pointers())
    .class_function("getVolume", &AudioEngine::getVolume, allow_raw_pointers())
    .class_function("uncache", &AudioEngine::uncache, allow_raw_pointers())
    .class_function("resumeAll", &AudioEngine::resumeAll, allow_raw_pointers())
    .class_function("stopAll", &AudioEngine::stopAll, allow_raw_pointers())
    .class_function("pause", &AudioEngine::pause, allow_raw_pointers())
    .class_function("end", &AudioEngine::end, allow_raw_pointers())
    .class_function("getMaxAudioInstance", &AudioEngine::getMaxAudioInstance, allow_raw_pointers())
    .class_function("isEnabled", &AudioEngine::isEnabled, allow_raw_pointers())
    .class_function("getCurrentTime", &AudioEngine::getCurrentTime, allow_raw_pointers())
    .class_function("setMaxAudioInstance", &AudioEngine::setMaxAudioInstance, allow_raw_pointers())
    .class_function("isLoop", &AudioEngine::isLoop, allow_raw_pointers())
    .class_function("pauseAll", &AudioEngine::pauseAll, allow_raw_pointers())
    .class_function("uncacheAll", &AudioEngine::uncacheAll, allow_raw_pointers())
    .class_function("setVolume", &AudioEngine::setVolume, allow_raw_pointers())
    .class_function("preload", select_overload<void(const std::string&, const std::function<void (bool)>&)>(&AudioEngine::preload), allow_raw_pointers())
    .class_function("preload", select_overload<void(const std::string&)>(&AudioEngine::preload), allow_raw_pointers())
    .class_function("setEnabled", &AudioEngine::setEnabled, allow_raw_pointers())
    .class_function("play2d", &AudioEngine::play2d, allow_raw_pointers())
    .class_function("play2d", optional_override(
      [](const std::string& arg0){
        return AudioEngine::play2d(arg0);
      }), allow_raw_pointers())
    .class_function("play2d", optional_override(
      [](const std::string& arg0, bool arg1){
        return AudioEngine::play2d(arg0, arg1);
      }), allow_raw_pointers())
    .class_function("play2d", optional_override(
      [](const std::string& arg0, bool arg1, float arg2){
        return AudioEngine::play2d(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("getState", &AudioEngine::getState, allow_raw_pointers())
    .class_function("resume", &AudioEngine::resume, allow_raw_pointers())
    .class_function("stop", &AudioEngine::stop, allow_raw_pointers())
    .class_function("getDuration", &AudioEngine::getDuration, allow_raw_pointers())
    .class_function("setLoop", &AudioEngine::setLoop, allow_raw_pointers())
    .class_function("getDefaultProfile", &AudioEngine::getDefaultProfile, allow_raw_pointers())
    .class_function("setFinishCallback", &AudioEngine::setFinishCallback, allow_raw_pointers())
    .class_function("getProfile", select_overload<cocos2d::experimental::AudioProfile*(const std::string&)>(&AudioEngine::getProfile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("getPlayingAudioCount", &AudioEngine::getPlayingAudioCount, allow_raw_pointers())
    .property("_className",  optional_override([](const AudioEngine& _) -> std::string {return "AudioEngine";}))    
    ;
}

#endif
