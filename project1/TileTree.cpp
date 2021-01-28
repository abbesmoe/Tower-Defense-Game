/**
 * \file TileTree.cpp
 *
 * \author Moez Abbes
 */

#include "pch.h"
#include "TileTree.h"
#include "Declaration.h"
#include <vector>
#include <string>

 /** Constructor
  * \param game The game this is a member of
  */
CTileTree::CTileTree(CGame* game) : CTile(game)
{
}

/**
*  Destructor
*/
CTileTree::~CTileTree()
{
}

/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
* \param itemImage image
* \param roadType type of road
* \param open if open
*/
void CTileTree::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open)
{
    CTile::XmlLoad(node, itemImage, roadType, false);
    SetImage(itemImage);
}