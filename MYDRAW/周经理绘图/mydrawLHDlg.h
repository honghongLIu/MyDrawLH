
// �ܾ����ͼDlg.h : ͷ�ļ�
//

#pragma once
#include "atltypes.h"

#include "vector"
#include "afxcoll.h"
using namespace std ;





// C�ܾ����ͼDlg �Ի���
class C�ܾ����ͼDlg : public CDialogEx
{
	
	//friend class SetDlg;
// ����
public:
	C�ܾ����ͼDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	// ���ں��������ֵ
	int m_nmx;
	// �������������ֵ
	int m_nmy;

	int m_nwidth1;
	int m_type;
	int m_pentype;
	COLORREF m_color;
	int num;
	 vector<CPoint> m_arrPt;//���Ǹ�����
	 CPtrArray m_ptrArray;//CPtrArray��ı���
	

	 int m_nwidth1read;
	 int m_typeread;
	 int m_pentyperead;
	 COLORREF m_colorread;
	vector<CPoint> m_arrPtread;
	 CPtrArray m_ptrArrayread;//CPtrArray��ı���

	// vector< vector < CPoint > >	m_arrPtAll;	// ����һ��װ����������

	//CPoint m_pold;// ԭ���ĵ㣬���ߵ�ǰһ����
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
