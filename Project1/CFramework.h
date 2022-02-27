#pragma once

//
//class CFramework
//{
//private:
//	static CFramework* g_pInst;
//
//public:
//	static CFramework* GetInstance()
//	{		
//		if (g_pInst == nullptr) 
//		{
//			g_pInst = new CFramework;
//		}
//
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (g_pInst != nullptr)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//	}
//
//private:
//	CFramework();
//	~CFramework();
//};

class CFramework
{
	SINGLE(CFramework);

private:
	HWND  m_hWnd;                         //  ���� ������ �ڵ�
	POINT  m_ptResolution;			  // ���� ������ �ػ�
	HDC m_hDC;								  // ���� �����쿡 Draw �� DC

	HBITMAP m_hBit;
	HDC m_memDC;

private:
	// ���� ����ϴ� GDI Object
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];


public:
	int Init(HWND _hwnd, POINT _ptResolution);
	void Progress();

private:
	void Update();
	void Render();

private:
	void CreateGDIObject();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
};