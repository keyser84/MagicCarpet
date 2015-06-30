/*
Provides an empty, "null" control
*/

#ifndef EMPTYCONTROL_H
#define EMPTYCONTROL_H

#include "Control.h"
#include "Player.h"

class EmptyControl : public Control
{
public:
	EmptyControl(Player* player);
	void poll();
};

#endif
