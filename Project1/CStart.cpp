#include "pch.h"
#include "CStart.h"
#include "CObject.h"

CStart::CStart()
{
}

CStart::~CStart()
{
}

void CStart::Enter()
{
	CObject* pObj = new CObject;

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::DEFAULT);
}

void CStart::Exit()
{
}
