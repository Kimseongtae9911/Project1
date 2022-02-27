#pragma once
class CCollideMgr
{
	SINGLE(CCollideMgr)

private:
	UINT m_arrCheck[(UINT)GROUP_TYPE::END];

public:
	void Init();
	void Update();

public:
	void CheckGroup(GROUP_TYPE _eFirst, GROUP_TYPE _eSecond);
	void Reset() { memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END); }
};