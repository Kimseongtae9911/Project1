#pragma once

class CCollider;

class CCollideMgr
{
	SINGLE(CCollideMgr)

private:

	UINT m_arrCheck[(UINT)GROUP_TYPE::END];  // Collide Check Matrix

public:
	void Update();
	void CheckGroup(GROUP_TYPE _eFirst, GROUP_TYPE _eSecond);
	void Reset() { memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END); }

private:
	void CollideGroupUpdate(GROUP_TYPE _eFirst, GROUP_TYPE _eSecond);
	bool IsCollide(CCollider* _pFirst, CCollider* _pSecond);
};