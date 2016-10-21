#pragma once
#include "sprite.h"

class CEnvironment :
	public CSprite
{
public:
	CEnvironment(float, float, float, float, int, CGame * pgame,float startRad,bool back);
	~CEnvironment(void);
	void Render();
	void Update(float dt);
	float m_rotAng;
	float m_angOffset;
	float m_PanelOneOffset;
	float m_PanelTwoOffset;
	float m_PanelThreeOffset;
	int p1;
	int p2;
	int p3;
		bool backs;
};
