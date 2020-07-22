#include "stdafx.h"
#include "DestructiblePillar.h"

HRESULT DestructiblePillar::init(float spawnCenterX, float spawnCenterY)
{
	_Type = OBSTACLE_TYPE::Pillar;
	_Name = "DestructiblPillar";
	_Img = IMAGEMANAGER->findImage("Pillar");
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_IsDestructible = true;
	return S_OK;
}
