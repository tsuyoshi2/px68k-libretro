#ifndef _DSWIN_H
#define _DSWIN_H

#include "common.h"

int DSound_Init(unsigned long rate);
int DSound_Cleanup(void);

void DSound_Play(void);
void DSound_Stop(void);
void DSound_Send0(long clock);

void DS_SetVolumeOPM(long vol);
void DS_SetVolumeADPCM(long vol);
void DS_SetVolumeMercury(long vol);

int audio_samples_avail(void);
void audio_samples_discard(int discard);
void raudio_callback(void *userdata, unsigned char *stream, int len);

#endif /* _DSWIN_H */
