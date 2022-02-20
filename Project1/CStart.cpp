#include "pch.h"
#include "CStart.h"
#include "CFramework.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CTexture.h"
#include "CFilePathMgr.h"
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
	
	// 계산하는 것을 변수화 하는 것이 더 좋아보인다, CMonster에서 함수를 만들어야함
	// for문에서 객체를 생성하기 때문에 함수를 불러올 수 없다 방법은?
 	float fTerm = (vResolution.x - 150.f) / (float)(iMonCnt - 1);

	for (int i = 0; i < iMonCnt; ++i)
	{
		pMonObj = new CMonster;
		pMonObj->SetPos(Vec2(75.f + i * fTerm, 100.f));
		pMonObj->SetCenterPos(pMonObj->GetPos());
		pMonObj->SetScale(Vec2(50.f, 50.f));
		AddObject(pMonObj, GROUP_TYPE::MONSTER);
	}
}

void CStart::Exit()
{
}
