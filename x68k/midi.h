#ifndef _WINX68K_MIDI_H
#define _WINX68K_MIDI_H

#include <stdint.h>
#include "common.h"

void MIDI_Init(void);
void MIDI_Cleanup(void);
void MIDI_Reset(void);
uint8_t FASTCALL MIDI_Read(DWORD adr);
void FASTCALL MIDI_Write(DWORD adr, uint8_t data);
void FASTCALL MIDI_Timer(DWORD clk);
int MIDI_SetMimpiMap(char *filename);
int MIDI_EnableMimpiDef(int enable);
void MIDI_DelayOut(unsigned int delay);

#endif /* _WINX68K_MIDI_H */
