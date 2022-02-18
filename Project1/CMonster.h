#pragma once
#include "CObject.h"
class CMonster : public CObject
{
private:
	Vec2 m_vCenterPos;
	float m_fSpeed;
	float m_fDistance;
	int m_iDir;

public:
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _f) { m_fSpeed = _f; }
	void SetCenterPos(Vec2 _pos) { m_vCenterPos = _pos; }

public:
	virtual void Update();

public:
	CMonster();
	~CMonster();
};

