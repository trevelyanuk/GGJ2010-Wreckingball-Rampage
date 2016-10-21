#pragma once

class CVector2
{
public:
	CVector2();
	CVector2(float x,float y,float mag);
		CVector2(float x,float y);
	~CVector2(void);

	float m_fx;
	float m_fy;
	float m_fmag;

public:
void ChangeCoords(float x,float y);
static void SubtractVector(CVector2 * vec1,CVector2 * vec2, CVector2 * result);
float Mag();
CVector2 * InvertVector();
static void CalculateCrossProduct(CVector2 * vec1, CVector2 * vec2, CVector2 * result);
static void dotProduct(CVector2 *vec1, CVector2 *vec2, CVector2 *invector);
static void Normalize(CVector2 * invector);
};
