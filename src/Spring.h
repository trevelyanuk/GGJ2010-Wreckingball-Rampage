#pragma once
#include "Mass.h"

class CMass;

class CSpring
{
public:

	CMass *m1;
	CMass *m2;
	float Lenght;
	float S_Lenght;
	float S_Stiffness;
	void render();
	CSpring(void);
	~CSpring(void);
	void update();
	bool ons;
	float dif;
	int cout;
};
