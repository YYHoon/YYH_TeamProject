#include "stdafx.h"
#include "ParentStage.h"
#include "Player.h"
#include "AllObstacle.h"


//void ParentStage::SetPlayer()
//{
//	Object* _Player = new Player;
//
//	_Player->init(300, WINSIZEY / 2);
//}

ParentStage::ParentStage()
{
}

void ParentStage::update()
{
	IsColRightExit();
	IsColLefttExit();
}

void ParentStage::render()
{
	

}

bool ParentStage::IsColRightExit()
{
	if (isCollision(_Player->GetPlayerRect(), _RightExit) && _IsOnceClear)return true;
	return false;
}

bool ParentStage::IsColLefttExit()
{
	if (isCollision(_Player->GetPlayerRect(), _RightExit) && _IsOnceClear)return true;
	return false;
}
