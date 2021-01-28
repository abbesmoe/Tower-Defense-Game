
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"


// CChildView window


/**
 * Class that implements the menu and app, handles most commands.
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

private:
	/// Instantiate game
	CGame mGame;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime = 0;    ///< Last time we read the timer
	double mTimeFreq = 0;       ///< Rate the timer updates

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	/// Function that will draw when the app is told to
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLevelsLevel1();
	afx_msg void OnLevelsLevel2();
	afx_msg void OnLevelsLevel3();
	/**
	* On left button up
	* \param nFlags flags
	* \param point point that was clicked
	*/
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	/**
	* On mouse move
	* \param nFlags flags
	* \param point point that was clicked
	*/
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	/**
	* On left button down
	* \param nFlags flags
	* \param point point that was clicked
	*/
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

	/// Any item we are currently dragging
	std::shared_ptr<CTile> mHitTile;
public:
	/** On timer
	* \param nIDEvent event that triggers timer
	*/
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

