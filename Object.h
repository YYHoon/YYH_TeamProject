#pragma once
#include "gameNode.h"
class Scene;

enum class OBJECT_TYPE
{
	Player,
	Enemy,
	Obstacle,
	End
};

class Object : public gameNode
{
protected:
	image* _Img;
	string _Name;
	OBJECT_TYPE _Type;
	MYRECT _Collision;
	POINT_FLOAT _Center;
	int _HP;
	
public:

	Object() {};
	~Object() {};

	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	string GetName() { return _Name; }
	OBJECT_TYPE GetType() { return _Type; }
	MYRECT GetCollision() { return _Collision; }
	POINT_FLOAT GetCenter() { return _Center; }
	image* GetImage() { return _Img; }
	virtual void SetCenter(float x, float y) { _Center.x = x; _Center.y = y; }
	int GetHP() { return _HP; }
	void SetHP(int dmg) { _HP -= dmg; }
};

