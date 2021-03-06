
// WordsCountDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "WordsCount.h"
#include "WordsCountDlg.h"
#include "afxdialogex.h"
#include"resource.h"
#include"statistic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
string address = "D\\:1.txt";


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWordsCountDlg 对话框



CWordsCountDlg::CWordsCountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_WORDSCOUNT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordsCountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTONBROWSE, m_browse);
	DDX_Control(pDX, IDC_EDIT2, m_editchar);
	DDX_Control(pDX, IDC_EDIT1, m_word);
	DDX_Control(pDX, IDC_EDIT3, m_editline);
	DDX_Control(pDX, IDC_EDIT5, m_editblank);
	DDX_Control(pDX, IDC_EDIT4, m_editcode);
	DDX_Control(pDX, IDC_EDIT6, m_editecomm);
	DDX_Control(pDX, IDC_BUTTONBEGIN, m_begin);
	DDX_Control(pDX, IDC_EDITBROWSE, m_editbrowse);
}

BEGIN_MESSAGE_MAP(CWordsCountDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONBROWSE, &CWordsCountDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTONBEGIN, &CWordsCountDlg::OnBnClickedButtonbegin)
END_MESSAGE_MAP()


// CWordsCountDlg 消息处理程序

BOOL CWordsCountDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	
	m_editchar.SetWindowTextW(LPCTSTR("1"));
	m_word.SetWindowTextW(LPCTSTR("2"));
	m_editline.SetWindowTextW(LPCTSTR("3"));
	m_editblank.SetWindowTextW(LPCTSTR("4"));
	m_editcode.SetWindowTextW(LPCTSTR("5"));
	m_editecomm.SetWindowTextW(LPCTSTR("6"));

	



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWordsCountDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWordsCountDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWordsCountDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWordsCountDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFilter = _T("c*文件(*.c*)\0*.c*\0txt文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0");//要选择的文件后缀 
	ofn.lpstrInitialDir = _T("D:\\");//默认的文件路径 
	ofn.lpstrFile = szBuffer;//存放文件的缓冲区 
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileName(&ofn);
	m_editbrowse.SetWindowTextW(szBuffer);
	
	statistic sta;
	address = sta.transition(szBuffer);

	
}


void CWordsCountDlg::OnBnClickedButtonbegin()
{
	// TODO: 在此添加控件通知处理程序代码

	
	statistic ss(address);
	CString str;
	
	LPCTSTR pStr = LPCTSTR(str);
	ss.fileinit(address);
	
	str.Format(_T("%d"), ss.getcharater());
	pStr = LPCTSTR(str);
	m_editchar.SetWindowTextW(pStr);
	
	str.Format(_T("%d"), ss.getword());
	pStr = LPCTSTR(str);
	m_word.SetWindowTextW(pStr);

	str.Format(_T("%d"), ss.getlines());
	pStr = LPCTSTR(str);
	m_editline.SetWindowTextW(pStr);

	str.Format(_T("%d"), ss.getblank());
	pStr = LPCTSTR(str);
	m_editblank.SetWindowTextW(pStr);

	str.Format(_T("%d"), ss.getcode());
	pStr = LPCTSTR(str);
	m_editcode.SetWindowTextW(pStr);

	str.Format(_T("%d"), ss.getcomment());
	pStr = LPCTSTR(str);
	m_editecomm.SetWindowTextW(pStr);

}
