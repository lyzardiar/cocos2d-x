#include "scripting/emscripten-bindings/CCScriptBindings.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_EMSCRIPTEN)
#include "audio/include/AudioEngine.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::experimental;

COCOS_BINDINGS(jsb_cocos2dx_audioengine) {


  class_<AudioProfile>("jsb.AudioProfile")
    .constructor(&cc_bindings_constructor<AudioProfile>, allow_raw_pointers())
    // TODO: Emscripten cannot automatically call destructor.
    .property("name", &AudioProfile::name)
    .property("maxInstances", &AudioProfile::maxInstances)
    .property("minDelay", &AudioProfile::minDelay)
    .property("_className",  optional_override([](const AudioProfile& _) -> std::string {return "AudioProfile";}))    
    ;

  class_<AudioEngine>("jsb.AudioEngine")
    .class_function("lazyInit", &AudioEngine::lazyInit)
    .class_function("setCurrentTime", &AudioEngine::setCurrentTime)
    .class_function("getVolume", &AudioEngine::getVolume)
    .class_function("uncache", &AudioEngine::uncache)
    .class_function("resumeAll", &AudioEngine::resumeAll)
    .class_function("stopAll", &AudioEngine::stopAll)
    .class_function("pause", &AudioEngine::pause)
    .class_function("end", &AudioEngine::end)
    .class_function("getMaxAudioInstance", &AudioEngine::getMaxAudioInstance)
    .class_function("isEnabled", &AudioEngine::isEnabled)
    .class_function("getCurrentTime", &AudioEngine::getCurrentTime)
    .class_function("setMaxAudioInstance", &AudioEngine::setMaxAudioInstance)
    .class_function("isLoop", &AudioEngine::isLoop)
    .class_function("pauseAll", &AudioEngine::pauseAll)
    .class_function("uncacheAll", &AudioEngine::uncacheAll)
    .class_function("setVolume", &AudioEngine::setVolume)
    .class_function("preload", optional_override(
      [](const std::string& arg0, const val& callback){
        return AudioEngine::preload(arg0, [callback](bool larg0) -> void {
          callback.call<void>("call", val::global("jsb")["AudioEngine"], val(larg0));
        });
      }))
    .class_function("preload", select_overload<void(const std::string&)>(&AudioEngine::preload))
    .class_function("setEnabled", &AudioEngine::setEnabled)
    .class_function("play2d", &AudioEngine::play2d, allow_raw_pointers())
    .class_function("play2d", optional_override(
      [](const std::string& arg0){
        return AudioEngine::play2d(arg0);
      }))
    .class_function("play2d", optional_override(
      [](const std::string& arg0, bool arg1){
        return AudioEngine::play2d(arg0, arg1);
      }))
    .class_function("play2d", optional_override(
      [](const std::string& arg0, bool arg1, float arg2){
        return AudioEngine::play2d(arg0, arg1, arg2);
      }))
    .class_function("getState", &AudioEngine::getState)
    .class_function("resume", &AudioEngine::resume)
    .class_function("stop", &AudioEngine::stop)
    .class_function("getDuration", &AudioEngine::getDuration)
    .class_function("setLoop", &AudioEngine::setLoop)
    .class_function("getDefaultProfile", &AudioEngine::getDefaultProfile, allow_raw_pointers())
    .class_function("setFinishCallback", &AudioEngine::setFinishCallback)
    .class_function("getProfile", optional_override(
      [](const val& arg0){
      if (!arg0.isString())
      {
        return AudioEngine::getProfile(arg0.as<int>());
      } else 
      {
        return AudioEngine::getProfile(arg0.as<std::string>());
      }
      }), allow_raw_pointers())
    .class_function("getPlayingAudioCount", &AudioEngine::getPlayingAudioCount)
    .property("_className",  optional_override([](const AudioEngine& _) -> std::string {return "AudioEngine";}))    
    ;
}

#endif
