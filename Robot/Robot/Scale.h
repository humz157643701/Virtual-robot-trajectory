#pragma once


// CScale �Ի���

class CScale : public CDialog
{
	DECLARE_DYNAMIC(CScale)

public:
	CScale(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScale();
	void OnOK();
// �Ի�������
	enum { IDD = IDD_SETSCALE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeScale();
};
