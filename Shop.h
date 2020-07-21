#pragma once
#include "gameNode.h"
enum ShopPage
{
	P1,
	P2,
	P3,
	P4
	
};
class Shop  : public gameNode
{
private:
	ShopPage _ShopPage;
	image* StoreImg;
	image* WalletImg;
	image* potatoChipsImg;
	image* baconSkewerImg;
	image* drinkImg;
	image* turboJuiceImg;


public:

	HRESULT init();
	void release();
	void update();
	void render();
};


