#include "KeyboardControl.h"

KeyboardControl::KeyboardControl(Player* player, MastEventReceiver* eventReceiver) : Control(player) {
	this->eventReceiver = eventReceiver;
}

void KeyboardControl::poll() {
	accelerating = eventReceiver->keyDown(KEY_UP);
	decelerating = eventReceiver->keyDown(KEY_DOWN);
	turningLeft = eventReceiver->keyDown(KEY_LEFT);
	turningRight = eventReceiver->keyDown(KEY_RIGHT);
	punchingLeft = eventReceiver->keyPressed(KEY_KEY_A);
	punchingRight = eventReceiver->keyPressed(KEY_KEY_D);
}
