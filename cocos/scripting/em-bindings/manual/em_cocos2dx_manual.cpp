
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

EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<Director>("cc.Director")
    .class_function("getInstance", &Director::getInstance, allow_raw_pointers())
    .function("getRunningScene", &Director::getRunningScene, allow_raw_pointers())
    .function("getRenderer", &Director::getRenderer, allow_raw_pointers())
    .function("drawScene", &Director::drawScene, allow_raw_pointers())
    ;

  class_<Renderer>("cc.Renderer")
    .function("getDrawnBatches", &Renderer::getDrawnBatches, allow_raw_pointers())
    .function("getDrawnVertices", &Renderer::getDrawnVertices, allow_raw_pointers())
    ;

  class_<Node>("cc.Node")
    .constructor(&Node::create, allow_raw_pointers())
    .function("addChild", select_overload<void(Node*)>(&Node::addChild), allow_raw_pointers())
    .function("removeChild", select_overload<void(Node*, bool)>(&Node::removeChild), allow_raw_pointers())
    .function("getParent", select_overload<Node*()>(&Node::getParent), allow_raw_pointers())
    .property("x", &Node::getPositionX, &Node::setPositionX)
    .property("y", &Node::getPositionY, &Node::setPositionY)
    .property<val>("anchorX", std::bind(&Node_getAnchorX, _1), std::bind(&Node_setAnchorX, _1, _2))
    .property<val>("anchorY", std::bind(&Node_getAnchorY, _1), std::bind(&Node_setAnchorY, _1, _2))
    .property<val>("width", std::bind(&Node_getWidth, _1), std::bind(&Node_setWidth, _1, _2))
    .property<val>("height", std::bind(&Node_getHeight, _1), std::bind(&Node_setHeight, _1, _2))
    .property("scaleX", &Node::getScaleX, &Node::setScaleX)
    .property("scaleY", &Node::getScaleY, &Node::setScaleY)
    .property("visible", &Node::isVisible, &Node::setVisible)
    .property("rotation", &Node::getRotation, &Node::setRotation)
    .property("skewX", &Node::getSkewX, &Node::setSkewX)
    .property("skewY", &Node::getSkewY, &Node::setSkewY)
    .property("name", &Node::getName, &Node::setName)
    .property<val>("children", std::bind(&Node_getChildren, _1))
    ;

  class_<Scene, base<Node>>("cc.Scene")
    .constructor(&Scene::create, allow_raw_pointers())
    ;

  value_object<Vec2>("cc.Vec2")
    .field("x", &Vec2::x)
    .field("y", &Vec2::y)
    ;
  value_object<Color4F>("cc.Color4F")
    .field("r", &Color4F::r)
    .field("g", &Color4F::g)
    .field("b", &Color4F::b)
    .field("a", &Color4F::a)
    ;

  class_<DrawNode, base<Node>>("cc.DrawNode")
    .constructor(&DrawNode::create, allow_raw_pointers())
    .function("drawSegment", &DrawNode::drawSegment, allow_raw_pointers())
    ;
}
