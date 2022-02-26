#include "pch.h"
#include "CMissile.h"
#include "CFrameMgr.h"

CMissile::CMissile()
	: m_fSpeed(400.f)
	, m_fTheta(PI / 2.f)
	, m_vDir(1.f, 1.f)
{
	m_vDir.Normalize();

	CreateCollider();
}

CMissile::~CMissile()
{
}

void CMissile::Update()
{
	Vec2 vPos = GetPos();

	//vPos.x += m_fSpeed * cosf(m_fTheta) * fDeltaTime;
	//vPos.y -= m_fSpeed * sinf(m_fTheta) * fDeltaTime;

	vPos.x += m_fSpeed * m_vDir.x * fDeltaTime;
	vPos.y += m_fSpeed * m_vDir.y * fDeltaTime;

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
