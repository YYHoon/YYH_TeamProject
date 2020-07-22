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

	MYRECT _SgShadow;				//�� �׸���
	MYRECT _SgHit;					//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SgAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _SgAttack;				//���� ���ݽ� �浹ó����

	POINTFLOAT _SgCenter;

	float _ShadowX, _ShadowY;  //�׸����� ����(ĳ���ͱ׸��� ���)

	float _EnemyX, _EnemyY;    //ĳ������ ����(���� ������ ���ݽ� ���)

	float _ChaseAngle;		   //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�
	float _Hp;
	float _Speed;

	bool _IsRight; //���ʿ�����

	bool _IsAttack; //�����ߴ°�

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetSchoolGirlCenterX() { return _SgCenter.x; } //����	
	float GetSchoolGirlCenterY() { return _SgCenter.y; } //����	
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//�ǰݿ���

	MYRECT GetSchoolGirlAttackExplor() { return _SgAttackExploration; } //�÷��̾ ���ý� ����

	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //���ݽ� ����

	SGSTATE getSgState() { return _SgState; }

	void SmHitHP(float damge);

	float setHP() { return _Hp; }

};