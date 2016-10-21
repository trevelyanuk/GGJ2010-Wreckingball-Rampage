#include "stdafx.h"
#include "Tank.h"
#include "Game.h"
#include "math.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>z

#include "Input.h"

#define PI 3.14159265


CTank::CTank(float x, float y, float w, float h, int textureID, CGame * pgame):CSprite(x,y,w,h,textureID,pgame)
{
	m_fX=x;
	m_fY=y;
	m_fW=w;
	m_fH=h;
	m_iTextureID=textureID;
	m_pGame=pgame;
	active = false;
	active2=true;

	// INITIAL UVW Animation 
	_TLX = 0.0f;
	_TLY = 1.0f;

	_BLX = 0.0f;
	_BLY = 0.5f;

	_BRX = 0.1f;
	_BRY = 0.5f;

	_TRX = 0.1f;
	_TRY = 1.0f;

	targetAngle = 0;
	timer = 0;
	
	
}

void
CTank::spawn(float targetPosX,float targetPosY,float x, float y)
{
	active = true;
	active2 = true;
	
	m_fX=x;
	m_fY=y;
}


void
CTank::Update(float dt)
{
	timer -= dt;

	////////// MOVING CODE ////////////
	m_fX -= 20*dt;
	if(m_fX > 340)
	{
		m_fY += 3*dt;
	}
	else
	{
		m_fY -= 3*dt;
	}

	if(m_fX <= -10)
	{	
		active = false;
	}
	//////////////////////////////////
 
	if(active2)
	{
		Aimiming();
		double ballsX = m_fX - m_pGame->ballie->x1;
		double ballsY = m_fY - m_pGame->ballie->y1;

		targetAngle =  (atan2(ballsX,ballsY)*180/PI);
		if(targetAngle < 0)
		{
			targetAngle = 360 + targetAngle;
		}
	


	//if (CInput::Instance()->GetIfKeyDown(DIK_SPACE))
	//{
	//	m_pGame->addSprite((m_pGame->ballie->x1), (m_pGame->ballie->y1), m_fX, m_fY);
	//}

		int randomTankSpawn =(rand()%150);
		if(randomTankSpawn == 1)
		{
			m_pGame->addSprite((m_pGame->ballie->x1), (m_pGame->ballie->y1), m_fX, m_fY,7);	
			CAudio::Instance()->playSound("Audio/fire.wav",-6,2.1,2,false);
		}
	}
	else
	{
		
	if(targetAngle > 180 && targetAngle< 360)
	{
		_TLX = 0.7f;	_TLY = 1.0f;_BLX = 0.7f;	_BLY = 0.5f;	_BRX = 0.8f;_BRY = 0.5f;	_TRX = 0.8f;_TRY = 1.0f;
	}

	else
	{
		_TLX = 0.7f;	_TLY = 0.5f;_BLX = 0.7f;	_BLY = 0.0f;	_BRX = 0.8f;_BRY = 0.0f;	_TRX = 0.8f;_TRY = 0.5f;
	}

	}

}



void
CTank::Aimiming()
{
	if(targetAngle < 300 && targetAngle > 257)
	{_TLX = 0.0f;	_TLY = 1.0f;_BLX = 0.0f;	_BLY = 0.5f;	_BRX = 0.1f;_BRY = 0.5f;	_TRX = 0.1f;_TRY = 1.0f;}

	if(targetAngle < 257 && targetAngle > 244)
	{_TLX = 0.1f;	_TLY = 1.0f;_BLX = 0.1f;	_BLY = 0.5f;	_BRX = 0.2f;_BRY = 0.5f;	_TRX = 0.2f;_TRY = 1.0f;}

	if(targetAngle < 244 && targetAngle > 231)
	{_TLX = 0.2f;	_TLY = 1.0f;_BLX = 0.2f;	_BLY = 0.5f;	_BRX = 0.3f;_BRY = 0.5f;	_TRX = 0.3f;_TRY = 1.0f;}

	if(targetAngle < 231 && targetAngle > 218)
	{_TLX = 0.3f;	_TLY = 1.0f;_BLX = 0.3f;	_BLY = 0.5f;	_BRX = 0.4f;_BRY = 0.5f;	_TRX = 0.4f;_TRY = 1.0f;}

	if(targetAngle < 218 && targetAngle > 206)
	{_TLX = 0.4f;	_TLY = 1.0f;_BLX = 0.4f;	_BLY = 0.5f;	_BRX = 0.5f;_BRY = 0.5f;	_TRX = 0.5f;_TRY = 1.0f;}

	if(targetAngle < 206 && targetAngle > 193)
	{_TLX = 0.5f;	_TLY = 1.0f;_BLX = 0.5f;	_BLY = 0.5f;	_BRX = 0.6f;_BRY = 0.5f;	_TRX = 0.6f;_TRY = 1.0f;}

	if(targetAngle < 193 && targetAngle > 180)
	{_TLX = 0.6f;	_TLY = 1.0f;_BLX = 0.6f;	_BLY = 0.5f;	_BRX = 0.7f;_BRY = 0.5f;	_TRX = 0.7f;_TRY = 1.0f;}

	////////////////////// BOTTOM ROW
	if(targetAngle > 10 && targetAngle< 102)
	{_TLX = 0.0f;	_TLY = 0.5f;_BLX = 0.0f;	_BLY = 0.0f;	_BRX = 0.1f;_BRY = 0.0f;	_TRX = 0.1f;_TRY = 0.5f;}

	if(targetAngle > 102 && targetAngle< 115)
	{_TLX = 0.1f;	_TLY = 0.5f;_BLX = 0.1f;	_BLY = 0.0f;	_BRX = 0.2f;_BRY = 0.0f;	_TRX = 0.2f;_TRY = 0.5f;}

	if(targetAngle > 115 && targetAngle< 128)
	{_TLX = 0.2f;	_TLY = 0.5f;_BLX = 0.2f;	_BLY = 0.0f;	_BRX = 0.3f;_BRY = 0.0f;	_TRX = 0.3f;_TRY = 0.5f;}

	if(targetAngle > 128 && targetAngle< 141)
	{_TLX = 0.3f;	_TLY = 0.5f;_BLX = 0.3f;	_BLY = 0.0f;	_BRX = 0.4f;_BRY = 0.0f;	_TRX = 0.4f;_TRY = 0.5f;}

	if(targetAngle > 141 && targetAngle< 154)
	{_TLX = 0.4f;	_TLY = 0.5f;_BLX = 0.4f;	_BLY = 0.0f;	_BRX = 0.5f;_BRY = 0.0f;	_TRX = 0.5f;_TRY = 0.5f;}

	if(targetAngle > 154 && targetAngle< 166)
	{_TLX = 0.5f;	_TLY = 0.5f;_BLX = 0.5f;	_BLY = 0.0f;	_BRX = 0.6f;_BRY = 0.0f;	_TRX = 0.6f;_TRY = 0.5f;}

	if(targetAngle > 166 && targetAngle< 180)
	{_TLX = 0.6f;	_TLY = 0.5f;_BLX = 0.6f;	_BLY = 0.0f;	_BRX = 0.7f;_BRY = 0.0f;	_TRX = 0.7f;_TRY = 0.5f;}


}

void
CTank::col(float x, float y)
{
	float pps=sqrt((float)((x-m_fX)*(x-m_fX))+((y-m_fY)*(y-m_fY)));
	if(pps<25.0)
	{
		CAudio::Instance()->playSound("Audio/boom.wav",-6,2.1,2,false);
		active2=false;
		int sdf=3;
	}

}
void
CTank::Render()
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


CTank::~CTank(void)
{
}
