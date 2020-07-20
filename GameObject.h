#pragma once
class GameObject
{
protected:
	Synthesize(string, mName, Name)
	Synthesize(POINT_FLOAT, mPosition, Position)
	Synthesize(POINT_FLOAT, mSize, Size)
	Synthesize(MYRECT, mRect, Rect)
	Synthesize(bool, mActive, Active)


public:

	GameObject() {};
	~GameObject() {};
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};

