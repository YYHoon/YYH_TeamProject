#pragma once
#include "gameNode.h"

#include "LoadingScene.h"
#include "IntroMenuScene.h"
#include "Player.h"
#include "ParentStage.h"
#include "StageManager.h"
#include "pixelCollsion.h"
#include "Shop.h"
#include "StageManager.h"
#define MAGENTA RGB(255,0,255)
#define BLACK RGB(0,0,0)
#include <iostream>

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;


class playGround : public gameNode
{
private:
	StageManager* _SM;


public:
	playGround();
	~playGround();
	Object* _Player;
	

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imginit();

};

