/**
 * \file ControlPanel.h
 *
 * \author Jacob Riggs
 *
 * 
 */


#pragma once
#include <memory>
#include <string>
#include "Item.h"
#include "Tile.h"

class CGame;

/**
 * Control panel class that does a lot of the calls to draw and update.
 */
class CControlPanel
{
public:
	/** Constructor for game
	* \param game pointer to game instantiation
	*/
    CControlPanel(CGame* game);

    /// Default constructor (disabled)
    CControlPanel() = delete;

    /// Copy constructor (disabled)
    CControlPanel(const CControlPanel&) = delete;

    ~CControlPanel();

    void DrawSidebar(Gdiplus::Graphics* graphics);

    std::shared_ptr<CItem> HitTest(double x, double y);

	/** Drops the item
	* \param Grabbed item grabbed
	* \param tile tile to drop on
	* \param x x position
	* \param y y position
	* \returns bool
	*/
	bool IsDrop(std::shared_ptr<CItem> Grabbed, CTile* tile, double x, double y);

	/**
	* Creates the first balloon in list
	*/
	void CreateFirstBalloon();

private:
    /// The game this item is contained in
    CGame* mGame;

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

	/// Image for tower eight
	std::unique_ptr<Gdiplus::Bitmap> mTowerEight;

	/// Image for ring tower
	std::unique_ptr<Gdiplus::Bitmap> mRingTower;

	/// Image for bomb
	std::unique_ptr<Gdiplus::Bitmap> mBomb;

	/// Image for go
	std::unique_ptr<Gdiplus::Bitmap> mGo;

	/// bomb numbers
	double mBombNumber = 0;
};

