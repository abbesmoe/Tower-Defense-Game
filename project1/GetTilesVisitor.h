/**
 * \file GetTilesVisitor.h
 *
 * \author Moez Abbes
 *
 * Tile visitor base class.
 */

#pragma once
#include "ItemVisitor.h"
#include <vector>

/**
 * Tile visitor base class.
 */
class CGetTilesVisitor :
    public CItemVisitor
{
public:
    /** Visits a tile
    * \param tile tile to visit
    */
    virtual void VisitTile(CTile* tile) override { mTiles.push_back(tile); }

    /** Gets tiles list
    * \returns vector of tiles
    */
    std::vector<CTile*> GetTiles() { return mTiles; }

private:
    /// vector of tiles
    std::vector<CTile*> mTiles;

};

