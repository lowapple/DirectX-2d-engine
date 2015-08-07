#include "Director.h"

void Director::init()
{
	GraphicRender::getInstance()->init();
	SceneRender::getInstance()->init();
}

void Director::update()
{
	SceneRender::getInstance()->update();
}

void Director::loop()
{
	DWORD prevTime = GetTickCount();
	DWORD nextTime;
	float fDt;

	while (msg.message != WM_QUIT)
	{
		nextTime = GetTickCount();
		fDt = (nextTime - prevTime) / 1000.f;
		prevTime = nextTime;

		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// loop
		update();
		render();
		Sleep(1);
	}
}

void Director::release()
{
	SceneRender::getInstance()->getScene()->release();
	GraphicRender::getInstance()->release();
}

void Director::render()
{
	// Render Start
	GraphicRender::getInstance()->renderStart();
	// Draw Start&End
	SceneRender::getInstance()->getScene()->render();
	// Render End
	GraphicRender::getInstance()->renderEnd();
}

void Director::replacescene(Scene * scene)
{
	SceneRender::getInstance()->replacescene(scene);
}

void Director::pushscene(Scene * scene)
{
	SceneRender::getInstance()->pushscene(scene);
}

void Director::popscene()
{
	SceneRender::getInstance()->popscene();
}