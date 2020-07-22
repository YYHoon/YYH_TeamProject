#include "stdafx.h"
#include "Stage1_Start.h"
#include "Player.h"
#include "AllObstacle.h"
#include "Merge.h"

HRESULT Stage1_Start::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");
	ZM = new Merge;
	_Player->GetCenter();

	_RightExit.centerSet(1435, 250, 300, 300);

	ParentsObstacle* Desk1 = new Desk;
	Desk1->init(400, 400);
	_vObstacle.push_back(Desk1);

	ParentsObstacle* Desk2 = new Desk;
	Desk2->init(800, 500);
	_vObstacle.push_back(Desk2);

	_IsOnceClear = true;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016, 672);
	
	return S_OK;
}

void Stage1_Start::render()
{
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		int y = RND->getFromIntTo(100, 500);
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new Desk;
		i->init(x, y);
		_vObstacle.push_back(i);
	}


	CAMERAMANAGER->render(getMemDC(), _Img, 0, 0);
	CAMERAMANAGER->render(getMemDC(), _Player->GetImage(), _Player->GetCollision().left, _Player->GetCollision().top);
	CAMERAMANAGER->rectangle(getMemDC(), _Player->GetCollision());
	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);


	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	
	}
}

