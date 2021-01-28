/**
 * \file SpecialItem.h
 *
 * \author Alan Wagner
 *
 * Base class for Special Item
 */

#pragma once
#include "Balloon.h"


/**
 * Class that implements the special item which is the balloon that instantly destroys the tower
 * that pops this balloon.
 */
class CSpecialItem : public CBalloon
{
public:
    CSpecialItem(CGame* game);

    /// Default constructor (disabled)
    CSpecialItem() = delete;

    /// Copy constructor (disabled)
    CSpecialItem(const CSpecialItem&) = delete;

};



