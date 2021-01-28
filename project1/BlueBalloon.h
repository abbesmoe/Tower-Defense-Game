/**
 * \file BlueBalloon.h
 *
 * \author Alan Wagner
 *
 * Base class for Blue Balloon
 */

#pragma once
#include "Balloon.h"


/**
 * Class that implements the blue balloon.
 */
class CBlueBalloon : public CBalloon
{
public:
    CBlueBalloon(CGame* game);

    /// Default constructor (disabled)
    CBlueBalloon() = delete;

    /// Copy constructor (disabled)
    CBlueBalloon(const CBlueBalloon&) = delete;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBlueBalloon(this); }
};












