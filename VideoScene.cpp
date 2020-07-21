#include "stdafx.h"
#include "VideoScene.h"

HRESULT VideoScene::init()
{
	video();

	return S_OK;
}

void VideoScene::release()
{
}

void VideoScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) || KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		destroyWindow("IntroVideo");
		SCENEMANAGER->changeScene("IntroMenuScene");
	}
}

void VideoScene::render()
{
}

int VideoScene::video()
{
	VideoCapture cap("Movies/RCG_Intro.mp4");

	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		cap.read(_Frame);

		if (_Frame.empty()) break;

		imshow("IntroVideo", _Frame);

		if (waitKey(24) >= 0) break;
	}
	destroyWindow("IntroVideo");
	return 0;
}
