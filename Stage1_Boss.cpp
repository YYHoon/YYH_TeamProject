#include "stdafx.h"
#include "Stage1_Boss.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT Stage1_Boss::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Boss");

	CAMERAMANAGER->setConfig(0, -200, WINSIZEX, WINSIZEY, 0, 0, 2769, 1280);
	return S_OK;
}

void Stage1_Boss::render()
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
