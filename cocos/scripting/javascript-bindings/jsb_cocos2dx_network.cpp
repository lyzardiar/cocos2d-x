#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_network.hpp"
#include "network/CCDownloader.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::network;

COCOS_BINDINGS(jsb_cocos2dx_network) {

  value_object<DownloaderHints>("_.DownloaderHints")
    .field("countOfMaxProcessingTasks", &DownloaderHints::countOfMaxProcessingTasks)
    .field("timeoutInSeconds", &DownloaderHints::timeoutInSeconds)
    .field("tempFileNameSuffix", &DownloaderHints::tempFileNameSuffix)
    ;

  value_object<DownloadTask>("_.DownloadTask")
    .field("identifier", &DownloadTask::identifier)
    .field("requestURL", &DownloadTask::requestURL)
    .field("storagePath", &DownloadTask::storagePath)
    ;

  class_<Downloader>("jsb.Downloader")
    .constructor<>()
    .constructor<const DownloaderHints& >()
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