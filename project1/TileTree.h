/**
* \file TileTree.h
*
* \author Moez Abbes
*
*  Class that implements a Tree tile
*/

#pragma once

#include "Tile.h"
#include <string>


/**
*  A Tree tile
*/
class CTileTree : public CTile
{
public:
    CTileTree(CGame* game);

    ///  Default constructor (disabled)
    CTileTree() = delete;

    ///  Copy constructor (disabled)
    CTileTree(const CTileTree&) = delete;

    ~CTileTree();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open);
};

