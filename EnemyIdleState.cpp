#include "stdafx.h"
#include "EnemyAllState.h"
#include "Enemy.h"

void EnemyIdleState::Enter(Enemy& enemy)
{
	_ClIdle = IMAGEMANAGER->findImage("CLIdle");
	
	int ClRIdle[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	KEYANIMANAGER->addArrayFrameAnimation("ClRIdle", "CLIdle", ClRIdle, 12, 10, true);

	int ClLIdle[] = {23,22,21,20,19,18,17,16,15,14,13,12};
	KEYANIMANAGER->addArrayFrameAnimation("ClLIdle", "CLIdle", ClLIdle, 12, 10, true);

	_ClidleAni = KEYANIMANAGER->findAnimation("ClRIdle");
}

void EnemyIdleState::Exit(Enemy& enemy)
{
	SAFE_DELETE(_ClidleAni);
}

EnemyState* EnemyIdleState::Update(Enemy& enemy)
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (enemy.GetDirection() == DIRECTION::LEFT)
		{
			enemy.SetDirection(DIRECTION::RIGHT);
			_ClidleAni = KEYANIMANAGER->findAnimation("ClRIdle");
			_ClidleAni->start();
		}
		return new EnemyMove;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (enemy.GetDirection() == DIRECTION::RIGHT)
		{
			enemy.SetDirection(DIRECTION::LEFT);
			_ClidleAni = KEYANIMANAGER->findAnimation("ClLIdle");
			_ClidleAni->start();
		}
		return new EnemyMove;
	}

	return nullptr;
}

void EnemyIdleState::Render(Enemy& enemy)
{
	RECT hit = enemy.GetEnemyHit();



}