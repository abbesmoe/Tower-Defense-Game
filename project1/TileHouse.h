/**
* \file TileHouse.h
*
* \author Moez Abbes
*
*  Class that implements a House tile
*/

#pragma once

#include "Tile.h"
#include <string>


/**
*  A House tile
*/
class CTileHouse : public CTile
{
public:
    CTileHouse(CGame* game);

    ///  Default constructor (disabled)
    CTileHouse() = delete;

    ///  Copy constructor (disabled)
    CTileHouse(const CTileHouse&) = delete;

    ~CTileHouse();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open);
};

