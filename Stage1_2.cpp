#include "stdafx.h"
#include "Stage1_2.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT Stage1_2::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_2");
	_LeftExit.centerSet(50, 450, 250, 400);
	_RightExit.centerSet(2710, 450, 250, 400);
	_IsOnceClear = true;


	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2860, 1040);
	return S_OK;
}

void Stage1_2::render()
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
