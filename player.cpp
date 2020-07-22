#include "stdafx.h"
#include "player.h"
#include "State.h"

Player::Player()
{
	_State = BattleStart::GetInstance();
}

void Player::PlayerImageAniStting()
{
	IMAGEMANAGER->addFrameImage("PlayerBattleStart", "Player/Kyoko_BattleStart.bmp", 2964, 420, 26, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerIdle", "Player/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerWalk", "Player/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerRun", "Player/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack1", "Player/Kyoko_ComboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack2", "Player/Kyoko_ComboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack3", "Player/Kyoko_ComboAttack3.bmp", 2970, 462, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerHit", "Player/Kyoko_Hit.bmp", 246, 348, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDown", "Player/Kyoko_Down.bmp", 4896, 366, 24, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerGuard", "Player/Kyoko_Guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDiveAttack", "Player/Kyoko_Dive.bmp", 5040, 360, 21, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerGameOver", "Player/Kyoko_GameOver.bmp", 6240, 282, 26, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerHKick", "Player/Kyoko_HurricaneKick.bmp", 2997, 657, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStandUp", "Player/Kyoko_StandUp.bmp", 3315, 330, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStomp", "Player/Kyoko_Stomp.bmp", 1290, 420, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStnned", "Player/Kyoko_Stunned.bmp", 384, 384, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDap", "Player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerJump", "Player/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("PlayerShadow", "Player/KyoKo_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));

	//��Ʋ��ŸƮ
	int lBattleStart[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftBattleStart", "PlayerBattleStart", lBattleStart, 26, 15, false);
	int rBattleStart[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightBattleStart", "PlayerBattleStart", rBattleStart, 26, 15, false);

	//���̵�
	int lIdele[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftIdle", "PlayerIdle", lIdele, 12, 10, true);
	int rIdle[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightIdle", "PlayerIdle", rIdle, 12, 10, true);

	//�ȱ�
	int lWalk[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftWalk", "PlayerWalk", lWalk, 12, 10, true);
	int rWalk[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightWalk", "PlayerWalk", rWalk, 12, 10, true);

	//�޸���
	int lRun[] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftRun", "PlayerRun", lRun, 16, 6, true);
	int rRun[] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightRun", "PlayerRun", rRun, 16, 6, true);

	//��Ÿ1
	int lAttack1[] = { 5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack1", "PlayerAttack1", lAttack1, 6, 6, false);
	int rAttack1[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack1", "PlayerAttack1", rAttack1, 6, 6, false);

	//��Ÿ2
	int lAttack2[] = { 6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack2", "PlayerAttack2", lAttack2, 7, 6, false);
	int rAttack2[] = { 7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack2", "PlayerAttack2", rAttack2, 7, 6, false);

	//��Ÿ3
	int lAttack3[] = { 7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack3", "PlayerAttack3", lAttack3, 8, 6, false);
	int rAttack3[] = { 8,9,10,11,12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack3", "PlayerAttack3", rAttack3, 8, 6, false);

	//�ǰ�
	int lHit[] = { 1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftHit", "PlayerHit", lHit, 2, 6, false);
	int rHit[] = { 2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightHit", "PlayerHit", rHit, 2, 6, false);

	//�ٿ�
	int lDown[] = { 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDown", "PlayerDown", lDown, 24, 10, false);
	int rDown[] = { 24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDown", "PlayerDown", rDown, 24, 10, false);

	//����
	int lGuard[] = { 2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGuard", "PlayerGuard", lGuard, 3, 6, false);
	int rGuard[] = { 3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGuard", "PlayerGuard", rGuard, 3, 6, false);

	//���̺�����
	int lDive[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDiveAttack", "PlayerDiveAttack", lDive, 21, 6, false);
	int rDive[] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDiveAttack", "PlayerDiveAttack", rDive, 21, 6, false);

	//���ӿ���
	int lGameOver[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGameOver", "PlayerGameOver", lGameOver, 26, 6, false);
	int rGameOver[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGameOver", "PlayerGameOver", rGameOver, 26, 6, false);

	//�㸮����ű
	int HKick[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerHurrKick", "PlayerHKick", HKick, 24, 6, false);

	//���
	int lStandUp[] = { 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStandUp", "PlayerStandUp", lStandUp, 17, 6, false);
	int rStandUp[] = { 17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStandUp", "PlayerStandUp", rStandUp, 17, 6, false);

	//���
	int lStomp[] = { 9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStomp", "PlayerStomp", lStomp, 10, 6, false);
	int rStomp[] = { 10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStomp", "PlayerStomp", rStomp, 10, 6, false);

	//����
	int lStnned[] = { 3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStnned", "PlayerStnned", lStnned, 4, 6, false);
	int rStnned[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStnned", "PlayerStnned", rStnned, 4, 6, false);

	//��
	int lDap[] = { 24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDap", "PlayerDap", lDap, 25, 6, false);
	int rDap[] = { 25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDap", "PlayerDap", rDap, 25, 6, false);

	//����
	int lJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftJump", "PlayerJump", lJump, 2, 5, false);
	int rJump[] = { 4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightJump", "PlayerJump", rJump, 2, 5, false);

	//����
	int lFall[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftFall", "PlayerJump", lFall, 1, 5, false);
	int rFall[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightFall", "PlayerJump", rFall, 1, 5, false);

}

HRESULT Player::Init()
{
	PlayerImageAniStting();
	_Center.x = 300;
	_Center.y = 300;
	_Shadow = IMAGEMANAGER->findImage("PlayerShadow");
	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));
	_PlayerHitRc.set(_Center.x - 64, _Center.y - 200, _Center.x + 64, _Center.y);

	_State->SetCenterXY(_Center);
	_State->Init();
	Default();


	return S_OK;

}

void Player::Update()
{
	PlayerKeyMove();
	_State->Update();

	if (_State == BattleStart::GetInstance() && !_State->GetAniIsPlay())
	{
		_State = PlayRightIdle::GetInstance();
		Default();
	}



	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));
	_PlayerHitRc.set(_Center.x - 64, _Center.y - 200, _Center.x + 64, _Center.y);
	_State->SetCenterXY(_Center);
}

void Player::Release()
{
}

void Player::Render()
{
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))DebugRender();
	_State->Render();

}

void Player::DebugRender()
{
	CAMERAMANAGER->rectangle(getMemDC(), _PlayerHitRc);
	CAMERAMANAGER->rectangle(getMemDC(), _ShadowRc);
	_State->DebugRender();
}

void Player::PlayerKeyMove()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_Center.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_Center.y += 2;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_Center.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_Center.y -= 2;
	}
}

void Player::Walk()
{
	_State->Walk(this);
}

void Player::Attack1()
{
	_State->Attack1(this);
}

void Player::Attack2()
{
	_State->Attack2(this);
}

void Player::Attack3()
{
	_State->Attack3(this);
}

void Player::StandUp()
{
	_State->StandUp(this);
}

void Player::Skill1()
{
	_State->Skill1(this);
}

void Player::Skill2()
{
	_State->Skill2(this);
}

void Player::Default()
{
	_State->Default(this);
}


void Player::SetState(State* state)
{
	this->_State = state;
}
