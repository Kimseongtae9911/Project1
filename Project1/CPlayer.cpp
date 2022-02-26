#include "pch.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CFrameMgr.h"
#include "CFilePathMgr.h"
#include "CResourceMgr.h"
#include "CMissile.h"
#include "CTexture.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	m_pTex = CResourceMgr::GetInst()->LoadTexture(L"Player", L"Test.bmp");

	CreateCollider();
}

CPlayer::~CPlayer()
{
}


void CPlayer::Update()
{
	Vec2 vPos = GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::KHOLD)
	{
		vPos.y -= 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::KHOLD)
	{
		vPos.y += 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::KHOLD)
	{
		vPos.x -= 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::KHOLD)
	{
		vPos.x += 200.f * fDeltaTime;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::SPACE) == KEY_STATE::KDOWN)
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();

	int iWidth = (int)m_pTex->GetSize().bmWidth;
	int iHeight = (int)m_pTex->GetSize().bmHeight;

	int iLeft = (int)(vPos.x - (float)(iWidth / 2));
	int iTop = (int)(vPos.y - (float)(iHeight / 2));

	//BitBlt(_dc, iLeft, iTop, iWidth, iHeight, m_pTex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc, iLeft, iTop, iWidth, iHeight, m_pTex->GetDC(), 0, 0, iWidth, iHeight, RGB(255, 0, 255));
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));	
	pMissile->SetDir(Vec2(-1.f, -7.f));
	
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::DEFAULT);
}

