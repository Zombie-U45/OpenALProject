#include "Player.h"
#include"Framework.h"

ALuint      uiBuffer;
ALuint      uiSource;
ALint       iState;

int init() {
	// Initialize Framework
	ALFWInit();
	if (!ALFWInitOpenAL())
	{
		ALFWShutdown();
		return 0;
	}
}

int Play(const char * fileName)
{
	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	// Load Wave file into OpenAL Buffer
	if (!ALFWLoadWaveToBuffer((char*)fileName, uiBuffer))
	{
		ALFWprintf("Failed to load %s\n", fileName);
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, &uiSource);

	// Attach Source to Buffer
	alSourcei(uiSource, AL_BUFFER, uiBuffer);
	//pour boucler un son
	alSourcei(uiSource, AL_LOOPING, 1);
	// Play Source
	alSourcePlay(uiSource);

	return 0;
}

int Stop(const char* fileName)
{
	// Clean up by deleting Source(s) and Buffer(s)
	
	alSourceStop(uiSource);
	alDeleteSources(1, &uiSource);
	alDeleteBuffers(1, &uiBuffer);
	
	return 0;
}

int Pause(const char* fileName)
{
	return 0;
}

int Resume(const char* fileName)
{
	return 0;
}
