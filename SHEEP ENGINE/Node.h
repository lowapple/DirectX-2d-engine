#pragma once
#include "stdafx.h"
#define Vec2(x,y) D3DXVECTOR2(x,y)
#define Rect(x,y,w,h) YRECT(x,y,w,h)
#define Scene_Create(SCENE)\
static SCENE * create()\
	{\
	SCENE * temp = new SCENE();\
	if (!temp->init())\
	{\
	delete temp;\
	temp = nullptr;\
	return NULL;\
	}\
	return temp;\
	}
class Node
{
public:
	 Node();
	~Node();
public:
	//Texture
	LPDIRECT3DTEXTURE9	m_npTexture;
	//Texture 구조체
	D3DXIMAGE_INFO		m_ninfo;

	// Node멤버는 n을 붙임
	D3DXVECTOR2 m_nPosition; //Position, 위치
	D3DXVECTOR2 m_nAnchorPoint; //AnchorPoint, 고정점
	D3DCOLOR m_nColor; //Color
	RECT m_nRect; //Rect, 사각형
	float m_nRot; //Rotation, 회전값
	float m_nScale; //Scale, 크기
	int m_nZorder; // Zorder, 높이조절
	int m_nOpacity; //Opacity, 투명함
	bool m_nVisible; //visible, 활성

public:
	// addchild,vector
	void addchild(Node * node);
	vector<Node *> m_vchild;

	//set
	void setPosition(int x, int y){ m_nPosition.x = x, m_nPosition.y = y; }
	void setPosition(D3DXVECTOR2 vec){ m_nPosition = vec; }
	void setAnchorPoint(int x, int y){ m_nAnchorPoint.x = x, m_nAnchorPoint.y = y; }
	void setAnchorPoint(D3DXVECTOR2 vec){ m_nAnchorPoint = vec; }
	void setColor(D3DCOLOR color){ m_nColor = color; }
	void setRect(RECT rect){ m_nRect = rect; }
	void setRect(float x, int y){ m_nRect.right = x, m_nRect.bottom = y; }
	void setRect(int x, int y){ m_nRect.right = x, m_nRect.bottom = y; }
	void setRotation(float rot){ m_nRot = rot; }
	void setScale(float scale){ m_nScale = scale; }
	void setZorder(int zorder){ m_nZorder = zorder; }
	void setOpacity(int opacity){ m_nOpacity = opacity; }
	void setOpacity(float opacity){ m_nOpacity = (int)opacity; }
	void setVisible(bool visible){ m_nVisible = visible; }

	//get
	D3DXVECTOR2 getPosition(){ return m_nPosition; }
	float getPositionX(){ return m_nPosition.x; }
	float getPositionY(){ return m_nPosition.y; }
	D3DXVECTOR2 getAnchorPoint(){ return m_nAnchorPoint; }
	float getAnchorPointX(){ return m_nAnchorPoint.x; }
	float getAnchorPointY(){ return m_nAnchorPoint.y; }
	D3DCOLOR getColor(){ return m_nColor; }
	RECT getRect(){ return m_nRect; }
	float getRectX(){ return m_nRect.right; }
	float getRectY(){ return m_nRect.bottom; }
	float getRotate(){ return m_nRot; };
	float getScale(){ return m_nScale; }
	bool getVisible(){ return m_nVisible; }
	D3DXMATRIX Matrix();

public:
	virtual bool init();
	virtual void update();
	virtual void render();
	virtual void release();
};
RECT YRECT(int x, int y, int w, int h);