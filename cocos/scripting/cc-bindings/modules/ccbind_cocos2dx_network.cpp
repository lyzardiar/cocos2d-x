#include "scripting/cc-bindings/CCScriptBindings.h"
#include "scripting/cc-bindings/modules/ccbind_cocos2dx_network.hpp"
#include "network/CCDownloader.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::network;

COCOS_BINDINGS(ccbind_cocos2dx_network) {


  class_<Downloader>("jsb.Downloader")
        // TODO: overloaded constructor
    // TODO: Emscripten cannot automatically call destructor.
    .function("setOnTaskError", &Downloader::setOnTaskError)
    .function("setOnTaskProgress", &Downloader::setOnTaskProgress)
    .function("createDownloadFileTask", &Downloader::createDownloadFileTask)
    .function("createDownloadFileTask", optional_override(
        [](Downloader& this_, const std::string& arg0, const std::string& arg1){
        return this_.createDownloadFileTask(arg0, arg1);
      }))
    .function("setOnFileTaskSuccess", &Downloader::setOnFileTaskSuccess)
    .function("setOnDataTaskSuccess", &Downloader::setOnDataTaskSuccess)
    .property("_className",  optional_override([](const Downloader& _) -> std::string {return "Downloader";}))    
    ;
}