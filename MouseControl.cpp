#include "MouseControl.h"

MouseControl::MouseControl(Player* player, MastEventReceiver* eventReceiver, int originX, int originY) : Control(player)
{
    this->eventReceiver = eventReceiver;
    this->originX = originX;
    this->originY = originY;
    deadzoneX = 50;
    deadzoneY = 50;
}

void MouseControl::poll()
{
    accelerating = (eventReceiver->mouseY()<originY-deadzoneY);
    decelerating = (eventReceiver->mouseY()>originY+deadzoneY);
    turningLeft = (eventReceiver->mouseX()<originX-deadzoneX);
    turningRight = (eventReceiver->mouseX()>originX+deadzoneX);
    punchingLeft = (eventReceiver->leftMousePressed());
    punchingRight = (eventReceiver->rightMousePressed());
}
