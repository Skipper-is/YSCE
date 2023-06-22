#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include <ysclass.h>
#include <fs.h>

#include "../../voicedll/fsvoiceenum.h"

////////////////////////////////////////////////////////////


void FsSoundInitialize(void)
{
}


void FsSoundTerminate(void)
{
}


void FsSoundSetMasterSwitch(YSBOOL sw)
{
}

void FsSoundSetEnvironmentalSwitch(YSBOOL sw)
{
}

void FsSoundSetOneTimeSwitch(YSBOOL sw)
{
}


void FsSoundStopAll(void)
{
}

void FsSoundSetVehicleName(const char [])
{
}

void FsSoundSetEngine(FSSND_ENGINETYPE ,int ,const double )
{
}

void FsSoundSetMachineGun(FSSND_MACHINEGUNTYPE )
{
}

void FsSoundSetAlarm(FSSND_ALARMTYPE, int balance, int volume)
{
}

void FsSoundSetOneTime(FSSND_ONETIMETYPE, int balance, int volume)
{
}

void FsSoundKeepPlaying(void)
{
}


////////////////////////////////////////////////////////////


void FsVoiceStopAll(void)
{
}

void FsVoiceSpeak(int nVoicePhrase,const struct FsVoicePhrase voicePhrase[])
{
}

void FsVoiceKeepSpeaking(void)
{
}
