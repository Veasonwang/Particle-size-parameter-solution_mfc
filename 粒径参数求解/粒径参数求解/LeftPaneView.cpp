// LeftPaneView.cpp : implementation file
//���ָ�����ʵ��

#include "stdafx.h"
#include "Chapter16.h"
#include "LeftPaneView.h"
#include "MainFrm.h"
#include "Chapter16Doc.h"
#include"Chapter16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftPaneView

IMPLEMENT_DYNCREATE(CLeftPaneView, CTreeView)

CLeftPaneView::CLeftPaneView()
{

}

CLeftPaneView::~CLeftPaneView()
{
}


BEGIN_MESSAGE_MAP(CLeftPaneView, CTreeView)
	//{{AFX_MSG_MAP(CLeftPaneView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED,OnSelchanged)
	//}}AFX_MSG_MAP
	ON_WM_NCPAINT()
//	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CLeftPaneView::OnTvnSelchanged)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftPaneView drawing

void CLeftPaneView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLeftPaneView diagnostics

#ifdef _DEBUG
void CLeftPaneView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftPaneView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftPaneView message handlers
void CLeftPaneView::OnInitialUpdate() 
{

	CTreeView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	//���������
	::SetWindowLong(m_hWnd,GWL_STYLE,WS_VISIBLE|WS_TABSTOP 
		|WS_CHILD|WS_BORDER|TVS_HASBUTTONS 
		|TVS_LINESATROOT|TVS_HASLINES);
}


void CLeftPaneView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CTreeCtrl& treeCtrl=GetTreeCtrl();
	string str;
	//��ȡ��ǰѡ�е�����
	HTREEITEM hSelectedItem=treeCtrl.GetSelectedItem();
	//��ȡ��ǰѡ�е������ı�
	str=treeCtrl.GetItemText(hSelectedItem);
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	if (pDoc->_table.Getrow() >= 1)
	{
		pDoc->NUM = pDoc->_table.name_to_int(str);
		pDoc->SO = pDoc->_table.get_So(pDoc->NUM);
		pDoc->Size_Average = pDoc->_table.get_AverageSize(pDoc->NUM);
		pDoc->Size_Middle = pDoc->_table.get_SizeMiddle(pDoc->NUM );
		pDoc->Skew = pDoc->_table.get_Skew(pDoc->NUM );
		pDoc->Kurtosis = pDoc->_table.get_Kurtosis(pDoc->NUM );
	}
	*pResult = 0;
	pMainFrame->Flash();
}


void CLeftPaneView::InsertDate()
{
	CTreeView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	//���������
	::SetWindowLong(m_hWnd, GWL_STYLE, WS_VISIBLE | WS_TABSTOP
		| WS_CHILD | WS_BORDER | TVS_HASBUTTONS
		| TVS_LINESATROOT | TVS_HASLINES);
	CTreeCtrl& treeCtrl = GetTreeCtrl();
	//����ͼ���б�
	//m_ImageList.Create(IDB_IMAGES, 16, 1, RGB(255, 0, 255));	
	//treeCtrl.SetImageList(&m_ImageList, LVSIL_NORMAL);
	//��������
	/*
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	int i = 0;
	table _table = pDoc->_table;
	char _name[20];
	HANDLE AAA;
	HTREEITEM hItem;
	hItem = treeCtrl.InsertItem("Parent1", TVI_ROOT);
	hItem = treeCtrl.InsertItem("Parent2", TVI_ROOT, hItem);
	hItem = treeCtrl.InsertItem("Parent3", TVI_ROOT, hItem);
	treeCtrl.DeleteAllItems();*/
}

void CLeftPaneView::InsertDate2(CTreeCtrl& treeCtrl)
{
	
}


void CLeftPaneView::OnNcPaint()
{
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CTreeView::OnNcPaint()
	// ���ĵ���ȡ����
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	
	if (pDoc->control!=0)
	{
		CTreeCtrl& treeCtrl = GetTreeCtrl();
		int i = 0;
		table table1 = pDoc->_table;
		int n = table1.Getrow();
		char *_name = new char[25];
		treeCtrl.DeleteAllItems();

		for (i = 1; i <= n; i++)
		{
			table1.get_name(i, _name);
			treeCtrl.InsertItem(_name, 0, 0);
		}
	}
	pDoc->control = 0;
}


//void CLeftPaneView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}
