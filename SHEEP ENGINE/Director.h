#pragma once
#include "stdafx.h"
#include "GraphicRender.h"
#include "SceneRender.h"

class Director : public singleton<Director>
{
public:
	 Director(){};
	~Director(){};
public:
	MSG msg;
public:
	void init();
	void loop();
	void update();
	void release();
	void render();
public:
	void replacescene(Scene * scene);
	void pushscene(Scene * scene);
	void popscene();
};