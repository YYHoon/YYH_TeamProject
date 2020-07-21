#pragma once
#include "gameNode.h"

class State;

class Player : public gameNode
{
private:
	State* _State;

	image* _PlayerImg;
	animation* _PlayerAni;
	POINTFLOAT _Center;
	MYRECT _PlayerRc;
	float _Speed;
	float _Gravity;
	float _Jump;
	float _JumpMax;

	bool _Left;

public:

	Player();
	virtual ~Player() {};

	virtual void PlayerImageAniStting();
	//플레이어 이미지 애니메이션 셋팅 함수


	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
	virtual void Render();

	virtual void PlayerKeyManager();


	virtual void BattleStart();
	virtual void Idle();
	virtual void Walk();
	virtual void Run();
	virtual void Jump();
	virtual void Attack();
	virtual void Hit();
	virtual void Stun();
	virtual void StandUp();



	inline bool GetPlayerDirection() { return _Left; }
	inline float GetPlayerCenterX() { return _Center.x; }
	inline float GetPlayerCenterY() { return _Center.y; }

	inline void SetPlayerCenterX(POINTFLOAT X) { _Center.x = X.x; }
	inline void SetPlayerCenterY(POINTFLOAT Y) { _Center.x = Y.y; }
	void SetState(State* state);
};
