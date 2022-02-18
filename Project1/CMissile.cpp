#include "pch.h"
#include "CMissile.h"
#include "CFrameMgr.h"

CMissile::CMissile()
	: m_fSpeed(400.f)
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

	SetPos(vPos);
}

void CMissile::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc, (int)(vPos.x - vScale.x / 2.f),
				 (int)(vPos.y - vScale.y / 2.f),
				 (int)(vPos.x + vScale.x / 2.f),
				 (int)(vPos.y + vScale.y / 2.f));
}
