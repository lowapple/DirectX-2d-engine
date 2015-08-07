#pragma once
#include "stdafx.h"

void Com_D3DInit9(HWND *hWnd,LPDIRECT3D9 _d3d, LPDIRECT3DDEVICE9 *_device,int _width,int _height,bool _windows)
{
	// D3D 초기화
	_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = _windows;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = _width;
	d3dpp.BackBufferHeight = _height;

	// 디바이스 생성
	_d3d->CreateDevice
			(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				*hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				_device
			);
}