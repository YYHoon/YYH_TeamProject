#include "stdafx.h"
#include "ParentStage.h"
#include "Player.h"
#include "AllObstacle.h"

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
	if (isCollision(_Player->GetCollision(), _RightExit) && _IsOnceClear)return true;
	return false;
}

bool ParentStage::IsColLefttExit()
{
	if (isCollision(_Player->GetCollision(), _LeftExit) && _IsOnceClear)return true;
	return false;
}



