#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_experimental_video.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)
#include "ui/UIVideoPlayer.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_experimental_video) {


  class_<VideoPlayer, base<Widget>>("ccui.VideoPlayer")
    .constructor<>()
    .function("getURL", &VideoPlayer::getURL, allow_raw_pointers())
    .function("setFullScreenEnabled", &VideoPlayer::setFullScreenEnabled, allow_raw_pointers())
    .function("setStyle", &VideoPlayer::setStyle, allow_raw_pointers())
    .function("setUserInputEnabled", &VideoPlayer::setUserInputEnabled, allow_raw_pointers())
    .function("onPlayEvent", &VideoPlayer::onPlayEvent, allow_raw_pointers())
    .function("seekTo", &VideoPlayer::seekTo, allow_raw_pointers())
    .function("play", &VideoPlayer::play, allow_raw_pointers())
    .function("stop", &VideoPlayer::stop, allow_raw_pointers())
    .function("setURL", &VideoPlayer::setURL, allow_raw_pointers())
    .function("isKeepAspectRatioEnabled", &VideoPlayer::isKeepAspectRatioEnabled, allow_raw_pointers())
    .function("isFullScreenEnabled", &VideoPlayer::isFullScreenEnabled, allow_raw_pointers())
    .function("isLooping", &VideoPlayer::isLooping, allow_raw_pointers())
    .function("isPlaying", &VideoPlayer::isPlaying, allow_raw_pointers())
    .function("getFileName", &VideoPlayer::getFileName, allow_raw_pointers())
    .function("isUserInputEnabled", &VideoPlayer::isUserInputEnabled, allow_raw_pointers())
    .function("setKeepAspectRatioEnabled", &VideoPlayer::setKeepAspectRatioEnabled, allow_raw_pointers())
    .function("setLooping", &VideoPlayer::setLooping, allow_raw_pointers())
    .function("setFileName", &VideoPlayer::setFileName, allow_raw_pointers())
    .class_function("create", &VideoPlayer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const VideoPlayer& _) -> std::string {return "VideoPlayer";}))    
    ;}