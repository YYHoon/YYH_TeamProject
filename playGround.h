#pragma once
#include "gameNode.h"
#include "LoadingScene.h"
#include "IntroMenuScene.h"

#include "Player.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define MAGENTA RGB(255,0,255)
#define BLACK RGB(0,0,0)

class playGround : public gameNode
{
private:
	
	Player* _Player;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imginit();
	
};

