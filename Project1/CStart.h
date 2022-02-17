#pragma once
#include "CScene.h"

class CStart : public CScene
{

public:
	virtual void Enter();
	virtual void Exit();


public:
	CStart();
	~CStart();
};