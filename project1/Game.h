/**
 * \file Game.h
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 *
 *  Class that implements the tower game
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>

#include "XmlNode.h"
#include "Item.h"

 /**
  *  Implements the tower game
  */
class CGame
{

public:
	CGame();
	virtual ~CGame();

    /// The spacing between grid locations
    static const int GridSpacing = 32;

    /** Adds item to vector of items
    * \param item item to add
    */
    void AddItem(std::shared_ptr<CItem> item) { mItems.push_back(item); }

    /** Removes item from vector of items
    * \param item item to remove
    */
    void removeItem(std::shared_ptr<CItem> item);

    /** Test purposes
    * \returns item
    */
    std::vector<std::shared_ptr<CItem> > GetItem() { return mItems; }

    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    void Load(const std::wstring& filename);

    void Clear();

    void Update(double elapsed);

    /** Drops item
    * \param tiles set of tiles
    * \param Grabbed grabbed item
    * \param x x position 
    * \param y y position
    * \returns bool
    */
    bool DropItem(std::vector<CTile*> tiles,std::shared_ptr<CItem> Grabbed, double x, double y);

    /** Sets starting tile
    * \param startY starting y pos
    * \param startX starting x pos
    */
    void SetStartRoadTile(std::wstring startY, std::wstring startX);

    /** Get scale
    * \returns float
    */
    float GetScale() { return mScale; }

    /** Get offset
    * \returns float
    */
    float GetXOffset() { return mXOffset; }

    /** Get offset
    * \returns float
    */
    float GetYOffset() { return mYOffset; }

    /** Sets level
    * \param level level to set
    */
    void SetLevel(int level) { mLevel = level; }

    /** Get level
    * \returns integer
    */
    int GetLevel() { return mLevel; }

    /** Get start
    * \returns pointer to item
    */
    std::shared_ptr<CItem> GetStart();

    /// Accept a visitor for the collection
    void Accept(CItemVisitor* visitor);

    /// Test an x, y click location to see if it clicked on some item in the aquarium.
    std::shared_ptr<CItem> HitTest(double x, double y);

    /// Remove bomb
    void RemoveBomb();

private:
    /// All of the tiles and items that make up our game
    std::vector<std::shared_ptr<CItem> > mItems;

    /// Adjacency lookup support
    std::map<std::pair<int, int>, std::shared_ptr<CTile> > mAdjacency;

    // int mPos = 0;

    /// scale of window
    float mScale = 0;

    /// offsetting x value specific amount
    float mXOffset = 0;

    /// offsetting y value specific amount
    float mYOffset = 0;

    /// sets initial level
    int mLevel = 1;

    /// sets if level is finished
    bool mLevelComplete = false;

    /// counts time
    double mTimeCounter = 0;

};

