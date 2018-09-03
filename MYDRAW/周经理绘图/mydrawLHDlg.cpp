// 周经理绘图Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mydrawLH.h"
#include "mydrawLHDlg.h"
#include "afxdialogex.h"
#include < afxinet.h >//FTP
#include "SetDlg.h"
#include "afxtempl.h"
#include "Drawlist.h"
#include "readlistclass.h"

#include "afx.h"


#include "vector"
using namespace std ;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



// C周经理绘图Dlg 对话框




C周经理绘图Dlg::C周经理绘图Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C周经理绘图Dlg::IDD, pParent)
    ,m_bDrawing(FALSE)
	//, m_pold(0)
	//, m_pnew(0)
	, m_nwidth1(0)
	, m_pentype(0)

	,m_saveString(_T(""))
	, m_readString(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//*****************************
	m_color = RGB(0,0,255);
	m_pentype=PS_SOLID;
	m_nwidth1 = 1;
	m_type=1;
	num=1;
	//PaintorShow =0;//默认是在画，用于onpaint中的画图或者是显示

	
}

//C周经理绘图Dlg::~C周经理绘图Dlg(CWnd* pParent /*=NULL*/)
//{
	//delete m_pmdc;
	///delete m_pbmp;
//}


void C周经理绘图Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_DRAWT, m_saveString);
	DDX_Text(pDX, IDC_SHOWPAINT, m_readString);
}


//消息映射表
BEGIN_MESSAGE_MAP(C周经理绘图Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SETTING, &C周经理绘图Dlg::OnBnClickedSetting)

	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &C周经理绘图Dlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &C周经理绘图Dlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDC_BTNCLEAR, &C周经理绘图Dlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTNCLEARREAD, &C周经理绘图Dlg:: OnBnClickedBtnclearread)
	
	ON_BN_CLICKED(IDC_SEND, &C周经理绘图Dlg::OnBnClickedSend)
END_MESSAGE_MAP()


// C周经理绘图Dlg 消息处理程序

BOOL C周经理绘图Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	// TODO: 在此添加额外的初始化代码
	
	/////////////////////////////////// 注意初始化状态 ////////////////////////////////////////////
	//m_arrPtAll.clear();
	//m_ptrArray.clear();//“clear”: 不是“CPtrArray”的成员
	/////////////////////////////////////   end ///////////////////////////////////////////////////
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C周经理绘图Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C周经理绘图Dlg::OnPaint()
{
	CDialogEx::OnPaint();
	
	
		CPaintDC dcDrawBack( GetDlgItem( IDC_DRAWT ) );
		CRect rc;
		GetDlgItem(IDC_DRAWT)->GetClientRect( &rc );
		CDC dcDraw; 
		dcDraw.CreateCompatibleDC(&dcDrawBack);
		CBitmap mBitmap;  
		mBitmap.CreateCompatibleBitmap(&dcDrawBack, rc.Width(), rc.Height());
		CBitmap *oBitmap=dcDraw.SelectObject(&mBitmap);
		CBrush drawBrush;
		drawBrush.CreateStockObject(NULL_BRUSH);
		CBrush*oldBrush= dcDraw.SelectObject(&drawBrush);
		dcDraw.FillRect( &rc, &CBrush( RGB( 255, 255, 255 ) ) );

		CPaintDC dcDrawreadBack( GetDlgItem( IDC_SHOWPAINT ) );
		CRect rcread;
		GetDlgItem(IDC_SHOWPAINT)->GetClientRect( &rcread );
		CDC dcDrawread; 
		dcDrawread.CreateCompatibleDC(&dcDrawreadBack);
		CBitmap mBitmapread;  
		mBitmapread.CreateCompatibleBitmap(&dcDrawreadBack, rcread.Width(), rcread.Height());
		CBitmap *oBitmapread=dcDrawread.SelectObject(&mBitmapread);
		CBrush drawBrushread;
		drawBrushread.CreateStockObject(NULL_BRUSH);
		CBrush*oldBrushread= dcDrawread.SelectObject(&drawBrushread);
		dcDrawread.FillRect( &rcread, &CBrush( RGB( 255, 255, 255 ) ) );

			CRect rcDraw;	
			GetDlgItem(IDC_DRAWT)->GetWindowRect(&rcDraw);
			ScreenToClient(&rcDraw);
			int xOff = rcDraw.left;
			int yOff = rcDraw.top;

			dcDraw.FillRect( &rc, &CBrush( RGB( 255, 255, 255 ) ) );
			dcDrawread.FillRect( &rcread, &CBrush( RGB( 255, 255, 255 ) ) );

			for ( int i = 0; i < m_ptrArray.GetSize(); i++ )//用来显示之前的轨迹
			{
				int countbig;
				countbig=((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt.size();

				CPen drawPen;
				drawPen.CreatePen(((Drawlist*)m_ptrArray.GetAt(i))->m_pentype,((Drawlist*)m_ptrArray.GetAt(i))->m_nwidth1,((Drawlist*)m_ptrArray.GetAt(i))->m_color);
				CPen* oldPen = dcDraw.SelectObject( &drawPen );


				switch(((Drawlist*)m_ptrArray.GetAt(i))->m_type)
				{
				case 1:
					{
						for (int j=1;j<countbig;j++)
						{
							dcDraw.MoveTo( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[j-1].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[j-1].y- yOff);
							dcDraw.LineTo( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[j].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[j].y- yOff);
						}

					}
					break;
				case 2:
					{
						dcDraw.Rectangle( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].y- yOff,((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].y- yOff);
					}
					break;
				case 3:
					{
						dcDraw.RoundRect( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].y- yOff,((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].y- yOff,10,10);
					}
					break;
				case 4:
					{
						dcDraw.MoveTo( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[0].y- yOff);
						dcDraw.LineTo( ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].x- xOff, ((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[countbig-1].y- yOff);
					}
					break;
				default:

					break;

				}
				dcDraw.SelectObject( oldPen );
				drawPen.DeleteObject();
				

			}


			for( int i = 1;i < m_arrPt.size(); i++ )//用来画当前的轨迹
			{
				int count;
				count=m_arrPt.size();

				CPen drawPen;
				drawPen.CreatePen(m_pentype,m_nwidth1,m_color);
				CPen* oldPen = dcDraw.SelectObject( &drawPen );

				switch(m_type)
				{
				case 1:
					{
						dcDraw.MoveTo( m_arrPt[ i - 1 ].x - xOff, m_arrPt[ i - 1 ].y - yOff );
						dcDraw.LineTo( m_arrPt[ i ].x - xOff, m_arrPt[ i ].y - yOff );

					}
					break;
				case 2:
					{
						dcDraw.Rectangle( m_arrPt[ 0 ].x- xOff,m_arrPt[ 0 ].y- yOff, m_arrPt[ count-1 ].x- xOff,m_arrPt[ count-1].y- yOff );

					}
					break;
				case 3:
					{
						dcDraw.RoundRect( m_arrPt[ 0 ].x- xOff,m_arrPt[ 0 ].y- yOff, m_arrPt[ count-1 ].x- xOff,m_arrPt[ count-1].y- yOff ,10,10);

					}
					break;
				case 4:
					{
						dcDraw.MoveTo( m_arrPt[ 0 ].x - xOff, m_arrPt[ 0].y - yOff );
						dcDraw.LineTo( m_arrPt[ count-1 ].x - xOff, m_arrPt[ count-1 ].y - yOff );

					}
					break;
				default:

					break;

				}

				dcDraw.SelectObject( oldPen );

				drawPen.DeleteObject();

			}

			dcDrawBack.BitBlt( 0, 0, rc.Width(), rc.Height(), &dcDraw, 0, 0, SRCCOPY );
			dcDrawreadBack.BitBlt( 0, 0, rcread.Width(), rcread.Height(), &dcDrawread, 0, 0, SRCCOPY );
			dcDraw.SelectObject( oBitmap );
			mBitmap.DeleteObject();
			dcDraw.DeleteDC();

			
					
		if (m_ptrArrayread.GetSize() > 0 )
		{
		
			int aa;
			aa=m_ptrArrayread.GetSize();
			for ( int i = 0; i < m_ptrArrayread.GetSize(); i++ )
			{
				int countbigread1;
				countbigread1=((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread.size();

				CPen drawPenread;
				int m_pentyperead1;
				m_pentyperead1=((readlistclass*)m_ptrArrayread.GetAt(i))->m_pentyperead;
				drawPenread.CreatePen(((readlistclass*)m_ptrArrayread.GetAt(i))->m_pentyperead,((readlistclass*)m_ptrArrayread.GetAt(i))->m_nwidth1read,((readlistclass*)m_ptrArrayread.GetAt(i))->m_colorread);
				CPen* oldPenread = dcDrawread.SelectObject( &drawPenread );

				switch(((readlistclass*)m_ptrArrayread.GetAt(i))->m_typeread)
				{
				case 1:
					{
						for (int j=1;j<countbigread1;j++)
						{
							dcDrawread.MoveTo( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[j-1].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[j-1].y- yOff);
							dcDrawread.LineTo( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[j].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[j].y- yOff);
						}

					}
					break;
				case 2:
					{
						dcDrawread.Rectangle( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].y- yOff,((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].y- yOff);
					}
					break;
				case 3:
					{
						dcDrawread.RoundRect( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].y- yOff,((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].y- yOff,10,10);
					}
					break;
				case 4:
					{
						dcDrawread.MoveTo( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[0].y- yOff);
						dcDrawread.LineTo( ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].x- xOff, ((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread[countbigread1-1].y- yOff);
					}
					break;
				default:

					break;

				}

				dcDraw.SelectObject(drawBrush);

				dcDrawread.SelectObject( oldPenread );
				dcDrawread.SelectObject(drawBrushread);
				drawPenread.DeleteObject();

			}
								
						
				dcDrawreadBack.BitBlt( 0, 0, rcread.Width(), rcread.Height(), &dcDrawread, 0, 0, SRCCOPY );
				dcDrawread.SelectObject( oBitmapread );
				mBitmapread.DeleteObject();
				dcDrawread.DeleteDC();

		}

	}
	

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C周经理绘图Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C周经理绘图Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc;//rc为控件的大小
	CWnd *pWND = GetDlgItem(IDC_DRAWT);
	pWND->GetWindowRect(&rc);
	ScreenToClient(&rc);
	if(!PtInRect(&rc,point))//判断鼠标移动这个点在picture这个控件里吗
	{
		m_bDrawing = FALSE;
		return;
	}

	m_bDrawing=TRUE;
	m_arrPt.push_back(point);

	CDialogEx::OnLButtonDown(nFlags, point);
	
}


void C周经理绘图Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取picture控件的高度等大小信息
	
	CRect rc;//rc为控件的大小
	CWnd *pWND = GetDlgItem(IDC_DRAWT);
	pWND->GetWindowRect(&rc);
	ScreenToClient(&rc);
	if(!PtInRect(&rc,point))//判断鼠标移动这个点在picture这个控件里吗
	{
		m_bDrawing = FALSE;
		return;
	}
			
	if(m_bDrawing == TRUE)
	{					
		m_arrPt.push_back(point);
			
		Invalidate(false);//不擦背景
		
	}
	
	CDialogEx::OnMouseMove(nFlags, point);
}



void C周经理绘图Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if(!m_bDrawing)return;//如果正在画图，执行如下代码，否则返回
	m_bDrawing=FALSE;


	Drawlist *graph=new Drawlist(m_pentype,m_nwidth1,m_color,m_type,m_arrPt);
	m_ptrArray.Add(graph);

	if( m_ptrArray.GetSize() > 0 )
	{
		m_arrPt.clear();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void C周经理绘图Dlg::OnBnClickedBtnclear()
{
	// TODO: 在此添加控件通知处理程序代码
	
	m_ptrArray.RemoveAll();
	m_arrPt.clear();
	
	m_bDrawing = false;
	Invalidate();//擦除背景
	
}
void C周经理绘图Dlg:: OnBnClickedBtnclearread()
	
{
	// TODO: 在此添加控件通知处理程序代码
	m_ptrArrayread.RemoveAll();
	m_arrPtread.clear();
	m_bDrawing = false;
	Invalidate();//擦除背景
}

void C周经理绘图Dlg::OnBnClickedSetting()
{
	// TODO: 在此添加控件通知处理程序代码
	

	CSetDlg Dlg;
	//Dlg.DoModal();//用于
	if(IDOK==Dlg.DoModal())
	{
		m_color=Dlg.senddatacolor();
		m_nwidth1=Dlg.senddatawidth();
		m_pentype=Dlg.senddatapentype();
		m_type=Dlg.senddatalinetype();

	}
	//UpdateData(FALSE);
	UpdateData(TRUE);
}



BOOL C周经理绘图Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//return TRUE;
	
	return CDialogEx::OnEraseBkgnd(pDC);
}


void C周经理绘图Dlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	PaintorShow =1;
	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = L"F:\MFC学习\画图文件";	//默认打开的文件路径
	CString fileName = L"";			//默认打开的文件名
	CString filter = L"文件 (*.dat;*.txt;*.doc; *.ppt; *.xls)|*.dat;*.txt;*.doc; *.ppt; *.xls||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"F:\MFC学习\画图文件";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\test.doc";
	if(result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
	}
	//******************实验*************
	/*CFile file;
	file.Open(filePath,CFile::modeRead);
	file.SeekToBegin();
	char *pBuf;
	DWORD dwFileLen;
	dwFileLen=file.GetLength();
	pBuf=new char[dwFileLen+1];
	pBuf[dwFileLen]=0;
	file.Read(pBuf,dwFileLen);
	file.Close();
	m_readString=pBuf;
	UpdateData(FALSE);*/
	//******************实验*************
	CFile file;
	file.Open(filePath,CFile::modeRead);
	int readnunofm_ptrArray;
	file.Read(&readnunofm_ptrArray,4);
	for ( int i = 0; i < readnunofm_ptrArray; i++ )
	{	
		if( m_ptrArrayread.GetSize() > 0 )
		{
			m_arrPtread.clear();
		}

		readlistclass *graphread=new readlistclass(m_pentyperead,m_nwidth1read,m_colorread,m_typeread,m_arrPtread);
		m_ptrArrayread.Add(graphread);
		int m_pentyperead1=3;
		int m_nwidth1read1=3;
		int m_typeread1=3;
		
		COLORREF m_colorread1;

		file.Read(&m_pentyperead1,4);
		file.Read(&m_nwidth1read1,4);
		file.Read(&m_colorread1,4);
		file.Read(&m_typeread1,4);
		((readlistclass*)m_ptrArrayread.GetAt(i))->m_pentyperead=m_pentyperead1;
		((readlistclass*)m_ptrArrayread.GetAt(i))->m_nwidth1read=m_nwidth1read1;
		((readlistclass*)m_ptrArrayread.GetAt(i))->m_colorread=m_colorread1;
		((readlistclass*)m_ptrArrayread.GetAt(i))->m_typeread=m_typeread1;
		int countread;
		
		file.Read(&countread,4);
		for( int j = 1;j <countread; j++ )
		{
			//CPoint point = (((Drawlist*)m_ptrArrayread.GetAt(i))->m_arrPt[j-1]);
			CPoint pointread;
			file.Read(&pointread.x,4);
			file.Read(&pointread.y,4);
			m_arrPtread.push_back(pointread);
			((readlistclass*)m_ptrArrayread.GetAt(i))->m_arrPtread=m_arrPtread;
			Invalidate();

		}
	

	}

	file.Close();



	CWnd::SetDlgItemTextW(IDC_OPEN_EDIT, filePath);
}


void C周经理绘图Dlg::OnBnClickedSaveButton()
{


	// TODO: 在此添加控件通知处理程序代码

	/*//*****************保存字符串*********************
	BOOL isOpen = FALSE;		//是否打开(否则为保存)
	CString defaultDir = L"F:\MFC学习\画图文件";	//默认打开的文件路径
	CString fileName = L"test.doc";			//默认打开的文件名
	CString filter = L"文件 (*.dat;*.doc; *.ppt; *.xls)|*.dat;*.doc;*.ppt;*.xls||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"F:\MFC学习\画图文件";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;

	if(result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
	}
	CFile file;
	file.Open(filePath,CFile::modeCreate|CFile::modeWrite);
	file.SeekToBegin();
	//file.Write((LPCTSTR)m_ptrArray,m_ptrArray.GetLength());
	char strtest[]="hello";
	CStringA aa=strtest;
	file.Write(strtest,aa.GetLength());
	file.Close();
	MessageBox("保存成功！");*/

	//*****************保存*********************
	BOOL isOpen = FALSE;		//是否打开(否则为保存)
	CString defaultDir = L"F:\MFC学习\画图文件";	//默认打开的文件路径
	CString fileName = L"test.txt";			//默认打开的文件名
	CString filter = L"文件 (*.dat;*.txt;*.doc; *.ppt; *.xls)|*.dat;*.txt;*.doc;*.ppt;*.xls||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"F:\MFC学习\画图文件";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;

	if(result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
	}
	//******************实验*************
	/*CFile file;
	file.Open(filePath,CFile::modeCreate|CFile::modeReadWrite);
	file.SeekToBegin();
	const unsigned char LeadBytes[]={0xff};
	file.Write(LeadBytes,sizeof(LeadBytes));//加unicode字节序标记
	file.Write("~~~liuhong",strlen("~~~liuhong"));
	file.Close();*/
	//******************实验*************

	
	//CArchive ar(&file,CArchive::store);

	/*for ( int i = 0; i < m_ptrArray.GetSize(); i++ )
	{
		ar.WriteObject((Drawlist*)m_ptrArray.GetAt(i));
	}*/
	//*******************  用file.write写 (未正确) ****************************
	CFile file;
	file.Open(filePath,CFile::modeCreate|CFile::modeReadWrite);
	int numofm_ptrArray=m_ptrArray.GetSize();
	file.Write(&numofm_ptrArray,4);
	for ( int i = 0; i < m_ptrArray.GetSize(); i++ )
	{		
		file.Write(&((Drawlist*)m_ptrArray.GetAt(i))->m_pentype,4);
		file.Write(&((Drawlist*)m_ptrArray.GetAt(i))->m_nwidth1,4);
		file.Write(&((Drawlist*)m_ptrArray.GetAt(i))->m_color,4);
		file.Write(&((Drawlist*)m_ptrArray.GetAt(i))->m_type,4);
		int count;
		count=(((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt).size();
		file.Write(&count,4);
		for( int j = 1;j <count; j++ )
		{
			CPoint point = (((Drawlist*)m_ptrArray.GetAt(i))->m_arrPt[j-1]);
	 		file.Write(&point.x,4);
			file.Write(&point.y,4);
		
		}

		}
	file.Close();
		
	CWnd::SetDlgItemTextW(IDC_SAVE_EDIT, filePath);

}


void C周经理绘图Dlg::OnBnClickedSend()
{
	UpdateData(FALSE);
	CString IPaddress1=_T("192.168.0.18");
	LPCTSTR	IPaddress=(LPCTSTR)IPaddress1;
	CString username1=_T("LHLH");//FTP3022123FTP上传
	LPCTSTR	username=(LPCTSTR)username1;

	CString password1=_T("123");
	LPCTSTR password=(LPCTSTR)password1;

	UINT port=21;
	CInternetSession* m_pInetSession;
	CFtpConnection*   m_pFtpConnection;
	m_pInetSession = new CInternetSession( AfxGetAppName(), 1,	PRE_CONFIG_INTERNET_ACCESS);
	//m_pInetSession = new CInternetSession;
	
	try{
		m_pFtpConnection= m_pInetSession->GetFtpConnection(IPaddress,username,password,21);
		// IPaddress1       ftp服务器的地址  LPCTSTR
		// username   登陆用户名       LPCTSTR 
		// password   密码            LPCTSTR
		// port       端口            UINT
	}

	//若登陆不成功则抛出异常，以下是针对异常的处理
	catch(CInternetException *pEx)
	{
		TCHAR szError[1024] = {0};
		if(pEx->GetErrorMessage(szError,1024))
			AfxMessageBox(szError);
		else
			AfxMessageBox(_T("There was an exception"));
		pEx->Delete();
		m_pFtpConnection = NULL;
		return;
	}


	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = L"F:\MFC学习\画图文件";	//默认打开的文件路径
	CString fileName = L"";			//默认打开的文件名
	CString filter = L"文件 (*.dat;*.txt;*.doc; *.ppt; *.xls)|*.dat;*.txt;*.doc; *.ppt; *.xls||";	//文件过虑的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"F:\MFC学习\画图文件";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\test.doc";
	if(result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
	}

	CString fileName_send=openFileDlg.GetFileName();

	CString strdir1=_T("\\");
	m_pFtpConnection->SetCurrentDirectory(strdir1);
	BOOL bput=m_pFtpConnection->PutFile(filePath,fileName_send);
	//LPCTSTR pstrLocalFile, LPCTSTR pstrRemoteFile,
	//	DWORD dwFlags = FTP_TRANSFER_TYPE_BINARY, DWORD_PTR dwContext = 1
	if (bput)

	{
		//MessageBox(NULL, _T("发送成功！"), _T("提示"), MB_OK);
		MessageBox( _T("发送成功！"));
		//第一个参数为地文件的地址，第二个为服务器端文件的地址
		//return 1;
	}
	else
	{

		//MessageBox(NULL, _T("发送失败！"), _T("提示"), MB_OK);
		MessageBox( _T("发送失败！"));
		//return 0;
	}

}