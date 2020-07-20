#include "stdafx.h"
#include "EnemyAllState.h"
#include "Enemy.h"


void EnemyRunState::Enter(Enemy& enemy)
{
	_ClRunimage = IMAGEMANAGER->findImage("ClRun");

	int ClRrun[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRMove", "ClWalk", ClRrun, 8, 10, true);

	int ClLrun[] = { 15,14,13,12,11,10,9,8 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLMove", "ClWalk", ClLrun, 8, 10, true);

	KEYANIMANAGER->findAnimation("ClRrun");

	//_ClRunAin;
}

void EnemyRunState::Exit(Enemy& enemy)
{
}

EnemyState* EnemyRunState::Update(Enemy& enemy)
{
	return nullptr;
}

void EnemyRunState::Render(Enemy& enemy)
{
}
