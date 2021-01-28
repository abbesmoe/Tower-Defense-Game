
// project1.h : main header file for the project1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cproject1App:
// See project1.cpp for the implementation of this class
//


/**
 * Class that implements the project as a whole
 */
class Cproject1App : public CWinApp
{
public:
	Cproject1App() noexcept;


// Overrides
public:
	/**  Initiallize an instance
	* \return boolean if initialized
	 */
	virtual BOOL InitInstance();
	/**  Exits an instance
	* \return integer if closed
	 */
	virtual int ExitInstance();

// Implementation

public:
	/**  What happens when about is clicked
	 */
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
private:
	/// gdi startup
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	/// gdi setup
	ULONG_PTR gdiplusToken = 0;
};

extern Cproject1App theApp;
