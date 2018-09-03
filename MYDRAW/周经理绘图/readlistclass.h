#pragma once
#include "vector"
#include "afxcoll.h"
using namespace std ;

// readlistclass 对话框

class readlistclass : public CDialogEx
{
	DECLARE_DYNAMIC(readlistclass)

public:
	//readlistclass(CWnd* pParent = NULL);   // 标准构造函数
	
   readlistclass(int m_pentyperead, int m_nwidth1read,COLORREF m_colorread, int m_typeread, vector<CPoint> m_arrPtread);
	virtual ~readlistclass();

// 对话框数据
	enum { IDD = IDD_READLISTCLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	int m_nwidth1read;
	int m_typeread;
	int m_pentyperead;
	COLORREF m_colorread;

	//long pointnum;
	vector<CPoint> m_arrPtread;//这是个容器
};
