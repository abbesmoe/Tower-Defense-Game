/**
 * \file Declaration.h
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 *
 * contains declations
 */

#pragma once
#include <string>
#include <memory>
#include "XmlNode.h"

class CGame;

class CTile;

/**
* Class that implements declarations
*/
class CDeclaration
{
public:
    CDeclaration(CGame* game, std::shared_ptr<xmlnode::CXmlNode> node);

    ///  Default constructor (disabled)
    CDeclaration() = delete;

    ///  Copy constructor (disabled)
    CDeclaration(const CDeclaration&) = delete;

    ~CDeclaration();

    std::shared_ptr<CTile> Display(std::shared_ptr<xmlnode::CXmlNode> node);

    /** Gets the id 
    * \returns id
    */
    std::wstring GetId() { return mId; }

private:
    /// pointer to game
    CGame* mGame;
    
    /// Item Id
    std::wstring mId;

    /// Image 
    std::wstring mItemImage;

    /// Type of Road
    std::wstring mRoadType;
};

