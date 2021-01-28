/**
 * \file Level.cpp
 *
 * \author Jacob Riggs, Mingzhe Huang
 */

#include "pch.h"
#include "Level.h"
#include "Game.h"

using namespace std;


/**
 * Constructor for a level.
 * \param game game that the level is part of
 */
CLevel::CLevel(CGame* game)
{
    mGame = game;
}

/**
*  Destructor
*/
CLevel::~CLevel()
{
}

void CLevel::OnDraw(Gdiplus::Graphics* graphics) {}

/**  Add a item to the level
 * \param item New item to add
 */
void CLevel::Add(std::shared_ptr<CItem> item)
{
    mItem.push_back(item);
}

/**  delete an item in mItem
* \param item that needs to be delete
*/
void CLevel::DeleteItem(std::shared_ptr<CItem> item)
{
    auto loc = find(::begin(mItem), ::end(mItem), item);
    if (loc != ::end(mItem))
    {
        mItem.erase(loc);
    }
}