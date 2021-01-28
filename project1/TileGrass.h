/**
 * \file TileGrass.h
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 *
 * Contains the grass tiles
 */

#pragma once
#include "Tile.h"
#include "Item.h"

 /**
   * Class that implements grass tiles
   */
class CTileGrass : public CTile
{
public:
    /** Accept a visitor
     * param visitor The visitor we accept */
     //virtual void Accept(CTileVisitor* visitor) override { visitor->VisitTile(this); }

    CTileGrass(CGame* game);

    ///  Default constructor (disabled)
    CTileGrass() = delete;

    ///  Copy constructor (disabled)
    CTileGrass(const CTileGrass&) = delete;

    ~CTileGrass();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open);

    /** Sets the hit
    */
    virtual void SetHit() override { mHit = true; }

    /** Sets the item
    * \param item item to set
    */
    virtual void SetItem(std::shared_ptr<CItem> item) override { mCurrentItem = item; }

    /** Gets the item
    * \returns item
    */
    virtual std::shared_ptr<CItem> GetItem() override { return mCurrentItem; };

private:
    /// marks if hit
    bool mHit = false;
    /// tracks current item on grass
    std::shared_ptr<CItem> mCurrentItem;
};

