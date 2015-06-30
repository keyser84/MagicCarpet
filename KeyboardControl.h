/*
Manages control input from the keyboard
*/

#ifndef KEYBOARDCONTROL_H
#define KEYBOARDCONTROL_H

#include "Control.h"
#include "Player.h"
#include "MastEventReceiver.cpp"

class KeyboardControl : public Control
{
protected:
	MastEventReceiver* eventReceiver;

public:
	KeyboardControl(Player* player, MastEventReceiver* eventReceiver);
	void poll();
};

#endif
