#include "Sprite.h"

Sprite * Sprite::create(const char * path)
{
	Sprite * sprite = new Sprite();

	D3DXCreateTextureFromFileEx(
		GraphicRender::getInstance()->getDevice()
		, path		// 텍스처 파일 이름
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1				// 밉 레벨(2D에서는 반드시 1)
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x0000001			// 필터링
		, 0x0000001			// 밉 필터링
		, 0x00FFFFFF			// 컬러 키
		, &sprite->m_ninfo			// 텍스처 인포메이션
		, NULL
		, &sprite->m_npTexture			// 텍스처 포인터
		);
	sprite->m_nRect.right 
		= sprite->m_ninfo.Width;
	sprite->m_nRect.bottom 
		= sprite->m_ninfo.Height;

	return sprite;
}

void Sprite::update()
{
	Node::update();
}

void Sprite::render()
{
	Node::render();
	if (m_nVisible == true)
	{
		// 적용
		GraphicRender::getInstance()->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		GraphicRender::getInstance()->getSprite()->SetTransform(&Matrix());
		GraphicRender::getInstance()->getSprite()->Draw(m_npTexture, &m_nRect, NULL, NULL, m_nColor);
		GraphicRender::getInstance()->getSprite()->End();
	};
}

void Sprite::release()
{
	Node::release();
}