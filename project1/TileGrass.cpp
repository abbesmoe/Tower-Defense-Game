/**
 * \file TileGrass.cpp
 *
 * \author Moez Abbes
 */

#include "pch.h"
#include "TileGrass.h"
#include "Declaration.h"
#include <vector>
#include <string>

using namespace Gdiplus;

 /** Constructor
  * \param game The game this is a member of
  */
CTileGrass::CTileGrass(CGame* game) : CTile(game)
{
}

/**
*  Destructor
*/
CTileGrass::~CTileGrass()
{
}

/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
* \param itemImage image
* \param roadType type of road
* \param open if open
*/
void CTileGrass::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open)
{
    CTile::XmlLoad(node, itemImage, roadType, true);
    SetImage(itemImage);
}
