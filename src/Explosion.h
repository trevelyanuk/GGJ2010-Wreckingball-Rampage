#pragma once
#include "sprite.h"

class CExplosion :
	public CSprite
{
public:
	CExplosion(float x, float y, float w, float h, int textureID, CGame * pgame);
	~CExplosion(void);
	void spawn(float targetPosX,float targetPosY,float x, float y);
	void Update(float dt);
	void Render();
	float lifeSpan;

	float _TLX;
	float _TLY;
	float _TRX;
	float _TRY;
	float _BLX;
	float _BLY;
	float _BRX;
	float _BRY;

};
