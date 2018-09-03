#pragma once


// CSetDlg 对话框

class CSetDlg : public   CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetDlg();

// 对话框数据
	enum { IDD = IDD_SETDIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int senddatacolor(){return m_color;};
	int senddatawidth(){return m_nwidth1;};
	int senddatapentype(){return m_pentype;};
	int senddatalinetype(){return m_type;};

	afx_msg void OnCbnSelchangeCombo1();
	
private:
	int m_pentype;
	int m_type;
	COLORREF m_color;
	int m_nwidth1;
	int m_typechose;


	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnBnClickedColor();
	afx_msg void OnBnClickedSolid();
	afx_msg void OnBnClickedDash();

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();

};

