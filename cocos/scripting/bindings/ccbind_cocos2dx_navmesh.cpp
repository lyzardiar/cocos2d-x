#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_navmesh.hpp"
#if CC_USE_NAVMESH
#include "navmesh/CCNavMesh.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_navmesh) {


  class_<NavMeshAgent, base<Component>>("jsb.NavMeshAgent")
    .constructor<>()
    .function("setMaxSpeed", &NavMeshAgent::setMaxSpeed, allow_raw_pointers())
    .function("syncToNode", &NavMeshAgent::syncToNode, allow_raw_pointers())
    .function("completeOffMeshLink", &NavMeshAgent::completeOffMeshLink, allow_raw_pointers())
    .function("getSeparationWeight", &NavMeshAgent::getSeparationWeight, allow_raw_pointers())
    .function("setAutoTraverseOffMeshLink", &NavMeshAgent::setAutoTraverseOffMeshLink, allow_raw_pointers())
    .function("getCurrentVelocity", &NavMeshAgent::getCurrentVelocity, allow_raw_pointers())
    .function("syncToAgent", &NavMeshAgent::syncToAgent, allow_raw_pointers())
    .function("isOnOffMeshLink", &NavMeshAgent::isOnOffMeshLink, allow_raw_pointers())
    .function("setSeparationWeight", &NavMeshAgent::setSeparationWeight, allow_raw_pointers())
    .function("pause", &NavMeshAgent::pause, allow_raw_pointers())
    .function("setAutoOrientation", &NavMeshAgent::setAutoOrientation, allow_raw_pointers())
    .function("getHeight", &NavMeshAgent::getHeight, allow_raw_pointers())
    .function("getMaxSpeed", &NavMeshAgent::getMaxSpeed, allow_raw_pointers())
    .function("getCurrentOffMeshLinkData", &NavMeshAgent::getCurrentOffMeshLinkData, allow_raw_pointers())
    .function("getRadius", &NavMeshAgent::getRadius, allow_raw_pointers())
    .function("setSyncFlag", &NavMeshAgent::setSyncFlag, allow_raw_pointers())
    .function("getSyncFlag", &NavMeshAgent::getSyncFlag, allow_raw_pointers())
    .function("resume", &NavMeshAgent::resume, allow_raw_pointers())
    .function("stop", &NavMeshAgent::stop, allow_raw_pointers())
    .function("getVelocity", &NavMeshAgent::getVelocity, allow_raw_pointers())
    .function("setMaxAcceleration", &NavMeshAgent::setMaxAcceleration, allow_raw_pointers())
    .function("setOrientationRefAxes", &NavMeshAgent::setOrientationRefAxes, allow_raw_pointers())
    .function("getMaxAcceleration", &NavMeshAgent::getMaxAcceleration, allow_raw_pointers())
    .function("setHeight", &NavMeshAgent::setHeight, allow_raw_pointers())
    .function("getObstacleAvoidanceType", &NavMeshAgent::getObstacleAvoidanceType, allow_raw_pointers())
    .function("setRadius", &NavMeshAgent::setRadius, allow_raw_pointers())
    .function("setObstacleAvoidanceType", &NavMeshAgent::setObstacleAvoidanceType, allow_raw_pointers())
    .class_function("getNavMeshAgentComponentName", &NavMeshAgent::getNavMeshAgentComponentName, allow_raw_pointers())
    .class_function("create", &NavMeshAgent::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMeshAgent& _) -> std::string {return "NavMeshAgent";}))    
    ;


  class_<NavMeshObstacle, base<Component>>("jsb.NavMeshObstacle")
    .constructor<>()
    .function("getSyncFlag", &NavMeshObstacle::getSyncFlag, allow_raw_pointers())
    .function("initWith", &NavMeshObstacle::initWith, allow_raw_pointers())
    .function("syncToObstacle", &NavMeshObstacle::syncToObstacle, allow_raw_pointers())
    .function("syncToNode", &NavMeshObstacle::syncToNode, allow_raw_pointers())
    .function("getHeight", &NavMeshObstacle::getHeight, allow_raw_pointers())
    .function("setSyncFlag", &NavMeshObstacle::setSyncFlag, allow_raw_pointers())
    .function("getRadius", &NavMeshObstacle::getRadius, allow_raw_pointers())
    .class_function("create", &NavMeshObstacle::create, allow_raw_pointers())
    .class_function("getNavMeshObstacleComponentName", &NavMeshObstacle::getNavMeshObstacleComponentName, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMeshObstacle& _) -> std::string {return "NavMeshObstacle";}))    
    ;


  class_<NavMesh>("jsb.NavMesh")
    .constructor<>()
    .function("removeNavMeshObstacle", &NavMesh::removeNavMeshObstacle, allow_raw_pointers())
    .function("removeNavMeshAgent", &NavMesh::removeNavMeshAgent, allow_raw_pointers())
    .function("update", &NavMesh::update, allow_raw_pointers())
    .function("isDebugDrawEnabled", &NavMesh::isDebugDrawEnabled, allow_raw_pointers())
    .function("addNavMeshAgent", &NavMesh::addNavMeshAgent, allow_raw_pointers())
    .function("addNavMeshObstacle", &NavMesh::addNavMeshObstacle, allow_raw_pointers())
    .function("setDebugDrawEnable", &NavMesh::setDebugDrawEnable, allow_raw_pointers())
    .function("debugDraw", &NavMesh::debugDraw, allow_raw_pointers())
    .class_function("create", &NavMesh::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMesh& _) -> std::string {return "NavMesh";}))    
    ;}