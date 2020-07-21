#pragma once
#include "gameNode.h"

enum SMSTATE
{
	SmBegging,
	SmBlownback,
	SmDazed,
	SmGethit,
	SmHoldhit,
	SmHoldrelrase,
	SmIdle,
	SmJumpPunch,
	SmKick,
	SmKnockdown,
	SmRun,
	SmSideKick,
	SmStPunch,
	SmTaunt,
	SmUpercut,
	SmWalk,
	SmWeaponSwing
};

class EnemySchoolMan : public gameNode
{
private:
	SMSTATE _SmState;

	animation* _SmAni;

	image* _SmShadowImage;
	image* _SmImage;

	RECT _SmShadow;				//적 그림자
	RECT _SmHit;				//적 캐릭터 및 충돌처리용 사각형
	RECT _SmPlayerExploration;	//적이 플레이어 탐색하는 영역
	RECT _SmAttackExploration;	//플레이어 들어올시 공격하는 영역
	RECT _SmAttack;				//적이 공격시 충돌처리용

	float _ShadowX, _ShadowY; //그림자의 중점 (EnemyCore에 사용)

	float _EnemyX, _EnemyY; //캐릭터의 중점

	float _ChaseAngle; //나중에 플레이어 위치따라 따라갈때 사용될 함수

	float _Hp;

	bool _IsRight; //왼쪽오른쪽

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINT pt);

	void SmAniInit();
	void SmAniSet(SMSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	RECT GetEnemyHit() { return _SmHit; } //피격영역

	SMSTATE getSmState() { return _SmState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }
};

