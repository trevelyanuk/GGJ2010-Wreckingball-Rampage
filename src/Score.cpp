///////////////////////////////////////////////////////////////////////////////////////
///Class:CScore
///does:Controls the players score
///////////////////////////////////////////////////////////////////////////////////////


#include "StdAfx.h"
#include ".\score.h"

CScore::CScore(void)
{
//initialize scoring system
	score1 = false;
	score2 = false;
	score3 = false;
	m_nScore=0;
	m_Multiplier = 1;
}

CScore::~CScore(void)
{
}

CScore *
CScore::Instance()
{
if (_instance==0)
{
	_instance=new CScore();
}
return _instance;
}

CScore * CScore::_instance=0;