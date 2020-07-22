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

	setEnemy();
	ENE = new EnemyManager;
	ENE->Init(_spawn);

	te1.MYRectMake(100, 100, 50, 50);
	
	te2.MYRectMake(200, 200, 50, 50);

	return S_OK;
}

//�޸� ����
void playGround::release()
{
	//SAFE_DELETE(ENE);
}

//����
void playGround::update()
{
	gameNode::update();

	getDistance(te1.left, te1.top, te2.left, te2.top);



	ENE->Updata();


}

//�׸��� ����
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	ENE->Render();

	te1.render(getMemDC());
	te2.render(getMemDC());

	TIMEMANAGER->render(getMemDC());
	
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::setEnemy()
{
	_spawn.clear();

	TagEnemySpawn _EnSpawn;


	_EnSpawn.EmType = CheerLeader;
	_EnSpawn.pt.x = 500;
	_EnSpawn.pt.y = 500;
	_spawn.push_back(_EnSpawn);
}
