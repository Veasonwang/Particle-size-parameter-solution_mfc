// MainFrm.cpp : implementation of the CMainFrame class
//
#define _AFXDLL
#include "stdafx.h"
#include "Chapter16.h"
#include "Chapter16View.h"
#include "MainFrm.h"
#include "LeftPaneView.h"
//#include "PreHand.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	/*
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}*/

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);
	HICON m_hIcon = AfxGetApp()->LoadIcon(ID_MAIN);
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszName = "�����������";
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(!m_wndSplitter.CreateStatic(this,1,2))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftPaneView),CSize(100,100),pContext))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(Chapter16View),CSize(100,100),pContext))
		return FALSE;
	//m_pEditView = (CEditPaneView*)m_wndSplitter.GetPane(0,1);

	return TRUE;
}

void CMainFrame::SwitchToView(int nViewType)
{
	/*CLeftPaneView* pView = (CLeftPaneView*)m_wndSplitter.GetPane(0,1);
	CRect rcRight,rcFrame;
	pView->GetClientRect(&rcRight);
	GetClientRect(&rcFrame);
	pView->IsKindOf(RUNTIME_CLASS(Chapter16View));
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	switch(nViewType)
	{
	case EDITVIEW:		//CEditPaneView
		{
			//pDoc->c = "1234444444";
			/*if(!pView->IsKindOf(RUNTIME_CLASS(CEditPaneView)))
			{
				//ɾ���ɵ���ͼ
				m_wndSplitter.DeleteView(0,1);
				//�����µ���ͼ
				m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CEditPaneView),
					CSize(rcRight.Width(),rcRight.Height()),NULL);
				//�����ֲ�
				m_wndSplitter.RecalcLayout();
				m_pEditView= (CEditPaneView*)m_wndSplitter.GetPane(0,1);
				
			}
			Invalidate();
			break;
		}
	case LISTVIEW:	//CListPaneView
		{
			//pDoc->c = "56788";
			/*if(!pView->IsKindOf(RUNTIME_CLASS(CListPaneView)))
			{
				m_wndSplitter.DeleteView(0,1);
				m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CListPaneView),
					CSize(rcRight.Width(),rcRight.Height()),NULL);
				m_wndSplitter.RecalcLayout();
				m_pListView= (CListPaneView*)m_wndSplitter.GetPane(0,1);
			}
			
			Invalidate();
			break;
		}
	default:
		break;
	}*/

}


void CMainFrame::On32775()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	// TODO: �ڴ���������������
	CString a;
	a = "�ļ� (*.csv)|*.csv||";
	CFileDialog openFileDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_READONLY, a, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = " ";
	openFileDlg.DoModal();
	a = openFileDlg.GetPathName();
	std::string f_name(a.GetBuffer());
	if (f_name == "")
	{
		/*pDoc->SO = 0;
		pDoc->Size_Average = 0;
		pDoc->Size_Middle = 0;
		pDoc->Skew = 0;
		pDoc->Kurtosis = 0;
		pDoc->length = 0;*/
	}
	else
	{
		pDoc->fil_name = f_name;
		pDoc->_table.Init();
		get_restlt_data(f_name, &(pDoc->length) , &pDoc->_table);
		
		pDoc->NUM = 0;
		pDoc->SO = pDoc->_table.get_So(pDoc->NUM);
		pDoc->Size_Average = pDoc->_table.get_AverageSize(pDoc->NUM);
		pDoc->Size_Middle = pDoc->_table.get_SizeMiddle(pDoc->NUM);
		pDoc->Skew = pDoc->_table.get_Skew(pDoc->NUM);
		pDoc->Kurtosis = pDoc->_table.get_Kurtosis(pDoc->NUM);
		
		//CLeftPaneView* pView = (CLeftPaneView*)m_wndSplitter.GetPane(0, 0);
		pDoc->control = 1;
	}
	Flash();
	Invalidate();
}

void Save_result(CString filePath)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	Chapter16Doc* pDoc = (Chapter16Doc*)pMainFrame->GetActiveDocument();
	HANDLE hFile = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{ }
	else
	{
		if (pDoc->_table.Output(hFile) == 1)
		{
			MessageBox(NULL,  "�����ɹ���", "��ʾ", MB_OK);
		}
		else
			MessageBox(NULL,  "����һ�����⣬�����Ƿ�������", "��ʾ", MB_OK);

	}
}

void CMainFrame::On32776()
{
	// TODO: �ڴ���������������
	BOOL isOpen = FALSE;        //�Ƿ��(����Ϊ����)  
	CString defaultDir = "";   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = "";         //Ĭ�ϴ򿪵��ļ���  
	CString filter = "�ļ� (*.csv)|*.csv||";   //�ļ����ǵ�����  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = "";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	Save_result(filePath);
}


void CMainFrame::Flash()
{
	Chapter16View* pView = (Chapter16View*)m_wndSplitter.GetPane(0, 1);
	pView->Invalidate();
}


void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CFrameWnd::OnLButtonDown(nFlags, point);
}
