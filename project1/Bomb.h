/**
* \file Bomb.h
*
* \author Moez Abbes, Jacob Riggs, Alan Reed Wagner, Bryan Vi, Mingzhe Huang
*
*  Class that implements a bomb tower
*/


#pragma once

#include "Game.h"
#include "Tower.h"

/**
 * Class that implements the bomb tower.
 */
class CBomb : public CTower
{
public:

    /** Accept a visitor
     * param visitor The visitor we accept */
    //virtual void Accept(CTowerVisitor* visitor) override { visitor->VisitTower(this); }

    CBomb(CGame* game);

    ///  Default constructor (disabled)
    CBomb() = delete;

    ///  Copy constructor (disabled)
    CBomb(const CBomb&) = delete;

    ~CBomb();

    /** Is this bomb exploded?
     * \return true if so */
    bool Exploded() { return mExploded; }

    /** Accept a visitor
     * \param file the file name
     * \param bombNumber number of bombs
     */
    virtual void CBomb::Tower(std::wstring file, double bombNumber) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBomb(this); }

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) override;

    /** Draws a bomb
     * \param graphics graphics to import */
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /** Shoots the bomb out */
    void Fire();

    /** Checks if bomb
     * \returns bool */
    virtual bool IsBomb() override { return true; }
private:
    /// default bomb explosion time = ???
    int mExplosionTime = 0;

    /// Is this bomb exploded?
    bool mExploded = false;

    /// time to fire
    double mTimeTillFire = 0;

    /// if bomb should fire
    bool mFire = false;

    /// counter for explosion radius
    double counter = 0;
};

