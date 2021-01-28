/**
 * \file Item.cpp
 *
 * \author Moez Abbes
 */

#include "pch.h"
#include <string>
#include "Item.h"
#include "Game.h"
#include "XmlNode.h"

using namespace Gdiplus;
using namespace std;

/**  Constructor for an item
 * \param game the game the we are using
 */
CItem::CItem(CGame* game) : mGame(game)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
 * Determine the distance from this item to some other item.
 * \param other Other item we are testing
 * \return Distance in pixels
 */
double CItem::Distance(std::shared_ptr<CItem> other)
{
    // Create a vector in the direction we are from the nudger
    double dx = mX - other->mX;
    double dy = mY - other->mY;

    // Determine how far away we are
    return sqrt(dx * dx + dy * dy);
}

/** Draw this item
 * \param graphics Graphics device to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics)
{
    if (mItemImage != nullptr && mX != 0 && mY != 0)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        graphics->DrawImage(mItemImage.get(), (int)GetX(), (int)GetY(), wid+1, hit+1);
    }
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = file;
        mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mItemImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mItemImage.release();
    }
}