#pragma once
#include "CObject.h"

class CPlayer : public CObject
{

public:
	virtual void Update();

private:
	void CreateMissile();
};

