#include "stdafx.h"
#include "Shop.h"

HRESULT Shop::init()
{

	// //	Shop  Playground 에 옮겨주세요
	// IMAGEMANAGER->addImage("Stage1_Store", "Image/Shop/Stage1_Store.bmp", 1600, 900, true, MAGENTA);
	// IMAGEMANAGER->addImage("Wallet", "Image/Shop/Wallet.bmp", 1600, 900, true, MAGENTA);
	// IMAGEMANAGER->addImage("potatoChips", "Image/Shop/potatoChips.bmp", 1600, 900, true, MAGENTA);
	// IMAGEMANAGER->addImage("baconSkewer", "Image/Shop/baconSkewer.bmp", 1600, 900, true, MAGENTA);
	// IMAGEMANAGER->addImage("drink", "Image/Shop/drink.bmp", 1600, 900, true, MAGENTA);
	// IMAGEMANAGER->addImage("turboJuice", "Image/Shop/turboJuice.bmp", 1600, 900, true, MAGENTA);



IMAGEMANAGER->findImage("Stage1_Store");
IMAGEMANAGER->findImage("Wallet");
IMAGEMANAGER->findImage("potatoChips");
IMAGEMANAGER->findImage("baconSkewer");
IMAGEMANAGER->findImage("drink");
IMAGEMANAGER->findImage("turboJuice");


	

	return S_OK;
}

void Shop::release()
{
}

void Shop::update()
{

	switch (_ShopPage)
	{
	case P1:
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_ShopPage = P2;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_ShopPage = P4;
		}




		break;
	case P2:
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_ShopPage = P3;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_ShopPage = P1;
		}
		break;
	case P3:
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_ShopPage = P4;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_ShopPage = P2;
		}
		break;
	case P4:
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_ShopPage = P1;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_ShopPage = P3;
		}
		break;
	
	default:
		break;
	}







}

void Shop::render()
{


	IMAGEMANAGER->findImage("Stage1_Store")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("Wallet")->render(getMemDC(), 0, 0);
	if(_ShopPage == P1)
	{ 
		IMAGEMANAGER->findImage("potatoChips")->render(getMemDC(), 0, 0);
	}
	if (_ShopPage == P2)
	{
		IMAGEMANAGER->findImage("baconSkewer")->render(getMemDC(), 0, 0);
	}
	if (_ShopPage == P3)
	{

		IMAGEMANAGER->findImage("drink")->render(getMemDC(), 0, 0);
	}
	if (_ShopPage == P4)
	{
		IMAGEMANAGER->findImage("turboJuice")->render(getMemDC(), 0, 0);
	}


}
