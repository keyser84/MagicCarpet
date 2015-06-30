#include "AIControl.h"

AIControl::AIControl(Player* player) : Control(player) {
	state = PURSUE;
}

void AIControl::poll() {
	if(state==PURSUE) {
		pursue(vector3df(0,25,0));
	}
	else if (state==FLEE) {
		flee(vector3df(0,25,0));
	}
}

void AIControl::pursue(vector3df target) {
    // calculate difference vector
	vector3df diffVec = player->getNode()->getPosition() - target;
	double targetAngle = atan2(diffVec.X, diffVec.Z);
	targetAngle = targetAngle / PI * 180;
	// DEBUG
	//printf("current angle: %.1f\ttarget angle: %.1f\n", node->getRotation().Y, targetAngle);
	//printf("dist: %.1f\tdifference: %.1f %.1f %.1f\n", diffVec.getLength(), diffVec.X, diffVec.Y, diffVec.Z);
    // check if close to target
    if(diffVec.X < 10 && diffVec.Z < 10) {
        // punch
        // TODO detect direction
        player->punchLeft();
        //player->punchRight();
    }
	// TODO tolerance limits
	// TODO better way for rotation (determine minimum angle)
	// turn to target
	if(targetAngle > player->getNode()->getRotation().Y) {
		turningLeft = false;
		turningRight = true;
	}
	else {
		turningLeft = true;
		turningRight = false;
	}
	// approach target
	f32 approachDistance = 8;
	if(diffVec.getLength() > approachDistance) {
		accelerating = true;
		decelerating = false;
	}
	else {
		accelerating = false;
		decelerating = true;
	}
	// adjust height
	if(diffVec.Y > 0) {
		accelerating = false;
	}
}

void AIControl::flee(vector3df target) {
	// TODO
}
