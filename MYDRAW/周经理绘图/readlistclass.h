#pragma once
#include "vector"
#include "afxcoll.h"
using namespace std ;

// readlistclass �Ի���

class readlistclass : public CDialogEx
{
	DECLARE_DYNAMIC(readlistclass)

public:
	//readlistclass(CWnd* pParent = NULL);   // ��׼���캯��
	
   readlistclass(int m_pentyperead, int m_nwidth1read,COLORREF m_colorread, int m_typeread, vector<CPoint> m_arrPtread);
	virtual ~readlistclass();

// �Ի�������
	enum { IDD = IDD_READLISTCLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	
	int m_nwidth1read;
	int m_typeread;
	int m_pentyperead;
	COLORREF m_colorread;

	//long pointnum;
	vector<CPoint> m_arrPtread;//���Ǹ�����
};
