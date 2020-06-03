// StaticDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StaticDemo.h"
#include "StaticDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticDemoDlg dialog

CStaticDemoDlg::CStaticDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaticDemoDlg)
	m_first = 0;
	m_result = 0;
	m_second = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaticDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaticDemoDlg)
	DDX_Text(pDX, IDC_EDIT_FIRST, m_first);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Text(pDX, IDC_EDIT_SECOND, m_second);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStaticDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CStaticDemoDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SUB, OnSub)
	ON_BN_CLICKED(IDC_MUL, OnMul)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticDemoDlg message handlers

BOOL CStaticDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	disp = new FIFODispatch(100);
	s = new Scaffold(SCAFFOLD_TYPE_DISPATCH	| SCAFFOLD_TYPE_SCHEDULER);
	sch = new RoundRobinScheduler(disp, 10);
	s->setScheduler(sch);
	s->setDispatch(disp);
	arch = new ArchitectureAdapter("a");
	a = new CompA();
	a->setScaffold(s);
	a->dlg = this;
	b=new CompB();
	b->setScaffold(s);
	c=new Connector("c");
	c->setScaffold(s);
	arch->add(a);
	arch->add(b);
	arch->add(c);
	arch->weld(b,c);
	arch->weld(c,a);
	sch->start();
	arch->start();
//	a->res=5;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStaticDemoDlg::DisplayInvalidResult()
{
	this->m_result = -1;
//	this->RedrawWindow();
	this->UpdateData(FALSE);
}

void CStaticDemoDlg::Done()
{
	this->m_result = a->res;
//	this->RedrawWindow();
	this->UpdateData(FALSE);
}

void CStaticDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	a->left=this->m_first;
	a->right=this->m_second;
	a->add();	
}

void CStaticDemoDlg::OnSub() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	a->left=this->m_first;
	a->right=this->m_second;
	a->sub();	
}

void CStaticDemoDlg::OnMul() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	a->left=this->m_first;
	a->right=this->m_second;
	a->mul();	
}
