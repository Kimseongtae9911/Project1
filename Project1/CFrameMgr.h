#pragma once

class CFrameMgr
{
	SINGLE(CFrameMgr);

private:
	LARGE_INTEGER m_lICurCount;
	LARGE_INTEGER m_lIPrevCount;
	LARGE_INTEGER m_LIFrequency;

	double m_dDT; // ��ŸŸ��
	double m_dAcc;
	UINT m_iCallCount; // �ʴ� ȣ�� Ƚ��
	UINT m_iFPS;


public:
	void Init();
	void Update();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

