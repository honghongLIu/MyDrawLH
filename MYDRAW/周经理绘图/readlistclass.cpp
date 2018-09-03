// readlistclass.cpp : 实现文件
//

#include "stdafx.h"
#include "mydrawLH.h"
#include "readlistclass.h"
#include "afxdialogex.h"


// readlistclass 对话框






IMPLEMENT_DYNAMIC(readlistclass, CDialogEx)

//readlistclass::readlistclass(CWnd* pParent /*=NULL*/)
	//: CDialogEx(readlistclass::IDD, pParent)
	readlistclass::readlistclass(int m_pentyperead, int m_nwidth1read,COLORREF m_colorread, int m_typeread, vector<CPoint> m_arrPtread)
{
	this -> m_pentyperead=m_pentyperead;
	this ->m_nwidth1read=m_nwidth1read;
	this ->m_colorread=m_colorread;
	this ->m_typeread=m_typeread;
	this ->m_arrPtread=m_arrPtread;

}

readlistclass::~readlistclass()
{
}

void readlistclass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(readlistclass, CDialogEx)
END_MESSAGE_MAP()


// readlistclass 消息处理程序
