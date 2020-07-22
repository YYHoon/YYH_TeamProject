#pragma once
#include "gameNode.h"

enum SGSTATE
{
	SgBegging,
	SgBlownback,
	SgDazed,
	SgGethit,
	SgHold,
	SgHoldhit,
	SgHoldrelrase,
	SgIdle,
	SgJumpKnee,
	SgKick,
	SgKnockdown,
	SgRun,
	SgJab,
	SgTaunt,
	SgWalk,
	SgWeaponSwing
};

class EnemySchoolGirl : public gameNode
{
private:
	SGSTATE _SgState;

	animation* _SgAni;

	image* _SgShadowImage;
	image* _SgImage;

	MYRECT _SgShadow;				//적 그림자
	MYRECT _SgHit;					//적 캐릭터 및 충돌처리용 사각형
	MYRECT _SgPlayerExploration;	//적이 플레이어 탐색하는 영역
	MYRECT _SgAttackExploration;	//플레이어 들어올시 공격하는 영역
	MYRECT _SgAttack;				//적이 공격시 충돌처리용

	float _ShadowX, _ShadowY; //그림자의 중점 (EnemyCore에 사용)

	float _EnemyX, _EnemyY; //캐릭터의 중점

	float _ChaseAngle; //나중에 플레이어 위치따라 따라갈때 사용될 함수

	float _Hp;

	bool _IsRight; //왼쪽오른쪽

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	MYRECT GetEnemyHit() { return _SgHit; } //피격영역

	SGSTATE getSmState() { return _SgState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }
};

