#include "pch.h"
#include "CCollider.h"
#include "CFramework.h"
#include "CObject.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider()
	: m_pObject(nullptr)
	, m_iID(g_iNextID++)
{
}

CCollider::~CCollider()
{
}

void CCollider::FinalUpdate()
{
	Vec2 vObjectPos = m_pObject->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void CCollider::Render(HDC _dc)
{
	HPEN hRedPen = CFramework::GetInst()->GetPen(PEN_TYPE::RED);
	HPEN hDefaultPen = (HPEN)SelectObject(_dc, hRedPen);

	HBRUSH hHollowBrush = CFramework::GetInst()->GetBrush(BRUSH_TYPE::HOLLOW);
	HBRUSH hDefaultBrush = (HBRUSH)SelectObject(_dc, hHollowBrush);

	Rectangle(_dc, (int)(m_vFinalPos.x - m_vScale.x / 2.f),
				   (int)(m_vFinalPos.y - m_vScale.y / 2.f),
				   (int)(m_vFinalPos.x + m_vScale.x / 2.f),
				   (int)(m_vFinalPos.y + m_vScale.y / 2.f));

	SelectObject(_dc, hDefaultPen);
	SelectObject(_dc, hDefaultBrush);
}

