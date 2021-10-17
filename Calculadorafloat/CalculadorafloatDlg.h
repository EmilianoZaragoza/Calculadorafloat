
// CalculadorafloatDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CCalculadorafloatDlg
class CCalculadorafloatDlg : public CDialogEx
{
// Construcción
public:
	CCalculadorafloatDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULADORAFLOAT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_resultado;
	float m_resulado_flotante;
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedMasButton();
	afx_msg void OnBnClickedMenosButton();
	afx_msg void OnBnClickedPorButton();
	afx_msg void OnBnClickedEntreButton();
//	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedCeButton();
	CString m_BIN;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedBinCheck();
	afx_msg void OnBnClickedButton1();
};
