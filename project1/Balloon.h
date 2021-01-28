/**
 * \file Balloon.h
 *
 * \author Alan Wagner
 *
 * Base class for Balloon object
 */

#pragma once
#include "Item.h"


 /**
  * Base class for ballon object
  */
class CBalloon : public CItem
{
public:
    CBalloon(CGame* game);

    /// Default constructor (disabled)
    CBalloon() = delete;

    /// Copy constructor (disabled)
    CBalloon(const CBalloon&) = delete;

    ///destructor
    ~CBalloon();

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /**
    * Sets the image of balloon
    * \param file file name of balloon image
    * \param startTile starting tile
    */
    virtual void Balloon(std::wstring file, std::shared_ptr<CItem> startTile) override { SetImage(file); mCurrentTile = startTile; }

    /**
    * Gets position on tile
    * \returns mT
    */
    float GetT() { return mT; }

    /**
    * Checks if ballloon is moving forward
    * \returns forward
    */
    bool IsForward() { return forward; }

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloon(this); }

    /**
    * Checks if balloon is popped
    * \returns mIsPopped
    */
    bool IsPopped() { return mIsPopped; }

    /**
    * Sets if balloon is popped
    * \param popped sets popped
    */
    void SetPopped(bool popped) { mIsPopped = popped; }

    /**
    * Gets speed of balloon
    * \returns mSpeed
    */
    double GetSpeed() { return mSpeed;  }

    /**
    * Sets speed of balloon
    * \param speed sets speed
    */
    void SetSpeed(double speed) { mSpeed = speed; }

    /**
    * Sets amount of lives balloon has
    * \param lives lives to set
    */
    void SetLives(int lives) { mLives = lives; }

    /**
    * Gets lives left on balloon
    * \returns mLives
    */
    int GetLives() { return mLives; }


private:
    /// bool that tracks if balloon should be removed
    bool mIsPopped = false;

    /// double that holds the speed of the balloon
    double mSpeed = 0;

    /// integer that tells how many times the balloon can be hit before popping
    int mLives = 1;

    /// 0 for when the balloon enters the tile and 1 when it exits
    float mT = 0;

    /// forward true means south to north, west to east
    /// forward false means north to south, east to west
    bool forward = true;

     /// Tile balloon is currently on
     std::shared_ptr<CItem> mCurrentTile;
};









