/**
 * \file Tile.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */

#include "pch.h"
#include "Tile.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/// The directory containing the file images
const std::wstring CTile::ImagesDirectory = L"images/";

/**
 *  Distance from center for inside of tiles.
 *
 * Our tiles are a diamond that is 64 pixels tall and 128 pixels
 * wide. So, if we take the distance from the center vertically and
 * double it, it would be as if we had a 64 by 64 diamond. The
 * "Manhattan distance" from the center would be no more than 64
 * in that case.
 */
const int InsideTolerance = 64;

/**  Constructor
 * \param game The game this tile is a member of
 */
CTile::CTile(CGame* game) : CItem(game)
{
}


/**
*  Destructor
*/
CTile::~CTile()
{
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CTile::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = ImagesDirectory + file;
        mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mItemImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mItemImage.release();
    }

    mFile = file;
}


void CTile::Draw(Gdiplus::Graphics* graphics)
{
    if (mItemImage != nullptr)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        graphics->DrawImage(mItemImage.get(), (int)GetX(), (int)GetY(), wid + 1, hit + 1);
    }
}

bool CTile::HitTest(int x, int y)
{
    // Simple manhattan distance 
    return (abs(x - mX) + abs(y - mY) * 2) <= InsideTolerance;
}

/**
* brief Load the attributes for an item node.
*
* This is the  base class version that loads the attributes
* common to all items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
* \param itemImage image of item
* \param roadType type of road
* \param open if tile is open
*/
void CTile::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open)
{
    mX = node->GetAttributeIntValue(L"x", 0);
    mY = node->GetAttributeIntValue(L"y", 0);
    mOpen = open;
}