#pragma once
#include "gameNode.h"
#include "EnemyCheerLeader.h"
#include "EnemySchoolGirl.h"
#include "EnemySchoolMan.h"
#include <vector>

enum ENEMYTYPE
{
	CheerLeader,
	SchoolMan,
	SchoolGirl
};

struct TagEnemySpawn
{
	ENEMYTYPE EmType;
	POINTFLOAT pt;
};


class EnemyManager : public gameNode
{
private:
	typedef vector<EnemyCheerLeader*> vCheerLeader;
	typedef vector<EnemySchoolMan*>   vSchoolMan;
	typedef vector<EnemySchoolGirl*>  vSchoolGirl;

	vCheerLeader _vCheerLeader;
	vSchoolMan	 _vSchoolMan;
	vSchoolGirl  _vSchoolGirl;

public:

	HRESULT init();
	HRESULT Init(vector<TagEnemySpawn> Spawn);
	void Release();
	void Updata();
	void Render();

	vector<EnemyCheerLeader*> GetCheerLeader() { return _vCheerLeader; }
	vector<EnemySchoolMan*>     GetSchoolMan() { return _vSchoolMan; }
	vector<EnemySchoolGirl*>   GetSchoolGirl() { return _vSchoolGirl; }
};