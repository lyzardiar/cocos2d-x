
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"


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

Mesh* Mesh_create(const val& positionsVal, const val& normalsVal, const val& texsVal, const val& indicesVal) {
  std::vector<float> positions;
  std::vector<float> normals;
  std::vector<float> texs;
  std::vector<unsigned short> indices;

  unsigned length;
  length = positionsVal["length"].as<unsigned>();
  for (unsigned i = 0; i < length; i++) {
      positions.push_back(positionsVal[i].as<float>());
  }

  length = normalsVal["length"].as<unsigned>();
  for (unsigned i = 0; i < length; i++) {
      normals.push_back(normalsVal[i].as<float>());
  }

  length = texsVal["length"].as<unsigned>();
  for (unsigned i = 0; i < length; i++) {
      texs.push_back(texsVal[i].as<float>());
  }

  length = indicesVal["length"].as<unsigned>();
  for (unsigned i = 0; i < length; i++) {
      indices.push_back(indicesVal[i].as<unsigned short>());
  }

  return Mesh::create(positions, normals, texs, indices);
}

val Node_getNodeToWorldTransform(const Node& node) {
    Mat4 mat = node.getNodeToWorldTransform();
    auto out = val::array();
    out.set(0, val(mat.m[0]));
    out.set(1, val(mat.m[1]));
    out.set(2, val(mat.m[2]));
    out.set(3, val(mat.m[3]));
    out.set(4, val(mat.m[4]));
    out.set(5, val(mat.m[5]));
    out.set(6, val(mat.m[6]));
    out.set(7, val(mat.m[7]));
    out.set(8, val(mat.m[8]));
    out.set(9, val(mat.m[9]));
    out.set(10, val(mat.m[10]));
    out.set(11, val(mat.m[11]));
    out.set(12, val(mat.m[12]));
    out.set(13, val(mat.m[13]));
    out.set(14, val(mat.m[14]));
    out.set(15, val(mat.m[15]));
    return out;
}

void Node_removeChild( Node& parent, Node * node) {
  parent.removeChild(node);
}

namespace emscripten {
    namespace internal {
        template<> void raw_destructor<Material>(Material* ptr) { /* do nothing */ }
    }
}

EMSCRIPTEN_BINDINGS(my_class_example) {
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
    // .function("removeChild", select_overload<void(Node*, bool)>(&Node::removeChild), allow_raw_pointers())
    .function<val>("removeChild", std::bind(&Node::removeChild, _1, _2, _3))
    .function("getParent", select_overload<Node*()>(&Node::getParent), allow_raw_pointers())
    .function("getNodeToWorldTransform", &Node_getNodeToWorldTransform, allow_raw_pointers())
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
  class_<Mesh, base<Ref>>("cc.Mesh")
    .class_function("create", &Mesh_create, allow_raw_pointers())
    .function("setMaterial", &Mesh::setMaterial, allow_raw_pointers())
    ;
  class_<Material, base<Ref>>("cc.Material")
    .function("clone", &Material::clone, allow_raw_pointers())
    ;
  enum_<Sprite3DMaterial::MaterialType>("cc.MaterialType")
        .value("UNLIT", Sprite3DMaterial::MaterialType::UNLIT)
        .value("UNLIT_NOTEX", Sprite3DMaterial::MaterialType::UNLIT_NOTEX)
        .value("VERTEX_LIT", Sprite3DMaterial::MaterialType::VERTEX_LIT)
        .value("DIFFUSE", Sprite3DMaterial::MaterialType::DIFFUSE)
        .value("DIFFUSE_NOTEX", Sprite3DMaterial::MaterialType::DIFFUSE_NOTEX)
        .value("BUMPED_DIFFUSE", Sprite3DMaterial::MaterialType::BUMPED_DIFFUSE)
        .value("CUSTOM", Sprite3DMaterial::MaterialType::CUSTOM)
        ;

  class_<Sprite3DMaterial, base<Material>>("cc.Sprite3DMaterial")
    .class_function("createBuiltInMaterial", select_overload<Sprite3DMaterial*(Sprite3DMaterial::MaterialType, bool)>(&Sprite3DMaterial::createBuiltInMaterial), allow_raw_pointers())
    ;
}
