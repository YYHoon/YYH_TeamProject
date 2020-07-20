#include "stdafx.h"
#include "EnemyMove.h"
#include "Enemy.h"

void EnemyMove::Enter(Enemy& enemy)
{
	_ClMoveimage = IMAGEMANAGER->findImage("ClWalk");

	int ClRMove[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRMove", "ClWalk", ClRMove, 12, 10, true);

	int ClLMove[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLMove", "ClWalk", ClLMove, 12, 10, true);

	KEYANIMANAGER->findAnimation("ClRMove");
}

void EnemyMove::Exit(Enemy& enemy)
{
	_ClMoveAin->release();
	SAFE_DELETE(_ClMoveAin);
}

EnemyState* EnemyMove::Update(Enemy & enemy)
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if(enemy.GetDirection() == DIRECTION::LEFT)
		{
			enemy.SetDirection(DIRECTION::RIGHT);
		}
			 KEYANIMANAGER->findAnimation("ClRMove");
			_ClMoveAin->start();
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (enemy.GetDirection() == DIRECTION::RIGHT)
		{
			enemy.SetDirection(DIRECTION::LEFT);
		}
			_ClMoveAin = KEYANIMANAGER->findAnimation("ClLMove");
			_ClMoveAin->start();
	}
	return nullptr;
}

void EnemyMove::Render(Enemy& enemy)
{

}
