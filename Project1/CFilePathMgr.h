#pragma once
class CFilePathMgr
{
	SINGLE(CFilePathMgr);

private:
	wchar_t m_szFilePath[255];

public:
	const wchar_t* GetFilePath() { return m_szFilePath; }

public:
	void Init();
};

