#include "pch.h"
#include "CFrameMgr.h"

CFrameMgr::CFrameMgr()
	: m_lICurCount{}
	, m_LIPrequency{}
{

}

CFrameMgr::~CFrameMgr()
{

}

void CFrameMgr::Init()
{
	QueryPerformanceCounter(&m_lICurCount);
	QueryPerformanceFrequency(&m_LIPrequency);
}
