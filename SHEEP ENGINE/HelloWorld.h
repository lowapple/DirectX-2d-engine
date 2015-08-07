#pragma once
#include "Sheep.h"

class HelloWorld : public Scene
{
public:
	float dt;

	bool init();
	void update();

	Scene_Create(HelloWorld);
};