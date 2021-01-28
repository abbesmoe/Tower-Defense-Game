/**
 * \file ControlPanel.cpp
 *
 * \author Jacob Riggs
 */

#include "pch.h"
#include "ControlPanel.h"
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "TowerEight.h"
#include "RingTower.h"
#include "Bomb.h"
#include "RedBalloon.h"
using namespace Gdiplus;
/// tower eight file
std::wstring tower8file = L"images/tower8.png";
/// ring tower file
std::wstring ringtowerfile = L"images/tower-rings.png";
/// bomb tower file
std::wstring bombfile = L"images/tower-bomb.png";
/// go button file
std::wstring gofile = L"images/button-go.png";
/// red balloon file
std::wstring redBalloonfile = L"images/red-balloon.png";
/// width of screen
const static int width = 1124;
/// width location of go button
const static int widthGO = 1086;
/// height of tower eight image
const static int heightTowerEight = 200;
/// height of bomb tower
const static int heightBombTower = 300;
/// height of ring tower
const static int heightRingTower = 100;
/// height of go button
const static int heightGoButton = 800;

CControlPanel::CControlPanel(CGame* game) : mGame(game)
{
}

CControlPanel::~CControlPanel()
{
}

/**
 * Function that draws the pictures of sidebar.
 * \param graphics Graphics we are drawing on
 */
void CControlPanel::DrawSidebar(Gdiplus::Graphics* graphics)
{
    /// Draws Tower Eight
    mTowerEight = std::unique_ptr<Bitmap>(Bitmap::FromFile(tower8file.c_str()));
	if (mTowerEight->GetLastStatus() != Ok)
	{
		std::wstring msg(L"Failed to open ");
		msg += tower8file;
		AfxMessageBox(msg.c_str());
	}
	graphics->DrawImage(mTowerEight.get(), width, heightTowerEight,
        mTowerEight->GetWidth(), mTowerEight->GetHeight());


    /// Draws Ring Tower
    mRingTower = std::unique_ptr<Bitmap>(Bitmap::FromFile(ringtowerfile.c_str()));
    if (mRingTower->GetLastStatus() != Ok)
    {
        std::wstring msg(L"Failed to open ");
        msg += ringtowerfile;
        AfxMessageBox(msg.c_str());
    }
    graphics->DrawImage(mRingTower.get(), width, heightRingTower,
        mRingTower->GetWidth(), mRingTower->GetHeight());


    /// Draws Bomb Tower
    mBomb = std::unique_ptr<Bitmap>(Bitmap::FromFile(bombfile.c_str()));
    if (mBomb->GetLastStatus() != Ok)
    {
        std::wstring msg(L"Failed to open ");
        msg += bombfile;
        AfxMessageBox(msg.c_str());
    }
    graphics->DrawImage(mBomb.get(), width, heightBombTower,
        mBomb->GetWidth(), mBomb->GetHeight());


    /// Draws Go Button
    mGo = std::unique_ptr<Bitmap>(Bitmap::FromFile(gofile.c_str()));
    if (mGo->GetLastStatus() != Ok)
    {
        std::wstring msg(L"Failed to open ");
        msg += gofile;
        AfxMessageBox(msg.c_str());
    }
    graphics->DrawImage(mGo.get(), widthGO, heightGoButton,
        mGo->GetWidth(), mGo->GetHeight());
}


/**  Test an x,y click location to see if it clicked
* on some item in the game.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CControlPanel::HitTest(double x, double y)
{
    int wid = 65;
    int hit = 65;

    // Make x and y relative to the top-left corner of the bitmap image.
    // Subtracting the center makes x, y relative to the center of 
    // the image. Adding half the size makes x, y relative to the top 
    // corner of the image.
    double testX = x - width;
    double testYTowerEight = y - heightTowerEight;
    double testYRingTower = y - heightRingTower;
    double testYBombTower = y - heightBombTower;

    int widGo = 150;
    int hitGo = 80;
    double testXGo = x - widthGO;
    double testYGo = y - heightGoButton;

    std::shared_ptr<CItem> item;

    // Test to see if x, y are in the image
    if (testX >= 0 && testYTowerEight >= 0 && testX < wid && testYTowerEight < hit)
    {
        // We are inside the image
        item = std::make_shared<CTowerEight>(mGame);

        item->Tower(tower8file,0);

    }
    else if (testX >= 0 && testYRingTower >= 0 && testX < wid && testYRingTower < hit)
    {
        // We are inside the image
        item = std::make_shared<CRingTower>(mGame);

        item->Tower(ringtowerfile,0);
    }
    else if (testX >= 0 && testYBombTower >= 0 && testX < wid && testYBombTower < hit)
    {
        mBombNumber++;

        // We are inside the image
        item = std::make_shared<CBomb>(mGame);

        item->Tower(bombfile,mBombNumber);
    }
    else if (testXGo >= 0 && testYGo >= 0  && testXGo < widGo && testYGo < hitGo) {
        CreateFirstBalloon();
        /*for(int i=0;i<29;i++)
            CreateBalloons();*/
    }
    if (item == nullptr) {
        item = mGame->HitTest(x, y);
    }

    return item;
}

void CControlPanel::CreateFirstBalloon()
{
    std::shared_ptr<CItem> item;
    item = std::make_shared<CBalloon>(mGame);
    std::shared_ptr<CItem> startTile = mGame->GetStart();
  
    item->SetLocation(startTile->GetX()-32, startTile->GetY()-32);
    item->Balloon(redBalloonfile, startTile);
    mGame->AddItem(item);
}

//void CControlPanel::CreateBalloons()
//{
//    
//    std::shared_ptr<CItem> item;
//    item = std::make_shared<CBalloon>(mGame);
//    std::vector<int> startLocation = mGame->GetStart();
//    item->SetLocation(startLocation[0], startLocation[1]);
//    item->Balloon(redBalloonfile);
//}

bool CControlPanel::IsDrop(std::shared_ptr<CItem> Grabbed, CTile * tile, double x, double y)
{
    int wid = 65;
    int hit = 65;

    // Make x and y relative to the top-left corner of the bitmap image.
    // Subtracting the center makes x, y relative to the center of 
    // the image. Adding half the size makes x, y relative to the top 
    // corner of the image.
    double testX = x - tile->GetX();
    double testY = y - tile->GetY();

    // Test to see if x, y are in the image
    if (testX >= 0 && testY >= 0 && testX < wid && testY < hit)
    {
        if (tile->GetItem() != nullptr) {
            mGame->removeItem(tile->GetItem());
        }
        Grabbed->SetLocation(tile->GetX(), tile->GetY());
        tile->SetItem(Grabbed);
        mGame->AddItem(Grabbed);
        return true;
    }
    return false;
}

