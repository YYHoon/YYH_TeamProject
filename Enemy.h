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

	EnemyState* _EnemyState; //����~

	DIRECTION _Dir; //����~

	animation* _ClMotion;

	image* _EnemyShadowImage;	//�׸��� �̹���(�߿���)
	image* _EnemyCoreImage;		//ĳ���� �̹��� ���� �޶�����

	RECT _EnemyShadow;				//�� �׸���
	RECT _EnemyCore;				//�� ĳ���� �� �浹ó���� �簢��
	RECT _EnemyPlayerExploration;	//���� �÷��̾� Ž���ϴ� ����
	RECT _EnemyAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	RECT _EnemyAttack;				//���� ���ݽ� �浹ó����

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _CoreX, _CoreY; //ĳ������ ����
	
	float _ChaseAngle; //���߿� �÷��̾� ��ġ���� ���󰥶� ���� �Լ�

	bool _IsTurn; //���ʿ�����

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	float GetEnemyX() { return _ShadowX; }
	float GetEnemyY() { return _ShadowY; }
	

	RECT GetEnemyHit() { return _EnemyCore; }
	RECT GetEnemyPlayerExploration() { return _EnemyPlayerExploration; } //�÷��̾� ��ġŽ�� ��Ʈ
	RECT GetEnemyAttackExploration() { return _EnemyAttackExploration; } //�÷��̾ ���ݷ�Ʈ�� ���ö� ���ݳ�����
	RECT GetEnemyAttack() { return _EnemyAttack; } //���ݽ� �����Ǵ� �浹�� ��Ʈ~

	DIRECTION GetDirection() { return _Dir; }

	void SetDirection(DIRECTION Dir) { _Dir = Dir; };
};