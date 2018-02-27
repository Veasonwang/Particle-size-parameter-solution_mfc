// ListPaneView.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter16.h"
#include "ListPaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListPaneView

IMPLEMENT_DYNCREATE(CListPaneView, CListView)

CListPaneView::CListPaneView()
{
}

CListPaneView::~CListPaneView()
{
}


BEGIN_MESSAGE_MAP(CListPaneView, CListView)
	//{{AFX_MSG_MAP(CListPaneView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListPaneView drawing

void CListPaneView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CListPaneView diagnostics

#ifdef _DEBUG
void CListPaneView::AssertValid() const
{
	CListView::AssertValid();
}

void CListPaneView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListPaneView message handlers

void CListPaneView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();	
	CListCtrl& ctl=GetListCtrl();
	// TODO: Add your specialized code here and/or call the base class	
	//�����б�ؼ����
	DWORD dwStyle=::GetWindowLong(m_hWnd,GWL_STYLE);
    dwStyle|=LVS_REPORT|LVS_SHOWSELALWAYS|LVS_EDITLABELS;	
	::SetWindowLong(m_hWnd,GWL_STYLE,dwStyle);
	dwStyle=ctl.GetExtendedStyle();
	dwStyle|= LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT;
    //������չ���
	ctl.SetExtendedStyle(dwStyle);	
	//�б�ؼ�ͷ����
	TCHAR tittle[3][10] = {_T("����"),_T("��λ"),_T("��ַ")};	
	LV_COLUMN lvcolumn;
	CRect rect;
	GetWindowRect(&rect);	
	//����б�ؼ�ͷ
	for(int i=0;i<3;i++)
	{
		lvcolumn.mask =LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT 
			|LVCF_WIDTH|LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = tittle[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Height()/3;
		GetListCtrl().InsertColumn(i, &lvcolumn);
	}
}
