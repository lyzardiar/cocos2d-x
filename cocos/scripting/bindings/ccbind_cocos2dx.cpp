#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx.hpp"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "scripting/js-bindings/manual/component/CCComponentJS.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace CocosDenshion;

COCOS_BINDINGS(ccbind_cocos2dx) {


  class_<Texture2D>("cc.Texture2D")
    .constructor<>()
    .function("getShaderProgram", &Texture2D::getGLProgram, allow_raw_pointers())
    .function("getMaxT", &Texture2D::getMaxT, allow_raw_pointers())
    .function("getStringForFormat", &Texture2D::getStringForFormat, allow_raw_pointers())
    .function("initWithImage", select_overload<bool(cocos2d::Image*, cocos2d::Texture2D::PixelFormat)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("initWithImage", select_overload<bool(cocos2d::Image*)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("setShaderProgram", &Texture2D::setGLProgram, allow_raw_pointers())
    .function("getMaxS", &Texture2D::getMaxS, allow_raw_pointers())
    .function("hasPremultipliedAlpha", &Texture2D::hasPremultipliedAlpha, allow_raw_pointers())
    .function("initWithMipmaps", &Texture2D::initWithMipmaps, allow_raw_pointers())
    .function("initWithMipmaps", optional_override(
        [](Texture2D& this_, cocos2d::_MipmapInfo* arg0, int arg1, cocos2d::Texture2D::PixelFormat arg2, int arg3, int arg4){
        return this_.initWithMipmaps(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("getPixelsHigh", &Texture2D::getPixelsHigh, allow_raw_pointers())
    .function("getAlphaTextureName", &Texture2D::getAlphaTextureName, allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int(cocos2d::Texture2D::PixelFormat) const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int() const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getName", &Texture2D::getName, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const cocos2d::FontDefinition&)>(&Texture2D::initWithString), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment, bool, int)>(&Texture2D::initWithString), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setMaxT", &Texture2D::setMaxT, allow_raw_pointers())
    .function("getPath", &Texture2D::getPath, allow_raw_pointers())
    .function("drawInRect", &Texture2D::drawInRect, allow_raw_pointers())
    .function("getContentSize", &Texture2D::getContentSize, allow_raw_pointers())
    .function("setAlphaTexture", &Texture2D::setAlphaTexture, allow_raw_pointers())
    .function("setAliasTexParameters", &Texture2D::setAliasTexParameters, allow_raw_pointers())
    .function("setAntiAliasTexParameters", &Texture2D::setAntiAliasTexParameters, allow_raw_pointers())
    .function("generateMipmap", &Texture2D::generateMipmap, allow_raw_pointers())
    .function("getAlphaTexture", &Texture2D::getAlphaTexture, allow_raw_pointers())
    .function("getDescription", &Texture2D::getDescription, allow_raw_pointers())
    .function("getPixelFormat", &Texture2D::getPixelFormat, allow_raw_pointers())
    .function("getContentSizeInPixels", &Texture2D::getContentSizeInPixels, allow_raw_pointers())
    .function("releaseTexture", &Texture2D::releaseGLTexture, allow_raw_pointers())
    .function("getPixelsWide", &Texture2D::getPixelsWide, allow_raw_pointers())
    .function("drawAtPoint", &Texture2D::drawAtPoint, allow_raw_pointers())
    .function("hasMipmaps", &Texture2D::hasMipmaps, allow_raw_pointers())
    .function("setMaxS", &Texture2D::setMaxS, allow_raw_pointers())
    .class_function("setDefaultAlphaPixelFormat", &Texture2D::setDefaultAlphaPixelFormat, allow_raw_pointers())
    .class_function("getDefaultAlphaPixelFormat", &Texture2D::getDefaultAlphaPixelFormat, allow_raw_pointers())
    .property("_className",  optional_override([](const Texture2D& _) -> std::string {return "Texture2D";}))    
    ;


  class_<Touch>("cc.Touch")
    .constructor<>()
    .function("getPreviousLocationInView", &Touch::getPreviousLocationInView, allow_raw_pointers())
    .function("getLocation", &Touch::getLocation, allow_raw_pointers())
    .function("getDelta", &Touch::getDelta, allow_raw_pointers())
    .function("getStartLocationInView", &Touch::getStartLocationInView, allow_raw_pointers())
    .function("getCurrentForce", &Touch::getCurrentForce, allow_raw_pointers())
    .function("getStartLocation", &Touch::getStartLocation, allow_raw_pointers())
    .function("getID", &Touch::getID, allow_raw_pointers())
    .function("setTouchInfo", select_overload<void(int, float, float, float, float)>(&Touch::setTouchInfo), allow_raw_pointers())
    .function("setTouchInfo", select_overload<void(int, float, float)>(&Touch::setTouchInfo), allow_raw_pointers())
    .function("getMaxForce", &Touch::getMaxForce, allow_raw_pointers())
    .function("getLocationInView", &Touch::getLocationInView, allow_raw_pointers())
    .function("getPreviousLocation", &Touch::getPreviousLocation, allow_raw_pointers())
    .property("_className",  optional_override([](const Touch& _) -> std::string {return "Touch";}))    
    ;


  class_<Event>("cc.Event")
    .constructor<cocos2d::Event::Type>()
    .function("isStopped", &Event::isStopped, allow_raw_pointers())
    .function("getType", &Event::getType, allow_raw_pointers())
    .function("getCurrentTarget", &Event::getCurrentTarget, allow_raw_pointers())
    .function("stopPropagation", &Event::stopPropagation, allow_raw_pointers())
    .property("_className",  optional_override([](const Event& _) -> std::string {return "Event";}))    
    ;


  class_<EventTouch, base<Event>>("cc.EventTouch")
    .constructor<>()
    .function("getEventCode", &EventTouch::getEventCode, allow_raw_pointers())
    .function("setEventCode", &EventTouch::setEventCode, allow_raw_pointers())
    .property("_className",  optional_override([](const EventTouch& _) -> std::string {return "EventTouch";}))    
    ;

  class_<ComponentContainer>("cc.ComponentContainer")
    .function("visit", &ComponentContainer::visit, allow_raw_pointers())
    .function("remove", select_overload<bool(cocos2d::Component*)>(&ComponentContainer::remove), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeAll", &ComponentContainer::removeAll, allow_raw_pointers())
    .function("add", &ComponentContainer::add, allow_raw_pointers())
    .function("isEmpty", &ComponentContainer::isEmpty, allow_raw_pointers())
    .function("getComponent", &ComponentContainer::get, allow_raw_pointers())
    .property("_className",  optional_override([](const ComponentContainer& _) -> std::string {return "ComponentContainer";}))    
    ;


  class_<Component>("cc.Component")
    .constructor<>()
    .function("setEnabled", &Component::setEnabled, allow_raw_pointers())
    .function("setName", &Component::setName, allow_raw_pointers())
    .function("isEnabled", &Component::isEnabled, allow_raw_pointers())
    .function("getOwner", &Component::getOwner, allow_raw_pointers())
    .function("init", &Component::init, allow_raw_pointers())
    .function("setOwner", &Component::setOwner, allow_raw_pointers())
    .function("getName", &Component::getName, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Component>, allow_raw_pointers())
    .class_function("create", &Component::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Component& _) -> std::string {return "Component";}))    
    // TODO: assign cc.Class.extend to cc.Component.extend
    ;


  class_<Node>("cc.Node")
    .constructor<>()
    .function("addChild", select_overload<void(cocos2d::Node*, int)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(cocos2d::Node*)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(cocos2d::Node*, int, int)>(&Node::addChild), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeComponent", select_overload<bool(cocos2d::Component*)>(&Node::removeComponent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setPhysicsBody", &Node::setPhysicsBody, allow_raw_pointers())
    .function("getShaderProgram", select_overload<cocos2d::GLProgram*() const>(&Node::getGLProgram), allow_raw_pointers())
    .function("getDescription", &Node::getDescription, allow_raw_pointers())
    .function("setOpacityModifyRGB", &Node::setOpacityModifyRGB, allow_raw_pointers())
    .function("setCascadeOpacityEnabled", &Node::setCascadeOpacityEnabled, allow_raw_pointers())
    .function("getChildren", select_overload<const cocos2d::Vector<cocos2d::Node *>&() const>(&Node::getChildren), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setOnExitCallback", &Node::setOnExitCallback, allow_raw_pointers())
    .function("setActionManager", &Node::setActionManager, allow_raw_pointers())
    .function("isIgnoreAnchorPointForPosition", &Node::isIgnoreAnchorPointForPosition, allow_raw_pointers())
    .function("getChildByName", &Node::getChildByName, allow_raw_pointers())
    .function("updateDisplayedOpacity", &Node::updateDisplayedOpacity, allow_raw_pointers())
    .function("init", &Node::init, allow_raw_pointers())
    .function("getCameraMask", &Node::getCameraMask, allow_raw_pointers())
    .function("setRotation", &Node::setRotation, allow_raw_pointers())
    .function("setScaleZ", &Node::setScaleZ, allow_raw_pointers())
    .function("setScaleY", &Node::setScaleY, allow_raw_pointers())
    .function("setScaleX", &Node::setScaleX, allow_raw_pointers())
    .function("getColor", &Node::getColor, allow_raw_pointers())
    .function("setonEnterTransitionDidFinishCallback", &Node::setonEnterTransitionDidFinishCallback, allow_raw_pointers())
    .function("removeAllComponents", &Node::removeAllComponents, allow_raw_pointers())
    .function("_setLocalZOrder", &Node::_setLocalZOrder, allow_raw_pointers())
    .function("setCameraMask", &Node::setCameraMask, allow_raw_pointers())
    .function("setCameraMask", optional_override(
        [](Node& this_, unsigned short arg0){
        return this_.setCameraMask(arg0);
      }), allow_raw_pointers())
    .function("getTag", &Node::getTag, allow_raw_pointers())
    .function("getonEnterTransitionDidFinishCallback", &Node::getonEnterTransitionDidFinishCallback, allow_raw_pointers())
    .function("getNodeToWorldTransform", &Node::getNodeToWorldAffineTransform, allow_raw_pointers())
    .function("getPosition3D", &Node::getPosition3D, allow_raw_pointers())
    .function("removeChild", &Node::removeChild, allow_raw_pointers())
    .function("removeChild", optional_override(
        [](Node& this_, cocos2d::Node* arg0){
        return this_.removeChild(arg0);
      }), allow_raw_pointers())
    .function("getScene", &Node::getScene, allow_raw_pointers())
    .function("getEventDispatcher", &Node::getEventDispatcher, allow_raw_pointers())
    .function("setSkewX", &Node::setSkewX, allow_raw_pointers())
    .function("setGLProgramState", &Node::setGLProgramState, allow_raw_pointers())
    .function("setOnEnterCallback", &Node::setOnEnterCallback, allow_raw_pointers())
    .function("stopActionsByFlags", &Node::stopActionsByFlags, allow_raw_pointers())
    .function("setNormalizedPosition", &Node::setNormalizedPosition, allow_raw_pointers())
    .function("setonExitTransitionDidStartCallback", &Node::setonExitTransitionDidStartCallback, allow_raw_pointers())
    .function("convertTouchToNodeSpace", &Node::convertTouchToNodeSpace, allow_raw_pointers())
    .function("removeAllChildren", select_overload<void(bool)>(&Node::removeAllChildrenWithCleanup), allow_raw_pointers())
    .function("removeAllChildren", select_overload<void()>(&Node::removeAllChildren), allow_raw_pointers())
    .function("getRotationX", select_overload<float() const>(&Node::getRotationSkewX), allow_raw_pointers())
    .function("getRotationY", select_overload<float() const>(&Node::getRotationSkewY), allow_raw_pointers())
    .function("getNodeToWorldTransform3D", &Node::getNodeToWorldTransform, allow_raw_pointers())
    .function("isCascadeOpacityEnabled", &Node::isCascadeOpacityEnabled, allow_raw_pointers())
    .function("setParent", &Node::setParent, allow_raw_pointers())
    .function("getName", &Node::getName, allow_raw_pointers())
    .function("getRotation3D", &Node::getRotation3D, allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<cocos2d::AffineTransform(cocos2d::Node*) const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<cocos2d::AffineTransform() const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("convertTouchToNodeSpaceAR", &Node::convertTouchToNodeSpaceAR, allow_raw_pointers())
    .function("getOnEnterCallback", &Node::getOnEnterCallback, allow_raw_pointers())
    .function("setPositionNormalized", &Node::setPositionNormalized, allow_raw_pointers())
    .function("isOpacityModifyRGB", &Node::isOpacityModifyRGB, allow_raw_pointers())
    .function("stopActionByTag", &Node::stopActionByTag, allow_raw_pointers())
    .function("reorderChild", &Node::reorderChild, allow_raw_pointers())
    .function("setSkewY", &Node::setSkewY, allow_raw_pointers())
    .function("setRotation3D", &Node::setRotation3D, allow_raw_pointers())
    .function("setPositionX", &Node::setPositionX, allow_raw_pointers())
    .function("setNodeToParentTransform", &Node::setNodeToParentTransform, allow_raw_pointers())
    .function("getAnchorPoint", &Node::getAnchorPoint, allow_raw_pointers())
    .function("getNumberOfRunningActions", &Node::getNumberOfRunningActions, allow_raw_pointers())
    .function("updateTransform", &Node::updateTransform, allow_raw_pointers())
    .function("isVisible", &Node::isVisible, allow_raw_pointers())
    .function("getChildrenCount", &Node::getChildrenCount, allow_raw_pointers())
    .function("getNodeToParentTransform3D", select_overload<cocos2d::Mat4(cocos2d::Node*) const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("getNodeToParentTransform3D", select_overload<const cocos2d::Mat4&() const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("convertToNodeSpaceAR", &Node::convertToNodeSpaceAR, allow_raw_pointers())
    .function("addComponent", &Node::addComponent, allow_raw_pointers())
    .function("runAction", &Node::runAction, allow_raw_pointers())
    .function("visit", select_overload<void()>(&Node::visit), allow_raw_pointers())
    .function("visit", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, unsigned int)>(&Node::visit), allow_raw_pointers())
    .function("setShaderProgram", select_overload<void(cocos2d::GLProgram*)>(&Node::setGLProgram), allow_raw_pointers())
    .function("getRotation", &Node::getRotation, allow_raw_pointers())
    .function("getPhysicsBody", &Node::getPhysicsBody, allow_raw_pointers())
    .function("getAnchorPointInPoints", &Node::getAnchorPointInPoints, allow_raw_pointers())
    .function("getRotationQuat", &Node::getRotationQuat, allow_raw_pointers())
    .function("removeChildByName", &Node::removeChildByName, allow_raw_pointers())
    .function("removeChildByName", optional_override(
        [](Node& this_, const std::string& arg0){
        return this_.removeChildByName(arg0);
      }), allow_raw_pointers())
    .function("setVertexZ", select_overload<void(float)>(&Node::setPositionZ), allow_raw_pointers())
    .function("getGLProgramState", &Node::getGLProgramState, allow_raw_pointers())
    .function("setScheduler", &Node::setScheduler, allow_raw_pointers())
    .function("stopAllActions", &Node::stopAllActions, allow_raw_pointers())
    .function("getSkewX", &Node::getSkewX, allow_raw_pointers())
    .function("getSkewY", &Node::getSkewY, allow_raw_pointers())
    .function("isScheduled", select_overload<bool(const std::string&) const>(&Node::isScheduled), allow_raw_pointers())
    .function("getDisplayedColor", &Node::getDisplayedColor, allow_raw_pointers())
    .function("getActionByTag", &Node::getActionByTag, allow_raw_pointers())
    .function("setRotationX", select_overload<void(float)>(&Node::setRotationSkewX), allow_raw_pointers())
    .function("setRotationY", select_overload<void(float)>(&Node::setRotationSkewY), allow_raw_pointers())
    .function("setName", &Node::setName, allow_raw_pointers())
    .function("update", &Node::update, allow_raw_pointers())
    .function("getDisplayedOpacity", &Node::getDisplayedOpacity, allow_raw_pointers())
    .function("getLocalZOrder", &Node::getLocalZOrder, allow_raw_pointers())
    .function("getScheduler", select_overload<const cocos2d::Scheduler*() const>(&Node::getScheduler), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getPositionNormalized", &Node::getPositionNormalized, allow_raw_pointers())
    .function("getPosition", select_overload<void(float*, float*) const>(&Node::getPosition), allow_raw_pointers())
    .function("getPosition", select_overload<const cocos2d::Vec2&() const>(&Node::getPosition), allow_raw_pointers())
    .function("isRunning", &Node::isRunning, allow_raw_pointers())
    .function("getParent", select_overload<const cocos2d::Node*() const>(&Node::getParent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getWorldToNodeTransform3D", &Node::getWorldToNodeTransform, allow_raw_pointers())
    .function("getPositionY", &Node::getPositionY, allow_raw_pointers())
    .function("getPositionX", &Node::getPositionX, allow_raw_pointers())
    .function("removeChildByTag", &Node::removeChildByTag, allow_raw_pointers())
    .function("removeChildByTag", optional_override(
        [](Node& this_, int arg0){
        return this_.removeChildByTag(arg0);
      }), allow_raw_pointers())
    .function("setPositionY", &Node::setPositionY, allow_raw_pointers())
    .function("updateDisplayedColor", &Node::updateDisplayedColor, allow_raw_pointers())
    .function("setVisible", &Node::setVisible, allow_raw_pointers())
    .function("getParentToNodeTransform", &Node::getParentToNodeAffineTransform, allow_raw_pointers())
    .function("getVertexZ", select_overload<float() const>(&Node::getPositionZ), allow_raw_pointers())
    .function("setGlobalZOrder", &Node::setGlobalZOrder, allow_raw_pointers())
    .function("setScale", select_overload<void(float, float)>(&Node::setScale), allow_raw_pointers())
    .function("setScale", select_overload<void(float)>(&Node::setScale), allow_raw_pointers())
    .function("getOnExitCallback", &Node::getOnExitCallback, allow_raw_pointers())
    .function("getChildByTag", &Node::getChildByTag, allow_raw_pointers())
    .function("getScaleZ", &Node::getScaleZ, allow_raw_pointers())
    .function("getScaleY", &Node::getScaleY, allow_raw_pointers())
    .function("getScaleX", &Node::getScaleX, allow_raw_pointers())
    .function("setLocalZOrder", &Node::setLocalZOrder, allow_raw_pointers())
    .function("setCascadeColorEnabled", &Node::setCascadeColorEnabled, allow_raw_pointers())
    .function("setOpacity", &Node::setOpacity, allow_raw_pointers())
    .function("getComponent", &Node::getComponent, allow_raw_pointers())
    .function("getContentSize", &Node::getContentSize, allow_raw_pointers())
    .function("stopAllActionsByTag", &Node::stopAllActionsByTag, allow_raw_pointers())
    .function("getBoundingBox", &Node::getBoundingBox, allow_raw_pointers())
    .function("setIgnoreAnchorPointForPosition", &Node::setIgnoreAnchorPointForPosition, allow_raw_pointers())
    .function("setEventDispatcher", &Node::setEventDispatcher, allow_raw_pointers())
    .function("getGlobalZOrder", &Node::getGlobalZOrder, allow_raw_pointers())
    .function("draw", select_overload<void()>(&Node::draw), allow_raw_pointers())
    .function("draw", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, unsigned int)>(&Node::draw), allow_raw_pointers())
    .function("setUserObject", &Node::setUserObject, allow_raw_pointers())
    .function("enumerateChildren", &Node::enumerateChildren, allow_raw_pointers())
    .function("getonExitTransitionDidStartCallback", &Node::getonExitTransitionDidStartCallback, allow_raw_pointers())
    .function("removeFromParent", select_overload<void(bool)>(&Node::removeFromParentAndCleanup), allow_raw_pointers())
    .function("removeFromParent", select_overload<void()>(&Node::removeFromParent), allow_raw_pointers())
    .function("setPosition3D", &Node::setPosition3D, allow_raw_pointers())
    .function("getNumberOfRunningActionsByTag", &Node::getNumberOfRunningActionsByTag, allow_raw_pointers())
    .function("sortAllChildren", &Node::sortAllChildren, allow_raw_pointers())
    .function("getWorldToNodeTransform", &Node::getWorldToNodeAffineTransform, allow_raw_pointers())
    .function("getScale", &Node::getScale, allow_raw_pointers())
    .function("getOpacity", &Node::getOpacity, allow_raw_pointers())
    .function("updateOrderOfArrival", &Node::updateOrderOfArrival, allow_raw_pointers())
    .function("getNormalizedPosition", &Node::getNormalizedPosition, allow_raw_pointers())
    .function("getParentToNodeTransform3D", &Node::getParentToNodeTransform, allow_raw_pointers())
    .function("convertToNodeSpace", &Node::convertToNodeSpace, allow_raw_pointers())
    .function("setTag", &Node::setTag, allow_raw_pointers())
    .function("isCascadeColorEnabled", &Node::isCascadeColorEnabled, allow_raw_pointers())
    .function("setRotationQuat", &Node::setRotationQuat, allow_raw_pointers())
    .function("stopAction", &Node::stopAction, allow_raw_pointers())
    .function("getActionManager", select_overload<const cocos2d::ActionManager*() const>(&Node::getActionManager), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<Node>, allow_raw_pointers())
    .class_function("create", &Node::create, allow_raw_pointers())
    .class_function("getAttachedNodeCount", &Node::getAttachedNodeCount, allow_raw_pointers())
    .property("_className",  optional_override([](const Node& _) -> std::string {return "Node";}))    
    // TODO: assign cc.Class.extend to cc.Node.extend
    ;


  class_<__NodeRGBA, base<Node>>("cc.__NodeRGBA")
    .constructor<>()
    .property("_className",  optional_override([](const __NodeRGBA& _) -> std::string {return "__NodeRGBA";}))    
    ;


  class_<Scene, base<Node>>("cc.Scene")
    .constructor<>()
    .function("setCameraOrderDirty", &Scene::setCameraOrderDirty, allow_raw_pointers())
    .function("render", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4*, const cocos2d::Mat4*, unsigned int)>(&Scene::render), allow_raw_pointers())
    .function("render", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, const cocos2d::Mat4*)>(&Scene::render), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("stepPhysicsAndNavigation", &Scene::stepPhysicsAndNavigation, allow_raw_pointers())
    .function("onProjectionChanged", &Scene::onProjectionChanged, allow_raw_pointers())
    .function("initWithSize", &Scene::initWithSize, allow_raw_pointers())
    .function("getDefaultCamera", &Scene::getDefaultCamera, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Scene>, allow_raw_pointers())
    .class_function("createWithSize", &Scene::createWithSize, allow_raw_pointers())
    .class_function("create", &Scene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Scene& _) -> std::string {return "Scene";}))    
    // TODO: assign cc.Class.extend to cc.Scene.extend
    ;

  class_<GLView>("cc.GLView")
    .function("setFrameSize", &GLView::setFrameSize, allow_raw_pointers())
    .function("getViewPortRect", &GLView::getViewPortRect, allow_raw_pointers())
    .function("getScaleY", &GLView::getScaleY, allow_raw_pointers())
    .function("setContentScaleFactor", &GLView::setContentScaleFactor, allow_raw_pointers())
    .function("getVR", &GLView::getVR, allow_raw_pointers())
    .function("getContentScaleFactor", &GLView::getContentScaleFactor, allow_raw_pointers())
    .function("setIMEKeyboardState", &GLView::setIMEKeyboardState, allow_raw_pointers())
    .function("getSafeAreaRect", &GLView::getSafeAreaRect, allow_raw_pointers())
    .function("setViewPortInPoints", &GLView::setViewPortInPoints, allow_raw_pointers())
    .function("setScissorInPoints", &GLView::setScissorInPoints, allow_raw_pointers())
    .function("getViewName", &GLView::getViewName, allow_raw_pointers())
    .function("isOpenGLReady", &GLView::isOpenGLReady, allow_raw_pointers())
    .function("setCursorVisible", &GLView::setCursorVisible, allow_raw_pointers())
    .function("setDefaultIcon", &GLView::setDefaultIcon, allow_raw_pointers())
    .function("getScaleX", &GLView::getScaleX, allow_raw_pointers())
    .function("getVisibleOrigin", &GLView::getVisibleOrigin, allow_raw_pointers())
    .function("setFrameZoomFactor", &GLView::setFrameZoomFactor, allow_raw_pointers())
    .function("getFrameZoomFactor", &GLView::getFrameZoomFactor, allow_raw_pointers())
    .function("getDesignResolutionSize", &GLView::getDesignResolutionSize, allow_raw_pointers())
    .function("setIcon", select_overload<void(const std::vector<std::string>&) const>(&GLView::setIcon), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setDefaultCursor", &GLView::setDefaultCursor, allow_raw_pointers())
    .function("windowShouldClose", &GLView::windowShouldClose, allow_raw_pointers())
    .function("setDesignResolutionSize", &GLView::setDesignResolutionSize, allow_raw_pointers())
    .function("getResolutionPolicy", &GLView::getResolutionPolicy, allow_raw_pointers())
    .function("isRetinaDisplay", &GLView::isRetinaDisplay, allow_raw_pointers())
    .function("renderScene", &GLView::renderScene, allow_raw_pointers())
    .function("setVR", &GLView::setVR, allow_raw_pointers())
    .function("getFrameSize", &GLView::getFrameSize, allow_raw_pointers())
    .function("getScissorRect", &GLView::getScissorRect, allow_raw_pointers())
    .function("setCursor", &GLView::setCursor, allow_raw_pointers())
    .function("setCursor", optional_override(
        [](GLView& this_, const std::string& arg0){
        return this_.setCursor(arg0);
      }), allow_raw_pointers())
    .function("getRetinaFactor", &GLView::getRetinaFactor, allow_raw_pointers())
    .function("setViewName", &GLView::setViewName, allow_raw_pointers())
    .function("getVisibleRect", &GLView::getVisibleRect, allow_raw_pointers())
    .function("getVisibleSize", &GLView::getVisibleSize, allow_raw_pointers())
    .function("isScissorEnabled", &GLView::isScissorEnabled, allow_raw_pointers())
    .function("pollEvents", &GLView::pollEvents, allow_raw_pointers())
    .class_function("setGLContextAttrs", &GLView::setGLContextAttrs, allow_raw_pointers())
    .class_function("getGLContextAttrs", &GLView::getGLContextAttrs, allow_raw_pointers())
    .property("_className",  optional_override([](const GLView& _) -> std::string {return "GLView";}))    
    ;

  class_<Director>("cc.Director")
    .function("pause", &Director::pause, allow_raw_pointers())
    .function("pushProjectionMatrix", &Director::pushProjectionMatrix, allow_raw_pointers())
    .function("popProjectionMatrix", &Director::popProjectionMatrix, allow_raw_pointers())
    .function("setEventDispatcher", &Director::setEventDispatcher, allow_raw_pointers())
    .function("loadProjectionIdentityMatrix", &Director::loadProjectionIdentityMatrix, allow_raw_pointers())
    .function("setContentScaleFactor", &Director::setContentScaleFactor, allow_raw_pointers())
    .function("getDeltaTime", &Director::getDeltaTime, allow_raw_pointers())
    .function("getContentScaleFactor", &Director::getContentScaleFactor, allow_raw_pointers())
    .function("getWinSizeInPixels", &Director::getWinSizeInPixels, allow_raw_pointers())
    .function("getSafeAreaRect", &Director::getSafeAreaRect, allow_raw_pointers())
    .function("setGLDefaultValues", &Director::setGLDefaultValues, allow_raw_pointers())
    .function("setActionManager", &Director::setActionManager, allow_raw_pointers())
    .function("setAlphaBlending", &Director::setAlphaBlending, allow_raw_pointers())
    .function("popToRootScene", &Director::popToRootScene, allow_raw_pointers())
    .function("loadMatrix", &Director::loadMatrix, allow_raw_pointers())
    .function("getNotificationNode", &Director::getNotificationNode, allow_raw_pointers())
    .function("getWinSize", &Director::getWinSize, allow_raw_pointers())
    .function("end", &Director::end, allow_raw_pointers())
    .function("getTextureCache", &Director::getTextureCache, allow_raw_pointers())
    .function("isSendCleanupToScene", &Director::isSendCleanupToScene, allow_raw_pointers())
    .function("getVisibleOrigin", &Director::getVisibleOrigin, allow_raw_pointers())
    .function("mainLoop", select_overload<void(float)>(&Director::mainLoop), allow_raw_pointers())
    .function("mainLoop", select_overload<void()>(&Director::mainLoop), allow_raw_pointers())
    .function("setDepthTest", &Director::setDepthTest, allow_raw_pointers())
    .function("getFrameRate", &Director::getFrameRate, allow_raw_pointers())
    .function("getSecondsPerFrame", &Director::getSecondsPerFrame, allow_raw_pointers())
    .function("resetMatrixStack", &Director::resetMatrixStack, allow_raw_pointers())
    .function("convertToUI", &Director::convertToUI, allow_raw_pointers())
    .function("pushMatrix", &Director::pushMatrix, allow_raw_pointers())
    .function("setDefaultValues", &Director::setDefaultValues, allow_raw_pointers())
    .function("init", &Director::init, allow_raw_pointers())
    .function("setScheduler", &Director::setScheduler, allow_raw_pointers())
    .function("multiplyProjectionMatrix", &Director::multiplyProjectionMatrix, allow_raw_pointers())
    .function("getMatrix", &Director::getMatrix, allow_raw_pointers())
    .function("isValid", &Director::isValid, allow_raw_pointers())
    .function("startAnimation", &Director::startAnimation, allow_raw_pointers())
    .function("getOpenGLView", &Director::getOpenGLView, allow_raw_pointers())
    .function("getRunningScene", &Director::getRunningScene, allow_raw_pointers())
    .function("setViewport", &Director::setViewport, allow_raw_pointers())
    .function("stopAnimation", &Director::stopAnimation, allow_raw_pointers())
    .function("popToSceneStackLevel", &Director::popToSceneStackLevel, allow_raw_pointers())
    .function("resume", &Director::resume, allow_raw_pointers())
    .function("isNextDeltaTimeZero", &Director::isNextDeltaTimeZero, allow_raw_pointers())
    .function("setClearColor", &Director::setClearColor, allow_raw_pointers())
    .function("setOpenGLView", &Director::setOpenGLView, allow_raw_pointers())
    .function("convertToGL", &Director::convertToGL, allow_raw_pointers())
    .function("purgeCachedData", &Director::purgeCachedData, allow_raw_pointers())
    .function("getTotalFrames", &Director::getTotalFrames, allow_raw_pointers())
    .function("runWithScene", &Director::runWithScene, allow_raw_pointers())
    .function("setNotificationNode", &Director::setNotificationNode, allow_raw_pointers())
    .function("drawScene", &Director::drawScene, allow_raw_pointers())
    .function("restart", &Director::restart, allow_raw_pointers())
    .function("popScene", &Director::popScene, allow_raw_pointers())
    .function("loadIdentityMatrix", &Director::loadIdentityMatrix, allow_raw_pointers())
    .function("isDisplayStats", &Director::isDisplayStats, allow_raw_pointers())
    .function("setProjection", &Director::setProjection, allow_raw_pointers())
    .function("multiplyMatrix", &Director::multiplyMatrix, allow_raw_pointers())
    .function("getZEye", &Director::getZEye, allow_raw_pointers())
    .function("setNextDeltaTimeZero", &Director::setNextDeltaTimeZero, allow_raw_pointers())
    .function("popMatrix", &Director::popMatrix, allow_raw_pointers())
    .function("getVisibleSize", &Director::getVisibleSize, allow_raw_pointers())
    .function("loadProjectionMatrix", &Director::loadProjectionMatrix, allow_raw_pointers())
    .function("initProjectionMatrixStack", &Director::initProjectionMatrixStack, allow_raw_pointers())
    .function("getScheduler", &Director::getScheduler, allow_raw_pointers())
    .function("pushScene", &Director::pushScene, allow_raw_pointers())
    .function("getAnimationInterval", &Director::getAnimationInterval, allow_raw_pointers())
    .function("getClearColor", &Director::getClearColor, allow_raw_pointers())
    .function("isPaused", &Director::isPaused, allow_raw_pointers())
    .function("setDisplayStats", &Director::setDisplayStats, allow_raw_pointers())
    .function("getEventDispatcher", &Director::getEventDispatcher, allow_raw_pointers())
    .function("replaceScene", &Director::replaceScene, allow_raw_pointers())
    .function("setAnimationInterval", &Director::setAnimationInterval, allow_raw_pointers())
    .function("getActionManager", &Director::getActionManager, allow_raw_pointers())
    .class_function("getInstance", &Director::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Director& _) -> std::string {return "Director";}))    
    ;


  class_<Scheduler>("cc.Scheduler")
    .constructor<>()
    .function("setTimeScale", &Scheduler::setTimeScale, allow_raw_pointers())
    .function("update", &Scheduler::update, allow_raw_pointers())
    .function("unscheduleScriptEntry", &Scheduler::unscheduleScriptEntry, allow_raw_pointers())
    .function("unscheduleAll", &Scheduler::unscheduleAll, allow_raw_pointers())
    .function("getTimeScale", &Scheduler::getTimeScale, allow_raw_pointers())
    .function("unscheduleAllWithMinPriority", &Scheduler::unscheduleAllWithMinPriority, allow_raw_pointers())
    .function("performFunctionInCocosThread", &Scheduler::performFunctionInCocosThread, allow_raw_pointers())
    .function("removeAllFunctionsToBePerformedInCocosThread", &Scheduler::removeAllFunctionsToBePerformedInCocosThread, allow_raw_pointers())
    .property("_className",  optional_override([](const Scheduler& _) -> std::string {return "Scheduler";}))    
    ;

  class_<AsyncTaskPool>("cc.AsyncTaskPool")
    .function("stopTasks", &AsyncTaskPool::stopTasks, allow_raw_pointers())
    .class_function("destroyInstance", &AsyncTaskPool::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &AsyncTaskPool::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AsyncTaskPool& _) -> std::string {return "AsyncTaskPool";}))    
    ;

  class_<Action>("cc.Action")
    .function("startWithTarget", &Action::startWithTarget, allow_raw_pointers())
    .function("setOriginalTarget", &Action::setOriginalTarget, allow_raw_pointers())
    .function("clone", &Action::clone, allow_raw_pointers())
    .function("getOriginalTarget", &Action::getOriginalTarget, allow_raw_pointers())
    .function("stop", &Action::stop, allow_raw_pointers())
    .function("update", &Action::update, allow_raw_pointers())
    .function("getTarget", &Action::getTarget, allow_raw_pointers())
    .function("getFlags", &Action::getFlags, allow_raw_pointers())
    .function("step", &Action::step, allow_raw_pointers())
    .function("setTag", &Action::setTag, allow_raw_pointers())
    .function("setFlags", &Action::setFlags, allow_raw_pointers())
    .function("getTag", &Action::getTag, allow_raw_pointers())
    .function("setTarget", &Action::setTarget, allow_raw_pointers())
    .function("isDone", &Action::isDone, allow_raw_pointers())
    .function("reverse", &Action::reverse, allow_raw_pointers())
    .property("_className",  optional_override([](const Action& _) -> std::string {return "Action";}))    
    ;

  class_<FiniteTimeAction, base<Action>>("cc.FiniteTimeAction")
    .function("setDuration", &FiniteTimeAction::setDuration, allow_raw_pointers())
    .function("getDuration", &FiniteTimeAction::getDuration, allow_raw_pointers())
    .property("_className",  optional_override([](const FiniteTimeAction& _) -> std::string {return "FiniteTimeAction";}))    
    ;


  class_<Speed, base<Action>>("cc.Speed")
    .constructor<>()
    .function("setInnerAction", &Speed::setInnerAction, allow_raw_pointers())
    .function("_getSpeed", &Speed::getSpeed, allow_raw_pointers())
    .function("_setSpeed", &Speed::setSpeed, allow_raw_pointers())
    .function("initWithAction", &Speed::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Speed::getInnerAction, allow_raw_pointers())
    .class_function("create", &Speed::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Speed& _) -> std::string {return "Speed";}))    
    ;


  class_<Follow, base<Action>>("cc.Follow")
    .constructor<>()
    .function("setBoundarySet", &Follow::setBoundarySet, allow_raw_pointers())
    .function("initWithTarget", &Follow::initWithTarget, allow_raw_pointers())
    .function("initWithTarget", optional_override(
        [](Follow& this_, cocos2d::Node* arg0){
        return this_.initWithTarget(arg0);
      }), allow_raw_pointers())
    .function("initWithTargetAndOffset", &Follow::initWithTargetAndOffset, allow_raw_pointers())
    .function("initWithTargetAndOffset", optional_override(
        [](Follow& this_, cocos2d::Node* arg0, float arg1, float arg2){
        return this_.initWithTargetAndOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("isBoundarySet", &Follow::isBoundarySet, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Follow>, allow_raw_pointers())
    .class_function("create", &Follow::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::Node* arg0){
        return Follow::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithOffset", &Follow::createWithOffset, allow_raw_pointers())
    .class_function("createWithOffset", optional_override(
      [](cocos2d::Node* arg0, float arg1, float arg2){
        return Follow::createWithOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Follow& _) -> std::string {return "Follow";}))    
    // TODO: assign cc.Class.extend to cc.Follow.extend
    ;


  class_<Image>("cc.Image")
    .constructor<>()
    .function("hasPremultipliedAlpha", &Image::hasPremultipliedAlpha, allow_raw_pointers())
    .function("reversePremultipliedAlpha", &Image::reversePremultipliedAlpha, allow_raw_pointers())
    .function("getDataLen", &Image::getDataLen, allow_raw_pointers())
    .function("saveToFile", &Image::saveToFile, allow_raw_pointers())
    .function("saveToFile", optional_override(
        [](Image& this_, const std::string& arg0){
        return this_.saveToFile(arg0);
      }), allow_raw_pointers())
    .function("getBitPerPixel", &Image::getBitPerPixel, allow_raw_pointers())
    .function("hasAlpha", &Image::hasAlpha, allow_raw_pointers())
    .function("isCompressed", &Image::isCompressed, allow_raw_pointers())
    .function("getHeight", &Image::getHeight, allow_raw_pointers())
    .function("premultiplyAlpha", &Image::premultiplyAlpha, allow_raw_pointers())
    .function("initWithImageFile", &Image::initWithImageFile, allow_raw_pointers())
    .function("getWidth", &Image::getWidth, allow_raw_pointers())
    .function("getFileType", &Image::getFileType, allow_raw_pointers())
    .function("getFilePath", &Image::getFilePath, allow_raw_pointers())
    .function("getNumberOfMipmaps", &Image::getNumberOfMipmaps, allow_raw_pointers())
    .function("getRenderFormat", &Image::getRenderFormat, allow_raw_pointers())
    .function("getData", &Image::getData, allow_raw_pointers())
    .function("getMipmaps", &Image::getMipmaps, allow_raw_pointers())
    .function("initWithRawData", &Image::initWithRawData, allow_raw_pointers())
    .function("initWithRawData", optional_override(
        [](Image& this_, const unsigned char* arg0, int arg1, int arg2, int arg3, int arg4){
        return this_.initWithRawData(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .class_function("setPVRImagesHavePremultipliedAlpha", &Image::setPVRImagesHavePremultipliedAlpha, allow_raw_pointers())
    .class_function("setPNGPremultipliedAlphaEnabled", &Image::setPNGPremultipliedAlphaEnabled, allow_raw_pointers())
    .property("_className",  optional_override([](const Image& _) -> std::string {return "Image";}))    
    ;


  class_<GLProgramState>("cc.GLProgramState")
    .constructor<>()
    .function("setUniformCallback", select_overload<void(int, const std::function<void (cocos2d::GLProgram *, cocos2d::Uniform *)>&)>(&GLProgramState::setUniformCallback), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribsFlags", &GLProgramState::getVertexAttribsFlags, allow_raw_pointers())
    .function("applyAutoBinding", &GLProgramState::applyAutoBinding, allow_raw_pointers())
    .function("setUniformVec2", select_overload<void(int, const cocos2d::Vec2&)>(&GLProgramState::setUniformVec2), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformVec3", select_overload<void(int, const cocos2d::Vec3&)>(&GLProgramState::setUniformVec3), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setVertexAttribCallback", &GLProgramState::setVertexAttribCallback, allow_raw_pointers())
    .function("apply", &GLProgramState::apply, allow_raw_pointers())
    .function("getNodeBinding", &GLProgramState::getNodeBinding, allow_raw_pointers())
    .function("applyGLProgram", &GLProgramState::applyGLProgram, allow_raw_pointers())
    .function("setNodeBinding", &GLProgramState::setNodeBinding, allow_raw_pointers())
    .function("setUniformInt", select_overload<void(int, int)>(&GLProgramState::setUniformInt), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setParameterAutoBinding", &GLProgramState::setParameterAutoBinding, allow_raw_pointers())
    .function("setUniformVec2v", select_overload<void(int, int, const cocos2d::Vec2*)>(&GLProgramState::setUniformVec2v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getUniformCount", &GLProgramState::getUniformCount, allow_raw_pointers())
    .function("applyAttributes", &GLProgramState::applyAttributes, allow_raw_pointers())
    .function("applyAttributes", optional_override(
        [](GLProgramState& this_){
        return this_.applyAttributes();
      }), allow_raw_pointers())
    .function("clone", &GLProgramState::clone, allow_raw_pointers())
    .function("setGLProgram", &GLProgramState::setGLProgram, allow_raw_pointers())
    .function("setUniformFloatv", select_overload<void(int, int, const float*)>(&GLProgramState::setUniformFloatv), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGLProgram", &GLProgramState::getGLProgram, allow_raw_pointers())
    .function("setUniformTexture", select_overload<void(const std::string&, cocos2d::Texture2D*)>(&GLProgramState::setUniformTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("applyUniforms", &GLProgramState::applyUniforms, allow_raw_pointers())
    .function("setUniformFloat", select_overload<void(int, float)>(&GLProgramState::setUniformFloat), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformMat4", select_overload<void(int, const cocos2d::Mat4&)>(&GLProgramState::setUniformMat4), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformVec3v", select_overload<void(int, int, const cocos2d::Vec3*)>(&GLProgramState::setUniformVec3v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribCount", &GLProgramState::getVertexAttribCount, allow_raw_pointers())
    .class_function("create", &GLProgramState::create, allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<cocos2d::GLProgramState*(const std::string&, cocos2d::Texture2D*)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<cocos2d::GLProgramState*(const std::string&)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgram", &GLProgramState::getOrCreateWithGLProgram, allow_raw_pointers())
    .class_function("getOrCreateWithShaders", &GLProgramState::getOrCreateWithShaders, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramState& _) -> std::string {return "GLProgramState";}))    
    ;


  class_<SpriteFrame>("cc.SpriteFrame")
    .constructor<>()
    .function("setAnchorPoint", &SpriteFrame::setAnchorPoint, allow_raw_pointers())
    .function("setTexture", &SpriteFrame::setTexture, allow_raw_pointers())
    .function("getTexture", &SpriteFrame::getTexture, allow_raw_pointers())
    .function("setOffsetInPixels", &SpriteFrame::setOffsetInPixels, allow_raw_pointers())
    .function("getOriginalSizeInPixels", &SpriteFrame::getOriginalSizeInPixels, allow_raw_pointers())
    .function("setOriginalSize", &SpriteFrame::setOriginalSize, allow_raw_pointers())
    .function("getCenterRect", &SpriteFrame::getCenterRect, allow_raw_pointers())
    .function("setRectInPixels", &SpriteFrame::setRectInPixels, allow_raw_pointers())
    .function("getRect", &SpriteFrame::getRect, allow_raw_pointers())
    .function("setCenterRectInPixels", &SpriteFrame::setCenterRectInPixels, allow_raw_pointers())
    .function("setOffset", &SpriteFrame::setOffset, allow_raw_pointers())
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::initWithTextureFilename), allow_raw_pointers())
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const cocos2d::Rect&)>(&SpriteFrame::initWithTextureFilename), allow_raw_pointers())
    .function("setRect", &SpriteFrame::setRect, allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
    .function("getOriginalSize", &SpriteFrame::getOriginalSize, allow_raw_pointers())
    .function("getRectInPixels", &SpriteFrame::getRectInPixels, allow_raw_pointers())
    .function("isRotated", &SpriteFrame::isRotated, allow_raw_pointers())
    .function("hasCenterRect", &SpriteFrame::hasCenterRect, allow_raw_pointers())
    .function("setRotated", &SpriteFrame::setRotated, allow_raw_pointers())
    .function("getOffset", &SpriteFrame::getOffset, allow_raw_pointers())
    .function("setOriginalSizeInPixels", &SpriteFrame::setOriginalSizeInPixels, allow_raw_pointers())
    .function("getAnchorPoint", &SpriteFrame::getAnchorPoint, allow_raw_pointers())
    .function("hasAnchorPoint", &SpriteFrame::hasAnchorPoint, allow_raw_pointers())
    .function("getOffsetInPixels", &SpriteFrame::getOffsetInPixels, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SpriteFrame>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::SpriteFrame*(const std::string&, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::SpriteFrame*(const std::string&, const cocos2d::Rect&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<cocos2d::SpriteFrame*(cocos2d::Texture2D*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<cocos2d::SpriteFrame*(cocos2d::Texture2D*, const cocos2d::Rect&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrame& _) -> std::string {return "SpriteFrame";}))    
    // TODO: assign cc.Class.extend to cc.SpriteFrame.extend
    ;


  class_<AnimationFrame>("cc.AnimationFrame")
    .constructor<>()
    .function("setSpriteFrame", &AnimationFrame::setSpriteFrame, allow_raw_pointers())
    .function("getUserInfo", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&AnimationFrame::getUserInfo), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setDelayUnits", &AnimationFrame::setDelayUnits, allow_raw_pointers())
    .function("getSpriteFrame", &AnimationFrame::getSpriteFrame, allow_raw_pointers())
    .function("getDelayUnits", &AnimationFrame::getDelayUnits, allow_raw_pointers())
    .function("setUserInfo", &AnimationFrame::setUserInfo, allow_raw_pointers())
    .function("initWithSpriteFrame", &AnimationFrame::initWithSpriteFrame, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<AnimationFrame>, allow_raw_pointers())
    .class_function("create", &AnimationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationFrame& _) -> std::string {return "AnimationFrame";}))    
    // TODO: assign cc.Class.extend to cc.AnimationFrame.extend
    ;


  class_<Animation>("cc.Animation")
    .constructor<>()
    .function("getLoops", &Animation::getLoops, allow_raw_pointers())
    .function("addSpriteFrame", &Animation::addSpriteFrame, allow_raw_pointers())
    .function("setRestoreOriginalFrame", &Animation::setRestoreOriginalFrame, allow_raw_pointers())
    .function("getDuration", &Animation::getDuration, allow_raw_pointers())
    .function("initWithAnimationFrames", &Animation::initWithAnimationFrames, allow_raw_pointers())
    .function("init", &Animation::init, allow_raw_pointers())
    .function("setFrames", &Animation::setFrames, allow_raw_pointers())
    .function("getFrames", &Animation::getFrames, allow_raw_pointers())
    .function("setLoops", &Animation::setLoops, allow_raw_pointers())
    .function("setDelayPerUnit", &Animation::setDelayPerUnit, allow_raw_pointers())
    .function("addSpriteFrameWithFile", &Animation::addSpriteFrameWithFile, allow_raw_pointers())
    .function("getTotalDelayUnits", &Animation::getTotalDelayUnits, allow_raw_pointers())
    .function("getDelayPerUnit", &Animation::getDelayPerUnit, allow_raw_pointers())
    .function("initWithSpriteFrames", &Animation::initWithSpriteFrames, allow_raw_pointers())
    .function("initWithSpriteFrames", optional_override(
        [](Animation& this_, const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){
        return this_.initWithSpriteFrames(arg0);
      }), allow_raw_pointers())
    .function("initWithSpriteFrames", optional_override(
        [](Animation& this_, const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0, float arg1){
        return this_.initWithSpriteFrames(arg0, arg1);
      }), allow_raw_pointers())
    .function("getRestoreOriginalFrame", &Animation::getRestoreOriginalFrame, allow_raw_pointers())
    .function("addSpriteFrameWithTexture", &Animation::addSpriteFrameWithTexture, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Animation>, allow_raw_pointers())
    .class_function("createWithAnimationFrames", select_overload<cocos2d::Animation*(const cocos2d::Vector<cocos2d::AnimationFrame *>&, float, unsigned int)>(&Animation::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithAnimationFrames", select_overload<cocos2d::Animation*()>(&Animation::create), allow_raw_pointers())
    .class_function("createWithSpriteFrames", &Animation::createWithSpriteFrames, allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){
        return Animation::createWithSpriteFrames(arg0);
      }), allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0, float arg1){
        return Animation::createWithSpriteFrames(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Animation& _) -> std::string {return "Animation";}))    
    // TODO: assign cc.Class.extend to cc.Animation.extend
    ;

  class_<ActionInterval, base<FiniteTimeAction>>("cc.ActionInterval")
    .function("setAmplitudeRate", &ActionInterval::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &ActionInterval::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &ActionInterval::getAmplitudeRate, allow_raw_pointers())
    .function("getElapsed", &ActionInterval::getElapsed, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionInterval& _) -> std::string {return "ActionInterval";}))    
    ;


  class_<Sequence, base<ActionInterval>>("cc.Sequence")
    .constructor<>()
    .function("initWithTwoActions", &Sequence::initWithTwoActions, allow_raw_pointers())
    .function("init", &Sequence::init, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Sequence>, allow_raw_pointers())
    .property("_className",  optional_override([](const Sequence& _) -> std::string {return "Sequence";}))    
    // TODO: assign cc.Class.extend to cc.Sequence.extend
    ;


  class_<Repeat, base<ActionInterval>>("cc.Repeat")
    .constructor<>()
    .function("setInnerAction", &Repeat::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &Repeat::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Repeat::getInnerAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Repeat>, allow_raw_pointers())
    .class_function("create", &Repeat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Repeat& _) -> std::string {return "Repeat";}))    
    // TODO: assign cc.Class.extend to cc.Repeat.extend
    ;


  class_<RepeatForever, base<ActionInterval>>("cc.RepeatForever")
    .constructor<>()
    .function("setInnerAction", &RepeatForever::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &RepeatForever::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &RepeatForever::getInnerAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RepeatForever>, allow_raw_pointers())
    .class_function("create", &RepeatForever::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RepeatForever& _) -> std::string {return "RepeatForever";}))    
    // TODO: assign cc.Class.extend to cc.RepeatForever.extend
    ;


  class_<Spawn, base<ActionInterval>>("cc.Spawn")
    .constructor<>()
    .function("initWithTwoActions", &Spawn::initWithTwoActions, allow_raw_pointers())
    .function("init", &Spawn::init, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Spawn>, allow_raw_pointers())
    .property("_className",  optional_override([](const Spawn& _) -> std::string {return "Spawn";}))    
    // TODO: assign cc.Class.extend to cc.Spawn.extend
    ;


  class_<RotateTo, base<ActionInterval>>("cc.RotateTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&RotateTo::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateTo::initWithDuration), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RotateTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateTo*(float, float)>(&RotateTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateTo*(float, float, float)>(&RotateTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateTo& _) -> std::string {return "RotateTo";}))    
    // TODO: assign cc.Class.extend to cc.RotateTo.extend
    ;


  class_<RotateBy, base<ActionInterval>>("cc.RotateBy")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateBy::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float)>(&RotateBy::initWithDuration), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<RotateBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateBy*(float, float, float)>(&RotateBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateBy*(float, float)>(&RotateBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateBy& _) -> std::string {return "RotateBy";}))    
    // TODO: assign cc.Class.extend to cc.RotateBy.extend
    ;


  class_<MoveBy, base<ActionInterval>>("cc.MoveBy")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&MoveBy::initWithDuration), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<MoveBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MoveBy*(float, const cocos2d::Vec3&)>(&MoveBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveBy& _) -> std::string {return "MoveBy";}))    
    // TODO: assign cc.Class.extend to cc.MoveBy.extend
    ;


  class_<MoveTo, base<MoveBy>>("cc.MoveTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&MoveTo::initWithDuration), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<MoveTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MoveTo*(float, const cocos2d::Vec3&)>(&MoveTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveTo& _) -> std::string {return "MoveTo";}))    
    // TODO: assign cc.Class.extend to cc.MoveTo.extend
    ;


  class_<SkewTo, base<ActionInterval>>("cc.SkewTo")
    .constructor<>()
    .function("initWithDuration", &SkewTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SkewTo>, allow_raw_pointers())
    .class_function("create", &SkewTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewTo& _) -> std::string {return "SkewTo";}))    
    // TODO: assign cc.Class.extend to cc.SkewTo.extend
    ;


  class_<SkewBy, base<SkewTo>>("cc.SkewBy")
    .constructor<>()
    .function("initWithDuration", &SkewBy::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SkewBy>, allow_raw_pointers())
    .class_function("create", &SkewBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewBy& _) -> std::string {return "SkewBy";}))    
    // TODO: assign cc.Class.extend to cc.SkewBy.extend
    ;


  class_<JumpBy, base<ActionInterval>>("cc.JumpBy")
    .constructor<>()
    .function("initWithDuration", &JumpBy::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<JumpBy>, allow_raw_pointers())
    .class_function("create", &JumpBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpBy& _) -> std::string {return "JumpBy";}))    
    // TODO: assign cc.Class.extend to cc.JumpBy.extend
    ;


  class_<JumpTo, base<JumpBy>>("cc.JumpTo")
    .constructor<>()
    .function("initWithDuration", &JumpTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<JumpTo>, allow_raw_pointers())
    .class_function("create", &JumpTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTo& _) -> std::string {return "JumpTo";}))    
    // TODO: assign cc.Class.extend to cc.JumpTo.extend
    ;


  class_<BezierBy, base<ActionInterval>>("cc.BezierBy")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<BezierBy>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierBy& _) -> std::string {return "BezierBy";}))    
    // TODO: assign cc.Class.extend to cc.BezierBy.extend
    ;


  class_<BezierTo, base<BezierBy>>("cc.BezierTo")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<BezierTo>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierTo& _) -> std::string {return "BezierTo";}))    
    // TODO: assign cc.Class.extend to cc.BezierTo.extend
    ;


  class_<ScaleTo, base<ActionInterval>>("cc.ScaleTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, float, float)>(&ScaleTo::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float)>(&ScaleTo::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float, float, float)>(&ScaleTo::initWithDuration), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ScaleTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleTo& _) -> std::string {return "ScaleTo";}))    
    // TODO: assign cc.Class.extend to cc.ScaleTo.extend
    ;


  class_<ScaleBy, base<ScaleTo>>("cc.ScaleBy")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<ScaleBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleBy& _) -> std::string {return "ScaleBy";}))    
    // TODO: assign cc.Class.extend to cc.ScaleBy.extend
    ;


  class_<Blink, base<ActionInterval>>("cc.Blink")
    .constructor<>()
    .function("initWithDuration", &Blink::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Blink>, allow_raw_pointers())
    .class_function("create", &Blink::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Blink& _) -> std::string {return "Blink";}))    
    // TODO: assign cc.Class.extend to cc.Blink.extend
    ;


  class_<FadeTo, base<ActionInterval>>("cc.FadeTo")
    .constructor<>()
    .function("initWithDuration", &FadeTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeTo>, allow_raw_pointers())
    .class_function("create", &FadeTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeTo& _) -> std::string {return "FadeTo";}))    
    // TODO: assign cc.Class.extend to cc.FadeTo.extend
    ;


  class_<FadeIn, base<FadeTo>>("cc.FadeIn")
    .constructor<>()
    .function("setReverseAction", &FadeIn::setReverseAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeIn>, allow_raw_pointers())
    .class_function("create", &FadeIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeIn& _) -> std::string {return "FadeIn";}))    
    // TODO: assign cc.Class.extend to cc.FadeIn.extend
    ;


  class_<FadeOut, base<FadeTo>>("cc.FadeOut")
    .constructor<>()
    .function("setReverseAction", &FadeOut::setReverseAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeOut>, allow_raw_pointers())
    .class_function("create", &FadeOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOut& _) -> std::string {return "FadeOut";}))    
    // TODO: assign cc.Class.extend to cc.FadeOut.extend
    ;


  class_<TintTo, base<ActionInterval>>("cc.TintTo")
    .constructor<>()
    .function("initWithDuration", &TintTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TintTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TintTo*(float, const cocos2d::Color3B&)>(&TintTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TintTo*(float, unsigned char, unsigned char, unsigned char)>(&TintTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TintTo& _) -> std::string {return "TintTo";}))    
    // TODO: assign cc.Class.extend to cc.TintTo.extend
    ;


  class_<TintBy, base<ActionInterval>>("cc.TintBy")
    .constructor<>()
    .function("initWithDuration", &TintBy::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TintBy>, allow_raw_pointers())
    .class_function("create", &TintBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TintBy& _) -> std::string {return "TintBy";}))    
    // TODO: assign cc.Class.extend to cc.TintBy.extend
    ;


  class_<DelayTime, base<ActionInterval>>("cc.DelayTime")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<DelayTime>, allow_raw_pointers())
    .class_function("create", &DelayTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DelayTime& _) -> std::string {return "DelayTime";}))    
    // TODO: assign cc.Class.extend to cc.DelayTime.extend
    ;


  class_<ReverseTime, base<ActionInterval>>("cc.ReverseTime")
    .constructor<>()
    .function("initWithAction", &ReverseTime::initWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ReverseTime>, allow_raw_pointers())
    .class_function("create", &ReverseTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReverseTime& _) -> std::string {return "ReverseTime";}))    
    // TODO: assign cc.Class.extend to cc.ReverseTime.extend
    ;


  class_<Animate, base<ActionInterval>>("cc.Animate")
    .constructor<>()
    .function("getAnimation", select_overload<const cocos2d::Animation*() const>(&Animate::getAnimation), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCurrentFrameIndex", &Animate::getCurrentFrameIndex, allow_raw_pointers())
    .function("initWithAnimation", &Animate::initWithAnimation, allow_raw_pointers())
    .function("setAnimation", &Animate::setAnimation, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Animate>, allow_raw_pointers())
    .class_function("create", &Animate::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Animate& _) -> std::string {return "Animate";}))    
    // TODO: assign cc.Class.extend to cc.Animate.extend
    ;


  class_<TargetedAction, base<ActionInterval>>("cc.TargetedAction")
    .constructor<>()
    .function("setForcedTarget", &TargetedAction::setForcedTarget, allow_raw_pointers())
    .function("initWithTarget", &TargetedAction::initWithTarget, allow_raw_pointers())
    .function("getForcedTarget", select_overload<const cocos2d::Node*() const>(&TargetedAction::getForcedTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<TargetedAction>, allow_raw_pointers())
    .class_function("create", &TargetedAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TargetedAction& _) -> std::string {return "TargetedAction";}))    
    // TODO: assign cc.Class.extend to cc.TargetedAction.extend
    ;


  class_<ActionFloat, base<ActionInterval>>("cc.ActionFloat")
    .constructor<>()
    .function("initWithDuration", &ActionFloat::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ActionFloat>, allow_raw_pointers())
    .class_function("create", &ActionFloat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionFloat& _) -> std::string {return "ActionFloat";}))    
    // TODO: assign cc.Class.extend to cc.ActionFloat.extend
    ;

  class_<Configuration>("cc.Configuration")
    .function("supportsPVRTC", &Configuration::supportsPVRTC, allow_raw_pointers())
    .function("supportsOESDepth24", &Configuration::supportsOESDepth24, allow_raw_pointers())
    .function("getMaxModelviewStackDepth", &Configuration::getMaxModelviewStackDepth, allow_raw_pointers())
    .function("supportsShareableVAO", &Configuration::supportsShareableVAO, allow_raw_pointers())
    .function("supportsBGRA8888", &Configuration::supportsBGRA8888, allow_raw_pointers())
    .function("checkForGLExtension", &Configuration::checkForGLExtension, allow_raw_pointers())
    .function("supportsETC2", &Configuration::supportsETC2, allow_raw_pointers())
    .function("supportsETC1", &Configuration::supportsETC1, allow_raw_pointers())
    .function("supportsATITC", &Configuration::supportsATITC, allow_raw_pointers())
    .function("supportsNPOT", &Configuration::supportsNPOT, allow_raw_pointers())
    .function("init", &Configuration::init, allow_raw_pointers())
    .function("getAnimate3DQuality", &Configuration::getAnimate3DQuality, allow_raw_pointers())
    .function("getMaxSupportPointLightInShader", &Configuration::getMaxSupportPointLightInShader, allow_raw_pointers())
    .function("getMaxTextureSize", &Configuration::getMaxTextureSize, allow_raw_pointers())
    .function("setValue", &Configuration::setValue, allow_raw_pointers())
    .function("getMaxSupportSpotLightInShader", &Configuration::getMaxSupportSpotLightInShader, allow_raw_pointers())
    .function("supportsETC", &Configuration::supportsETC, allow_raw_pointers())
    .function("getMaxSupportDirLightInShader", &Configuration::getMaxSupportDirLightInShader, allow_raw_pointers())
    .function("loadConfigFile", &Configuration::loadConfigFile, allow_raw_pointers())
    .function("supportsDiscardFramebuffer", &Configuration::supportsDiscardFramebuffer, allow_raw_pointers())
    .function("supportsOESPackedDepthStencil", &Configuration::supportsOESPackedDepthStencil, allow_raw_pointers())
    .function("supportsS3TC", &Configuration::supportsS3TC, allow_raw_pointers())
    .function("dumpInfo", &Configuration::getInfo, allow_raw_pointers())
    .function("getMaxTextureUnits", &Configuration::getMaxTextureUnits, allow_raw_pointers())
    .function("getValue", &Configuration::getValue, allow_raw_pointers())
    .function("getValue", optional_override(
        [](Configuration& this_, const std::string& arg0){
        return this_.getValue(arg0);
      }), allow_raw_pointers())
    .function("gatherGPUInfo", &Configuration::gatherGPUInfo, allow_raw_pointers())
    .function("supportsMapBuffer", &Configuration::supportsMapBuffer, allow_raw_pointers())
    .function("getInfoAsMap", &Configuration::getInfoAsMap, allow_raw_pointers())
    .class_function("destroyInstance", &Configuration::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &Configuration::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Configuration& _) -> std::string {return "Configuration";}))    
    ;

  class_<Properties>("cc.Properties")
    .function("getVariable", &Properties::getVariable, allow_raw_pointers())
    .function("getVariable", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getVariable(arg0);
      }), allow_raw_pointers())
    .function("getString", &Properties::getString, allow_raw_pointers())
    .function("getString", optional_override(
        [](Properties& this_){
        return this_.getString();
      }), allow_raw_pointers())
    .function("getString", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getString(arg0);
      }), allow_raw_pointers())
    .function("getLong", &Properties::getLong, allow_raw_pointers())
    .function("getLong", optional_override(
        [](Properties& this_){
        return this_.getLong();
      }), allow_raw_pointers())
    .function("getNamespace", select_overload<const char*() const>(&Properties::getNamespace), allow_raw_pointers())
    .function("getNamespace", select_overload<cocos2d::Properties*(const char*, bool, bool) const>(&Properties::getNamespace), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("getPath", &Properties::getPath, allow_raw_pointers())
    .function("getMat4", &Properties::getMat4, allow_raw_pointers())
    .function("exists", &Properties::exists, allow_raw_pointers())
    .function("setString", &Properties::setString, allow_raw_pointers())
    .function("getId", &Properties::getId, allow_raw_pointers())
    .function("rewind", &Properties::rewind, allow_raw_pointers())
    .function("setVariable", &Properties::setVariable, allow_raw_pointers())
    .function("getBool", &Properties::getBool, allow_raw_pointers())
    .function("getBool", optional_override(
        [](Properties& this_){
        return this_.getBool();
      }), allow_raw_pointers())
    .function("getBool", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getBool(arg0);
      }), allow_raw_pointers())
    .function("getColor", select_overload<bool(const char*, cocos2d::Vec4*) const>(&Properties::getColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getType", &Properties::getType, allow_raw_pointers())
    .function("getType", optional_override(
        [](Properties& this_){
        return this_.getType();
      }), allow_raw_pointers())
    .function("getNextNamespace", &Properties::getNextNamespace, allow_raw_pointers())
    .function("getInt", &Properties::getInt, allow_raw_pointers())
    .function("getInt", optional_override(
        [](Properties& this_){
        return this_.getInt();
      }), allow_raw_pointers())
    .function("getVec3", &Properties::getVec3, allow_raw_pointers())
    .function("getVec2", &Properties::getVec2, allow_raw_pointers())
    .function("getVec4", &Properties::getVec4, allow_raw_pointers())
    .function("getNextProperty", &Properties::getNextProperty, allow_raw_pointers())
    .function("getFloat", &Properties::getFloat, allow_raw_pointers())
    .function("getFloat", optional_override(
        [](Properties& this_){
        return this_.getFloat();
      }), allow_raw_pointers())
    .function("getQuaternionFromAxisAngle", &Properties::getQuaternionFromAxisAngle, allow_raw_pointers())
    .class_function("parseColor", select_overload<bool(const char*, cocos2d::Vec4*)>(&Properties::parseColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("parseVec3", &Properties::parseVec3, allow_raw_pointers())
    .class_function("parseAxisAngle", &Properties::parseAxisAngle, allow_raw_pointers())
    .class_function("parseVec2", &Properties::parseVec2, allow_raw_pointers())
    .class_function("createNonRefCounted", &Properties::createNonRefCounted, allow_raw_pointers())
    .class_function("parseVec4", &Properties::parseVec4, allow_raw_pointers())
    .property("_className",  optional_override([](const Properties& _) -> std::string {return "Properties";}))    
    ;

  class_<FileUtils>("cc.FileUtils")
    .function("fullPathForFilename", &FileUtils::fullPathForFilename, allow_raw_pointers())
    .function("getStringFromFile", select_overload<void(const std::string&, std::function<void (std::string)>) const>(&FileUtils::getStringFromFile), allow_raw_pointers())
    .function("getStringFromFile", select_overload<std::string(const std::string&) const>(&FileUtils::getStringFromFile), allow_raw_pointers())
    .function("removeFile", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::removeFile), allow_raw_pointers())
    .function("removeFile", select_overload<bool(const std::string&) const>(&FileUtils::removeFile), allow_raw_pointers())
    .function("isAbsolutePath", &FileUtils::isAbsolutePath, allow_raw_pointers())
    .function("renameFile", select_overload<void(const std::string&, const std::string&, const std::string&, std::function<void (bool)>) const>(&FileUtils::renameFile), allow_raw_pointers())
    .function("renameFile", select_overload<bool(const std::string&, const std::string&, const std::string&) const>(&FileUtils::renameFile), allow_raw_pointers())
    .function("renameFile", select_overload<bool(const std::string&, const std::string&) const>(&FileUtils::renameFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getDefaultResourceRootPath", &FileUtils::getDefaultResourceRootPath, allow_raw_pointers())
    .function("loadFilenameLookup", &FileUtils::loadFilenameLookupDictionaryFromFile, allow_raw_pointers())
    .function("isPopupNotify", &FileUtils::isPopupNotify, allow_raw_pointers())
    .function("getValueVectorFromFile", &FileUtils::getValueVectorFromFile, allow_raw_pointers())
    .function("removeDirectory", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::removeDirectory), allow_raw_pointers())
    .function("removeDirectory", select_overload<bool(const std::string&) const>(&FileUtils::removeDirectory), allow_raw_pointers())
    .function("getSearchPaths", &FileUtils::getSearchPaths, allow_raw_pointers())
    .function("writeToFile", &FileUtils::writeToFile, allow_raw_pointers())
    .function("getOriginalSearchPaths", &FileUtils::getOriginalSearchPaths, allow_raw_pointers())
    .function("getNewFilename", &FileUtils::getNewFilename, allow_raw_pointers())
    .function("listFiles", &FileUtils::listFiles, allow_raw_pointers())
    .function("getValueMapFromFile", &FileUtils::getValueMapFromFile, allow_raw_pointers())
    .function("getFileSize", select_overload<void(const std::string&, std::function<void (long)>) const>(&FileUtils::getFileSize), allow_raw_pointers())
    .function("getFileSize", select_overload<long(const std::string&) const>(&FileUtils::getFileSize), allow_raw_pointers())
    .function("getValueMapFromData", &FileUtils::getValueMapFromData, allow_raw_pointers())
    .function("setSearchPaths", &FileUtils::setSearchPaths, allow_raw_pointers())
    .function("writeStringToFile", select_overload<void(std::string, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeStringToFile), allow_raw_pointers())
    .function("writeStringToFile", select_overload<bool(const std::string&, const std::string&) const>(&FileUtils::writeStringToFile), allow_raw_pointers())
    .function("setSearchResolutionsOrder", &FileUtils::setSearchResolutionsOrder, allow_raw_pointers())
    .function("addSearchResolutionsOrder", &FileUtils::addSearchResolutionsOrder, allow_raw_pointers())
    .function("addSearchResolutionsOrder", optional_override(
        [](FileUtils& this_, const std::string& arg0){
        return this_.addSearchResolutionsOrder(arg0);
      }), allow_raw_pointers())
    .function("addSearchPath", &FileUtils::addSearchPath, allow_raw_pointers())
    .function("addSearchPath", optional_override(
        [](FileUtils& this_, const std::string& arg0){
        return this_.addSearchPath(arg0);
      }), allow_raw_pointers())
    .function("writeValueVectorToFile", select_overload<void(std::vector<cocos2d::Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueVectorToFile), allow_raw_pointers())
    .function("writeValueVectorToFile", select_overload<bool(const std::vector<cocos2d::Value>&, const std::string&) const>(&FileUtils::writeValueVectorToFile), allow_raw_pointers())
    .function("isFileExist", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::isFileExist), allow_raw_pointers())
    .function("isFileExist", select_overload<bool(const std::string&) const>(&FileUtils::isFileExist), allow_raw_pointers())
    .function("purgeCachedEntries", &FileUtils::purgeCachedEntries, allow_raw_pointers())
    .function("fullPathFromRelativeFile", &FileUtils::fullPathFromRelativeFile, allow_raw_pointers())
    .function("getSuitableFOpen", &FileUtils::getSuitableFOpen, allow_raw_pointers())
    .function("writeValueMapToFile", select_overload<void(std::unordered_map<std::string, cocos2d::Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueMapToFile), allow_raw_pointers())
    .function("writeValueMapToFile", select_overload<bool(const std::unordered_map<std::string, cocos2d::Value>&, const std::string&) const>(&FileUtils::writeValueMapToFile), allow_raw_pointers())
    .function("getFileExtension", &FileUtils::getFileExtension, allow_raw_pointers())
    .function("setWritablePath", &FileUtils::setWritablePath, allow_raw_pointers())
    .function("setPopupNotify", &FileUtils::setPopupNotify, allow_raw_pointers())
    .function("isDirectoryExist", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::isDirectoryExist), allow_raw_pointers())
    .function("isDirectoryExist", select_overload<bool(const std::string&) const>(&FileUtils::isDirectoryExist), allow_raw_pointers())
    .function("setDefaultResourceRootPath", &FileUtils::setDefaultResourceRootPath, allow_raw_pointers())
    .function("getSearchResolutionsOrder", &FileUtils::getSearchResolutionsOrder, allow_raw_pointers())
    .function("createDirectory", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::createDirectory), allow_raw_pointers())
    .function("createDirectory", select_overload<bool(const std::string&) const>(&FileUtils::createDirectory), allow_raw_pointers())
    .function("getWritablePath", &FileUtils::getWritablePath, allow_raw_pointers())
    .function("listFilesRecursively", &FileUtils::listFilesRecursively, allow_raw_pointers())
    .class_function("setDelegate", &FileUtils::setDelegate, allow_raw_pointers())
    .class_function("getInstance", &FileUtils::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const FileUtils& _) -> std::string {return "FileUtils";}))    
    ;


  class_<EventAcceleration, base<Event>>("cc.EventAcceleration")
    .constructor<const cocos2d::Acceleration&>()
    .property("_className",  optional_override([](const EventAcceleration& _) -> std::string {return "EventAcceleration";}))    
    ;


  class_<EventCustom, base<Event>>("cc.EventCustom")
    .constructor<const std::string&>()
    .function("getEventName", &EventCustom::getEventName, allow_raw_pointers())
    .property("_className",  optional_override([](const EventCustom& _) -> std::string {return "EventCustom";}))    
    ;

  class_<EventListener>("cc.EventListener")
    .function("setEnabled", &EventListener::setEnabled, allow_raw_pointers())
    .function("isEnabled", &EventListener::isEnabled, allow_raw_pointers())
    .function("clone", &EventListener::clone, allow_raw_pointers())
    .function("checkAvailable", &EventListener::checkAvailable, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListener& _) -> std::string {return "EventListener";}))    
    ;


  class_<EventDispatcher>("cc.EventDispatcher")
    .constructor<>()
    .function("setEnabled", &EventDispatcher::setEnabled, allow_raw_pointers())
    .function("removeAllListeners", &EventDispatcher::removeAllEventListeners, allow_raw_pointers())
    .function("addEventListenerWithSceneGraphPriority", &EventDispatcher::addEventListenerWithSceneGraphPriority, allow_raw_pointers())
    .function("addEventListenerWithFixedPriority", &EventDispatcher::addEventListenerWithFixedPriority, allow_raw_pointers())
    .function("removeListeners", select_overload<void(cocos2d::Node*, bool)>(&EventDispatcher::removeEventListenersForTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeListeners", select_overload<void(cocos2d::EventListener::Type)>(&EventDispatcher::removeEventListenersForType), allow_raw_pointers())
    .function("resumeTarget", &EventDispatcher::resumeEventListenersForTarget, allow_raw_pointers())
    .function("resumeTarget", optional_override(
        [](EventDispatcher& this_, cocos2d::Node* arg0){
        return this_.resumeEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("setPriority", &EventDispatcher::setPriority, allow_raw_pointers())
    .function("dispatchEvent", &EventDispatcher::dispatchEvent, allow_raw_pointers())
    .function("hasEventListener", &EventDispatcher::hasEventListener, allow_raw_pointers())
    .function("pauseTarget", &EventDispatcher::pauseEventListenersForTarget, allow_raw_pointers())
    .function("pauseTarget", optional_override(
        [](EventDispatcher& this_, cocos2d::Node* arg0){
        return this_.pauseEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("removeCustomListeners", &EventDispatcher::removeCustomEventListeners, allow_raw_pointers())
    .function("removeListener", &EventDispatcher::removeEventListener, allow_raw_pointers())
    .function("isEnabled", &EventDispatcher::isEnabled, allow_raw_pointers())
    .property("_className",  optional_override([](const EventDispatcher& _) -> std::string {return "EventDispatcher";}))    
    ;


  class_<EventFocus, base<Event>>("cc.EventFocus")
    .constructor<cocos2d::ui::Widget*, cocos2d::ui::Widget*>()
    .property("_className",  optional_override([](const EventFocus& _) -> std::string {return "EventFocus";}))    
    ;


  class_<EventListenerAcceleration, base<EventListener>>("cc.EventListenerAcceleration")
    .constructor<>()
    .function("init", &EventListenerAcceleration::init, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerAcceleration& _) -> std::string {return "EventListenerAcceleration";}))    
    ;


  class_<EventListenerCustom, base<EventListener>>("cc.EventListenerCustom")
    .constructor<>()
    .property("_className",  optional_override([](const EventListenerCustom& _) -> std::string {return "EventListenerCustom";}))    
    ;


  class_<EventListenerFocus, base<EventListener>>("cc.EventListenerFocus")
    .constructor<>()
    .function("init", &EventListenerFocus::init, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerFocus& _) -> std::string {return "EventListenerFocus";}))    
    ;


  class_<EventListenerKeyboard, base<EventListener>>("cc.EventListenerKeyboard")
    .constructor<>()
    .function("init", &EventListenerKeyboard::init, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerKeyboard& _) -> std::string {return "EventListenerKeyboard";}))    
    ;


  class_<EventMouse, base<Event>>("cc.EventMouse")
    .constructor<cocos2d::EventMouse::MouseEventType>()
    .function("getButton", &EventMouse::getMouseButton, allow_raw_pointers())
    .function("getLocation", &EventMouse::getLocation, allow_raw_pointers())
    .function("setButton", &EventMouse::setMouseButton, allow_raw_pointers())
    .function("setScrollData", &EventMouse::setScrollData, allow_raw_pointers())
    .function("getPreviousLocationInView", &EventMouse::getPreviousLocationInView, allow_raw_pointers())
    .function("getDelta", &EventMouse::getDelta, allow_raw_pointers())
    .function("getStartLocation", &EventMouse::getStartLocation, allow_raw_pointers())
    .function("getLocationY", &EventMouse::getCursorY, allow_raw_pointers())
    .function("getLocationX", &EventMouse::getCursorX, allow_raw_pointers())
    .function("getLocationInView", &EventMouse::getLocationInView, allow_raw_pointers())
    .function("getScrollY", &EventMouse::getScrollY, allow_raw_pointers())
    .function("setLocation", &EventMouse::setCursorPosition, allow_raw_pointers())
    .function("getScrollX", &EventMouse::getScrollX, allow_raw_pointers())
    .function("getPreviousLocation", &EventMouse::getPreviousLocation, allow_raw_pointers())
    .function("getStartLocationInView", &EventMouse::getStartLocationInView, allow_raw_pointers())
    .property("_className",  optional_override([](const EventMouse& _) -> std::string {return "EventMouse";}))    
    ;


  class_<EventListenerMouse, base<EventListener>>("cc.EventListenerMouse")
    .constructor<>()
    .function("init", &EventListenerMouse::init, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerMouse& _) -> std::string {return "EventListenerMouse";}))    
    ;

  class_<EventListenerController, base<EventListener>>("cc.EventListenerController")
    .class_function("create", &EventListenerController::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerController& _) -> std::string {return "EventListenerController";}))    
    ;


  class_<EventListenerTouchOneByOne, base<EventListener>>("cc.EventListenerTouchOneByOne")
    .constructor<>()
    .function("isSwallowTouches", &EventListenerTouchOneByOne::isSwallowTouches, allow_raw_pointers())
    .function("init", &EventListenerTouchOneByOne::init, allow_raw_pointers())
    .function("setSwallowTouches", &EventListenerTouchOneByOne::setSwallowTouches, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerTouchOneByOne& _) -> std::string {return "EventListenerTouchOneByOne";}))    
    ;


  class_<EventListenerTouchAllAtOnce, base<EventListener>>("cc.EventListenerTouchAllAtOnce")
    .constructor<>()
    .function("init", &EventListenerTouchAllAtOnce::init, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerTouchAllAtOnce& _) -> std::string {return "EventListenerTouchAllAtOnce";}))    
    ;


  class_<EventController, base<Event>>("cc.EventController")
        // TODO: overloaded constructor
    .function("getControllerEventType", &EventController::getControllerEventType, allow_raw_pointers())
    .function("setConnectStatus", &EventController::setConnectStatus, allow_raw_pointers())
    .function("isConnected", &EventController::isConnected, allow_raw_pointers())
    .function("setKeyCode", &EventController::setKeyCode, allow_raw_pointers())
    .function("getController", &EventController::getController, allow_raw_pointers())
    .function("getKeyCode", &EventController::getKeyCode, allow_raw_pointers())
    .property("_className",  optional_override([](const EventController& _) -> std::string {return "EventController";}))    
    ;


  class_<ActionCamera, base<ActionInterval>>("cc.ActionCamera")
    .constructor<>()
    .function("setEye", select_overload<void(float, float, float)>(&ActionCamera::setEye), allow_raw_pointers())
    .function("setEye", select_overload<void(const cocos2d::Vec3&)>(&ActionCamera::setEye), allow_raw_pointers())
    .function("getEye", &ActionCamera::getEye, allow_raw_pointers())
    .function("getCenter", &ActionCamera::getCenter, allow_raw_pointers())
    .function("setUp", &ActionCamera::setUp, allow_raw_pointers())
    .function("setCenter", &ActionCamera::setCenter, allow_raw_pointers())
    .function("getUp", &ActionCamera::getUp, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ActionCamera>, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionCamera& _) -> std::string {return "ActionCamera";}))    
    // TODO: assign cc.Class.extend to cc.ActionCamera.extend
    ;


  class_<OrbitCamera, base<ActionCamera>>("cc.OrbitCamera")
    .constructor<>()
    .function("initWithDuration", &OrbitCamera::initWithDuration, allow_raw_pointers())
    .function("sphericalRadius", &OrbitCamera::sphericalRadius, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<OrbitCamera>, allow_raw_pointers())
    .class_function("create", &OrbitCamera::create, allow_raw_pointers())
    .property("_className",  optional_override([](const OrbitCamera& _) -> std::string {return "OrbitCamera";}))    
    // TODO: assign cc.Class.extend to cc.OrbitCamera.extend
    ;


  class_<CardinalSplineTo, base<ActionInterval>>("cc.CardinalSplineTo")
    .constructor<>()
    .function("getPoints", &CardinalSplineTo::getPoints, allow_raw_pointers())
    .function("updatePosition", &CardinalSplineTo::updatePosition, allow_raw_pointers())
    .property("_className",  optional_override([](const CardinalSplineTo& _) -> std::string {return "CardinalSplineTo";}))    
    ;


  class_<CardinalSplineBy, base<CardinalSplineTo>>("cc.CardinalSplineBy")
    .constructor<>()
    .property("_className",  optional_override([](const CardinalSplineBy& _) -> std::string {return "CardinalSplineBy";}))    
    ;

  class_<CatmullRomTo, base<CardinalSplineTo>>("cc.CatmullRomTo")
    .property("_className",  optional_override([](const CatmullRomTo& _) -> std::string {return "CatmullRomTo";}))    
    ;

  class_<CatmullRomBy, base<CardinalSplineBy>>("cc.CatmullRomBy")
    .property("_className",  optional_override([](const CatmullRomBy& _) -> std::string {return "CatmullRomBy";}))    
    ;

  class_<ActionEase, base<ActionInterval>>("cc.ActionEase")
    .function("initWithAction", &ActionEase::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &ActionEase::getInnerAction, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionEase& _) -> std::string {return "ActionEase";}))    
    ;

  class_<EaseRateAction, base<ActionEase>>("cc.EaseRateAction")
    .function("setRate", &EaseRateAction::setRate, allow_raw_pointers())
    .function("initWithAction", &EaseRateAction::initWithAction, allow_raw_pointers())
    .function("getRate", &EaseRateAction::getRate, allow_raw_pointers())
    .class_function("create", &EaseRateAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseRateAction& _) -> std::string {return "EaseRateAction";}))    
    ;


  class_<EaseExponentialIn, base<ActionEase>>("cc.EaseExponentialIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialIn>, allow_raw_pointers())
    .class_function("create", &EaseExponentialIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialIn& _) -> std::string {return "EaseExponentialIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialIn.extend
    ;


  class_<EaseExponentialOut, base<ActionEase>>("cc.EaseExponentialOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialOut& _) -> std::string {return "EaseExponentialOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialOut.extend
    ;


  class_<EaseExponentialInOut, base<ActionEase>>("cc.EaseExponentialInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialInOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialInOut& _) -> std::string {return "EaseExponentialInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialInOut.extend
    ;


  class_<EaseSineIn, base<ActionEase>>("cc.EaseSineIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineIn>, allow_raw_pointers())
    .class_function("create", &EaseSineIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineIn& _) -> std::string {return "EaseSineIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineIn.extend
    ;


  class_<EaseSineOut, base<ActionEase>>("cc.EaseSineOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineOut>, allow_raw_pointers())
    .class_function("create", &EaseSineOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineOut& _) -> std::string {return "EaseSineOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineOut.extend
    ;


  class_<EaseSineInOut, base<ActionEase>>("cc.EaseSineInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineInOut>, allow_raw_pointers())
    .class_function("create", &EaseSineInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineInOut& _) -> std::string {return "EaseSineInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineInOut.extend
    ;

  class_<EaseBounce, base<ActionEase>>("cc.EaseBounce")
    .property("_className",  optional_override([](const EaseBounce& _) -> std::string {return "EaseBounce";}))    
    ;


  class_<EaseBounceIn, base<ActionEase>>("cc.EaseBounceIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceIn>, allow_raw_pointers())
    .class_function("create", &EaseBounceIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceIn& _) -> std::string {return "EaseBounceIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceIn.extend
    ;


  class_<EaseBounceOut, base<ActionEase>>("cc.EaseBounceOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceOut& _) -> std::string {return "EaseBounceOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceOut.extend
    ;


  class_<EaseBounceInOut, base<ActionEase>>("cc.EaseBounceInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceInOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceInOut& _) -> std::string {return "EaseBounceInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceInOut.extend
    ;


  class_<EaseBackIn, base<ActionEase>>("cc.EaseBackIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackIn>, allow_raw_pointers())
    .class_function("create", &EaseBackIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackIn& _) -> std::string {return "EaseBackIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackIn.extend
    ;


  class_<EaseBackOut, base<ActionEase>>("cc.EaseBackOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackOut>, allow_raw_pointers())
    .class_function("create", &EaseBackOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackOut& _) -> std::string {return "EaseBackOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackOut.extend
    ;


  class_<EaseBackInOut, base<ActionEase>>("cc.EaseBackInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackInOut>, allow_raw_pointers())
    .class_function("create", &EaseBackInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackInOut& _) -> std::string {return "EaseBackInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackInOut.extend
    ;


  class_<EaseQuadraticActionIn, base<ActionEase>>("cc.EaseQuadraticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionIn& _) -> std::string {return "EaseQuadraticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionIn.extend
    ;


  class_<EaseQuadraticActionOut, base<ActionEase>>("cc.EaseQuadraticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionOut& _) -> std::string {return "EaseQuadraticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionOut.extend
    ;


  class_<EaseQuadraticActionInOut, base<ActionEase>>("cc.EaseQuadraticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionInOut& _) -> std::string {return "EaseQuadraticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionInOut.extend
    ;


  class_<EaseQuarticActionIn, base<ActionEase>>("cc.EaseQuarticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionIn& _) -> std::string {return "EaseQuarticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionIn.extend
    ;


  class_<EaseQuarticActionOut, base<ActionEase>>("cc.EaseQuarticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionOut& _) -> std::string {return "EaseQuarticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionOut.extend
    ;


  class_<EaseQuarticActionInOut, base<ActionEase>>("cc.EaseQuarticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionInOut& _) -> std::string {return "EaseQuarticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionInOut.extend
    ;


  class_<EaseQuinticActionIn, base<ActionEase>>("cc.EaseQuinticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionIn& _) -> std::string {return "EaseQuinticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionIn.extend
    ;


  class_<EaseQuinticActionOut, base<ActionEase>>("cc.EaseQuinticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionOut& _) -> std::string {return "EaseQuinticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionOut.extend
    ;


  class_<EaseQuinticActionInOut, base<ActionEase>>("cc.EaseQuinticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionInOut& _) -> std::string {return "EaseQuinticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionInOut.extend
    ;


  class_<EaseCircleActionIn, base<ActionEase>>("cc.EaseCircleActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionIn& _) -> std::string {return "EaseCircleActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionIn.extend
    ;


  class_<EaseCircleActionOut, base<ActionEase>>("cc.EaseCircleActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionOut& _) -> std::string {return "EaseCircleActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionOut.extend
    ;


  class_<EaseCircleActionInOut, base<ActionEase>>("cc.EaseCircleActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionInOut& _) -> std::string {return "EaseCircleActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionInOut.extend
    ;


  class_<EaseCubicActionIn, base<ActionEase>>("cc.EaseCubicActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionIn& _) -> std::string {return "EaseCubicActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionIn.extend
    ;


  class_<EaseCubicActionOut, base<ActionEase>>("cc.EaseCubicActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionOut& _) -> std::string {return "EaseCubicActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionOut.extend
    ;


  class_<EaseCubicActionInOut, base<ActionEase>>("cc.EaseCubicActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionInOut& _) -> std::string {return "EaseCubicActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionInOut.extend
    ;


  class_<EaseIn, base<EaseRateAction>>("cc.EaseIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseIn>, allow_raw_pointers())
    .class_function("create", &EaseIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseIn& _) -> std::string {return "EaseIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseIn.extend
    ;


  class_<EaseOut, base<EaseRateAction>>("cc.EaseOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseOut>, allow_raw_pointers())
    .class_function("create", &EaseOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseOut& _) -> std::string {return "EaseOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseOut.extend
    ;


  class_<EaseInOut, base<EaseRateAction>>("cc.EaseInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseInOut>, allow_raw_pointers())
    .class_function("create", &EaseInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseInOut& _) -> std::string {return "EaseInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseInOut.extend
    ;

  class_<EaseElastic, base<ActionEase>>("cc.EaseElastic")
    .function("setPeriod", &EaseElastic::setPeriod, allow_raw_pointers())
    .function("initWithAction", &EaseElastic::initWithAction, allow_raw_pointers())
    .function("initWithAction", optional_override(
        [](EaseElastic& this_, cocos2d::ActionInterval* arg0){
        return this_.initWithAction(arg0);
      }), allow_raw_pointers())
    .function("getPeriod", &EaseElastic::getPeriod, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElastic& _) -> std::string {return "EaseElastic";}))    
    ;


  class_<EaseElasticIn, base<EaseElastic>>("cc.EaseElasticIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticIn>, allow_raw_pointers())
    .class_function("create", &EaseElasticIn::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticIn::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticIn& _) -> std::string {return "EaseElasticIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticIn.extend
    ;


  class_<EaseElasticOut, base<EaseElastic>>("cc.EaseElasticOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticOut& _) -> std::string {return "EaseElasticOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticOut.extend
    ;


  class_<EaseElasticInOut, base<EaseElastic>>("cc.EaseElasticInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticInOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticInOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticInOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticInOut& _) -> std::string {return "EaseElasticInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticInOut.extend
    ;


  class_<EaseBezierAction, base<ActionEase>>("cc.EaseBezierAction")
    .constructor<>()
    .function("setBezierParamer", &EaseBezierAction::setBezierParamer, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<EaseBezierAction>, allow_raw_pointers())
    .class_function("create", &EaseBezierAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBezierAction& _) -> std::string {return "EaseBezierAction";}))    
    // TODO: assign cc.Class.extend to cc.EaseBezierAction.extend
    ;

  class_<ActionInstant, base<FiniteTimeAction>>("cc.ActionInstant")
    .property("_className",  optional_override([](const ActionInstant& _) -> std::string {return "ActionInstant";}))    
    ;


  class_<Show, base<ActionInstant>>("cc.Show")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Show>, allow_raw_pointers())
    .class_function("create", &Show::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Show& _) -> std::string {return "Show";}))    
    // TODO: assign cc.Class.extend to cc.Show.extend
    ;


  class_<Hide, base<ActionInstant>>("cc.Hide")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Hide>, allow_raw_pointers())
    .class_function("create", &Hide::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Hide& _) -> std::string {return "Hide";}))    
    // TODO: assign cc.Class.extend to cc.Hide.extend
    ;


  class_<ToggleVisibility, base<ActionInstant>>("cc.ToggleVisibility")
    .constructor<>()
    .class_function("create", &ToggleVisibility::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ToggleVisibility& _) -> std::string {return "ToggleVisibility";}))    
    ;


  class_<RemoveSelf, base<ActionInstant>>("cc.RemoveSelf")
    .constructor<>()
    .function("init", &RemoveSelf::init, allow_raw_pointers())
    .class_function("create", &RemoveSelf::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return RemoveSelf::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RemoveSelf& _) -> std::string {return "RemoveSelf";}))    
    ;


  class_<FlipX, base<ActionInstant>>("cc.FlipX")
    .constructor<>()
    .function("initWithFlipX", &FlipX::initWithFlipX, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FlipX>, allow_raw_pointers())
    .class_function("create", &FlipX::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX& _) -> std::string {return "FlipX";}))    
    // TODO: assign cc.Class.extend to cc.FlipX.extend
    ;


  class_<FlipY, base<ActionInstant>>("cc.FlipY")
    .constructor<>()
    .function("initWithFlipY", &FlipY::initWithFlipY, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FlipY>, allow_raw_pointers())
    .class_function("create", &FlipY::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY& _) -> std::string {return "FlipY";}))    
    // TODO: assign cc.Class.extend to cc.FlipY.extend
    ;


  class_<Place, base<ActionInstant>>("cc.Place")
    .constructor<>()
    .function("initWithPosition", &Place::initWithPosition, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Place>, allow_raw_pointers())
    .class_function("create", &Place::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Place& _) -> std::string {return "Place";}))    
    // TODO: assign cc.Class.extend to cc.Place.extend
    ;


  class_<CallFunc, base<ActionInstant>>("cc._CallFunc")
    .constructor<>()
    .function("execute", &CallFunc::execute, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<CallFunc>, allow_raw_pointers())
    .property("_className",  optional_override([](const CallFunc& _) -> std::string {return "CallFunc";}))    
    // TODO: assign cc.Class.extend to cc._CallFunc.extend
    ;


  class_<CallFuncN, base<CallFunc>>("cc.CallFunc")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<CallFuncN>, allow_raw_pointers())
    .property("_className",  optional_override([](const CallFuncN& _) -> std::string {return "CallFuncN";}))    
    // TODO: assign cc.Class.extend to cc.CallFunc.extend
    ;

  class_<GridAction, base<ActionInterval>>("cc.GridAction")
    .function("getGrid", &GridAction::getGrid, allow_raw_pointers())
    .function("initWithDuration", &GridAction::initWithDuration, allow_raw_pointers())
    .property("_className",  optional_override([](const GridAction& _) -> std::string {return "GridAction";}))    
    ;

  class_<Grid3DAction, base<GridAction>>("cc.Grid3DAction")
    .function("getGridRect", &Grid3DAction::getGridRect, allow_raw_pointers())
    .property("_className",  optional_override([](const Grid3DAction& _) -> std::string {return "Grid3DAction";}))    
    ;

  class_<TiledGrid3DAction, base<GridAction>>("cc.TiledGrid3DAction")
    .property("_className",  optional_override([](const TiledGrid3DAction& _) -> std::string {return "TiledGrid3DAction";}))    
    ;


  class_<StopGrid, base<ActionInstant>>("cc.StopGrid")
    .constructor<>()
    .class_function("create", &StopGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const StopGrid& _) -> std::string {return "StopGrid";}))    
    ;


  class_<ReuseGrid, base<ActionInstant>>("cc.ReuseGrid")
    .constructor<>()
    .function("initWithTimes", &ReuseGrid::initWithTimes, allow_raw_pointers())
    .class_function("create", &ReuseGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReuseGrid& _) -> std::string {return "ReuseGrid";}))    
    ;


  class_<Waves3D, base<Grid3DAction>>("cc.Waves3D")
    .constructor<>()
    .function("setAmplitudeRate", &Waves3D::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &Waves3D::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &Waves3D::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &Waves3D::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &Waves3D::getAmplitude, allow_raw_pointers())
    .class_function("create", &Waves3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves3D& _) -> std::string {return "Waves3D";}))    
    ;


  class_<FlipX3D, base<Grid3DAction>>("cc.FlipX3D")
    .constructor<>()
    .function("initWithSize", &FlipX3D::initWithSize, allow_raw_pointers())
    .function("initWithDuration", &FlipX3D::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FlipX3D>, allow_raw_pointers())
    .class_function("create", &FlipX3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX3D& _) -> std::string {return "FlipX3D";}))    
    // TODO: assign cc.Class.extend to cc.FlipX3D.extend
    ;


  class_<FlipY3D, base<FlipX3D>>("cc.FlipY3D")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FlipY3D>, allow_raw_pointers())
    .class_function("create", &FlipY3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY3D& _) -> std::string {return "FlipY3D";}))    
    // TODO: assign cc.Class.extend to cc.FlipY3D.extend
    ;


  class_<Lens3D, base<Grid3DAction>>("cc.Lens3D")
    .constructor<>()
    .function("setConcave", &Lens3D::setConcave, allow_raw_pointers())
    .function("initWithDuration", &Lens3D::initWithDuration, allow_raw_pointers())
    .function("setLensEffect", &Lens3D::setLensEffect, allow_raw_pointers())
    .function("getLensEffect", &Lens3D::getLensEffect, allow_raw_pointers())
    .function("setPosition", &Lens3D::setPosition, allow_raw_pointers())
    .function("getPosition", &Lens3D::getPosition, allow_raw_pointers())
    .class_function("create", &Lens3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Lens3D& _) -> std::string {return "Lens3D";}))    
    ;


  class_<Ripple3D, base<Grid3DAction>>("cc.Ripple3D")
    .constructor<>()
    .function("setAmplitudeRate", &Ripple3D::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &Ripple3D::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &Ripple3D::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &Ripple3D::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &Ripple3D::getAmplitude, allow_raw_pointers())
    .function("setPosition", &Ripple3D::setPosition, allow_raw_pointers())
    .function("getPosition", &Ripple3D::getPosition, allow_raw_pointers())
    .class_function("create", &Ripple3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Ripple3D& _) -> std::string {return "Ripple3D";}))    
    ;


  class_<Shaky3D, base<Grid3DAction>>("cc.Shaky3D")
    .constructor<>()
    .function("initWithDuration", &Shaky3D::initWithDuration, allow_raw_pointers())
    .class_function("create", &Shaky3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Shaky3D& _) -> std::string {return "Shaky3D";}))    
    ;


  class_<Liquid, base<Grid3DAction>>("cc.Liquid")
    .constructor<>()
    .function("setAmplitudeRate", &Liquid::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &Liquid::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &Liquid::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &Liquid::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &Liquid::getAmplitude, allow_raw_pointers())
    .class_function("create", &Liquid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Liquid& _) -> std::string {return "Liquid";}))    
    ;


  class_<Waves, base<Grid3DAction>>("cc.Waves")
    .constructor<>()
    .function("setAmplitudeRate", &Waves::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &Waves::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &Waves::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &Waves::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &Waves::getAmplitude, allow_raw_pointers())
    .class_function("create", &Waves::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves& _) -> std::string {return "Waves";}))    
    ;


  class_<Twirl, base<Grid3DAction>>("cc.Twirl")
    .constructor<>()
    .function("setAmplitudeRate", &Twirl::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &Twirl::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &Twirl::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &Twirl::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &Twirl::getAmplitude, allow_raw_pointers())
    .function("setPosition", &Twirl::setPosition, allow_raw_pointers())
    .function("getPosition", &Twirl::getPosition, allow_raw_pointers())
    .class_function("create", &Twirl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Twirl& _) -> std::string {return "Twirl";}))    
    ;


  class_<ActionManager>("cc.ActionManager")
    .constructor<>()
    .function("getActionByTag", &ActionManager::getActionByTag, allow_raw_pointers())
    .function("removeActionByTag", &ActionManager::removeActionByTag, allow_raw_pointers())
    .function("removeActionsByFlags", &ActionManager::removeActionsByFlags, allow_raw_pointers())
    .function("removeAllActions", &ActionManager::removeAllActions, allow_raw_pointers())
    .function("addAction", &ActionManager::addAction, allow_raw_pointers())
    .function("resumeTarget", &ActionManager::resumeTarget, allow_raw_pointers())
    .function("getNumberOfRunningActions", &ActionManager::getNumberOfRunningActions, allow_raw_pointers())
    .function("pauseTarget", &ActionManager::pauseTarget, allow_raw_pointers())
    .function("getNumberOfRunningActionsInTarget", &ActionManager::getNumberOfRunningActionsInTarget, allow_raw_pointers())
    .function("removeAllActionsFromTarget", &ActionManager::removeAllActionsFromTarget, allow_raw_pointers())
    .function("resumeTargets", &ActionManager::resumeTargets, allow_raw_pointers())
    .function("removeAction", &ActionManager::removeAction, allow_raw_pointers())
    .function("pauseAllRunningActions", &ActionManager::pauseAllRunningActions, allow_raw_pointers())
    .function("update", &ActionManager::update, allow_raw_pointers())
    .function("removeAllActionsByTag", &ActionManager::removeAllActionsByTag, allow_raw_pointers())
    .function("getNumberOfRunningActionsInTargetByTag", &ActionManager::getNumberOfRunningActionsInTargetByTag, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ActionManager>, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionManager& _) -> std::string {return "ActionManager";}))    
    // TODO: assign cc.Class.extend to cc.ActionManager.extend
    ;

  class_<PageTurn3D, base<Grid3DAction>>("cc.PageTurn3D")
    .class_function("create", &PageTurn3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageTurn3D& _) -> std::string {return "PageTurn3D";}))    
    ;


  class_<ProgressTo, base<ActionInterval>>("cc.ProgressTo")
    .constructor<>()
    .function("initWithDuration", &ProgressTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ProgressTo>, allow_raw_pointers())
    .class_function("create", &ProgressTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTo& _) -> std::string {return "ProgressTo";}))    
    // TODO: assign cc.Class.extend to cc.ProgressTo.extend
    ;


  class_<ProgressFromTo, base<ActionInterval>>("cc.ProgressFromTo")
    .constructor<>()
    .function("initWithDuration", &ProgressFromTo::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ProgressFromTo>, allow_raw_pointers())
    .class_function("create", &ProgressFromTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressFromTo& _) -> std::string {return "ProgressFromTo";}))    
    // TODO: assign cc.Class.extend to cc.ProgressFromTo.extend
    ;


  class_<ShakyTiles3D, base<TiledGrid3DAction>>("cc.ShakyTiles3D")
    .constructor<>()
    .function("initWithDuration", &ShakyTiles3D::initWithDuration, allow_raw_pointers())
    .class_function("create", &ShakyTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShakyTiles3D& _) -> std::string {return "ShakyTiles3D";}))    
    ;


  class_<ShatteredTiles3D, base<TiledGrid3DAction>>("cc.ShatteredTiles3D")
    .constructor<>()
    .function("initWithDuration", &ShatteredTiles3D::initWithDuration, allow_raw_pointers())
    .class_function("create", &ShatteredTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShatteredTiles3D& _) -> std::string {return "ShatteredTiles3D";}))    
    ;


  class_<ShuffleTiles, base<TiledGrid3DAction>>("cc.ShuffleTiles")
    .constructor<>()
    .function("placeTile", &ShuffleTiles::placeTile, allow_raw_pointers())
    .function("initWithDuration", &ShuffleTiles::initWithDuration, allow_raw_pointers())
    .function("getDelta", &ShuffleTiles::getDelta, allow_raw_pointers())
    .function("shuffle", &ShuffleTiles::shuffle, allow_raw_pointers())
    .class_function("create", &ShuffleTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShuffleTiles& _) -> std::string {return "ShuffleTiles";}))    
    ;


  class_<FadeOutTRTiles, base<TiledGrid3DAction>>("cc.FadeOutTRTiles")
    .constructor<>()
    .function("turnOnTile", &FadeOutTRTiles::turnOnTile, allow_raw_pointers())
    .function("turnOffTile", &FadeOutTRTiles::turnOffTile, allow_raw_pointers())
    .function("transformTile", &FadeOutTRTiles::transformTile, allow_raw_pointers())
    .function("testFunc", &FadeOutTRTiles::testFunc, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeOutTRTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutTRTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutTRTiles& _) -> std::string {return "FadeOutTRTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutTRTiles.extend
    ;


  class_<FadeOutBLTiles, base<FadeOutTRTiles>>("cc.FadeOutBLTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutBLTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutBLTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutBLTiles& _) -> std::string {return "FadeOutBLTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutBLTiles.extend
    ;


  class_<FadeOutUpTiles, base<FadeOutTRTiles>>("cc.FadeOutUpTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutUpTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutUpTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutUpTiles& _) -> std::string {return "FadeOutUpTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutUpTiles.extend
    ;


  class_<FadeOutDownTiles, base<FadeOutUpTiles>>("cc.FadeOutDownTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutDownTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutDownTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutDownTiles& _) -> std::string {return "FadeOutDownTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutDownTiles.extend
    ;


  class_<TurnOffTiles, base<TiledGrid3DAction>>("cc.TurnOffTiles")
    .constructor<>()
    .function("turnOnTile", &TurnOffTiles::turnOnTile, allow_raw_pointers())
    .function("turnOffTile", &TurnOffTiles::turnOffTile, allow_raw_pointers())
    .function("shuffle", &TurnOffTiles::shuffle, allow_raw_pointers())
    .function("initWithDuration", &TurnOffTiles::initWithDuration, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TurnOffTiles*(float, const cocos2d::Size&, unsigned int)>(&TurnOffTiles::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TurnOffTiles*(float, const cocos2d::Size&)>(&TurnOffTiles::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TurnOffTiles& _) -> std::string {return "TurnOffTiles";}))    
    ;


  class_<WavesTiles3D, base<TiledGrid3DAction>>("cc.WavesTiles3D")
    .constructor<>()
    .function("setAmplitudeRate", &WavesTiles3D::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &WavesTiles3D::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &WavesTiles3D::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &WavesTiles3D::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &WavesTiles3D::getAmplitude, allow_raw_pointers())
    .class_function("create", &WavesTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const WavesTiles3D& _) -> std::string {return "WavesTiles3D";}))    
    ;


  class_<JumpTiles3D, base<TiledGrid3DAction>>("cc.JumpTiles3D")
    .constructor<>()
    .function("setAmplitudeRate", &JumpTiles3D::setAmplitudeRate, allow_raw_pointers())
    .function("initWithDuration", &JumpTiles3D::initWithDuration, allow_raw_pointers())
    .function("getAmplitudeRate", &JumpTiles3D::getAmplitudeRate, allow_raw_pointers())
    .function("setAmplitude", &JumpTiles3D::setAmplitude, allow_raw_pointers())
    .function("getAmplitude", &JumpTiles3D::getAmplitude, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<JumpTiles3D>, allow_raw_pointers())
    .class_function("create", &JumpTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTiles3D& _) -> std::string {return "JumpTiles3D";}))    
    // TODO: assign cc.Class.extend to cc.JumpTiles3D.extend
    ;


  class_<SplitRows, base<TiledGrid3DAction>>("cc.SplitRows")
    .constructor<>()
    .function("initWithDuration", &SplitRows::initWithDuration, allow_raw_pointers())
    .class_function("create", &SplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitRows& _) -> std::string {return "SplitRows";}))    
    ;


  class_<SplitCols, base<TiledGrid3DAction>>("cc.SplitCols")
    .constructor<>()
    .function("initWithDuration", &SplitCols::initWithDuration, allow_raw_pointers())
    .class_function("create", &SplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitCols& _) -> std::string {return "SplitCols";}))    
    ;

  class_<ActionTween, base<ActionInterval>>("cc.ActionTween")
    .function("initWithDuration", &ActionTween::initWithDuration, allow_raw_pointers())
    .class_function("create", &ActionTween::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTween& _) -> std::string {return "ActionTween";}))    
    // TODO: assign cc.Class.extend to cc.ActionTween.extend
    ;


  class_<AtlasNode, base<Node>>("cc.AtlasNode")
    .constructor<>()
    .function("updateAtlasValues", &AtlasNode::updateAtlasValues, allow_raw_pointers())
    .function("setTextureAtlas", &AtlasNode::setTextureAtlas, allow_raw_pointers())
    .function("getTextureAtlas", &AtlasNode::getTextureAtlas, allow_raw_pointers())
    .function("getQuadsToDraw", &AtlasNode::getQuadsToDraw, allow_raw_pointers())
    .function("initWithTileFile", &AtlasNode::initWithTileFile, allow_raw_pointers())
    .function("initWithTexture", &AtlasNode::initWithTexture, allow_raw_pointers())
    .function("setQuadsToDraw", &AtlasNode::setQuadsToDraw, allow_raw_pointers())
    .class_function("create", &AtlasNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AtlasNode& _) -> std::string {return "AtlasNode";}))    
    ;


  class_<ClippingNode, base<Node>>("cc.ClippingNode")
    .constructor<>()
    .function("hasContent", &ClippingNode::hasContent, allow_raw_pointers())
    .function("setInverted", &ClippingNode::setInverted, allow_raw_pointers())
    .function("setStencil", &ClippingNode::setStencil, allow_raw_pointers())
    .function("getAlphaThreshold", &ClippingNode::getAlphaThreshold, allow_raw_pointers())
    .function("getStencil", &ClippingNode::getStencil, allow_raw_pointers())
    .function("setAlphaThreshold", &ClippingNode::setAlphaThreshold, allow_raw_pointers())
    .function("isInverted", &ClippingNode::isInverted, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ClippingNode*(cocos2d::Node*)>(&ClippingNode::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ClippingNode*()>(&ClippingNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ClippingNode& _) -> std::string {return "ClippingNode";}))    
    ;


  class_<DrawNode, base<Node>>("cc.DrawNode")
    .constructor<float>()
    .function("drawLine", &DrawNode::drawLine, allow_raw_pointers())
    .function("drawPoints", select_overload<void(const cocos2d::Vec2*, unsigned int, const float, const cocos2d::Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("drawPoints", select_overload<void(const cocos2d::Vec2*, unsigned int, const cocos2d::Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("setIsolated", &DrawNode::setIsolated, allow_raw_pointers())
    .function("drawRect", select_overload<void(const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Color4F&)>(&DrawNode::drawRect), allow_raw_pointers())
    .function("drawRect", select_overload<void(const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Color4F&)>(&DrawNode::drawRect), allow_raw_pointers())
    .function("drawSolidCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, const cocos2d::Color4F&)>(&DrawNode::drawSolidCircle), allow_raw_pointers())
    .function("drawSolidCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, float, float, const cocos2d::Color4F&)>(&DrawNode::drawSolidCircle), allow_raw_pointers())
    .function("setLineWidth", &DrawNode::setLineWidth, allow_raw_pointers())
    .function("onDrawGLPoint", &DrawNode::onDrawGLPoint, allow_raw_pointers())
    .function("drawPolygon", &DrawNode::drawPolygon, allow_raw_pointers())
    .function("drawDot", &DrawNode::drawDot, allow_raw_pointers())
    .function("drawCatmullRom", &DrawNode::drawCatmullRom, allow_raw_pointers())
    .function("drawSegment", &DrawNode::drawSegment, allow_raw_pointers())
    .function("getBlendFunc", &DrawNode::getBlendFunc, allow_raw_pointers())
    .function("onDraw", &DrawNode::onDraw, allow_raw_pointers())
    .function("drawCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, bool, const cocos2d::Color4F&)>(&DrawNode::drawCircle), allow_raw_pointers())
    .function("drawCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, bool, float, float, const cocos2d::Color4F&)>(&DrawNode::drawCircle), allow_raw_pointers())
    .function("drawQuadBezier", select_overload<void(const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Vec2&, unsigned int, const cocos2d::Color4F&)>(&DrawNode::drawQuadBezier), allow_raw_pointers())
    .function("onDrawGLLine", &DrawNode::onDrawGLLine, allow_raw_pointers())
    .function("drawSolidPoly", &DrawNode::drawSolidPoly, allow_raw_pointers())
    .function("drawTriangle", &DrawNode::drawTriangle, allow_raw_pointers())
    .function("setBlendFunc", &DrawNode::setBlendFunc, allow_raw_pointers())
    .function("clear", &DrawNode::clear, allow_raw_pointers())
    .function("drawCardinalSpline", &DrawNode::drawCardinalSpline, allow_raw_pointers())
    .function("drawSolidRect", &DrawNode::drawSolidRect, allow_raw_pointers())
    .function("getLineWidth", &DrawNode::getLineWidth, allow_raw_pointers())
    .function("drawPoint", &DrawNode::drawPoint, allow_raw_pointers())
    .function("isIsolated", &DrawNode::isIsolated, allow_raw_pointers())
    .function("drawCubicBezier", &DrawNode::drawCubicBezier, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<DrawNode>, allow_raw_pointers())
    .class_function("create", &DrawNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return DrawNode::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const DrawNode& _) -> std::string {return "DrawNode";}))    
    // TODO: assign cc.Class.extend to cc.DrawNode.extend
    ;


  class_<Label, base<Node>>("cc.Label")
    .constructor<cocos2d::TextHAlignment, cocos2d::TextVAlignment>()
    .function("isClipMarginEnabled", &Label::isClipMarginEnabled, allow_raw_pointers())
    .function("enableShadow", &Label::enableShadow, allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Label& this_){
        return this_.enableShadow();
      }), allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0){
        return this_.enableShadow(arg0);
      }), allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0, const cocos2d::Size& arg1){
        return this_.enableShadow(arg0, arg1);
      }), allow_raw_pointers())
    .function("setDimensions", &Label::setDimensions, allow_raw_pointers())
    .function("getWidth", &Label::getWidth, allow_raw_pointers())
    .function("getHeight", &Label::getHeight, allow_raw_pointers())
    .function("disableEffect", select_overload<void(cocos2d::LabelEffect)>(&Label::disableEffect), allow_raw_pointers())
    .function("disableEffect", select_overload<void()>(&Label::disableEffect), allow_raw_pointers())
    .function("getLabelType", &Label::getLabelType, allow_raw_pointers())
    .function("getTextColor", &Label::getTextColor, allow_raw_pointers())
    .function("enableWrap", &Label::enableWrap, allow_raw_pointers())
    .function("setWidth", &Label::setWidth, allow_raw_pointers())
    .function("getAdditionalKerning", &Label::getAdditionalKerning, allow_raw_pointers())
    .function("getBMFontSize", &Label::getBMFontSize, allow_raw_pointers())
    .function("getMaxLineWidth", &Label::getMaxLineWidth, allow_raw_pointers())
    .function("getHorizontalAlignment", &Label::getHorizontalAlignment, allow_raw_pointers())
    .function("getShadowOffset", &Label::getShadowOffset, allow_raw_pointers())
    .function("getLineSpacing", &Label::getLineSpacing, allow_raw_pointers())
    .function("setClipMarginEnabled", &Label::setClipMarginEnabled, allow_raw_pointers())
    .function("setSystemFontName", &Label::setSystemFontName, allow_raw_pointers())
    .function("isWrapEnabled", &Label::isWrapEnabled, allow_raw_pointers())
    .function("getOutlineSize", &Label::getOutlineSize, allow_raw_pointers())
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const cocos2d::Rect&, bool, float)>(&Label::setBMFontFilePath), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, float)>(&Label::setBMFontFilePath), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const std::string&, float)>(&Label::setBMFontFilePath), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const cocos2d::_ttfConfig&, const std::string&, cocos2d::TextHAlignment, int)>(&Label::initWithTTF), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const std::string&, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Label::initWithTTF), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setLineHeight", &Label::setLineHeight, allow_raw_pointers())
    .function("setSystemFontSize", &Label::setSystemFontSize, allow_raw_pointers())
    .function("setOverflow", &Label::setOverflow, allow_raw_pointers())
    .function("enableStrikethrough", &Label::enableStrikethrough, allow_raw_pointers())
    .function("updateContent", &Label::updateContent, allow_raw_pointers())
    .function("getStringLength", &Label::getStringLength, allow_raw_pointers())
    .function("setLineBreakWithoutSpace", &Label::setLineBreakWithoutSpace, allow_raw_pointers())
    .function("getStringNumLines", &Label::getStringNumLines, allow_raw_pointers())
    .function("enableOutline", &Label::enableOutline, allow_raw_pointers())
    .function("enableOutline", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0){
        return this_.enableOutline(arg0);
      }), allow_raw_pointers())
    .function("getShadowBlurRadius", &Label::getShadowBlurRadius, allow_raw_pointers())
    .function("getEffectColor", &Label::getEffectColor, allow_raw_pointers())
    .function("setCharMap", select_overload<bool(cocos2d::Texture2D*, int, int, int)>(&Label::setCharMap), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setCharMap", select_overload<bool(const std::string&)>(&Label::setCharMap), allow_raw_pointers())
    .function("getDimensions", &Label::getDimensions, allow_raw_pointers())
    .function("setMaxLineWidth", &Label::setMaxLineWidth, allow_raw_pointers())
    .function("getSystemFontName", &Label::getSystemFontName, allow_raw_pointers())
    .function("setVerticalAlignment", &Label::setVerticalAlignment, allow_raw_pointers())
    .function("setLineSpacing", &Label::setLineSpacing, allow_raw_pointers())
    .function("getRenderingFontSize", &Label::getRenderingFontSize, allow_raw_pointers())
    .function("getLineHeight", &Label::getLineHeight, allow_raw_pointers())
    .function("getShadowColor", &Label::getShadowColor, allow_raw_pointers())
    .function("getTTFConfig", &Label::getTTFConfig, allow_raw_pointers())
    .function("enableItalics", &Label::enableItalics, allow_raw_pointers())
    .function("setTextColor", &Label::setTextColor, allow_raw_pointers())
    .function("getLetter", &Label::getLetter, allow_raw_pointers())
    .function("setHeight", &Label::setHeight, allow_raw_pointers())
    .function("isShadowEnabled", &Label::isShadowEnabled, allow_raw_pointers())
    .function("enableGlow", &Label::enableGlow, allow_raw_pointers())
    .function("getOverflow", &Label::getOverflow, allow_raw_pointers())
    .function("getVerticalAlignment", &Label::getVerticalAlignment, allow_raw_pointers())
    .function("setAdditionalKerning", &Label::setAdditionalKerning, allow_raw_pointers())
    .function("getSystemFontSize", &Label::getSystemFontSize, allow_raw_pointers())
    .function("getTextAlignment", &Label::getTextAlignment, allow_raw_pointers())
    .function("getBMFontFilePath", &Label::getBMFontFilePath, allow_raw_pointers())
    .function("setHorizontalAlignment", &Label::setHorizontalAlignment, allow_raw_pointers())
    .function("enableBold", &Label::enableBold, allow_raw_pointers())
    .function("enableUnderline", &Label::enableUnderline, allow_raw_pointers())
    .function("getLabelEffectType", &Label::getLabelEffectType, allow_raw_pointers())
    .function("setAlignment", select_overload<void(cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Label::setAlignment), allow_raw_pointers())
    .function("setAlignment", select_overload<void(cocos2d::TextHAlignment)>(&Label::setAlignment), allow_raw_pointers())
    .function("requestSystemFontRefresh", &Label::requestSystemFontRefresh, allow_raw_pointers())
    .function("setBMFontSize", &Label::setBMFontSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Label>, allow_raw_pointers())
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int, const cocos2d::Rect&, bool)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int)>(&Label::createWithBMFont), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int, const std::string&)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Label*()>(&Label::create), allow_raw_pointers())
    .class_function("createWithCharMap", select_overload<cocos2d::Label*(cocos2d::Texture2D*, int, int, int)>(&Label::createWithCharMap), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithCharMap", select_overload<cocos2d::Label*(const std::string&)>(&Label::createWithCharMap), allow_raw_pointers())
    .class_function("createWithSystemFont", &Label::createWithSystemFont, allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2){
        return Label::createWithSystemFont(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3, cocos2d::TextHAlignment arg4){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Label& _) -> std::string {return "Label";}))    
    // TODO: assign cc.Class.extend to cc.Label.extend
    ;


  class_<LabelAtlas, base<AtlasNode>>("cc.LabelAtlas")
    .constructor<>()
    .function("initWithString", select_overload<bool(const std::string&, const std::string&)>(&LabelAtlas::initWithString), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::initWithString), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<LabelAtlas>, allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*()>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*(const std::string&, const std::string&)>(&LabelAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LabelAtlas& _) -> std::string {return "LabelAtlas";}))    
    // TODO: assign cc.Class.extend to cc.LabelAtlas.extend
    ;


  class_<LabelBMFont, base<Node>>("cc.LabelBMFont")
    .constructor<>()
    .function("setLineBreakWithoutSpace", &LabelBMFont::setLineBreakWithoutSpace, allow_raw_pointers())
    .function("getLetter", &LabelBMFont::getLetter, allow_raw_pointers())
    .function("initWithString", &LabelBMFont::initWithString, allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1){
        return this_.initWithString(arg0, arg1);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1, float arg2){
        return this_.initWithString(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1, float arg2, cocos2d::TextHAlignment arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("getFntFile", &LabelBMFont::getFntFile, allow_raw_pointers())
    .function("setFntFile", select_overload<void(const std::string&, const cocos2d::Rect&, bool)>(&LabelBMFont::setFntFile), allow_raw_pointers())
    .function("setFntFile", select_overload<void(const std::string&, const cocos2d::Vec2&)>(&LabelBMFont::setFntFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setAlignment", &LabelBMFont::setAlignment, allow_raw_pointers())
    .function("setWidth", &LabelBMFont::setWidth, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LabelBMFont>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelBMFont*()>(&LabelBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelBMFont*(const std::string&, const std::string&, float, cocos2d::TextHAlignment, const cocos2d::Vec2&)>(&LabelBMFont::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LabelBMFont& _) -> std::string {return "LabelBMFont";}))    
    // TODO: assign cc.Class.extend to cc.LabelBMFont.extend
    ;


  class_<LabelTTF, base<Node>>("cc.LabelTTF")
    .constructor<>()
    .function("enableShadow", &LabelTTF::enableShadow, allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](LabelTTF& this_, const cocos2d::Size& arg0, float arg1, float arg2){
        return this_.enableShadow(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("setDimensions", &LabelTTF::setDimensions, allow_raw_pointers())
    .function("getFontSize", &LabelTTF::getFontSize, allow_raw_pointers())
    .function("setFlippedY", &LabelTTF::setFlippedY, allow_raw_pointers())
    .function("setFlippedX", &LabelTTF::setFlippedX, allow_raw_pointers())
    .function("setTextDefinition", &LabelTTF::setTextDefinition, allow_raw_pointers())
    .function("setFontName", &LabelTTF::setFontName, allow_raw_pointers())
    .function("getHorizontalAlignment", &LabelTTF::getHorizontalAlignment, allow_raw_pointers())
    .function("initWithStringAndTextDefinition", &LabelTTF::initWithStringAndTextDefinition, allow_raw_pointers())
    .function("initWithString", &LabelTTF::initWithString, allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2){
        return this_.initWithString(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3, cocos2d::TextHAlignment arg4){
        return this_.initWithString(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("setFontFillColor", &LabelTTF::setFontFillColor, allow_raw_pointers())
    .function("setFontFillColor", optional_override(
        [](LabelTTF& this_, const cocos2d::Color3B& arg0){
        return this_.setFontFillColor(arg0);
      }), allow_raw_pointers())
    .function("enableStroke", &LabelTTF::enableStroke, allow_raw_pointers())
    .function("enableStroke", optional_override(
        [](LabelTTF& this_, const cocos2d::Color3B& arg0, float arg1){
        return this_.enableStroke(arg0, arg1);
      }), allow_raw_pointers())
    .function("getDimensions", &LabelTTF::getDimensions, allow_raw_pointers())
    .function("setVerticalAlignment", &LabelTTF::setVerticalAlignment, allow_raw_pointers())
    .function("setFontSize", &LabelTTF::setFontSize, allow_raw_pointers())
    .function("getVerticalAlignment", &LabelTTF::getVerticalAlignment, allow_raw_pointers())
    .function("getTextDefinition", &LabelTTF::getTextDefinition, allow_raw_pointers())
    .function("getFontName", &LabelTTF::getFontName, allow_raw_pointers())
    .function("setHorizontalAlignment", &LabelTTF::setHorizontalAlignment, allow_raw_pointers())
    .function("disableShadow", &LabelTTF::disableShadow, allow_raw_pointers())
    .function("disableShadow", optional_override(
        [](LabelTTF& this_){
        return this_.disableShadow();
      }), allow_raw_pointers())
    .function("disableStroke", &LabelTTF::disableStroke, allow_raw_pointers())
    .function("disableStroke", optional_override(
        [](LabelTTF& this_){
        return this_.disableStroke();
      }), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LabelTTF>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelTTF*()>(&LabelTTF::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelTTF*(const std::string&, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&LabelTTF::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithFontDefinition", &LabelTTF::createWithFontDefinition, allow_raw_pointers())
    .property("_className",  optional_override([](const LabelTTF& _) -> std::string {return "LabelTTF";}))    
    // TODO: assign cc.Class.extend to cc.LabelTTF.extend
    ;


  class_<Layer, base<Node>>("cc.Layer")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Layer>, allow_raw_pointers())
    .class_function("create", &Layer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layer& _) -> std::string {return "Layer";}))    
    // TODO: assign cc.Class.extend to cc.Layer.extend
    ;


  class_<__LayerRGBA, base<Layer>>("cc.__LayerRGBA")
    .constructor<>()
    .class_function("create", &__LayerRGBA::create, allow_raw_pointers())
    .property("_className",  optional_override([](const __LayerRGBA& _) -> std::string {return "__LayerRGBA";}))    
    ;


  class_<LayerColor, base<Layer>>("cc.LayerColor")
    .constructor<>()
    .function("changeWidthAndHeight", &LayerColor::changeWidthAndHeight, allow_raw_pointers())
    .function("init", select_overload<bool(const cocos2d::Color4B&, float, float)>(&LayerColor::initWithColor), allow_raw_pointers())
    .function("init", select_overload<bool(const cocos2d::Color4B&)>(&LayerColor::initWithColor), allow_raw_pointers())
    .function("changeWidth", &LayerColor::changeWidth, allow_raw_pointers())
    .function("changeHeight", &LayerColor::changeHeight, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LayerColor>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*(const cocos2d::Color4B&, float, float)>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*()>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*(const cocos2d::Color4B&)>(&LayerColor::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerColor& _) -> std::string {return "LayerColor";}))    
    // TODO: assign cc.Class.extend to cc.LayerColor.extend
    ;


  class_<LayerGradient, base<LayerColor>>("cc.LayerGradient")
    .constructor<>()
    .function("getStartColor", &LayerGradient::getStartColor, allow_raw_pointers())
    .function("isCompressedInterpolation", &LayerGradient::isCompressedInterpolation, allow_raw_pointers())
    .function("getStartOpacity", &LayerGradient::getStartOpacity, allow_raw_pointers())
    .function("setVector", &LayerGradient::setVector, allow_raw_pointers())
    .function("setStartOpacity", &LayerGradient::setStartOpacity, allow_raw_pointers())
    .function("setCompressedInterpolation", &LayerGradient::setCompressedInterpolation, allow_raw_pointers())
    .function("setEndOpacity", &LayerGradient::setEndOpacity, allow_raw_pointers())
    .function("getVector", &LayerGradient::getVector, allow_raw_pointers())
    .function("setEndColor", &LayerGradient::setEndColor, allow_raw_pointers())
    .function("initWithColor", select_overload<bool(const cocos2d::Color4B&, const cocos2d::Color4B&, const cocos2d::Vec2&)>(&LayerGradient::initWithColor), allow_raw_pointers())
    .function("initWithColor", select_overload<bool(const cocos2d::Color4B&, const cocos2d::Color4B&)>(&LayerGradient::initWithColor), allow_raw_pointers())
    .function("getEndColor", &LayerGradient::getEndColor, allow_raw_pointers())
    .function("getEndOpacity", &LayerGradient::getEndOpacity, allow_raw_pointers())
    .function("setStartColor", &LayerGradient::setStartColor, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LayerGradient>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&)>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*()>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&, const cocos2d::Vec2&)>(&LayerGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerGradient& _) -> std::string {return "LayerGradient";}))    
    // TODO: assign cc.Class.extend to cc.LayerGradient.extend
    ;


  class_<LayerRadialGradient, base<Layer>>("cc.LayerRadialGradient")
    .constructor<>()
    .function("setStartOpacity", &LayerRadialGradient::setStartOpacity, allow_raw_pointers())
    .function("getStartColor3B", &LayerRadialGradient::getStartColor3B, allow_raw_pointers())
    .function("getEndColor", &LayerRadialGradient::getEndColor, allow_raw_pointers())
    .function("getRadius", &LayerRadialGradient::getRadius, allow_raw_pointers())
    .function("getStartColor", &LayerRadialGradient::getStartColor, allow_raw_pointers())
    .function("setExpand", &LayerRadialGradient::setExpand, allow_raw_pointers())
    .function("getEndOpacity", &LayerRadialGradient::getEndOpacity, allow_raw_pointers())
    .function("initWithColor", &LayerRadialGradient::initWithColor, allow_raw_pointers())
    .function("getEndColor3B", &LayerRadialGradient::getEndColor3B, allow_raw_pointers())
    .function("getBlendFunc", &LayerRadialGradient::getBlendFunc, allow_raw_pointers())
    .function("setCenter", &LayerRadialGradient::setCenter, allow_raw_pointers())
    .function("getCenter", &LayerRadialGradient::getCenter, allow_raw_pointers())
    .function("setStartColor", select_overload<void(const cocos2d::Color4B&)>(&LayerRadialGradient::setStartColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getExpand", &LayerRadialGradient::getExpand, allow_raw_pointers())
    .function("setBlendFunc", &LayerRadialGradient::setBlendFunc, allow_raw_pointers())
    .function("getStartOpacity", &LayerRadialGradient::getStartOpacity, allow_raw_pointers())
    .function("setEndOpacity", &LayerRadialGradient::setEndOpacity, allow_raw_pointers())
    .function("setEndColor", select_overload<void(const cocos2d::Color4B&)>(&LayerRadialGradient::setEndColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setRadius", &LayerRadialGradient::setRadius, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LayerRadialGradient>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerRadialGradient*()>(&LayerRadialGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerRadialGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&, float, const cocos2d::Vec2&, float)>(&LayerRadialGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerRadialGradient& _) -> std::string {return "LayerRadialGradient";}))    
    // TODO: assign cc.Class.extend to cc.LayerRadialGradient.extend
    ;


  class_<LayerMultiplex, base<Layer>>("cc.LayerMultiplex")
    .constructor<>()
    .function("initWithArray", &LayerMultiplex::initWithArray, allow_raw_pointers())
    .function("switchToAndReleaseMe", &LayerMultiplex::switchToAndReleaseMe, allow_raw_pointers())
    .function("addLayer", &LayerMultiplex::addLayer, allow_raw_pointers())
    .function("switchTo", select_overload<void(int, bool)>(&LayerMultiplex::switchTo), allow_raw_pointers())
    .function("switchTo", select_overload<void(int)>(&LayerMultiplex::switchTo), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LayerMultiplex>, allow_raw_pointers())
    .property("_className",  optional_override([](const LayerMultiplex& _) -> std::string {return "LayerMultiplex";}))    
    // TODO: assign cc.Class.extend to cc.LayerMultiplex.extend
    ;


  class_<MenuItem, base<Node>>("cc.MenuItem")
    .constructor<>()
    .function("setEnabled", &MenuItem::setEnabled, allow_raw_pointers())
    .function("activate", &MenuItem::activate, allow_raw_pointers())
    .function("initWithCallback", &MenuItem::initWithCallback, allow_raw_pointers())
    .function("isEnabled", &MenuItem::isEnabled, allow_raw_pointers())
    .function("selected", &MenuItem::selected, allow_raw_pointers())
    .function("isSelected", &MenuItem::isSelected, allow_raw_pointers())
    .function("setCallback", &MenuItem::setCallback, allow_raw_pointers())
    .function("unselected", &MenuItem::unselected, allow_raw_pointers())
    .function("rect", &MenuItem::rect, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItem>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItem& _) -> std::string {return "MenuItem";}))    
    // TODO: assign cc.Class.extend to cc.MenuItem.extend
    ;


  class_<MenuItemLabel, base<MenuItem>>("cc.MenuItemLabel")
    .constructor<>()
    .function("setLabel", &MenuItemLabel::setLabel, allow_raw_pointers())
    .function("getString", &MenuItemLabel::getString, allow_raw_pointers())
    .function("getDisabledColor", &MenuItemLabel::getDisabledColor, allow_raw_pointers())
    .function("setString", &MenuItemLabel::setString, allow_raw_pointers())
    .function("initWithLabel", select_overload<bool(cocos2d::Node*, const std::function<void (cocos2d::Ref *)>&)>(&MenuItemLabel::initWithLabel), allow_raw_pointers())
    .function("setDisabledColor", &MenuItemLabel::setDisabledColor, allow_raw_pointers())
    .function("getLabel", &MenuItemLabel::getLabel, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemLabel>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemLabel& _) -> std::string {return "MenuItemLabel";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemLabel.extend
    ;


  class_<MenuItemAtlasFont, base<MenuItemLabel>>("cc.MenuItemAtlasFont")
    .constructor<>()
    .function("initWithString", select_overload<bool(const std::string&, const std::string&, int, int, char, const std::function<void (cocos2d::Ref *)>&)>(&MenuItemAtlasFont::initWithString), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemAtlasFont>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemAtlasFont& _) -> std::string {return "MenuItemAtlasFont";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemAtlasFont.extend
    ;


  class_<MenuItemFont, base<MenuItemLabel>>("cc.MenuItemFont")
    .constructor<>()
    .function("setFontName", &MenuItemFont::setFontNameObj, allow_raw_pointers())
    .function("getFontSize", &MenuItemFont::getFontSizeObj, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const std::string&, const std::function<void (cocos2d::Ref *)>&)>(&MenuItemFont::initWithString), allow_raw_pointers())
    .function("setFontSize", &MenuItemFont::setFontSizeObj, allow_raw_pointers())
    .function("getFontName", &MenuItemFont::getFontNameObj, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemFont>, allow_raw_pointers())
    .class_function("setFontName", &MenuItemFont::setFontName, allow_raw_pointers())
    .class_function("getFontSize", &MenuItemFont::getFontSize, allow_raw_pointers())
    .class_function("setFontSize", &MenuItemFont::setFontSize, allow_raw_pointers())
    .class_function("getFontName", &MenuItemFont::getFontName, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemFont& _) -> std::string {return "MenuItemFont";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemFont.extend
    ;


  class_<MenuItemSprite, base<MenuItem>>("cc.MenuItemSprite")
    .constructor<>()
    .function("setEnabled", &MenuItemSprite::setEnabled, allow_raw_pointers())
    .function("selected", &MenuItemSprite::selected, allow_raw_pointers())
    .function("setNormalImage", &MenuItemSprite::setNormalImage, allow_raw_pointers())
    .function("setDisabledImage", &MenuItemSprite::setDisabledImage, allow_raw_pointers())
    .function("initWithNormalSprite", select_overload<bool(cocos2d::Node*, cocos2d::Node*, cocos2d::Node*, const std::function<void (cocos2d::Ref *)>&)>(&MenuItemSprite::initWithNormalSprite), allow_raw_pointers())
    .function("setSelectedImage", &MenuItemSprite::setSelectedImage, allow_raw_pointers())
    .function("getDisabledImage", &MenuItemSprite::getDisabledImage, allow_raw_pointers())
    .function("getSelectedImage", &MenuItemSprite::getSelectedImage, allow_raw_pointers())
    .function("getNormalImage", &MenuItemSprite::getNormalImage, allow_raw_pointers())
    .function("unselected", &MenuItemSprite::unselected, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemSprite>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemSprite& _) -> std::string {return "MenuItemSprite";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemSprite.extend
    ;


  class_<MenuItemImage, base<MenuItemSprite>>("cc.MenuItemImage")
    .constructor<>()
    .function("setDisabledSpriteFrame", &MenuItemImage::setDisabledSpriteFrame, allow_raw_pointers())
    .function("setSelectedSpriteFrame", &MenuItemImage::setSelectedSpriteFrame, allow_raw_pointers())
    .function("setNormalSpriteFrame", &MenuItemImage::setNormalSpriteFrame, allow_raw_pointers())
    .function("init", &MenuItemImage::init, allow_raw_pointers())
    .function("initWithNormalImage", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::function<void (cocos2d::Ref *)>&)>(&MenuItemImage::initWithNormalImage), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemImage>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemImage& _) -> std::string {return "MenuItemImage";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemImage.extend
    ;


  class_<MenuItemToggle, base<MenuItem>>("cc.MenuItemToggle")
    .constructor<>()
    .function("setSubItems", &MenuItemToggle::setSubItems, allow_raw_pointers())
    .function("setSelectedIndex", &MenuItemToggle::setSelectedIndex, allow_raw_pointers())
    .function("getSelectedIndex", &MenuItemToggle::getSelectedIndex, allow_raw_pointers())
    .function("getSelectedItem", &MenuItemToggle::getSelectedItem, allow_raw_pointers())
    .function("initWithItem", &MenuItemToggle::initWithItem, allow_raw_pointers())
    .function("addSubItem", &MenuItemToggle::addSubItem, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemToggle>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemToggle& _) -> std::string {return "MenuItemToggle";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemToggle.extend
    ;


  class_<Menu, base<Layer>>("cc.Menu")
    .constructor<>()
    .function("initWithArray", &Menu::initWithArray, allow_raw_pointers())
    .function("alignItemsVertically", &Menu::alignItemsVertically, allow_raw_pointers())
    .function("isEnabled", &Menu::isEnabled, allow_raw_pointers())
    .function("alignItemsHorizontallyWithPadding", &Menu::alignItemsHorizontallyWithPadding, allow_raw_pointers())
    .function("alignItemsHorizontally", &Menu::alignItemsHorizontally, allow_raw_pointers())
    .function("setEnabled", &Menu::setEnabled, allow_raw_pointers())
    .function("alignItemsVerticallyWithPadding", &Menu::alignItemsVerticallyWithPadding, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Menu>, allow_raw_pointers())
    .property("_className",  optional_override([](const Menu& _) -> std::string {return "Menu";}))    
    // TODO: assign cc.Class.extend to cc.Menu.extend
    ;


  class_<MotionStreak, base<Node>>("cc.MotionStreak")
    .constructor<>()
    .function("getStroke", &MotionStreak::getStroke, allow_raw_pointers())
    .function("isStartingPositionInitialized", &MotionStreak::isStartingPositionInitialized, allow_raw_pointers())
    .function("setFastMode", &MotionStreak::setFastMode, allow_raw_pointers())
    .function("reset", &MotionStreak::reset, allow_raw_pointers())
    .function("tintWithColor", &MotionStreak::tintWithColor, allow_raw_pointers())
    .function("setStartingPositionInitialized", &MotionStreak::setStartingPositionInitialized, allow_raw_pointers())
    .function("isFastMode", &MotionStreak::isFastMode, allow_raw_pointers())
    .function("initWithFade", select_overload<bool(float, float, float, const cocos2d::Color3B&, cocos2d::Texture2D*)>(&MotionStreak::initWithFade), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setStroke", &MotionStreak::setStroke, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MotionStreak>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MotionStreak*(float, float, float, const cocos2d::Color3B&, cocos2d::Texture2D*)>(&MotionStreak::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MotionStreak& _) -> std::string {return "MotionStreak";}))    
    // TODO: assign cc.Class.extend to cc.MotionStreak.extend
    ;


  class_<NodeGrid, base<Node>>("cc.NodeGrid")
    .constructor<>()
    .function("setTarget", &NodeGrid::setTarget, allow_raw_pointers())
    .function("getGrid", select_overload<const cocos2d::GridBase*() const>(&NodeGrid::getGrid), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGridRect", &NodeGrid::getGridRect, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::NodeGrid*(const cocos2d::Rect&)>(&NodeGrid::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::NodeGrid*()>(&NodeGrid::create), allow_raw_pointers())
    .property("_className",  optional_override([](const NodeGrid& _) -> std::string {return "NodeGrid";}))    
    ;


  class_<ParticleBatchNode, base<Node>>("cc.ParticleBatchNode")
    .constructor<>()
    .function("initWithTexture", &ParticleBatchNode::initWithTexture, allow_raw_pointers())
    .function("disableParticle", &ParticleBatchNode::disableParticle, allow_raw_pointers())
    .function("setTextureAtlas", &ParticleBatchNode::setTextureAtlas, allow_raw_pointers())
    .function("initWithFile", &ParticleBatchNode::initWithFile, allow_raw_pointers())
    .function("getTextureAtlas", &ParticleBatchNode::getTextureAtlas, allow_raw_pointers())
    .function("insertChild", &ParticleBatchNode::insertChild, allow_raw_pointers())
    .function("removeChildAtIndex", &ParticleBatchNode::removeChildAtIndex, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ParticleBatchNode>, allow_raw_pointers())
    .class_function("create", &ParticleBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return ParticleBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &ParticleBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return ParticleBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleBatchNode& _) -> std::string {return "ParticleBatchNode";}))    
    // TODO: assign cc.Class.extend to cc.ParticleBatchNode.extend
    ;


  class_<ParticleData>("cc.ParticleData")
    .constructor<>()
    // TODO: Emscripten cannot automatically call destructor.
    .function("release", &ParticleData::release, allow_raw_pointers())
    .function("getMaxCount", &ParticleData::getMaxCount, allow_raw_pointers())
    .function("init", &ParticleData::init, allow_raw_pointers())
    .function("copyParticle", &ParticleData::copyParticle, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleData& _) -> std::string {return "ParticleData";}))    
    ;


  class_<ParticleSystem, base<Node>>("cc.ParticleSystem")
    .constructor<>()
    .function("getStartSizeVar", &ParticleSystem::getStartSizeVar, allow_raw_pointers())
    .function("isFull", &ParticleSystem::isFull, allow_raw_pointers())
    .function("getBatchNode", &ParticleSystem::getBatchNode, allow_raw_pointers())
    .function("getStartColor", &ParticleSystem::getStartColor, allow_raw_pointers())
    .function("getPositionType", &ParticleSystem::getPositionType, allow_raw_pointers())
    .function("setPosVar", &ParticleSystem::setPosVar, allow_raw_pointers())
    .function("getEndSpin", &ParticleSystem::getEndSpin, allow_raw_pointers())
    .function("setRotatePerSecondVar", &ParticleSystem::setRotatePerSecondVar, allow_raw_pointers())
    .function("setSourcePositionCompatible", &ParticleSystem::setSourcePositionCompatible, allow_raw_pointers())
    .function("getStartSpinVar", &ParticleSystem::getStartSpinVar, allow_raw_pointers())
    .function("getRadialAccelVar", &ParticleSystem::getRadialAccelVar, allow_raw_pointers())
    .function("getEndSizeVar", &ParticleSystem::getEndSizeVar, allow_raw_pointers())
    .function("setTangentialAccel", &ParticleSystem::setTangentialAccel, allow_raw_pointers())
    .function("getRadialAccel", &ParticleSystem::getRadialAccel, allow_raw_pointers())
    .function("setStartRadius", &ParticleSystem::setStartRadius, allow_raw_pointers())
    .function("setRotatePerSecond", &ParticleSystem::setRotatePerSecond, allow_raw_pointers())
    .function("setEndSize", &ParticleSystem::setEndSize, allow_raw_pointers())
    .function("getGravity", &ParticleSystem::getGravity, allow_raw_pointers())
    .function("resumeEmissions", &ParticleSystem::resumeEmissions, allow_raw_pointers())
    .function("getTangentialAccel", &ParticleSystem::getTangentialAccel, allow_raw_pointers())
    .function("setEndRadius", &ParticleSystem::setEndRadius, allow_raw_pointers())
    .function("getSpeed", &ParticleSystem::getSpeed, allow_raw_pointers())
    .function("pauseEmissions", &ParticleSystem::pauseEmissions, allow_raw_pointers())
    .function("getAngle", &ParticleSystem::getAngle, allow_raw_pointers())
    .function("setEndColor", &ParticleSystem::setEndColor, allow_raw_pointers())
    .function("setStartSpin", &ParticleSystem::setStartSpin, allow_raw_pointers())
    .function("setDuration", &ParticleSystem::setDuration, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleSystem::initWithTotalParticles, allow_raw_pointers())
    .function("addParticles", &ParticleSystem::addParticles, allow_raw_pointers())
    .function("getPosVar", &ParticleSystem::getPosVar, allow_raw_pointers())
    .function("updateWithNoTime", &ParticleSystem::updateWithNoTime, allow_raw_pointers())
    .function("isBlendAdditive", &ParticleSystem::isBlendAdditive, allow_raw_pointers())
    .function("getSpeedVar", &ParticleSystem::getSpeedVar, allow_raw_pointers())
    .function("setPositionType", &ParticleSystem::setPositionType, allow_raw_pointers())
    .function("stopSystem", &ParticleSystem::stopSystem, allow_raw_pointers())
    .function("getSourcePosition", &ParticleSystem::getSourcePosition, allow_raw_pointers())
    .function("setLifeVar", &ParticleSystem::setLifeVar, allow_raw_pointers())
    .function("setTotalParticles", &ParticleSystem::setTotalParticles, allow_raw_pointers())
    .function("setEndColorVar", &ParticleSystem::setEndColorVar, allow_raw_pointers())
    .function("getAtlasIndex", &ParticleSystem::getAtlasIndex, allow_raw_pointers())
    .function("getStartSize", &ParticleSystem::getStartSize, allow_raw_pointers())
    .function("setStartSpinVar", &ParticleSystem::setStartSpinVar, allow_raw_pointers())
    .function("resetSystem", &ParticleSystem::resetSystem, allow_raw_pointers())
    .function("setAtlasIndex", &ParticleSystem::setAtlasIndex, allow_raw_pointers())
    .function("setTangentialAccelVar", &ParticleSystem::setTangentialAccelVar, allow_raw_pointers())
    .function("setEndRadiusVar", &ParticleSystem::setEndRadiusVar, allow_raw_pointers())
    .function("getEndRadius", &ParticleSystem::getEndRadius, allow_raw_pointers())
    .function("isActive", &ParticleSystem::isActive, allow_raw_pointers())
    .function("setRadialAccelVar", &ParticleSystem::setRadialAccelVar, allow_raw_pointers())
    .function("setStartSize", &ParticleSystem::setStartSize, allow_raw_pointers())
    .function("setSpeed", &ParticleSystem::setSpeed, allow_raw_pointers())
    .function("getStartSpin", &ParticleSystem::getStartSpin, allow_raw_pointers())
    .function("getResourceFile", &ParticleSystem::getResourceFile, allow_raw_pointers())
    .function("getRotatePerSecond", &ParticleSystem::getRotatePerSecond, allow_raw_pointers())
    .function("setEmitterMode", &ParticleSystem::setEmitterMode, allow_raw_pointers())
    .function("getDuration", &ParticleSystem::getDuration, allow_raw_pointers())
    .function("setSourcePosition", &ParticleSystem::setSourcePosition, allow_raw_pointers())
    .function("updateParticleQuads", &ParticleSystem::updateParticleQuads, allow_raw_pointers())
    .function("getEndSpinVar", &ParticleSystem::getEndSpinVar, allow_raw_pointers())
    .function("setBlendAdditive", &ParticleSystem::setBlendAdditive, allow_raw_pointers())
    .function("setLife", &ParticleSystem::setLife, allow_raw_pointers())
    .function("setAngleVar", &ParticleSystem::setAngleVar, allow_raw_pointers())
    .function("setRotationIsDir", &ParticleSystem::setRotationIsDir, allow_raw_pointers())
    .function("setEndSizeVar", &ParticleSystem::setEndSizeVar, allow_raw_pointers())
    .function("setAngle", &ParticleSystem::setAngle, allow_raw_pointers())
    .function("setBatchNode", &ParticleSystem::setBatchNode, allow_raw_pointers())
    .function("getTangentialAccelVar", &ParticleSystem::getTangentialAccelVar, allow_raw_pointers())
    .function("getEmitterMode", &ParticleSystem::getEmitterMode, allow_raw_pointers())
    .function("setEndSpinVar", &ParticleSystem::setEndSpinVar, allow_raw_pointers())
    .function("initWithFile", &ParticleSystem::initWithFile, allow_raw_pointers())
    .function("getAngleVar", &ParticleSystem::getAngleVar, allow_raw_pointers())
    .function("setStartColor", &ParticleSystem::setStartColor, allow_raw_pointers())
    .function("getRotatePerSecondVar", &ParticleSystem::getRotatePerSecondVar, allow_raw_pointers())
    .function("getEndSize", &ParticleSystem::getEndSize, allow_raw_pointers())
    .function("getLife", &ParticleSystem::getLife, allow_raw_pointers())
    .function("isPaused", &ParticleSystem::isPaused, allow_raw_pointers())
    .function("setSpeedVar", &ParticleSystem::setSpeedVar, allow_raw_pointers())
    .function("setAutoRemoveOnFinish", &ParticleSystem::setAutoRemoveOnFinish, allow_raw_pointers())
    .function("setGravity", &ParticleSystem::setGravity, allow_raw_pointers())
    .function("postStep", &ParticleSystem::postStep, allow_raw_pointers())
    .function("setEmissionRate", &ParticleSystem::setEmissionRate, allow_raw_pointers())
    .function("getEndColorVar", &ParticleSystem::getEndColorVar, allow_raw_pointers())
    .function("getRotationIsDir", &ParticleSystem::getRotationIsDir, allow_raw_pointers())
    .function("getEmissionRate", &ParticleSystem::getEmissionRate, allow_raw_pointers())
    .function("getEndColor", &ParticleSystem::getEndColor, allow_raw_pointers())
    .function("getLifeVar", &ParticleSystem::getLifeVar, allow_raw_pointers())
    .function("setStartSizeVar", &ParticleSystem::setStartSizeVar, allow_raw_pointers())
    .function("getStartRadius", &ParticleSystem::getStartRadius, allow_raw_pointers())
    .function("getParticleCount", &ParticleSystem::getParticleCount, allow_raw_pointers())
    .function("getStartRadiusVar", &ParticleSystem::getStartRadiusVar, allow_raw_pointers())
    .function("setStartColorVar", &ParticleSystem::setStartColorVar, allow_raw_pointers())
    .function("setEndSpin", &ParticleSystem::setEndSpin, allow_raw_pointers())
    .function("setRadialAccel", &ParticleSystem::setRadialAccel, allow_raw_pointers())
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, cocos2d::Value>&, const std::string&)>(&ParticleSystem::initWithDictionary), allow_raw_pointers())
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, cocos2d::Value>&)>(&ParticleSystem::initWithDictionary), allow_raw_pointers())
    .function("isAutoRemoveOnFinish", &ParticleSystem::isAutoRemoveOnFinish, allow_raw_pointers())
    .function("isSourcePositionCompatible", &ParticleSystem::isSourcePositionCompatible, allow_raw_pointers())
    .function("getTotalParticles", &ParticleSystem::getTotalParticles, allow_raw_pointers())
    .function("setStartRadiusVar", &ParticleSystem::setStartRadiusVar, allow_raw_pointers())
    .function("getEndRadiusVar", &ParticleSystem::getEndRadiusVar, allow_raw_pointers())
    .function("getStartColorVar", &ParticleSystem::getStartColorVar, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ParticleSystem>, allow_raw_pointers())
    .class_function("create", &ParticleSystem::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSystem::createWithTotalParticles, allow_raw_pointers())
    .class_function("getAllParticleSystems", &ParticleSystem::getAllParticleSystems, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystem& _) -> std::string {return "ParticleSystem";}))    
    // TODO: assign cc.Class.extend to cc.ParticleSystem.extend
    ;


  class_<ParticleSystemQuad, base<ParticleSystem>>("cc.ParticleSystem")
    .constructor<>()
    .function("setTextureWithRect", &ParticleSystemQuad::setTextureWithRect, allow_raw_pointers())
    .function("setDisplayFrame", &ParticleSystemQuad::setDisplayFrame, allow_raw_pointers())
    .function("listenRendererRecreated", &ParticleSystemQuad::listenRendererRecreated, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ParticleSystemQuad*(const std::string&)>(&ParticleSystemQuad::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ParticleSystemQuad*()>(&ParticleSystemQuad::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithTotalParticles", &ParticleSystemQuad::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystemQuad& _) -> std::string {return "ParticleSystemQuad";}))    
    ;


  class_<ParticleFire, base<ParticleSystemQuad>>("cc.ParticleFire")
    .constructor<>()
    .class_function("create", &ParticleFire::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFire::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFire& _) -> std::string {return "ParticleFire";}))    
    ;


  class_<ParticleFireworks, base<ParticleSystemQuad>>("cc.ParticleFireworks")
    .constructor<>()
    .function("init", &ParticleFireworks::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleFireworks::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleFireworks::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFireworks::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFireworks& _) -> std::string {return "ParticleFireworks";}))    
    ;


  class_<ParticleSun, base<ParticleSystemQuad>>("cc.ParticleSun")
    .constructor<>()
    .function("init", &ParticleSun::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleSun::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleSun::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSun::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSun& _) -> std::string {return "ParticleSun";}))    
    ;


  class_<ParticleGalaxy, base<ParticleSystemQuad>>("cc.ParticleGalaxy")
    .constructor<>()
    .function("init", &ParticleGalaxy::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleGalaxy::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleGalaxy::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleGalaxy::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleGalaxy& _) -> std::string {return "ParticleGalaxy";}))    
    ;


  class_<ParticleFlower, base<ParticleSystemQuad>>("cc.ParticleFlower")
    .constructor<>()
    .function("init", &ParticleFlower::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleFlower::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleFlower::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFlower::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFlower& _) -> std::string {return "ParticleFlower";}))    
    ;


  class_<ParticleMeteor, base<ParticleSystemQuad>>("cc.ParticleMeteor")
    .constructor<>()
    .function("init", &ParticleMeteor::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleMeteor::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleMeteor::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleMeteor::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleMeteor& _) -> std::string {return "ParticleMeteor";}))    
    ;


  class_<ParticleSpiral, base<ParticleSystemQuad>>("cc.ParticleSpiral")
    .constructor<>()
    .function("init", &ParticleSpiral::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleSpiral::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleSpiral::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSpiral::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSpiral& _) -> std::string {return "ParticleSpiral";}))    
    ;


  class_<ParticleExplosion, base<ParticleSystemQuad>>("cc.ParticleExplosion")
    .constructor<>()
    .function("init", &ParticleExplosion::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleExplosion::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleExplosion::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleExplosion::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleExplosion& _) -> std::string {return "ParticleExplosion";}))    
    ;


  class_<ParticleSmoke, base<ParticleSystemQuad>>("cc.ParticleSmoke")
    .constructor<>()
    .function("init", &ParticleSmoke::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleSmoke::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleSmoke::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSmoke::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSmoke& _) -> std::string {return "ParticleSmoke";}))    
    ;


  class_<ParticleSnow, base<ParticleSystemQuad>>("cc.ParticleSnow")
    .constructor<>()
    .function("init", &ParticleSnow::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleSnow::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleSnow::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSnow::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSnow& _) -> std::string {return "ParticleSnow";}))    
    ;


  class_<ParticleRain, base<ParticleSystemQuad>>("cc.ParticleRain")
    .constructor<>()
    .function("init", &ParticleRain::init, allow_raw_pointers())
    .function("initWithTotalParticles", &ParticleRain::initWithTotalParticles, allow_raw_pointers())
    .class_function("create", &ParticleRain::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleRain::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleRain& _) -> std::string {return "ParticleRain";}))    
    ;


  class_<ProgressTimer, base<Node>>("cc.ProgressTimer")
    .constructor<>()
    .function("initWithSprite", &ProgressTimer::initWithSprite, allow_raw_pointers())
    .function("isReverseDirection", &ProgressTimer::isReverseDirection, allow_raw_pointers())
    .function("setBarChangeRate", &ProgressTimer::setBarChangeRate, allow_raw_pointers())
    .function("getPercentage", &ProgressTimer::getPercentage, allow_raw_pointers())
    .function("setSprite", &ProgressTimer::setSprite, allow_raw_pointers())
    .function("getType", &ProgressTimer::getType, allow_raw_pointers())
    .function("getSprite", &ProgressTimer::getSprite, allow_raw_pointers())
    .function("setMidpoint", &ProgressTimer::setMidpoint, allow_raw_pointers())
    .function("getBarChangeRate", &ProgressTimer::getBarChangeRate, allow_raw_pointers())
    .function("setReverseDirection", select_overload<void(bool)>(&ProgressTimer::setReverseDirection), allow_raw_pointers())
    .function("getMidpoint", &ProgressTimer::getMidpoint, allow_raw_pointers())
    .function("setPercentage", &ProgressTimer::setPercentage, allow_raw_pointers())
    .function("setType", &ProgressTimer::setType, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ProgressTimer>, allow_raw_pointers())
    .class_function("create", &ProgressTimer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTimer& _) -> std::string {return "ProgressTimer";}))    
    // TODO: assign cc.Class.extend to cc.ProgressTimer.extend
    ;


  class_<ProtectedNode, base<Node>>("cc.ProtectedNode")
    .constructor<>()
    .function("addProtectedChild", select_overload<void(cocos2d::Node*, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(cocos2d::Node*)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(cocos2d::Node*, int, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("removeProtectedChildByTag", &ProtectedNode::removeProtectedChildByTag, allow_raw_pointers())
    .function("removeProtectedChildByTag", optional_override(
        [](ProtectedNode& this_, int arg0){
        return this_.removeProtectedChildByTag(arg0);
      }), allow_raw_pointers())
    .function("reorderProtectedChild", &ProtectedNode::reorderProtectedChild, allow_raw_pointers())
    .function("removeAllProtectedChildrenWithCleanup", &ProtectedNode::removeAllProtectedChildrenWithCleanup, allow_raw_pointers())
    .function("sortAllProtectedChildren", &ProtectedNode::sortAllProtectedChildren, allow_raw_pointers())
    .function("getProtectedChildByTag", &ProtectedNode::getProtectedChildByTag, allow_raw_pointers())
    .function("removeProtectedChild", &ProtectedNode::removeProtectedChild, allow_raw_pointers())
    .function("removeProtectedChild", optional_override(
        [](ProtectedNode& this_, cocos2d::Node* arg0){
        return this_.removeProtectedChild(arg0);
      }), allow_raw_pointers())
    .function("removeAllProtectedChildren", &ProtectedNode::removeAllProtectedChildren, allow_raw_pointers())
    .class_function("create", &ProtectedNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProtectedNode& _) -> std::string {return "ProtectedNode";}))    
    ;


  class_<Sprite, base<Node>>("cc.Sprite")
    .constructor<>()
    .function("setSpriteFrame", select_overload<void(cocos2d::SpriteFrame*)>(&Sprite::setSpriteFrame), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setTexture", select_overload<void(const std::string&)>(&Sprite::setTexture), allow_raw_pointers())
    .function("setFlippedY", &Sprite::setFlippedY, allow_raw_pointers())
    .function("setFlippedX", &Sprite::setFlippedX, allow_raw_pointers())
    .function("getResourceType", &Sprite::getResourceType, allow_raw_pointers())
    .function("setDisplayFrameWithAnimationName", &Sprite::setDisplayFrameWithAnimationName, allow_raw_pointers())
    .function("getBatchNode", &Sprite::getBatchNode, allow_raw_pointers())
    .function("getOffsetPosition", &Sprite::getOffsetPosition, allow_raw_pointers())
    .function("getCenterRect", &Sprite::getCenterRect, allow_raw_pointers())
    .function("setCenterRectNormalized", &Sprite::setCenterRectNormalized, allow_raw_pointers())
    .function("isStretchEnabled", &Sprite::isStretchEnabled, allow_raw_pointers())
    .function("isFlippedX", &Sprite::isFlippedX, allow_raw_pointers())
    .function("setTextureRect", select_overload<void(const cocos2d::Rect&, bool, const cocos2d::Size&)>(&Sprite::setTextureRect), allow_raw_pointers())
    .function("setTextureRect", select_overload<void(const cocos2d::Rect&)>(&Sprite::setTextureRect), allow_raw_pointers())
    .function("setStretchEnabled", &Sprite::setStretchEnabled, allow_raw_pointers())
    .function("isFrameDisplayed", &Sprite::isFrameDisplayed, allow_raw_pointers())
    .function("getAtlasIndex", &Sprite::getAtlasIndex, allow_raw_pointers())
    .function("setBatchNode", &Sprite::setBatchNode, allow_raw_pointers())
    .function("initWithSpriteFrameName", &Sprite::initWithSpriteFrameName, allow_raw_pointers())
    .function("setCenterRect", &Sprite::setCenterRect, allow_raw_pointers())
    .function("setTextureAtlas", &Sprite::setTextureAtlas, allow_raw_pointers())
    .function("getSpriteFrame", &Sprite::getSpriteFrame, allow_raw_pointers())
    .function("getResourceName", &Sprite::getResourceName, allow_raw_pointers())
    .function("isDirty", &Sprite::isDirty, allow_raw_pointers())
    .function("getCenterRectNormalized", &Sprite::getCenterRectNormalized, allow_raw_pointers())
    .function("setAtlasIndex", &Sprite::setAtlasIndex, allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&, bool)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("setDirty", &Sprite::setDirty, allow_raw_pointers())
    .function("isTextureRectRotated", &Sprite::isTextureRectRotated, allow_raw_pointers())
    .function("getTextureRect", &Sprite::getTextureRect, allow_raw_pointers())
    .function("initWithFile", select_overload<bool(const std::string&, const cocos2d::Rect&)>(&Sprite::initWithFile), allow_raw_pointers())
    .function("initWithFile", select_overload<bool(const std::string&)>(&Sprite::initWithFile), allow_raw_pointers())
    .function("getTextureAtlas", &Sprite::getTextureAtlas, allow_raw_pointers())
    .function("initWithSpriteFrame", &Sprite::initWithSpriteFrame, allow_raw_pointers())
    .function("isFlippedY", &Sprite::isFlippedY, allow_raw_pointers())
    .function("setVertexRect", &Sprite::setVertexRect, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Sprite>, allow_raw_pointers())
    .property("_className",  optional_override([](const Sprite& _) -> std::string {return "Sprite";}))    
    // TODO: assign cc.Class.extend to cc.Sprite.extend
    ;


  class_<RenderTexture, base<Node>>("cc.RenderTexture")
    .constructor<>()
    .function("setVirtualViewport", &RenderTexture::setVirtualViewport, allow_raw_pointers())
    .function("clearStencil", &RenderTexture::clearStencil, allow_raw_pointers())
    .function("getClearDepth", &RenderTexture::getClearDepth, allow_raw_pointers())
    .function("getClearStencil", &RenderTexture::getClearStencil, allow_raw_pointers())
    .function("end", &RenderTexture::end, allow_raw_pointers())
    .function("setClearStencil", &RenderTexture::setClearStencil, allow_raw_pointers())
    .function("setSprite", &RenderTexture::setSprite, allow_raw_pointers())
    .function("getSprite", &RenderTexture::getSprite, allow_raw_pointers())
    .function("isAutoDraw", &RenderTexture::isAutoDraw, allow_raw_pointers())
    .function("setKeepMatrix", &RenderTexture::setKeepMatrix, allow_raw_pointers())
    .function("setClearFlags", &RenderTexture::setClearFlags, allow_raw_pointers())
    .function("begin", &RenderTexture::begin, allow_raw_pointers())
    .function("setAutoDraw", &RenderTexture::setAutoDraw, allow_raw_pointers())
    .function("setClearColor", &RenderTexture::setClearColor, allow_raw_pointers())
    .function("beginWithClear", select_overload<void(float, float, float, float, float)>(&RenderTexture::beginWithClear), allow_raw_pointers())
    .function("beginWithClear", select_overload<void(float, float, float, float)>(&RenderTexture::beginWithClear), allow_raw_pointers())
    .function("beginWithClear", select_overload<void(float, float, float, float, float, int)>(&RenderTexture::beginWithClear), allow_raw_pointers())
    .function("newImage", &RenderTexture::newImage, allow_raw_pointers())
    .function("newImage", optional_override(
        [](RenderTexture& this_){
        return this_.newImage();
      }), allow_raw_pointers())
    .function("clearDepth", &RenderTexture::clearDepth, allow_raw_pointers())
    .function("getClearColor", &RenderTexture::getClearColor, allow_raw_pointers())
    .function("clear", &RenderTexture::clear, allow_raw_pointers())
    .function("getClearFlags", &RenderTexture::getClearFlags, allow_raw_pointers())
    .function("setClearDepth", &RenderTexture::setClearDepth, allow_raw_pointers())
    .function("initWithWidthAndHeight", select_overload<bool(int, int, cocos2d::Texture2D::PixelFormat, unsigned int)>(&RenderTexture::initWithWidthAndHeight), allow_raw_pointers())
    .function("initWithWidthAndHeight", select_overload<bool(int, int, cocos2d::Texture2D::PixelFormat)>(&RenderTexture::initWithWidthAndHeight), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RenderTexture>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int, cocos2d::Texture2D::PixelFormat)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int, cocos2d::Texture2D::PixelFormat, unsigned int)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int)>(&RenderTexture::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RenderTexture& _) -> std::string {return "RenderTexture";}))    
    // TODO: assign cc.Class.extend to cc.RenderTexture.extend
    ;

  class_<TransitionEaseScene>("cc.TransitionEaseScene")
    .function("easeActionWithAction", &TransitionEaseScene::easeActionWithAction, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionEaseScene& _) -> std::string {return "TransitionEaseScene";}))    
    ;


  class_<TransitionScene, base<Scene>>("cc.TransitionScene")
    .constructor<>()
    .function("getInScene", &TransitionScene::getInScene, allow_raw_pointers())
    .function("finish", &TransitionScene::finish, allow_raw_pointers())
    .function("initWithDuration", &TransitionScene::initWithDuration, allow_raw_pointers())
    .function("getDuration", &TransitionScene::getDuration, allow_raw_pointers())
    .function("hideOutShowIn", &TransitionScene::hideOutShowIn, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionScene>, allow_raw_pointers())
    .class_function("create", &TransitionScene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionScene& _) -> std::string {return "TransitionScene";}))    
    // TODO: assign cc.Class.extend to cc.TransitionScene.extend
    ;


  class_<TransitionSceneOriented, base<TransitionScene>>("cc.TransitionSceneOriented")
    .constructor<>()
    .function("initWithDuration", &TransitionSceneOriented::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSceneOriented>, allow_raw_pointers())
    .class_function("create", &TransitionSceneOriented::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSceneOriented& _) -> std::string {return "TransitionSceneOriented";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSceneOriented.extend
    ;


  class_<TransitionRotoZoom, base<TransitionScene>>("cc.TransitionRotoZoom")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionRotoZoom>, allow_raw_pointers())
    .class_function("create", &TransitionRotoZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionRotoZoom& _) -> std::string {return "TransitionRotoZoom";}))    
    // TODO: assign cc.Class.extend to cc.TransitionRotoZoom.extend
    ;


  class_<TransitionJumpZoom, base<TransitionScene>>("cc.TransitionJumpZoom")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionJumpZoom>, allow_raw_pointers())
    .class_function("create", &TransitionJumpZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionJumpZoom& _) -> std::string {return "TransitionJumpZoom";}))    
    // TODO: assign cc.Class.extend to cc.TransitionJumpZoom.extend
    ;


  class_<TransitionMoveInL, base<TransitionScene>>("cc.TransitionMoveInL")
    .constructor<>()
    .function("action", &TransitionMoveInL::action, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionMoveInL>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInL& _) -> std::string {return "TransitionMoveInL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInL.extend
    ;


  class_<TransitionMoveInR, base<TransitionMoveInL>>("cc.TransitionMoveInR")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInR>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInR& _) -> std::string {return "TransitionMoveInR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInR.extend
    ;


  class_<TransitionMoveInT, base<TransitionMoveInL>>("cc.TransitionMoveInT")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInT>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInT& _) -> std::string {return "TransitionMoveInT";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInT.extend
    ;


  class_<TransitionMoveInB, base<TransitionMoveInL>>("cc.TransitionMoveInB")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInB>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInB& _) -> std::string {return "TransitionMoveInB";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInB.extend
    ;


  class_<TransitionSlideInL, base<TransitionScene>>("cc.TransitionSlideInL")
    .constructor<>()
    .function("action", &TransitionSlideInL::action, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSlideInL>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInL& _) -> std::string {return "TransitionSlideInL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInL.extend
    ;


  class_<TransitionSlideInR, base<TransitionSlideInL>>("cc.TransitionSlideInR")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInR>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInR& _) -> std::string {return "TransitionSlideInR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInR.extend
    ;


  class_<TransitionSlideInB, base<TransitionSlideInL>>("cc.TransitionSlideInB")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInB>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInB& _) -> std::string {return "TransitionSlideInB";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInB.extend
    ;


  class_<TransitionSlideInT, base<TransitionSlideInL>>("cc.TransitionSlideInT")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInT>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInT& _) -> std::string {return "TransitionSlideInT";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInT.extend
    ;


  class_<TransitionShrinkGrow, base<TransitionScene>>("cc.TransitionShrinkGrow")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionShrinkGrow>, allow_raw_pointers())
    .class_function("create", &TransitionShrinkGrow::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionShrinkGrow& _) -> std::string {return "TransitionShrinkGrow";}))    
    // TODO: assign cc.Class.extend to cc.TransitionShrinkGrow.extend
    ;


  class_<TransitionFlipX, base<TransitionSceneOriented>>("cc.TransitionFlipX")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipX*(float, cocos2d::Scene*)>(&TransitionFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipX*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipX& _) -> std::string {return "TransitionFlipX";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipX.extend
    ;


  class_<TransitionFlipY, base<TransitionSceneOriented>>("cc.TransitionFlipY")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipY*(float, cocos2d::Scene*)>(&TransitionFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipY*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipY& _) -> std::string {return "TransitionFlipY";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipY.extend
    ;


  class_<TransitionFlipAngular, base<TransitionSceneOriented>>("cc.TransitionFlipAngular")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipAngular*(float, cocos2d::Scene*)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipAngular*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipAngular& _) -> std::string {return "TransitionFlipAngular";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipAngular.extend
    ;


  class_<TransitionZoomFlipX, base<TransitionSceneOriented>>("cc.TransitionZoomFlipX")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipX*(float, cocos2d::Scene*)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipX*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipX& _) -> std::string {return "TransitionZoomFlipX";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipX.extend
    ;


  class_<TransitionZoomFlipY, base<TransitionSceneOriented>>("cc.TransitionZoomFlipY")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipY*(float, cocos2d::Scene*)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipY*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipY& _) -> std::string {return "TransitionZoomFlipY";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipY.extend
    ;


  class_<TransitionZoomFlipAngular, base<TransitionSceneOriented>>("cc.TransitionZoomFlipAngular")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipAngular*(float, cocos2d::Scene*)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipAngular*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipAngular& _) -> std::string {return "TransitionZoomFlipAngular";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipAngular.extend
    ;


  class_<TransitionFade, base<TransitionScene>>("cc.TransitionFade")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, cocos2d::Scene*)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, cocos2d::Scene*, const cocos2d::Color3B&)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionFade>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFade*(float, cocos2d::Scene*)>(&TransitionFade::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFade*(float, cocos2d::Scene*, const cocos2d::Color3B&)>(&TransitionFade::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFade& _) -> std::string {return "TransitionFade";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFade.extend
    ;


  class_<TransitionCrossFade, base<TransitionScene>>("cc.TransitionCrossFade")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionCrossFade>, allow_raw_pointers())
    .class_function("create", &TransitionCrossFade::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionCrossFade& _) -> std::string {return "TransitionCrossFade";}))    
    // TODO: assign cc.Class.extend to cc.TransitionCrossFade.extend
    ;


  class_<TransitionTurnOffTiles, base<TransitionScene>>("cc.TransitionTurnOffTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionTurnOffTiles>, allow_raw_pointers())
    .class_function("create", &TransitionTurnOffTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionTurnOffTiles& _) -> std::string {return "TransitionTurnOffTiles";}))    
    // TODO: assign cc.Class.extend to cc.TransitionTurnOffTiles.extend
    ;


  class_<TransitionSplitCols, base<TransitionScene>>("cc.TransitionSplitCols")
    .constructor<>()
    .function("action", &TransitionSplitCols::action, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSplitCols>, allow_raw_pointers())
    .class_function("create", &TransitionSplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitCols& _) -> std::string {return "TransitionSplitCols";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSplitCols.extend
    ;


  class_<TransitionSplitRows, base<TransitionSplitCols>>("cc.TransitionSplitRows")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSplitRows>, allow_raw_pointers())
    .class_function("create", &TransitionSplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitRows& _) -> std::string {return "TransitionSplitRows";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSplitRows.extend
    ;


  class_<TransitionFadeTR, base<TransitionScene>>("cc.TransitionFadeTR")
    .constructor<>()
    .function("actionWithSize", &TransitionFadeTR::actionWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionFadeTR>, allow_raw_pointers())
    .class_function("create", &TransitionFadeTR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeTR& _) -> std::string {return "TransitionFadeTR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeTR.extend
    ;


  class_<TransitionFadeBL, base<TransitionFadeTR>>("cc.TransitionFadeBL")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeBL>, allow_raw_pointers())
    .class_function("create", &TransitionFadeBL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeBL& _) -> std::string {return "TransitionFadeBL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeBL.extend
    ;


  class_<TransitionFadeUp, base<TransitionFadeTR>>("cc.TransitionFadeUp")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeUp>, allow_raw_pointers())
    .class_function("create", &TransitionFadeUp::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeUp& _) -> std::string {return "TransitionFadeUp";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeUp.extend
    ;


  class_<TransitionFadeDown, base<TransitionFadeTR>>("cc.TransitionFadeDown")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeDown>, allow_raw_pointers())
    .class_function("create", &TransitionFadeDown::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeDown& _) -> std::string {return "TransitionFadeDown";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeDown.extend
    ;


  class_<TransitionPageTurn, base<TransitionScene>>("cc.TransitionPageTurn")
    .constructor<>()
    .function("initWithDuration", &TransitionPageTurn::initWithDuration, allow_raw_pointers())
    .function("actionWithSize", &TransitionPageTurn::actionWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionPageTurn>, allow_raw_pointers())
    .class_function("create", &TransitionPageTurn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionPageTurn& _) -> std::string {return "TransitionPageTurn";}))    
    // TODO: assign cc.Class.extend to cc.TransitionPageTurn.extend
    ;


  class_<TransitionProgress, base<TransitionScene>>("cc.TransitionProgress")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgress>, allow_raw_pointers())
    .class_function("create", &TransitionProgress::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgress& _) -> std::string {return "TransitionProgress";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgress.extend
    ;


  class_<TransitionProgressRadialCCW, base<TransitionProgress>>("cc.TransitionProgressRadialCCW")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressRadialCCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCCW& _) -> std::string {return "TransitionProgressRadialCCW";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressRadialCCW.extend
    ;


  class_<TransitionProgressRadialCW, base<TransitionProgress>>("cc.TransitionProgressRadialCW")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressRadialCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCW& _) -> std::string {return "TransitionProgressRadialCW";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressRadialCW.extend
    ;


  class_<TransitionProgressHorizontal, base<TransitionProgress>>("cc.TransitionProgressHorizontal")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressHorizontal>, allow_raw_pointers())
    .class_function("create", &TransitionProgressHorizontal::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressHorizontal& _) -> std::string {return "TransitionProgressHorizontal";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressHorizontal.extend
    ;


  class_<TransitionProgressVertical, base<TransitionProgress>>("cc.TransitionProgressVertical")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressVertical>, allow_raw_pointers())
    .class_function("create", &TransitionProgressVertical::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressVertical& _) -> std::string {return "TransitionProgressVertical";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressVertical.extend
    ;


  class_<TransitionProgressInOut, base<TransitionProgress>>("cc.TransitionProgressInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressInOut>, allow_raw_pointers())
    .class_function("create", &TransitionProgressInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressInOut& _) -> std::string {return "TransitionProgressInOut";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressInOut.extend
    ;


  class_<TransitionProgressOutIn, base<TransitionProgress>>("cc.TransitionProgressOutIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressOutIn>, allow_raw_pointers())
    .class_function("create", &TransitionProgressOutIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressOutIn& _) -> std::string {return "TransitionProgressOutIn";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressOutIn.extend
    ;


  class_<Camera, base<Node>>("cc.Camera")
    .constructor<>()
    .function("restore", &Camera::restore, allow_raw_pointers())
    .function("getDepth", &Camera::getDepth, allow_raw_pointers())
    .function("getViewProjectionMatrix", &Camera::getViewProjectionMatrix, allow_raw_pointers())
    .function("applyViewport", &Camera::applyViewport, allow_raw_pointers())
    .function("setBackgroundBrush", &Camera::setBackgroundBrush, allow_raw_pointers())
    .function("lookAt", &Camera::lookAt, allow_raw_pointers())
    .function("lookAt", optional_override(
        [](Camera& this_, const cocos2d::Vec3& arg0){
        return this_.lookAt(arg0);
      }), allow_raw_pointers())
    .function("apply", &Camera::apply, allow_raw_pointers())
    .function("getBackgroundBrush", &Camera::getBackgroundBrush, allow_raw_pointers())
    .function("getProjectionMatrix", &Camera::getProjectionMatrix, allow_raw_pointers())
    .function("isBrushValid", &Camera::isBrushValid, allow_raw_pointers())
    .function("getDepthInView", &Camera::getDepthInView, allow_raw_pointers())
    .function("restoreViewport", &Camera::restoreViewport, allow_raw_pointers())
    .function("clearBackground", &Camera::clearBackground, allow_raw_pointers())
    .function("setAdditionalProjection", &Camera::setAdditionalProjection, allow_raw_pointers())
    .function("setViewport", &Camera::setViewport, allow_raw_pointers())
    .function("initDefault", &Camera::initDefault, allow_raw_pointers())
    .function("getCameraFlag", &Camera::getCameraFlag, allow_raw_pointers())
    .function("getType", &Camera::getType, allow_raw_pointers())
    .function("initOrthographic", &Camera::initOrthographic, allow_raw_pointers())
    .function("getRenderOrder", &Camera::getRenderOrder, allow_raw_pointers())
    .function("setDepth", &Camera::setDepth, allow_raw_pointers())
    .function("setScene", &Camera::setScene, allow_raw_pointers())
    .function("projectGL", &Camera::projectGL, allow_raw_pointers())
    .function("restoreFrameBufferObject", &Camera::restoreFrameBufferObject, allow_raw_pointers())
    .function("getViewMatrix", &Camera::getViewMatrix, allow_raw_pointers())
    .function("getNearPlane", &Camera::getNearPlane, allow_raw_pointers())
    .function("project", &Camera::project, allow_raw_pointers())
    .function("setCameraFlag", &Camera::setCameraFlag, allow_raw_pointers())
    .function("getFarPlane", &Camera::getFarPlane, allow_raw_pointers())
    .function("applyFrameBufferObject", &Camera::applyFrameBufferObject, allow_raw_pointers())
    .function("setFrameBufferObject", &Camera::setFrameBufferObject, allow_raw_pointers())
    .function("isViewProjectionUpdated", &Camera::isViewProjectionUpdated, allow_raw_pointers())
    .function("initPerspective", &Camera::initPerspective, allow_raw_pointers())
    .class_function("createOrthographic", &Camera::createOrthographic, allow_raw_pointers())
    .class_function("getVisitingCamera", &Camera::getVisitingCamera, allow_raw_pointers())
    .class_function("create", &Camera::create, allow_raw_pointers())
    .class_function("createPerspective", &Camera::createPerspective, allow_raw_pointers())
    .class_function("getDefaultViewport", &Camera::getDefaultViewport, allow_raw_pointers())
    .class_function("setDefaultViewport", &Camera::setDefaultViewport, allow_raw_pointers())
    .class_function("getDefaultCamera", &Camera::getDefaultCamera, allow_raw_pointers())
    .property("_className",  optional_override([](const Camera& _) -> std::string {return "Camera";}))    
    ;


  class_<CameraBackgroundBrush>("cc.CameraBackgroundBrush")
    .constructor<>()
    .function("getBrushType", &CameraBackgroundBrush::getBrushType, allow_raw_pointers())
    .function("drawBackground", &CameraBackgroundBrush::drawBackground, allow_raw_pointers())
    .function("init", &CameraBackgroundBrush::init, allow_raw_pointers())
    .function("isValid", &CameraBackgroundBrush::isValid, allow_raw_pointers())
    .class_function("createSkyboxBrush", &CameraBackgroundBrush::createSkyboxBrush, allow_raw_pointers())
    .class_function("createColorBrush", &CameraBackgroundBrush::createColorBrush, allow_raw_pointers())
    .class_function("createNoneBrush", &CameraBackgroundBrush::createNoneBrush, allow_raw_pointers())
    .class_function("createDepthBrush", &CameraBackgroundBrush::createDepthBrush, allow_raw_pointers())
    .class_function("createDepthBrush", optional_override(
      [](){
        return CameraBackgroundBrush::createDepthBrush();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundBrush& _) -> std::string {return "CameraBackgroundBrush";}))    
    ;


  class_<CameraBackgroundDepthBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundDepthBrush")
    .constructor<>()
    .function("setDepth", &CameraBackgroundDepthBrush::setDepth, allow_raw_pointers())
    .class_function("create", &CameraBackgroundDepthBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundDepthBrush& _) -> std::string {return "CameraBackgroundDepthBrush";}))    
    ;


  class_<CameraBackgroundColorBrush, base<CameraBackgroundDepthBrush>>("cc.CameraBackgroundColorBrush")
    .constructor<>()
    .function("setColor", &CameraBackgroundColorBrush::setColor, allow_raw_pointers())
    .class_function("create", &CameraBackgroundColorBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundColorBrush& _) -> std::string {return "CameraBackgroundColorBrush";}))    
    ;


  class_<CameraBackgroundSkyBoxBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundSkyBoxBrush")
    .constructor<>()
    .function("setTexture", &CameraBackgroundSkyBoxBrush::setTexture, allow_raw_pointers())
    .function("isActived", &CameraBackgroundSkyBoxBrush::isActived, allow_raw_pointers())
    .function("setTextureValid", &CameraBackgroundSkyBoxBrush::setTextureValid, allow_raw_pointers())
    .function("setActived", &CameraBackgroundSkyBoxBrush::setActived, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::CameraBackgroundSkyBoxBrush*()>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::CameraBackgroundSkyBoxBrush*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundSkyBoxBrush& _) -> std::string {return "CameraBackgroundSkyBoxBrush";}))    
    ;

  class_<GridBase>("cc.GridBase")
    .function("setGridSize", &GridBase::setGridSize, allow_raw_pointers())
    .function("setGridRect", &GridBase::setGridRect, allow_raw_pointers())
    .function("afterBlit", &GridBase::afterBlit, allow_raw_pointers())
    .function("getGridRect", &GridBase::getGridRect, allow_raw_pointers())
    .function("afterDraw", &GridBase::afterDraw, allow_raw_pointers())
    .function("beforeDraw", &GridBase::beforeDraw, allow_raw_pointers())
    .function("calculateVertexPoints", &GridBase::calculateVertexPoints, allow_raw_pointers())
    .function("isTextureFlipped", &GridBase::isTextureFlipped, allow_raw_pointers())
    .function("getGridSize", &GridBase::getGridSize, allow_raw_pointers())
    .function("getStep", &GridBase::getStep, allow_raw_pointers())
    .function("set2DProjection", &GridBase::set2DProjection, allow_raw_pointers())
    .function("setStep", &GridBase::setStep, allow_raw_pointers())
    .function("setTextureFlipped", &GridBase::setTextureFlipped, allow_raw_pointers())
    .function("blit", &GridBase::blit, allow_raw_pointers())
    .function("setActive", &GridBase::setActive, allow_raw_pointers())
    .function("getReuseGrid", &GridBase::getReuseGrid, allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, const cocos2d::Rect&)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const cocos2d::Size&)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("beforeBlit", &GridBase::beforeBlit, allow_raw_pointers())
    .function("setReuseGrid", &GridBase::setReuseGrid, allow_raw_pointers())
    .function("isActive", &GridBase::isActive, allow_raw_pointers())
    .function("reuse", &GridBase::reuse, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::GridBase*(const cocos2d::Size&)>(&GridBase::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::GridBase*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&GridBase::create), allow_raw_pointers())
    .property("_className",  optional_override([](const GridBase& _) -> std::string {return "GridBase";}))    
    // TODO: assign cc.Class.extend to cc.GridBase.extend
    ;


  class_<Grid3D, base<GridBase>>("cc.Grid3D")
    .constructor<>()
    .function("getNeedDepthTestForBlit", &Grid3D::getNeedDepthTestForBlit, allow_raw_pointers())
    .function("setNeedDepthTestForBlit", &Grid3D::setNeedDepthTestForBlit, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Grid3D>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, const cocos2d::Rect&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&Grid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Grid3D& _) -> std::string {return "Grid3D";}))    
    // TODO: assign cc.Class.extend to cc.Grid3D.extend
    ;


  class_<TiledGrid3D, base<GridBase>>("cc.TiledGrid3D")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TiledGrid3D>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, const cocos2d::Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TiledGrid3D& _) -> std::string {return "TiledGrid3D";}))    
    // TODO: assign cc.Class.extend to cc.TiledGrid3D.extend
    ;

  class_<BaseLight, base<Node>>("cc.BaseLight")
    .function("setEnabled", &BaseLight::setEnabled, allow_raw_pointers())
    .function("getIntensity", &BaseLight::getIntensity, allow_raw_pointers())
    .function("isEnabled", &BaseLight::isEnabled, allow_raw_pointers())
    .function("getLightType", &BaseLight::getLightType, allow_raw_pointers())
    .function("setLightFlag", &BaseLight::setLightFlag, allow_raw_pointers())
    .function("setIntensity", &BaseLight::setIntensity, allow_raw_pointers())
    .function("getLightFlag", &BaseLight::getLightFlag, allow_raw_pointers())
    .property("_className",  optional_override([](const BaseLight& _) -> std::string {return "BaseLight";}))    
    ;


  class_<DirectionLight, base<BaseLight>>("cc.DirectionLight")
    .constructor<>()
    .function("getDirection", &DirectionLight::getDirection, allow_raw_pointers())
    .function("getDirectionInWorld", &DirectionLight::getDirectionInWorld, allow_raw_pointers())
    .function("setDirection", &DirectionLight::setDirection, allow_raw_pointers())
    .class_function("create", &DirectionLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DirectionLight& _) -> std::string {return "DirectionLight";}))    
    ;


  class_<PointLight, base<BaseLight>>("cc.PointLight")
    .constructor<>()
    .function("getRange", &PointLight::getRange, allow_raw_pointers())
    .function("setRange", &PointLight::setRange, allow_raw_pointers())
    .class_function("create", &PointLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PointLight& _) -> std::string {return "PointLight";}))    
    ;


  class_<SpotLight, base<BaseLight>>("cc.SpotLight")
    .constructor<>()
    .function("getRange", &SpotLight::getRange, allow_raw_pointers())
    .function("setDirection", &SpotLight::setDirection, allow_raw_pointers())
    .function("getCosInnerAngle", &SpotLight::getCosInnerAngle, allow_raw_pointers())
    .function("getOuterAngle", &SpotLight::getOuterAngle, allow_raw_pointers())
    .function("getInnerAngle", &SpotLight::getInnerAngle, allow_raw_pointers())
    .function("getDirection", &SpotLight::getDirection, allow_raw_pointers())
    .function("getCosOuterAngle", &SpotLight::getCosOuterAngle, allow_raw_pointers())
    .function("setOuterAngle", &SpotLight::setOuterAngle, allow_raw_pointers())
    .function("setInnerAngle", &SpotLight::setInnerAngle, allow_raw_pointers())
    .function("getDirectionInWorld", &SpotLight::getDirectionInWorld, allow_raw_pointers())
    .function("setRange", &SpotLight::setRange, allow_raw_pointers())
    .class_function("create", &SpotLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SpotLight& _) -> std::string {return "SpotLight";}))    
    ;


  class_<AmbientLight, base<BaseLight>>("cc.AmbientLight")
    .constructor<>()
    .class_function("create", &AmbientLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AmbientLight& _) -> std::string {return "AmbientLight";}))    
    ;


  class_<GLProgram>("cc.GLProgram")
    .constructor<>()
    .function("getFragmentShaderLog", &GLProgram::getFragmentShaderLog, allow_raw_pointers())
    .function("addAttribute", select_overload<void(const std::string&, unsigned int) const>(&GLProgram::bindAttribLocation), allow_raw_pointers())
    .function("getUniformFlags", &GLProgram::getUniformFlags, allow_raw_pointers())
    .function("getUniformLocationForName", &GLProgram::getUniformLocationForName, allow_raw_pointers())
    .function("use", &GLProgram::use, allow_raw_pointers())
    .function("getVertexShaderLog", &GLProgram::getVertexShaderLog, allow_raw_pointers())
    .function("getUniform", &GLProgram::getUniform, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*, const std::string&, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("setUniformLocationWith1f", &GLProgram::setUniformLocationWith1f, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("setUniformLocationWith3f", &GLProgram::setUniformLocationWith3f, allow_raw_pointers())
    .function("setUniformsForBuiltins", select_overload<void()>(&GLProgram::setUniformsForBuiltins), allow_raw_pointers())
    .function("setUniformsForBuiltins", select_overload<void(const cocos2d::Mat4&)>(&GLProgram::setUniformsForBuiltins), allow_raw_pointers())
    .function("setUniformLocationWith3i", &GLProgram::setUniformLocationWith3i, allow_raw_pointers())
    .function("setUniformLocationWith4f", &GLProgram::setUniformLocationWith4f, allow_raw_pointers())
    .function("updateUniforms", &GLProgram::updateUniforms, allow_raw_pointers())
    .function("getUniformLocation", &GLProgram::getUniformLocation, allow_raw_pointers())
    .function("link", &GLProgram::link, allow_raw_pointers())
    .function("reset", &GLProgram::reset, allow_raw_pointers())
    .function("getAttribLocation", &GLProgram::getAttribLocation, allow_raw_pointers())
    .function("getVertexAttrib", &GLProgram::getVertexAttrib, allow_raw_pointers())
    .function("setUniformLocationWith2f", &GLProgram::setUniformLocationWith2f, allow_raw_pointers())
    .function("setUniformLocationWith4i", &GLProgram::setUniformLocationWith4i, allow_raw_pointers())
    .function("setUniformLocationI32", &GLProgram::setUniformLocationWith1i, allow_raw_pointers())
    .function("setUniformLocationWith2i", &GLProgram::setUniformLocationWith2i, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<GLProgram>, allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*, const std::string&, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgram& _) -> std::string {return "GLProgram";}))    
    // TODO: assign cc.Class.extend to cc.GLProgram.extend
    ;


  class_<GLProgramCache>("cc.ShaderCache")
    .constructor<>()
    .function("loadDefaultShaders", select_overload<void()>(&GLProgramCache::loadDefaultGLPrograms), allow_raw_pointers())
    .function("reloadDefaultGLProgramsRelativeToLights", &GLProgramCache::reloadDefaultGLProgramsRelativeToLights, allow_raw_pointers())
    .function("addProgram", select_overload<void(cocos2d::GLProgram*, const std::string&)>(&GLProgramCache::addGLProgram), allow_raw_pointers())
    .function("reloadDefaultShaders", select_overload<void()>(&GLProgramCache::reloadDefaultGLPrograms), allow_raw_pointers())
    .function("getProgram", select_overload<cocos2d::GLProgram*(const std::string&)>(&GLProgramCache::getGLProgram), allow_raw_pointers())
    .class_function("destroyInstance", &GLProgramCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &GLProgramCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramCache& _) -> std::string {return "GLProgramCache";}))    
    ;


  class_<RenderState>("cc.RenderState")
    .constructor<>()
    .function("setTexture", &RenderState::setTexture, allow_raw_pointers())
    .function("getTopmost", &RenderState::getTopmost, allow_raw_pointers())
    .function("getTexture", &RenderState::getTexture, allow_raw_pointers())
    .function("bind", &RenderState::bind, allow_raw_pointers())
    .function("getName", &RenderState::getName, allow_raw_pointers())
    .function("getStateBlock", &RenderState::getStateBlock, allow_raw_pointers())
    .function("setParent", &RenderState::setParent, allow_raw_pointers())
    .class_function("initialize", &RenderState::initialize, allow_raw_pointers())
    .class_function("finalize", &RenderState::finalize, allow_raw_pointers())
    .property("_className",  optional_override([](const RenderState& _) -> std::string {return "RenderState";}))    
    ;


  class_<Pass, base<RenderState>>("cc.Pass")
    .constructor<>()
    .function("unbind", &Pass::unbind, allow_raw_pointers())
    .function("bind", select_overload<void(const cocos2d::Mat4&, bool)>(&Pass::bind), allow_raw_pointers())
    .function("bind", select_overload<void(const cocos2d::Mat4&)>(&Pass::bind), allow_raw_pointers())
    .function("clone", &Pass::clone, allow_raw_pointers())
    .function("getGLProgramState", &Pass::getGLProgramState, allow_raw_pointers())
    .function("getVertexAttributeBinding", &Pass::getVertexAttributeBinding, allow_raw_pointers())
    .function("getHash", &Pass::getHash, allow_raw_pointers())
    .function("setVertexAttribBinding", &Pass::setVertexAttribBinding, allow_raw_pointers())
    .class_function("create", &Pass::create, allow_raw_pointers())
    .class_function("createWithGLProgramState", &Pass::createWithGLProgramState, allow_raw_pointers())
    .property("_className",  optional_override([](const Pass& _) -> std::string {return "Pass";}))    
    ;


  class_<Technique, base<RenderState>>("cc.Technique")
    .constructor<>()
    .function("getPassCount", &Technique::getPassCount, allow_raw_pointers())
    .function("clone", &Technique::clone, allow_raw_pointers())
    .function("addPass", &Technique::addPass, allow_raw_pointers())
    .function("getPasses", &Technique::getPasses, allow_raw_pointers())
    .function("getName", &Technique::getName, allow_raw_pointers())
    .function("getPassByIndex", &Technique::getPassByIndex, allow_raw_pointers())
    .class_function("create", &Technique::create, allow_raw_pointers())
    .class_function("createWithGLProgramState", &Technique::createWithGLProgramState, allow_raw_pointers())
    .property("_className",  optional_override([](const Technique& _) -> std::string {return "Technique";}))    
    ;


  class_<Material, base<RenderState>>("cc.Material")
    .constructor<>()
    .function("clone", &Material::clone, allow_raw_pointers())
    .function("getTechniqueCount", &Material::getTechniqueCount, allow_raw_pointers())
    .function("setName", &Material::setName, allow_raw_pointers())
    .function("getTechniqueByIndex", &Material::getTechniqueByIndex, allow_raw_pointers())
    .function("getName", &Material::getName, allow_raw_pointers())
    .function("getTechniques", &Material::getTechniques, allow_raw_pointers())
    .function("setTechnique", &Material::setTechnique, allow_raw_pointers())
    .function("getTechniqueByName", &Material::getTechniqueByName, allow_raw_pointers())
    .function("addTechnique", &Material::addTechnique, allow_raw_pointers())
    .function("getTechnique", &Material::getTechnique, allow_raw_pointers())
    .class_function("createWithFilename", &Material::createWithFilename, allow_raw_pointers())
    .class_function("createWithGLStateProgram", &Material::createWithGLStateProgram, allow_raw_pointers())
    .class_function("createWithProperties", &Material::createWithProperties, allow_raw_pointers())
    .property("_className",  optional_override([](const Material& _) -> std::string {return "Material";}))    
    ;


  class_<TextureCache>("cc.TextureCache")
    .constructor<>()
    .function("reloadTexture", &TextureCache::reloadTexture, allow_raw_pointers())
    .function("removeAllTextures", &TextureCache::removeAllTextures, allow_raw_pointers())
    .function("unbindAllImageAsync", &TextureCache::unbindAllImageAsync, allow_raw_pointers())
    .function("removeTextureForKey", &TextureCache::removeTextureForKey, allow_raw_pointers())
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (cocos2d::Texture2D *)>&, const std::string&)>(&TextureCache::addImageAsync), allow_raw_pointers())
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (cocos2d::Texture2D *)>&)>(&TextureCache::addImageAsync), allow_raw_pointers())
    .function("getDescription", &TextureCache::getDescription, allow_raw_pointers())
    .function("getCachedTextureInfo", &TextureCache::getCachedTextureInfo, allow_raw_pointers())
    .function("addImage", select_overload<cocos2d::Texture2D*(cocos2d::Image*, const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("addImage", select_overload<cocos2d::Texture2D*(const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("unbindImageAsync", &TextureCache::unbindImageAsync, allow_raw_pointers())
    .function("getTextureForKey", &TextureCache::getTextureForKey, allow_raw_pointers())
    .function("getTextureFilePath", &TextureCache::getTextureFilePath, allow_raw_pointers())
    .function("renameTextureWithKey", &TextureCache::renameTextureWithKey, allow_raw_pointers())
    .function("removeUnusedTextures", &TextureCache::removeUnusedTextures, allow_raw_pointers())
    .function("removeTexture", &TextureCache::removeTexture, allow_raw_pointers())
    .function("waitForQuit", &TextureCache::waitForQuit, allow_raw_pointers())
    .class_function("setETC1AlphaFileSuffix", &TextureCache::setETC1AlphaFileSuffix, allow_raw_pointers())
    .class_function("getETC1AlphaFileSuffix", &TextureCache::getETC1AlphaFileSuffix, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureCache& _) -> std::string {return "TextureCache";}))    
    ;

  class_<Device>("cc.Device")
    .class_function("setAccelerometerEnabled", &Device::setAccelerometerEnabled, allow_raw_pointers())
    .class_function("setAccelerometerInterval", &Device::setAccelerometerInterval, allow_raw_pointers())
    .class_function("setKeepScreenOn", &Device::setKeepScreenOn, allow_raw_pointers())
    .class_function("vibrate", &Device::vibrate, allow_raw_pointers())
    .class_function("getDPI", &Device::getDPI, allow_raw_pointers())
    .property("_className",  optional_override([](const Device& _) -> std::string {return "Device";}))    
    ;

  class_<SAXParser>("cc.PlistParser")
    .function("init", &SAXParser::init, allow_raw_pointers())
    .property("_className",  optional_override([](const SAXParser& _) -> std::string {return "SAXParser";}))    
    ;

  class_<Application>("cc.Application")
    .class_function("getInstance", &Application::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Application& _) -> std::string {return "Application";}))    
    ;


  class_<AnimationCache>("cc.AnimationCache")
    .constructor<>()
    .function("getAnimation", &AnimationCache::getAnimation, allow_raw_pointers())
    .function("addAnimation", &AnimationCache::addAnimation, allow_raw_pointers())
    .function("addAnimationsWithDictionary", &AnimationCache::addAnimationsWithDictionary, allow_raw_pointers())
    .function("init", &AnimationCache::init, allow_raw_pointers())
    .function("removeAnimation", &AnimationCache::removeAnimation, allow_raw_pointers())
    .function("addAnimations", &AnimationCache::addAnimationsWithFile, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<AnimationCache>, allow_raw_pointers())
    .class_function("destroyInstance", &AnimationCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &AnimationCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationCache& _) -> std::string {return "AnimationCache";}))    
    // TODO: assign cc.Class.extend to cc.AnimationCache.extend
    ;


  class_<SpriteBatchNode, base<Node>>("cc.SpriteBatchNode")
    .constructor<>()
    .function("appendChild", &SpriteBatchNode::appendChild, allow_raw_pointers())
    .function("reorderBatch", &SpriteBatchNode::reorderBatch, allow_raw_pointers())
    .function("removeChildAtIndex", &SpriteBatchNode::removeChildAtIndex, allow_raw_pointers())
    .function("removeSpriteFromAtlas", &SpriteBatchNode::removeSpriteFromAtlas, allow_raw_pointers())
    .function("addSpriteWithoutQuad", &SpriteBatchNode::addSpriteWithoutQuad, allow_raw_pointers())
    .function("atlasIndexForChild", &SpriteBatchNode::atlasIndexForChild, allow_raw_pointers())
    .function("increaseAtlasCapacity", &SpriteBatchNode::increaseAtlasCapacity, allow_raw_pointers())
    .function("insertQuadFromSprite", &SpriteBatchNode::insertQuadFromSprite, allow_raw_pointers())
    .function("lowestAtlasIndexInChild", &SpriteBatchNode::lowestAtlasIndexInChild, allow_raw_pointers())
    .function("initWithTexture", &SpriteBatchNode::initWithTexture, allow_raw_pointers())
    .function("initWithTexture", optional_override(
        [](SpriteBatchNode& this_, cocos2d::Texture2D* arg0){
        return this_.initWithTexture(arg0);
      }), allow_raw_pointers())
    .function("setTextureAtlas", &SpriteBatchNode::setTextureAtlas, allow_raw_pointers())
    .function("reserveCapacity", &SpriteBatchNode::reserveCapacity, allow_raw_pointers())
    .function("initWithFile", &SpriteBatchNode::initWithFile, allow_raw_pointers())
    .function("initWithFile", optional_override(
        [](SpriteBatchNode& this_, const std::string& arg0){
        return this_.initWithFile(arg0);
      }), allow_raw_pointers())
    .function("rebuildIndexInOrder", &SpriteBatchNode::rebuildIndexInOrder, allow_raw_pointers())
    .function("getTextureAtlas", &SpriteBatchNode::getTextureAtlas, allow_raw_pointers())
    .function("highestAtlasIndexInChild", &SpriteBatchNode::highestAtlasIndexInChild, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SpriteBatchNode>, allow_raw_pointers())
    .class_function("create", &SpriteBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return SpriteBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &SpriteBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return SpriteBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteBatchNode& _) -> std::string {return "SpriteBatchNode";}))    
    // TODO: assign cc.Class.extend to cc.SpriteBatchNode.extend
    ;

  class_<SpriteFrameCache>("cc.SpriteFrameCache")
    .function("reloadTexture", &SpriteFrameCache::reloadTexture, allow_raw_pointers())
    .function("addSpriteFramesWithFileContent", &SpriteFrameCache::addSpriteFramesWithFileContent, allow_raw_pointers())
    .function("addSpriteFrame", &SpriteFrameCache::addSpriteFrame, allow_raw_pointers())
    .function("addSpriteFrames", select_overload<void(const std::string&, const std::string&)>(&SpriteFrameCache::addSpriteFramesWithFile), allow_raw_pointers())
    .function("addSpriteFrames", select_overload<void(const std::string&)>(&SpriteFrameCache::addSpriteFramesWithFile), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getSpriteFrame", &SpriteFrameCache::getSpriteFrameByName, allow_raw_pointers())
    .function("removeSpriteFramesFromFile", &SpriteFrameCache::removeSpriteFramesFromFile, allow_raw_pointers())
    .function("init", &SpriteFrameCache::init, allow_raw_pointers())
    .function("removeSpriteFrames", &SpriteFrameCache::removeSpriteFrames, allow_raw_pointers())
    .function("removeUnusedSpriteFrames", &SpriteFrameCache::removeUnusedSpriteFrames, allow_raw_pointers())
    .function("removeSpriteFramesFromFileContent", &SpriteFrameCache::removeSpriteFramesFromFileContent, allow_raw_pointers())
    .function("removeSpriteFrameByName", &SpriteFrameCache::removeSpriteFrameByName, allow_raw_pointers())
    .function("isSpriteFramesWithFileLoaded", &SpriteFrameCache::isSpriteFramesWithFileLoaded, allow_raw_pointers())
    .function("removeSpriteFramesFromTexture", &SpriteFrameCache::removeSpriteFramesFromTexture, allow_raw_pointers())
    .class_function("destroyInstance", &SpriteFrameCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &SpriteFrameCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrameCache& _) -> std::string {return "SpriteFrameCache";}))    
    ;


  class_<TextFieldTTF, base<Label>>("cc.TextFieldTTF")
    .constructor<>()
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder), allow_raw_pointers())
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const cocos2d::Size&, cocos2d::TextHAlignment, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder), allow_raw_pointers())
    .function("getPlaceHolder", &TextFieldTTF::getPlaceHolder, allow_raw_pointers())
    .function("isSecureTextEntry", &TextFieldTTF::isSecureTextEntry, allow_raw_pointers())
    .function("getPasswordTextStyle", &TextFieldTTF::getPasswordTextStyle, allow_raw_pointers())
    .function("setCursorPosition", &TextFieldTTF::setCursorPosition, allow_raw_pointers())
    .function("getCharCount", &TextFieldTTF::getCharCount, allow_raw_pointers())
    .function("getColorSpaceHolder", &TextFieldTTF::getColorSpaceHolder, allow_raw_pointers())
    .function("setColorSpaceHolder", select_overload<void(const cocos2d::Color4B&)>(&TextFieldTTF::setColorSpaceHolder), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("appendString", &TextFieldTTF::appendString, allow_raw_pointers())
    .function("setPlaceHolder", &TextFieldTTF::setPlaceHolder, allow_raw_pointers())
    .function("setCursorFromPoint", &TextFieldTTF::setCursorFromPoint, allow_raw_pointers())
    .function("setCursorChar", &TextFieldTTF::setCursorChar, allow_raw_pointers())
    .function("setPasswordTextStyle", &TextFieldTTF::setPasswordTextStyle, allow_raw_pointers())
    .function("setSecureTextEntry", &TextFieldTTF::setSecureTextEntry, allow_raw_pointers())
    .function("setCursorEnabled", &TextFieldTTF::setCursorEnabled, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TextFieldTTF>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TextFieldTTF*(const std::string&, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TextFieldTTF*(const std::string&, const cocos2d::Size&, cocos2d::TextHAlignment, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .property("_className",  optional_override([](const TextFieldTTF& _) -> std::string {return "TextFieldTTF";}))    
    // TODO: assign cc.Class.extend to cc.TextFieldTTF.extend
    ;


  class_<ParallaxNode, base<Node>>("cc.ParallaxNode")
    .constructor<>()
    .function("addChild", select_overload<void(cocos2d::Node*, int, const cocos2d::Vec2&, const cocos2d::Vec2&)>(&ParallaxNode::addChild), allow_raw_pointers())
    .function("getParallaxArray", select_overload<const cocos2d::_ccArray*() const>(&ParallaxNode::getParallaxArray), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setParallaxArray", &ParallaxNode::setParallaxArray, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ParallaxNode>, allow_raw_pointers())
    .class_function("create", &ParallaxNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ParallaxNode& _) -> std::string {return "ParallaxNode";}))    
    // TODO: assign cc.Class.extend to cc.ParallaxNode.extend
    ;


  class_<TMXObjectGroup>("cc.TMXObjectGroup")
    .constructor<>()
    .function("setPositionOffset", &TMXObjectGroup::setPositionOffset, allow_raw_pointers())
    .function("getProperty", &TMXObjectGroup::getProperty, allow_raw_pointers())
    .function("getPositionOffset", &TMXObjectGroup::getPositionOffset, allow_raw_pointers())
    .function("getObject", &TMXObjectGroup::getObject, allow_raw_pointers())
    .function("getObjects", select_overload<std::vector<cocos2d::Value>&()>(&TMXObjectGroup::getObjects), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setGroupName", &TMXObjectGroup::setGroupName, allow_raw_pointers())
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXObjectGroup::getProperties), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGroupName", &TMXObjectGroup::getGroupName, allow_raw_pointers())
    .function("setProperties", &TMXObjectGroup::setProperties, allow_raw_pointers())
    .function("setObjects", &TMXObjectGroup::setObjects, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXObjectGroup& _) -> std::string {return "TMXObjectGroup";}))    
    ;


  class_<TMXLayerInfo>("cc.TMXLayerInfo")
    .constructor<>()
    .function("setProperties", &TMXLayerInfo::setProperties, allow_raw_pointers())
    .function("getProperties", &TMXLayerInfo::getProperties, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXLayerInfo& _) -> std::string {return "TMXLayerInfo";}))    
    ;


  class_<TMXTilesetInfo>("cc.TMXTilesetInfo")
    .constructor<>()
    .function("getRectForGID", &TMXTilesetInfo::getRectForGID, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTilesetInfo& _) -> std::string {return "TMXTilesetInfo";}))    
    ;


  class_<TMXMapInfo>("cc.TMXMapInfo")
    .constructor<>()
    .function("setCurrentString", &TMXMapInfo::setCurrentString, allow_raw_pointers())
    .function("getHexSideLength", &TMXMapInfo::getHexSideLength, allow_raw_pointers())
    .function("setTileSize", &TMXMapInfo::setTileSize, allow_raw_pointers())
    .function("initWithTMXFile", &TMXMapInfo::initWithTMXFile, allow_raw_pointers())
    .function("getOrientation", &TMXMapInfo::getOrientation, allow_raw_pointers())
    .function("setObjectGroups", &TMXMapInfo::setObjectGroups, allow_raw_pointers())
    .function("setLayers", &TMXMapInfo::setLayers, allow_raw_pointers())
    .function("parseXMLFile", &TMXMapInfo::parseXMLFile, allow_raw_pointers())
    .function("getParentElement", &TMXMapInfo::getParentElement, allow_raw_pointers())
    .function("setTMXFileName", &TMXMapInfo::setTMXFileName, allow_raw_pointers())
    .function("parseXMLString", &TMXMapInfo::parseXMLString, allow_raw_pointers())
    .function("getLayers", select_overload<cocos2d::Vector<cocos2d::TMXLayerInfo *>&()>(&TMXMapInfo::getLayers), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerAxis", &TMXMapInfo::getStaggerAxis, allow_raw_pointers())
    .function("setHexSideLength", &TMXMapInfo::setHexSideLength, allow_raw_pointers())
    .function("getTilesets", select_overload<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&()>(&TMXMapInfo::getTilesets), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getParentGID", &TMXMapInfo::getParentGID, allow_raw_pointers())
    .function("setParentElement", &TMXMapInfo::setParentElement, allow_raw_pointers())
    .function("initWithXML", &TMXMapInfo::initWithXML, allow_raw_pointers())
    .function("setParentGID", &TMXMapInfo::setParentGID, allow_raw_pointers())
    .function("getLayerAttribs", &TMXMapInfo::getLayerAttribs, allow_raw_pointers())
    .function("getTileSize", &TMXMapInfo::getTileSize, allow_raw_pointers())
    .function("getTileProperties", &TMXMapInfo::getTileProperties, allow_raw_pointers())
    .function("isStoringCharacters", &TMXMapInfo::isStoringCharacters, allow_raw_pointers())
    .function("getExternalTilesetFileName", &TMXMapInfo::getExternalTilesetFileName, allow_raw_pointers())
    .function("getObjectGroups", select_overload<cocos2d::Vector<cocos2d::TMXObjectGroup *>&()>(&TMXMapInfo::getObjectGroups), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getTMXFileName", &TMXMapInfo::getTMXFileName, allow_raw_pointers())
    .function("setStaggerIndex", &TMXMapInfo::setStaggerIndex, allow_raw_pointers())
    .function("setProperties", &TMXMapInfo::setProperties, allow_raw_pointers())
    .function("setOrientation", &TMXMapInfo::setOrientation, allow_raw_pointers())
    .function("setTileProperties", &TMXMapInfo::setTileProperties, allow_raw_pointers())
    .function("setMapSize", &TMXMapInfo::setMapSize, allow_raw_pointers())
    .function("getCurrentString", &TMXMapInfo::getCurrentString, allow_raw_pointers())
    .function("setStoringCharacters", &TMXMapInfo::setStoringCharacters, allow_raw_pointers())
    .function("setStaggerAxis", &TMXMapInfo::setStaggerAxis, allow_raw_pointers())
    .function("getMapSize", &TMXMapInfo::getMapSize, allow_raw_pointers())
    .function("setTilesets", &TMXMapInfo::setTilesets, allow_raw_pointers())
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXMapInfo::getProperties), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerIndex", &TMXMapInfo::getStaggerIndex, allow_raw_pointers())
    .function("setLayerAttribs", &TMXMapInfo::setLayerAttribs, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TMXMapInfo>, allow_raw_pointers())
    .class_function("create", &TMXMapInfo::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXMapInfo::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXMapInfo& _) -> std::string {return "TMXMapInfo";}))    
    // TODO: assign cc.Class.extend to cc.TMXMapInfo.extend
    ;


  class_<TMXLayer, base<SpriteBatchNode>>("cc.TMXLayer")
    .constructor<>()
    .function("getTileGIDAt", &TMXLayer::getTileGIDAt, allow_raw_pointers())
    .function("getTileGIDAt", optional_override(
        [](TMXLayer& this_, const cocos2d::Vec2& arg0){
        return this_.getTileGIDAt(arg0);
      }), allow_raw_pointers())
    .function("getAnimTileCoord", &TMXLayer::getAnimTileCoord, allow_raw_pointers())
    .function("getPositionAt", &TMXLayer::getPositionAt, allow_raw_pointers())
    .function("setLayerOrientation", &TMXLayer::setLayerOrientation, allow_raw_pointers())
    .function("releaseMap", &TMXLayer::releaseMap, allow_raw_pointers())
    .function("hasTileAnimation", &TMXLayer::hasTileAnimation, allow_raw_pointers())
    .function("setTiles", &TMXLayer::setTiles, allow_raw_pointers())
    .function("getLayerSize", &TMXLayer::getLayerSize, allow_raw_pointers())
    .function("setMapTileSize", &TMXLayer::setMapTileSize, allow_raw_pointers())
    .function("getLayerOrientation", &TMXLayer::getLayerOrientation, allow_raw_pointers())
    .function("setProperties", &TMXLayer::setProperties, allow_raw_pointers())
    .function("setLayerName", &TMXLayer::setLayerName, allow_raw_pointers())
    .function("removeTileAt", &TMXLayer::removeTileAt, allow_raw_pointers())
    .function("initWithTilesetInfo", &TMXLayer::initWithTilesetInfo, allow_raw_pointers())
    .function("setupTiles", &TMXLayer::setupTiles, allow_raw_pointers())
    .function("setTileGID", select_overload<void(unsigned int, const cocos2d::Vec2&, cocos2d::TMXTileFlags_)>(&TMXLayer::setTileGID), allow_raw_pointers())
    .function("setTileGID", select_overload<void(unsigned int, const cocos2d::Vec2&)>(&TMXLayer::setTileGID), allow_raw_pointers())
    .function("getMapTileSize", &TMXLayer::getMapTileSize, allow_raw_pointers())
    .function("getProperty", &TMXLayer::getProperty, allow_raw_pointers())
    .function("setLayerSize", &TMXLayer::setLayerSize, allow_raw_pointers())
    .function("getLayerName", &TMXLayer::getLayerName, allow_raw_pointers())
    .function("setTileSet", &TMXLayer::setTileSet, allow_raw_pointers())
    .function("getTileSet", &TMXLayer::getTileSet, allow_raw_pointers())
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXLayer::getProperties), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getTileAt", &TMXLayer::getTileAt, allow_raw_pointers())
    .function("getTileAnimManager", &TMXLayer::getTileAnimManager, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TMXLayer>, allow_raw_pointers())
    .class_function("create", &TMXLayer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXLayer& _) -> std::string {return "TMXLayer";}))    
    // TODO: assign cc.Class.extend to cc.TMXLayer.extend
    ;


  class_<TMXTileAnimTask>("cc.TMXTileAnimTask")
    .constructor<cocos2d::TMXLayer*, cocos2d::TMXTileAnimInfo*, const cocos2d::Vec2&>()
    .function("start", &TMXTileAnimTask::start, allow_raw_pointers())
    .function("stop", &TMXTileAnimTask::stop, allow_raw_pointers())
    .function("isRunning", &TMXTileAnimTask::isRunning, allow_raw_pointers())
    .class_function("create", &TMXTileAnimTask::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimTask& _) -> std::string {return "TMXTileAnimTask";}))    
    ;


  class_<TMXTileAnimManager>("cc.TMXTileAnimManager")
    .constructor<cocos2d::TMXLayer*>()
    .function("getTasks", &TMXTileAnimManager::getTasks, allow_raw_pointers())
    .function("startAll", &TMXTileAnimManager::startAll, allow_raw_pointers())
    .function("stopAll", &TMXTileAnimManager::stopAll, allow_raw_pointers())
    .class_function("create", &TMXTileAnimManager::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimManager& _) -> std::string {return "TMXTileAnimManager";}))    
    ;


  class_<TMXTiledMap, base<Node>>("cc.TMXTiledMap")
    .constructor<>()
    .function("setObjectGroups", &TMXTiledMap::setObjectGroups, allow_raw_pointers())
    .function("setTileSize", &TMXTiledMap::setTileSize, allow_raw_pointers())
    .function("initWithXML", &TMXTiledMap::initWithXML, allow_raw_pointers())
    .function("getPropertiesForGID", select_overload<bool(int, cocos2d::Value**)>(&TMXTiledMap::getPropertiesForGID), allow_raw_pointers())
    .function("getPropertiesForGID", select_overload<cocos2d::Value(int) const>(&TMXTiledMap::getPropertiesForGID), allow_raw_pointers())
    .function("setMapOrientation", &TMXTiledMap::setMapOrientation, allow_raw_pointers())
    .function("initWithTMXFile", &TMXTiledMap::initWithTMXFile, allow_raw_pointers())
    .function("getLayerNum", &TMXTiledMap::getLayerNum, allow_raw_pointers())
    .function("setProperties", &TMXTiledMap::setProperties, allow_raw_pointers())
    .function("getLayer", &TMXTiledMap::getLayer, allow_raw_pointers())
    .function("getTileSize", &TMXTiledMap::getTileSize, allow_raw_pointers())
    .function("getObjectGroups", select_overload<cocos2d::Vector<cocos2d::TMXObjectGroup *>&()>(&TMXTiledMap::getObjectGroups), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getMapOrientation", &TMXTiledMap::getMapOrientation, allow_raw_pointers())
    .function("getProperty", &TMXTiledMap::getProperty, allow_raw_pointers())
    .function("setMapSize", &TMXTiledMap::setMapSize, allow_raw_pointers())
    .function("getObjectGroup", &TMXTiledMap::getObjectGroup, allow_raw_pointers())
    .function("getMapSize", &TMXTiledMap::getMapSize, allow_raw_pointers())
    .function("setTileAnimEnabled", &TMXTiledMap::setTileAnimEnabled, allow_raw_pointers())
    .function("getProperties", &TMXTiledMap::getProperties, allow_raw_pointers())
    .function("getResourceFile", &TMXTiledMap::getResourceFile, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TMXTiledMap>, allow_raw_pointers())
    .class_function("create", &TMXTiledMap::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXTiledMap::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTiledMap& _) -> std::string {return "TMXTiledMap";}))    
    // TODO: assign cc.Class.extend to cc.TMXTiledMap.extend
    ;


  class_<TileMapAtlas, base<AtlasNode>>("cc.TileMapAtlas")
    .constructor<>()
    .function("initWithTileFile", &TileMapAtlas::initWithTileFile, allow_raw_pointers())
    .function("releaseMap", &TileMapAtlas::releaseMap, allow_raw_pointers())
    .function("getTGAInfo", &TileMapAtlas::getTGAInfo, allow_raw_pointers())
    .function("getTileAt", &TileMapAtlas::getTileAt, allow_raw_pointers())
    .function("setTile", &TileMapAtlas::setTile, allow_raw_pointers())
    .function("setTGAInfo", &TileMapAtlas::setTGAInfo, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TileMapAtlas>, allow_raw_pointers())
    .class_function("create", &TileMapAtlas::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TileMapAtlas& _) -> std::string {return "TileMapAtlas";}))    
    // TODO: assign cc.Class.extend to cc.TileMapAtlas.extend
    ;

  class_<SimpleAudioEngine>("cc.AudioEngine")
    .function("preloadMusic", &SimpleAudioEngine::preloadBackgroundMusic, allow_raw_pointers())
    .function("stopMusic", &SimpleAudioEngine::stopBackgroundMusic, allow_raw_pointers())
    .function("stopMusic", optional_override(
        [](SimpleAudioEngine& this_){
        return this_.stopBackgroundMusic();
      }), allow_raw_pointers())
    .function("stopAllEffects", &SimpleAudioEngine::stopAllEffects, allow_raw_pointers())
    .function("getMusicVolume", &SimpleAudioEngine::getBackgroundMusicVolume, allow_raw_pointers())
    .function("resumeMusic", &SimpleAudioEngine::resumeBackgroundMusic, allow_raw_pointers())
    .function("setMusicVolume", &SimpleAudioEngine::setBackgroundMusicVolume, allow_raw_pointers())
    .function("preloadEffect", &SimpleAudioEngine::preloadEffect, allow_raw_pointers())
    .function("isMusicPlaying", &SimpleAudioEngine::isBackgroundMusicPlaying, allow_raw_pointers())
    .function("getEffectsVolume", &SimpleAudioEngine::getEffectsVolume, allow_raw_pointers())
    .function("willPlayMusic", &SimpleAudioEngine::willPlayBackgroundMusic, allow_raw_pointers())
    .function("pauseEffect", &SimpleAudioEngine::pauseEffect, allow_raw_pointers())
    .function("playEffect", &SimpleAudioEngine::playEffect, allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0){
        return this_.playEffect(arg0);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1){
        return this_.playEffect(arg0, arg1);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1, float arg2){
        return this_.playEffect(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1, float arg2, float arg3){
        return this_.playEffect(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("rewindMusic", &SimpleAudioEngine::rewindBackgroundMusic, allow_raw_pointers())
    .function("playMusic", &SimpleAudioEngine::playBackgroundMusic, allow_raw_pointers())
    .function("playMusic", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0){
        return this_.playBackgroundMusic(arg0);
      }), allow_raw_pointers())
    .function("resumeAllEffects", &SimpleAudioEngine::resumeAllEffects, allow_raw_pointers())
    .function("setEffectsVolume", &SimpleAudioEngine::setEffectsVolume, allow_raw_pointers())
    .function("stopEffect", &SimpleAudioEngine::stopEffect, allow_raw_pointers())
    .function("pauseMusic", &SimpleAudioEngine::pauseBackgroundMusic, allow_raw_pointers())
    .function("pauseAllEffects", &SimpleAudioEngine::pauseAllEffects, allow_raw_pointers())
    .function("unloadEffect", &SimpleAudioEngine::unloadEffect, allow_raw_pointers())
    .function("resumeEffect", &SimpleAudioEngine::resumeEffect, allow_raw_pointers())
    .class_function("end", &SimpleAudioEngine::end, allow_raw_pointers())
    .class_function("getInstance", &SimpleAudioEngine::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SimpleAudioEngine& _) -> std::string {return "SimpleAudioEngine";}))    
    ;

  class_<ComponentJS, base<Component>>("cc.ComponentJS")
    .property("_className",  optional_override([](const ComponentJS& _) -> std::string {return "ComponentJS";}))    
    ;}