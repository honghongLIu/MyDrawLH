// SetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mydrawLH.h"
#include "SetDlg.h"
#include "afxdialogex.h"


// CSetDlg �Ի���

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetDlg::IDD, pParent)
	, m_type(0)
	, m_nwidth1(0)
	, m_pentype(0)
	, m_typechose(0)
{

	m_color = RGB(0,0,255);
	m_pentype=PS_SOLID;
	m_nwidth1 = 1;
	m_type=1;
		

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_CBIndex(pDX, IDC_COMBO1, m_typechose);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_COLOR, &CSetDlg::OnBnClickedColor)
	ON_BN_CLICKED(IDC_SOLID, &CSetDlg::OnBnClickedSolid)
	ON_BN_CLICKED(IDC_DASH, &CSetDlg::OnBnClickedDash)
	ON_BN_CLICKED(IDC_RADIO1, &CSetDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSetDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CSetDlg::OnBnClickedRadio3)	
	ON_BN_CLICKED(IDOK, &CSetDlg::OnBnClickedOk)	
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSetDlg::OnCbnSelchangeCombo1)

END_MESSAGE_MAP()




//��ʼ������

BOOL CSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);//ѡ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
	
	
}


// CSetDlg ��Ϣ�������


void CSetDlg::OnBnClickedSolid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pentype=PS_SOLID;
	UpdateData(FALSE);
}



void CSetDlg::OnBnClickedDash()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pentype=PS_DASH;
	UpdateData(FALSE);
}


void CSetDlg::OnBnClickedColor()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CColorDialog dlg;
	dlg.m_cc.Flags |=CC_PREVENTFULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(dlg.DoModal()==IDOK)
	{
		m_color=dlg.GetColor();//��ȡѡ������ɫ�����丳����ǰ������ɫ����

	}
	UpdateData(FALSE);
}


void CSetDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nwidth1=1;
	UpdateData(FALSE);
}


void CSetDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nwidth1=3;
	UpdateData(FALSE);
}


void CSetDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nwidth1=5;
	
	UpdateData(FALSE);
}



void CSetDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();

	
}



void CSetDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	switch(m_typechose)
	{
	case 0:
		m_type=2;
		break;
	case 1:
		m_type=1;
		break;
	case 2:
		m_type=3;
		break;
	case 3:
		m_type=4;
		break;
	default:
		break;

	}
	UpdateData(FALSE);
	
}

