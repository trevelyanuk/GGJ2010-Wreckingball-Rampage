#include "stdafx.h"
#include "Cloud.h"

CCloud::CCloud(float x, float y, float w, float h, int textureID, CGame * pgame):CSprite(x,y,w,h,textureID,pgame)
{
		 ssp=(rand()%4)+1;
		 m_fY=(rand()%250)+220;
		m_fX=(rand()%1000)+700;
		int spps=(rand()%2)+17;
		this->m_iTextureID=spps;
		this->m_fH=this->m_fW=((rand()%500)*0.1)+50;
		


}

CCloud::~CCloud(void)
{
}
void
CCloud::spawn(float targetPosX,float targetPosY,float x, float y)
{
	active = true;
	active2 = true;
	
	m_fX=x;
	m_fY=y;
}


void
CCloud::Update(float dt)
{
	m_fX-=(ssp*dt)*10;

	if(m_fX<-20)
	{		this->m_fH=this->m_fW==((rand()%500)*0.1)+50;
		//this->m_fH=((rand()%500)*0.1)+50;
		int spps=(rand()%2)+17;
		this->m_iTextureID=spps;
		ssp=((rand()%30)*0.1)+1;
		m_fY=(rand()%250)+220;
		m_fX=(rand()%1000)+700;
	}
}