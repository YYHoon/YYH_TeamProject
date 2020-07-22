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

	MYRECT _SgShadow;				//�� �׸���
	MYRECT _SgHit;					//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SgPlayerExploration;	//���� �÷��̾� Ž���ϴ� ����
	MYRECT _SgAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _SgAttack;				//���� ���ݽ� �浹ó����

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

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
	MYRECT GetEnemyHit() { return _SgHit; } //�ǰݿ���

	SGSTATE getSmState() { return _SgState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }
};

