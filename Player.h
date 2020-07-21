#pragma once
#include "gameNode.h"

class State;

class Player : public gameNode
{
private:
	State* _State;

	animation* _ani;

	bool _Left;

public:

	Player();
	virtual ~Player() {};

	virtual HRESULT Init();
	//virtual void Update();
	//virtual void Release();
	//virtual void Render();



	virtual void Walk();
	virtual void Run();
	virtual void Jump();
	virtual void Attack();
	virtual void Hit();
	virtual void Stun();
	virtual void StandUp();



	inline bool GetPlayerDirection() { return _Left; }


	void SetState(State* state);
};
