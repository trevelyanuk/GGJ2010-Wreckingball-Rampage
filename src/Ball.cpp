#include "stdafx.h"
#include "Ball.h"
#include <gl.h>
#include <glut.h>
#include <glaux.h>
#include "game.h"
#include "Score.h"

CBall::CBall(CGame * in)
{
	score=0;
	pGame=in;
	x1=0;
	y1=0;
	on=false;
	force_x=0;
	force_y=0;
	grouded=false;
	rad=2;
	mouse1down=in->m_mouse_LeftButton;
	mouse1down=in->m_mouse_RightButton;

	originPoint = new CVector2(320, -1100);
	distanceToOrigin = new CVector2(0,0,0);
	mousePosStart = new CVector2(0,0,0);
	mousePosEnd =  new CVector2(10,0,0);
	ballVector = new CVector2(0,1,1);
	CVector2::Normalize(ballVector);
	mouseDirection = new CVector2(0,0,0);
	tempLineLeft = new CVector2(0,0,0);
	tempLineRight = new CVector2(0,0,0);
	tempVectorRight = new CVector2(0,0,0);
	tempVectorLeft = new CVector2(0,0,0);
	tempVector = new CVector2(0,0,0);
	radius = 8; //hard coded
	//CVector2::CalculateCrossProduct(tempPoint1, tempPoint2, tempLineRight);
	//CVector2::CalculateCrossProduct(new CVector2(-tempPoint1->m_fx,-tempPoint1->m_fy),new CVector2(-tempPoint2->m_fx,-tempPoint2->m_fy), tempLineLeft);
}

CBall::~CBall(void)
{
}

void
CBall::render(void)
{
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2); 
	glColor4f(1,1,1,1);		// set color

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(x1- 8, y1 + 8);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(x1- 8, y1- 8);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(x1 + 8, y1 - 8);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(x1 + 8, y1 + 8);
	glEnd();

	if (!pGame->start)
	{
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

	
float xco=200;

	for (int i = 0; i < 6; i++)
	
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 9); 
		glBegin(GL_QUADS);
		glTexCoord2f(v1/10, 1.0f);
		glVertex2f(320 - 96-xco, 480);

		glTexCoord2f(v1/10, 0.0f);
		glVertex2f(320 - 96-xco, 450);

		glTexCoord2f(v1/10 + 0.1, 0.0f);
		glVertex2f(320 - 64-xco, 450);

		glTexCoord2f(v1/10+ 0.1, 1.0f);
		glVertex2f(320 - 64-xco, 480);
		


		glTexCoord2f(v2/10, 1.0f);
		glVertex2f(320 - 64-xco, 480);

		glTexCoord2f(v2/10, 0.0f);
		glVertex2f(320 - 64-xco, 450);

		glTexCoord2f(v2/10 + 0.1, 0.0f);
		glVertex2f(320 - 32-xco, 450);

		glTexCoord2f(v2/10+ 0.1, 1.0f);
		glVertex2f(320 - 32-xco, 480);

		glTexCoord2f(v3/10, 1.0f);
		glVertex2f(320 - 32-xco, 480);

		glTexCoord2f(v3/10, 0.0f);
		glVertex2f(320 - 32-xco, 450);

		glTexCoord2f(v3/10 + 0.1, 0.0f);
		glVertex2f(320-xco, 450);

		glTexCoord2f(v3/10+ 0.1, 1.0f);
		glVertex2f(320-xco, 480);

		glTexCoord2f(v4/10, 1.0f);
		glVertex2f(320-xco, 480);

		glTexCoord2f(v4/10, 0.0f);
		glVertex2f(320-xco, 450);

		glTexCoord2f(v4/10 + 0.1, 0.0f);
		glVertex2f(320 + 32-xco, 450);

		glTexCoord2f(v4/10+ 0.1, 1.0f);
		glVertex2f(320 +32-xco, 480);

		glTexCoord2f(v5/10, 1.0f);
		glVertex2f(320 + 32-xco, 480);

		glTexCoord2f(v5/10, 0.0f);
		glVertex2f(320 + 32-xco, 450);

		glTexCoord2f(v5/10 + 0.1, 0.0f);
		glVertex2f(320 + 64-xco, 450);

		glTexCoord2f(v5/10+ 0.1, 1.0f);
		glVertex2f(320 +64-xco, 480);

		glTexCoord2f(v6/10, 1.0f);
		glVertex2f(320 + 64-xco, 480);

		glTexCoord2f(v6/10, 0.0f);
		glVertex2f(320 + 64-xco, 450);

		glTexCoord2f(v6/10 + 0.1, 0.0f);
		glVertex2f(320 + 96-xco, 450);

		glTexCoord2f(v6/10+ 0.1, 1.0f);
		glVertex2f(320 +96-xco, 480);




	screenClock = pGame->clock;

	temp1 = screenClock /60;
	float v7 = temp1;
	if (screenClock < 60)
	{
		v7 = 0;
	}

	temp1 = (screenClock % 60 )/10;
	float v8 = temp1;
	if (screenClock < 6)
	{
		v8 = 0;
	}

	temp1 = screenClock % 10;
	float v9 = temp1;
	if (screenClock < 0)
	{
		v9 = 0;
	}
	

	float xoff=-250;
	
	glTexCoord2f(v7/10, 1.0f);
		glVertex2f(283-xoff, 480);

		glTexCoord2f(v7/10, 0.0f);
		glVertex2f(283-xoff, 450);

		glTexCoord2f(v7/10 + 0.1, 0.0f);
		glVertex2f(315-xoff , 450);

		glTexCoord2f(v7/10+ 0.1, 1.0f);
		glVertex2f(315-xoff, 480);

		glTexCoord2f(v8/10, 1.0f);
		glVertex2f(320-xoff, 480);

		glTexCoord2f(v8/10, 0.0f);
		glVertex2f(320-xoff, 450);

		glTexCoord2f(v8/10 + 0.1, 0.0f);
		glVertex2f(352-xoff, 450);

		glTexCoord2f(v8/10+ 0.1, 1.0f);
		glVertex2f(352-xoff, 480);
		

		glTexCoord2f(v9/10, 1.0f);
		glVertex2f(352-xoff, 480);

		glTexCoord2f(v9/10, 0.0f);
		glVertex2f(352-xoff, 450);

		glTexCoord2f(v9/10 + 0.1, 0.0f);
		glVertex2f(384-xoff , 450);

		glTexCoord2f(v9/10+ 0.1, 1.0f);
		glVertex2f(384-xoff, 480);
		glEnd();


					int multi = CScore::Instance()->GetMultiplier();
		if (multi > 1)
		{
			if (multi == 2)
			{
				multi = 13;
			}
			if (multi == 4)
			{
				multi = 14;
			}
			if (multi == 8)
			{
				multi = 15;
			}
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, multi); 
			glBegin(GL_QUADS);
			glTexCoord2f(0, 1.0f);
			glVertex2f(295, 25);

			glTexCoord2f(0, 0.0f);
			glVertex2f(295, 0);

			glTexCoord2f(1, 0.0f);
			glVertex2f(335, 0);

			glTexCoord2f(1, 1.0f);
			glVertex2f(335,25);
			glEnd();
		}
	}
	
	


	
}
void 
CBall::add_force(float x,float y)
{	
	force_x+=x;
	force_y+=y;
}

void CBall::Collide(float x1_, float y1_, float x2_, float y2_)
{
	tempPoint1 = new CVector2(x1_,y1_);
	tempPoint2 = new CVector2(x2_,y2_);

	CVector2::CalculateCrossProduct(tempPoint1, tempPoint2, tempLineRight);
	CVector2::CalculateCrossProduct(new CVector2(-tempPoint1->m_fx,-tempPoint1->m_fy),
									new CVector2(-tempPoint2->m_fx,-tempPoint2->m_fy), 
									tempLineLeft);

	CVector2::SubtractVector(new CVector2(this->x1,this->y1),tempLineRight,tempVectorRight);		
	CVector2::SubtractVector(new CVector2(this->x1,this->y1),tempLineLeft,tempVectorLeft);
	if (tempVectorRight->Mag() < tempVectorLeft->Mag())
	{
		CVector2::dotProduct(ballVector,tempLineLeft,tempVector);
		ballVector->m_fx = ballVector->m_fx - 2 * (tempVector->m_fx * tempLineLeft->m_fx);
		ballVector->m_fy = ballVector->m_fy - 2 * (tempVector->m_fy * tempLineLeft->m_fy);
		CVector2::Normalize(ballVector);
		force_x *= ballVector->m_fx;
		force_y *= ballVector->m_fy;
		

	}
	else
	{			
		CVector2::dotProduct(ballVector,tempLineRight,tempVector);
		ballVector->m_fx = ballVector->m_fx - 2 * (tempVector->m_fx * tempLineRight->m_fx);
		ballVector->m_fy = ballVector->m_fy - 2 * (tempVector->m_fy * tempLineRight->m_fy);
		CVector2::Normalize(ballVector);
		force_x *= ballVector->m_fx;
		force_y *= ballVector->m_fy;
	}
}
bool CBall::CheckBoundaries()
{
	if (y1 < 150)
	{
		CVector2::SubtractVector(originPoint,new CVector2(x1,y1),distanceToOrigin);
			if(distanceToOrigin->m_fmag <= 1160)
			{			
				/*ballVector->m_fx -=(2 * distanceToOrigin->m_fx * ballVector->m_fx);
				ballVector->m_fy -=(2 * distanceToOrigin->m_fy * ballVector->m_fy);*/
				/*CVector2::Normalize(ballVector);
				distanceToOrigin->m_fx;*/
		
				force_x -= distanceToOrigin->m_fx*5;
				force_y -= distanceToOrigin->m_fy*5;
				//force_x += 0.6;
	//	force_y += 0.6;
				CScore::Instance()->reset();

			
			}
		
	}
	if (x1-radius < 0)
	{
		x1 = radius;
		ballVector->m_fx = -ballVector->m_fx;
			force_x = -force_x;
			if (!CScore::Instance()->score3)
			{
				CScore::Instance()->SetMultiplier();
				CScore::Instance()->score3 =  true;
			}
	}
	if (x1 + radius > 640)
	{
		x1 = 640 - radius;
		ballVector->m_fx = -ballVector->m_fx;
		force_x = -force_x;
		if (!CScore::Instance()->score2)
			{
				CScore::Instance()->SetMultiplier();
				CScore::Instance()->score2 =  true;
			}
	}
	if (y1 + radius > 480)
	{
		y1= 480 - radius ;
		ballVector->m_fy = -ballVector->m_fy;
			force_y = -force_y;
			if (!CScore::Instance()->score1)
			{
				CScore::Instance()->SetMultiplier();
				CScore::Instance()->score1 =  true;
			}
			

	}
	return true;
}
void
CBall::update(void)
{


	int cg=0;

	if ((pGame->start) && (!pGame->prestart))
	{
		if(pGame->mouse_LeftButton2)
		{
			pGame->start = false;
		}
	}

	else
		if(!pGame->start)
	{
	if(!mouse1down)
		{
			if(pGame->m_mouse_LeftButton)
			{
				//start
				mousePosStart = new CVector2(-pGame->m_mouse_XPos,pGame->m_mouse_YPos);
				
			}
		}
	if(mouse1down){
		if(!pGame->m_mouse_LeftButton)
		{			
			mousePosEnd = new CVector2(-pGame->m_mouse_XPos,pGame->m_mouse_YPos);
			CScore::Instance()->reset();
			if((mousePosEnd->m_fx == mousePosStart->m_fx) &&(mousePosEnd->m_fy == mousePosStart->m_fy))
			{
			}
			else
			{
				CVector2::SubtractVector(mousePosEnd, mousePosStart, mouseDirection);
				ballVector = mouseDirection;
				force_x *=0.1;
				force_y *=0.1;
				add_force((mouseDirection->m_fx * mouseDirection->m_fmag * 0.03),(mouseDirection->m_fy * mouseDirection->m_fmag * 0.03));
				}
		}
	}
	
	mouse1down=pGame->m_mouse_LeftButton;
	}

	force_x*=0.986;
	force_y*=0.986;
	force_y-=0.01;

	x1+=force_x;
	y1+=force_y;
	CheckBoundaries();
}

