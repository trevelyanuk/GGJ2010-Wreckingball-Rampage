#include "stdafx.h"
#include "Environment.h"
#include "Game.h"
#include "Input.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "main.h"
#include ".\sprite.h"
#include <math.h>


CEnvironment::CEnvironment(float x_, float y_, float w_, float h_, int textureID_, CGame * pgame, float startRad,bool back):CSprite(x_,y_,w_,h_,textureID_,pgame)
{
	m_fX=x_;
	m_fY=y_;
	m_fW=w_;
	m_fH=h_;
	m_iTextureID=textureID_;
	m_pGame=pgame;
	m_rotAng = 0;

	m_PanelOneOffset	= 0;
	m_PanelTwoOffset	= 30;
	m_PanelThreeOffset	= 60;
	p1=3;
	p2=3;
	p3=3;
		 backs=back;

}

CEnvironment::~CEnvironment(void)
{
}

void CEnvironment::Update(float dt)
{

		if(backs)
		{
	m_PanelOneOffset	+= 0.8*dt;
	m_PanelTwoOffset	+= 0.8*dt;
	m_PanelThreeOffset	+= 0.8*dt;

	

	
	if(m_PanelOneOffset >= 90)
	{ m_PanelOneOffset -= 90;
	p1=(rand()%3)+3;
	}
	if(m_PanelTwoOffset >= 90)
	{ m_PanelTwoOffset -= 90;
	p2=4;
	}
	if(m_PanelThreeOffset >= 90)
	{ m_PanelThreeOffset -= 90;
	p3=(rand()%3)+3;
	}
	
	}
		else
		{
			m_PanelOneOffset	+= 1.1*dt;
	m_PanelTwoOffset	+= 1.1*dt;
	m_PanelThreeOffset	+= 1.1*dt;

	

	
	if(m_PanelOneOffset >= 90)
	{ m_PanelOneOffset -= 90;
	p1=3;
	}
	if(m_PanelTwoOffset >= 90)
	{ m_PanelTwoOffset -= 90;
	p2=3;
	}
	if(m_PanelThreeOffset >= 90)
	{ m_PanelThreeOffset -= 90;
	p3=3;
	}
	


	if (CInput::Instance()->GetIfKeyDown(DIK_P))
	{
		float ang1 = m_rotAng;
	}}
		
}

void CEnvironment::Render()
{
	////////////////////////////////////////////
	///// TRIANGLE ONE /////////////////////////
	glLoadIdentity();
	glEnable(GL_BLEND);// Turn Blending On
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(m_fR,m_fG,m_fB,m_fA);		// set color
	glPushMatrix();
	glTranslatef(320,-1100,0);	
	glScalef(0.8,0.8,0);	
	glRotatef(m_PanelOneOffset-45,0,0,1);
	glPushMatrix();
	//glScalef(0.8,0.8,0);


	if (m_iTextureID)
	{
		//use texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, p1); 
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	glBegin(GL_POLYGON);
	

		glTexCoord2f(0.5f,0.0f);
		glVertex2f(0,0);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-670,2500);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(670,2500);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	////////////////////////////////////////////
	///// TRIANGLE TWO /////////////////////////
	glLoadIdentity();
	glEnable(GL_BLEND);// Turn Blending On
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(m_fR,m_fG,m_fB,m_fA);		// set color
	glPushMatrix();
	glTranslatef(320,-1100,0);	
	glScalef(0.8,0.8,0);		
	glRotatef(m_PanelTwoOffset-45,0,0,1);
	glPushMatrix();
	//glScalef(0.8,0.8,0);

	if (m_iTextureID)
	{
		//use texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, p2); 
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	glBegin(GL_POLYGON);
	

		glTexCoord2f(0.5f,0.0f);
		glVertex2f(0,0);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-670,2500);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(670,2500);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	////////////////////////////////////////////
	///// TRIANGLE THREE ///////////////////////
	glLoadIdentity();
	glEnable(GL_BLEND);// Turn Blending On
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(m_fR,m_fG,m_fB,m_fA);		// set color
	glPushMatrix();
	glTranslatef(320,-1100,0);	
	glScalef(0.8,0.8,0);
	glRotatef(m_PanelThreeOffset-45,0,0,1);
	glPushMatrix();
	//glScalef(0.8,0.8,0);

	if (m_iTextureID)
	{
		//use texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, p3); 
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	glBegin(GL_POLYGON);
	

		glTexCoord2f(0.5f,0.0f);
		glVertex2f(0,0);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-670,2500);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(670,2500);

	glEnd();
	glPopMatrix();
	glPopMatrix();
	
}
