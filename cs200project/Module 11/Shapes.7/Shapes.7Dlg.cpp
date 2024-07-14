
// Shapes.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"

#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "pShapes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CShapes7Dlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT1, &CShapes7Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CShapes7Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CShapes7Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDCANCEL, &CShapes7Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CShapes7Dlg::OnBnClickedOk)
	ON_STN_CLICKED(IDIGNORE, &CShapes7Dlg::OnStnClickedIgnore)
	ON_EN_CHANGE(IDC_EDIT5, &CShapes7Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// combo box
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Rectangle"));
	pCombo->InsertString(2, _T("Circle"));
	pCombo->InsertString(3, _T("Triangle"));
	pCombo->InsertString(4, _T("Cube"));
	pCombo->InsertString(5, _T("Box"));
	pCombo->InsertString(6, _T("Cylinder"));
	pCombo->InsertString(7, _T("Prism"));
	pCombo->SetCurSel(-1); // or -1 for unselected

		// Picture control setup
		CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC8));
		pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapes7Dlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int n = pCombo->GetCurSel();
	CEdit* pStatic3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CStatic* pStatic4 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_EDIT6));
	CStatic* pStatic5 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_EDIT7));
	

	switch (n)
	{
	  case 0:// Square
		  pStatic3->SetWindowText(CString(_T("Side")));
		  pStatic4->SetWindowText(CString(_T(" ")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 1:// Rectangle
		  pStatic3->SetWindowText(CString(_T("Length")));
		  pStatic4->SetWindowText(CString(_T("Width")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 2:// circle
		  pStatic3->SetWindowText(CString(_T("Radius")));
		  pStatic4->SetWindowText(CString(_T(" ")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 3:// Triangle
		  pStatic3->SetWindowText(CString(_T("side")));
		  pStatic4->SetWindowText(CString(_T(" ")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 4:// Cube
		  pStatic3->SetWindowText(CString(_T("Side")));
		  pStatic4->SetWindowText(CString(_T(" ")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 5:// Box
		  pStatic3->SetWindowText(CString(_T("Length")));
		  pStatic4->SetWindowText(CString(_T("Width")));
		  pStatic5->SetWindowText(CString(_T("Height")));
		  break;

	  case 6:// Cylinder
		  pStatic3->SetWindowText(CString(_T("Radius")));
		  pStatic4->SetWindowText(CString(_T("Height")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;

	  case 7:// Prism
		  pStatic3->SetWindowText(CString(_T("Side")));
		  pStatic4->SetWindowText(CString(_T("Height")));
		  pStatic5->SetWindowText(CString(_T(" ")));
		  break;
	}
}


void CShapes7Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CShapes7Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	vector<string> tokens;

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int n = pCombo->GetCurSel();
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	ostringstream sout;

	switch (n)
	{
	case 0: //Square
	{
		CString token;
		tokens.push_back("Square");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString(token);
		std::string temp(pszConvertedAnsiString);
		tokens.push_back(temp);
		Square square(tokens);
		square.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 1: //Rectangle
	{
		CString token;
		tokens.push_back("Rectangle");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString1(token);
		std::string temp1(pszConvertedAnsiString1);
		tokens.push_back(temp1);
		pEdit2->GetWindowText(token);
		CT2CA pszConvertedAnsiString2(token);
		std::string temp2(pszConvertedAnsiString2);
		tokens.push_back(temp2);
		comsc::Rectangle rectangle(tokens);
		rectangle.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 2: //Circle
	{
		CString token;
		tokens.push_back("Circle");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString(token);
		std::string temp(pszConvertedAnsiString);
		tokens.push_back(temp);
		Circle circle(tokens);
		circle.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 3: //Triangle
	{
		CString token;
		tokens.push_back("Triangle");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString(token);
		std::string temp(pszConvertedAnsiString);
		tokens.push_back(temp);
		Triangle triangle(tokens);
		triangle.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 4: //Cube
	{
		CString token;
		tokens.push_back("Cube");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString(token);
		std::string temp(pszConvertedAnsiString);
		tokens.push_back(temp);
		Cube cube(tokens);
		cube.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 5: //Box
	{
		CString token;
		tokens.push_back("Box");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString1(token);
		std::string temp1(pszConvertedAnsiString1);
		tokens.push_back(temp1);
		pEdit2->GetWindowText(token);
		CT2CA pszConvertedAnsiString2(token);
		std::string temp2(pszConvertedAnsiString2);
		tokens.push_back(temp2);
		pEdit3->GetWindowText(token);
		CT2CA pszConvertedAnsiString3(token);
		std::string temp3(pszConvertedAnsiString3);
		tokens.push_back(temp3);
		Box box(tokens);
		box.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 6: //Cylinder
	{
		CString token;
		tokens.push_back("Cylinder");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString1(token);
		std::string temp1(pszConvertedAnsiString1);
		tokens.push_back(temp1);
		pEdit2->GetWindowText(token);
		CT2CA pszConvertedAnsiString2(token);
		std::string temp2(pszConvertedAnsiString2);
		tokens.push_back(temp2);
		Cylinder cylinder(tokens);
		cylinder.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}

	case 7: //Prism
	{
		CString token;
		tokens.push_back("Prism");
		pEdit1->GetWindowText(token);
		CT2CA pszConvertedAnsiString1(token);
		std::string temp1(pszConvertedAnsiString1);
		tokens.push_back(temp1);
		pEdit2->GetWindowText(token);
		CT2CA pszConvertedAnsiString2(token);
		std::string temp2(pszConvertedAnsiString2);
		tokens.push_back(temp2);
		Prism prism(tokens);
		prism.output(sout);
		pEdit4->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	}

}


void CShapes7Dlg::OnStnClickedIgnore()
{
	// TODO: Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
