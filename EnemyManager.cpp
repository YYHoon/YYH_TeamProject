#include "stdafx.h"
#include "EnemyManager.h"

HRESULT EnemyManager::init()
{
	return S_OK;
}

HRESULT EnemyManager::Init(vector<TagEnemySpawn> Spawn)
{
	_vCheerLeader.clear();
	_vSchoolMan.clear();
	_vSchoolGirl.clear();

	for (int i = 0; i < Spawn.size(); i++)
	{
		EnemyCheerLeader* _EnemyCheerLeader;
		_EnemyCheerLeader = new EnemyCheerLeader;
		EnemySchoolMan* _EnemySchoolMan;
		_EnemySchoolMan = new EnemySchoolMan;
		EnemySchoolGirl* _EnemySchoolGirl;
		_EnemySchoolGirl = new EnemySchoolGirl;

		switch (Spawn[i].EmType)
		{
		case CheerLeader :
			_EnemyCheerLeader->Init(Spawn[i].pt);
			_vCheerLeader.push_back(_EnemyCheerLeader);
			break;
		case SchoolMan :
			_EnemySchoolMan->Init(Spawn[i].pt);
			_vSchoolMan.push_back(_EnemySchoolMan);
			break;
		case SchoolGirl :
			_EnemySchoolGirl->Init(Spawn[i].pt);
			_vSchoolGirl.push_back(_EnemySchoolGirl);
			break;
		}
	}
	return S_OK;
}

void EnemyManager::Release()
{
}

void EnemyManager::Updata()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->Update();

		//여기서 부터 치어리더 상태정의~
	}

	for (int j = 0; j < _vSchoolMan.size(); j++)
	{
		_vSchoolMan[j]->Update();


		//여기서 부터 남학생 상태정의~
	}

	for (int k = 0; k < _vSchoolGirl.size(); k++)
	{
		_vSchoolGirl[k]->Update();

	}

}

void EnemyManager::Render()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->Render();
	}

	for (int j = 0; j < _vSchoolMan.size(); j++)
	{
		_vSchoolMan[j]->Render();
	}

	for (int k = 0; k < _vSchoolGirl.size(); k++)
	{
		_vSchoolGirl[k]->Render();

	}
}
