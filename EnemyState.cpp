#include "stdafx.h"
#include "EnemyState.h"
#include "Enemy.h"


void EnemyState::Enter(Enemy& enemy)
{
}

void EnemyState::Exit(Enemy& enemy)
{
}

EnemyState* EnemyState::Update(Enemy& enemy)
{
	return nullptr;
}

void EnemyState::Render(Enemy& enemy)
{
}

bool EnemyState::IsStop()
{
	return false;
}
