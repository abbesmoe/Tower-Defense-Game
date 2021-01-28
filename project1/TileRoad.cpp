/**
 * \file TileRoad.cpp
 *
 * \author Moez Abbes
 */

#include "pch.h"
#include "TileRoad.h"
#include "Declaration.h"
#include <vector>
#include <string>

using namespace std;
using namespace Gdiplus;


/** Constructor
* \param game The game this is a member of
*/
CTileRoad::CTileRoad(CGame* game) : CTile(game)
{
    /*SetAdjacencies(false, false, false, false);*/
}


/**
*  Destructor
*/
CTileRoad::~CTileRoad()
{
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
* \param itemImage image
* \param roadType type of road
* \param open if open
*/
void CTileRoad::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open)
{
    mRoadType = roadType;
    CTile::XmlLoad(node, itemImage, roadType, false);
    SetImage(itemImage);
}

void CTileRoad::PlaceBalloonEW(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    // Moving horizontally right
    x = GetX() + t * GetWidth();

    balloon->SetLocation(x-32, y-32);
}

void CTileRoad::PlaceBalloonNS(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    // Moving vertically down
    y = GetY() + t * GetHeight();

    balloon->SetLocation(x-32, y-32);
}

void CTileRoad::PlaceBalloonNE(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + t * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally right
        x = GetX() + t * GetWidth();
    }

    balloon->SetLocation(x-32, y-32);
}

void CTileRoad::PlaceBalloonNW(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + t * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally left
        x = GetX() + (1 - t) * GetWidth();
    }

    balloon->SetLocation(x-32, y-32);
}

void CTileRoad::PlaceBalloonSE(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + (1 - t) * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally right
        x = GetX() + t * GetWidth();
    }

    balloon->SetLocation(x-32, y-32);
}

void CTileRoad::PlaceBalloonSW(CBalloon* balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    if (!balloon->IsForward())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + (1 - t) * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally left
        x = GetX() + (1 - t) * GetWidth();
    }

    balloon->SetLocation(x-32, y-32);
}


/**
 *  Indicate the road tiles adjacent to this one
 *
 * The road time image chosen is dependent on the tiles around
 * it. This is where the adjacency of road tiles is indicated.
 *
 * \param ul True if road tile to upper left
 * \param ur True if road tile to upper right
 * \param ll True if road tile to lower left
 * \param lr True if road tile to lower right
 */
//void CTileRoad::SetAdjacencies(bool ul, bool ur, bool ll, bool lr)
//{
//    // Create the adjacency code
//    int code = (ul ? 1 : 0) | (ur ? 2 : 0) | (ll ? 4 : 0) | (lr ? 8 : 0);
//    if (mCurrentAdj == code)
//    {
//        // We are already set. Do nothing
//        return;
//    }
//
//    static wstring files[] = {
//        L"roadlr.png",      // 0
//        L"roadlr.png",      // 1
//        L"roadud.png",      // 2
//        L"roadlu.png",      // 3
//        L"roadud.png",      // 4
//        L"roadld.png",      // 5
//        L"roadud.png",      // 6
//        L"roadlud.png",     // 7
//        L"roadlr.png",      // 8
//        L"roadlr.png",      // 9
//        L"roadur.png",      // 10
//        L"roadlur.png",     // 11
//        L"roaddr.png",      // 12
//        L"roadldr.png",     // 13
//        L"roadudr.png",     // 14
//        L"roadludr.png"    // 15
//    };
//
//    // Select the appropriate image
//    mCurrentAdj = code;
//    SetImage(files[code]);
//}