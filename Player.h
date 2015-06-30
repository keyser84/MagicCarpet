/*
Handles a player including character, carpet, stick, control, cameras
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <irrlicht.h>
#include "Carpet.h"
#include "Character.h"
#include "Stick.h"
#include "Control.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Control;

class Player
{

protected:
    ISceneNode* node;
    Carpet* carpet;
    Character* character;
    Stick* stick;
    Control* control;
    enum tControl {EMPTY,KEYBOARD,AI,MOUSE,WII} controlType;
    f32 speed;
    f32 speedMin;
    f32 speedMax;
    f32 acceleration;
    f32 deceleration;
    f32 friction;
    f32 turningAngle;
    f32 turningAngleMin;
    f32 turningAngleMax;
    f32 turningSpeed;
    f32 verticalSpeed;
    f32 verticalSpeedMax;
    f32 rotCos;
    f32 rotSin;

public:
    Player(IVideoDriver* driver, ISceneManager* smgr);
    void setControl(Control* control);
    ISceneNode* getNode();
    void turn(f32 amount);
    void punchLeft();
    void punchRight();
    void update(int rate);
};

#endif
