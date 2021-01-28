
/**
 * \file BlueBalloon.cpp
 *
 * \author Alan Wagner
 */

#include "pch.h"
#include "BlueBalloon.h"
using namespace std;
using namespace Gdiplus;
/// speed balloon travels at
const double speed = 4;
/// times it takes to hit and pop balloon
const int lives = 2;

/** Constructor
* \param game The game this is a member of
*/
CBlueBalloon::CBlueBalloon(CGame* game) : CBalloon(game)
{
    SetSpeed(speed);
    SetPopped(false);
    SetLives(lives);
}








