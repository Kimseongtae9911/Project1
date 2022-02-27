#include "pch.h"
#include "CFramework.h"

#include "CCollideMgr.h"
#include "CFilePathMgr.h"
#include "CFrameMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CObject.h"

CFramework::CFramework()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{

}

CFramework::~CFramework()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
	
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}

}

int CFramework::Init(HWND _hwnd, POINT _ptResolution)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResolution;

	//윈도우 크기 조정
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);
	
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	CreateGDIObject();

	//manager 초기화
	CFilePathMgr::GetInst()->Init();
	CFrameMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();
	CSceneMgr::GetInst()->Init();

	return S_OK;
}

void CFramework::Progress()
{
	CFrameMgr::GetInst()->Update();
	CKeyMgr::GetInst()->Update();
	CSceneMgr::GetInst()->Update();
	CCollideMgr::GetInst()->Update();

	// Double Buffering
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	CFrameMgr::GetInst()->Render();
}

void CFramework::CreateGDIObject()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
