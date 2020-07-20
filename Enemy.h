#pragma once
#include "gameNode.h"
#include "EnemyState.h"

enum class DIRECTION
{
	LEFT,
	RIGHT
};

class Enemy : public gameNode
{
private:

	EnemyState* _EnemyState; //상태~

	DIRECTION _Dir; //방향~

	animation* _ClMotion;

	image* _EnemyShadowImage;	//그림자 이미지(중요함)
	image* _EnemyCoreImage;		//캐릭터 이미지 자주 달라진다

	RECT _EnemyShadow;				//적 그림자
	RECT _EnemyCore;				//적 캐릭터 및 충돌처리용 사각형
	RECT _EnemyPlayerExploration;	//적이 플레이어 탐색하는 영역
	RECT _EnemyAttackExploration;	//플레이어 들어올시 공격하는 영역
	RECT _EnemyAttack;				//적이 공격시 충돌처리용

	float _ShadowX, _ShadowY; //그림자의 중점 (EnemyCore에 사용)

	float _CoreX, _CoreY; //캐릭터의 중점
	
	float _ChaseAngle; //나중에 플레이어 위치따라 따라갈때 사용될 함수

	bool _IsTurn; //왼쪽오른쪽

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	

	RECT GetEnemyHit() { return _EnemyCore; }
	RECT GetEnemyPlayerExploration() { return _EnemyPlayerExploration; } //플레이어 위치탐색 렉트
	RECT GetEnemyAttackExploration() { return _EnemyAttackExploration; } //플레이어가 공격렉트에 들어올때 공격나간다
	RECT GetEnemyAttack() { return _EnemyAttack; } //공격시 생성되는 충돌용 렉트~

	DIRECTION GetDirection() { return _Dir; }

	void SetDirection(DIRECTION Dir) { _Dir = Dir; };
};