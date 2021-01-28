/**
* \file TowerEight.h
*
* \author Moez Abbes
*
*  Class that implements a Tower Eight
*/

#pragma once

#include "Tower.h"

/**
*  A Tower Eight
*/
class CTowerEight : public CTower
{
public:
    CTowerEight(CGame* game);

    ///  Default constructor (disabled)
    CTowerEight() = delete;

    ///  Copy constructor (disabled)
    CTowerEight(const CTowerEight&) = delete;

    ~CTowerEight();

    virtual void CTowerEight::Tower(std::wstring file, double bombNumber) override;

    /**
    * Sets the Attack Rate for Tower
    * \param num attack rate
    */
    void SetAttackRate(int num) { mAttackRate = num; }

    /**
    * Returns the attack rate
    * \returns int
    */
    int GetAttackRate() { return mAttackRate; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerEight(this); }
private:
    /// Tracks the attack rate of the tower
    int mAttackRate = 0;

};

