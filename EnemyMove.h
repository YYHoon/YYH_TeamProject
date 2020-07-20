#pragma once
#include "EnemyState.h"


class EnemyMove : public EnemyState
{
private:
	image* _ClMoveimage;
	animation* _ClMoveAin;

public:
	EnemyMove() {}
	~EnemyMove() {}

	virtual void Enter(Enemy& enemy);

	virtual void Exit(Enemy& enemy);

	virtual EnemyState* Update(Enemy& enemy);

	virtual void Render(Enemy& enemy);

	virtual bool IsStop() { return false; }

};