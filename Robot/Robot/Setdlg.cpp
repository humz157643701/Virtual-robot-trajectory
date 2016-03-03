// Setdlg.cpp : 实现文件
//

// 在Setdlg.cpp 中加入实现功能的函数
#include "stdafx.h"
#include "Robot.h"
#include "Setdlg.h"
//#include<stdlib.h>
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CSetdlg 对话框

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

// CSetdlg 消息处理程序
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
