#pragma once
#include "gameNode.h"
enum class MOVELR
{
	LEFT_WALK,
	RIGHT_WALK,
	LEFT_RUN,
	RIGHT_RUN,
	NON
};
enum class MOVEUD
{
	UP_WALK,
	DOWN_WALK,
	UP_RUN,
	DOWN_RUN,
	NON
};
class State;

class Player : public gameNode
{
private:
	

	State* _State;

	image* _Shadow;
	POINTFLOAT _Center;
	MYRECT _ShadowRc;
	MYRECT _PlayerHitRc;
	MOVELR _MoveLR;
	MOVEUD _MoveUD;
	float _Speed;
	float _Gravity;
	float _Jump;
	float _JumpMax;

	int _Money;
	int _HP;

	int _AttackCount = 0;
	int _RunCount=0;
	/// <대쉬>
	bool _LRun=false;
	int _LTime = 0;
	int _LClickTime = 0;
	bool _RRun=false;
	int _RTime = 0;
	int _RClickTime = 0;
	/// </대쉬>
	
	bool _Left;

public:

	Player();
	virtual ~Player() {};

	virtual void PlayerImageAniStting();
	//플레이어 이미지 애니메이션 셋팅 함수


	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
	virtual void Render();
	virtual void DebugRender();
	virtual void PlayerKeyMove();
	virtual void MoveUpdate();
	virtual void AttackUpdate();
	virtual void DashUpdate();

	virtual void Walk();
	virtual void Attack1();
	virtual void Attack2();
	virtual void Attack3();
	virtual void StandUp();
	virtual void Skill1();
	virtual void Skill2();
	virtual void Guard();
	virtual void GameOver();
	virtual void DiveAttack();
	virtual void Default();


	
	inline bool GetPlayerDirection() { return _Left; }
	inline float GetShadowCenterX() { return _Center.x; }
	inline float GetShadowCenterY() { return _Center.y; }
	inline POINTFLOAT GetShadowCenterPoint() { return _Center; }
	inline MYRECT GetShadowRect() { return _ShadowRc; }		//플레이어그림자렉트(기준)
	inline MYRECT GetPlayerRect() { return _PlayerHitRc; } //플레이어피격렉트
	inline int GetAttactCount() { return _AttackCount; }
	


	inline void SetAttackCount(int count) { _AttackCount += count; }
	inline void SetCenterX(float x) { _Center.x += x; }
	inline void SetCenterY(float y) { _Center.y += y; }
	inline void SetShadowCenterX(POINTFLOAT XY) {
		_Center.x = XY.x;
		_Center.y = XY.y;
	}
	
	void SetState(State* state);
};
