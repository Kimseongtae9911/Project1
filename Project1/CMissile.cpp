#include "pch.h"
#include "CMissile.h"
#include "CFrameMgr.h"

CMissile::CMissile()
	: m_fSpeed(200.f)
	, m_iDir(1)
{
}

CMissile::~CMissile()
{
}

void CMissile::Update()
{
	Vec2 vPos = GetPos();

	vPos.y += m_fSpeed * (float)m_iDir * fDeltaTime;
}