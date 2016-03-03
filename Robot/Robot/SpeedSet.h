#pragma once


// CSpeedSet 对话框
;
class CSpeedSet : public CDialog
{
	DECLARE_DYNAMIC(CSpeedSet)

public:
	CSpeedSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSpeedSet();
	void OnOK();

// 对话框数据
	enum { IDD = IDD_SPEEDSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeSpeed();
};
