/**
 * \file BlackBalloon.cpp
 *
 * \author Alan Wagner
 */

#include "pch.h"
#include "BlackBalloon.h"
using namespace std;
using namespace Gdiplus;
/// constant speed of the black balloon
const double speed = 8;
/// times it takes to hit and pop balloon
const int lives = 1;

/** Constructor
* \param game The game this is a member of
*/
CBlackBalloon::CBlackBalloon(CGame* game) : CBalloon(game)
{
    SetSpeed(speed);
    SetPopped(false);
    SetLives(lives);
}