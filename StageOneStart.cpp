#include "stdafx.h"
#include "StageOneStart.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT StageOneStart::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");

	//_Player->GetCenter();

	_RightExit.set(1400, 400, 1450, 450);

	ParentsObstacle* Desk1 = new Desk;
	Desk1->init(400, 400);
	_vObstacle.push_back(Desk1);

	ParentsObstacle* Desk2 = new Desk;
	Desk2->init(800, 500);
	_vObstacle.push_back(Desk2);

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016, 672);

	return S_OK;
}

void StageOneStart::render()
{
	CAMERAMANAGER->render(getMemDC(), _Img, 0, 0);
	//CAMERAMANAGER->render(getMemDC(), _Player->GetImage(), _Player->GetCollision().left, _Player->GetCollision().top);

	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}

}

