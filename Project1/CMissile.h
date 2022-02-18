#pragma once
#include "CObject.h"

class CMissile : public CObject
{
private:
	int m_iDir;
	float m_fSpeed;
	
public:
	virtual void Update();

public:
	CMissile();
	~CMissile();
};

