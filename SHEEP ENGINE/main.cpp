#include "stdafx.h"
#include "Sheep.h"

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	Director * director = new Director;

	director->init();

	director->loop();

	director->release();
}