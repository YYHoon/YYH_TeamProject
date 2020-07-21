#include "stdafx.h"
#include "StageManager.h"
#include "Player.h"
#include "StageOneStart.h"
#include "StageOneOfOne.h"

HRESULT StageManager::init()
{
	_Player = new Player;
	_Player->init();
	
	ParentStage* _Stage_One_Start = new StageOneStart;
	_Stage_One_Start->SetPlayerMemoryAddressLink(_Player);
	_Stage_One_Start->init();
	_vStageName.push_back("Stage_One_Start");
	_vStage.push_back(_Stage_One_Start);

	ParentStage* _Stage_One_One = new StageOneOfOne;
	_Stage_One_One->SetPlayerMemoryAddressLink(_Player);
	_Stage_One_One->init();
	_vStageName.push_back("Stage_One_One");
	_vStage.push_back(_Stage_One_One);


	SCENEMANAGER->addScene(_vStageName[0], _Stage_One_Start);
	SCENEMANAGER->addScene(_vStageName[1], _Stage_One_One);

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
	
	MoveStage();
	_Player->update();
}

void StageManager::render()
{
	SCENEMANAGER->render();
}

void StageManager::MoveStage()
{
	for (int i = 0; i < _vStage.size(); i++)
	{
		if (_vStage[i]->IsColRightExit())
		{
			_CurrentStageIndex += 1;
			break;
		}
		if (_vStage[i]->IsColLefttExit())
		{
			_CurrentStageIndex -= 1;
			break;
		}
	}

}
