#pragma once
//#include "DECLARE_SERIAL"
#include "atltypes.h"

#include "vector"
#include "afxcoll.h"
using namespace std ;
// Drawlist 对话框

class Drawlist : public CDialogEx
{
	DECLARE_DYNAMIC(Drawlist)

public:
	//Drawlist(CWnd* pParent = NULL);   // 标准构造函数
	Drawlist (int m_pentype, int m_nwidth1,COLORREF m_color, int m_type, vector<CPoint> m_arrPt);
	virtual ~Drawlist();

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	
	int m_pentype;
	int m_type;
	COLORREF m_color;
	int m_nwidth1;

	//long pointnum;
	vector<CPoint> m_arrPt;//这是个容器

	
	
	
};
