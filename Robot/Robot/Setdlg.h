#pragma once


// CSetdlg �Ի���
;
class CSetdlg : public CDialog
{
	DECLARE_DYNAMIC(CSetdlg)

public:
	CSetdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetdlg();
	void OnOK();
// �Ի�������
	enum { IDD = IDD_SETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeRad();
};
