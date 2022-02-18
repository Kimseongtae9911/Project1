#include "pch.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CFrameMgr.h"


void CPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::KHOLD)
	{
		vPos.y -= 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::KHOLD)
	{
		vPos.y += 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::KHOLD)
	{
		vPos.x -= 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::KHOLD)
	{
		vPos.x += 200.f * fDeltaTime;
	}

	SetPos(vPos);
}