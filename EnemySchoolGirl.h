#pragma once
#include "gameNode.h"
#include "Player.h"

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

	Player* _Player;

	image* _SgShadowImage;
	image* _SgImage;

	MYRECT _SgShadow;				//적 그림자
	MYRECT _SgHit;					//적 캐릭터 및 충돌처리용 사각형
	MYRECT _SgAttackExploration;	//플레이어 들어올시 공격하는 영역
	MYRECT _SgAttack;				//적이 공격시 충돌처리용

	POINTFLOAT _SgCenter;

	float _ShadowX, _ShadowY;  //그림자의 중점(캐릭터그릴떄 사용)

	float _EnemyX, _EnemyY;    //캐릭터의 중점(공격 영역및 공격시 사용)

	float _ChaseAngle;		   //나중에 플레이어 위치따라 따라갈때 사용될 함수
	float _Hp;
	float _Speed;

	bool _IsRight; //왼쪽오른쪽

	bool _IsAttack; //공격했는가

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetSchoolGirlCenterX() { return _SgCenter.x; } //중점	
	float GetSchoolGirlCenterY() { return _SgCenter.y; } //중점	
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//피격영역

	MYRECT GetSchoolGirlAttackExplor() { return _SgAttackExploration; } //플레이어가 들어올시 공격

	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //공격시 영역

	SGSTATE getSgState() { return _SgState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }

};