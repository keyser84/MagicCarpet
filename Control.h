/*
Parent class for control input classes
*/

#ifndef CONTROL_H
#define CONTROL_H

#include "Player.h"

class Player;

class Control
{
protected:
    Player* player;
    bool accelerating;
    bool decelerating;
    bool turningLeft;
    bool turningRight;
    bool punchingLeft;
    bool punchingRight;

public:
	Control(Player* player);
	virtual void poll() = 0;
	bool isAccelerating();
	bool isDecelerating();
	bool isTurningLeft();
	bool isTurningRight();
	bool isPunchingLeft();
	bool isPunchingRight();
};

#endif
