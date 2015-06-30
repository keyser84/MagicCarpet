/*
Provides an AI control
*/

#ifndef AICONTROL_H
#define AICONTROL_H

#include <irrlicht.h>
#include "Control.h"
#include "Player.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class AIControl : public Control
{
protected:
	enum tState {PURSUE, FLEE} state;
    void pursue(vector3df target);
    void flee(vector3df target);

public:
	AIControl(Player* player);
	void poll();
};

#endif
