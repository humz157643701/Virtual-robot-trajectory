
// Robot.h : Robot Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CRobotApp:
// �йش����ʵ�֣������ Robot.cpp
//

class CRobotApp : public CWinAppEx
{
public:
	CRobotApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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
