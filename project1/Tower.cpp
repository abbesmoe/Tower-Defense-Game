#include "pch.h"
#include "Tower.h"

CTower::CTower(CGame* game) : CItem(game)
{
}

CTower::~CTower()
{
}

void CTower::Draw(Gdiplus::Graphics* graphics)
{
	CItem::Draw(graphics);
}

bool CTower::HitTest(double x, double y)
{
    double wid = 65;
    double hit = 65;

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX();
    double testY = y - GetY();

    // Test to see if x, y are in the image
    if (testX >= 0 && testY >= 0 || testX < wid || testY < hit)
    {
        // We are inside the image
        return true;
    }
    else {
        return false;
    }
}
