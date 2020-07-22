#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{
	_Type = OBJECT_TYPE::Player;
	_Name = "KyonKo";
	_Img = IMAGEMANAGER->findImage("Player");
	_HP = 50;
	return S_OK;
}

void Player::release()
{
	SAFE_DELETE(_Img);
}

void Player::update()
{
	move();
	_Collision.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
}

void Player::render()
{
	
	
}

void Player::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_Center.x -= 10;
	}
	if(KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_Center.x += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_Center.y += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_Center.y -= 10;
	}
}
