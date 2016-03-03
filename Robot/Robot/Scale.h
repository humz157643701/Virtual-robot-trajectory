#pragma once


// CScale 对话框

class CScale : public CDialog
{
	DECLARE_DYNAMIC(CScale)

public:
	CScale(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScale();
	void OnOK();
// 对话框数据
	enum { IDD = IDD_SETSCALE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeScale();
};
