#pragma once


// CSetdlg 对话框
;
class CSetdlg : public CDialog
{
	DECLARE_DYNAMIC(CSetdlg)

public:
	CSetdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetdlg();
	void OnOK();
// 对话框数据
	enum { IDD = IDD_SETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeRad();
};
