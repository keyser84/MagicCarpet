#include "Character.h"

Character::Character(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent)
{
    // lower part
    nodeLower = smgr->addAnimatedMeshSceneNode(smgr->getMesh("data/characterLowerUV.b3d"), parent);
    nodeLower->setMaterialTexture(0, driver->getTexture("data/characterLowerUV.jpg"));
    nodeLower->setScale(vector3df(2,2,2));
    nodeLower->addShadowVolumeSceneNode();
    nodeLower->setAnimationSpeed(0);
    turn(0);
    // upper part
    nodeUpper = smgr->addAnimatedMeshSceneNode(smgr->getMesh("data/characterUpperUV.b3d"), parent);
    nodeUpper->setMaterialTexture(0, driver->getTexture("data/characterUpperUV.jpg"));
    nodeUpper->setScale(vector3df(2,2,2));
    nodeUpper->addShadowVolumeSceneNode();
    nodeUpper->setLoopMode(false);
    nodeUpper->setFrameLoop(60,60);
    nodeUpper->setAnimationSpeed(60);
}

void Character::turn(f32 amount)
{
    s32 currentFrame = 60 - amount * 30;
    nodeLower->setFrameLoop(currentFrame,currentFrame);
}

void Character::punchLeft()
{
    nodeUpper->setFrameLoop(60,120);
}

void Character::punchRight()
{
    nodeUpper->setFrameLoop(1,60);
}
