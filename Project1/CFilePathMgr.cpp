#include "pch.h"
#include "CFilePathMgr.h"
#include "CFramework.h"

CFilePathMgr::CFilePathMgr()
{

}

CFilePathMgr::~CFilePathMgr()
{

}

void CFilePathMgr::Init()
{
	GetCurrentDirectory(255, m_szFilePath);
	
	int iLen = (int)wcslen(m_szFilePath);

	for (int i = iLen - 1; i >= 0; --i)
	{
		if ('\\' == m_szFilePath[i])
		{
			m_szFilePath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_szFilePath, 255, L"\\Resource\\");

	//SetWindowText(CFramework::GetInst()->GetMainHwnd(), m_szFilePath);
}
