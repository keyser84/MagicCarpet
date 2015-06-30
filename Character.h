/*
Handles character display and animations according to game actions
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Character
{

protected:
    IAnimatedMeshSceneNode* nodeLower;
    IAnimatedMeshSceneNode* nodeUpper;

public:
    Character(IVideoDriver* driver, ISceneManager* smgr, ISceneNode* parent);
    void turn(f32 amount);
    void punchLeft();
    void punchRight();
    // TODO: return function for bounding box

};

#endif
