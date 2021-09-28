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
    .function("setAutoPlaySequenceId", &CCBAnimationManager::setAutoPlaySequenceId)
    .function("getDocumentCallbackNames", &CCBAnimationManager::getDocumentCallbackNames)
    .function("actionForSoundChannel", &CCBAnimationManager::actionForSoundChannel, allow_raw_pointers())
    .function("setBaseValue", &CCBAnimationManager::setBaseValue, allow_raw_pointers())
    .function("getDocumentOutletNodes", &CCBAnimationManager::getDocumentOutletNodes)
    .function("getLastCompletedSequenceName", &CCBAnimationManager::getLastCompletedSequenceName)
    .function("setRootNode", &CCBAnimationManager::setRootNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamedTweenDuration", &CCBAnimationManager::runAnimationsForSequenceNamedTweenDuration, allow_raw_pointers())
    .function("addDocumentOutletName", &CCBAnimationManager::addDocumentOutletName)
    .function("getRootContainerSize", &CCBAnimationManager::getRootContainerSize)
    .function("setDocumentControllerName", &CCBAnimationManager::setDocumentControllerName)
    .function("setObject", &CCBAnimationManager::setObject, allow_raw_pointers())
    .function("getContainerSize", &CCBAnimationManager::getContainerSize, allow_raw_pointers())
    .function("actionForCallbackChannel", &CCBAnimationManager::actionForCallbackChannel, allow_raw_pointers())
    .function("getDocumentOutletNames", &CCBAnimationManager::getDocumentOutletNames)
    .function("addDocumentCallbackControlEvents", &CCBAnimationManager::addDocumentCallbackControlEvents)
    .function("init", &CCBAnimationManager::init)
    .function("getKeyframeCallbacks", &CCBAnimationManager::getKeyframeCallbacks)
    .function("getDocumentCallbackControlEvents", &CCBAnimationManager::getDocumentCallbackControlEvents)
    .function("setRootContainerSize", &CCBAnimationManager::setRootContainerSize)
    .function("runAnimationsForSequenceIdTweenDuration", &CCBAnimationManager::runAnimationsForSequenceIdTweenDuration)
    .function("getRunningSequenceName", &CCBAnimationManager::getRunningSequenceName, allow_raw_pointers())
    .function("getAutoPlaySequenceId", &CCBAnimationManager::getAutoPlaySequenceId)
    .function("addDocumentCallbackName", &CCBAnimationManager::addDocumentCallbackName)
    .function("getRootNode", &CCBAnimationManager::getRootNode, allow_raw_pointers())
    .function("addDocumentOutletNode", &CCBAnimationManager::addDocumentOutletNode, allow_raw_pointers())
    .function("setDelegate", &CCBAnimationManager::setDelegate, allow_raw_pointers())
    .function("getSequenceDuration", &CCBAnimationManager::getSequenceDuration, allow_raw_pointers())
    .function("addDocumentCallbackNode", &CCBAnimationManager::addDocumentCallbackNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamed", &CCBAnimationManager::runAnimationsForSequenceNamed, allow_raw_pointers())
    .function("getSequenceId", &CCBAnimationManager::getSequenceId, allow_raw_pointers())
    .function("setCallFunc", &CCBAnimationManager::setCallFunc, allow_raw_pointers())
    .function("getDocumentCallbackNodes", &CCBAnimationManager::getDocumentCallbackNodes)
    .function("setSequences", &CCBAnimationManager::setSequences)
    .function("debug", &CCBAnimationManager::debug)
    .function("getDocumentControllerName", &CCBAnimationManager::getDocumentControllerName)
    .property("_className",  optional_override([](const CCBAnimationManager& _) -> std::string {return "CCBAnimationManager";}))    
    ;


  class_<CCBReader>("cc._Reader")
        // TODO: overloaded constructor
    .function("getAnimationManager", &CCBReader::getAnimationManager, allow_raw_pointers())
    .function("setAnimationManager", &CCBReader::setAnimationManager, allow_raw_pointers())
    .function("addOwnerOutletName", &CCBReader::addOwnerOutletName)
    .function("getOwnerCallbackNames", &CCBReader::getOwnerCallbackNames)
    .function("addDocumentCallbackControlEvents", &CCBReader::addDocumentCallbackControlEvents)
    .function("setCCBRootPath", &CCBReader::setCCBRootPath, allow_raw_pointers())
    .function("addOwnerOutletNode", &CCBReader::addOwnerOutletNode, allow_raw_pointers())
    .function("getOwnerCallbackNodes", &CCBReader::getOwnerCallbackNodes)
    .function("readSoundKeyframesForSeq", &CCBReader::readSoundKeyframesForSeq, allow_raw_pointers())
    .function("getCCBRootPath", &CCBReader::getCCBRootPath)
    .function("getOwnerCallbackControlEvents", &CCBReader::getOwnerCallbackControlEvents)
    .function("getOwnerOutletNodes", &CCBReader::getOwnerOutletNodes)
    .function("readUTF8", &CCBReader::readUTF8)
    .function("addOwnerCallbackControlEvents", &CCBReader::addOwnerCallbackControlEvents)
    .function("getOwnerOutletNames", &CCBReader::getOwnerOutletNames)
    .function("readCallbackKeyframesForSeq", &CCBReader::readCallbackKeyframesForSeq, allow_raw_pointers())
    .function("getAnimationManagersForNodes", &CCBReader::getAnimationManagersForNodes)
    .function("getNodesWithAnimationManagers", &CCBReader::getNodesWithAnimationManagers)
    .class_function("setResolutionScale", &CCBReader::setResolutionScale, allow_raw_pointers())
    .property("_className",  optional_override([](const CCBReader& _) -> std::string {return "CCBReader";}))    
    ;
}
