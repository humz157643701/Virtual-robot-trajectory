// Setdlg.cpp : ʵ���ļ�
//

// ��Setdlg.cpp �м���ʵ�ֹ��ܵĺ���
#include "stdafx.h"
#include "Robot.h"
#include "Setdlg.h"
//#include<stdlib.h>
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CSetdlg �Ի���

IMPLEMENT_DYNAMIC(CSetdlg, CDialog)

// CSetdlg dialog


CSetdlg::CSetdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}
CSetdlg::~CSetdlg()
{
}
void CSetdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	SetDlgItemInt(IDC_RAD,1);
	SetDlgItemInt(IDC_DIA,1);
	SetDlgItemInt(IDC_Speed,1);
}
BEGIN_MESSAGE_MAP(CSetdlg, CDialog)
	//{{AFX_MSG_MAP(CSetdlg)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_RAD, &CSetdlg::OnEnChangeRad)
END_MESSAGE_MAP()

// CSetdlg ��Ϣ�������
// CSetdlg message handlers

void CSetdlg::OnOK() 
{
	// TODO: Add extra validation here
  	sradio=GetDlgItemInt(IDC_RAD);
    sdistance=GetDlgItemInt(IDC_DIA);
	speed=GetDlgItemInt(IDC_Speed);
  UpdateWindow();
	CDialog::OnOK();	
}


void CSetdlg::OnEnChangeRad()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
