#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CFrameMgr.h"
#include "CCollider.h"

CObject::CObject()
	: m_vPos{}
	, m_vScale{}
	, m_pCollider( nullptr )
{
}

CObject::~CObject()
{
	if (m_pCollider != nullptr)
		delete m_pCollider;
}

void CObject::FinalUpdate()
{
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}

void CObject::Render(HDC _dc)
{
	Rectangle(_dc, (int)(m_vPos.x - m_vScale.x / 2.f),
				   (int)(m_vPos.y - m_vScale.y / 2.f),
				   (int)(m_vPos.x + m_vScale.x / 2.f),
				   (int)(m_vPos.y + m_vScale.y / 2.f));

	Component_Render(_dc);
}

void CObject::Component_Render(HDC _dc)
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->Render(_dc);   // Object의 충돌체
	}
}

void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pObject = this;
}