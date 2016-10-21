#include "StdAfx.h"

#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "main.h"
#include ".\sprite.h"


CSprite::CSprite( CGame * pgame)
{
	m_fX=0.0f;
	m_fY=0.0f;
	m_fW=1.0f;
	m_fH=1.0f;
	m_fR=m_fG=m_fB=m_fA=1.0;
	m_iTextureID=0;
	m_pGame=pgame;
	m_ident = 0;
	
}

CSprite::CSprite(float x_, float y_, float w_, float h_, int textureID_, CGame * pgame)
{
	
	m_fX=x_;
	m_fY=y_;
	m_fW=w_;
	m_fH=h_;
	m_fR=m_fG=m_fB=m_fA=1.0;
	m_iTextureID=textureID_;
	m_pGame=pgame;
	active = true;
}

CSprite::~CSprite(void)
{
}

void CSprite::setPosition(float x, float y)
{
	m_fX = x;
	m_fY = y;
	active = true;
}

void CSprite::hitBehaviour(int hitBy)
{


}

void
CSprite::spawn(float targetPosX,float targetPosY,float x, float y)
{
	

}

void
CSprite::Render()
{
	/*glLoadIdentity();

	glTranslatef(m_fX,m_fY,0);		// move to proper position
	glScalef(m_fW,m_fH,1);

	if (m_iTextureID)
	{
	//use texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_iTextureID); 
	}
	else
	{
	//zero for texture ID means don't use texture
	glDisable(GL_TEXTURE_2D);
	}

	
	if(	m_iTextureID != 2 && m_iTextureID != 6)
	{
		//Mask image, areas needing alpha are white.
		glBindTexture(GL_TEXTURE_2D, m_iTextureID + 6); 
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glColor4f(1,1,1,1);
		glBlendFunc(GL_DST_COLOR,GL_ZERO);	
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(0.5, -0.5);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
	
	// Diffuse component, areas needing to be alpha have to be black.
	glBindTexture(GL_TEXTURE_2D, m_iTextureID); 		
	glBlendFunc(GL_ONE,GL_ONE);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(0.5, -0.5);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);*/

	glLoadIdentity();

	glEnable(GL_BLEND);// Turn Blending On
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(m_fX,m_fY,0);		// move to proper position
	glScalef(m_fW,m_fH,1);



	glColor4f(m_fR,m_fG,m_fB,m_fA);		// set color

	if (m_iTextureID)
	{
	//use texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_iTextureID); 
	}
	else
	{
	//zero for texture ID means don't use texture
	glDisable(GL_TEXTURE_2D);
	}

// Display a quad size 1 by 1, centred at origin
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(0.5, -0.5);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(0.5, 0.5);
	glEnd();
}

void
CSprite::Update(float dt)
{

}





