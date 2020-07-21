#pragma once
#include "ParentStage.h"
class Stage1_2 : public ParentStage
{
public:
	virtual HRESULT init()override;
	void render()override;
};

