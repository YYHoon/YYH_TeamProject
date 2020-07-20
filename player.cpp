#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init(float spawnX, float spawnY)
{
	_Type = OBJECT_TYPE::Player;
	_Name = "KyonKo";
	_Collision.set(spawnX- 100, spawnY - 100, spawnX + 100, spawnY + 100);
	return S_OK;
}

void Player::release()
{
	SAFE_DELETE(_Img);
}

void Player::update()
{
	move();
}

void Player::render()
{
	_Img = IMAGEMANAGER->findImage("Player");
}

void Player::move()
{
}
