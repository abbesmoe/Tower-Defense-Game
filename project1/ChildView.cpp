// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "project1.h"
#include "ChildView.h"
#include "ControlPanel.h"
#include "Game.h"

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "DoubleBufferDC.h"
#include "GetTilesVisitor.h"
using namespace Gdiplus;

/// Frame duration in milliseconds
const int FrameDuration = 30;

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_LEVELS_LEVEL1, &CChildView::OnLevelsLevel1)
	ON_COMMAND(ID_LEVELS_LEVEL2, &CChildView::OnLevelsLevel2)
	ON_COMMAND(ID_LEVELS_LEVEL3, &CChildView::OnLevelsLevel3)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{	
	if (mFirstDraw)
	{
		OnLevelsLevel1();
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	 * Compute the elapsed time since the last draw
	 */
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mGame.Update(elapsed);

	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

	if (mGrabbedItem != nullptr) 
	{
		mGrabbedItem->Draw(&graphics);
	}
	
}


/**
* Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


/**
 * Menu click for level 1 loads level.
 */
void CChildView::OnLevelsLevel1()
{
	mGame.Clear();
	std::wstring filename =L"levels/level1.xml";
	mGame.Load(filename);
	mGame.SetLevel(1);
	Invalidate();
}


/**
 * Menu click for level 2 loads level.
 */
void CChildView::OnLevelsLevel2()
{
	mGame.Clear();
	std::wstring filename = L"levels/level2.xml";
	mGame.Load(filename);
	mGame.SetLevel(2);
	Invalidate();
}


/**
 * Menu click for level 3 loads level.
 */
void CChildView::OnLevelsLevel3()
{
	mGame.Clear();
	std::wstring filename = L"levels/level3.xml";
	mGame.Load(filename);
	mGame.SetLevel(3);
	Invalidate();
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//OnMouseMove(nFlags, point);
	CGetTilesVisitor visitor;
	mGame.Accept(&visitor);
	std::vector<CTile*> tiles = visitor.GetTiles();
	// When the left button is released, we release the
	// item.
	double oX = (point.x - mGame.GetXOffset()) / mGame.GetScale();
	double oY = (point.y - mGame.GetYOffset()) / mGame.GetScale();
	bool hit = mGame.DropItem(tiles, mGrabbedItem, oX, oY);
	if (!hit) {
		mGrabbedItem = nullptr;
	}
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			double oX = (point.x - mGame.GetXOffset()) / mGame.GetScale();
			double oY = (point.y - mGame.GetYOffset()) / mGame.GetScale();
			mGrabbedItem->SetLocation(oX-32, oY-32);
		}

		// Force the screen to redraw
		Invalidate();
	}
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	double oX = (point.x - mGame.GetXOffset()) / mGame.GetScale();
	double oY = (point.y - mGame.GetYOffset()) / mGame.GetScale();
	auto controlpanel = std::make_shared<CControlPanel>(&mGame);
	mGrabbedItem = controlpanel->HitTest(oX, oY);
	Invalidate();
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}
