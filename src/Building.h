#pragma once
#include "Mass.h"
#include "Spring.h"
class CBall;
class CMass;
class CSpring;
class CBuilding
{
public:
	CBuilding(void);
	~CBuilding(void);
	void CreateTextureBuild( char * filename) ; 
	bool buildings[32][32];
	CMass* masses[32][32];
	void update();
	void render();
	int numspring;
	CSpring* springs[2000];
	float x,y;
	float scale;
	void Collision(float bx,float by,float rad,CBall * ball);
	void make(int id);
	void distroys();
	bool deads;
	int bbs;
	void distroys2();
};
