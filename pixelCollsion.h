#pragma once
#include "gameNode.h"

class pixelCollsion : public gameNode
{
private:
	image* _hill;	//언덕 이미지
	image* _ball;	//볼 이미지

	RECT _rc;		//볼이 사용할 렉트

	float _x, _y;	//볼의 중점좌표

	RECT _rc2;
	float speed;
	int _probeY;	//Y축 탐사
	int _probeX;	//X축 탐사
	bool collision; // 픽셀끼리 충돌했을때

public:
	pixelCollsion();
	~pixelCollsion();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void PixelCollisionTest();

};

