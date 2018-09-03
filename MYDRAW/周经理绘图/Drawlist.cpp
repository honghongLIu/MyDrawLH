// Drawlist.cpp : 实现文件
//

#include "stdafx.h"
#include "mydrawLH.h"
#include "Drawlist.h"
#include "SetDlg.h"
#include "afxdialogex.h"

#include "vector"
using namespace std ;



// Drawlist 对话框

IMPLEMENT_DYNAMIC(Drawlist, CDialogEx)

//Drawlist::Drawlist(CWnd* pParent /*=NULL*/)
Drawlist::Drawlist(int m_pentype, int m_nwidth1,COLORREF m_color, int m_type, vector<CPoint> m_arrPt)
	//: CDialogEx(Drawlist::IDD, pParent)

	//,m_drawpen(PS_SOLID,1,RGB(0,0,255))

{
	//this ->pointnum=pointnum;
	//this ->m_type=m_type;
	this -> m_pentype=m_pentype;
	this ->m_nwidth1=m_nwidth1;
	this ->m_color=m_color;
	this ->m_type=m_type;
	this ->m_arrPt=m_arrPt;
	/*m_color = RGB(0,0,255);
	m_pentype=PS_SOLID;
	m_nwidth1 = 1;
	m_type=1;*/
	

}


Drawlist::~Drawlist()
{
}

void Drawlist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(Drawlist, CDialogEx)

	
	
END_MESSAGE_MAP()


// Drawlist 消息处理程序








