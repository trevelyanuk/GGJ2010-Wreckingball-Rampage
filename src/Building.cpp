#include "stdafx.h"
#include "Building.h"
#include <gl\glu.h>
#include <glut.h>
#include <glaux.h>
#include "Mass.h"
#include "Ball.h"
#include <math.h>

void
CBuilding::distroys()
{
	deads=true;
	for(int i=0;i<numspring;i++)
	{
		delete springs[i];
	}
	numspring=0;
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{	////mass setup
			//masses[i][j]=new CMass();
			masses[i][j]->x1=0;
			masses[i][j]->y1=0;


			masses[i][j]->on=false;
			if(j==0)
			{
				masses[i][j]->grouded=true;
			}
		}	
	}
}
void
CBuilding::distroys2()
{

	//bbs=rand()%3;
	if(bbs==0){CreateTextureBuild( "test.bmp"); }
	if(bbs==1){CreateTextureBuild( "test2.bmp"); }
	if(bbs==2){CreateTextureBuild( "test.bmp"); }
	x=680;
	y=59;
	scale=4;

	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{	////mass setup

			masses[i][j]->x1=((((16*scale)))-(i*scale))+x;
			masses[i][j]->y1=(-(((16*scale))-(j*scale)))+y;
			masses[i][j]->force_x=0;
			masses[i][j]->force_y=0;


			masses[i][j]->on=buildings[i][j];
			if(j==0)
			{
				masses[i][j]->grouded=true;
			}
		}	
	}
	/*for(int i=0;i<numspring;i++)
	{
		springs[i]->
	}*/

}
void
CBuilding::make(int id)
{	
	deads=false;
	x=680;
	y=59;
	scale=8;
	bbs=rand()%3;
	if(bbs==0){CreateTextureBuild( "test.bmp"); }
	if(bbs==1){CreateTextureBuild( "test2.bmp"); }
	if(bbs==2){CreateTextureBuild( "test.bmp"); }

	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{	////mass setup
			//masses[i][j]=new CMass();
			masses[i][j]->x1=((((16*scale)))-(i*scale))+x;
			masses[i][j]->y1=(-(((16*scale))-(j*scale)))+y;
			masses[i][j]->prepositionx=x-(((32*0.2)*0.5)+(i*0.2));
			masses[i][j]->prepositiony=y-(((32*0.2)*0.5)+(j*0.2));
			masses[i][j]->hits=true;
			float sdf=((float)(i*0.1)/32.0)+0.2;
			masses[i][j]->shade=sdf;

			masses[i][j]->on=buildings[i][j];
			if(j==0)
			{
				masses[i][j]->grouded=true;
			}
		}	
	}
	numspring=0;
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			////spring setup
			if(masses[i][j]->on)
			{
				if((i!=31)||(j!=31))
				{
					if(masses[i+1][j+1]->on)
					{
						springs[numspring]=new CSpring();
						springs[numspring]->m1=masses[i][j];
						springs[numspring]->m2=masses[i+1][j+1];
						springs[numspring]->S_Lenght=sqrt(((masses[i][j]->x1-masses[i+1][j+1]->x1)*(masses[i][j]->x1-masses[i+1][j+1]->x1))+((masses[i][j]->y1-masses[i+1][j+1]->y1)*(masses[i][j]->y1-masses[i+1][j+1]->y1)));
						numspring++;	
					}
				}
				if((i!=31)||(j!=0))
				{
					if(masses[i+1][j-1]->on)
					{
						springs[numspring]=new CSpring();
						springs[numspring]->m1=masses[i][j];
						springs[numspring]->m2=masses[i+1][j-1];
						springs[numspring]->S_Lenght=sqrt(((masses[i][j]->x1-masses[i+1][j-1]->x1)*(masses[i][j]->x1-masses[i+1][j-1]->x1))+((masses[i][j]->y1-masses[i+1][j-1]->y1)*(masses[i][j]->y1-masses[i+1][j-1]->y1)));
						
						numspring++;	
					}
				}
				if(i!=31)
				{
					if(masses[i+1][j]->on)
					{
						springs[numspring]=new CSpring();
						springs[numspring]->m1=masses[i][j];
						springs[numspring]->m2=masses[i+1][j];
						springs[numspring]->S_Lenght=sqrt(((masses[i][j]->x1-masses[i+1][j]->x1)*(masses[i][j]->x1-masses[i+1][j]->x1))+((masses[i][j]->y1-masses[i+1][j]->y1)*(masses[i][j]->y1-masses[i+1][j]->y1)));
					
						numspring++;
					}
				}
				if(j!=31)
				{
					if(masses[i][j+1]->on)
					{
						springs[numspring]=new CSpring();
						springs[numspring]->m1=masses[i][j];
						springs[numspring]->m2=masses[i][j+1];
						springs[numspring]->S_Lenght=sqrt(((masses[i][j]->x1-masses[i][j+1]->x1)*(masses[i][j]->x1-masses[i][j+1]->x1))+((masses[i][j]->y1-masses[i][j+1]->y1)*(masses[i][j]->y1-masses[i][j+1]->y1)));
						
						numspring++;
					}
				}
			}		
		}	
	}
}
CBuilding::CBuilding(void)
{
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			masses[i][j]=new CMass();
		}
	}

	bbs=0;
	make(0);
	distroys();
}

CBuilding::~CBuilding(void)
{

}

void 
CBuilding::update()
{

if(!deads)
{
for(int i=0;i<numspring;i++)
	{
		springs[i]->update();
		
	}
for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{	
			x-=0.0005;
			if(x>640)
			{
				masses[i][j]->update(-0.5,0);
			}float ksp=x/640;
			if((x>440)&&(x<640)){
				

			masses[i][j]->update(-0.5,0.08);
			}
			if((x>340)&&(x<440)){
				

			masses[i][j]->update(-0.5,0.06);
			}
			if((x>320)&&(x<340)){	

			masses[i][j]->update(-0.5,0.03);
			}

			if((x>300)&&(x<320)){
				

			masses[i][j]->update(-0.5,-0.01);
			}

			if((x>200)&&(x<300)){
				

			masses[i][j]->update(-0.5,-0.035);
			}
			if((x>0)&&(x<200)){	

			masses[i][j]->update(-0.5,-0.08);
			}
			if(x<0)
			{masses[i][j]->update(-0.5,-0.07);
			}
			
		}
}
if(x<-100)
{

	this->distroys();
	//this->make(1);
}
}
}

void 
CBuilding::render()
{
	if(!deads)
	{
			for(int i=0;i<numspring;i++)
	{
		springs[i]->render();
	}
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			masses[i][j]->render();
		
		}	
	}

	/*glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glColor4f(1,1,1,1);		// set color

	glPointSize(2);

	glBegin(GL_POINTS);

		glVertex2f(x,y);
	glEnd();*/
	}
}
void 
CBuilding::Collision(float bx,float by,float rad,CBall * ball)
{
	if(!deads)
	{

	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			if(masses[i][j]->on){
				float disr=sqrt(((masses[i][j]->x1-bx)*(masses[i][j]->x1-bx))+((masses[i][j]->y1-by)*(masses[i][j]->y1-by)));
				if(disr<=10)
				{
					masses[i][j]->add_force(ball->force_x,ball->force_y);
						float sp=10000;
						int kout=0;
						int mr=3;
						for(int k=0;k<numspring;k++)
						{
							if(springs[k]->ons){
							if(springs[k]->m1==masses[i][j])
							{
								float disr2=sqrt(((springs[k]->m2->x1-bx)*(springs[k]->m2->x1-bx))+((springs[k]->m2->y1-by)*(springs[k]->m2->y1-by)));
								if(disr2<sp)
								{	kout=k;
									sp=disr2;
									mr=2;
								}

							}
							if(springs[k]->m2==masses[i][j])
							{
								float disr3=sqrt(((springs[k]->m1->x1-bx)*(springs[k]->m1->x1-bx))+((springs[k]->m1->y1-by)*(springs[k]->m1->y1-by)));
								if(disr3<sp)
								{	kout=k;
									sp=disr3;
									mr=1;
								}
							}}
						}
						if(mr!=3)
						{
							if (mr == 2)
							{
								ball->Collide(masses[i][j]->x1,masses[i][j]->y1,springs[kout]->m2->x1,springs[kout]->m2->y1);
							}
							else
							{
								ball->Collide(masses[i][j]->x1,masses[i][j]->y1,springs[kout]->m1->x1,springs[kout]->m1->y1);
							}
							int sdfg=0;
							break;

						}
					
					
				}
			}
		}
	}
	}
}
void 
CBuilding::CreateTextureBuild( char * filename )    
{
    AUX_RGBImageRec *pImage_RGB = auxDIBImageLoad( filename );
    unsigned char *pImage_RGBA = NULL;

    if( pImage_RGB != NULL )
    {
        int imageSize_RGB  = pImage_RGB->sizeX * pImage_RGB->sizeY * 3;
  
        // allocate buffer for a RGBA image
     
   
        int i,  k;

		

        for( i = 0, k=0; i < imageSize_RGB; i += 3 ,k++)
        {
		
            // Does the current pixel match the selected color key?
            if( pImage_RGB->data[i]   == 255 )
            {
                buildings[k%32][(int)k/32] = false;   // If so, mass
            }
            else
            {
				 buildings[k%32][(int)k/32] =true ; 
               // buildings[k-(((k/32)-1)*32)][(k/32)-1] = false; // If not, mass
            }
        }

    }

    if( pImage_RGB )
    {
        if( pImage_RGB->data )
            free( pImage_RGB->data );

        free( pImage_RGB );
    }


}

