#include "StdAfx.h"
#include ".\game.h"
#include "main.h"
#include "Input.h"
#include "Timer.h"
#include "building.h"
#include "Ball.h"
#include "Environment.h"
#include <math.h>
#include "Score.h"
#include "Projectile.h"
#include "Explosion.h"
#include "Cloud.h"
#include "Tank.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>

int gameState = 1;


//game constructor loads sprites into array
CGame::CGame(void)
{	
	timer = 0;
	texy = 19;	
	alpha = 0.5f;
	prestart = true;
	start = true;
	 arx=0;
	 ary=0;
	 arrow =false;
	clock = 300;
	buildon=0;
	nextone=1;
	times=0;
	finish=false;
	char message[]="**** Entering Game constructor ***\n";
	OutputDebugString(message);
	for(int i=0;i<50;i++)
	{
		test[i]=new CBuilding();
	}
	ballie=new CBall(this);
	m_iSpritesLoaded=0;
	time = 50;

	//load sprites
	//background first
	
//	m_pSprite[m_iSpritesLoaded++]=new CSprite(475,340,950,680,1,this); // BACKGROUND
	
	bac2=new CSprite(475,(340),2048,2048,12,this); // PLANET
	bac=new CEnvironment(475,(340),2048,2048,3,this, -60,true); // PLANET

	//m_pSprites[m_iSpritesLoaded++]=new CEnvironment(475,(340),2048,2048,3,this, -30); // PLANET
	m_pSprite[m_iSpritesLoaded++]=new CEnvironment(475,(340),2048,2048,3,this, -60,false); // PLANET

for(int i = 0; i <= 10; i++)
	{
		m_pSprite[m_iSpritesLoaded++]=new CProjectile(0,1000,10,10,7,this); // Bullets
	}

	for(int i = 0; i <= 4; i++)
	{
		m_pSprite[m_iSpritesLoaded++]=new CTank(680,10,50,50,6,this); // Tanks
	}

	for(int i = 0; i <= 10; i++)
	{
		m_pSprite[m_iSpritesLoaded++]=new CExplosion(680,0,50,50,8,this); // Explosions
	}
	for(int i = 0; i <= 30; i++)
	{
		m_pSprite[m_iSpritesLoaded++]=new CCloud(200,200,50,50,17,this); // Explosions
	}


}

//destructor destroys all loaded sprites
CGame::~CGame(void)
{
	for (int i=0;i<m_iSpritesLoaded;i++)
	{
		delete m_pSprite[i];
		m_pSprite[i]=0;
	}
}

//doframe method iterates through all sprites and 
//updates and renders them

bool
CGame::DoFrame(float mouse_XPos, float mouse_YPos, bool mouse_LeftButton, bool mouse_RightButton, float appWidth, float appHeight)
{
	mouse_LeftButton2 = mouse_LeftButton;
	if (clock <= 0)
	{
		if(mouse_LeftButton2)
		{
				timer = 0;
	texy = 19;	
	alpha = 0.5f;
	prestart = true;
	start = true;
	 arx=0;
	 ary=0;
	 arrow =false;
	clock = 300;
	buildon=0;
	nextone=1;
	times=0;
	finish=false;
	char message[]="**** Entering Game constructor ***\n";
	OutputDebugString(message);
			
			delete ballie;
			ballie=new CBall(this);
			time = 50;

			//load sprites
			//background first
				
			CScore::Instance()->reset();
		}	CScore::Instance()->Set(0);			
		

		int scorey = CScore::Instance()->GetScore();
		int temp1 = scorey /100000;
		float v1 = temp1;
		if (scorey < 100000)
		{
			v1 = 0;
		}

		temp1 = (scorey% 100000) /10000;
		float v2 = temp1;
		if (scorey < 10000)
		{
			v2 = 0;
		}

		temp1 = (scorey% 10000) /1000;
		float v3 = temp1;
		if (scorey < 1000)
		{
			v3 = 0;
		}

		temp1 = (scorey% 1000) /100;
		float v4 = temp1;
		if (scorey < 100)
		{
			v4 = 0;
		}

		temp1 = (scorey% 100) /10;
		float v5 = temp1;
		if (scorey < 10)
		{
			v5 = 0;
		}

		temp1 = scorey% 10;
		float v6 = temp1;
		if (scorey < 1)
		{
			v6 = 0;
		}

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 9); 
		glBegin(GL_QUADS);
		glTexCoord2f(v1/10, 1.0f);
		glVertex2f(320 - 96, 256);

		glTexCoord2f(v1/10, 0.0f);
		glVertex2f(320 - 96, 224);

		glTexCoord2f(v1/10 + 0.1, 0.0f);
		glVertex2f(320 - 64, 224);

		glTexCoord2f(v1/10+ 0.1, 1.0f);
		glVertex2f(320 - 64, 256);
		


		glTexCoord2f(v2/10, 1.0f);
		glVertex2f(320 - 64, 256);

		glTexCoord2f(v2/10, 0.0f);
		glVertex2f(320 - 64, 224);

		glTexCoord2f(v2/10 + 0.1, 0.0f);
		glVertex2f(320 - 32, 224);

		glTexCoord2f(v2/10+ 0.1, 1.0f);
		glVertex2f(320 - 32, 256);

		glTexCoord2f(v3/10, 1.0f);
		glVertex2f(320 - 32, 256);

		glTexCoord2f(v3/10, 0.0f);
		glVertex2f(320 - 32, 224);

		glTexCoord2f(v3/10 + 0.1, 0.0f);
		glVertex2f(320, 224);

		glTexCoord2f(v3/10+ 0.1, 1.0f);
		glVertex2f(320, 256);

		glTexCoord2f(v4/10, 1.0f);
		glVertex2f(320, 256);

		glTexCoord2f(v4/10, 0.0f);
		glVertex2f(320, 224);

		glTexCoord2f(v4/10 + 0.1, 0.0f);
		glVertex2f(320 + 32, 224);

		glTexCoord2f(v4/10+ 0.1, 1.0f);
		glVertex2f(320 +32, 256);

		glTexCoord2f(v5/10, 1.0f);
		glVertex2f(320 + 32, 256);

		glTexCoord2f(v5/10, 0.0f);
		glVertex2f(320 + 32, 224);

		glTexCoord2f(v5/10 + 0.1, 0.0f);
		glVertex2f(320 + 64, 224);

		glTexCoord2f(v5/10+ 0.1, 1.0f);
		glVertex2f(320 +64, 256);

		glTexCoord2f(v6/10, 1.0f);
		glVertex2f(320 + 64, 256);

		glTexCoord2f(v6/10, 0.0f);
		glVertex2f(320 + 64, 224);

		glTexCoord2f(v6/10 + 0.1, 0.0f);
		glVertex2f(320 + 96, 224);

		glTexCoord2f(v6/10+ 0.1, 1.0f);
		glVertex2f(320 +96, 256);

		}
	else
	{
	CInput::Instance()->GetInput();
	float dt=CTimer::Instance()->Getdt();
	
	
	times+=dt;
	if(times>nextone)
	{
		times=0;
		nextone=((rand()%100)*0.1)+4;
		if(test[buildon]->deads)
		{
			//test[buildon]->deads=false;
			test[buildon]->make(1);
			//test[buildon]->distroys2();
			buildon++;
			if(buildon>49){
				buildon=0;

			}
		}
	}
	if (!start)
	{
		clock-= dt;
	
	if(!m_mouse_LeftButton)
		{
			if(mouse_LeftButton)
			{
					 arx=mouse_XPos;
					 ary=-(mouse_YPos-480);
					 arrow =true;
			}
		}

	if(m_mouse_RightButton){
		if(!mouse_LeftButton)
		{			
				 arrow =false;
		}
	}
	m_mouse_XPos = mouse_XPos;
	m_mouse_YPos = mouse_YPos;
	m_mouse_LeftButton = mouse_LeftButton;
	m_mouse_RightButton = mouse_RightButton;

	}
	//update all sprites

	time+= dt;
	if(time > 0.016)
	{
		if (!start)
		{
			alpha -= 0.05;
		}
		for (int i=0;i<m_iSpritesLoaded;i++)
		{
			m_pSprite[i]->Update(dt);
		}
		time = 0;
	

	//render all sprites

	Collision();
	for(int i=0;i<50;i++)
	{
	test[i]->update();
	}
	bac->Update(dt);
	ballie->update();
	}
	int randomTankSpawn =(rand()%300);
	if(randomTankSpawn == 1)
	{
		for (int i=0;i<m_iSpritesLoaded;i++)
		{
			if(!(m_pSprite[i]->active) && (m_pSprite[i]->m_iTextureID == 6))
			{
				m_pSprite[i]->spawn(0,0,680,10);	
				break;
			}
		}
		
	}
	bac2->Render();
	bac->Render();
	for(int i=0;i<50;i++)
	{
		test[i]->render();
	}

	for (int i=0;i<m_iSpritesLoaded;i++)
	{
		m_pSprite[i]->Render();
	}

		if(arrow)
	{	
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glColor4f(1,0,0,0.6);		// set color


		glLineWidth(2);
		glBegin(GL_LINES);
		//glColor4f(m1->shade,m1->shade,m1->shade,1);
		//glTexCoord2f(0.0f, 1.0f);
		glVertex2f(mouse_XPos,-(mouse_YPos-480));
		glVertex2f(arx,ary);
		//glColor4f(m2->shade,m2->shade,m2->shade,1);
		
		glEnd();

	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 11); 	
	glColor4f(1,1,1,0.8);		// set color
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(arx- 3, ary + 3);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(arx- 3, ary- 3);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(arx + 3, ary - 3);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(arx + 3, ary + 3);
		
	glEnd();


	
	}


	ballie->render();
	
		

if (alpha > 0)
		{
		glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor4f(1,1,1,alpha);		// set color
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, 16); 
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1.0f);
		glVertex2f(0, 480);

		glTexCoord2f(0, 0.0f);
		glVertex2f(0, 0);

		glTexCoord2f(1, 0.0f);
		glVertex2f(640, 0);

		glTexCoord2f(1, 1.0f);
		glVertex2f(640, 480);
		
		glEnd();
		glDisable(GL_BLEND);
		}

if (start)
{
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, 21); 
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1.0f);
		glVertex2f(0, 480);

		glTexCoord2f(0, 0.0f);
		glVertex2f(0, 0);

		glTexCoord2f(1, 0.0f);
		glVertex2f(640, 0);

		glTexCoord2f(1, 1.0f);
		glVertex2f(640, 480);
		glEnd();
		glDisable(GL_BLEND);
		
		timer++;
}

if (prestart)
	{
		if (timer > 300)
		{
			timer = 0;
			texy++;
			if (texy == 21)
			{
				prestart = false;
			}
		}

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texy); 
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1.0f);
		glVertex2f(0, 480);

		glTexCoord2f(0, 0.0f);
		glVertex2f(0, 0);

		glTexCoord2f(1, 0.0f);
		glVertex2f(640, 0);

		glTexCoord2f(1, 1.0f);
		glVertex2f(640, 480);
		glEnd();
		
		timer++;
		
	}


	if (CInput::Instance()->GetIfKeyDown(DIK_Q))
	{
		
		return false; //to show it is time to quit game
	}
		return true;
	}
	


	
	return true; //meaning keep going




}
void CGame::Collision()
{	
	for (int i=0;i<m_iSpritesLoaded;i++)
		{
			if( (m_pSprite[i]->m_iTextureID == 6))
			{
				m_pSprite[i]->col(ballie->x1,ballie->y1);	
			//	break;
			}
		}

	for(int i=0;i<50;i++)
	{
	float disr=sqrt(((ballie->x1-test[i]->x)*(ballie->x1-test[i]->x))+((ballie->y1-test[i]->y)*(ballie->y1-test[i]->y)));
	if(disr<test[i]->scale*20)
	{
		test[i]->Collision(ballie->x1,ballie->y1,ballie->rad,ballie);

	}
	}

}
//////////////// ADDED BY STEVE FOR TANK SHELLS 03:25

//////////////// ADDED BY STEVE FOR TANK SHELLS 03:25
void CGame::addSprite(float targetX, float targetY, float posX, float posY, int objectType)
{
	for (int i=0;i<m_iSpritesLoaded;i++)
	{
		if((!(m_pSprite[i]->active)) && (m_pSprite[i]->m_iTextureID == objectType))
		{
			if (objectType == 8)
			{
				CVector2 * disty = new CVector2(0,0,0);
				CVector2 * ballpo = new CVector2(ballie->x1,ballie->y1);
				CVector2 * exploCentre = new CVector2(posX,posY);				
				CVector2::SubtractVector(exploCentre, ballpo, disty);
				CVector2::Normalize(exploCentre);
				if (disty->m_fmag < 100)
				{
					if (disty->m_fmag < 50)
					{
						CScore::Instance()->IncrementScore((disty->m_fmag)-50);
					}
					ballie->add_force(-disty->m_fx,-disty->m_fy);//exploCentre->m_fx * (100 - disty->m_fmag) * 0.1,exploCentre->m_fy *(100 - disty->m_fmag)* 0.1);
				}
			}
			m_pSprite[i]->spawn(targetX,targetY,posX,posY);	

			break;
		}
	}
}








