#include "pch.h"
#include "CFramework.h"

#include "CFrameMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CObject.h"

CObject g_obj;

CFramework::CFramework()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
{

}

CFramework::~CFramework()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
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

	//manager 초기화
	CFrameMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();
	CSceneMgr::GetInst()->Init();

	g_obj.SetPos(Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y / 2)));
	g_obj.SetScale(Vec2(100, 100));

	return S_OK;
}

void CFramework::Progress()
{
	CFrameMgr::GetInst()->Update();
	CKeyMgr::GetInst()->Update();
	//CSceneMgr::GetInst()->Update();

	Update();
	Render();
}

void CFramework::Update()
{
	// 키입력이 메시지 기반이 아니라 지금 이 순간 무슨 키가 눌렸는지 확인 --> 비동기 키입출력 함수 사용
	// 우리 윈도우가 포커싱 되어있는지 따질수가 없고 백그라운드에 항상 실행[단점]

	Vec2 vPos = g_obj.GetPos();
	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::KDOWN)  //지금 눌렸는지만 확인
	{
		//vPos.x -= 100.f * CFrameMgr::GetInst()->GetfDT();
		vPos.x -= 100.f * fDeltaTime;
	}

	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::KHOLD)
	{
		vPos.x += 100.f * fDeltaTime;
	}

	g_obj.SetPos(vPos);
}

void CFramework::Render()
{
	// 초기화
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
					 
	// 그리기
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	
	Rectangle(m_memDC, int(vPos.x - vScale.x / 2.f),
		             int(vPos.y - vScale.y / 2.f),
		             int(vPos.x + vScale.x / 2.f),
		             int(vPos.y + vScale.y / 2.f));

	Rectangle(m_memDC, int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y),
		int(vPos.x + vScale.x),
		int(vPos.y + vScale.y));
	
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}
