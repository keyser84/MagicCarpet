/*
Handles stick display and animations according to game actions
*/

#ifndef STICK_H
#define STICK_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Stick
{

protected:
    IAnimatedMeshSceneNode* node;

public:
    Stick(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent);
    void punchLeft();
    void punchRight();
    // TODO: return function for bounding box
};

#endif
