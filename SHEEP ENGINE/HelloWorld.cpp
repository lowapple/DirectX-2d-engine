#include "HelloWorld.h"
#include "Game.h"

bool HelloWorld::init()
{
	Sprite * sprite = Sprite::create("Resource/SHEEP.png");
	sprite->setPosition(Vec2(10,10));

	this->addchild(sprite);
	return true;
}

void HelloWorld::update()
{
	static int dt;
	dt++;
	if (100<=dt)
	{
		Director::getInstance()->pushscene(Game::create());
		dt = 0;
	}
}