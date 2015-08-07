#include "Node.h"

bool Node::init()
{
	return true;
}

void Node::update()
{
	for (auto it : m_vchild)
	{
		it->update();
	}
}

void Node::render()
{
	for (auto it : m_vchild)
	{
		it->render();
	}
}

void Node::release()
{
	for (auto it : m_vchild)
	{
		it->release();
		delete it;
	}
	m_vchild.clear();
}

Node::Node()
{
	ZeroMemory(&m_nPosition, (sizeof(m_nPosition)));
	ZeroMemory(&m_nAnchorPoint, sizeof(m_nAnchorPoint));
	m_nRect = Rect(0,0,0,0);
	m_nRot = 0.0f;
	m_nOpacity = 100;
	m_nVisible = true;
	m_nColor = WHITE;
	m_nScale = 1;
}
Node::~Node(){}

void Node::addchild(Node * node)
{
	m_vchild.push_back(node);
}

D3DXMATRIX Node::Matrix()
{
	D3DXVECTOR2 anchor = D3DXVECTOR2(getRect().right * m_nAnchorPoint.x, getRect().bottom * m_nAnchorPoint.y);
	D3DXVECTOR2 scale = D3DXVECTOR2(m_nScale, m_nScale);
	D3DXVECTOR2 center = D3DXVECTOR2(getRect().right / 2 * m_nScale, getRect().bottom / 2 * m_nScale);
	D3DXVECTOR2 trans = D3DXVECTOR2(m_nPosition.x - anchor.x, m_nPosition.y - anchor.y);

	float Rot = D3DXToRadian(m_nRot);

	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(&matrix, &anchor, 1, &scale, &center, Rot, &trans);
	
	return matrix;
}

RECT YRECT(int x, int y, int w, int h)
{
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = w;
	rect.bottom = h;
	return rect;
}