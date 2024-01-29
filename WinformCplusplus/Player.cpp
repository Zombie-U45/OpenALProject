#include "Player.h"
#include "Framework.h"

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

int Play(const char* fileName)
{
	// Get Source State
	alGetSourcei(uiSource, AL_SOURCE_STATE, &iState);

	Stop(fileName);

	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	if (iState == AL_PLAYING)
		ALFWprintf("playing %s\n", fileName);

	if (iState != AL_PLAYING)//play source if source is not already playing
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

		alSourcePlay(uiSource);
	}

	return 0;
}

int Stop(const char* fileName)
{
	// Clean up by deleting Source(s) and Buffer(s)
	alGetSourcei(uiSource, AL_SOURCE_STATE, &iState);
	if (iState == AL_PLAYING)
		alSourceStop(uiSource);

	return 0;
}

int Pause(const char* fileName)
{
	// Get Source State
	alGetSourcei(uiSource, AL_SOURCE_STATE, &iState);
	if (iState == AL_PLAYING)
		alSourcePause(uiSource);
	return 0;
}

int Resume(const char* fileName)
{
	alSourceRewind(uiSource);
	alSourcePlay(uiSource);
	return 0;
}

void ChangeVolume(float volume)
{
	alListenerf(AL_GAIN, volume / 10.0f);
}