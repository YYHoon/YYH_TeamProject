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

	MYRECT _SmShadow;				//�� �׸���
	MYRECT _SmHit;				//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SmPlayerExploration;	//���� �÷��̾� Ž���ϴ� ����
	MYRECT _SmAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _SmAttack;				//���� ���ݽ� �浹ó����

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SmAniInit();
	void SmAniSet(SMSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	MYRECT GetEnemyHit() { return _SmHit; } //�ǰݿ���

	SMSTATE getSmState() { return _SmState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }
};

