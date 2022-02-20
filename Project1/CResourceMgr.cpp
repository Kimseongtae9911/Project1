#include "pch.h"
#include "CResourceMgr.h"
#include "CFilePathMgr.h"
#include "CTexture.h"

CResourceMgr::CResourceMgr()
{

}

CResourceMgr::~CResourceMgr()
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

CTexture* CResourceMgr::LoadTexture(const wstring& _strKey, const wstring& _strFilePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr)
	{
		return pTex;
	}

	wstring strFilePath = CFilePathMgr::GetInst()->GetFilePath();
	strFilePath += _strFilePath;

    pTex = new CTexture;
	pTex->Load(strFilePath);

	pTex->SetKey(_strKey);
	pTex->SetFilePath(_strFilePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResourceMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}
