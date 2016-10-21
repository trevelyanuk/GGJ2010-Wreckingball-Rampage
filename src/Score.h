#pragma once

//a singleton, used to score the current score in game
class CScore
{
public:
	~CScore(void);
	bool score1;
	bool score2;
	bool score3;
	static CScore * Instance();
	int GetScore(){return m_nScore;}
	int GetMultiplier(){return m_Multiplier;}
	void SetMultiplier()
	{
		m_Multiplier*=2;
	}
	void IncrementScore(int pointsToAdd)
	{
		m_nScore+=pointsToAdd*m_Multiplier;
		if(m_nScore<0)
		{m_nScore=0;
		}
	}
	void Set(int points){m_nScore=points;}
	void reset(void){
	score1 = false;
	score2 = false;
	score3 = false;
	m_Multiplier = 1;
	}

private:
	
	static CScore * _instance;
	CScore(void);
	int m_nScore; 
	int m_Multiplier;
};
