/*
Handles the arena including skydome/skybox, terrain, objects, light (ambient and sun), etc.
*/

#ifndef ARENA_H
#define ARENA_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Arena
{
protected:
    // TODO: include arena boundaries (x,y,z) + getters
    static const int numAppearances = 2;
    int appearance;
    ISceneNode* sky[numAppearances];
    ILightSceneNode* sun[numAppearances];
    ITerrainSceneNode* terrain[numAppearances];

public:
    Arena(IVideoDriver* driver, ISceneManager* smgr);
    int getAppearance();
    void setAppearance(int number);
};

#endif
