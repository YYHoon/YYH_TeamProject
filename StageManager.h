#pragma once
#include "gameNode.h"
#include <vector>

class Object;

class StageManager : public gameNode
{
private:
	vector<string> _vStageName;
	vector<string>::iterator _viStage;
	int _CurrentStageIndex;
	

public:
	HRESULT init();
	void update();
	void render();


};

