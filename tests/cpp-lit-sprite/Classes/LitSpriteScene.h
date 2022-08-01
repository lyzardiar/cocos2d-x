#ifndef __LIT_SPRITE_SCENE_H__
#define __LIT_SPRITE_SCENE_H__

#include "cocos2d.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"

class LitSpriteScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* scene();
    CREATE_FUNC(LitSpriteScene);
	virtual bool init() override;

private:
    
};

#endif // __LIT_SPRITE_SCENE_H__
