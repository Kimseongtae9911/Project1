#pragma once

class CResource
{
private:
	wstring m_strKey;
	wstring m_strFilePath;

public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetFilePath(const wstring& _FilePath) { m_strFilePath = _FilePath; }

	const wstring& GetKey() { return m_strKey;}
	const wstring& GetFilePath() { return m_strFilePath; }

public:
	CResource();
	~CResource();
};

