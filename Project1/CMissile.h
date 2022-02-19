#pragma once
#include "CObject.h"

class CMissile : public CObject
{
private:
	float m_fTheta;
	float m_fSpeed;
	Vec2 m_vDir;

public:
	void SetDir(float _fTheta) { m_fTheta = _fTheta;}	
	void SetDir(Vec2 _vDir) 
	{ 
		m_vDir = _vDir; 
		m_vDir.Normalize();
	}

public:
	virtual void Update();
	virtual void Render(HDC _dc);

public:
	CMissile();
	~CMissile();
};

