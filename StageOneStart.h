#pragma once
#include "ParentStage.h"

class Player;
class ParentsObstacle;

class StageOneStart : public ParentStage
{
private:
	

public:
	HRESULT init()override;
	void render()override;
	

};

