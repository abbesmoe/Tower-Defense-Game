/**
 * \file XmlLoader.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */

#pragma once
#include <string>
#include "XmlNode.h"
#include "Declaration.h"
#include <map>

class CGame;

/**  Constructor
* \param game The game this class is a member of
*/
class CXmlLoader
{
public:
    CXmlLoader(CGame* game);

    ///  Default constructor (disabled)
    CXmlLoader() = delete;

    ///  Copy constructor (disabled)
    CXmlLoader(const CXmlLoader&) = delete;

    ~CXmlLoader();

    void Load(std::wstring filename);

    /// handle the Xml node declaration
    void XmlDeclaration(std::shared_ptr<xmlnode::CXmlNode> node);

    /// handle an item tag inside a display tag
    std::shared_ptr<CTile> XmlDisplayItem(std::shared_ptr<xmlnode::CXmlNode> node);

private:
    /// game to instantiate
    CGame* mGame;

    /// name of xml
    std::wstring mName;

    /// All of the defines for this file
    std::map<std::wstring, std::shared_ptr<CDeclaration>> mDeclarations;
};

