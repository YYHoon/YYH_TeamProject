#include "stdafx.h"
#include "playGround.h"
#include "Player.h"

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
	_Player = new Player;
	_Player->Init();
	imginit(); // 모든 이미지를 여기다 넣도록

	
	CAMERAMANAGER->setConfig(0, 0, 1600, 900, 0, 0, 1600, 900);


	//SCENEMANAGER->addScene("LoadingScene", new LoadingScene);
	//SCENEMANAGER->addScene("MenuScene", new IntroMenuScene);
	
	//Object* _Player = new Player;
	//_Player->init();

	//SCENEMANAGER->changeScene("LoadingScene");


	SCENEMANAGER->addScene("LoadingScene", new LoadingScene);
	SCENEMANAGER->addScene("MenuScene", new IntroMenuScene);
	SCENEMANAGER->addScene("pixel", new pixelCollsion);
	SCENEMANAGER->addScene("Shop", new Shop);

	//SCENEMANAGER->changeScene("LoadingScene");
	//SCENEMANAGER->changeScene("pixel");
	SCENEMANAGER->changeScene("Shop");



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
	//SCENEMANAGER->update();
	_Player->Update();

	//SCENEMANAGER->update();

	SCENEMANAGER->update();	

	_SM->update();

}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=================================================


	//SCENEMANAGER->render();

	SCENEMANAGER->render();
	
	_SM->render();
	_Player->Render();
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
	//	Shop
	IMAGEMANAGER->addImage("Stage1_Store", "Image/Shop/Stage1_Store.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("Wallet", "Image/Shop/Wallet.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("potatoChips", "Image/Shop/potatoChips.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("baconSkewer", "Image/Shop/baconSkewer.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("drink", "Image/Shop/drink.bmp", 1600, 900, true, MAGENTA);
	IMAGEMANAGER->addImage("turboJuice", "Image/Shop/turboJuice.bmp", 1600, 900, true, MAGENTA);

	//플레이어 이미지 셋팅
	_Player->PlayerImageAniStting();
	// StageManager
	IMAGEMANAGER->addImage("Player", "image/Player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));

	//Obstacle
	IMAGEMANAGER->addImage("Pillar", "image/Obstacle/Pillar.bmp", 207, 864, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Desk", "image/Obstacle/desk.bmp", 168, 159, true, RGB(255, 0, 255));

}
