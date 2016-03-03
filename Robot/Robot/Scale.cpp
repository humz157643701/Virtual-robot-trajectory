// Scale.cpp : 实现文件
//

#include "stdafx.h"
#include "Robot.h"
#include "Scale.h"
#include "afxdialogex.h"


// CScale 对话框

IMPLEMENT_DYNAMIC(CScale, CDialog)

CScale::CScale(CWnd* pParent /*=NULL*/)
	: CDialog(CScale::IDD, pParent)
{	

}

CScale::~CScale()
{
}

void CScale::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetDlgItemInt(IDC_Scale,1);
}


BEGIN_MESSAGE_MAP(CScale, CDialog)

	ON_EN_CHANGE(IDC_Scale, &CScale::OnEnChangeScale)
END_MESSAGE_MAP()


// CScale 消息处理程序

void CScale::OnOK() 
{
	// TODO: Add extra validation here	
    scale=GetDlgItemInt(IDC_Scale);
    UpdateWindow();
	CDialog::OnOK();

}

void CScale::OnEnChangeScale()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
