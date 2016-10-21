#pragma once

class CMass
{
public:
	CMass(void);
	~CMass(void);
	void add_force(float x,float y);
	float x1,y1;
	bool on;
	void render();
	float force_x;
	float force_y;
		//position.x=0; position.y=0;  forceX=0;	forceY=0;
	float prepositionx, prepositiony;
	void update(float xh,float yh);
	bool grouded;
	bool hits;
	float shade;
};
