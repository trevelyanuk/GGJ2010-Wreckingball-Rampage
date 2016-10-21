#include "stdafx.h"
#include "Projectile.h"
#include "Game.h"
#include "math.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "Input.h"

CProjectile::CProjectile(float x, float y, float w, float h, int textureID, CGame * pgame):CSprite(x,y,w,h,textureID,pgame)
{
	m_fX=x;
	m_fY=y;
	m_fW=w;
	m_fH=h;
	m_iTextureID=textureID;
	m_pGame=pgame;
	calcNorm = false;
	active = false;
}

void
CProjectile::spawn(float targetPosX,float targetPosY,float x, float y)
{
	active = true;
	calcNorm = true;
	m_fX=x;
	m_fY=y;
	m_targetPosX = targetPosX;
	m_targetPosY = targetPosY;

}

void 
CProjectile::Update(float dt)
{

	if(calcNorm) // Ensures normalisation i only done once.
	{
		vecX = m_targetPosX - m_fX;
		vecY = m_targetPosY - m_fY;
		length = sqrt((vecX * vecX) + (vecY * vecY));
		normX = (vecX/ length);
		normY = (vecY/ length);
		calcNorm = false;
	}

	if(active)
	{
		m_fX += (normX * 200) *dt; // Move on target Vector
		m_fY += (normY * 200) *dt;

		if(m_fY >= m_targetPosY)
		{	
			
			active = false;
			m_pGame->addSprite(0,0,m_fX,m_fY, 8);
			m_fY = 1000;
			// Detonate.
		}
		if(m_fY<=0)
		{
			m_fY = 1000;
			active = false;

		}
	}

}

CProjectile::~CProjectile(void)
{
}
