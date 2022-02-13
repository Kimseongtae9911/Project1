#pragma once

class CFrameMgr
{
	SINGLE(CFrameMgr);

private:
	LARGE_INTEGER m_lICurCount;
	LARGE_INTEGER m_LIPrequency;

public:
	void Init();
};

