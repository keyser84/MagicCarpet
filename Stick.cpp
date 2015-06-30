#include "Stick.h"

Stick::Stick(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent)
{
    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("data/characterStickFix.b3d"), parent);
    node->setMaterialTexture(0, driver->getTexture("data/characterStickFix.jpg"));
    node->setScale(vector3df(2,2,2));
    node->addShadowVolumeSceneNode();
    node->setLoopMode(false);
    node->setFrameLoop(60,60);
    node->setAnimationSpeed(60);
}

void Stick::punchLeft()
{
    node->setFrameLoop(60,120);
}

void Stick::punchRight()
{
    node->setFrameLoop(1,60);
}
