
// CalculadorafloatDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Calculadorafloat.h"
#include "CalculadorafloatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CCalculadorafloatDlg



CCalculadorafloatDlg::CCalculadorafloatDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CALCULADORAFLOAT_DIALOG, pParent)
	, m_resultado(_T(""))
	, m_resulado_flotante(0)
	, m_BIN(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadorafloatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_resultado);
	DDX_Text(pDX, IDC_RESULT_STATIC, m_resulado_flotante);
	DDX_Text(pDX, IDC_Bin_STATIC, m_BIN);
}

BEGIN_MESSAGE_MAP(CCalculadorafloatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CCalculadorafloatDlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CCalculadorafloatDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CCalculadorafloatDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CCalculadorafloatDlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CCalculadorafloatDlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CCalculadorafloatDlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CCalculadorafloatDlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CCalculadorafloatDlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CCalculadorafloatDlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CCalculadorafloatDlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_MAS_BUTTON, &CCalculadorafloatDlg::OnBnClickedMasButton)
	ON_BN_CLICKED(IDC_MENOS_BUTTON, &CCalculadorafloatDlg::OnBnClickedMenosButton)
	ON_BN_CLICKED(IDC_POR_BUTTON, &CCalculadorafloatDlg::OnBnClickedPorButton)
	ON_BN_CLICKED(IDC_ENTRE_BUTTON, &CCalculadorafloatDlg::OnBnClickedEntreButton)
//	ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CCalculadorafloatDlg::OnBnClickedIgualButton)
ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CCalculadorafloatDlg::OnBnClickedIgualButton)
ON_BN_CLICKED(IDC_CE_BUTTON, &CCalculadorafloatDlg::OnBnClickedCeButton)
//ON_BN_CLICKED(IDC_CHECK1, &CCalculadorafloatDlg::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_BIN_CHECK, &CCalculadorafloatDlg::OnBnClickedBinCheck)
ON_BN_CLICKED(IDC_BUTTON1, &CCalculadorafloatDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Controladores de mensajes de CCalculadorafloatDlg

BOOL CCalculadorafloatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCalculadorafloatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCalculadorafloatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCalculadorafloatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

float conteo;
float op1;
float op2;
float op1add;
float op2add;
float resultadoadd;
int codigo_de_operacion;

void CCalculadorafloatDlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "0";
		m_resulado_flotante = 0;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked1Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "1";
		m_resulado_flotante = 1;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 1;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado= MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked2Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "2";
		m_resulado_flotante = 2;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 2;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked3Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "3";
		m_resulado_flotante = 3;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 3;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked4Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "4";
		m_resulado_flotante = 4;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 4;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked5Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "5";
		m_resulado_flotante = 5;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 5;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked6Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "6";
		m_resulado_flotante = 6;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 6;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked7Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "7";
		m_resulado_flotante = 7;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 7;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked8Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "8";
		m_resulado_flotante = 8;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 8;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClicked9Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "9";
		m_resulado_flotante = 9;
		op1 = m_resulado_flotante;
	}
	else {
		op2 = m_resulado_flotante * 10;
		op1 = op2 + 9;
		m_resulado_flotante = op1;
		CString MyCadena;
		MyCadena.Format(L"%.2f", op1);
		m_resultado = MyCadena;

	}

	conteo++;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClickedMasButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 1;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resulado_flotante;

	conteo = 0;

	op1 = 0;
	op2 = 0;


	CString MyCadenita;
	MyCadenita.Format(L"%.2f+",resultadoadd);
	m_resultado = MyCadenita; 
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClickedMenosButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 2;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resulado_flotante;

	conteo = 0;

	CString MyCadenita;
	MyCadenita.Format(L"%.2f-", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClickedPorButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 3;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resulado_flotante;

	conteo = 0;

	CString MyCadenita;
	MyCadenita.Format(L"%.2f x", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClickedEntreButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 4;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resulado_flotante;

	conteo = 0;

	CString MyCadenita;
	MyCadenita.Format(L"%.2f /", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}

void CCalculadorafloatDlg::OnBnClickedIgualButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	switch (codigo_de_operacion)
	{
	case 1:
		m_resulado_flotante = resultadoadd + op1;
		break;
	case 2:
		m_resulado_flotante = resultadoadd - op1;
		break;
	case 3:
		m_resulado_flotante = resultadoadd * op1;
		break;
	case 4:
		m_resulado_flotante = resultadoadd / op1;
		break;
	default:
		break;
	}
	CString MyCadenita;
	MyCadenita.Format(L"%.2f ", m_resulado_flotante);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}


void CCalculadorafloatDlg::OnBnClickedCeButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resulado_flotante = 0;
	resultadoadd = 0;

	CString MyCadenita;

	MyCadenita.Format(L"%.2f", m_resulado_flotante);
	m_resultado = MyCadenita;
	UpdateData(FALSE);

}

int m_Bin_entero;

void CCalculadorafloatDlg::OnBnClickedBinCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	int a[10], n, i;
	/// "actualizamos el numero a convertir ";
	UpdateData(TRUE);
	n =m_resulado_flotante;
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	//limpiar cadena y generar ciclo para presentar dato convertido";
	m_BIN = "";
	UpdateData(FALSE);
	for (i = i - 1; i >= 0; i--)
	{
		m_Bin_entero = a[i];
		CString Cadena;
		Cadena.Format(L"%d", m_Bin_entero);
		m_BIN += Cadena;
	}
	UpdateData(FALSE);
}

void CCalculadorafloatDlg::OnBnClickedButton1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	CString MyCadenita;
	MyCadenita.Format(L" % x", 0);
	m_BIN = MyCadenita;
	UpdateData(FALSE);
}
