/**
 * \file ItemVisitor.h
 *
 * \author Moez Abbes, Jacob Riggs
 *
 * Item visitor base class.
 */

#pragma once

 // Forward references to all tile types
class CTile;
class CTower;
class CBalloon;
class CTileGrass;
class CTileHouse;
class CTileRoad;
class CTileTree;
class CTowerEight;
class CRingTower;
class CBomb;
class CRedBalloon;
class CBlackBalloon;
class CBlueBalloon;

 /** Item visitor base class */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a CTile object
     * \param tile Tile we are visiting */
    virtual void VisitTile(CTile* tile) {}

    /** Visit a CTileGrass object
    * \param grass Grass tile we are visiting */
    virtual void VisitTileGrass(CTileGrass* grass) {}

    /** Visit a CTileHouse object
    * \param house House tile we are visiting */
    virtual void VisitTileHouse(CTileHouse* house) {}

    /** Visit a CTileRoad object
    * \param road Road tile we are visiting */
    virtual void VisitTileRoad(CTileRoad* road) {}

    /** Visit a CTileTree object
    * \param tree Tree tile we are visiting */
    virtual void VisitTileTree(CTileTree* tree) {}

    /** Visit a CTower object
     * \param tower Tower we are visiting */
    virtual void VisitTower(CTower* tower) {}

    /** Visit a CTowerEight object
    * \param towerEight TowerEight tower we are visiting */
    virtual void VisitTowerEight(CTowerEight* towerEight) {}

    /** Visit a CBomb object
    * \param bomb Bomb tower we are visiting */
    virtual void VisitBomb(CBomb* bomb) {}

    /** Visit a CRingTower object
    * \param ringTower RingTower tower we are visiting */
    virtual void VisitRingTower(CRingTower* ringTower) {}

    /** Visit a CBalloon object
    * \param balloon Balloon balloon we are visiting */
    virtual void VisitBalloon(CBalloon* balloon) {}

    /** Visit a CRedBalloon object
    * \param redBalloon RedBalloon balloon we are visiting */
    virtual void VisitRedBalloon(CRedBalloon* redBalloon) {}

    /** Visit a CBlackBalloon object
    * \param blackBalloon BlackBalloon balloon we are visiting */
    virtual void VisitBlackBalloon(CBlackBalloon* blackBalloon) {}

    /** Visit a CBlueBalloon object
    * \param blueBalloon BlueBalloon balloon we are visiting */
    virtual void VisitBlueBalloon(CBlueBalloon* blueBalloon) {}
};

