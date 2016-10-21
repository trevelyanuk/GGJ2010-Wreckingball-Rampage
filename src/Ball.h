#pragma once
#include "Vector.h"
class CGame;
class CBall
{
public:
	CBall(void){};
	CBall(CGame * in);
	~CBall(void);
	void add_force(float x,float y);
	float x1,y1;
	bool on;
	void render();
	float force_x;
	float force_y;
	void update();
	CGame * pGame;
	bool mouse1down;
	float dowposx,dowposy;
	float rad;
	bool grouded;
	void Collide(float x1, float y1, float x2, float y2);
	int screenClock;
	int score;

	float radius;

	CVector2 * originPoint;
	CVector2 * distanceToOrigin;
	CVector2 * 	tempPoint1;
	CVector2 * 	tempPoint2;
	CVector2 * 	tempLineLeft;
	CVector2 * 	tempLineRight;
	CVector2 * 	tempVectorLeft;
	CVector2 * 	tempVectorRight;
	CVector2 * 	tempVector;
	CVector2 * ballVector;
	CVector2 * mousePosStart;
	CVector2 * mousePosEnd;
	CVector2 * mouseDirection;
	bool CheckBoundaries();
};
