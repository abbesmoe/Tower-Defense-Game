/**
 * \file Game.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */

#include "pch.h"
#include <algorithm>

#include "Game.h"
#include "XmlLoader.h"
#include "ControlPanel.h"
#include "GetTilesVisitor.h"

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

/// Game area in virtual pixels
const static int Width = 1224;

/// Game area height in virtual pixels
const static int Height = 1024;

CGame::CGame()
{
}


CGame::~CGame()
{
}


/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(Width);
    float scaleY = float(height) / float(Height);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - Width * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - Height * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    /// Draws items
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    auto controlpanel = std::make_shared<CControlPanel>(this);
    controlpanel->DrawSidebar(graphics);

    if (mLevelComplete && mTimeCounter > 0)
    {
        FontFamily fontFamily(L"Arial");
        Gdiplus::Font font(&fontFamily, 64);
        SolidBrush red(Color(255, 20, 0));
        wstring complete = L"Level complete!";

        mLevelComplete = true;

        graphics->DrawString(complete.c_str(), -1, &font,
            PointF(((float)width / mScale) / 2 - 800, (float)height / mScale / 2),
            &red);
    }

    if (0 < mLevel && mLevel <= 3 && mTimeCounter < 3)
    {
        FontFamily fontFamily(L"Arial");
        Gdiplus::Font font(&fontFamily, 64);
        SolidBrush red(Color(255, 20, 0));
        wstring begin = L"Level " + to_wstring(mLevel) + L" Begin";

        graphics->DrawString(begin.c_str(),-1, &font,
            PointF(((float)width / mScale) / 2-800, (float)height / mScale / 2),
            &red);
    }
}


/**  Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
    mTimeCounter += elapsed;

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
    if (mLevelComplete && mLevel < 3)
    {
        if (mTimeCounter > 1)
        {
            mLevel++;
            mLevelComplete = false;
            wstring path = L"levels/";
            wstring levelnumber = to_wstring(mLevel);
            wstring filename = path + L"level" + levelnumber + L".xml";
            this->Load(filename);
            mTimeCounter = 0;
        }
    }
    else if (mLevelComplete)
    {
        if (mTimeCounter > 1)
        {
            mLevelComplete = false;
            wstring path = L"levels/";
            wstring levelnumber = to_wstring(mLevel);
            wstring filename = path + L"level" + levelnumber + L".xml";
            this->Load(filename);
            mTimeCounter = 0;
        }
    }
}

/**  Load the city from a .city XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* \param filename The filename of the file to load the city from.
*/
void CGame::Load(const std::wstring& filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        auto xmlLoader = std::make_shared<CXmlLoader>(this);
        xmlLoader->Load(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
*  Clear the city data.
*
* Deletes all known items in the city.
*/
void CGame::Clear()
{
    mItems.clear();
}

bool CGame::DropItem(std::vector<CTile *> tiles, std::shared_ptr<CItem> Grabbed, double x, double y) {
    auto controlpanel = std::make_shared<CControlPanel>(this);
    for (auto tile : tiles) {
        if (tile->IsOpen()) {
            bool hit = controlpanel->IsDrop(Grabbed, tile, x, y);
            if (hit)
                return hit;
            else
                continue;
        }
    }
    return false;
}

void CGame::removeItem(std::shared_ptr<CItem> item)
{
    for (int i = 0; i < mItems.size(); i++) {
        if (mItems[i] == item) {
            mItems.erase(mItems.begin() + i);
        }
    }
}

void CGame::SetStartRoadTile(std::wstring startX, std::wstring startY) {
    for (auto item : mItems) {
        if ((stod(startY) * 64) == item->GetY() && (stod(startX) * 64) == item->GetX()) {
            item->SetStart();
            break;
        }
    }
}

std::shared_ptr<CItem> CGame::GetStart()
{
    for (auto item : mItems) {
        if (item->IsStart())
        {
            return item;
        }
    }
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CGame::HitTest(double x, double y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return  nullptr;
}

void CGame::RemoveBomb() {
    /*for (auto item : mItems) {
        if (item->IsBomb()) {
            removeItem(item);
        }
    }*/
}