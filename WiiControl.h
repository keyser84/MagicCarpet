/*
Manages control input by Wiimotes and Wiiboards
*/

#ifndef WIICONTROL_H
#define WIICONTROL_H

#include "Control.h"
#include "Player.h"

class WiiControl : public Control
{
protected:
	int wiimoteID;

public:
	WiiControl(Player* player, int wiimoteID);
};

#endif
