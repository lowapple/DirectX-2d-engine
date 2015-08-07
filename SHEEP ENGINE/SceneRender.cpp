#include "SceneRender.h"

void SceneRender::init()
{
	if (curScene != NULL)
	{
		curScene->release();
		delete curScene;
		curScene = NULL;
	}

	curScene = HelloWorld::create();
}

void SceneRender::update()
{
	curScene->update();
}

void SceneRender::pushscene(Scene * scene)
{	
	this->scene[_SceneNum] = curScene;

	curScene->release();
	curScene = nullptr;
	curScene = scene;
	curScene->init();

	_SceneNum++;
	this->scene[_SceneNum] = scene;
}

void SceneRender::popscene()
{
	curScene->release();
	curScene = nullptr;
	
	_SceneNum--;
	curScene = this->scene[_SceneNum];

	curScene->init();
}

void SceneRender::replacescene(Scene * scene)
{
	curScene->release();
	curScene = nullptr;
	curScene = scene;
	curScene->init();
}