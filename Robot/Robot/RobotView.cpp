
// RobotView.cpp : CRobotView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Robot.h"
#endif

#include "RobotDoc.h"
#include "RobotView.h"
#include "Setdlg.h"
#include "SpeedSet.h"
#include "qiu.h"
#include "Scale.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CRobotView

IMPLEMENT_DYNCREATE(CRobotView, CView)

	BEGIN_MESSAGE_MAP(CRobotView, CView)
		//{{AFX_MSG_MAP(CRobotView)
		ON_WM_CREATE()
		ON_WM_DESTROY()
		ON_WM_SIZE()
		ON_WM_ERASEBKGND()
		ON_COMMAND(IDM_OPEN, OnOpen)
		ON_COMMAND(IDM_SGUN, OnSgun)
		ON_COMMAND(IDM_START, OnStart)
		ON_COMMAND(IDM_STOP, OnStop)
		ON_WM_TIMER()
		ON_WM_LBUTTONDOWN()
		ON_WM_MOUSEMOVE()
		ON_COMMAND(IDM_SPEED, OnSpeed)
		//}}AFX_MSG_MAP
		// Standard printing commands
		ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
		ON_COMMAND(IDM_Scale, &CRobotView::OnScale)
	END_MESSAGE_MAP()

	/////////////////////////////////////////////////////////////////////////////
	// CRobotView construction/destruction

	CRobotView::CRobotView()
	{
		// TODO: add construction code here
		my_pDC=NULL;
		m_fX1=0;
		m_fY1=0;
		xRange=90;
		yRange=0;
		//	 x=y=z=0;
		//	xrot=yrot=zrot=0;
		j=0;
	}

	CRobotView::~CRobotView()
	{
	}

	BOOL CRobotView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: Modify the Window class or styles here by modifying
		//  the CREATESTRUCT cs
		cs.style|=WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		return CView::PreCreateWindow(cs);
	}

	// CRobotView 绘制

	void CRobotView::OnDraw(CDC* pDC)
	{
		CRobotDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		// TODO: add draw code for native data here
		static BOOL bBusy = FALSE;
		if(bBusy) return;
		bBusy = TRUE;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();	
		//	gluLookAt (0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0); 
		mydraw();   
		glFinish();		
		SwapBuffers(wglGetCurrentDC());
		bBusy = FALSE;
	}

	/////////////////////////////////////////////////////////////////////////////
	// CRobotView printing

	void CRobotView::OnFilePrintPreview()
	{
#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
#endif
	}

	BOOL CRobotView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// default preparation
		return DoPreparePrinting(pInfo);
	}

	void CRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: add extra initialization before printing
	}

	void CRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: add cleanup after printing
	}

	/////////////////////////////////////////////////////////////////////////////
	// CRobotView diagnostics

#ifdef _DEBUG
	void CRobotView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CRobotView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CRobotDoc* CRobotView::GetDocument() const// non-debug version is inline
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotDoc)));
		return (CRobotDoc*)m_pDocument;
	}
#endif //_DEBUG

	/////////////////////////////////////////////////////////////////////////////
	// CRobotView message handlers			
	void CRobotView::OnOpen()
	{
		// TODO: 在此添加命令处理程序代码
		KillTimer(1);
		j=0;
		CFileDialog FileDlg(true, _T("txt"),NULL,OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,"(*.TXT)|*.TXT|All Files(*.*)|*.*||"); 
		if( FileDlg.DoModal() == IDOK ) 
		{    
			CString fileName;    
			fileName = FileDlg.GetFileName();
			CStdioFile file; 
			float	rx,ry,rz,rxrot,ryrot,rzrot;	
			file.Open(fileName,CFile::modeRead,0);  
			CString str;
			int i=0;
			while(file.ReadString(str))
			{
				sscanf( (LPCTSTR)str,"%f %f %f %f %f %f", &pt[i].x, &pt[i].y, &pt[i].z,&pt[i].xr, &pt[i].yr, &pt[i].zr);
				i++;
				cnt=i;
			}
		}
	}

	void CRobotView::mydraw()
	{
		glTranslatef(0.0f,0.0f,-100.0f);
		/*		
		lm();
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LINE_STIPPLE);
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		*/		 
		glRotatef(yRange,0,1,0);   
		glRotatef(xRange,1,0,0); 
		//	glRotatef(45,0,0,1); 
		glPushMatrix();
		//  glRotatef(100,1.0f,0.0f,0.0f); 	
		glRotatef(angle,0,0,1);
		glPointSize(3.0f);
		glLineWidth(1.0);
		glBegin(GL_LINE_STRIP);	
		for(int i=0;i<j;i++)			
		{	
			tx=pt[i].x*scale;					
			ty=pt[i].y*scale;					
			tz=pt[i].z*scale;					
			glColor3f(0,0,1.0);							
			glVertex3f(tx,ty,tz);
		}
		glEnd();
		glBegin(GL_POINTS);	
		for(int i=0;i<j;i++)			
		{	
			tx=pt[i].x*scale;					
			ty=pt[i].y*scale;					
			tz=pt[i].z*scale;					
			glColor3f(1.0,0,0);							
			glVertex3f(tx,ty,tz);
		}
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x*scale,0,0);
		glTranslatef(0,y*scale,0);
		glTranslatef(0,0,z*scale);
		glTranslatef(0,sdistance,0);
		glScalef(0.3f,0.3f,0.3f);
		glRotatef(zrot,0.0f,0.0f,1.0f);
		glRotatef(xrot,1.0f,0.0f,0.0f);					
		glRotatef(yrot,0.0f,1.0f,0.0f);						
		// glTranslatef(morph1.points[0].x,morph1.points[0].y,morph1.points[0].z);
		glColor3f(0.4f,0.4f,0.3f);
		gluCylinder(quadratic,sradio/2,sradio,15.0f,32,32);
		glPopMatrix();
		/*
		glDisable(GL_LIGHTING);
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_POINT_SMOOTH);
		glDisable(GL_LINE_STIPPLE);
		*/
		//	moxing();
		RedrawWindow();
	}

	BOOL CRobotView::mypixelformat()
	{
		static PIXELFORMATDESCRIPTOR pfd = 
		{
			sizeof(PIXELFORMATDESCRIPTOR), 
			1,                             
			PFD_DRAW_TO_WINDOW |           
			PFD_SUPPORT_OPENGL|			
			PFD_DOUBLEBUFFER,            
			PFD_TYPE_RGBA,              
			24,                         
			0, 0, 0, 0, 0, 0,           
			0,                          
			0,                          
			0,                          
			0, 0, 0, 0,                 
			32,                         
			0,                          
			0,                          
			PFD_MAIN_PLANE,             
			0,                          
			0, 0, 0                     
		};
		int pixelformat;
		if ( (pixelformat = ChoosePixelFormat(my_pDC->GetSafeHdc(), &pfd)) == 0 )
		{
			MessageBox("ChoosePixelFormat failed");
			return FALSE;
		}
		if (SetPixelFormat(my_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
		{
			MessageBox("SetPixelFormat failed");
			return FALSE;
		}
		return TRUE;
	}

	void CRobotView::init()
	{
		PIXELFORMATDESCRIPTOR pfd;
		int n;
		HGLRC hrc;
		my_pDC = new CClientDC(this);
		ASSERT(my_pDC != NULL);
		if (!mypixelformat())
			return;
		n =::GetPixelFormat(my_pDC->GetSafeHdc());
		::DescribePixelFormat(my_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);
		hrc = wglCreateContext(my_pDC->GetSafeHdc());
		wglMakeCurrent(my_pDC->GetSafeHdc(), hrc);
		GetClientRect(&my_oldRect);
		quadratic=gluNewQuadric();				
		gluQuadricNormals(quadratic, GLU_SMOOTH);
		glShadeModel(GL_SMOOTH);						
		glClearColor(0.8f, 0.8f, 0.8f, 0.5f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);								
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	}

	int CRobotView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;	
		// TODO: Add your specialized creation code here
		init();
		return 0;
	}

	void CRobotView::OnDestroy() 
	{
		CView::OnDestroy();	
		// TODO: Add your message handler code here
		KillTimer(1);
		gluDeleteQuadric(quadratic);
		HGLRC	hrc;
		hrc = ::wglGetCurrentContext();
		::wglMakeCurrent(NULL,  NULL);
		if (hrc)
			::wglDeleteContext(hrc);
		if (my_pDC)
			delete my_pDC;	
		//objfree(&morph1);
	}

	void CRobotView::OnSize(UINT nType, int cx, int cy) 
	{
		CView::OnSize(nType, cx, cy);	
		// TODO: Add your message handler code here
		if(cy > 0)
		{
			my_oldRect.right = cx;
			my_oldRect.bottom = cy;
			glViewport(0,0,cx,cy);						
			glMatrixMode(GL_PROJECTION);					
			glLoadIdentity();										                                                         
			gluPerspective(45.0f,cx/cy,0.1f,100.0f);
			glMatrixMode(GL_MODELVIEW);						
			glLoadIdentity();		
		}
	}

	BOOL CRobotView::OnEraseBkgnd(CDC* pDC) 
	{
		// TODO: Add your message handler code here and/or call default
		return TRUE;
	}

	void CRobotView::OnStart() 
	{	
		SetTimer(1,500.0/speed, NULL);
		Invalidate(TRUE);	
	}
	void CRobotView::OnStop() 
	{
		KillTimer(1);
	}
	void CRobotView::OnTimer(UINT nIDEvent) 
	{
		x=pt[j].x;					 
		y=pt[j].y;					
		z=pt[j].z;
		xrot=pt[j].xr;
		yrot=pt[j].yr;
		zrot=pt[j].zr;
		if(nIDEvent==1)
		{

			if(j<cnt)
			{
				j=j+1;
			}
			else
			{
				x=y=z=0;
			};		
		};
		Invalidate(FALSE);
		CView::OnTimer(nIDEvent);
	}
	void CRobotView::lm()
	{
		GLfloat		lAmb[4];
		GLfloat		lDif[4];
		GLfloat		lSpe[4];
		GLfloat		lPos[4];
		GLfloat		mAmb[4];
		GLfloat		mDif[4];
		GLfloat		mSpe[4];
		GLfloat		mEmi[4];
		GLfloat		mShininess;
		lAmb[0]=0.2f;	lAmb[1]=0.2f;
		lAmb[2]=0.2f;	lAmb[3]=0.1f;
		lDif[0]=0.2f;	lDif[1]=0.2f;
		lDif[2]=0.1f;	lDif[3]=0.1f;
		lSpe[0]=0.5f;	lSpe[1]=0.5f;
		lSpe[2]=0.7f;	lSpe[3]=0.8f;
		lPos[0]=1.0f;	lPos[1]=1.0f;
		lPos[2]=2.0f;	lPos[3]=0.0f;
		mAmb[0]=0.0f;	mAmb[1]=0.0f;
		mAmb[2]=0.3f;	mAmb[3]=0.3f;	 
		mDif[0]=0.0f;	mDif[1]=0.0f;
		mDif[2]=0.0f;	mDif[3]=1.0f;
		mSpe[0]=0.1f;	mSpe[1]=0.1f;
		mSpe[2]=0.8f;	mSpe[3]=0.8f;	
		mEmi[0]=0.5f;	mEmi[1]=0.5f;
		mEmi[2]=0.5f;	mEmi[3]=0.2f;
		mShininess=20.0f;	
		glLightfv(GL_LIGHT1,GL_AMBIENT,lAmb);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,lDif);
		glLightfv(GL_LIGHT1,GL_SPECULAR,lSpe);
		glLightfv(GL_LIGHT1,GL_POSITION,lPos);

		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mAmb);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mDif);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mSpe);
		glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,mEmi);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,mShininess);
	}

	void CRobotView::OnLButtonDown(UINT nFlags, CPoint point) 
	{
		// TODO: Add your message handler code here and/or call default
		m_fX1=(float)point.x;   
		m_fY1=(float)point.y; 
		CView::OnLButtonDown(nFlags, point);
	}

	void CRobotView::OnMouseMove(UINT nFlags, CPoint point) 
	{
		// TODO: Add your message handler code here and/or call default
		const   float   PI=3.14159f;                         
		if(nFlags==MK_LBUTTON)   
		{   
			xRange+=PI*(point.y-m_fY1)/my_oldRect.right;     
			yRange+=PI*(point.x-m_fX1)/my_oldRect.bottom;   
			CView::OnMouseMove(nFlags, point);
		};
	}

	void CRobotView::OnSpeed() 
	{
		// TODO: Add your command handler code here
		CSpeedSet set;
		set.DoModal();
	}

	void CRobotView::OnSgun() 
	{
		CSetdlg dlg;
		dlg.DoModal();
	}

	void CRobotView::OnScale()
	{
		// TODO: 在此添加命令处理程序代码
		CScale dlg;
		dlg.DoModal();
	}
