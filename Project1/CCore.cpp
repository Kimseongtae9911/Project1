#include "pch.h"
#include "CCore.h"
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

	//������ ũ�� ����
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);
	
	g_obj.m_ptPos = POINT{ m_ptResolution.x / 2, m_ptResolution.y / 2};
	g_obj.m_ptScale = POINT{ 100, 100 };

	return S_OK;
}

void CCore::Progress()
{
	static int callcount = 0;
	++callcount;

	static int iPrevCount = GetTickCount();

	int iCurCount = GetTickCount();
	if (iCurCount - iPrevCount > 1000)
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}

	Update();
	Render();
}

void CCore::Update()
{
	// Ű�Է��� �޽��� ����� �ƴ϶� ���� �� ���� ���� Ű�� ���ȴ��� Ȯ�� --> �񵿱� Ű����� �Լ� ���
	// �츮 �����찡 ��Ŀ�� �Ǿ��ִ��� �������� ���� ��׶��忡 �׻� ����[����]
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)  //���� ���ȴ����� Ȯ��
	{
		g_obj.m_ptPos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_obj.m_ptPos.x += 1;
	}
}

void CCore::Render()
{
	Rectangle(m_hDC, g_obj.m_ptPos.x - g_obj.m_ptScale.x / 2,
		g_obj.m_ptPos.y - g_obj.m_ptScale.y / 2,
		g_obj.m_ptPos.x + g_obj.m_ptScale.x / 2,
		g_obj.m_ptPos.y + g_obj.m_ptScale.y / 2);
		
}
