#pragma once
#include "sprite.h"

class CTank :
	public CSprite
{
public:
	CTank(float x, float y, float w, float h, int textureID, CGame * pgame);
	~CTank(void);
	void Update(float dt);
	void Render();
	void Aimiming();
	void spawn(float targetPosX,float targetPosY,float x, float y);
	void col(float x, float y);
	float timer;

	float _TLX;
	float _TLY;
	float _TRX;
	float _TRY;
	float _BLX;
	float _BLY;
	float _BRX;
	float _BRY;

	float targetAngle;
};
