#include "scripting/emscripten-bindings/CCScriptBindings.h"
#include "scripting/emscripten-bindings/manual/jsb_cocos2dx_experimental_webView.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS) && !defined(CC_TARGET_OS_TVOS)
#include "ui/UIWebView.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(jsb_cocos2dx_experimental_webView) {


  class_<WebView, base<Widget>>("ccui.WebView")
    .constructor(&cc_bindings_constructor<WebView>, allow_raw_pointers())
    .function("setOpacityWebView", &WebView::setOpacityWebView)
    .function("canGoBack", &WebView::canGoBack)
    .function("loadHTMLString", &WebView::loadHTMLString)
    .function("loadHTMLString", optional_override(
        [](WebView& this_, const std::string& arg0){
        return this_.loadHTMLString(arg0);
      }))
    .function("goForward", &WebView::goForward)
    .function("goBack", &WebView::goBack)
    .function("setScalesPageToFit", &WebView::setScalesPageToFit)
    .function("getOnDidFailLoading", &WebView::getOnDidFailLoading)
    .function("loadFile", &WebView::loadFile)
    .function("loadURL", select_overload<void(const std::string&, bool)>(&WebView::loadURL))
    .function("loadURL", select_overload<void(const std::string&)>(&WebView::loadURL))
    .function("setBounces", &WebView::setBounces)
    .function("evaluateJS", &WebView::evaluateJS)
    .function("setBackgroundTransparent", &WebView::setBackgroundTransparent)
    .function("getOnJSCallback", &WebView::getOnJSCallback)
    .function("canGoForward", &WebView::canGoForward)
    .function("getOnShouldStartLoading", &WebView::getOnShouldStartLoading)
    .function("stopLoading", &WebView::stopLoading)
    .function("getOpacityWebView", &WebView::getOpacityWebView)
    .function("reload", &WebView::reload)
    .function("setJavascriptInterfaceScheme", &WebView::setJavascriptInterfaceScheme)
    .function("getOnDidFinishLoading", &WebView::getOnDidFinishLoading)
    // from manual
    .function("setOnShouldStartLoading", optional_override([](const val& thisv, const val& func) 
    {
      WebView& this_ = thisv.as<WebView&>();
      this_.setOnShouldStartLoading([thisv, func](WebView *sender, const std::string &url) -> void
      {
        func.call<void>("call", thisv, thisv, val(url));
      });
    }))
    .function("setOnDidFinishLoading", optional_override([](const val& thisv, const val& func) 
    {
      WebView& this_ = thisv.as<WebView&>();
      this_.setOnDidFinishLoading([thisv, func](WebView *sender, const std::string &url) -> void
      {
        func.call<void>("call", thisv, thisv, val(url));
      });
    }))
    .function("setOnDidFailLoading", optional_override([](const val& thisv, const val& func) 
    {
      WebView& this_ = thisv.as<WebView&>();
      this_.setOnDidFailLoading([thisv, func](WebView *sender, const std::string &url) -> void
      {
        func.call<void>("call", thisv, thisv, val(url));
      });
    }))
    .function("setOnJSCallback", optional_override([](const val& thisv, const val& func) 
    {
      WebView& this_ = thisv.as<WebView&>();
      this_.setOnJSCallback([thisv, func](WebView *sender, const std::string &url) -> void
      {
        func.call<void>("call", thisv, thisv, val(url));
      });
    }))
    // end of manual
    .class_function("create", &WebView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const WebView& _) -> std::string {return "WebView";}))    
    ;
}

#endif
