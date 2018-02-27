// Chapter16Doc.h : interface of the Chapter16Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_Chapter16Doc_H__436FEEB4_11D3_4947_8F95_BCECBB98D661__INCLUDED_)
#define AFX_Chapter16Doc_H__436FEEB4_11D3_4947_8F95_BCECBB98D661__INCLUDED_
#include "PreHand.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Chapter16Doc : public CDocument
{
protected: // create from serialization only
	Chapter16Doc();
	DECLARE_DYNCREATE(Chapter16Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Chapter16Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Chapter16Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(Chapter16Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	double Size_Middle;
	double SO;
	double Size_Average;
	double Skew;
	double Kurtosis;
	int NUM;
	string fil_name;
	table _table;
	int length;
	int control;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Chapter16Doc_H__436FEEB4_11D3_4947_8F95_BCECBB98D661__INCLUDED_)
