#include "pch.h"
#include "CMonster.h"
#include "CFrameMgr.h"

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