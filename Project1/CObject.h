#pragma once

class CCollider;

class CObject
{

private:
	Vec2 m_vPos;
	Vec2 m_vScale;

	CCollider* m_pCollider;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }

public:
	virtual void Update() = 0;
	virtual void FinalUpdate() final;
	virtual void Render(HDC _dc);

	void Component_Render(HDC _dc);

public:
	CObject();
	virtual ~CObject();

};