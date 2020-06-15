// BorderDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BorderDemo.h"
#include "BorderDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoDlg dialog

CBorderDemoDlg::CBorderDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBorderDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBorderDemoDlg)
	m_first = 0;
	m_second = 0;
	m_result = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	consumer = false;
}

void CBorderDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBorderDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_first);
	DDX_Text(pDX, IDC_EDIT2, m_second);
	DDX_Text(pDX, IDC_EDIT3, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBorderDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CBorderDemoDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, OnMultiply)
	ON_BN_CLICKED(IDC_BUTTON3, OnSubtract)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoDlg message handlers

BOOL CBorderDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	if(consumer == true) {
		CWnd *pwnd;
		pwnd = GetDlgItem(IDC_EDIT1);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_EDIT2);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_EDIT3);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_BUTTON1);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_BUTTON2);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_BUTTON3);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_STATIC1);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_STATIC2);
		pwnd->ShowWindow(SW_HIDE);
		pwnd = GetDlgItem(IDC_STATIC3);
		pwnd->ShowWindow(SW_HIDE);

		// create components.
		disp = new FIFODispatch(100); //message queue of size 100
		s = new Scaffold(SCAFFOLD_TYPE_DISPATCH | SCAFFOLD_TYPE_SCHEDULER);
		sch = new RoundRobinScheduler(disp, 10);//10 threads
		s->setScheduler(sch);
		s->setDispatch(disp);
		arch = new ArchitectureAdapter("a");
		a = new CompA();
		a->setScaffold(s);
		bbc = new BottomBorderConnector("BBC", BORDER_DEMO_PORT);
		bbc->setScaffold(s);
		arch->add(bbc);
		arch->add(a);
		arch->weld(a,bbc);//t is on top of conn
		sch->start();
		arch->start();
	}
	else {
		CWnd *pwnd;
		pwnd = GetDlgItem(IDC_STATIC4);
		pwnd->SetWindowText(_T(""));

		// create components.
		disp = new FIFODispatch(100);//size of the message queue
		s = new Scaffold(SCAFFOLD_TYPE_DISPATCH | SCAFFOLD_TYPE_SCHEDULER);
		sch = new RoundRobinScheduler(disp, 10);//10 threads
		s->setScheduler(sch);
		s->setDispatch(disp);
		arch = new ArchitectureAdapter("a");
		b = new CompB();
		b->setScaffold(s);
		tbc = new TopBorderConnector("Connector");
		tbc->connect(BORDER_DEMO_HOST, BORDER_DEMO_PORT);
		tbc->setScaffold(s);
		arch->add(b);
		arch->add(tbc);
		arch->weld(tbc,b);//conn is on top of b
		sch->start();
		arch->start();
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBorderDemoDlg::DisplayInvalidResult()
{
	this->m_result = -1;
	this->UpdateData(FALSE);
}

void CBorderDemoDlg::Done()
{
	this->m_result = a->res;
	this->UpdateData(FALSE);
}


void CBorderDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	
}

void CBorderDemoDlg::OnMultiply() 
{
	// TODO: Add your control notification handler code here
	
}

void CBorderDemoDlg::OnSubtract() 
{
	// TODO: Add your control notification handler code here
	
}
