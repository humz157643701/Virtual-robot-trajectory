#pragma once


// CSpeedSet �Ի���
;
class CSpeedSet : public CDialog
{
	DECLARE_DYNAMIC(CSpeedSet)

public:
	CSpeedSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSpeedSet();
	void OnOK();

// �Ի�������
	enum { IDD = IDD_SPEEDSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeSpeed();
};
