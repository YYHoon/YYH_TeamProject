#pragma once
#include "gameNode.h"

class Object;

class ParentStage : public gameNode
{
protected:
	image* _Img;
	string _Name;
	MYRECT _Exit[2];
	MYRECT _EventArea;
	POINT_FLOAT _EventCenterSpot;
	bool _IsOnceClear;
	int _StageIndex;
	Object* _Player;

public:
	virtual HRESULT init() = 0;
	virtual void release() {}
	virtual void update() {}
	virtual void render() {}

	virtual void SetPlayer();
};

