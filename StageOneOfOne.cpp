#include "stdafx.h"
#include "StageOneOfOne.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT StageOneOfOne::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_1");
	_LeftExit.centerSet(1270, 500, 50, 50);
	_RightExit.centerSet(2150, 600, 100, 100);

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2400, 1064);


	return S_OK;
}
