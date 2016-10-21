#pragma once
#include "sprite.h"

class CCloud :
	public CSprite
{
public:
	CCloud(void);
	~CCloud(void);
	CCloud(float x, float y, float w, float h, int textureID, CGame * pgame);
	void Update(float dt);
	void spawn(float targetPosX,float targetPosY,float x, float y);
};
