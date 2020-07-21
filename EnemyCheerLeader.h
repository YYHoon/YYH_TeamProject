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

	RECT _EnemyShadow;				//�� �׸���
	RECT _Enemy;					//�� ĳ���� �� �浹ó���� �簢��
	RECT _EnemyPlayerExploration;	//���� �÷��̾� Ž���ϴ� ����
	RECT _EnemyAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	RECT _EnemyAttack;				//���� ���ݽ� �浹ó����

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	float _Hp;

	bool _IsRight; //���ʿ�����

public:

	virtual HRESULT init();
	virtual HRESULT Init(POINT pt);

	void AniInit();
	void AniSet(CLSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	RECT GetEnemyHit() { return _Enemy; } //�ǰݿ���

	CLSTATE getClState() { return _ClState; }

	void hitHP(float damge);

	float setHP() { return _Hp; }
};