#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_navmesh.hpp"
#if CC_USE_NAVMESH
#include "navmesh/CCNavMesh.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_navmesh) {


  class_<NavMeshAgent, base<Component>>("jsb.NavMeshAgent")
    .constructor(&cc_bindings_constructor<NavMeshAgent>, allow_raw_pointers())
    .function("setMaxSpeed", &NavMeshAgent::setMaxSpeed)
    .function("syncToNode", &NavMeshAgent::syncToNode)
    .function("completeOffMeshLink", &NavMeshAgent::completeOffMeshLink)
    .function("getSeparationWeight", &NavMeshAgent::getSeparationWeight)
    .function("setAutoTraverseOffMeshLink", &NavMeshAgent::setAutoTraverseOffMeshLink)
    .function("getCurrentVelocity", &NavMeshAgent::getCurrentVelocity)
    .function("syncToAgent", &NavMeshAgent::syncToAgent)
    .function("isOnOffMeshLink", &NavMeshAgent::isOnOffMeshLink)
    .function("setSeparationWeight", &NavMeshAgent::setSeparationWeight)
    .function("pause", &NavMeshAgent::pause)
    .function("setAutoOrientation", &NavMeshAgent::setAutoOrientation)
    .function("getHeight", &NavMeshAgent::getHeight)
    .function("getMaxSpeed", &NavMeshAgent::getMaxSpeed)
    .function("getCurrentOffMeshLinkData", &NavMeshAgent::getCurrentOffMeshLinkData)
    .function("getRadius", &NavMeshAgent::getRadius)
    .function("setSyncFlag", optional_override(
        [](NavMeshAgent& this_, int32_t arg0){
        return this_.setSyncFlag((const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag&)arg0);
      }))
    .function("getSyncFlag", optional_override(
        [](NavMeshAgent& this_){
        return (int32_t)this_.getSyncFlag();
      }))
    .function("resume", &NavMeshAgent::resume)
    .function("stop", &NavMeshAgent::stop)
    .function("setMaxAcceleration", &NavMeshAgent::setMaxAcceleration)
    .function("setOrientationRefAxes", &NavMeshAgent::setOrientationRefAxes)
    .function("getMaxAcceleration", &NavMeshAgent::getMaxAcceleration)
    .function("setHeight", &NavMeshAgent::setHeight)
    .function("getObstacleAvoidanceType", &NavMeshAgent::getObstacleAvoidanceType)
    .function("getVelocity", &NavMeshAgent::getVelocity)
    .function("setRadius", &NavMeshAgent::setRadius)
    .function("setObstacleAvoidanceType", &NavMeshAgent::setObstacleAvoidanceType)
    .class_function("getNavMeshAgentComponentName", &NavMeshAgent::getNavMeshAgentComponentName)
    .class_function("create", &NavMeshAgent::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMeshAgent& _) -> std::string {return "NavMeshAgent";}))    
    ;


  class_<NavMeshObstacle, base<Component>>("jsb.NavMeshObstacle")
    .constructor(&cc_bindings_constructor<NavMeshObstacle>, allow_raw_pointers())
    .function("getSyncFlag", optional_override(
        [](NavMeshObstacle& this_){
        return (int32_t)this_.getSyncFlag();
      }))
    .function("initWith", &NavMeshObstacle::initWith)
    .function("syncToObstacle", &NavMeshObstacle::syncToObstacle)
    .function("syncToNode", &NavMeshObstacle::syncToNode)
    .function("getHeight", &NavMeshObstacle::getHeight)
    .function("setSyncFlag", optional_override(
        [](NavMeshObstacle& this_, int32_t arg0){
        return this_.setSyncFlag((const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag&)arg0);
      }))
    .function("getRadius", &NavMeshObstacle::getRadius)
    .class_function("create", &NavMeshObstacle::create, allow_raw_pointers())
    .class_function("getNavMeshObstacleComponentName", &NavMeshObstacle::getNavMeshObstacleComponentName)
    .property("_className",  optional_override([](const NavMeshObstacle& _) -> std::string {return "NavMeshObstacle";}))    
    ;


  class_<NavMesh>("jsb.NavMesh")
    .constructor(&cc_bindings_constructor<NavMesh>, allow_raw_pointers())
    .function("removeNavMeshObstacle", &NavMesh::removeNavMeshObstacle, allow_raw_pointers())
    .function("removeNavMeshAgent", &NavMesh::removeNavMeshAgent, allow_raw_pointers())
    .function("update", &NavMesh::update)
    .function("isDebugDrawEnabled", &NavMesh::isDebugDrawEnabled)
    .function("addNavMeshAgent", &NavMesh::addNavMeshAgent, allow_raw_pointers())
    .function("addNavMeshObstacle", &NavMesh::addNavMeshObstacle, allow_raw_pointers())
    .function("setDebugDrawEnable", &NavMesh::setDebugDrawEnable)
    .function("debugDraw", &NavMesh::debugDraw, allow_raw_pointers())
    .class_function("create", &NavMesh::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMesh& _) -> std::string {return "NavMesh";}))    
    ;
}

#endif
