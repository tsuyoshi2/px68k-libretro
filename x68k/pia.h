#ifndef _WINX68K_PIA_H
#define _WINX68K_PIA_H

#include <stdint.h>
#include "common.h"

void PIA_Init(void);
uint8_t FASTCALL PIA_Read(DWORD adr);
void FASTCALL PIA_Write(DWORD adr, uint8_t data);

#endif /* _WINX68K_PIA_H */
