#include "stdafx.h"
#include "State.h"

PlayLeftIdle* PlayLeftIdle::_Instance;
PlayRightIdle* PlayRightIdle::_Instance;


////////////////////���̵�
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
	cout << "����" << endl;
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
///////////////////////���̵� ���� ����Ʈ �Ʒ��¶���Ʈ

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
//////////////////////���̵�

void State::Render(Player* player)
{
	
}
