#include "Game.h"

bool Game::init()
{
	Sprite * sprite = Sprite::create("Resource/POINT.jpg");
	this->addchild(sprite);
	return true;
}

void Game::update()
{
	static int dt;
	dt++;
	if (dt >= 50)
	{
		Director::getInstance()->popscene();
		dt = 0;
	}
}