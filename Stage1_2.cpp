#include "stdafx.h"
#include "Stage1_2.h"
#include "Player.h"
#include "AllObstacle.h"
#include "Event.h"

HRESULT Stage1_2::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_2");
	_LeftExit.centerSet(50, 450, 250, 400);
	_RightExit.centerSet(2710, 450, 250, 400);
	_EventCenterSpot.x = _Img->getWidth() / 2;
	_EventCenterSpot.y = 560;
	_EventArea.centerSet(_EventCenterSpot.x, _EventCenterSpot.y, 1300, 500);
	_IsOnceClear = false;
	_IsEventPlay = false;

	

	_Ev = new StopCamera;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2860, 1040);
	return S_OK;
}

void Stage1_2::render()
{
	cout << _IsEventPlay << endl;
	EventScript();
	CAMERAMANAGER->render(getMemDC(), _Img, 0, -100);
	CAMERAMANAGER->render(getMemDC(), _Player->GetImage(), _Player->GetCollision().left, _Player->GetCollision().top);
	CAMERAMANAGER->rectangle(getMemDC(), _Player->GetCollision());
	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
	if (!_IsEventPlay)
	{
		CAMERAMANAGER->setX(_Player->GetCenter().x);
		CAMERAMANAGER->setY(_Player->GetCenter().y);
	}
	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}

}

void Stage1_2::EventScript()
{
	if (IsInEventArea())
	{
		_IsEventPlay = true;
		_Ev->EventStart(_EventCenterSpot.x, _EventCenterSpot.y);
		
	}
	/*
		if(Enemy.size() == 0)
		WaveCount++;
		if(WaveCount > 4)_IsEventPlay = false;
	*/
}


