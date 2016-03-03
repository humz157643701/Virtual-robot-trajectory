// SpeedSet.cpp : 实现文件
//
// 在SpeedSet.cpp 中加入实现功能的函数
#include "stdafx.h"
#include "Robot.h"
#include "SpeedSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////



// CSpeedSet 对话框
IMPLEMENT_DYNAMIC(CSpeedSet, CDialog)
// CSpeedSet dialog
CSpeedSet::CSpeedSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSpeedSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpeedSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	angle=0;
}
CSpeedSet::~CSpeedSet()
{
}

void CSpeedSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeedSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	SetDlgItemInt(IDC_Speed,0);
}
BEGIN_MESSAGE_MAP(CSpeedSet, CDialog)
	//{{AFX_MSG_MAP(CSpeedSet)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_Speed, &CSpeedSet::OnEnChangeSpeed)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////



// CSpeedSet 消息处理程序
// CSpeedSet message handlers
void CSpeedSet::OnOK() 
{
	// TODO: Add extra validation here	
    angle=GetDlgItemInt(IDC_Speed);
    UpdateWindow();
	CDialog::OnOK();
}

void CSpeedSet::OnEnChangeSpeed()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
