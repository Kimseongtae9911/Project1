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

public:
	int Init(HWND _hwnd, POINT _ptResolution);
	void Progress();

private:
	void Update();
	void Render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	
};