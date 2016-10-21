#include "stdafx.h"
#include "Spring.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "Mass.h"
#include <math.h>
#include "Score.h"

CSpring::CSpring(void)
{	cout=-23;
	ons =true;
}

CSpring::~CSpring(void)
{

}
void
CSpring::update()
{
	if(ons){
	float xs=(m1->x1)-(m2->x1);
	float ys=(m1->y1)-(m2->y1);
	float nowdis=sqrt((xs*xs)+(ys*ys));
	 dif=(S_Lenght)-nowdis;
	float nowdis1=nowdis;
	float dif1=dif;

	if(dif==0)
	{dif=0.000000001;}
	if(dif<0)
	{
		dif=-dif;
	}
		if(nowdis==0)
	{nowdis=0.000000001;}
	if(nowdis<0)
	{
		nowdis=-nowdis;
	}

	
	float forcemas1_X=(xs/nowdis);
	float forcemas1_Y=(ys/nowdis);

	float disx=(forcemas1_X*dif1)*0.2;
	float disy=(forcemas1_Y*dif1)*0.2;


	m1->add_force(disx,disy);
	m2->add_force(-disx,-disy);
	
	if(dif>(S_Lenght*0.13))
	{
		cout=5;
	}

	cout--;
	if(cout==0)
	{
		if(m1->hits)
		{
			m1->hits=false;
		}
		if(m2->hits)
		{
			m2->hits=false;
		}
		CScore::Instance()->IncrementScore(1);
		ons=false;
	}
	}
	/*
	if((m1->grouded)&&(m2->grouded)){
	}
	else if(m1->grouded)
	{
			m2->add_force(forcemas2_X,forcemas2_Y);
	}
	else if(m2->grouded)
	{
		m1->add_force(forcemas1_X,forcemas1_Y);
	}
	else
	{	
			m1->add_force(forcemas1_X,forcemas1_Y);
			m2->add_force(forcemas2_X,forcemas2_Y);
	}
*/
	

//	m1->add_force(0,-5000);
//	m2->add_force(0,-5000);
		
						
}


void
CSpring::render(void)
{
	if(ons)
	{
	glLoadIdentity();

	//glEnable(GL_BLEND);// Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	/*glTranslatef(m_fX,m_fY,0);		// move to proper position
	glScalef(m_fW,m_fH,1);

*/
	glLineWidth(10);

	glDisable(GL_TEXTURE_2D);
			// set color
	glBegin(GL_LINES);
		glColor4f(m1->shade,m1->shade,m1->shade,1);
		//glTexCoord2f(0.0f, 1.0f);
		glVertex2f(m1->x1,m1->y1);
		glColor4f(m2->shade,m2->shade,m2->shade,1);
		glVertex2f(m2->x1,m2->y1);
	glEnd();

	}
/*
	glBegin(GL_LINES);
	
		glVertex2f(m1->x,m1->y);
		glVertex2f(m2->x,m1->y);

	glEnd();*/

}