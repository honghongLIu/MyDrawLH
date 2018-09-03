
// 周经理绘图Dlg.h : 头文件
//

#pragma once
#include "atltypes.h"

#include "vector"
#include "afxcoll.h"
using namespace std ;





// C周经理绘图Dlg 对话框
class C周经理绘图Dlg : public CDialogEx
{
	
	//friend class SetDlg;
// 构造
public:
	C周经理绘图Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedLine();
	afx_msg void OnBnClickedRect();
	afx_msg void OnBnClickedEllirect();
	afx_msg void OnBnClickedColor();
	afx_msg void OnBnClickedStart();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	afx_msg void OnBnClickedDash();
	afx_msg void OnBnClickedSolid();
	afx_msg void OnPaint();

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedSetting();
	
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnBnClickedBtnclearread();
	
	afx_msg void OnBnClickedSend();
private:
	// 窗口横坐标最大值
	int m_nmx;
	// 窗口纵坐标最大值
	int m_nmy;

	int m_nwidth1;
	int m_type;
	int m_pentype;
	COLORREF m_color;
	int num;
	 vector<CPoint> m_arrPt;//这是个容器
	 CPtrArray m_ptrArray;//CPtrArray类的变量
	

	 int m_nwidth1read;
	 int m_typeread;
	 int m_pentyperead;
	 COLORREF m_colorread;
	vector<CPoint> m_arrPtread;
	 CPtrArray m_ptrArrayread;//CPtrArray类的变量

	// vector< vector < CPoint > >	m_arrPtAll;	// 这是一个装容器的容器

	//CPoint m_pold;// 原来的点，连线的前一个点
	//CPoint m_pnew;
	//CPoint  m_startpoint;
	BOOL m_bDrawing;

	
	CImage image;  
	DWORD bytenum;
	int PaintorShow;


public:
	CString m_saveString;
	CString m_readString;
public:
	

	static UINT PutFile(LPVOID pFtp);

	

};
