#pragma once
#include "Object.h"

class Player : public Object
{
protected:

public:
	Player();
	~Player();

	HRESULT init(float spawnX, float spawnY);
	void release();
	void update();
	void render();

	void move();
};

