/**
 * \file Item.h
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 *
 * Base class for any item in our game.
 */

//This is a test commit

#pragma once
#include <memory>
#include <string>
#include "XmlNode.h"
#include "ItemVisitor.h"

class CGame;

 /**
 * Base class for any item in our game.
 */
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    virtual ~CItem();

    /** The X location of the item
    * \returns X location in pixels */
    virtual double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    virtual double GetY() const { return mY; }

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(Gdiplus::Graphics* graphics);

    /** Draws the item
    * \param x mouse location x
    * \param y mouse location y
    * \returns bool
    */
    virtual bool HitTest(double x, double y) { return false; }

    /// Determine the distance from this item to some other item.
    double CItem::Distance(std::shared_ptr<CItem> other);

    /// Move the item by directly changing x,y by delta amounts
    /// \param dx X amount to move
    /// \param dy Y amount to move
    void Move(double dx, double dy) { mX += dx; mY += dy; }

    /**  Returns a pointer to the game
     * \return pointer to the game
     */
    CGame* GetGame() { return mGame; }

    /// Handle updates for animation
    /// param elapsed The time since the last update
    //virtual void Update(double elapsed) {};

    /// Get the width of the game
    /// \returns game width
    int GetWidth() const { return mItemImage->GetWidth(); }

    /// Get the height of the game
    /// \returns game height
    int GetHeight() const { return mItemImage->GetHeight(); }

    /// Get the file path
    /// \returns string of file
    std::wstring GetFile() { return mFile; }

    /** Instantiation of a tower
    * \param file file image name
    * \param bombNumber number of bomb on screen
    */
    virtual void Tower(std::wstring file, double bombNumber) {};

    /** Sets up to draw balloon
    * \param file file image name
    * \param startTile starting tile
    */
    virtual void Balloon(std::wstring file, std::shared_ptr<CItem> startTile) {};

    void SetImage(const std::wstring& file);

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    /** Sets up to start level and game
    */
    virtual void SetStart() {}

    /** Checks if tile is open
    * \returns bool
    */
    virtual bool IsOpen() { return false; }

    /** Checks if tile is start
    * \returns bool
    */
    virtual bool IsStart() { return false; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) = 0;

    /** Sets up an item
    * \param item item that exists
    */
    virtual void SetItem(std::shared_ptr<CItem> item) {};

    /** Gets item
    * \returns nullptr or item
    */
    virtual std::shared_ptr<CItem> GetItem() { return nullptr; }

    /** Checks if item is a bomb
    * \returns bool
    */
    virtual bool IsBomb() { return false; }

    /**
    * Gets type of road
    * \returns road type
    */
    virtual std::wstring GetType() { return L""; }

    /** Sets direction EW
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonEW(CBalloon* balloon) {};

    /** Sets direction NS
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNS(CBalloon* balloon) {};

    /** Sets direction NE
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNE(CBalloon* balloon) {};

    /** Sets direction NW
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNW(CBalloon* balloon) {};

    /** Sets direction SE
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonSE(CBalloon* balloon) {};

    /** Sets direction SW
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonSW(CBalloon* balloon) {};

protected:
    CItem(CGame* game);

private:
    /// The game this item is contained in
    CGame* mGame;

    // Item location in the game
    double mX = 0;     ///< X location for the center of the item
    double mY = 0;     ///< Y location for the center of the item

    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;


    /// The file to load from
    const std::wstring mFile;
};

