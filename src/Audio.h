#pragma once
#include <al.h>
#include <alut.h>

#define NUM_BUFFERS 10
#define NUM_SOURCES 10
#define NUM_ENVIRONMENTS 1

class CAudio
{
public:
	CAudio(void);
	~CAudio(void);
	static CAudio * Instance();
	bool version1();
	void setListenerPosition(float x,float y, float z);
	void setListenerLookAt(float x,float y,float z);
	int playSound(char * filename_,float x, float y, float z, bool brepeat_=false,bool relativeToListener_=false);
	void setVolume(int sourceNumber_,float value_);
	void stop(int sourceNumber_);
	bool initialize();
	void shutDown();
private:
	static CAudio * instance;

	int getNextFreeBuffer();

	//listener properties
	ALfloat listenerPos[3];
	ALfloat listenerVel[3];
	ALfloat listenerOri[6];
	//source properties
	ALfloat source0Pos[3];
	ALfloat source0Vel[3];

	//similar to textures, sounds loaded in an array
	ALuint  buffer[NUM_BUFFERS];
	ALuint  source[NUM_SOURCES];
	ALuint  environment[NUM_ENVIRONMENTS];

	ALsizei size,freq;
	ALenum  format;
	ALvoid  *data;

	ALCcontext *m_pContext;
	ALCdevice *m_pDevice;

	bool bBufferInUse[10];
	
	int freeUpABuffer();

};
