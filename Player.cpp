#include "Player.h"

Player::Player(IVideoDriver* driver, ISceneManager* smgr)
{
    node = smgr->addEmptySceneNode();
    carpet = new Carpet(driver, smgr, node);
    character = new Character(driver, smgr, node);
    stick = new Stick(driver, smgr, node);
    control = NULL;
    speed = 0.0;
    speedMin = 0.0;
    speedMax = 220.0;
    acceleration = 80.0;
    deceleration = 150.0;
    friction = 50.0;
    turningAngle = 0.0;
    turningAngleMin = -80.0;
    turningAngleMax =  80.0;
    turningSpeed = 240.0;
    verticalSpeed = 0.0;
    verticalSpeedMax = 250.0;
}

void Player::setControl(Control* control)
{
	delete this->control;
    this->control = control;
}

ISceneNode* Player::getNode()
{
    return node;
}

void Player::turn(f32 amount)
{
    carpet->turn(amount);
    character->turn(amount);
}

void Player::punchLeft()
{
    character->punchLeft();
    stick->punchLeft();
}

void Player::punchRight()
{
    character->punchRight();
    stick->punchRight();
}

void Player::update(int rate)
{
    // update control status
	control->poll();

    // forward/backward movement
    if (control->isAccelerating())
        speed += acceleration / rate;
    else if (control->isDecelerating())
        speed -= deceleration / rate;
    speed -= friction / rate;
    if (speed < speedMin) speed = speedMin;
    else if (speed > speedMax) speed = speedMax;

    // turning
    if (control->isTurningLeft())
        turningAngle -= turningSpeed / rate;
    else if (control->isTurningRight())
        turningAngle += turningSpeed / rate;
    else
    {
        if (turningAngle > 0)
        {
            turningAngle -= turningSpeed / rate;
            if (turningAngle < 0)
                turningAngle = 0;
        }
        else if (turningAngle < 0)
        {
            turningAngle += turningSpeed / rate;
            if (turningAngle > 0)
                turningAngle = 0;
        }
    }
    if (turningAngle < turningAngleMin)
        turningAngle = turningAngleMin;
    else if (turningAngle > turningAngleMax)
        turningAngle = turningAngleMax;

    // elevation
    verticalSpeed = speed / speedMax * verticalSpeedMax;

    // punching
    if (control->isPunchingLeft())
        punchLeft();
    else if (control->isPunchingRight())
        punchRight();

    // update position and rotation

    vector3df pos = node->getPosition();
    vector3df rot = node->getRotation();

    rot.Y += turningAngle / rate;// * (speed / speedMax);
    rotCos = cos(rot.Y / 180 * PI);
    rotSin = sin(rot.Y / 180 * PI);

    //TODO: do collision and border detection somewhere else!
    // environment
    f32 posXMin = -400.0;
    f32 posXMax =  400.0;
    f32 posZMin = -400.0;
    f32 posZMax =  400.0;
    f32 posYMin = 25.0;
    f32 posYMax = 125.0;
    f32 gravity = 120.0;


    pos.X -= rotSin * speed / rate;
    if (pos.X < posXMin)
        pos.X = posXMin;
    else if (pos.X > posXMax)
        pos.X = posXMax;

    pos.Z -= rotCos * speed / rate;
    if (pos.Z < posZMin)
        pos.Z = posZMin;
    else if (pos.Z > posZMax)
        pos.Z = posZMax;

    pos.Y += (verticalSpeed - gravity) / rate;
    if (pos.Y < posYMin)
        pos.Y = posYMin;
    else if (pos.Y > posYMax)
        pos.Y = posYMax;

    node->setPosition(pos);
    node->setRotation(rot);

    // update turning pose
    turn(turningAngle / turningAngleMax);
}
