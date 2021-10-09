#include "scripting/CCScriptBindings.h"
#include "scripting/modules/ccbind_cocos2dx_experimental_video.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)
#include "ui/UIVideoPlayer.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_experimental_video) {


  class_<VideoPlayer, base<Widget>>("ccui.VideoPlayer")
    .constructor(&cc_bindings_constructor<VideoPlayer>, allow_raw_pointers())
    .function("getFileName", &VideoPlayer::getFileName)
    .function("getURL", &VideoPlayer::getURL)
    .function("play", &VideoPlayer::play)
    .function("isUserInputEnabled", &VideoPlayer::isUserInputEnabled)
    .function("setKeepAspectRatioEnabled", &VideoPlayer::setKeepAspectRatioEnabled)
    .function("stop", &VideoPlayer::stop)
    .function("setFullScreenEnabled", &VideoPlayer::setFullScreenEnabled)
    .function("setFileName", &VideoPlayer::setFileName)
    .function("setURL", &VideoPlayer::setURL)
    .function("setStyle", optional_override(
        [](VideoPlayer& this_, int32_t arg0){
        return this_.setStyle((cocos2d::experimental::ui::VideoPlayer::StyleType)arg0);
      }))
    .function("seekTo", &VideoPlayer::seekTo)
    .function("isKeepAspectRatioEnabled", &VideoPlayer::isKeepAspectRatioEnabled)
    .function("onPlayEvent", &VideoPlayer::onPlayEvent)
    .function("isFullScreenEnabled", &VideoPlayer::isFullScreenEnabled)
    .function("isLooping", &VideoPlayer::isLooping)
    .function("isPlaying", &VideoPlayer::isPlaying)
    .function("setLooping", &VideoPlayer::setLooping)
    .function("setUserInputEnabled", &VideoPlayer::setUserInputEnabled)
    .class_function("create", &VideoPlayer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const VideoPlayer& _) -> std::string {return "VideoPlayer";}))    
    ;
}

#endif
