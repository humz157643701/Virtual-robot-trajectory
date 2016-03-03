
// Robot.h : Robot 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CRobotApp:
// 有关此类的实现，请参阅 Robot.cpp
//

class CRobotApp : public CWinAppEx
{
public:
	CRobotApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRobotApp theApp;

class point
{
public:
	float x,y,z,xr,yr,zr;
};
class OBJECT
{
public:
	int verts;
	point points[100];
};
