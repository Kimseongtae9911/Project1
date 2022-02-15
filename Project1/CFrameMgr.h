#pragma once

class CFrameMgr
{
	SINGLE(CFrameMgr);

private:
	LARGE_INTEGER m_lICurCount;
	LARGE_INTEGER m_lIPrevCount;
	LARGE_INTEGER m_LIFrequency;

	double m_dDT; // 델타타임
	double m_dAcc;
	UINT m_iCallCount; // 초당 호출 횟수
	UINT m_iFPS;


public:
	void Init();
	void Update();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

