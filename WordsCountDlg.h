
// WordsCountDlg.h: 头文件
//

#pragma once
#include "afxwin.h"


// CWordsCountDlg 对话框
class CWordsCountDlg : public CDialog
{
// 构造
public:
	CWordsCountDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORDSCOUNT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_browse;
	afx_msg void OnBnClickedButton1();
	CEdit m_editchar;
	CEdit m_word;
	CEdit m_editline;
	CEdit m_editblank;
	CEdit m_editcode;
	CEdit m_editecomm;
	CButton m_begin;
	afx_msg void OnBnClickedButtonbegin();
	CEdit m_editbrowse;
};
