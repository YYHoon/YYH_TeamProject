#pragma once
#include "gameNode.h"

class Enemy;

class EnemyState : public gameNode
{
private:


public:
	EnemyState() {}
	~EnemyState() {}

	virtual void Enter(Enemy& enemy);

	virtual void Exit(Enemy& enemy);

	virtual EnemyState* Update(Enemy& enemy);

	virtual void Render(Enemy& enemy);

	virtual bool IsStop();
};