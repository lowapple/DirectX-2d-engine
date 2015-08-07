#pragma once
#include "stdafx.h"
class GraphicRender : public singleton<GraphicRender>
{
public:
	GraphicRender();
	~GraphicRender();
private:
	LPDIRECT3D9         m_pD3D;
	LPDIRECT3DDEVICE9   m_pd3dDevice;
	LPD3DXSPRITE		m_pSprite;
	LPCSTR				m_name;
	int					m_Width;
	int					m_Height;
	bool				m_Windows;
	WNDCLASSEX			wc;
	HWND				hWnd;
public:
	void init();
	void renderStart();
	void renderEnd();
	void release();
	void AppSetting();
public:
	LPDIRECT3DDEVICE9 getDevice() { return m_pd3dDevice; }
	LPD3DXSPRITE getSprite() { return m_pSprite; }

	void setName(LPCSTR name) { this->m_name = name; }
	void setWidth(int width) { this->m_Width = width; }
	void setHeight(int height) { this->m_Height = height; }
	void setWindows(bool tf) { this->m_Windows = tf; }

	LPCSTR getName() { return m_name; }
	int getWidth() { return m_Width;}
	int getHeight() { return m_Height; }
	bool getWindows() { return m_Windows; }
};