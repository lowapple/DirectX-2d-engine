#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "HelloWorld.h"

class SceneRender : public singleton<SceneRender>
{
private:
	int _SceneNum = 0;
	Scene * curScene;
	Scene * scene[10];
public:
	void init();
	void update ();
public:
	void replacescene(Scene * scene);
	void pushscene(Scene *scene);
	void popscene();

	int getSceneNum() { return _SceneNum; }
	Scene *getScene() { return curScene; }
};