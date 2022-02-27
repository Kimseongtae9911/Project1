#pragma once

class CObject;

class CCollider
{

private:
	static UINT g_iNextID;

	CObject* m_pObject;
	Vec2 m_vOffsetPos;   // ������Ʈ�κ��� ������� ��ġ(Collider�� ��ġ)
	Vec2 m_vFinalPos;    // ������Ʈ�� ������ġ
	Vec2 m_vScale;		 // �浹ü�� ũ��
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

