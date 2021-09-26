#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_experimental_webView.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)
#include "ui/UIWebView.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_experimental_webView) {


  class_<WebView, base<Widget>>("ccui.WebView")
    .constructor<>()
    .function("setOpacityWebView", &WebView::setOpacityWebView, allow_raw_pointers())
    .function("canGoBack", &WebView::canGoBack, allow_raw_pointers())
    .function("loadHTMLString", &WebView::loadHTMLString, allow_raw_pointers())
    .function("loadHTMLString", optional_override(
        [](WebView& this_, const std::string& arg0){
        return this_.loadHTMLString(arg0);
      }), allow_raw_pointers())
    .function("goForward", &WebView::goForward, allow_raw_pointers())
    .function("goBack", &WebView::goBack, allow_raw_pointers())
    .function("setScalesPageToFit", &WebView::setScalesPageToFit, allow_raw_pointers())
    .function("getOnDidFailLoading", &WebView::getOnDidFailLoading, allow_raw_pointers())
    .function("loadFile", &WebView::loadFile, allow_raw_pointers())
    .function("loadURL", select_overload<void(const std::string&, bool)>(&WebView::loadURL), allow_raw_pointers())
    .function("loadURL", select_overload<void(const std::string&)>(&WebView::loadURL), allow_raw_pointers())
    .function("setBounces", &WebView::setBounces, allow_raw_pointers())
    .function("evaluateJS", &WebView::evaluateJS, allow_raw_pointers())
    .function("setBackgroundTransparent", &WebView::setBackgroundTransparent, allow_raw_pointers())
    .function("getOnJSCallback", &WebView::getOnJSCallback, allow_raw_pointers())
    .function("canGoForward", &WebView::canGoForward, allow_raw_pointers())
    .function("getOnShouldStartLoading", &WebView::getOnShouldStartLoading, allow_raw_pointers())
    .function("stopLoading", &WebView::stopLoading, allow_raw_pointers())
    .function("getOpacityWebView", &WebView::getOpacityWebView, allow_raw_pointers())
    .function("reload", &WebView::reload, allow_raw_pointers())
    .function("setJavascriptInterfaceScheme", &WebView::setJavascriptInterfaceScheme, allow_raw_pointers())
    .function("getOnDidFinishLoading", &WebView::getOnDidFinishLoading, allow_raw_pointers())
    .class_function("create", &WebView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const WebView& _) -> std::string {return "WebView";}))    
    ;}