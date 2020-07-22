#pragma once
#include "gameNode.h"
#include "EnemyCheerLeader.h"
#include "EnemySchoolGirl.h"
#include "EnemySchoolMan.h"
#include "Player.h"
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

	Player* _Player;

public:

	HRESULT init();
	HRESULT Init(vector<TagEnemySpawn> Spawn);
	void Release();
	void Updata();
	void Render();

	vector<EnemyCheerLeader*> GetEnemyCheerLeader() { return _vCheerLeader; }
	vector<EnemySchoolMan*>   GetEnemySchoolMan()   { return _vSchoolMan; }
	vector<EnemySchoolGirl*>  GetEnemySchoolGirl()	{ return _vSchoolGirl; }
};