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
	// ������ ��Ŀ�� �˾Ƴ���
	HWND hWnd = GetFocus();

	// �����찡 ��Ŀ�� ���϶�
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) // Ű�� ���ȴ�
			{
				if (m_vecKey[i].bPrevPush)
				{
					// Ű�� �����־���
					m_vecKey[i].eState = KEY_STATE::KHOLD;
				}
				else {
					// Ű�� �ȴ����־���
					m_vecKey[i].eState = KEY_STATE::KDOWN;
				}

				m_vecKey[i].bPrevPush = true;
			}
			else // Ű�� �ȴ����ִ�
			{
				if (m_vecKey[i].bPrevPush)
				{
					// ������ �����־���
					m_vecKey[i].eState = KEY_STATE::KUP;
				}
				else
				{
					// ������ �ȴ����־���
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	else // �����찡 ��Ŀ���� Ǯ���� ��
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