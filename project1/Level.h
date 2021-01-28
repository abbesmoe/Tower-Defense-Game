/**
 * \file Level.h
 *
 * \author Jacob Riggs, Mingzhe Huang
 *
 * Implements the base level class.
 */


#pragma once
#include "Game.h"

 /**
  * Class that implements the base level class.
  */
class CLevel
{
public:
    ///  Default constructor (disabled)
    CLevel() = delete;

    ///  Copy constructor (disabled)
    CLevel(const CLevel&) = delete;

    CLevel(CGame* game);

    virtual ~CLevel();

    /** On draw
    * \param graphics graphics to import
    */
    void OnDraw(Gdiplus::Graphics* graphics);

    /// Add item to the item vector 
    void Add(std::shared_ptr<CItem> item);

    /** getter for item
    * \returns item
    */
    std::vector<std::shared_ptr<CItem> > GetItem() { return mItem; }

    /** Getter for game
    * \returns game
    */
    CGame* GetGame() const { return mGame; }

    /** Sets the score
    * \param score score to set to
    */
    void SetScore(int score) { mScore = score; }

    /// Increment the score by 1
    void IncrementScore() { mScore += 1; }

    /// Decrement the score by 1
    void DecrementScore() { mScore -= 1; }

    /** Gets score
    * \returns integer of score
    */
    int GetScore() { return mScore; }

    /** Set certain item to an empty pointer when
    *   it is touched by a dart
    * \param item item to delete
    */
    void SetDelete(CItem* item);

    void DeleteItem(std::shared_ptr<CItem> item);

private:
    /// the game we are currently playing
    CGame* mGame;

    /// score of current level
    int mScore = 0;

    /// All of the items that make up our level
    std::vector<std::shared_ptr<CItem> > mItem;

};