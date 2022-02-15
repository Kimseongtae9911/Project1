#include "pch.h"
#include "CSceneMgr.h"

#include "CStart.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (m_arrScene[i] != nullptr)
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneMgr::Init()
{
	// Scene Create
	m_arrScene[(UINT)SCENE_TYPE::START] = new CStart;

	// Current Scene
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
}