#pragma once
#include "Sheep.h"

class Game : public Scene
{
public:
	bool init();
	void update();

	Scene_Create(Game);
};