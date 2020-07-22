#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);
	_Player = new Player;
	_Player->Init();

	imginit(); // ��� �̹����� ����� �ֵ���
	//SCENEMANAGER->addScene("LoadingScene", new LoadingScene);
	//SCENEMANAGER->addScene("MenuScene", new IntroMenuScene);
	//
	//SCENEMANAGER->changeScene("LoadingScene");
	CAMERAMANAGER->setConfig(0, 0, 1600, 900, 0, 0, 1600, 900);

	setEnemy();
	_EnM = new EnemyManager;
	_EnM->Init(_spawn);


	return S_OK;
}

//�޸� ����
void playGround::release()
{
	SAFE_DELETE(_EnM);
}

//����
void playGround::update()
{
	gameNode::update();
	//SCENEMANAGER->update();
	_Player->Update();
	_EnM->Updata();
}

//�׸��� ����
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	//SCENEMANAGER->render();
	_EnM->Render();
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
	

	// StageManager
	//IMAGEMANAGER->addImage("Player", "image/Player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	//IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	//IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));

	//�÷��̾� �̹��� ����
	_Player->PlayerImageAniStting();
}

void playGround::setEnemy()
{
	_spawn.clear();

	TagEnemySpawn _EnSpawn;

	_EnSpawn.EmType = SchoolGirl;
	_EnSpawn.pt.x = 500;
	_EnSpawn.pt.y = 500;
	_spawn.push_back(_EnSpawn);

}
