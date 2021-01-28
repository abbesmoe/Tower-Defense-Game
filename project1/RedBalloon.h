/**
 * \file RedBalloon.h
 *
 * \author Alan Wagner
 *
 * Base class for Red Balloon
 */

#pragma once
#include "Balloon.h"

 /**
  * Class that implements the blue balloon.
  */
class CRedBalloon : public CBalloon
{
public:
    CRedBalloon(CGame* game);

    /// Default constructor (disabled)
    CRedBalloon() = delete;

    /// Copy constructor (disabled)
    CRedBalloon(const CRedBalloon&) = delete;

};



