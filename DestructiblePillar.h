#pragma once
#include "ParentsObstacle.h"
class DestructiblePillar : public ParentsObstacle
{
public:
	HRESULT init(float spawnCenterX, float spawnCenterY)override;
};

