#include "EmptyControl.h"

EmptyControl::EmptyControl(Player* player) : Control(player) {
	// nothing to be done in here...
}

void EmptyControl::poll() {
	// no controlling in here...
}
