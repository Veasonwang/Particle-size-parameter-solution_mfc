// Chapter16.h : main header file for the CChapter16 application
//

#if !defined(AFX_CChapter16_H__742A1E09_8002_4741_A2B7_EDE0A4C68E02__INCLUDED_)
#define AFX_CChapter16_H__742A1E09_8002_4741_A2B7_EDE0A4C68E02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CChapter16App:
// See CChapter16.cpp for the implementation of this class
//

class CChapter16App : public CWinApp
{
public:
	CChapter16App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChapter16App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChapter16App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CChapter16_H__742A1E09_8002_4741_A2B7_EDE0A4C68E02__INCLUDED_)
