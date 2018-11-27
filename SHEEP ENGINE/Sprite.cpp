#include "Sprite.h"

Sprite * Sprite::create(const char * path)
{
	Sprite * sprite = new Sprite();

	D3DXCreateTextureFromFileEx(
		GraphicRender::getInstance()->getDevice()
		, path		// �ؽ�ó ���� �̸�
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1				// �� ����(2D������ �ݵ�� 1)
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x0000001			// ���͸�
		, 0x0000001			// �� ���͸�
		, 0x00FFFFFF			// �÷� Ű
		, &sprite->m_ninfo			// �ؽ�ó �������̼�
		, NULL
		, &sprite->m_npTexture			// �ؽ�ó ������
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
		// ����
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