#include "stdafx.h"
#include "StageManager.h"
#include "Player.h"
#include "AllStage.h"

HRESULT StageManager::init()
{
	_Player = new Player;
	_Player->init();
	
	ParentStage* _Stage1_Start = new Stage1_Start;
	_Stage1_Start->SetPlayerMemoryAddressLink(_Player);
	_Stage1_Start->init();
	_vStageName.push_back("Stage1_Start");
	_vStage.push_back(_Stage1_Start);

	ParentStage* _Stage1_1 = new Stage1_1;
	_Stage1_1->SetPlayerMemoryAddressLink(_Player);
	_Stage1_1->init();
	_vStageName.push_back("Stage1_1");
	_vStage.push_back(_Stage1_1);

	ParentStage* _Stage1_2 = new Stage1_2;
	_Stage1_2->SetPlayerMemoryAddressLink(_Player);
	_Stage1_2->init();
	_vStageName.push_back("Stage1_2");
	_vStage.push_back(_Stage1_2);

	ParentStage* _Stage1_Boss = new Stage1_Boss;
	_Stage1_Boss->SetPlayerMemoryAddressLink(_Player);
	_Stage1_Boss->init();
	_vStageName.push_back("Stage1_Boss");
	_vStage.push_back(_Stage1_Boss);

	SCENEMANAGER->addScene(_vStageName[0], _Stage1_Start);
	SCENEMANAGER->addScene(_vStageName[1], _Stage1_1);
	SCENEMANAGER->addScene(_vStageName[2], _Stage1_2);
	SCENEMANAGER->addScene(_vStageName[3], _Stage1_Boss);

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
		if (_vStage[i]->IsColRightExit() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_CurrentStageIndex += 1;
			SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);

			if (i == 0)
			{
				_Player->SetCenter(1270, 400);
			}
			if (i == 1)
			{
				_Player->SetCenter(50, 500);
			}
			if (i == 2)
			{
				_Player->SetCenter(1400, 800);
			}

		}
		if (_vStage[i]->IsColLefttExit() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_CurrentStageIndex -= 1;
			SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
		}
	}



	cout << _CurrentStageIndex << endl;

}