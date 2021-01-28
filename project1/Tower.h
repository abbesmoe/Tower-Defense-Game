/**
 * \file Balloon.h
 *
 * \author Moez Abbes
 *
 * Base class for Tower object
 */

#pragma once
#include "Item.h"

/**
 * Derived tower class from item that refers to the towers.
 */
class CTower : public CItem
{
public:
    /** Constructs a tower
     * \param game instantiation of game */
    CTower(CGame* game);

    ///  Default constructor (disabled)
    CTower() = delete;

    ///  Copy constructor (disabled)
    CTower(const CTower&) = delete;

    virtual ~CTower();

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTower(this); }

    /** Checks if a hit
     * \param x x value position
     * \param y y value position
     * \returns bool
     */
    virtual bool HitTest(double x, double y) override;
};

