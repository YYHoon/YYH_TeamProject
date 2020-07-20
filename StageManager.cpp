#include "stdafx.h"
#include "StageManager.h"
#include "Player.h"
#include "StageOneStart.h"
#include "StageOneOfOne.h"

HRESULT StageManager::init()
{
	

	ParentStage* Stage_One_Start = new StageOneStart;
	Stage_One_Start->init();
	_vStageName.push_back("Stage_One_Start");


	ParentStage* Stage_One_One = new StageOneOfOne;
	Stage_One_One->init();
	_vStageName.push_back("Stage_One_One");


	SCENEMANAGER->addScene(_vStageName[0], Stage_One_Start);
	SCENEMANAGER->addScene(_vStageName[1], Stage_One_One);

	_CurrentStageIndex = 0;

	SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);

	return S_OK;
}

void StageManager::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_CurrentStageIndex++;
		SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
	}

}

void StageManager::render()
{
	cout << _vStageName[_CurrentStageIndex] << endl;
	SCENEMANAGER->render();
}
