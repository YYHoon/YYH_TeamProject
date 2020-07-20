#include "stdafx.h"
#include "pixelCollsion.h"


pixelCollsion::pixelCollsion()
{
}


pixelCollsion::~pixelCollsion()
{
}

HRESULT pixelCollsion::init()
{
	IMAGEMANAGER->addImage("교실이미지", "01_Detention_BG_x3_start_second.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 60, 60, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 150;
	_y = WINSIZEY / 2 + 80;

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	collision = false;
	_probeY = _y + _ball->getHeight() / 2;
	_probeX = _x + _ball->getWidth() / 2;
	speed = 2;
	return S_OK;
}

void pixelCollsion::release()
{
}

void pixelCollsion::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += speed;
	}



	//탐사축도 업데이트 함수에 넣어서 계속해서 갱신해준다
	_probeY = _y + _ball->getHeight() ;
	_probeX = _x + _ball->getWidth() / 2;

	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("교실이미지")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 0 && b == 0))
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_y = i + _ball->getHeight();
			}

			_y = i + _ball->getHeight() / 2;
			//_x = j - _ball->getWidth() / 2;
			break;
		}
		else
		{
			collision = false;
		}
	}
		

	
	
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
}

void pixelCollsion::render()
{
	IMAGEMANAGER->findImage("교실이미지")->render(getMemDC(), 0, 0);
	Rectangle(getMemDC(), _rc);
	_ball->render(getMemDC(), _rc.left, _rc.top);
}
