#ifndef  _MESH_HELPER_H_
#define  _MESH_HELPER_H_

#include "cocos2d.h"

using namespace cocos2d;

class  MeshHelper
{
public:
    static Sprite3D* createBox(float w = 1, float h = 1, float d = 1, unsigned int wSegments = 1, unsigned int hSegments = 1, unsigned int dSegments = 1);
};

#endif

