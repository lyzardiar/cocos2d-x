#include "LitSpriteScene.h"

USING_NS_CC;

Scene* LitSpriteScene::scene()
{
    return LitSpriteScene::create();
}

bool LitSpriteScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto sizeInPixels = Director::getInstance()->getWinSizeInPixels();

    auto camera = Camera::createPerspective(60, visibleSize.width / visibleSize.height, 10.0f, 1000);
    camera->setCameraFlag(CameraFlag::USER1);
    addChild(camera);

    Texture2D * diffuseTex = Director::getInstance()->getTextureCache()->addImage("01.png");
    Texture2D * normalTex = Director::getInstance()->getTextureCache()->addImage("01_n.png");
    diffuseTex->setAlphaTexture(normalTex);

	auto billboard = BillBoard::createWithTexture(diffuseTex);
    billboard->setPosition3D(Vec3(0, 0, -500));
    billboard->setCameraMask((unsigned short)CameraFlag::USER1);

    auto shader = GLProgram::createWithFilenames("pos_tex_color.vert", "lit_sprite.frag");
	auto state = GLProgramState::create(shader);
    billboard->setGLProgramState(state);
    addChild(billboard);
    return true;
}
