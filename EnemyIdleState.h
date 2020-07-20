#pragma once
#include "EnemyState.h"

class EnemyIdleState : public EnemyState
{
private:
	image* _ClIdle;
	animation* _ClidleAni;

public:
	EnemyIdleState() {}
	~EnemyIdleState() {}

	virtual void Enter(Enemy& enemy);

	virtual void Exit(Enemy& enemy);

	virtual EnemyState* Update(Enemy& enemy);

	virtual void Render(Enemy& enemy);

	virtual bool IsStop() { return false; }

};