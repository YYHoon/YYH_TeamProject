#pragma once
#include "gameNode.h"

class State;

class Player : public gameNode
{
private:
	State* _State;

	image* _Shadow;
	POINTFLOAT _Center;
	MYRECT _ShadowRc;
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
	virtual void DebugRender();
	virtual void PlayerKeyMove();


	virtual void Walk();
	virtual void Attack1();
	virtual void Attack2();
	virtual void Attack3();
	virtual void StandUp();
	virtual void Skill1();
	virtual void Skill2();
	virtual void Default();



	inline bool GetPlayerDirection() { return _Left; }
	inline float GetShadowCenterX() { return _Center.x; }
	inline float GetShadowCenterY() { return _Center.y; }
	inline POINTFLOAT GetShadowCenterPoint() { return _Center; }
	inline MYRECT GetShadowRect() { return _ShadowRc; }
	//inline MYRECT GetPlayerRect() { return _State->GetRect(); }//ㅡㄹ레이어피격렉트


	inline void SetShadowCenterX(POINTFLOAT XY) {
		_Center.x = XY.x;
		_Center.y = XY.y;
	}

	void SetState(State* state);
};
