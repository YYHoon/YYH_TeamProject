#pragma once
#include "gameNode.h"

enum CLSTATE
{
	CLIdle,
	CLBegging,
	CLBlowback,
	CLDazed,
	CLFalling,
	CLHolding,
	CLHoldingrelease,
	CLJump,
	CLKnockdown,
	CLWalk,
	CLRun,
	CLJab,
	CLSpinpom,
	CLDoublepom,
	CLBackflip,
	CLWeaponSwing
};

class EnemyCheerLeader : public gameNode
{
private:
	CLSTATE _ClState;

	animation* _CLAni;

	image* _EnemyShadowImage;	//그림자 이미지(중요함)
	image* _EnemyImage;		//캐릭터 이미지 자주 달라진다

	MYRECT _EnemyShadow;				//적 그림자
	MYRECT _Enemy;						//적 캐릭터 및 충돌처리용 사각형
	MYRECT _EnemyPlayerExploration;		//적이 플레이어 탐색하는 영역
	MYRECT _EnemyAttackExploration;		//플레이어 들어올시 공격하는 영역
	MYRECT _EnemyAttack;				//적을 공격시 충돌처리용

	float _ShadowX, _ShadowY; //그림자의 중점 (Enemy에 사용)

	float _EnemyX, _EnemyY; //캐릭터의 중점

	float _ChaseAngle; //나중에 플레이어 위치따라 따라갈때 사용될 함수

	float _Hp;

	bool _IsRight; //왼쪽오른쪽

public:

	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void AniInit();
	void AniSet(CLSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	MYRECT GetEnemyHit() { return _Enemy; } //피격영역

	CLSTATE getClState() { return _ClState; }

	void hitHP(float damge);

	float setHP() { return _Hp; }

	void SetX(float X) { _ShadowX = X; }
	void SetY(float Y) { _ShadowY = Y; }
};