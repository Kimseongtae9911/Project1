#pragma once

class CObject;

class CCollider
{

private:
	static UINT g_iNextID;

	CObject* m_pObject;
	Vec2 m_vOffsetPos;   // 오브젝트로부터 상대적인 위치(Collider의 위치)
	Vec2 m_vFinalPos;    // 오브젝트의 최종위치
	Vec2 m_vScale;		 // 충돌체의 크기
	UINT m_iID;			 // Collider unique ID

public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }

public:   
	void FinalUpdate();
	void Render(HDC _dc);

public:
	CCollider();
	~CCollider();

	friend class CObject;
};

