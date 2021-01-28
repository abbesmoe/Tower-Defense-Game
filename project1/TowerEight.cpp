#include "pch.h"
#include "TowerEight.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
* \param game The game this is a member of
*/
CTowerEight::CTowerEight(CGame* game) : CTower(game)
{
}

/**
*  Destructor
*/
CTowerEight::~CTowerEight()
{
}

/**
 * Constructs TowerEight with its image along with an x and y location
 * \param file image 
 * \param bombNumber number of bombs
 */
void CTowerEight::Tower(std::wstring file, double bombNumber)
{
    SetImage(file);
}