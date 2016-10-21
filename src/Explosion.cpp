#include "stdafx.h"
#include "Explosion.h"
#include "stdafx.h"
#include "Game.h"
#include "math.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "Input.h"
#include "Audio.h"

CExplosion::CExplosion(float x, float y, float w, float h, int textureID, CGame * pgame):CSprite(x,y,w,h,textureID,pgame)
{
	m_fX=x;
	m_fY=y;
	m_fW=w;
	m_fH=h;
	m_iTextureID=textureID;
	m_pGame=pgame;
	active = false;
	lifeSpan = 0;

	_TLX = 0.0f;
	_TLY = 1.0f;
	_BLX = 0.0f;
	_BLY = 0.0f;

	_BRX = 0.0625f;
	_BRY = 0.0f;
	_TRX = 0.0625f;
	_TRY = 1.0f;
}

void
CExplosion::spawn(float targetPosX,float targetPosY,float x, float y)
{
	m_fX=x;
	m_fY=y;
	lifeSpan = 0;

	_TLX = 0.0f;
	_TLY = 1.0f;
	_BLX = 0.0f;
	_BLY = 0.0f;

	_BRX = 0.0625f;
	_BRY = 0.0f;
	_TRX = 0.0625f;
	_TRY = 1.0f;

	active = true;

	CAudio::Instance()->playSound("Audio/flak.wav",-6,2.1,2,false);
}

void 
CExplosion::Update(float dt)
{
	if(active)
	{
		lifeSpan += dt;

		if(lifeSpan >= 0.2)
		{	_TLX = 0.0f;	_BLX = 0.0f;	_BRX = 0.0625f;	_TRX = 0.0625f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.4)
		{	_TLX = 0.0625f;	_BLX = 0.0625f;	_BRX = 0.125f;	_TRX = 0.125f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.6)
		{	_TLX = 0.125f;	_BLX = 0.125f;	_BRX = 0.1875f;	_TRX = 0.1875f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.7)
		{	_TLX = 0.1875f;	_BLX = 0.1875f;	_BRX = 0.25f;_TRX = 0.25f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
	
		if(lifeSpan >= 0.10)
		{	_TLX = 0.25f;	_BLX = 0.25f;	_BRX = 0.3125f;	_TRX = 0.3125f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.12)
		{	_TLX = 0.3125f;	_BLX = 0.3125f;	_BRX = 0.375f;	_TRX = 0.375f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.14)
		{	_TLX = 0.375f;	_BLX = 0.375f;	_BRX = 0.4375f;	_TRX = 0.4375f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.16)
		{	_TLX = 0.4375f;	_BLX = 0.4375f;	_BRX = 0.5f;	_TRX = 0.5f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.18)
		{	_TLX = 0.5f;	_BLX = 0.5f;	_BRX = 0.5625f;	_TRX = 0.5625f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.20)
		{	_TLX = 0.5625f;	_BLX = 0.5625f;	_BRX = 0.625f;	_TRX = 0.625f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.22)
		{	_TLX = 0.625f;	_BLX = 0.625f;	_BRX = 0.6875f;	_TRX = 0.6875f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.24)
		{	_TLX = 0.6875f;	_BLX = 0.6875f;	_BRX = 0.75f;	_TRX = 0.75f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.26)
		{	_TLX = 0.75f;	_BLX = 0.75f;	_BRX = 0.8125f;	_TRX = 0.8125f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
		
		if(lifeSpan >= 0.28)
		{	_TLX = 0.8125f;	_BLX = 0.8125f;	_BRX = 0.875f;	_TRX = 0.875f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}
	
		if(lifeSpan >= 0.30)
		{	_TLX = 0.875f;	_BLX = 0.875f;	_BRX = 0.9375f;	_TRX = 0.9375f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.32)
		{	_TLX = 0.9375f;	_BLX = 0.9375f;	_BRX = 1.0f;	_TRX = 1.0f;		_TLY = 1.0f;	_BLY = 0.0f;_BRY = 0.0f;_TRY = 1.0f;}

		if(lifeSpan >= 0.36)
		{
			
			m_fY = 1000;
			active = false;
		}
	}


}

void
CExplosion::Render()
{
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
		glTexCoord2f(_TLX, _TLY);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(_BLX, _BLY);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(_BRX, _BRY);
		glVertex2f(0.5, -0.5);

		glTexCoord2f(_TRX, _TRY);
		glVertex2f(0.5, 0.5);
	glEnd();

	/*glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-0.5, 0.5);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-0.5, -0.5);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(0.5, -0.5);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(0.5, 0.5);
	glEnd();*/


}
CExplosion::~CExplosion(void)
{
}
