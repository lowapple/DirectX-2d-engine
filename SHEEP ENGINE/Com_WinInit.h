#pragma once
#include "stdafx.h"

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void Com_WinInit(WNDCLASSEX *wc,HWND *hWnd,LPCSTR name,int width,int height)
{
	// 윈도우 클래스 생성
	*wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		MsgProc,
		0L,
		0L,
		GetModuleHandle(NULL),
		NULL,
		NULL,
		NULL,
		NULL,
		name,
		NULL
	};

	RegisterClassEx(wc);

	// 윈도우 생성
	*hWnd = CreateWindow
		(
			name,
			name,
			WS_OVERLAPPEDWINDOW,
			100,
			100,
			width,
			height,
			NULL,
			NULL,
			NULL,
			NULL
		);

	ShowWindow(*hWnd, SW_SHOWDEFAULT);
	UpdateWindow(*hWnd);
}