#include "stdafx.h"
#include "Stage1_1.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT Stage1_1::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_1");
	_LeftExit.centerSet(1270, 300, 300, 400);
	_RightExit.centerSet(2150, 500, 200, 400);

	_IsOnceClear = true;

	CAMERAMANAGER->setConfig(0, -200, WINSIZEX, WINSIZEY, 0, 0, 2400, 1064);
	return S_OK;
}

void Stage1_1::render()
{
	CAMERAMANAGER->render(getMemDC(), _Img, 0, -100);
	CAMERAMANAGER->render(getMemDC(), _Player->GetImage(), _Player->GetCollision().left, _Player->GetCollision().top);
	CAMERAMANAGER->rectangle(getMemDC(), _Player->GetCollision());
	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
	CAMERAMANAGER->setX(_Player->GetCenter().x);
	CAMERAMANAGER->setY(_Player->GetCenter().y);

	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
}
