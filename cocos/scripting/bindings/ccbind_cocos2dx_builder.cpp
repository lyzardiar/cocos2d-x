#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_builder.hpp"
#include "editor-support/cocosbuilder/CocosBuilder.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocosbuilder;

COCOS_BINDINGS(ccbind_cocos2dx_builder) {


  class_<CCBAnimationManager>("cc.BuilderAnimationManager")
    .constructor<>()
    .function("moveAnimationsFromNode", &CCBAnimationManager::moveAnimationsFromNode, allow_raw_pointers())
    .function("setAutoPlaySequenceId", &CCBAnimationManager::setAutoPlaySequenceId, allow_raw_pointers())
    .function("getDocumentCallbackNames", &CCBAnimationManager::getDocumentCallbackNames, allow_raw_pointers())
    .function("actionForSoundChannel", &CCBAnimationManager::actionForSoundChannel, allow_raw_pointers())
    .function("setBaseValue", &CCBAnimationManager::setBaseValue, allow_raw_pointers())
    .function("getDocumentOutletNodes", &CCBAnimationManager::getDocumentOutletNodes, allow_raw_pointers())
    .function("getLastCompletedSequenceName", &CCBAnimationManager::getLastCompletedSequenceName, allow_raw_pointers())
    .function("setRootNode", &CCBAnimationManager::setRootNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamedTweenDuration", &CCBAnimationManager::runAnimationsForSequenceNamedTweenDuration, allow_raw_pointers())
    .function("addDocumentOutletName", &CCBAnimationManager::addDocumentOutletName, allow_raw_pointers())
    .function("getRootContainerSize", &CCBAnimationManager::getRootContainerSize, allow_raw_pointers())
    .function("setDocumentControllerName", &CCBAnimationManager::setDocumentControllerName, allow_raw_pointers())
    .function("setObject", &CCBAnimationManager::setObject, allow_raw_pointers())
    .function("getContainerSize", &CCBAnimationManager::getContainerSize, allow_raw_pointers())
    .function("actionForCallbackChannel", &CCBAnimationManager::actionForCallbackChannel, allow_raw_pointers())
    .function("getDocumentOutletNames", &CCBAnimationManager::getDocumentOutletNames, allow_raw_pointers())
    .function("addDocumentCallbackControlEvents", &CCBAnimationManager::addDocumentCallbackControlEvents, allow_raw_pointers())
    .function("init", &CCBAnimationManager::init, allow_raw_pointers())
    .function("getKeyframeCallbacks", &CCBAnimationManager::getKeyframeCallbacks, allow_raw_pointers())
    .function("getDocumentCallbackControlEvents", &CCBAnimationManager::getDocumentCallbackControlEvents, allow_raw_pointers())
    .function("setRootContainerSize", &CCBAnimationManager::setRootContainerSize, allow_raw_pointers())
    .function("runAnimationsForSequenceIdTweenDuration", &CCBAnimationManager::runAnimationsForSequenceIdTweenDuration, allow_raw_pointers())
    .function("getRunningSequenceName", &CCBAnimationManager::getRunningSequenceName, allow_raw_pointers())
    .function("getAutoPlaySequenceId", &CCBAnimationManager::getAutoPlaySequenceId, allow_raw_pointers())
    .function("addDocumentCallbackName", &CCBAnimationManager::addDocumentCallbackName, allow_raw_pointers())
    .function("getRootNode", &CCBAnimationManager::getRootNode, allow_raw_pointers())
    .function("addDocumentOutletNode", &CCBAnimationManager::addDocumentOutletNode, allow_raw_pointers())
    .function("setDelegate", &CCBAnimationManager::setDelegate, allow_raw_pointers())
    .function("getSequenceDuration", &CCBAnimationManager::getSequenceDuration, allow_raw_pointers())
    .function("addDocumentCallbackNode", &CCBAnimationManager::addDocumentCallbackNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamed", &CCBAnimationManager::runAnimationsForSequenceNamed, allow_raw_pointers())
    .function("getSequenceId", &CCBAnimationManager::getSequenceId, allow_raw_pointers())
    .function("setCallFunc", &CCBAnimationManager::setCallFunc, allow_raw_pointers())
    .function("getDocumentCallbackNodes", &CCBAnimationManager::getDocumentCallbackNodes, allow_raw_pointers())
    .function("setSequences", &CCBAnimationManager::setSequences, allow_raw_pointers())
    .function("debug", &CCBAnimationManager::debug, allow_raw_pointers())
    .function("getDocumentControllerName", &CCBAnimationManager::getDocumentControllerName, allow_raw_pointers())
    .property("_className",  optional_override([](const CCBAnimationManager& _) -> std::string {return "CCBAnimationManager";}))    
    ;


  class_<CCBReader>("cc._Reader")
        // TODO: overloaded constructor
    .function("getAnimationManager", &CCBReader::getAnimationManager, allow_raw_pointers())
    .function("setAnimationManager", &CCBReader::setAnimationManager, allow_raw_pointers())
    .function("addOwnerOutletName", &CCBReader::addOwnerOutletName, allow_raw_pointers())
    .function("getOwnerCallbackNames", &CCBReader::getOwnerCallbackNames, allow_raw_pointers())
    .function("addDocumentCallbackControlEvents", &CCBReader::addDocumentCallbackControlEvents, allow_raw_pointers())
    .function("setCCBRootPath", &CCBReader::setCCBRootPath, allow_raw_pointers())
    .function("addOwnerOutletNode", &CCBReader::addOwnerOutletNode, allow_raw_pointers())
    .function("getOwnerCallbackNodes", &CCBReader::getOwnerCallbackNodes, allow_raw_pointers())
    .function("readSoundKeyframesForSeq", &CCBReader::readSoundKeyframesForSeq, allow_raw_pointers())
    .function("getCCBRootPath", &CCBReader::getCCBRootPath, allow_raw_pointers())
    .function("getOwnerCallbackControlEvents", &CCBReader::getOwnerCallbackControlEvents, allow_raw_pointers())
    .function("getOwnerOutletNodes", &CCBReader::getOwnerOutletNodes, allow_raw_pointers())
    .function("readUTF8", &CCBReader::readUTF8, allow_raw_pointers())
    .function("addOwnerCallbackControlEvents", &CCBReader::addOwnerCallbackControlEvents, allow_raw_pointers())
    .function("getOwnerOutletNames", &CCBReader::getOwnerOutletNames, allow_raw_pointers())
    .function("readCallbackKeyframesForSeq", &CCBReader::readCallbackKeyframesForSeq, allow_raw_pointers())
    .function("getAnimationManagersForNodes", &CCBReader::getAnimationManagersForNodes, allow_raw_pointers())
    .function("getNodesWithAnimationManagers", &CCBReader::getNodesWithAnimationManagers, allow_raw_pointers())
    .class_function("setResolutionScale", &CCBReader::setResolutionScale, allow_raw_pointers())
    .property("_className",  optional_override([](const CCBReader& _) -> std::string {return "CCBReader";}))    
    ;
}
