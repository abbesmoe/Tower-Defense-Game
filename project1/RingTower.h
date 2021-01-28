/**
* \file RingTower.h
*
* \author Bryan Vi
*
*  Class that implements a Tower Eight
*/

#pragma once

#include "Tower.h"

/**
*  A Ring Tower
*/
class CRingTower : public CTower
{
public:
    CRingTower(CGame* game);

    ///  Default constructor (disabled)
    CRingTower() = delete;

    ///  Copy constructor (disabled)
    CRingTower(const CRingTower&) = delete;

    ~CRingTower();

    /** Makes a ring tower
    * \param file image of ring tower
    * \param bombNumber number of bombs
    */
    virtual void CRingTower::Tower(std::wstring file, double bombNumber) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRingTower(this); }
private:
    /// tracks the attack rate of the ring tower
    int mAttackRate = 0;

};

