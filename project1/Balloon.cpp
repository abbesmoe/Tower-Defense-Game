/**
 * \file Balloon.cpp
 *
 * \author Alan Wagner
 */

#include "pch.h"
#include "Balloon.h"
using namespace std;
using namespace Gdiplus;

/**  Constructor for the balloon
 * \param game the game the we are using
 */
CBalloon::CBalloon(CGame* game) : CItem(game)
{
}

/**
*  Destructor
*/
CBalloon::~CBalloon()
{
}

void CBalloon::Draw(Gdiplus::Graphics* graphics)
{
	CItem::Draw(graphics);
}

/// Handle updates for animation
/// \param elapsed The time since the last update
void CBalloon::Update(double elapsed)
{
	mT += 2.0 * elapsed;

	if (mCurrentTile->GetType() == L"EW") {
		mCurrentTile->PlaceBalloonEW(this);
	}
	if (mCurrentTile->GetType() == L"NS") {
		mCurrentTile->PlaceBalloonNS(this);
	}
	if (mCurrentTile->GetType() == L"NE") {
		mCurrentTile->PlaceBalloonNE(this);
	}
	if (mCurrentTile->GetType() == L"NW") {
		mCurrentTile->PlaceBalloonNW(this);
	}
	if (mCurrentTile->GetType() == L"SE") {
		mCurrentTile->PlaceBalloonSE(this);
	}
	if (mCurrentTile->GetType() == L"SW") {
		mCurrentTile->PlaceBalloonSW(this);
	}

	//SetLocation(GetX() + elapsed, GetY() + elapsed);
}
