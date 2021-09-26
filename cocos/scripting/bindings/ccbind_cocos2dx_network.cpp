#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_network.hpp"
#include "network/CCDownloader.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_network) {


  class_<Downloader>("jsb.Downloader")
        // TODO: overloaded constructor
    // TODO: Emscripten cannot automatically call destructor.
    .function("setOnTaskError", &Downloader::setOnTaskError, allow_raw_pointers())
    .function("setOnTaskProgress", &Downloader::setOnTaskProgress, allow_raw_pointers())
    .function("createDownloadFileTask", &Downloader::createDownloadFileTask, allow_raw_pointers())
    .function("createDownloadFileTask", optional_override(
        [](Downloader& this_, const std::string& arg0, const std::string& arg1){
        return this_.createDownloadFileTask(arg0, arg1);
      }), allow_raw_pointers())
    .function("setOnFileTaskSuccess", &Downloader::setOnFileTaskSuccess, allow_raw_pointers())
    .function("setOnDataTaskSuccess", &Downloader::setOnDataTaskSuccess, allow_raw_pointers())
    .property("_className",  optional_override([](const Downloader& _) -> std::string {return "Downloader";}))    
    ;}