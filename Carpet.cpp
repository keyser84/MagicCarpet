#include "Carpet.h"

Carpet::Carpet(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent)
{
    node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("data/carpetWaveUV.md3"), parent);
    node->setScale(vector3df(2,2,2));
    node->setMaterialTexture(0, driver->getTexture("data/carpetWaveUV.jpg"));
    // not working, because of .md3 or vertex animation?
    //node->addShadowVolumeSceneNode();
    node->setFrameLoop(48,64);
    node->setAnimationSpeed(30);
    // add unanimated transparent node for fake shadow
    IAnimatedMeshSceneNode* nodeShadow = smgr->addAnimatedMeshSceneNode(smgr->getMesh("data/carpetStaticTrans.b3d"), node);
    nodeShadow->setMaterialFlag(EMF_LIGHTING, false);
    nodeShadow->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
    nodeShadow->setMaterialTexture(0, driver->getTexture("data/transparent.png"));
    nodeShadow->addShadowVolumeSceneNode();
}

void Carpet::fly(f32 amount)
{
    // TODO: set animation speed of wave animation
}

void Carpet::turn(f32 amount)
{
    vector3df point(0,0,0);
    vector3df center(0,4,0);
    vector3df rotation(0,0,amount * 30);
    point -= center;
    matrix4 m;
    m.setRotationDegrees(rotation);
    m.rotateVect(point);
    point += center;
    node->setPosition(point);
    node->setRotation(rotation);
}

void Carpet::setAppearance(int number)
{
    // TODO: change texture
}
