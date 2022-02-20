#pragma once
#include "CResource.h"

class CTexture : public CResource
{
private:
	HDC m_dc;
	HBITMAP m_hBit;
	BITMAP m_bitInfo;

public:
	void Load(const wstring& _strFilePath);
	BITMAP GetSize() { return m_bitInfo; }
	HDC GetDC() { return m_dc; }

private:
	CTexture();
	~CTexture();

	friend class CResourceMgr;
};

