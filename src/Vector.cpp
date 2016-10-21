#include "StdAfx.h"
#include "vector.h"
#include <math.h>

CVector2::CVector2(float x,float y,float mag)
{
	m_fx=x;
	m_fy=y;
	m_fmag=mag;
}
CVector2::CVector2(float x,float y)
{
	m_fx=x;
	m_fy=y;
	m_fmag=0.0;
}
CVector2::CVector2()
{
	m_fx=0.0;
	m_fy=0.0;
	m_fmag=0.0;
}

CVector2::~CVector2(void)
{
}

void
CVector2::ChangeCoords(float x, float y)
{
	m_fx=x;
	m_fy=y;
}
void
CVector2::SubtractVector(CVector2 * vec1,CVector2 * vec2, CVector2 * result)
{
result->m_fx=vec1->m_fx - vec2->m_fx;
result->m_fy=vec1->m_fy - vec2->m_fy;
result->m_fmag = sqrt((result->m_fx*result->m_fx)+(result->m_fy*result->m_fy));
Normalize(result);
}
void
CVector2::CalculateCrossProduct(CVector2 * vec1, CVector2 * vec2, CVector2 * result)
{
	float normx = (vec1->m_fx - vec2->m_fx);
	float normy = (vec1->m_fy - vec2->m_fy);
	result->m_fx= normy;
	result->m_fy= -normx;
	Normalize(result);
}
CVector2 *
CVector2::InvertVector(void)
{
	m_fx = -m_fx;
	m_fy = -m_fy;
	return new CVector2(-m_fx, -m_fy);
}
void 
CVector2::Normalize(CVector2 * invector)
{
//calc length
	float len=sqrt((invector->m_fx*invector->m_fx)+(invector->m_fy*invector->m_fy));
	
invector->m_fx/=len;
invector->m_fy/=len;
}
float CVector2::Mag()
{
	float len=sqrt((m_fx*m_fx)+(m_fy*m_fy));
	return len;
}
void 
CVector2::dotProduct(CVector2 *vec1, CVector2 *vec2, CVector2 *invector)
{
	invector->m_fx = vec1->m_fx * vec2->m_fx;
	invector->m_fy = vec1->m_fy * vec2->m_fy;
	Normalize(invector);

}