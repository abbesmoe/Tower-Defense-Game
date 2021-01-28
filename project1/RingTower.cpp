#include "pch.h"
#include "RingTower.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
* \param game This is a member of CTower(game)
*/
CRingTower::CRingTower(CGame* game) : CTower(game)
{
}

/**
*  Destructor
*/
CRingTower::~CRingTower()
{
}

void CRingTower::Tower(std::wstring file, double bombNumber)
{
    SetImage(file);
}