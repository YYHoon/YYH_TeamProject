#pragma once
#include "ParentStage.h"
class StageOneStart : public ParentStage
{
public:
	HRESULT init()override;
	void update()override;
	void render()override;



};

