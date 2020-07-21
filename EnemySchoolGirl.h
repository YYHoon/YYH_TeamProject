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

	RECT _SgShadow;				//�� �׸���
	RECT _SgHit;				//�� ĳ���� �� �浹ó���� �簢��
	RECT _SgPlayerExploration;	//���� �÷��̾� Ž���ϴ� ����
	RECT _SgAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	RECT _SgAttack;				//���� ���ݽ� �浹ó����

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	RECT GetEnemyHit() { return _SgHit; } //�ǰݿ���

	SGSTATE getSmState() { return _SgState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }
};

