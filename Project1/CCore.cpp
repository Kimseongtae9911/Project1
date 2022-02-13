#include "pch.h"
#include "CCore.h"
#include "CKeyMgr.h"
#include "CFrameMgr.h"
#include "CObject.h"

CObject g_obj;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}

int CCore::Init(HWND _hwnd, POINT _ptResolution)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResolution;

	//윈도우 크기 조정
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);
	
	//manager 초기화
	CFrameMgr::GetInst()->Init();
	CKeyMgr::GetInst()->Init();


	g_obj.SetPos(Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y / 2)));
	g_obj.SetScale(Vec2(100, 100));

	return S_OK;
}

void CCore::Progress()
{
	//static int callcount = 0;
	//++callcount;

	//static int iPrevCount = GetTickCount();

	//int iCurCount = GetTickCount();
	//if (iCurCount - iPrevCount > 1000)
	//{
	//	iPrevCount = iCurCount;
	//	callcount = 0;
	//}

	Update();
	Render();
}

void CCore::Update()
{
	// 키입력이 메시지 기반이 아니라 지금 이 순간 무슨 키가 눌렸는지 확인 --> 비동기 키입출력 함수 사용
	// 우리 윈도우가 포커싱 되어있는지 따질수가 없고 백그라운드에 항상 실행[단점]

	Vec2 vPos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)  //지금 눌렸는지만 확인
	{
		vPos.x -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 0.01f;
	}

	g_obj.SetPos(vPos);
}

void CCore::Render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC, int(vPos.x - vScale.x / 2.f),
		             int(vPos.y - vScale.y / 2.f),
		             int(vPos.x + vScale.x / 2.f),
		             int(vPos.y + vScale.y / 2.f));
		
}
