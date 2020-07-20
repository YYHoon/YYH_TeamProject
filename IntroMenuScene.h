#pragma once
#include "gameNode.h"

class IntroMenuScene : public gameNode
{
private:

	RECT _RcStart, _RcQuit;

	float _MisakoX, _MisakoY;
	float _KyokoX, _KyokoY;

	int _AlphaValue;
	int _FrameCount;

public:
	IntroMenuScene();
	~IntroMenuScene();

	HRESULT init();
	void release();
	void update();
	void render();

};