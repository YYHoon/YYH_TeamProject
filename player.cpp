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
	IMAGEMANAGER->addFrameImage("PlayerAttack3", "Player/Kyoko_ComboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));
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

	//배틀스타트
	int lBattleStart[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftBattleStart", "PlayerBattleStart", lBattleStart, 26, 15, false);
	int rBattleStart[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightBattleStart", "PlayerBattleStart", rBattleStart, 26, 15, false);

	//아이들
	int lIdele[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftIdle", "PlayerIdle", lIdele, 12, 10, true);
	int rIdle[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightIdle", "PlayerIdle", rIdle, 12, 10, true);

	//걷기
	int lWalk[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftWalk", "PlayerWalk", lWalk, 12, 10, true);
	int rWalk[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightWalk", "PlayerWalk", rWalk, 12, 10, true);

	//달리기
	int lRun[] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftRun", "PlayerRun", lRun, 16, 6, true);
	int rRun[] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightRun", "PlayerRun", rRun, 16, 6, true);

	//평타1
	int lAttack1[] = { 5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack1", "PlayerAttack1", lAttack1, 6, 10, false);
	int rAttack1[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack1", "PlayerAttack1", rAttack1, 6, 10, false);

	//평타2
	int lAttack2[] = { 6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack2", "PlayerAttack2", lAttack2, 7, 10, false);
	int rAttack2[] = { 7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack2", "PlayerAttack2", rAttack2, 7, 10, false);

	//평타3
	int lAttack3[] = { 8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack3", "PlayerAttack3", lAttack3, 9, 10, false);
	int rAttack3[] = { 9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack3", "PlayerAttack3", rAttack3, 9, 10, false);

	//피격
	int lHit[] = { 1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftHit", "PlayerHit", lHit, 2, 6, false);
	int rHit[] = { 2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightHit", "PlayerHit", rHit, 2, 6, false);

	//다운
	int lDown[] = { 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDown", "PlayerDown", lDown, 24, 10, false);
	int rDown[] = { 24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDown", "PlayerDown", rDown, 24, 10, false);

	//가드
	int lGuard[] = { 2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGuard", "PlayerGuard", lGuard, 3, 6, false);
	int rGuard[] = { 3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGuard", "PlayerGuard", rGuard, 3, 6, false);

	//다이빙공격
	int lDive[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDiveAttack", "PlayerDiveAttack", lDive, 21, 6, false);
	int rDive[] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDiveAttack", "PlayerDiveAttack", rDive, 21, 6, false);

	//게임오버
	int lGameOver[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGameOver", "PlayerGameOver", lGameOver, 26, 6, false);
	int rGameOver[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGameOver", "PlayerGameOver", rGameOver, 26, 6, false);

	//허리케인킥
	int HKick[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerHurrKick", "PlayerHKick", HKick, 24, 6, false);

	//기상
	int lStandUp[] = { 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStandUp", "PlayerStandUp", lStandUp, 17, 6, false);
	int rStandUp[] = { 17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStandUp", "PlayerStandUp", rStandUp, 17, 6, false);

	//밟기
	int lStomp[] = { 9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStomp", "PlayerStomp", lStomp, 10, 6, false);
	int rStomp[] = { 10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStomp", "PlayerStomp", rStomp, 10, 6, false);

	//기절
	int lStnned[] = { 3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStnned", "PlayerStnned", lStnned, 4, 6, false);
	int rStnned[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStnned", "PlayerStnned", rStnned, 4, 6, false);

	//댑
	int lDap[] = { 24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDap", "PlayerDap", lDap, 25, 6, false);
	int rDap[] = { 25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDap", "PlayerDap", rDap, 25, 6, false);

	//점프
	int lJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftJump", "PlayerJump", lJump, 2, 5, false);
	int rJump[] = { 4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightJump", "PlayerJump", rJump, 2, 5, false);

	//착지
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
	_Speed = 5;
	_MoveLR = MOVELR::NON;
	_MoveUD = MOVEUD::NON;
	
	_State->SetCenterXY(_Center);
	_State->Init();
	Default();

	
	return S_OK;

}

void Player::Update()
{
	if (_State == BattleStart::GetInstance() && !_State->GetAniIsPlay())
	{
		_State = PlayRightIdle::GetInstance();
		Default();
	}
	if (_State != BattleStart::GetInstance())
	{
		AttackUpdate();
		PlayerKeyMove();
	}
	
	if (_State != BattleStart::GetInstance() && !_State->GetAniIsPlay())Default();
	

	if (_AttackCount < 0 || _AttackCount>2)_AttackCount = 0;



	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));
	_PlayerHitRc.set(_Center.x - 64, _Center.y - 200, _Center.x + 64, _Center.y);
	_State->SetCenterXY(_Center);
	_State->Update();
}

void Player::Release()
{
}

void Player::Render()
{
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))DebugRender();
	
	_Shadow->render(getMemDC(),_ShadowRc.left,_ShadowRc.top);
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
	
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_State = PlayLeftIdle::GetInstance();
		Walk();
		_State->SetLeft(true);
		_MoveLR = MOVELR::LEFT_WALK;
		_LClickTime++;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_State = PlayLeftIdle::GetInstance();
		Default();
		_MoveLR = MOVELR::NON;
		_LClickTime++;
	}
	
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_State = PlayRightIdle::GetInstance();
		Walk();
		_State->SetLeft(false);
		_MoveLR = MOVELR::RIGHT_WALK;
		
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		Default();
		_MoveLR = MOVELR::NON;
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		if (_State->GetLeft())_State = PlayLeftIdle::GetInstance();
		if (!_State->GetLeft())_State = PlayRightIdle::GetInstance();
		Walk();
		_MoveUD = MOVEUD::UP_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		_State->SetLeft(true);
		_MoveUD = MOVEUD::NON;
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (_State->GetLeft())_State = PlayLeftIdle::GetInstance();
		if (!_State->GetLeft())_State = PlayRightIdle::GetInstance();
		Walk();
		_MoveUD = MOVEUD::DOWN_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{

		_MoveUD = MOVEUD::NON;
	}
	


	MoveUpdate();
}

void Player::MoveUpdate()
{
	switch (_MoveLR)
	{
	case MOVELR::LEFT_WALK:
		_Center.x -= _Speed;
		break;
	case MOVELR::RIGHT_WALK:
		_Center.x += _Speed;
		break;
	case MOVELR::LEFT_RUN:
		_Center.x -= _Speed*1.5f;
		break;
	case MOVELR::RIGHT_RUN:
		_Center.x += _Speed*1.5f;
		break;
	case MOVELR::NON:
		break;
	}
	switch (_MoveUD)
	{
	case MOVEUD::UP_WALK:
		_Center.y -= (_Speed * 0.5f);
		break;
	case MOVEUD::DOWN_WALK:
		_Center.y += (_Speed * 0.5f);
		break;
	case MOVEUD::UP_RUN:
		_Center.y -= _Speed;
		break;
	case MOVEUD::DOWN_RUN:
		_Center.y += _Speed;
		break;
	case MOVEUD::NON:
		break;
	}
}

void Player::AttackUpdate()
{
	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		//if (_State->GetLeft())_State = PlayLeftIdle::GetInstance();
		//if (!_State->GetLeft())_State = PlayRightIdle::GetInstance();
		if (_AttackCount == 0 && _State->GetAniIndex() > 4)
		{

			Attack1();
			cout << _State->GetAttRect().left << endl;
			_AttackCount++;
			_State->SetAttRect();
		}
		else if (_AttackCount == 1&&_State->GetAniIndex()>4)
		{

			Attack2();
			cout << _State->GetAttRect().left << endl;
			_AttackCount++;
			_State->SetAttRect();
		}

		else if (_AttackCount == 2 && _State->GetAniIndex() > 5)
		{

			Attack3();
			cout << _State->GetAttRect().left << endl;
			_AttackCount++;
			_State->SetAttRect();
		}
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
	}
	

}

void Player::DashUpdate()
{
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

void Player::Guard()
{
}

void Player::GameOver()
{
}

void Player::DiveAttack()
{
}

void Player::Default()
{
	_State->Default(this);
}


void Player::SetState(State* state)
{
	this->_State = state;
}


