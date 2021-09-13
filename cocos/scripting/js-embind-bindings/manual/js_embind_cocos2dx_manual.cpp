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
  class_<Ref>("cc.Ref")
    .function("retain", &Node::retain, allow_raw_pointers())
    .function("release", &Node::release, allow_raw_pointers())
    ;

  
  class_<GLProgram, base<Ref>>("cc.GLProgram")
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
    .property("_className",  select_overload<std::string(const GLProgram&)>([](const GLProgram& _) -> std::string {return "GLProgram";}))
    .property("__nativeObj", &js_embind_getBool<GLProgram, true>)
    .property("__is_ref", &js_embind_getBool<GLProgram, true>)
    ;
  class_<Texture2D, base<Ref>>("cc.Texture2D")
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
    .function("initWithMipmaps", &Texture2D::initWithMipmaps, allow_raw_pointers())
    .function("getAlphaTextureName", &Texture2D::getAlphaTextureName, allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int() const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getBitsPerPixelForFormat", select_overload<unsigned int(Texture2D::PixelFormat) const>(&Texture2D::getBitsPerPixelForFormat), allow_raw_pointers())
    .function("getName", &Texture2D::getName, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize)>(std::bind(
      static_cast<bool(Texture2D::*)(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString),
      _1, _2, _3, Size(0, 0), TextHAlignment::CENTER, TextVAlignment::TOP, true, 0
 )), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
    // .function("initWithString", select_overload<bool(const char *text,  const std::string &fontName, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment, bool enableWrap, int overflow)>(&Texture2D::initWithString), allow_raw_pointers())
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
    .property("_className",  select_overload<std::string(const Texture2D&)>([](const Texture2D& _) -> std::string {return "Texture2D";}))
    .property("__nativeObj", &js_embind_getBool<Texture2D, true>)
    .property("__is_ref", &js_embind_getBool<Texture2D, true>)
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
