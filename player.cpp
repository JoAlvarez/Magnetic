#include "player.h"

Player::Player()
{
	input = Input::getInstance();
    score = 0;
    souls = 0;
}

void Player::checkInput()
{
    if( input->isKeyDown( "-" ) || input->leftMouseDown())
    {
		p = NEGATIVE;
		ball->setCharge( p );
    }
    else if( input->isKeyDown( "+" ) || input->rightMouseDown())
    {
		p = POSITIVE;
		ball->setCharge( p );
    }
    else
    {
        p = NEUTRAL;
		ball->setCharge( p );
    }
}

void Player::startTimer()
{
    times->start();
}

void Player::stopTimer()
{
    times->stop();
}

double Player::getScore()
{
    return times->getTimePassed();
}

Polarity Player::getPolarity()
{
    return p;
}

int Player::getLives()
{
    return souls;
}

void Player::setPlayerBall( Ball * b )
{
    ball = b;
}
Ball* Player::getBall()
{
    return ball;
}
Player::~Player()
{
    input->release();
}
