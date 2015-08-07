#pragma once
#include "stdafx.h"

void Com_D3DSprite(LPDIRECT3DDEVICE9 * _device, LPD3DXSPRITE * _sprite)
{
	D3DXCreateSprite(*_device, _sprite);
}