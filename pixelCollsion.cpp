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
	IMAGEMANAGER->addImage("����̹���", "Image/01_Detention_BG_x3_second.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_ball = IMAGEMANAGER->addImage("ball", "Image/UI_title_arrow.bmp", 53, 61, true, RGB(255, 0, 255));

	_x = 600;
	_y = 500;

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	//Y�� Ž����ġ == ���� �Ʒ�
	_probeY = _y + _ball->getHeight() / 2;

	return S_OK;
}

void pixelCollsion::release()
{



}

void pixelCollsion::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _x -= 3;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _x += 3;
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _y -= 3;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _y += 3;

	//Ž���൵ ������Ʈ �Լ��� �־ ����ؼ� �������ش�
	_probeY = _y + _ball->getHeight() / 2;

	for (int i = _probeY -10 ; i < _probeY + 10; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("����̹���")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 0 && b == 0))
		{
			cout << "�浹��" << endl;
			//_y = i - _ball->getHeight() / 2;
			break;
		}
	
	
	}
		


	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	
}

void pixelCollsion::render()
{
	IMAGEMANAGER->findImage("����̹���")->render(getMemDC(), 0, 0);

	_ball->render(getMemDC(), _rc.left, _rc.top);
}
