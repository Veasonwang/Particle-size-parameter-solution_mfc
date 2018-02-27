// Chapter16Doc.cpp : implementation of the Chapter16Doc class
//

#include "stdafx.h"
#include "Chapter16.h"

#include "Chapter16Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chapter16Doc

IMPLEMENT_DYNCREATE(Chapter16Doc, CDocument)

BEGIN_MESSAGE_MAP(Chapter16Doc, CDocument)
	//{{AFX_MSG_MAP(Chapter16Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chapter16Doc construction/destruction

Chapter16Doc::Chapter16Doc()
{
	// TODO: add one-time construction code here
	Size_Middle = 0;
	SO = 0;
	Size_Average = 0;
	Skew = 0;
	Kurtosis = 0;
	NUM = 0;
	fil_name = "";
	length = 0;
	control = 0;
}

Chapter16Doc::~Chapter16Doc()
{
}

BOOL Chapter16Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// Chapter16Doc serialization

void Chapter16Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// Chapter16Doc diagnostics

#ifdef _DEBUG
void Chapter16Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Chapter16Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Chapter16Doc commands
