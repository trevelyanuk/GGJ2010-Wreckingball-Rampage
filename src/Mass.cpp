#include "stdafx.h"
#include "Mass.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>

CMass::CMass(void)
{
	x1=0;
	y1=0;
	on=false;
	force_x=0;
	force_y=0;
	prepositiony=0;
	prepositionx=0;
	grouded=false;
	hits=true;
	shade=0;
}

CMass::~CMass(void)
{
}

void
CMass::render(void)
{
	if(on){
	if(hits)
	{
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glColor4f(1,1,0,1);		// set color

	glPointSize(4);

	glBegin(GL_POINTS);

		glVertex2f(x1,y1);
	glEnd();
/*
			glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 6); 
	glColor4f(1,1,1,1);		// set color

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(x1- 2, y1 + 2);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(x1- 2, y1- 2);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(x1 + 2, y1 -2);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(x1 + 2, y1 + 2);
	glEnd();
*/
	}
	else
	{	
		glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glColor4f(shade,shade,shade,1);		// set color

	glPointSize(10);

	glBegin(GL_POINTS);

		glVertex2f(x1,y1);
	glEnd();
	}

	






	}
}
void 
CMass::add_force(float x,float y)
{	
		if((!grouded)){

			force_x+=x;
			force_y+=y;
			/*int ko=force_y*100;
			force_y=ko*0.01;
			ko=force_x*100;
			force_x=ko*0.01;*/
		}
}
void
CMass::update(float xh,float yh)
{	/*if(!grouded){

	force_x*=0.9998;
	force_y*=0.9998;
	//force_y-=0.0001;

	x1+=force_x;
	y1+=force_y;
	}
	else
	{
		force_x=0;
		force_y=0;
	}

	prepositiony=y1;
	prepositionx=x1;*/

		if(on){
			x1+=xh;
			y1+=yh;
		if(!grouded){
			force_x*=0.95;
			force_y*=0.95;
			force_y-=0.007;
			x1+=force_x;
			y1+=force_y;
		}
		else
		{
			x1+=force_x;
			y1+=force_y;
		}
		}
}

