#include "pch.h"
#include "CKeyMgr.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'Z', 'X', 'C', 'V', 'B',
	VK_MENU, VK_CONTROL, VK_LSHIFT, VK_SPACE, VK_RETURN, VK_ESCAPE
};

CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{

}

void CKeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::Update()
{
	// 윈도우 포커싱 알아내기
	HWND hWnd = GetFocus();

	// 윈도우가 포커싱 중일때
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) // 키가 눌렸다
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 키가 눌려있었다
					m_vecKey[i].eState = KEY_STATE::KHOLD;
				}
				else {
					// 키가 안눌려있었다
					m_vecKey[i].eState = KEY_STATE::KDOWN;
				}

				m_vecKey[i].bPrevPush = true;
			}
			else // 키가 안눌려있다
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에 눌려있었다
					m_vecKey[i].eState = KEY_STATE::KUP;
				}
				else
				{
					// 이전에 안눌려있었다
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	else // 윈도우가 포커싱이 풀렸을 때
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::KDOWN == m_vecKey[i].eState || KEY_STATE::KHOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::KUP;
			}
			else if (KEY_STATE::KUP == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}