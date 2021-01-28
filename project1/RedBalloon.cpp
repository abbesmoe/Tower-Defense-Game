/**
 * \file RedBalloon.cpp
 *
 * \author Alan Wagner
 */

#include "pch.h"
#include "RedBalloon.h"
using namespace std;
using namespace Gdiplus;
/// speed balloon travels
const double speed = 5.5;
/// times it takes to hit and pop balloon
const int lives = 1;

/** Constructor
* \param game The game this is a member of
*/
CRedBalloon::CRedBalloon(CGame* game) : CBalloon(game)
{
    SetSpeed(speed);
    SetPopped(false);
    SetLives(lives);
}

