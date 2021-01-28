/**
 * \file Declaration.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */

#include "pch.h"
#include "Declaration.h"
#include "TileGrass.h"
#include "Game.h"
#include "TileRoad.h"
#include "TileTree.h"
#include "TileHouse.h"

using namespace xmlnode;

/**
* Constructor
* \param game game to use
* \param node the Xml node for this define
*/
CDeclaration::CDeclaration(CGame* game, std::shared_ptr<xmlnode::CXmlNode> node)
{
    mGame = game;
    mId = node->GetAttributeValue(L"id", L"");
    mItemImage = node->GetAttributeValue(L"image", L"");
    if (node->GetName() == L"road") {
        mRoadType = node->GetAttributeValue(L"type", L"");
    }
}


/**
*  Destructor
*/
CDeclaration::~CDeclaration()
{
}

/**
 * pass the declarations to display the item.
 * \param node std::shared_ptr<xmlnode::CXmlNode> node that points to item.
 * \returns pointer to tile
 */
std::shared_ptr<CTile> CDeclaration::Display(std::shared_ptr<xmlnode::CXmlNode> node)
{
    // A pointer for the item we are loading
    std::shared_ptr<CTile> tile;
    std::shared_ptr<CTile> tileroad;

    // We have an item. What type?
    std::wstring type = node->GetName();

    if (type == L"road")
    {
        tile = std::make_shared<CTileRoad>(mGame);

        tileroad = tile;
    }

    else if (type == L"trees")
    {
        tile = std::make_shared<CTileTree>(mGame);
    }
    else if (type == L"open")
    {
        tile = std::make_shared<CTileGrass>(mGame);
    }
    else if (type == L"house")
    {
        tile = std::make_shared<CTileHouse>(mGame);
    }
    if (tile != nullptr)
    {
        tile->XmlLoad(node, mItemImage, mRoadType, false);
        mGame->AddItem(tile);
    }

    return tileroad;
}
