// Chapter16View.cpp : implementation of the Chapter16View class
//

#include "stdafx.h"
#include "Chapter16.h"
#include "Chapter16Doc.h"
#include "Chapter16View.h"
#include"MainFrm.h"
#include"LeftPaneView.h"
//#include"PreHand.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#define PTOP 0.3
#define PBOT 0.2
#define PLR 0.2
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Chapter16View

IMPLEMENT_DYNCREATE(Chapter16View, CView)

BEGIN_MESSAGE_MAP(Chapter16View, CView)
	//{{AFX_MSG_MAP(Chapter16View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	//ON_COMMAND(ID_32775, &Chapter16View::On32773)
	//ON_COMMAND(ID_32776, &Chapter16View::On32774save)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Chapter16View construction/destruction
CMainFrame *pMain;
table _table;
string fil_name;
Chapter16View::Chapter16View()
{
	// TODO: add construction code here
	fil_name = "";
	i = 0;
	//定义画笔
	hPen = CreatePen(PS_SOLID, 1, RGB(23, 225, 232));
	hPen1 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	hPen2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	hPen3 = CreatePen(PS_SOLID, 1, RGB(184, 188, 186));
	Size_Middle = 0;
	SO = 0;
	Size_Average = 0;
	Skew = 0;
	Kurtosis = 0;
	NUM = 1;
	
}

Chapter16View::~Chapter16View()
{
}

BOOL Chapter16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// Chapter16View drawing

void Chapter16View::OnDraw(CDC* pDC)
{

	Chapter16Doc *pDoc = GetDocument();
	NUM = pDoc->NUM;
	Size_Middle = pDoc->Size_Middle;
	SO = pDoc->SO;
	Size_Average = pDoc->Size_Average;
	Skew = pDoc->Skew;
	Kurtosis = pDoc->Kurtosis;
	_table = pDoc->_table;
	fil_name = pDoc->fil_name;
	length = pDoc->length;

	CRect rect;
	GetClientRect(&rect);
	/*
	CDC dcMem;                                                  //用于缓冲作图的内存DC
	CBitmap bmp;                                                 //内存中承载临时图象的位图
	dcMem.CreateCompatibleDC(pDC);               //依附窗口DC创建兼容内存DC
	bmp.CreateCompatibleBitmap(&dcMem, rect.Width(), rect.Height());//创建兼容位图
	dcMem.SelectObject(&bmp);                          //将位图选择进内存DC
	dcMem.FillSolidRect(rect, pDC->GetBkColor());//按原来背景填充客户区，不然会是黑色
	*/
	HDC hdc = pDC->GetSafeHdc();

	//画图
	POINT pt[255];
	CRect rt;
	GetClientRect(&rt);
	double cxClient, cyClient;
	cxClient = rt.right - rt.left;
	cyClient = rt.bottom - rt.top;

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);//将内存DC上的图象拷贝到前台






	HPEN hOldPen;

	//
	/*
	if (MSE_LCT.x >= PLR*cxClient&&MSE_LCT.x <= 0.8*cxClient&&MSE_LCT.y >= 0.3*cyClient&&MSE_LCT.y <= 0.8*cyClient)
	{
		string str1 = "粒径:";
		string str2 = int_to_str_x(MSE_LCT.x, cxClient,_table.Getlength());
		string str3 = int_to_str_y(MSE_LCT.y, cyClient);
		string str4 = "百分比:";
		string str5 = str1 + str2;
		string str6 = str4 + str3;

		TextOut(hdc, cxClient*0.2, cyClient*0.1 + 10, str5.c_str(), strlen(str5.c_str()));
		TextOut(hdc, cxClient*0.2, cyClient*0.1 + 30, str6.c_str(), strlen(str6.c_str()));

		//绘制坐标线
		//hOldPen = (HPEN)SelectObject(hdc, hPen4);
		MoveToEx(hdc, MSE_LCT.x, MSE_LCT.y, NULL);
		LineTo(hdc, MSE_LCT.x, cyClient *0.8);
		MoveToEx(hdc, MSE_LCT.x, MSE_LCT.y, NULL);
		LineTo(hdc, 0.2*cxClient, MSE_LCT.y);
		MoveToEx(hdc, MSE_LCT.x, MSE_LCT.y, NULL);
		LineTo(hdc, 0.8*cxClient, MSE_LCT.y);
		MoveToEx(hdc, MSE_LCT.x, MSE_LCT.y, NULL);
		LineTo(hdc, MSE_LCT.x, cyClient *0.3);


		

	}*/

	//绘制图例
	hOldPen = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, 0.6*cxClient, cyClient*0.15 + 10, NULL);
	LineTo(hdc, 0.65*cxClient, cyClient *0.15 + 10);
	TextOut(hdc, 0.65*cxClient + 10, cyClient*0.15 + 5, "累计曲线", strlen("累计曲线"));
	hOldPen = (HPEN)SelectObject(hdc, hPen1);
	MoveToEx(hdc, 0.6*cxClient, cyClient*0.15 + 30, NULL);
	LineTo(hdc, 0.65*cxClient, cyClient *0.15 + 30);
	TextOut(hdc, 0.65*cxClient + 10, cyClient*0.15 + 25, "分布曲线", strlen("分布曲线"));

	string str7 = "当前文件:" + fil_name;
	xlength = 0.6*cxClient;
	ylength = 0.5*cyClient;
	TextOut(hdc, cxClient*0.2, cyClient*0.1 - 10, str7.c_str(), strlen(str7.c_str()));



	//画坐标系
	hOldPen = (HPEN)SelectObject(hdc, hPen2);
	TextOut(hdc, cxClient*0.2 + 0.0125*xlength, cyClient*0.8 + 10, "5um", strlen("5um"));
	TextOut(hdc, cxClient*0.2 + 0.125*xlength - 10, cyClient*0.8 + 10, "50um", strlen("50um"));
	TextOut(hdc, cxClient*0.2 + 0.25*xlength - 10, cyClient*0.8 + 10, "100um", strlen("100um"));
	TextOut(hdc, cxClient*0.2 + 0.375*xlength - 10, cyClient*0.8 + 10, "150um", strlen("150um"));
	TextOut(hdc, cxClient*0.2 + 0.5*xlength - 10, cyClient*0.8 + 10, "200um", strlen("200um"));
	TextOut(hdc, cxClient*0.2 + 0.625*xlength - 10, cyClient*0.8 + 10, "250um", strlen("250um"));
	TextOut(hdc, cxClient*0.2 + 0.75*xlength - 10, cyClient*0.8 + 10, "300um", strlen("300um"));
	TextOut(hdc, cxClient*0.2 + 0.875*xlength - 10, cyClient*0.8 + 10, "350um", strlen("350um"));
	TextOut(hdc, cxClient*0.2 + xlength - 10, cyClient*0.8 + 10, "400um", strlen("400um"));

	TextOut(hdc, cxClient*0.2 - 38, 0.3*cyClient - 3, "100%", strlen("100%"));
	TextOut(hdc, cxClient*0.2 - 33, 0.3*cyClient + 0.25*ylength - 8, "75%", strlen("75%"));
	TextOut(hdc, cxClient*0.2 - 33, 0.3*cyClient + 0.5*ylength - 8, "50%", strlen("50%"));
	TextOut(hdc, cxClient*0.2 - 33, 0.3*cyClient + 0.75*ylength - 8, "25%", strlen("25%"));
	TextOut(hdc, cxClient*0.2 - 28, 0.3*cyClient + ylength - 10, "0%", strlen("0%"));

	MoveToEx(hdc, PLR*cxClient, cyClient *0.8, NULL);
	LineTo(hdc, 0.8*cxClient, cyClient *0.8);
	MoveToEx(hdc, PLR*cxClient, cyClient *0.8, NULL);
	LineTo(hdc, PLR*cxClient, cyClient *0.3);

	//绘制网格
	hOldPen = (HPEN)SelectObject(hdc, hPen3);
	MoveToEx(hdc, cxClient*0.2 + 0.125*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.125*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.25*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.25*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.375*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.375*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.5*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.5*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.625*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.625*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.75*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.75*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 0.875*xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 0.875*xlength, cyClient *0.3);
	MoveToEx(hdc, cxClient*0.2 + 1 * xlength, cyClient*0.8, NULL);
	LineTo(hdc, cxClient*0.2 + 1 * xlength, cyClient *0.3);

	MoveToEx(hdc, cxClient*0.2, 0.3*cyClient, NULL);
	LineTo(hdc, cxClient*0.8, 0.3*cyClient + 0 * ylength);
	MoveToEx(hdc, cxClient*0.2, 0.3*cyClient + 0.75*ylength, NULL);
	LineTo(hdc, cxClient*0.8, 0.3*cyClient + 0.75* ylength);
	MoveToEx(hdc, cxClient*0.2, 0.3*cyClient + 0.5*ylength, NULL);
	LineTo(hdc, cxClient*0.8, 0.3*cyClient + 0.5 * ylength);
	MoveToEx(hdc, cxClient*0.2, 0.3*cyClient + 0.25*ylength, NULL);
	LineTo(hdc, cxClient*0.8, 0.3*cyClient + 0.25 * ylength);




	//绘制函数曲线

	hOldPen = (HPEN)SelectObject(hdc, hPen);

	for (int i = 0; i < length; i++)
	{
		pt[i].x = (get_table(i) / get_table(length - 1))*(0.6*cxClient) + 0.2*cxClient;
		pt[i].y = cyClient - (0.5*(cyClient*(_table.get_add_data(NUM, i)) / 100) + 0.2*cyClient);
		Ellipse(hdc, pt[i].x - 2, pt[i].y - 2, pt[i].x + 2, pt[i].y + 2);
	}
	Polyline(hdc, pt, length);

	hOldPen = (HPEN)SelectObject(hdc, hPen1);
	for (int i = 0; i < length; i++)
	{

		pt[i].x = (get_table(i) / get_table(length - 1))*(0.6*cxClient) + 0.2*cxClient;
		pt[i].y = cyClient - (0.5*(cyClient*(_table.get_data(NUM, i)) / 100) + 0.2*cyClient);
		Ellipse(hdc, pt[i].x - 2, pt[i].y - 2, pt[i].x + 2, pt[i].y + 2);
	}
	Polyline(hdc, pt, length);

	//绘制结果
	string result_average = "平均粒径:" + dob_to_str(Size_Average) + "um";
	TextOut(hdc, 20, 0.3*cyClient - 30, result_average.c_str(), strlen(result_average.c_str()));
	string result_1 = "粒度中值:" + dob_to_str(Size_Middle) + "um";
	TextOut(hdc, 20, 0.3*cyClient, result_1.c_str(), strlen(result_1.c_str()));
	string result_SO = "分选系数:" + dob_to_str(SO);
	TextOut(hdc, 20, 0.3*cyClient + 30, result_SO.c_str(), strlen(result_SO.c_str()));
	string result_Skew = "偏度:" + dob_to_str(Skew);
	TextOut(hdc, 20, 0.3*cyClient + 60, result_Skew.c_str(), strlen(result_Skew.c_str()));
	string result_Kurtosis = "尖度:" + dob_to_str(Kurtosis);
	TextOut(hdc, 20, 0.3*cyClient + 90, result_Kurtosis.c_str(), strlen(result_Kurtosis.c_str()));





	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);//将内存DC上的图象拷贝到前台
	//dcMem.DeleteDC();                                       //删除DC
	//bmp.DeleteObject();                                     //删除位图
}

/////////////////////////////////////////////////////////////////////////////
// Chapter16View printing

BOOL Chapter16View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Chapter16View::OnBeginPrinting(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing

}

void Chapter16View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// Chapter16View diagnostics

#ifdef _DEBUG
void Chapter16View::AssertValid() const
{
	CView::AssertValid();
}

void Chapter16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chapter16Doc* Chapter16View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chapter16Doc)));
	return (Chapter16Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Chapter16View message handlers

/*
void Chapter16View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CString a;
	a = "文件 (*.csv)|*.csv||";
	CFileDialog openFileDlg(TRUE, "", "", OFN_HIDEREADONLY | OFN_READONLY, a, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = " ";
	openFileDlg.DoModal();
	a = openFileDlg.GetPathName();
	string f_name(a.GetBuffer());
	fil_name = f_name;
	if (f_name == "")
	{
		SO = 0;
		Size_Average = 0;
		Size_Middle = 0;
		Skew = 0;
		Kurtosis = 0;
		length = 0;
	}
	else
	{
		get_restlt_data(f_name, &length, &_table);
		SO = _table.get_So(NUM);
		Size_Average = _table.get_AverageSize(NUM);
		Size_Middle = _table.get_SizeMiddle(NUM);
		Skew = _table.get_Skew(NUM);
		Kurtosis = _table.get_Kurtosis(NUM);
	}
	Invalidate();
}
void Save_result(CString filePath)
{
	HANDLE hFile = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		MessageBox(NULL, "error", "error1", MB_OK);
	_table.Output(hFile);
}

void Chapter16View::On32774save()
{
	// TODO: 在此添加命令处理程序代码
	BOOL isOpen = FALSE;        //是否打开(否则为保存)  
	CString defaultDir = "";   //默认打开的文件路径  
	CString fileName = "";         //默认打开的文件名  
	CString filter = "文件 (*.csv)|*.csv||";   //文件过虑的类型  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = "";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	Save_result(filePath);
}
*/

void Chapter16View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/*
	CView::OnMouseMove(nFlags, point);
	RECT rt;
	CPaintDC hdc(this);
	CWnd::OnMouseMove(nFlags, point);
	GetClientRect(&rt);
	int cxClient, cyClient;
	cxClient = rt.right - rt.left;
	cyClient = rt.bottom - rt.top;
	MSE_LCT.x = point.x;
	MSE_LCT.y = point.y;
	if (MSE_LCT.x >= (PLR - 0.05)*cxClient&&MSE_LCT.x <= 0.85*cxClient&&MSE_LCT.y >= 0.25*cyClient&&MSE_LCT.y <= 0.85*cyClient)
	{
		//SetClassLong(this->GetSafeHwnd(),GCL_HCURSOR,(LONG)LoadCursor(NULL, IDC_CROSS));
		Invalidate();
	}
	*/
}

