#pragma once
#include "gameNode.h"

#include "LoadingScene.h"
#include "IntroMenuScene.h"
#include "pixelCollsion.h"
#include "Shop.h"
#include "StageManager.h"


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

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imginit();
	
};

