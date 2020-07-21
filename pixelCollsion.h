#pragma once
#include "gameNode.h"
#include "stdafx.h"

class pixelCollsion : public gameNode
{
private:
	image* _hill;	//��� �̹���
	image* _ball;	//�� �̹���

	RECT _rc;		//���� ����� ��Ʈ

	float _x, _y;	//���� ������ǥ

	RECT _rc2;
	float speed;
	int _probeY;	//Y�� Ž��
	int _probeX;	//X�� Ž��
	bool collision; // �ȼ����� �浹������

public:
	pixelCollsion();
	~pixelCollsion();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	//void PixelCollisionTest();

};

