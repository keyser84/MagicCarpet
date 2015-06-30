#include "Control.h"

Control::Control(Player* player) {
	this->player = player;
	accelerating = false;
    decelerating = false;
    turningLeft = false;
    turningRight = false;
    punchingLeft = false;
    punchingRight = false;
}

bool Control::isAccelerating() {
	return accelerating;
}

bool Control::isDecelerating() {
	return decelerating;
}

bool Control::isTurningLeft() {
	return turningLeft;
}

bool Control::isTurningRight() {
	return turningRight;
}

bool Control::isPunchingLeft() {
	return punchingLeft;
}

bool Control::isPunchingRight() {
	return punchingRight;
}
