#pragma once

//
//class CCore
//{
//private:
//	static CCore* g_pInst;
//
//public:
//	static CCore* GetInstance()
//	{		
//		if (g_pInst == nullptr) 
//		{
//			g_pInst = new CCore;
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
//	CCore();
//	~CCore();
//};

class CCore
{
	SINGLE(CCore);

private:
	HWND  m_hWnd;                         //  메인 윈도우 핸들
	POINT  m_ptResolution;			  // 메인 윈도우 해상도
	HDC m_hDC;								  // 메인 윈도우에 Draw 할 DC

public:
	int Init(HWND _hwnd, POINT _ptResolution);
	void Progress();

private:
	void Update();
	void Render();
};