#pragma once
#include "CObject.h"

class CTexture;

class CPlayer : public CObject
{
private:
	CTexture* m_pTex;

public:
	virtual void Update();
	virtual void Render(HDC _dc);

private:
	void CreateMissile();

public:
	CPlayer();
	~CPlayer();
};

