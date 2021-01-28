/**
 * \file Tile.h
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 *
 * Base class for any tile in our game
 */

#pragma once

#include "Item.h"
#include "Declaration.h"
#include "XmlNode.h"
#include <string>
#include <memory>
#include <vector>

class CGame;

/**
*  Implements the Tiles
*/
class CTile : public CItem
{
public:
    /// How much we offset drawing the tile to the left of the center
    const static int OffsetLeft = 612;

    /// How much we offset drawing the tile above the center
    const static int OffsetDown = 1024;

    CTile(CGame* game);

    ///  Default constructor (disabled)
    CTile() = delete;

    ///  Copy constructor (disabled)
    CTile(const CTile&) = delete;

    virtual ~CTile();

    /** The directory were the images are stored */
    static const std::wstring ImagesDirectory;

    void SetImage(const std::wstring& file);

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /** Sets the hit
    */
    virtual void SetHit() {};

    /** Sets the item
    * \param item item to set
    */
    virtual void SetItem(std::shared_ptr<CItem> item) override {};

    /** Gets the item
    * \returns item that you got
    */
    virtual std::shared_ptr<CItem> GetItem() override { return nullptr; }

    /**  Test this item to see if it has been clicked on
    * \param x X location on the aquarium to test
    * \param y Y location on the aquarium to test
    * \return true if clicked on */
    virtual bool HitTest(int x, int y);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open);

    /**  The X location of the center of the tile
    * \returns X location in pixels */
    virtual double GetX() const override { return mX*64; }

    /**  The Y location of the center of the tile
    * \returns Y location in pixels */
    virtual double GetY() const override { return mY*64; }

    /**  Set the item location
    * \param x X location
    * \param y Y location */
    void SetLocation(double x, double y) { mX = x; mY = y; }

    /** Sets the directions
    * \param road tile that is north
    */
    virtual void SetNorth(std::shared_ptr<CTile> road) {}

    /** Sets the directions
    * \param road tile that is south
    */
    virtual void SetSouth(std::shared_ptr<CTile> road) {}

    /** Sets the directions
    * \param road tile that is east
    */
    virtual void SetEast(std::shared_ptr<CTile> road) {}

    /** Sets the directions
    * \param road tile that is west
    */
    virtual void SetWest(std::shared_ptr<CTile> road) {}

    /// Get the width of the game
    /// \returns game width
    int GetWidth() const { return mItemImage->GetWidth(); }

    /// Get the height of the game
    /// \returns game height
    int GetHeight() const { return mItemImage->GetHeight(); }

    /**  Get the file name for this tile image
     * \returns Filename or blank if none */
    std::wstring GetFile() { return mFile; }

    /** Gets the declarations
    * \returns vector of declarations
    */
    std::vector<std::shared_ptr<CDeclaration> > GetDeclaration() { return mDeclarations; }

    /** Adds a dec to vector
    * \param declaration to be added
    */
    void AddDeclaration(std::shared_ptr<CDeclaration> declaration) { 
        mDeclarations.push_back(declaration);
    }

    /** Checks if open
    * \returns bool if open
    */
    virtual bool IsOpen() override { return mOpen; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTile(this); }

private:
    // Item location in the aquarium
    double mX = 0;     ///< X location for the center of the item
    double mY = 0;     ///< Y location for the center of the item

    /// The file for this item
    std::wstring mFile;

    /// The image of this tile
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

    /// Tile ID
    std::string mId;

    /// All of the tiles that make up our city
    std::vector<std::shared_ptr<CDeclaration> > mDeclarations;

    /// Tracks if tile is open
    bool mOpen = false;
};
