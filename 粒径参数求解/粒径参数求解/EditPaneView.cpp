// EditPaneView.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter16.h"
#include "EditPaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditPaneView

IMPLEMENT_DYNCREATE(CEditPaneView, CEditView)

CEditPaneView::CEditPaneView()
{
}

CEditPaneView::~CEditPaneView()
{
}


BEGIN_MESSAGE_MAP(CEditPaneView, CEditView)
	//{{AFX_MSG_MAP(CEditPaneView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditPaneView drawing

void CEditPaneView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CEditPaneView diagnostics

#ifdef _DEBUG
void CEditPaneView::AssertValid() const
{
	CEditView::AssertValid();
}

void CEditPaneView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditPaneView message handlers

void CEditPaneView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	//SetWindowText("��ѡ���������ͼѡ���Ա�鿴�л���ͼЧ����ͼ");
}
