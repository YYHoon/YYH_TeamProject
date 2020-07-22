#pragma once
#include "gameNode.h"
#include "EnemyManager.h"


class playGround : public gameNode
{
private:
	EnemyManager* ENE;
	vector<TagEnemySpawn> _spawn;
	
	MYRECT te1;

	MYRECT te2;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy();

};

