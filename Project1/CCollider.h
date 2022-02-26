#pragma once

class CObject;

class CCollider
{

private:
	CObject* m_pObject;

public:
	void FinalUpdate();

	friend class CObject;
};

