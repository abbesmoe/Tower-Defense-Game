/**
* \file TileRoad.h
*
* \author Moez Abbes
*
*  Class that implements a Road tile
*/

#pragma once

#include "Tile.h"
#include <string>
#include "Balloon.h"


/**
*  A Road tile
*/
class CTileRoad : public CTile
{
public:
    CTileRoad(CGame* game);

    ///  Default constructor (disabled)
    CTileRoad() = delete;

    ///  Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    ~CTileRoad();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node, std::wstring itemImage, std::wstring roadType, bool open);

    /** Sets direction EW 
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonEW(CBalloon* balloon) override;

    /** Sets direction NS
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNS(CBalloon* balloon) override;

    /** Sets direction NE
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNE(CBalloon* balloon) override;

    /** Sets direction NW
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonNW(CBalloon* balloon) override;

    /** Sets direction SE
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonSE(CBalloon* balloon) override;

    /** Sets direction SW
    * \param balloon balloon to place
    */
    virtual void PlaceBalloonSW(CBalloon* balloon) override;

    /** Sets direction N
    * \param road road that next
    */
    virtual void SetNorth(std::shared_ptr<CTile> road) override { mNorth = road; }

    /** Sets direction S
    * \param road road that next
    */
    virtual void SetSouth(std::shared_ptr<CTile> road) override { mSouth = road; }

    /** Sets direction E
    * \param road road that next
    */
    virtual void SetEast(std::shared_ptr<CTile> road) override { mEast = road; }

    /** Sets direction W
    * \param road road that next
    */
    virtual void SetWest(std::shared_ptr<CTile> road) override { mWest = road; }

    /** Sets start road
    */
    virtual void SetStart() override { mStartPosition = true; }
    
    /** Checks if start road
    * \returns bool
    */
    virtual bool IsStart() override { return mStartPosition; }

    /**
    * Gets type of road
    * \returns road type
    */
    virtual std::wstring GetType() override { return mRoadType;  }

private:
    /// tracks road type
    std::wstring mRoadType;

    /// All of the ballons that are on this road
    std::vector<std::shared_ptr<CBalloon> > mBallons;

    /// points to road tile north of this tile
    std::weak_ptr<CTile> mNorth;

    /// points to road tile south of this tile
    std::weak_ptr<CTile> mSouth;

    /// points to road tile east of this tile
    std::weak_ptr<CTile> mEast;

    /// points to road tile west of this tile
    std::weak_ptr<CTile> mWest;

    /// marks if this is the starting road tile for balloons
    bool mStartPosition = false;

    /// bool that represents which direction the balloon is going to move
    /// true means south to north, west to east
    /// false means north to south, east to west
    bool direction = true;
};

