#pragma once
#include "sprite.h"

class CProjectile :
	public CSprite
{
public:
	CProjectile(float x, float y, float w, float h, int textureID, CGame * pgame);
	~CProjectile(void);
	void Update(float dt);
	float m_targetPosX;
	float m_targetPosY;
	bool calcNorm;
	void spawn(float targetPosX,float targetPosY,float x, float y);

	float vecX;
	float vecY;
	float length;
	float normX;
	float normY;

};
