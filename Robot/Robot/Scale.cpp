// Scale.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Robot.h"
#include "Scale.h"
#include "afxdialogex.h"


// CScale �Ի���

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


// CScale ��Ϣ�������

void CScale::OnOK() 
{
	// TODO: Add extra validation here	
    scale=GetDlgItemInt(IDC_Scale);
    UpdateWindow();
	CDialog::OnOK();

}

void CScale::OnEnChangeScale()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
