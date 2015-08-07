#pragma once
#include "stdafx.h"
#include "GraphicRender.h"
#include "Node.h"

class Sprite : public Node
{
public:
	static Sprite * create(const char * path);
	virtual void update();
	virtual void render();
	virtual void release();
};