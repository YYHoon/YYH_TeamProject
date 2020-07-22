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

	image* _EnemyShadowImage;	//�׸��� �̹���(�߿���)
	image* _EnemyImage;		//ĳ���� �̹��� ���� �޶�����

	MYRECT _EnemyShadow;				//�� �׸���
	MYRECT _Enemy;						//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _EnemyAttackExploration;		//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _EnemyAttack;				//���� ���ݽ� �浹ó����

	POINTFLOAT _ClCenter;

	float _ShadowX, _ShadowY; //�׸����� ���� (Enemy�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

public:

	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void AniInit();
	void AniSet(CLSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ClCenter.x; }
	float GetEnemyY() { return _ClCenter.y; }
	MYRECT GetEnemyHit() { return _Enemy; } //�ǰݿ���

	CLSTATE getClState() { return _ClState; }

	void hitHP(float damge);

	float setHP() { return _Hp; }
};