// SpeedSet.cpp : ʵ���ļ�
//
// ��SpeedSet.cpp �м���ʵ�ֹ��ܵĺ���
#include "stdafx.h"
#include "Robot.h"
#include "SpeedSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////



// CSpeedSet �Ի���
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



// CSpeedSet ��Ϣ�������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
