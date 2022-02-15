#include "pch.h"
#include "CFrameMgr.h"
#include "CFramework.h"

CFrameMgr::CFrameMgr()
	: m_lICurCount{}
	, m_lIPrevCount{}
	, m_LIFrequency{}
	, m_dDT(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
{

}

CFrameMgr::~CFrameMgr()
{

}

void CFrameMgr::Init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_lIPrevCount);

	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_LIFrequency);
}

void CFrameMgr::Update()
{
	QueryPerformanceCounter(&m_lICurCount);

	m_dDT = (double)(m_lICurCount.QuadPart - m_lIPrevCount.QuadPart) / (double)m_LIFrequency.QuadPart;

	m_lIPrevCount = m_lICurCount;

	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d,  DT : %f", m_iFPS, m_dDT);
		SetWindowText(CFramework::GetInst()->GetMainHwnd(), szBuffer);
	}
}
