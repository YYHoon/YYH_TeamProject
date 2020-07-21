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
	SCENEMANAGER->addScene("LoadingScene", new LoadingScene);
	SCENEMANAGER->addScene("IntroMenuScene", new IntroMenuScene);
	SCENEMANAGER->addScene("SelectMenuScene", new SelectMenuScene);
	SCENEMANAGER->addScene("VideoScene", new VideoScene);
	
	SCENEMANAGER->changeScene("LoadingScene");
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
	SCENEMANAGER->update();
}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	// UI
	SOUNDMANAGER->addSound("IntroMusic", "Sounds/RCG_Intro_Song.wav", true, true);
	IMAGEMANAGER->addImage("MenuBackGround", "Image/UI/menuBackGround.bmp", WINSIZEX, WINSIZEY, false, BLACK);
	IMAGEMANAGER->addImage("MenuFrontGround", "Image/UI/MenuFront.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
	IMAGEMANAGER->addImage("KyokoIntro", "Image/UI/fx_battle_portraits_kyoko.bmp", 512, 771, true, MAGENTA);
	IMAGEMANAGER->addImage("MisakoIntro", "Image/UI/fx_battle_portraits_misako.bmp", 443, 761, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_START", "Image/UI/UI_START.bmp", 151, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_QUIT", "Image/UI/UI_QUIT.bmp", 136, 54, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_ARROW", "Image/UI/UI_title_arrow.bmp", 53, 61, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_LOGO", "Image/UI/UI_TITLE_LOGO.bmp", 573, 317, true, MAGENTA);
	IMAGEMANAGER->addImage("SelectManuBackGround", "Image/UI/UI_FILE_SELECT.bmp", 1600, 900, false, BLACK);
	IMAGEMANAGER->addImage("UI_FILE_A", "Image/UI/UI_FILE_A.bmp", 608, 248, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_B", "Image/UI/UI_FILE_B.bmp", 608, 248, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_C", "Image/UI/UI_FILE_C.bmp", 608, 248, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_MENU", "Image/UI/UI_FILE_SELECT_MENU.bmp", 797, 878, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_FG", "Image/UI/UI_FILE_SELECT_FG.bmp", 351, 128, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Blue", "Image/UI/UI_FILE_SELECT_BG_Blue.bmp", 1585, 885, false, BLACK);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Pink", "Image/UI/UI_FILE_SELECT_BG_Pink.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Yellow", "Image/UI/UI_FILE_SELECT_BG_Yellow.bmp", 797, 829, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_FILE_SELECT_FG_Character", "Image/UI/UI_FILE_SELECT_FG_Character.bmp", 790, 900, true, MAGENTA);
}
