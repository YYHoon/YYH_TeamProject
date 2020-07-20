#include "stdafx.h"
#include "Enemy.h"
#include "EnemyAllState.h"

HRESULT Enemy::init()
{
	//���� �׸���~
	_EnemyShadowImage = IMAGEMANAGER->addImage("Showdow", "image/enemy/Enemy_Shadow.bmp", 128, 38, true, RGB(255, 0, 255)); 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//ġ��� �⺻����
	_EnemyCoreImage = IMAGEMANAGER->addFrameImage("CLIdle", "image/enemy/cr/cl_idle.bmp", 0, 0, 1980, 432, 12, 2, true, RGB(255, 0, 255));

	//ġ��� �׺�
	IMAGEMANAGER->addFrameImage("ClBegging", "image/enemy/cr/cl_begging.bmp", 0, 0, 468, 372, 3, 2, true, RGB(255, 0, 255));

	//ġ��� �÷����� ������ �Ǵ� 3Ÿ �¾�����
	IMAGEMANAGER->addFrameImage("Clblownback", "image/enemy/cr/cl_blownback.bmp", 0, 0, 1020, 414, 12, 6, true, RGB(255, 0, 255));

	//ġ��� ȸ�ǵ���
	IMAGEMANAGER->addFrameImage("ClCratwheel", "image/enemy/cr/cl_cartwheel.bmp", 0, 0, 957, 332, 22, 4, true, RGB(255, 0, 255));

	//ġ��� ����
	IMAGEMANAGER->addFrameImage("ClDazed", "image/enemy/cr/cl_dazed.bmp", 0, 0, 540, 390, 4, 2, true, RGB(255, 0, 255));

	//ġ��� ��������
	IMAGEMANAGER->addFrameImage("ClFalling", "image/enemy/cr/cl_falling.bmp", 0, 0, 624, 354, 4, 2, true, RGB(255, 0, 255));

	//ġ��� ���ݴ������� (1,2Ÿ)
	IMAGEMANAGER->addFrameImage("ClGethit", "image/enemy/cr/cl_gethit.bmp", 0, 0, 1539, 426, 9, 2, true, RGB(255, 0, 255));

	//ġ��� ��������
	IMAGEMANAGER->addFrameImage("ClholdingHit", "image/enemy/cr/cl_holding_hit.bmp", 0, 0, 840, 366, 5, 2, true, RGB(255, 0, 255));

	//ġ��� ��� Ǯ������
	IMAGEMANAGER->addFrameImage("ClholdingRelease", "image/enemy/cr/cl_holdingrelease.bmp", 0, 0, 840, 450, 12, 2, true, RGB(255, 0, 255));

	//ġ��� ��������
	IMAGEMANAGER->addFrameImage("ClJump", "image/enemy/cr/cl_jump.bmp", 0, 0, 540, 474, 3, 2, true, RGB(255, 0, 255));

	//ġ��� �ٿ�� ���
	IMAGEMANAGER->addFrameImage("ClKnockdown", "image/enemy/cr/cl_knockdown.bmp", 0, 0, 3060, 1242, 12, 6, true, RGB(255, 0, 255));

	//ġ��� �ȱ�
	IMAGEMANAGER->addFrameImage("ClWalk", "image/enemy/cr/cl_walk.bmp", 0, 0, 2736, 438, 12, 2, true, RGB(255, 0, 255));

	//ġ��� �޸���
	IMAGEMANAGER->addFrameImage("Clrun", "image/enemy/cr/cl_run.bmp", 0, 0, 1368, 318, 8, 2, true, RGB(255, 0, 255));

	//ġ��� �Ϲݰ��� & �޺� 1��
	IMAGEMANAGER->addFrameImage("ClJab", "image/enemy/cr/cl_jab.bmp", 0, 0, 1332, 468, 6, 2, true, RGB(255, 0, 255));

	//ġ��� �޺�2�� ����
	IMAGEMANAGER->addFrameImage("ClSpinpom", "image/enemy/cr/cl_spinpom.bmp", 0, 0, 1827, 426, 7, 2, true, RGB(255, 0, 255));

	//ġ��� �޺� 3��
	IMAGEMANAGER->addFrameImage("ClDoublepom", "image/enemy/cr/cl_doublepom.bmp", 0, 0, 2850, 816, 10, 4, true, RGB(255, 0, 255));

	//ġ��� ������
	IMAGEMANAGER->addFrameImage("ClBackflip", "image/enemy/cr/cl_backflip.bmp", 0, 0, 3060, 1836, 10, 6, true, RGB(255, 0, 255));

	//ġ��� �÷��̾ ����� ����
	IMAGEMANAGER->addFrameImage("ClWeponSwing", "image/enemy/cr/cl_weapon_swing2.bmp", 0, 0, 2604, 432, 7, 2, true, RGB(255, 0, 255));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//���л� �׺�
	IMAGEMANAGER->addFrameImage("SmBegging", "image/enemy/sb/sm_begging.bmp", 0, 0, 216, 354, 2, 2, true, RGB(255, 0, 255));

	//���л� �ٿ� �� ���
	IMAGEMANAGER->addFrameImage("SmBlownback", "image/enemy/sb/sm_blownback.bmp", 0, 0, 2970, 1260, 11, 6, true, RGB(255, 0, 255));

	//���л� ����
	IMAGEMANAGER->addFrameImage("SmDazed", "image/enemy/sb/sm_dazed.bmp", 0, 0, 422, 272, 4, 2, true, RGB(255, 0, 255));

	//���л� �ǰ�
	IMAGEMANAGER->addFrameImage("SmGetHit", "image/enemy/sb/sm_gethit.bmp", 0, 0, 1728, 450, 9, 2, true, RGB(255, 0, 255));

	//���л� �ȱ�
	IMAGEMANAGER->addFrameImage("SmWalk", "image/enemy/sb/sm_walk.bmp", 0, 0, 1620, 444, 12, 2, true, RGB(255, 0, 255));

	//���л� �⺻
	IMAGEMANAGER->addFrameImage("SmIdle", "image/enemy/sb/sm_idle.bmp", 0, 0, 1224, 432, 8, 2, true, RGB(255, 0, 255));

	//���л� �޸���
	IMAGEMANAGER->addFrameImage("SmRun", "image/enemy/sb/sm_run.bmp", 0, 0, 1920, 390, 10, 2, true, RGB(255, 0, 255));

	//���л� �÷��̾ ����� ����
	IMAGEMANAGER->addFrameImage("SmWeponSwing", "image/enemy/sb/sm_weapon_swing.bmp", 0, 0, 2646, 456, 7, 2, true, RGB(255, 0, 255));

	//���л� ����
	IMAGEMANAGER->addFrameImage("SmTaunt", "image/enemy/sb/sm_taunt.bmp", 0, 0, 1650, 456, 11, 2, true, RGB(255, 0, 255));

	//���л� �ٿ���
	IMAGEMANAGER->addFrameImage("SmKnockdown", "image/enemy/sb/sm_knockdown.bmp", 0, 0, 2970, 1260, 11, 6, true, RGB(255, 0, 255));

	//���л� �߰���
	IMAGEMANAGER->addFrameImage("SmKick", "image/enemy/sb/sm_kick.bmp", 0, 0, 1863, 558, 9, 2, true, RGB(255, 0, 255));

	//���л� ������ġ
	IMAGEMANAGER->addFrameImage("SmJumpPunch", "image/enemy/sb/sm_jump_punch.bmp", 0, 0, 1188, 456, 6, 2, true, RGB(255, 0, 255));

	//���л� ��� �޺� 1
	IMAGEMANAGER->addFrameImage("SmStPunch", "image/enemy/sb/sm_st_punch.bmp", 0, 0, 1764, 426, 7, 2, true, RGB(255, 0, 255));

	//���л� �޺�2����
	IMAGEMANAGER->addFrameImage("SmSideKick", "image/enemy/sb/sm_side_kick.bmp", 0, 0, 1764, 444, 7, 2, true, RGB(255, 0, 255));

	//���л� ������ �޺�3
	IMAGEMANAGER->addFrameImage("SmUpercut", "image/enemy/sb/sm_upercut.bmp", 0, 0, 1386, 510, 7, 2, true, RGB(255, 0, 255));

	//���л� ������ ���·� ��Ʈ��
	IMAGEMANAGER->addFrameImage("SmHoldhit", "image/enemy/sb/sm_heldhit.bmp", 0, 0, 576, 372, 3, 2, true, RGB(255, 0, 255));

	//���л� ��� ȸ��
	IMAGEMANAGER->addFrameImage("SmHoldrelease", "image/enemy/sb/sm_heldrelease.bmp", 0, 0, 589, 426, 4, 2, true, RGB(255, 0, 255));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//���л� �׺�
	IMAGEMANAGER->addFrameImage("SgBegging", "image/enemy/sg/sg_begging.bmp", 0, 0, 378, 336, 3, 2, true, RGB(255, 0, 255));

	//���л� �ٿ�
	IMAGEMANAGER->addFrameImage("SgBlowback", "image/enemy/sg/sg_blownback.bmp", 0, 0, 2925, 1080, 13, 6, true, RGB(255, 0, 255));

	//���л� ����
	IMAGEMANAGER->addFrameImage("SgDazed", "image/enemy/sg/sg_dazed.bmp", 0, 0, 456, 324, 4, 2, true, RGB(255, 0, 255));

	//���л� �ǰݸ��
	IMAGEMANAGER->addFrameImage("SgGethit", "image/enemy/sg/sg_gethit.bmp", 0, 0, 1431, 360, 9, 2, true, RGB(255, 0, 255));

	//���л� �ٿ���ݸ�����
	IMAGEMANAGER->addFrameImage("SgGroundhit", "image/enemy/sg/sg_groundhit.bmp", 0, 0, 639, 132, 3, 2, true, RGB(255, 0, 255));

	//���л� ���
	IMAGEMANAGER->addFrameImage("SgHold", "image/enemy/sg/sg_held.bmp", 0, 0, 1128, 360, 8, 2, true, RGB(255, 0, 255));

	//���л� �⺻
	IMAGEMANAGER->addFrameImage("SgIdle", "image/enemy/sg/sg_idle.bmp", 0, 0, 1170, 354, 10, 2, true, RGB(255, 0, 255));

	//���л� �Ϲݰ���
	IMAGEMANAGER->addFrameImage("SgJab", "image/enemy/sg/sg_jab.bmp", 0, 0, 1239, 354, 7, 2, true, RGB(255, 0, 255));

	//���л� ����
	IMAGEMANAGER->addFrameImage("SgJump", "image/enemy/sg/sg_jump.bmp", 0, 0, 333, 366, 3, 2, true, RGB(255, 0, 255));

	//���л� ���� ����
	IMAGEMANAGER->addFrameImage("SgJumpKnee", "image/enemy/sg/sg_jump_knee.bmp", 0, 0, 1197, 354, 7, 2, true, RGB(255, 0, 255));

	//���л� ���� �߰���
	IMAGEMANAGER->addFrameImage("SgKick", "image/enemy/sg/sg_kick.bmp", 0, 0, 2412, 414, 12, 2, true, RGB(255, 0, 255));

	//���л� �ٿ� �� ���
	IMAGEMANAGER->addFrameImage("SgKnockdown", "image/enemy/sg/sg_knockdown.bmp", 0, 0, 2925, 1080, 13, 6, true, RGB(255, 0, 255));

	//���л� �޸���
	IMAGEMANAGER->addFrameImage("SgRun", "image/enemy/sg/sg_run.bmp", 0, 0, 1470, 330, 10, 2, true, RGB(255, 0, 255));

	//���л� ����
	IMAGEMANAGER->addFrameImage("SgTaunt", "image/enemy/sg/sg_taunt.bmp", 0, 0, 2970, 732, 22, 4, true, RGB(255, 0, 255));

	//���л� �ȱ�
	IMAGEMANAGER->addFrameImage("SgWalk", "image/enemy/sg/sg_walk.bmp", 0, 0, 1296, 372, 12, 2, true, RGB(255, 0, 255));

	//���л� ����� ����
	IMAGEMANAGER->addFrameImage("SgWeaponSwing", "image/enemy/sg/sg_weapon_swing.bmp", 0, 0, 1708, 292, 6, 2, true, RGB(255, 0, 255));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	_EnemyShadow = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _EnemyShadowImage->getWidth(), _EnemyShadowImage->getHeight());

	_ShadowX = (_EnemyShadow.left + _EnemyShadow.right) / 2;
	_ShadowY = (_EnemyShadow.top + _EnemyShadow.bottom) / 2;

	_EnemyCore = RectMakeCenter(_ShadowX, _ShadowY - _EnemyCoreImage->getFrameHeight() / 2,
		_EnemyCoreImage->getFrameWidth(), _EnemyCoreImage->getFrameHeight());

	_CoreX = (_EnemyCore.left + _EnemyCore.right) / 2;
	_CoreY = (_EnemyCore.top + _EnemyCore.bottom) / 2;

	_EnemyPlayerExploration = RectMakeCenter(_CoreX, _CoreY, 800, 500);

	_EnemyAttackExploration = RectMakeCenter(_CoreX, _CoreY, 400, 200);

	int RIdle[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRightIdle", "CLIdle", RIdle, 12, 10, true);

	_ClMotion = KEYANIMANAGER->findAnimation("ClRightIdle");
	_ClMotion->start();

	_EnemyState = new EnemyIdleState;
	_EnemyState->Enter(*this);


	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	EnemyState* EnemySt = _EnemyState->Update(*this);

	if(EnemySt != nullptr)
	{
		_EnemyState->Exit(*this);
		EnemySt->Enter(*this);
		delete _EnemyState;
		_EnemyState = EnemySt;
	}

////////////////////////////////////////////////////////////////////////

	_ShadowX = (_EnemyShadow.left + _EnemyShadow.right) / 2;
	_ShadowY = (_EnemyShadow.top + _EnemyShadow.bottom) / 2;

	_EnemyCore = RectMakeCenter(_ShadowX, _ShadowY - _EnemyCoreImage->getFrameHeight() / 2,
		_EnemyCoreImage->getFrameWidth(), _EnemyCoreImage->getFrameHeight());

	_CoreX = (_EnemyCore.left + _EnemyCore.right) / 2;
	_CoreY = (_EnemyCore.top + _EnemyCore.bottom) / 2;

	_EnemyPlayerExploration = RectMakeCenter(_CoreX, _CoreY, 800, 500);

	_EnemyAttackExploration = RectMakeCenter(_CoreX, _CoreY, 400, 200);
}

void Enemy::render()
{
	Rectangle(getMemDC(), _EnemyPlayerExploration);
	Rectangle(getMemDC(), _EnemyAttackExploration);
	Rectangle(getMemDC(), _EnemyCore);
	_EnemyShadowImage->render(getMemDC(), _EnemyShadow.left, _EnemyShadow.top);
	_EnemyCoreImage->aniRender(getMemDC(), _EnemyCore.left, _EnemyCore.top, _ClMotion);
	_EnemyState->Render(*this);
}
