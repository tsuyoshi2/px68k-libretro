#ifndef _WINX68K_MEMORY_H
#define _WINX68K_MEMORY_H

#include <stdint.h>
#include "../libretro/common.h"

extern	uint8_t*	IPL;
extern	uint8_t*	MEM;
extern	uint8_t*	FONT;
extern  uint8_t    SCSIIPL[0x2000];
extern  uint8_t    SRAM[0x4000];
extern  uint8_t    GVRAM[0x80000];
extern  uint8_t   TVRAM[0x80000];

extern	uint32_t	BusErrFlag;
extern	uint32_t	MemByteAccess;

void Memory_Init(void);

DWORD cpu_readmem24(DWORD adr);
DWORD cpu_readmem24_word(DWORD adr);
DWORD cpu_readmem24_dword(DWORD adr);

void cpu_writemem24(DWORD adr, DWORD data);
void cpu_writemem24_word(DWORD adr, DWORD data);
void cpu_writemem24_dword(DWORD adr, DWORD data);

uint8_t dma_readmem24(DWORD adr);
WORD dma_readmem24_word(DWORD adr);
DWORD dma_readmem24_dword(DWORD adr);

void dma_writemem24(DWORD adr, uint8_t data);
void dma_writemem24_word(DWORD adr, WORD data);
void dma_writemem24_dword(DWORD adr, DWORD data);

void Memory_SetSCSIMode(void);

#endif
