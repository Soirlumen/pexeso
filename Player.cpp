#include "Player.h"

void Player::setScore(unsigned int _s)
{
    score=_s;
}

Player::Player(std::string _n) : name(_n), score(0)
{}

std::string Player::getName() const
{
    return name;
}

unsigned int Player::getScore() const
{
    return score;
}

void Player::addScore()
{
    setScore(getScore()+1);
}

Player::~Player()
{

}