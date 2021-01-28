/**
 * \file XmlLoader.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */

#include "pch.h"
#include "XmlLoader.h"
#include <string>
#include <memory>
#include <iostream>
#include "Declaration.h"
#include "Game.h"
#include "TileRoad.h"

using namespace xmlnode;

/**  Constructor
* \param game The game this class is a member of
*/
CXmlLoader::CXmlLoader(CGame* game) : mGame(game)
{
}


/**
*  Destructor
*/
CXmlLoader::~CXmlLoader()
{
}

/**
 * Load the file from XML
 * \param filename The file to load.
 */
void CXmlLoader::Load(std::wstring filename)
{
    try
    {
        // Open the document to read
        std::shared_ptr<CXmlNode> root = xmlnode::CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        mGame->Clear();

        auto startY = root->GetAttributeValue(L"start-y", L"");
        auto startX = root->GetAttributeValue(L"start-x", L"");

        for (auto child : root->GetChildren())
        {
            if (child->GetType() == NODE_ELEMENT)
            {
                std::wstring name = child->GetName();
                if (child->GetName() == L"declarations")
                {
                    for (auto subchild : child->GetChildren()) {
                        XmlDeclaration(subchild);
                    }
                }
                else if (child->GetName() == L"items")
                {
                    std::vector<std::shared_ptr<CTile> > roads;
                    for (auto subchild : child->GetChildren()) {
                        std::shared_ptr<CTile> road = XmlDisplayItem(subchild);
                        if (road != nullptr) {
                            roads.push_back(road);
                        }
                    }
                    for (auto road : roads) {
                        for (auto road2 : roads) {
                            if (road2->GetX()/64 == road->GetX()/64 && road2->GetY()/64 == road->GetY()/64+1) {
                                road->SetNorth(road2);
                            }
                            if (road2->GetX()/64 == road->GetX()/64 && road2->GetY()/64 == road->GetY()/64-1) {
                                road->SetSouth(road2);
                            }
                            if (road2->GetX()/64 == road->GetX()/64+1 && road2->GetY()/64 == road->GetY()/64) {
                                road->SetEast(road2);
                            }
                            if (road2->GetX()/64 == road->GetX()/64-1 && road2->GetY()/64 == road->GetY()/64) {
                                road->SetWest(road2);
                            }
                        }
                    }
                }

            }
        }
        mGame->SetStartRoadTile(startX, startY);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Handle the Xml node declaration
 * \param node The XML node
 */
void CXmlLoader::XmlDeclaration(std::shared_ptr<xmlnode::CXmlNode> node)
{
    // We need to create an object to store this item definition
    // Notice how I pass the Xml node to the constructor so it can
    // do all of the work.
    auto declaration = std::make_shared<CDeclaration>(mGame, node);

    // Add to the collection
    mDeclarations[declaration->GetId()] = declaration;
}

/**
 * Handle an item tag inside a display tag.
 * \param node The XML node
 * \returns tile created
 */
std::shared_ptr<CTile> CXmlLoader::XmlDisplayItem(std::shared_ptr<xmlnode::CXmlNode> node)
{
    // Get the id
    auto id = node->GetAttributeValue(L"id", L"");

    // Find the definition associated with this id
    auto iterator = mDeclarations.find(id);
    if (iterator != mDeclarations.end())
    {
        // We found it
        auto declaration = iterator->second;
        std::shared_ptr<CTile> road = declaration->Display(node);
        return road;
    }
}
