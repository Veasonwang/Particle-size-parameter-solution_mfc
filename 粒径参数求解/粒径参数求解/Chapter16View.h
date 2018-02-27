// Chapter16View.h : interface of the Chapter16View class
//
/////////////////////////////////////////////////////////////////////////////
#include"Chapter16Doc.h"
#if !defined(AFX_Chapter16View_H__B2FC564B_5AC2_4569_9D43_46B3BE75EBED__INCLUDED_)
#define AFX_Chapter16View_H__B2FC564B_5AC2_4569_9D43_46B3BE75EBED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Chapter16View : public CView
{
protected: // create from serialization only
	Chapter16View();
	DECLARE_DYNCREATE(Chapter16View)

// Attributes
public:
	Chapter16Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Chapter16View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Chapter16View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(Chapter16View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	double xlength;
	double ylength;
	POINT MSE_LCT;
	//string fil_name;
	int i;
	HPEN hPen;
	HPEN hPen1;
	HPEN hPen2;
	HPEN hPen3;
	double Size_Middle;
	double SO;
	double Size_Average;
	double Skew;
	double Kurtosis;
	int NUM;
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen2();
	afx_msg void OnFileSave2();
	afx_msg void On32773();
	afx_msg void On32774save();
	int length;
};

#ifndef _DEBUG  // debug version in Chapter16View.cpp
inline Chapter16Doc* Chapter16View::GetDocument()
   { return (Chapter16Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Chapter16View_H__B2FC564B_5AC2_4569_9D43_46B3BE75EBED__INCLUDED_)
