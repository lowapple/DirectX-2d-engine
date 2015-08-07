#include "GraphicRender.h"
#include "Com_D3DInit9.h"
#include "Com_WinInit.h"
#include "Com_D3DSpriteInit.h"

GraphicRender::GraphicRender(){ }
GraphicRender::~GraphicRender(){ release();}

void GraphicRender::init()
{
	//AppSetting
	AppSetting();

	// WInInit
	Com_WinInit(&wc,&hWnd,getName(), getWidth(), getHeight());
	//D3DInit
	Com_D3DInit9(&hWnd, m_pD3D, &m_pd3dDevice, getWidth(), getHeight(), getWindows());
	// Sprite 초기화
	Com_D3DSprite(&m_pd3dDevice, &m_pSprite);
}

void GraphicRender::renderStart()
{
	// 렌더 시작
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, SCENE_COLOR, 1.0f, 0);
	m_pd3dDevice->BeginScene();
}

void GraphicRender::renderEnd()
{
	// 렌더 해제
	m_pd3dDevice->EndScene();
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GraphicRender::release()
{
	// Release
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pD3D);
	SAFE_RELEASE(m_pd3dDevice);
}