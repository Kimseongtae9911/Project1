#pragma once

class CCore
{
private:
	static CCore* g_pInst;

public:
	static CCore* GetInstance()
	{		
		if (g_pInst == nullptr) 
		{
			g_pInst = new CCore;
		}

		return g_pInst;
	}

	static void Release()
	{
		if (g_pInst != nullptr)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}

private:
	CCore();
	~CCore();
};