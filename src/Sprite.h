#pragma once
class CGame;
struct vector2d;

class CSprite  
{
public:
	float m_fX;	//the position of the centre of the sprite
	float m_fY;
	float m_fW;	//width of the sprite in arbitrary units
	float m_fH;	//height of the sprite in arbitrary units
	int m_iTextureID; //which of the preloaded textures to use

	float m_fR;	//red component between 0 and 1
	float m_fG;	//green component between 0 and 1
	float m_fB;	//blue component between 0 and 1
	float m_fA;	//alpha value 0-1
	int	m_ident;

	int health;
	bool active;
bool active2;
	bool backs;
	float ssp;

	CGame * m_pGame; //pointer to game which this sprite is part of

public:
	virtual void col(float x, float y){};
	CSprite(CGame * pgame);
	CSprite(float x, float y, float w, float h, int textureID, CGame * pgame); 
//This new constructor is added to the Csprite.h header file.

	virtual ~CSprite();
	virtual void Render();
	virtual void Update(float dt);
	virtual void setPosition(float x, float y);
	virtual void hitBehaviour(int hitBy);
	virtual void spawn(float targetPosX,float targetPosY,float x, float y);


	





}; 

