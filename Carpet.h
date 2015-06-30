/*
Handles carpet display and animations according to game actions
*/

#ifndef CARPET_H
#define CARPET_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Carpet
{

protected:
    IAnimatedMeshSceneNode* node;

public:
    Carpet(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent);
    void fly(f32 amount);
    void turn(f32 amount);
    void setAppearance(int number);
    // TODO: return function for bounding box
};

#endif
