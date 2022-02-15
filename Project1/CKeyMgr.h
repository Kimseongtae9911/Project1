#pragma once

// 프레임 동기화 --> 동일 프레임 내에서 같은 키에 대해, 도일한 이벤트를 가져간다

enum class KEY_STATE { NONE, KDOWN, KHOLD, KUP};

enum class KEY {LEFT, RIGHT, UP, DOWN, 
	Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, Z, X, C, V, B,
	ALT, CTRL, LSHIFT, SPACE, ENTER, ESC,
	LAST};

struct tKeyInfo
{
	KEY_STATE eState; // 키의 상태값
	bool bPrevPush;		  // 이전 프레임에서 키가 눌렸는지
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	vector<tKeyInfo> m_vecKey;

public:
	void Init();
	void Update();

public:
	KEY_STATE GetKeyState(KEY _eKey) {return m_vecKey[(int)_eKey].eState;}
};

