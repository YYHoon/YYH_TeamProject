#pragma once
#include"Player.h"

class State
{
protected:
	State* _State;

public:
	State() {};
	virtual ~State() {};

	virtual void Walk(Player* player) = 0;
	virtual void Run(Player* player) = 0;
	virtual void Jump(Player* player) = 0;
	virtual void Attack(Player* player) = 0;
	virtual void Hit(Player* player) = 0;
	virtual void Stun(Player* player) = 0;
	virtual void StandUp(Player* player) = 0;

	inline State* GetState() { return _State; }
	inline void SetState(State* state) { _State = state; }

};


class PlayLeftIdle : public State
{
private:

	static PlayLeftIdle* _Instance;

public:
	PlayLeftIdle() {};
	virtual ~PlayLeftIdle() {};

	static PlayLeftIdle* GetInstance();

	virtual void Walk(Player* player);
	virtual void Run(Player* player);
	virtual void Jump(Player* player);
	virtual void Attack(Player* player);
	virtual void Hit(Player* player);
	virtual void Stun(Player* player);
	virtual void StandUp(Player* player);

};
class PlayRightIdle : public State
{
private:

	static PlayRightIdle* _Instance;

public:
	PlayRightIdle() {};
	virtual ~PlayRightIdle() {};

	static PlayRightIdle* GetInstance();

	virtual void Walk(Player* player);
	virtual void Run(Player* player);
	virtual void Jump(Player* player);
	virtual void Attack(Player* player);
	virtual void Hit(Player* player);
	virtual void Stun(Player* player);
	virtual void StandUp(Player* player);

};
///////////////////////////////////////////////////////