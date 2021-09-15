#include "scripting/js-embind-bindings/manual/js_embind_cocos2dx_manual.hpp"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "scripting/js-bindings/manual/component/CCComponentJS.h"

#include <functional>
#include <emscripten/bind.h>

using namespace emscripten;
using namespace std;
using namespace std::placeholders;
using namespace cocos2d;

val Node_getChildren(const Node& node) {
    Vector<Node*> children = node.getChildren();
    
    auto begin = children.begin();
    auto end = children.end();

    val new_array = val::array();
    
    for (auto it = begin; it != end; ++it) {
        new_array.call<void>("push", val(*it));
    }

    return new_array;
}

val Node_getAnchorX(const Node& node) {
    return val(node.getAnchorPoint().x);
}

val Node_getAnchorY(const Node& node) {
    return val(node.getAnchorPoint().y);
}

void Node_setAnchorX(Node& node, const val& x) {
    node.setAnchorPoint(Vec2(x.as<float>(), node.getAnchorPoint().y));
}

void Node_setAnchorY(Node& node, const val& y) {
    node.setAnchorPoint(Vec2(node.getAnchorPoint().x, y.as<float>()));
}

val Node_getWidth(const Node& node) {
    return val(node.getContentSize().width);
}

val Node_getHeight(const Node& node) {
    return val(node.getContentSize().height);
}

void Node_setWidth(Node& node, const val& width) {
    node.setContentSize(Size(width.as<float>(), node.getContentSize().height));
}

void Node_setHeight(Node& node, const val& height) {
    node.setContentSize(Size(node.getContentSize().width, height.as<float>()));
}

Image* Image_createWithImageFile(const std::string& path) {
    Image *ret = new (std::nothrow) Image();
    if (ret && ret->initWithImageFile(path))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

Texture2D* Texture2D_createWithImage(Image * image) {
    Texture2D *ret = new (std::nothrow) Texture2D();
    if (ret && ret->initWithImage(image))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

template<typename T, bool R>
bool js_embind_getBool(const T& obj) {
  return R;
}

template<typename T>
bool js_embind_ctor(const T& obj) {
  return true;
}

template<typename T>
T* js_embind_constructor() {
  T *obj = new (std::nothrow) T();
  return obj;
}

EMSCRIPTEN_BINDINGS(js_embind_cocos2dx) {
  class_<GLProgram>("cc.GLProgram")
    .constructor(&js_embind_constructor<GLProgram>, allow_raw_pointers())
    .function("getFragmentShaderLog", &GLProgram::getFragmentShaderLog, allow_raw_pointers())
    .function("addAttribute", &GLProgram::bindAttribLocation, allow_raw_pointers())
    .function("getUniformFlags", &GLProgram::getUniformFlags, allow_raw_pointers())
    .function("getUniformLocationForName", &GLProgram::getUniformLocationForName, allow_raw_pointers())
    .function("use", &GLProgram::use, allow_raw_pointers())
    .function("getVertexShaderLog", &GLProgram::getVertexShaderLog, allow_raw_pointers())
    .function("getUniform", &GLProgram::getUniform, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const GLchar*, const GLchar*)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const GLchar*, const GLchar*, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const GLchar*, const GLchar*, const std::string&, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("setUniformLocationWith1f", &GLProgram::setUniformLocationWith1f, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames), allow_raw_pointers())
    .function("setUniformLocationWith3f", &GLProgram::setUniformLocationWith3f, allow_raw_pointers())
    .function("setUniformsForBuiltins", select_overload<void()>(&GLProgram::setUniformsForBuiltins), allow_raw_pointers())
    .function("setUniformsForBuiltins", select_overload<void(const Mat4 &)>(&GLProgram::setUniformsForBuiltins), allow_raw_pointers())
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
    .function("ctor", &js_embind_ctor<GLProgram>, allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<GLProgram*(const GLchar*, const GLchar*)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<GLProgram*(const GLchar*, const GLchar*, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<GLProgram*(const GLchar*, const GLchar*, const std::string&, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgram& _) -> std::string {return "GLProgram";}))
    .property("__nativeObj", &js_embind_getBool<GLProgram, true>)
    .property("__is_ref", &js_embind_getBool<GLProgram, true>)
    ;
  class_<Texture2D>("cc.Texture2D")
    .constructor(&js_embind_constructor<Texture2D>, allow_raw_pointers())
    .function("getShaderProgram", &Texture2D::getGLProgram, allow_raw_pointers())
    .function("getMaxT", &Texture2D::getMaxT, allow_raw_pointers())
    .function("setAlphaTexture", &Texture2D::setAlphaTexture, allow_raw_pointers())
    .function("getStringForFormat", &Texture2D::getStringForFormat, allow_raw_pointers())
    .function("initWithImage", select_overload<bool(Image * image)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("initWithImage", select_overload<bool(Image * image, Texture2D::PixelFormat format)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("setShaderProgram", &Texture2D::setGLProgram, allow_raw_pointers())
    .function("getMaxS", &Texture2D::getMaxS, allow_raw_pointers())
    .function("hasPremultipliedAlpha", &Texture2D::hasPremultipliedAlpha, allow_raw_pointers())
    .function("getPixelsHigh", &Texture2D::getPixelsHigh, allow_raw_pointers())
    .function("initWithMipmaps", optional_override(
      [](Texture2D& this_, MipmapInfo* mipmaps, int mipmapsNum, Texture2D::PixelFormat pixelFormat, int pixelsWide, int pixelsHigh){
        return this_.initWithMipmaps(mipmaps, mipmapsNum, pixelFormat, pixelsWide, pixelsHigh);
      }), allow_raw_pointers())
    .function("initWithMipmaps", &Texture2D::initWithMipmaps, allow_raw_pointers())
    .function("getAlphaTextureName", &Texture2D::getAlphaTextureName, allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int() const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int(Texture2D::PixelFormat) const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getName", &Texture2D::getName, allow_raw_pointers())
    .function("initWithString", optional_override(
      [](Texture2D& this_, const char *text,  const std::string &fontName, float fontSize){
        return this_.initWithString(text, fontName, fontSize);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
      [](Texture2D& this_, const char *text,  const std::string &fontName, float fontSize, const Size& dimensions){
        return this_.initWithString(text, fontName, fontSize, dimensions);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
      [](Texture2D& this_, const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment){
        return this_.initWithString(text, fontName, fontSize, dimensions, hAlignment);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
      [](Texture2D& this_, const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment){
        return this_.initWithString(text, fontName, fontSize, dimensions, hAlignment, vAlignment);
      }), allow_raw_pointers())
    .function("initWithString", optional_override(
      [](Texture2D& this_, const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap){
        return this_.initWithString(text, fontName, fontSize, dimensions, hAlignment, vAlignment, enableWrap);
      }), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char *, const std::string &, float, const Size&, TextHAlignment, TextVAlignment, bool, int)>(&Texture2D::initWithString), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char *, const FontDefinition&)>(&Texture2D::initWithString), allow_raw_pointers())
    .function("setMaxT", &Texture2D::setMaxT, allow_raw_pointers())
    .function("getPath", &Texture2D::getPath, allow_raw_pointers())
    .function("drawInRect", &Texture2D::drawInRect, allow_raw_pointers())
    .function("getContentSize", &Texture2D::getContentSize, allow_raw_pointers())
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
    .property("__nativeObj", &js_embind_getBool<Texture2D, true>)
    .property("__is_ref", &js_embind_getBool<Texture2D, true>)
    ;
  class_<Touch>("cc.Touch")
    .constructor(&js_embind_constructor<Touch>, allow_raw_pointers())
    .function("getPreviousLocationInView", &Touch::getPreviousLocationInView, allow_raw_pointers())
    .function("getLocation", &Touch::getLocation, allow_raw_pointers())
    .function("getDelta", &Touch::getDelta, allow_raw_pointers())
    .function("getStartLocationInView", &Touch::getStartLocationInView, allow_raw_pointers())
    .function("getCurrentForce", &Touch::getCurrentForce, allow_raw_pointers())
    .function("getStartLocation", &Touch::getStartLocation, allow_raw_pointers())
    .function("getID", &Touch::getID, allow_raw_pointers())
    .function("setTouchInfo", select_overload<void(int, float, float)>(&Touch::setTouchInfo), allow_raw_pointers())
    .function("setTouchInfo", select_overload<void(int, float, float, float, float)>(&Touch::setTouchInfo), allow_raw_pointers())
    .function("getMaxForce", &Touch::getMaxForce, allow_raw_pointers())
    .function("getLocationInView", &Touch::getLocationInView, allow_raw_pointers())
    .function("getPreviousLocation", &Touch::getPreviousLocation, allow_raw_pointers())
    .property("_className",  optional_override([](const Touch& _) -> std::string {return "Touch";}))
    .property("__nativeObj", &js_embind_getBool<Touch, true>)
    .property("__is_ref", &js_embind_getBool<Touch, true>)
    ;
  class_<Event>("cc.Event")
    .constructor(select_overload<Event*(Event::Type type)>([](Event::Type type)-> Event*{
        return new (std::nothrow) Event(type);
    }), allow_raw_pointers())
    .function("isStopped", &Event::isStopped, allow_raw_pointers())
    .function("getType", &Event::getType, allow_raw_pointers())
    .function("getCurrentTarget", &Event::getCurrentTarget, allow_raw_pointers())
    .function("stopPropagation", &Event::stopPropagation, allow_raw_pointers())
    .property("_className",  optional_override([](const Event& _) -> std::string {return "Event";}))
    .property("__nativeObj", &js_embind_getBool<Event, true>)
    .property("__is_ref", &js_embind_getBool<Event, true>)
    ;
  class_<EventTouch, base<Event>>("cc.EventTouch")
    .constructor(&js_embind_constructor<EventTouch>, allow_raw_pointers())
    .function("getEventCode", &EventTouch::getEventCode, allow_raw_pointers())
    .function("setEventCode", &EventTouch::setEventCode, allow_raw_pointers())
    .property("_className",  optional_override([](const EventTouch& _) -> std::string {return "EventTouch";}))
    .property("__nativeObj", &js_embind_getBool<EventTouch, true>)
    .property("__is_ref", &js_embind_getBool<EventTouch, true>)
    ;
  class_<ComponentContainer>("cc.ComponentContainer")
    .function("visit", &ComponentContainer::visit, allow_raw_pointers())
    .function("remove", optional_override([](ComponentContainer& this_, val v) {
        if (v.isString()) 
        {
          return this_.remove(v.as<string>());
        }
        else 
        {
          return this_.remove(v.as<Component *>(allow_raw_pointers()));
        }
    }))
    .function("removeAll", &ComponentContainer::removeAll, allow_raw_pointers())
    .function("add", &ComponentContainer::add, allow_raw_pointers())
    .function("isEmpty", &ComponentContainer::isEmpty, allow_raw_pointers())
    .function("getComponent", &ComponentContainer::get, allow_raw_pointers())
    .property("_className",  optional_override([](const ComponentContainer& _) -> std::string {return "ComponentContainer";}))
    .property("__nativeObj", &js_embind_getBool<ComponentContainer, true>)
    .property("__is_ref", &js_embind_getBool<ComponentContainer, false>)
    ;
  class_<Component>("cc.Component")
    .constructor(&js_embind_constructor<Component>, allow_raw_pointers())
    .function("setEnabled", &Component::setEnabled, allow_raw_pointers())
    .function("setName", &Component::setName, allow_raw_pointers())
    .function("isEnabled", &Component::isEnabled, allow_raw_pointers())
    .function("getOwner", &Component::getOwner, allow_raw_pointers())
    .function("init", &Component::init, allow_raw_pointers())
    .function("setOwner", &Component::setOwner, allow_raw_pointers())
    .function("getName", &Component::getName, allow_raw_pointers())
    .function("ctor", &js_embind_ctor<Component>, allow_raw_pointers())
    .class_function("create", &Component::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Component& _) -> std::string {return "Component";}))
    .property("__nativeObj", &js_embind_getBool<Component, true>)
    .property("__is_ref", &js_embind_getBool<Component, true>)
    ;
  class_<Node>("cc.Node")
    .constructor(&js_embind_constructor<Node>, allow_raw_pointers())
    .function("addChild", select_overload<void(Node *)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(Node *, int)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", optional_override([](Node& this_, val child, val localZOrder, val tagOrName) {
        if (tagOrName.isString()) 
        {
          return this_.addChild(child.as<Node *>(allow_raw_pointers()), localZOrder.as<int>(), tagOrName.as<string>());
        }
        else 
        {
          return this_.addChild(child.as<Node *>(allow_raw_pointers()), localZOrder.as<int>(), tagOrName.as<int>());
        }
    }))
    .function("removeComponent", optional_override([](Node& this_, val v) {
        if (v.isString()) 
        {
          return this_.removeComponent(v.as<string>());
        }
        else 
        {
          return this_.removeComponent(v.as<Component *>(allow_raw_pointers()));
        }
    }))
    .function("setPhysicsBody", &Node::setPhysicsBody, allow_raw_pointers())
    .function("getShaderProgram", &Node::getGLProgram, allow_raw_pointers())
    .function("getDescription", &Node::getDescription, allow_raw_pointers())
    .function("setOpacityModifyRGB", &Node::setOpacityModifyRGB, allow_raw_pointers())
    .function("setCascadeOpacityEnabled", &Node::setCascadeOpacityEnabled, allow_raw_pointers())
    .function("getChildren", select_overload<const Vector<Node*>& () const>(&Node::getChildren), allow_raw_pointers())
    .function("setOnExitCallback", &Node::setOnExitCallback, allow_raw_pointers())
    .function("setActionManager", &Node::setActionManager, allow_raw_pointers())
    .function("isIgnoreAnchorPointForPosition", &Node::isIgnoreAnchorPointForPosition, allow_raw_pointers())
    .function("getChildByName", optional_override([](Node& this_, const std::string& name) {
        return this_.getChildByName(name);
    }), allow_raw_pointers())
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
    .function("setCameraMask", optional_override([](Node& this_, unsigned short mask) {
        return this_.setCameraMask(mask);
    }), allow_raw_pointers())
    .function("setCameraMask", &Node::setCameraMask, allow_raw_pointers())
    .function("getTag", &Node::getTag, allow_raw_pointers())
    .function("getonEnterTransitionDidFinishCallback", &Node::getonEnterTransitionDidFinishCallback, allow_raw_pointers())
    .function("getNodeToWorldTransform", &Node::getNodeToWorldAffineTransform, allow_raw_pointers())
    .function("getPosition3D", &Node::getPosition3D, allow_raw_pointers())
    .function("removeChild", optional_override(
      [](Node& this_, Node* child){
        return this_.removeChild(child);
      }), allow_raw_pointers())
    .function("removeChild", &Node::removeChild, allow_raw_pointers())
    .function("getScene", &Node::getScene, allow_raw_pointers())
    .function("getEventDispatcher", &Node::getEventDispatcher, allow_raw_pointers())
    .function("setSkewX", &Node::setSkewX, allow_raw_pointers())
    .function("setGLProgramState", &Node::setGLProgramState, allow_raw_pointers())
    .function("setOnEnterCallback", &Node::setOnEnterCallback, allow_raw_pointers())
    .function("stopActionsByFlags", &Node::stopActionsByFlags, allow_raw_pointers())
    .function("setNormalizedPosition", &Node::setNormalizedPosition, allow_raw_pointers())
    .function("setonExitTransitionDidStartCallback", &Node::setonExitTransitionDidStartCallback, allow_raw_pointers())
    .function("convertTouchToNodeSpace", &Node::convertTouchToNodeSpace, allow_raw_pointers())
    .function("removeAllChildren", &Node::removeAllChildrenWithCleanup, allow_raw_pointers())
    .function("getRotationX", &Node::getRotationSkewX, allow_raw_pointers())
    .function("getRotationY", &Node::getRotationSkewY, allow_raw_pointers())
    .function("getNodeToWorldTransform3D", &Node::getNodeToWorldTransform, allow_raw_pointers())
    .function("isCascadeOpacityEnabled", &Node::isCascadeOpacityEnabled, allow_raw_pointers())
    .function("setParent", &Node::setParent, allow_raw_pointers())
    .function("getName", &Node::getName, allow_raw_pointers())
    .function("getRotation3D", &Node::getRotation3D, allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<AffineTransform() const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<AffineTransform(Node*) const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
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
    .function("getNodeToParentTransform3D", select_overload<const Mat4&() const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("getNodeToParentTransform3D", select_overload<Mat4 (Node* ancestor) const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("convertToNodeSpaceAR", &Node::convertToNodeSpaceAR, allow_raw_pointers())
    .function("addComponent", &Node::addComponent, allow_raw_pointers())
    .function("runAction", &Node::runAction, allow_raw_pointers())
    .function("visit", select_overload<void (Renderer *, const Mat4&, uint32_t)>(&Node::visit), allow_raw_pointers())
    .function("visit", select_overload<void ()>(&Node::visit), allow_raw_pointers())
    .function("setShaderProgram", &Node::setGLProgram, allow_raw_pointers())
    .function("getRotation", &Node::getRotation, allow_raw_pointers())
    .function("getPhysicsBody", &Node::getPhysicsBody, allow_raw_pointers())
    .function("getAnchorPointInPoints", &Node::getAnchorPointInPoints, allow_raw_pointers())
    .function("getRotationQuat", &Node::getRotationQuat, allow_raw_pointers())
    .function("removeChildByName", optional_override(
      [](Node& this_, const std::string &name){
        return this_.removeChildByName(name);
      }), allow_raw_pointers())
    .function("removeChildByName", &Node::removeChildByName, allow_raw_pointers())
    .function("setVertexZ", &Node::setPositionZ, allow_raw_pointers())
    .function("getGLProgramState", &Node::getGLProgramState, allow_raw_pointers())
    .function("setScheduler", &Node::setScheduler, allow_raw_pointers())
    .function("stopAllActions", &Node::stopAllActions, allow_raw_pointers())
    .function("getSkewX", &Node::getSkewX, allow_raw_pointers())
    .function("getSkewY", &Node::getSkewY, allow_raw_pointers())
    .function("isScheduled", select_overload<bool (const std::string &key) const>(&Node::isScheduled), allow_raw_pointers())
    .function("getDisplayedColor", &Node::getDisplayedColor, allow_raw_pointers())
    .function("getActionByTag", &Node::getActionByTag, allow_raw_pointers())
    .function("setRotationX", &Node::setRotationSkewX, allow_raw_pointers())
    .function("setRotationY", &Node::setRotationSkewY, allow_raw_pointers())
    .function("setName", &Node::setName, allow_raw_pointers())
    .function("update", &Node::update, allow_raw_pointers())
    .function("getDisplayedOpacity", &Node::getDisplayedOpacity, allow_raw_pointers())
    .function("getLocalZOrder", &Node::getLocalZOrder, allow_raw_pointers())
    .function("getScheduler", select_overload<const Scheduler* () const>(&Node::getScheduler), allow_raw_pointers())
    .function("getPositionNormalized", &Node::getPositionNormalized, allow_raw_pointers())
    .function("getPosition", select_overload<void (float*, float*) const>(&Node::getPosition), allow_raw_pointers())
    .function("getPosition", select_overload<const Vec2& () const>(&Node::getPosition), allow_raw_pointers())
    .function("isRunning", &Node::isRunning, allow_raw_pointers())
    .function("getParent", select_overload<const Node* () const>(&Node::getParent), allow_raw_pointers())
    .function("getWorldToNodeTransform3D", &Node::getWorldToNodeTransform, allow_raw_pointers())
    .function("getPositionY", &Node::getPositionY, allow_raw_pointers())
    .function("getPositionX", &Node::getPositionX, allow_raw_pointers())
    .function("removeChildByTag", optional_override(
      [](Node& this_, int tag){
        return this_.removeChildByTag(tag);
      }), allow_raw_pointers())
    .function("removeChildByTag", &Node::removeChildByTag, allow_raw_pointers())
    .function("setPositionY", &Node::setPositionY, allow_raw_pointers())
    .function("updateDisplayedColor", &Node::updateDisplayedColor, allow_raw_pointers())
    .function("setVisible", &Node::setVisible, allow_raw_pointers())
    .function("getParentToNodeTransform", &Node::getParentToNodeAffineTransform, allow_raw_pointers())
    .function("getVertexZ", &Node::getPositionZ, allow_raw_pointers())
    .function("setGlobalZOrder", &Node::setGlobalZOrder, allow_raw_pointers())
    .function("setScale", select_overload<void (float)>(&Node::setScale), allow_raw_pointers())
    .function("setScale", select_overload<void (float, float)>(&Node::setScale), allow_raw_pointers())
    .function("getOnExitCallback", &Node::getOnExitCallback, allow_raw_pointers())
    .function("getChildByTag", optional_override([](Node& this_, int tag) {
        return this_.getChildByTag(tag);
    }), allow_raw_pointers())
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
    .function("draw", select_overload<void ()>(&Node::draw), allow_raw_pointers())
    .function("draw", select_overload<void (Renderer *, const Mat4&, uint32_t)>(&Node::draw), allow_raw_pointers())
    .function("setUserObject", &Node::setUserObject, allow_raw_pointers())
    .function("enumerateChildren", &Node::enumerateChildren, allow_raw_pointers())
    .function("getonExitTransitionDidStartCallback", &Node::getonExitTransitionDidStartCallback, allow_raw_pointers())
    .function("removeFromParent", &Node::removeFromParentAndCleanup, allow_raw_pointers())
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
    .function("getActionManager", select_overload<const ActionManager* () const>(&Node::getActionManager), allow_raw_pointers())
    .function("ctor", &js_embind_ctor<Node>, allow_raw_pointers())
    .class_function("create", &Node::create, allow_raw_pointers())
    .class_function("getAttachedNodeCount", &Node::getAttachedNodeCount, allow_raw_pointers())
    .property("_className",  optional_override([](const Node& _) -> std::string {return "Node";}))
    .property("__nativeObj", &js_embind_getBool<Node, true>)
    .property("__is_ref", &js_embind_getBool<Node, true>)
    ;
  class_<__NodeRGBA>("cc.__NodeRGBA")
    .constructor(&js_embind_constructor<__NodeRGBA>, allow_raw_pointers())
    .property("_className",  optional_override([](const __NodeRGBA& _) -> std::string {return "__NodeRGBA";}))
    .property("__nativeObj", &js_embind_getBool<__NodeRGBA, true>)
    .property("__is_ref", &js_embind_getBool<__NodeRGBA, true>)
    ;
  class_<Scene, base<Node>>("cc.Scene")
    .constructor(&js_embind_constructor<Scene>, allow_raw_pointers())
    .function("setCameraOrderDirty", &Scene::setCameraOrderDirty, allow_raw_pointers())
    .function("render", optional_override(
      [](Scene& this_, Renderer* renderer, const Mat4& eyeTransform){
        return this_.render(renderer, eyeTransform);
      }), allow_raw_pointers())
    .function("render", select_overload<void (Renderer*, const Mat4&, const Mat4*)>(&Scene::render), allow_raw_pointers())
    .function("render", select_overload<void (Renderer*, const Mat4*, const Mat4*, unsigned int)>(&Scene::render), allow_raw_pointers())
    .function("stepPhysicsAndNavigation", &Scene::stepPhysicsAndNavigation, allow_raw_pointers())
    .function("onProjectionChanged", &Scene::onProjectionChanged, allow_raw_pointers())
    .function("initWithSize", &Scene::initWithSize, allow_raw_pointers())
    .function("getDefaultCamera", &Scene::getDefaultCamera, allow_raw_pointers())
    .function("ctor", &js_embind_ctor<Scene>, allow_raw_pointers())
    
    .class_function("createWithSize", &Scene::createWithSize, allow_raw_pointers())
    .class_function("create", &Scene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Scene& _) -> std::string {return "Scene";}))
    .property("__nativeObj", &js_embind_getBool<Scene, true>)
    .property("__is_ref", &js_embind_getBool<Scene, true>)
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
    .function("setIcon", optional_override([](GLView& this_, val v) {
        if (v.isString()) 
        {
          return this_.setIcon(v.as<string>());
        }
        else 
        {
          return this_.setIcon(v.as<std::vector<std::string>>());
        }
    }))
    .function("setDefaultCursor", &GLView::setDefaultCursor, allow_raw_pointers())
    .function("windowShouldClose", &GLView::windowShouldClose, allow_raw_pointers())
    .function("setDesignResolutionSize", &GLView::setDesignResolutionSize, allow_raw_pointers())
    .function("getResolutionPolicy", &GLView::getResolutionPolicy, allow_raw_pointers())
    .function("isRetinaDisplay", &GLView::isRetinaDisplay, allow_raw_pointers())
    .function("renderScene", &GLView::renderScene, allow_raw_pointers())
    .function("setVR", &GLView::setVR, allow_raw_pointers())
    .function("getFrameSize", &GLView::getFrameSize, allow_raw_pointers())
    .function("getScissorRect", &GLView::getScissorRect, allow_raw_pointers())
    .function("setCursor", optional_override(
      [](GLView& this_, const std::string& filename){
        return this_.setCursor(filename);
      }))
    .function("setCursor", &GLView::setCursor, allow_raw_pointers())
    .function("getRetinaFactor", &GLView::getRetinaFactor, allow_raw_pointers())
    .function("setViewName", &GLView::setViewName, allow_raw_pointers())
    .function("getVisibleRect", &GLView::getVisibleRect, allow_raw_pointers())
    .function("getVisibleSize", &GLView::getVisibleSize, allow_raw_pointers())
    .function("isScissorEnabled", &GLView::isScissorEnabled, allow_raw_pointers())
    .function("pollEvents", &GLView::pollEvents, allow_raw_pointers())
    .class_function("setGLContextAttrs", &GLView::setGLContextAttrs, allow_raw_pointers())
    .class_function("getGLContextAttrs", &GLView::getGLContextAttrs, allow_raw_pointers())
    .property("_className",  optional_override([](const GLView& _) -> std::string {return "GLView";}))
    .property("__nativeObj", &js_embind_getBool<GLView, true>)
    .property("__is_ref", &js_embind_getBool<GLView, true>)
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
    .function("mainLoop", select_overload<void ()>(&Director::mainLoop), allow_raw_pointers())
    .function("mainLoop", select_overload<void (float)>(&Director::mainLoop), allow_raw_pointers())
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
    .property("__nativeObj", &js_embind_getBool<Director, true>)
    .property("__is_ref", &js_embind_getBool<Director, true>)
    ;
  class_<Scheduler>("cc.Scheduler")
    .constructor(&js_embind_constructor<Scheduler>, allow_raw_pointers())
    .function("setTimeScale", &Scheduler::setTimeScale, allow_raw_pointers())
    .function("unscheduleAllWithMinPriority", &Scheduler::unscheduleAllWithMinPriority, allow_raw_pointers())
    .function("update", &Scheduler::update, allow_raw_pointers())
    .function("unscheduleScriptEntry", &Scheduler::unscheduleScriptEntry, allow_raw_pointers())
    .function("performFunctionInCocosThread", &Scheduler::performFunctionInCocosThread, allow_raw_pointers())
    .function("removeAllFunctionsToBePerformedInCocosThread", &Scheduler::removeAllFunctionsToBePerformedInCocosThread, allow_raw_pointers())
    .function("unscheduleAll", &Scheduler::unscheduleAll, allow_raw_pointers())
    .function("getTimeScale", &Scheduler::getTimeScale, allow_raw_pointers())
    .property("_className",  optional_override([](const Scheduler& _) -> std::string {return "Scheduler";}))
    .property("__nativeObj", &js_embind_getBool<Scheduler, true>)
    .property("__is_ref", &js_embind_getBool<Scheduler, true>)
    ;
  class_<AsyncTaskPool>("cc.AsyncTaskPool")
    .function("stopTasks", &AsyncTaskPool::stopTasks, allow_raw_pointers())
    .class_function("destroyInstance", &AsyncTaskPool::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &AsyncTaskPool::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AsyncTaskPool& _) -> std::string {return "AsyncTaskPool";}))
    .property("__nativeObj", &js_embind_getBool<AsyncTaskPool, true>)
    .property("__is_ref", &js_embind_getBool<AsyncTaskPool, false>)
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
    .property("__nativeObj", &js_embind_getBool<Action, true>)
    .property("__is_ref", &js_embind_getBool<Action, true>)
    ;
  class_<FiniteTimeAction, base<Action>>("cc.FiniteTimeAction")
    .function("setDuration", &FiniteTimeAction::setDuration, allow_raw_pointers())
    .function("getDuration", &FiniteTimeAction::getDuration, allow_raw_pointers())
    .property("_className",  optional_override([](const FiniteTimeAction& _) -> std::string {return "FiniteTimeAction";}))
    .property("__nativeObj", &js_embind_getBool<FiniteTimeAction, true>)
    .property("__is_ref", &js_embind_getBool<FiniteTimeAction, true>)
    ;
  class_<Speed, base<Action>>("cc.Speed")
    .function("setInnerAction", &Speed::setInnerAction, allow_raw_pointers())
    .function("_getSpeed", &Speed::getSpeed, allow_raw_pointers())
    .function("_setSpeed", &Speed::setSpeed, allow_raw_pointers())
    .function("initWithAction", &Speed::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Speed::getInnerAction, allow_raw_pointers())
    .class_function("create", &Speed::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Speed& _) -> std::string {return "Speed";}))
    .property("__nativeObj", &js_embind_getBool<Speed, true>)
    .property("__is_ref", &js_embind_getBool<Speed, true>)
    ;
  class_<Follow, base<Action>>("cc.Follow")
    .constructor(&js_embind_constructor<Follow>, allow_raw_pointers())
    .function("setBoundarySet", &Follow::setBoundarySet, allow_raw_pointers())
    .function("initWithTarget", &Follow::initWithTarget, allow_raw_pointers())
    .function("initWithTargetAndOffset", &Follow::initWithTargetAndOffset, allow_raw_pointers())
    .function("isBoundarySet", &Follow::isBoundarySet, allow_raw_pointers())
    .function("ctor", &js_embind_ctor<Follow>, allow_raw_pointers())
    .class_function("create", optional_override(
      [](Node* followedNode){
        return Follow::create(followedNode);
      }), allow_raw_pointers())
    .class_function("create", &Follow::create, allow_raw_pointers())
    .class_function("createWithOffset", optional_override(
      [](Node* followedNode, float xOffset, float yOffset){
        return Follow::createWithOffset(followedNode, xOffset, yOffset);
      }), allow_raw_pointers())
    .class_function("createWithOffset", &Follow::createWithOffset, allow_raw_pointers())
    .property("_className",  optional_override([](const Follow& _) -> std::string {return "Follow";}))
    .property("__nativeObj", &js_embind_getBool<Follow, true>)
    .property("__is_ref", &js_embind_getBool<Follow, true>)
    ;
    /*
  class_<Director>("cc.Director")
    .class_function("getInstance", &Director::getInstance, allow_raw_pointers())
    .function("getRunningScene", &Director::getRunningScene, allow_raw_pointers())
    .function("getRenderer", &Director::getRenderer, allow_raw_pointers())
    .function("drawScene", &Director::drawScene, allow_raw_pointers())
    .function("pushScene", &Director::pushScene, allow_raw_pointers())
    .function("startAnimation", &Director::startAnimation, allow_raw_pointers())
    .function("stopAnimation", &Director::stopAnimation, allow_raw_pointers())
    ;

  class_<Renderer>("cc.Renderer")
    .function("getDrawnBatches", &Renderer::getDrawnBatches, allow_raw_pointers())
    .function("getDrawnVertices", &Renderer::getDrawnVertices, allow_raw_pointers())
    ;

  class_<Ref>("cc.Ref")
    .function("retain", &Node::retain, allow_raw_pointers())
    .function("release", &Node::release, allow_raw_pointers())
    ;

  class_<Node, base<Ref>>("cc.Node")
    .constructor(&Node::create, allow_raw_pointers())
    .function("addChild", select_overload<void(Node*)>(&Node::addChild), allow_raw_pointers())
    .function("removeChild", select_overload<void(Node*, bool)>(&Node::removeChild), allow_raw_pointers())
    .function("getParent", select_overload<Node*()>(&Node::getParent), allow_raw_pointers())
    .property("position", select_overload<const Vec2&() const>(&Node::getPosition), select_overload<void(const Vec2 &)>(&Node::setPosition))
    .property("positionZ", &Node::getPositionZ, &Node::setPositionZ)
    .property<val>("anchorX", std::bind(&Node_getAnchorX, _1), std::bind(&Node_setAnchorX, _1, _2))
    .property<val>("anchorY", std::bind(&Node_getAnchorY, _1), std::bind(&Node_setAnchorY, _1, _2))
    .property<val>("width", std::bind(&Node_getWidth, _1), std::bind(&Node_setWidth, _1, _2))
    .property<val>("height", std::bind(&Node_getHeight, _1), std::bind(&Node_setHeight, _1, _2))
    .property("scaleX", &Node::getScaleX, &Node::setScaleX)
    .property("scaleY", &Node::getScaleY, &Node::setScaleY)
    .property("color", &Node::getColor, &Node::setColor)
    .property("visible", &Node::isVisible, &Node::setVisible)
    .property("rotation", &Node::getRotation, &Node::setRotation)
    .property("skewX", &Node::getSkewX, &Node::setSkewX)
    .property("skewY", &Node::getSkewY, &Node::setSkewY)
    .property("name", &Node::getName, &Node::setName)
    .property("cascadeColorEnabled", &Node::isCascadeColorEnabled, &Node::setCascadeColorEnabled)
    .property("opacity", &Node::getOpacity, &Node::setOpacity)
    .property<val>("children", std::bind(&Node_getChildren, _1))
    .function("getNodeToParentAffineTransform", select_overload<AffineTransform() const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("getBoundingBox", &Node::getBoundingBox, allow_raw_pointers())
    ;
  class_<Scene, base<Node>>("cc.Scene")
    .constructor(&Scene::create, allow_raw_pointers())
    .function("getDefaultCamera", &Scene::getDefaultCamera, allow_raw_pointers())
    ;
  class_<Sprite, base<Node>>("cc.Sprite")
    .constructor(select_overload<Sprite*()>(&Sprite::create), allow_raw_pointers())
    .function("setTexture", select_overload<void(Texture2D *)>(&Sprite::setTexture), allow_raw_pointers())
    .function("getTexture", &Sprite::getTexture, allow_raw_pointers())
    .function("setTextureRect", select_overload<void(const Rect&)>(&Sprite::setTextureRect), allow_raw_pointers())
    .function("getTextureRect", &Sprite::getTextureRect, allow_raw_pointers())
    .property("flippedX", &Sprite::isFlippedX, &Sprite::setFlippedX)
    .property("flippedY", &Sprite::isFlippedY, &Sprite::setFlippedY)
    .property("blendFunc", &Sprite::getBlendFunc, &Sprite::setBlendFunc)
    ;
  class_<Label, base<Node>>("cc.Label")
    .constructor(select_overload<Label*()>(&Label::create), allow_raw_pointers())
    .property("ttfConfig", &Label::getTTFConfig, &Label::setTTFConfig)
    .property("string", &Label::getString, &Label::setString)
    .property("horizontalAlignment", &Label::getHorizontalAlignment, &Label::setHorizontalAlignment)
    .property("verticalAlignment", &Label::getVerticalAlignment, &Label::setVerticalAlignment)
    .property("maxLineWidth", &Label::getMaxLineWidth, &Label::setMaxLineWidth)
    ;
  class_<ParticleSystem, base<Node>>("cc.ParticleSystem")
    .constructor(&ParticleSystem::create, allow_raw_pointers())
    .function("stopSystem", &ParticleSystem::stopSystem, allow_raw_pointers())
    .function("resetSystem", &ParticleSystem::resetSystem, allow_raw_pointers())
    .property("autoRemoveOnFinish", &ParticleSystem::isAutoRemoveOnFinish, &ParticleSystem::setAutoRemoveOnFinish)
    .property("gravity", &ParticleSystem::getGravity, &ParticleSystem::setGravity)
    .property("speed", &ParticleSystem::getSpeed, &ParticleSystem::setSpeed)
    .property("speedVar", &ParticleSystem::getSpeedVar, &ParticleSystem::setSpeedVar)
    .property("tangentialAccel", &ParticleSystem::getTangentialAccel, &ParticleSystem::setTangentialAccel)
    .property("tangentialAccelVar", &ParticleSystem::getTangentialAccelVar, &ParticleSystem::setTangentialAccelVar)
    .property("radialAccel", &ParticleSystem::getRadialAccel, &ParticleSystem::setRadialAccel)
    .property("radialAccelVar", &ParticleSystem::getRadialAccelVar, &ParticleSystem::setRadialAccelVar)
    .property("rotationIsDir", &ParticleSystem::getRotationIsDir, &ParticleSystem::setRotationIsDir)
    .property("startRadius", &ParticleSystem::getStartRadius, &ParticleSystem::setStartRadius)
    .property("startRadiusVar", &ParticleSystem::getStartRadiusVar, &ParticleSystem::setStartRadiusVar)
    .property("endRadius", &ParticleSystem::getEndRadius, &ParticleSystem::setEndRadius)
    .property("endRadiusVar", &ParticleSystem::getEndRadiusVar, &ParticleSystem::setEndRadiusVar)
    .property("rotatePerSecond", &ParticleSystem::getRotatePerSecond, &ParticleSystem::setRotatePerSecond)
    .property("rotatePerSecondVar", &ParticleSystem::getRotatePerSecondVar, &ParticleSystem::setRotatePerSecondVar)
    .property("blendAdditive", &ParticleSystem::isBlendAdditive, &ParticleSystem::setBlendAdditive)
    .property("duration", &ParticleSystem::getDuration, &ParticleSystem::setDuration)
    .property("sourcePosition", &ParticleSystem::getSourcePosition, &ParticleSystem::setSourcePosition)
    .property("posVar", &ParticleSystem::getPosVar, &ParticleSystem::setPosVar)
    .property("life", &ParticleSystem::getLife, &ParticleSystem::setLife)
    .property("lifeVar", &ParticleSystem::getLifeVar, &ParticleSystem::setLifeVar)
    .property("angle", &ParticleSystem::getAngle, &ParticleSystem::setAngle)
    .property("angleVar", &ParticleSystem::getAngleVar, &ParticleSystem::setAngleVar)
    .property("emitterMode", &ParticleSystem::getEmitterMode, &ParticleSystem::setEmitterMode)
    .property("startSize", &ParticleSystem::getStartSize, &ParticleSystem::setStartSize)
    .property("startSizeVar", &ParticleSystem::getStartSizeVar, &ParticleSystem::setStartSizeVar)
    .property("endSize", &ParticleSystem::getEndSize, &ParticleSystem::setEndSize)
    .property("endSizeVar", &ParticleSystem::getEndSizeVar, &ParticleSystem::setEndSizeVar)
    .property("startColor", &ParticleSystem::getStartColor, &ParticleSystem::setStartColor)
    .property("startColorVar", &ParticleSystem::getStartColorVar, &ParticleSystem::setStartColorVar)
    .property("endColor", &ParticleSystem::getEndColor, &ParticleSystem::setEndColor)
    .property("endColorVar", &ParticleSystem::getEndColorVar, &ParticleSystem::setEndColorVar)
    .property("startSpin", &ParticleSystem::getStartSpin, &ParticleSystem::setStartSpin)
    .property("startSpinVar", &ParticleSystem::getStartSpinVar, &ParticleSystem::setStartSpinVar)
    .property("endSpin", &ParticleSystem::getEndSpin, &ParticleSystem::setEndSpin)
    .property("endSpinVar", &ParticleSystem::getEndSpinVar, &ParticleSystem::setEndSpinVar)
    .property("emissionRate", &ParticleSystem::getEmissionRate, &ParticleSystem::setEmissionRate)
    .property("totalParticles", &ParticleSystem::getTotalParticles, &ParticleSystem::setTotalParticles)
    .property("positionType", &ParticleSystem::getPositionType, &ParticleSystem::setPositionType)
    ;
  value_object<Rect>("cc.Rect")
    .field("origin", &Rect::origin)
    .field("size", &Rect::size)
    ;
  value_object<Vec2>("cc.Vec2")
    .field("x", &Vec2::x)
    .field("y", &Vec2::y)
    ;
  value_object<Size>("cc.Size")
    .field("width", &Size::width)
    .field("height", &Size::height)
    ;
  value_object<Color4F>("cc.Color4F")
    .field("r", &Color4F::r)
    .field("g", &Color4F::g)
    .field("b", &Color4F::b)
    .field("a", &Color4F::a)
    ;
  value_object<Color3B>("cc.Color3B")
    .field("r", &Color3B::r)
    .field("g", &Color3B::g)
    .field("b", &Color3B::b)
    ;
  value_object<AffineTransform>("cc.AffineTransform")
    .field("a", &AffineTransform::a)
    .field("b", &AffineTransform::b)
    .field("c", &AffineTransform::c)
    .field("d", &AffineTransform::d)
    .field("tx", &AffineTransform::tx)
    .field("ty", &AffineTransform::ty)
    ;
  value_object<BlendFunc>("cc.BlendFunc")
    .field("src", &BlendFunc::src)
    .field("dst", &BlendFunc::dst)
    ;
  value_object<TTFConfig>("cc.TTFConfig")
    .field("fontFilePath", &TTFConfig::fontFilePath)
    .field("fontSize", &TTFConfig::fontSize)
    .field("glyphs", &TTFConfig::glyphs)
    // .field("customGlyphs", &TTFConfig::customGlyphs)
    .field("distanceFieldEnabled", &TTFConfig::distanceFieldEnabled)
    .field("outlineSize", &TTFConfig::outlineSize)
    .field("italics", &TTFConfig::italics)
    .field("bold", &TTFConfig::bold)
    .field("underline", &TTFConfig::underline)
    .field("strikethrough", &TTFConfig::strikethrough)
    ;
  emscripten::function("cc.PointApplyAffineTransform", &PointApplyAffineTransform, allow_raw_pointers());
  class_<DrawNode, base<Node>>("cc.DrawNode")
    .constructor(&DrawNode::create, allow_raw_pointers())
    .function("clear", &DrawNode::clear, allow_raw_pointers())
    .function("drawLine", &DrawNode::drawLine, allow_raw_pointers())
    ;
  class_<Image, base<Ref>>("cc.Image")
    .class_function("createWithImageFile", &Image_createWithImageFile, allow_raw_pointers())
    ;
  class_<Texture2D, base<Ref>>("cc.Texture2D")
    .class_function("createWithImage", &Texture2D_createWithImage, allow_raw_pointers())
    .function("getContentSize", &Texture2D::getContentSize, allow_raw_pointers())
    ;
  class_<Camera, base<Node>>("cc.Camera");
  class_<Sprite3D, base<Node>>("cc.Sprite3D")
    .class_function("create", select_overload<Sprite3D*()>(&Sprite3D::create), allow_raw_pointers())
    .function("addMesh", &Sprite3D::addMesh, allow_raw_pointers())
    ;
  class_<Mesh, base<Ref>>("cc.Mesh");
  class_<MeshHelper>("cc.MeshHelper")
    .class_function("createBox", &MeshHelper::createBox, allow_raw_pointers())
    ;
    */
}
