#include "stdafx.h"
#include "ParentStage.h"
#include "Player.h"

void ParentStage::SetPlayer()
{
	Object* _Player = new Player;

	_Player->init(300, WINSIZEY / 2);
}
