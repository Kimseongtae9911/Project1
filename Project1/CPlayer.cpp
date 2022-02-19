#include "pch.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CFrameMgr.h"
#include "CMissile.h"

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
	if (CKeyMgr::GetInst()->GetKeyState(KEY::SPACE) == KEY_STATE::KDOWN)
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));	
	pMissile->SetDir(Vec2(-1.f, -7.f));
	
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}