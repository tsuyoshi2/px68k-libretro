#ifndef _WINX68K_BG_H
#define _WINX68K_BG_H

#include <stdint.h>
#include "common.h"

extern	uint8_t	BG_DrawWork0[1024*1024];
extern	uint8_t	BG_DrawWork1[1024*1024];
extern	DWORD	BG0ScrollX, BG0ScrollY;
extern	DWORD	BG1ScrollX, BG1ScrollY;
extern	DWORD	BG_AdrMask;
extern	uint8_t	BG_Regs[0x12];
extern	long	BG_HAdjust;
extern	long	BG_VLINE;
extern	DWORD	VLINEBG;

extern	uint8_t	Sprite_DrawWork[1024*1024];
extern	WORD	BG_LineBuf[1600];

void BG_Init(void);

uint8_t FASTCALL BG_Read(DWORD adr);
void FASTCALL BG_Write(DWORD adr, uint8_t data);

void FASTCALL BG_DrawLine(int opaq, int gd);

#endif /* _WINX68K_BG_H */
