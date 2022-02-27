#include "pch.h"
#include "CCollideMgr.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CObject.h"
#include "CCollideMgr.h"

CCollideMgr::CCollideMgr()
	: m_arrCheck{}
{

}

CCollideMgr::~CCollideMgr()
{

}

void CCollideMgr::Update()
{
	for (UINT row = 0; row < (UINT)GROUP_TYPE::END; ++row)
	{
		for (UINT col = row; col < (UINT)GROUP_TYPE::END; ++col)
		{
			if (m_arrCheck[row] & (1 << col))
			{
				CollideGroupUpdate((GROUP_TYPE)row, (GROUP_TYPE)col);
			}
		}
	}

}

void CCollideMgr::CollideGroupUpdate(GROUP_TYPE _eFirst, GROUP_TYPE _eSecond)
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	const vector<CObject*>& vecFirst = pCurScene->GetGroupObject(_eFirst);
	const vector<CObject*>& vecSecond = pCurScene->GetGroupObject(_eSecond);

	for (size_t i = 0; i < vecFirst.size(); ++i)
	{
		if (vecFirst[i]->GetCollider() == nullptr)
			continue;

		for (size_t j = 0; j < vecSecond.size(); ++j)
		{
			if (vecSecond[j]->GetCollider() == nullptr || vecFirst[i] == vecSecond[j])
				continue;

			if (IsCollide(vecFirst[i]->GetCollider(), vecSecond[j]->GetCollider()))
			{

			}	
			else
			{

			}
		}
	}
}

bool CCollideMgr::IsCollide(CCollider* _pFirst, CCollider* _pSecond)
{
	return false;
}


void CCollideMgr::CheckGroup(GROUP_TYPE _eFirst, GROUP_TYPE _eSecond)
{
	UINT iRow = (UINT)_eFirst;
	UINT iCol = (UINT)_eSecond;

	if ((UINT)_eFirst > (UINT)_eSecond)
	{
		iRow = (UINT)_eSecond;
		iCol = (UINT)_eFirst;
	}

	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}
}