#include "pch.h"
#include "CStart.h"
#include "CFramework.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CTexture.h"
#include "CFilePathMgr.h"
#include "CCollideMgr.h"

CStart::CStart()
{
}

CStart::~CStart()
{
}

void CStart::Enter()
{
	CObject* pObj = new CPlayer;
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	int iMonCnt = 5;
	Vec2 vResolution = CFramework::GetInst()->GetResolution();
	CMonster* pMonObj = nullptr;
	
	// ����ϴ� ���� ����ȭ �ϴ� ���� �� ���ƺ��δ�, CMonster���� �Լ��� ��������
	// for������ ��ü�� �����ϱ� ������ �Լ��� �ҷ��� �� ���� �����?
 	float fTerm = (vResolution.x - 150.f) / (float)(iMonCnt - 1);

	for (int i = 0; i < iMonCnt; ++i)
	{
		pMonObj = new CMonster;
		pMonObj->SetPos(Vec2(75.f + i * fTerm, 100.f));
		pMonObj->SetCenterPos(pMonObj->GetPos());
		pMonObj->SetScale(Vec2(50.f, 50.f));
		AddObject(pMonObj, GROUP_TYPE::MONSTER);
	}

	// Collide Group Select
	// Player and Monster,  Monster and Weapon
	CCollideMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollideMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::WEAPON);
}

void CStart::Exit()
{
	// Collide Group Cancel
	CCollideMgr::GetInst()->Reset();
}
