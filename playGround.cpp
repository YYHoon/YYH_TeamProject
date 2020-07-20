#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);
	
	imginit(); // 모든 이미지를 여기다 넣도록


	_SM = new StageManager;
	_SM->init();

	

	return S_OK;
}

//메모리 해제
void playGround::release()
{
	
}

//연산
void playGround::update()
{
	gameNode::update();

	_SM->update();
}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=================================================

	SCENEMANAGER->render();
	_SM->render();

	TIMEMANAGER->render(getMemDC());
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	IMAGEMANAGER->addImage("Player", "image/Player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));
}
