
// 计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "计算器.h"
#include "计算器Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C计算器Dlg 对话框



C计算器Dlg::C计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C计算器Dlg::IDD, pParent)
	, m_display(_T(""))
{
	m_first=0.0;
	m_second=0.0;
	m_operator=_T("+");
	m_coff=1.0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
}

BEGIN_MESSAGE_MAP(C计算器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &C计算器Dlg::OnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &C计算器Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C计算器Dlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C计算器Dlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C计算器Dlg::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C计算器Dlg::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C计算器Dlg::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C计算器Dlg::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C计算器Dlg::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &C计算器Dlg::OnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &C计算器Dlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &C计算器Dlg::OnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &C计算器Dlg::OnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &C计算器Dlg::OnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &C计算器Dlg::OnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLY, &C计算器Dlg::OnClickedButtonMutiply)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &C计算器Dlg::OnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_RECIPROCAL, &C计算器Dlg::OnClickedButtonReciprocal)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &C计算器Dlg::OnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &C计算器Dlg::OnClickedButtonSqrt)
END_MESSAGE_MAP()


// C计算器Dlg 消息处理程序

BOOL C计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C计算器Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C计算器Dlg::OnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+0;
	else
	{
		m_second=m_second+0*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+1;
	else
	{
		m_second=m_second+1*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+2;
	else
	{
		m_second=m_second+2*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+3;
	else
	{
		m_second=m_second+3*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+4;
	else
	{
		m_second=m_second+4*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+5;
	else
	{
		m_second=m_second+5*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+6;
	else
	{
		m_second=m_second+6*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+7;
	else
	{
		m_second=m_second+7*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+8;
	else
	{
		m_second=m_second+8*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_coff==1.0)m_second=m_second*10+9;
	else
	{
		m_second=m_second+9*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator="+";
}


void C计算器Dlg::OnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_first=0;
	m_second=0;
	m_operator="+";
	m_coff=1;
	UpdateDisplay(0.0);
}


void C计算器Dlg::OnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator="/";
}


void C计算器Dlg::OnClickedButtonEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_first=0;
	m_operator="+";
}


void C计算器Dlg::OnClickedButtonMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator="-";
}


void C计算器Dlg::OnClickedButtonMutiply()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculate();
	m_operator="*";
}


void C计算器Dlg::OnClickedButtonPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	m_coff=0.1;
}


void C计算器Dlg::OnClickedButtonReciprocal()
{
	// TODO: 在此添加控件通知处理程序代码
	if(fabs(m_second)<=0.000001)
	{
		m_display="除数不能为0";
		UpdateData(false);
		return;
	}
	m_second=1/m_second;
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButtonSign()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second=-m_second;
	UpdateDisplay(m_second);
}


void C计算器Dlg::OnClickedButtonSqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second=sqrt(m_second);
	UpdateDisplay(m_second);
}


void C计算器Dlg::UpdateDisplay(double IVal)
{
	m_display.Format(_T("%f"),IVal);
	int i=m_display.GetLength();
	while(m_display.GetAt(i-1)=='0')
	{
		m_display.Delete(i-1,1);
		i--;
	}
	UpdateData(false);
}


void C计算器Dlg::Calculate(void)
{
	switch(m_operator.GetAt(0))
	{
	case '+':m_first+=m_second;break;
	case '-':m_first-=m_second;break;
	case '*':m_first*=m_second;break;
	case '/':if(fabs(m_second)<=0.000001)
			 {
				 m_display="除数不能为0";
				 UpdateData(false);
				 return;
			 }
			 m_first/=m_second;break;
	}
	m_second=0;
	m_coff=1;
	UpdateDisplay(m_first);
}
