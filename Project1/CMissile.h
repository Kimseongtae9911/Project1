#pragma once
#include "CObject.h"

class CMissile : public CObject
{
private:
	int m_iDir;
	float m_fSpeed;
	
public:
	void SetDir(int _iDir) { m_iDir = _iDir;}	

public:
	virtual void Update();
	virtual void Render(HDC _dc);

public:
	CMissile();
	~CMissile();
};

