#include "stdafx.h"
#include "State.h"

PlayLeftIdle* PlayLeftIdle::_Instance;
PlayRightIdle* PlayRightIdle::_Instance;


////////////////////아이들
PlayLeftIdle* PlayLeftIdle::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftIdle;
	}
	return _Instance;
}

void PlayLeftIdle::BattleStart(Player* player)
{
}

void PlayLeftIdle::Idle(Player* player)
{
	
}

void PlayLeftIdle::Walk(Player* player)
{
	cout << "씨발" << endl;
}

void PlayLeftIdle::Run(Player* player)
{
}

void PlayLeftIdle::Jump(Player* player)
{
}

void PlayLeftIdle::Attack(Player* player)
{
}

void PlayLeftIdle::Hit(Player* player)
{
}

void PlayLeftIdle::Stun(Player* player)
{
}

void PlayLeftIdle::StandUp(Player* player)
{
}
///////////////////////아이들 위는 레프트 아래는라이트

PlayRightIdle* PlayRightIdle::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightIdle;
	}
	return _Instance;
}

void PlayRightIdle::BattleStart(Player* player)
{
}

void PlayRightIdle::Idle(Player* player)
{
}

void PlayRightIdle::Walk(Player* player)
{
}

void PlayRightIdle::Run(Player* player)
{
}

void PlayRightIdle::Jump(Player* player)
{
}

void PlayRightIdle::Attack(Player* player)
{
}

void PlayRightIdle::Hit(Player* player)
{
}

void PlayRightIdle::Stun(Player* player)
{
}

void PlayRightIdle::StandUp(Player* player)
{
}
//////////////////////아이들

void State::Render(Player* player)
{
	
}
