#pragma once
#include "Sprite.h"
#include "Building.h"
#include "Ball.h"

#define MAXSPRITES 100
class CBall;
class CSprite;
//class CMissileBase;

class CGame
{
public:
	CGame(void);
	~CGame(void);
	bool DoFrame(float mouse_XPos, float mouse_YPos, bool mouse_LeftButton, bool mouse_RightButton, float appWidth, float appHeight);
	bool finish;
	float clock;
	int screenclock;
	float arx;
	float ary;
	bool arrow;
	bool start;
	float alpha;
	int texy;
	bool prestart; 
	int timer;

	int score;
	int scoreMultiplier;

	bool mouse_LeftButton2;
	float m_mouse_XPos;
	float m_mouse_YPos;
	bool m_mouse_LeftButton;
	bool m_mouse_RightButton;
	void Collision();
	float time;
	int buildon;
	float nextone;
	float times;
	int	m_iSpritesLoaded;
CBall * ballie; 
	void addSprite(float targetX, float targetY, float posX, float posY,int objectType);
private:
	CSprite * bac;
		CSprite * bac2;
	CSprite * m_pSprite[MAXSPRITES];
	CBuilding * test[50]; 
	
	//CSprite * m_pMissileBase;


};
