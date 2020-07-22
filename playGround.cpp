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
	SCENEMANAGER->addScene("MenuScene", new IntroMenuScene);

	img = IMAGEMANAGER->addFrameImage("CLIdle", "image/enemy/cr/cl_idle.bmp", 0, 0, 1980, 432, 12, 2, true, RGB(255, 0, 255));
	int RIdle[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	 KEYANIMANAGER->addArrayFrameAnimation("ClRightIdle", "CLIdle", RIdle, 12, 10, true,10);


	 _ClMotion = KEYANIMANAGER->findAnimation("ClRightIdle");
	//_ClMotion->start();
	KEYANIMANAGER->StartB("ClRightIdle");
	//SCENEMANAGER->changeScene("LoadingScene");
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
	KEYANIMANAGER->update();
}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	//SCENEMANAGER->render();
	img->aniRender(getMemDC(), 200, 200, _ClMotion);
	cout << "확인" << endl;

	TIMEMANAGER->render(getMemDC());
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	// UI
	SOUNDMANAGER->addSound("IntroMusic", "Sounds/RCG_Intro_Song.wav", true, false);
	IMAGEMANAGER->addImage("MenuBackGround", "Image/menuBackGround.bmp", WINSIZEX, WINSIZEY, false, BLACK);
	IMAGEMANAGER->addImage("MenuFrontGround", "Image/MenuFront.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
	IMAGEMANAGER->addImage("KyokoIntro", "Image/fx_battle_portraits_kyoko.bmp", 512, 771, true, MAGENTA);
	IMAGEMANAGER->addImage("MisakoIntro", "Image/fx_battle_portraits_misako.bmp", 443, 761, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_START", "Image/UI_START.bmp", 151, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_QUIT", "Image/UI_QUIT.bmp", 136, 54, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_ARROW", "Image/UI_title_arrow.bmp", 53, 61, true, MAGENTA);
	IMAGEMANAGER->addImage("Intro_UI_LOGO", "Image/UI_TITLE_LOGO.bmp", 573, 317, true, MAGENTA);
	

	// StageManager
	//IMAGEMANAGER->addImage("Player", "image/Player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	//IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	//IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));
}
