/**
 * \file TileHouse.cpp
 *
 * \author Moez Abbes
 */

#include "pch.h"
#include "TileHouse.h"
#include "Declaration.h"
#include <vector>
#include <string>

 /** Constructor
  * \param game The game this is a member of
  */
CTileHouse::CTileHouse(CGame* game) : CTile(game)
{
}

/**
*  Destructor
*/
CTileHouse::~CTileHouse()
{
}

/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
* \param itemImage image
* \param roadType type of road
* \param open if open
*/
void CTileHouse::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open)
{
    CTile::XmlLoad(node, itemImage, roadType, false);
    SetImage(itemImage);
}