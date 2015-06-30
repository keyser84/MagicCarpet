/*
Manages control input from the mouse
*/

#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H

#include "Control.h"
#include "Player.h"
#include "MastEventReceiver.cpp"

class MouseControl : public Control
{
protected:
	MastEventReceiver* eventReceiver;
	int originX;
	int originY;
	int deadzoneX;
	int deadzoneY;

public:
	MouseControl(Player* player, MastEventReceiver* eventReceiver, int originX, int originY);
	void poll();
	// TODO: get deadzone to display control indicator
};

#endif
