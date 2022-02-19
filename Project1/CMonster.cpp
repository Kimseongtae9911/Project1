#include "pch.h"
#include "CMonster.h"
#include "CFrameMgr.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CMissile.h"

CMonster::CMonster()
	: m_vCenterPos(Vec2(0.f, 0.f))
	, m_fSpeed(100.f)
	, m_fDistance(50.f)
	, m_iDir(1)
{
}

CMonster::~CMonster()
{
}

void CMonster::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;

	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(-1);

	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}

void CMonster::Update()
{
	Vec2 vCurPos = GetPos();

	vCurPos.x += fDeltaTime * m_fSpeed * m_iDir;	

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fDistance;

	if (fDist > 0.f)
	{
		m_iDir = -m_iDir;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}