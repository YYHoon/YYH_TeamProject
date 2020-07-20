#pragma once
#include "EnemyState.h"

class EnemyRunState : public EnemyState
{
private:
	image* _ClRunimage;
	animation* _ClRunAin;

public:

	EnemyRunState() {}
	~EnemyRunState() {}

	virtual void Enter(Enemy& enemy);

	virtual void Exit(Enemy& enemy);

	virtual EnemyState* Update(Enemy& enemy);

	virtual void Render(Enemy& enemy);

	virtual bool IsStop() { return false; }
};