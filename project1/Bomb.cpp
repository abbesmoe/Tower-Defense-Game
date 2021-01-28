/**
 * \file Bomb.cpp
 *
 * \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
 */
#include "pch.h"
#include "Bomb.h"

using namespace std;
using namespace Gdiplus;
/// time that happens between shots from bomb
double const TimeBetweenShots = 3;

/** Constructor
* \param game The game this is a member of
*/
CBomb::CBomb(CGame* game) : CTower(game)
{
}

/**
*  Destructor
*/
CBomb::~CBomb()
{
}

void CBomb::Tower(std::wstring file, double bombNumber)
{
    SetImage(file);
    mTimeTillFire = bombNumber * 3;
}
/*Handle updates for animation
*/
void CBomb::Update(double elapsed)
{
    if (mFire)
    {
        counter++;
    }
    mTimeTillFire -= elapsed;
    if (mTimeTillFire <= 0)
    {
        if (!mFire) 
        {
            mTimeTillFire += TimeBetweenShots;
            Fire();
            counter = 0;
        }
        
    }
    
}

void CBomb::Draw(Gdiplus::Graphics* graphics)
{
    CItem::Draw(graphics);
    if (mFire) {
        if (counter <= 40)
        {
            // Create a new pen.
            Pen pen(Color(128, 0, 0), 3);
            SolidBrush brush(Color(128, 0, 0));
            graphics->DrawEllipse(&pen, (int)GetX() - 64, (int)GetY() - 64, 200, 200);
            graphics->FillEllipse(&brush, (int)GetX() - 64, (int)GetY() - 64, 200, 200);
        }
    }
}

void CBomb::Fire() {
    mFire = true;
    GetGame()->RemoveBomb();
}
