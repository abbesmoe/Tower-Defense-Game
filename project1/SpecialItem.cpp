/**
 * \file SpecialItem.cpp
 *
 * \author Alan Wagner
 */

#include "pch.h"
#include "SpecialItem.h"
using namespace std;
using namespace Gdiplus;

/** Constructor
* \param game The game this is a member of
*/
CSpecialItem::CSpecialItem(CGame* game) : CBalloon(game)
{
}
