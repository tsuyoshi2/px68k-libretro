#ifndef _WINX68K_PAL_H
#define _WINX68K_PAL_H

#include <stdint.h>
#include "common.h"

extern	uint8_t	Pal_Regs[1024];
extern	WORD	TextPal[256];
extern	WORD	GrphPal[256];
extern	WORD	Pal16[65536];

void Pal_SetColor(void);
void Pal_Init(void);

uint8_t FASTCALL Pal_Read(DWORD adr);
void FASTCALL Pal_Write(DWORD adr, uint8_t data);
void Pal_ChangeContrast(int num);

extern WORD Ibit, Pal_HalfMask, Pal_Ix2;

#endif /* _WINX68K_PAL_H */
