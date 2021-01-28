

/**
 * \file BlackBalloon.h
 *
 * \author Alan Wagner
 *
 * Base class for Black Balloon
 */

#pragma once
#include "Balloon.h"

/**
 * Class that implements the black balloon.
 */
class CBlackBalloon : public CBalloon
{
public:
    CBlackBalloon(CGame* game);

    /// Default constructor (disabled)
    CBlackBalloon() = delete;

    /// Copy constructor (disabled)
    CBlackBalloon(const CBlackBalloon&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBlackBalloon(this); }
};






