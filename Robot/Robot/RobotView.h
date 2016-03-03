#include<gl/gl.h> 
#include<gl/glu.h>
#include<gl/glaux.h>
#include<gl/glut.h>

// RobotView.h : CRobotView ��Ľӿ�
//

#pragma once


class CRobotView : public CView
{
protected: // �������л�����
	CRobotView();
	DECLARE_DYNCREATE(CRobotView)

// ����
public:
	CRobotDoc* GetDocument() const;
	void mydraw();
	BOOL mypixelformat();
	void init();
	int OnCreate(LPCREATESTRUCT);
	void OnDestroy();
	void OnSize(UINT,int,int);
	BOOL OnEraseBkgnd(CDC *);
	void objallocate(OBJECT *k,int n);
	void objfree(OBJECT *k);
	void readstr(char *string);
	void objload(char *name);
	void OnTimer(UINT);
	void lm();
	void OnLButtonDown(UINT,CPoint);
	void OnMouseMove(UINT,CPoint);
	point pt[1000];
	int max;
	int cnt;
	void moxing();
	GLuint listnum;	
	CDC *my_pDC;
	CRect my_oldRect;
    OBJECT morph1;
    GLUquadricObj *quadratic;	
    float mx1;
    float my1;
    CStdioFile fil;
    CString name;
    float  m_fX1;
    float  m_fY1;
    float xRange;
    float yRange;
    float x;
    float y;
    float z;
    int j;
    float xrot;
    float yrot;
    float zrot;
	GLfloat tx,ty,tz;
	//int m;
	
	// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnSgun();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnSpeed();
	afx_msg void OnScale();
};

#ifndef _DEBUG  // RobotView.cpp �еĵ��԰汾
inline CRobotDoc* CRobotView::GetDocument() const
   { return reinterpret_cast<CRobotDoc*>(m_pDocument); }
#endif
