#ifndef _WINX68K_ADPCM_H
#define _WINX68K_ADPCM_H

#include <stdint.h>

void FASTCALL ADPCM_PreUpdate(DWORD clock);
void ADPCM_Update(int16_t *buffer, DWORD length, uint8_t *pbsp, uint8_t *pbep);

void FASTCALL ADPCM_Write(DWORD adr, uint8_t data);
uint8_t FASTCALL ADPCM_Read(DWORD adr);

void ADPCM_SetVolume(uint8_t vol);
void ADPCM_SetPan(int n);
void ADPCM_SetClock(int n);

void ADPCM_Init(DWORD samplerate);

#endif /* _WINX68K_ADPCM_H */
