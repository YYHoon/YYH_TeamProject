#include "stdafx.h"
#include "StageOneStart.h"

HRESULT StageOneStart::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");

	_Exit[0].set(1400, 400, 1450, 450);

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016, 672);

	return S_OK;
}

void StageOneStart::update()
{


}

void StageOneStart::render()
{
	
	//IMAGEMANAGER->render("Stage1_Start", getMemDC());
	CAMERAMANAGER->render(getMemDC(), _Img,0,0);

}
