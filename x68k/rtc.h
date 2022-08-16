#ifndef _X68K_RTC_H
#define _X68K_RTC_H

#include <stdint.h>

void RTC_Init(void);
uint8_t FASTCALL RTC_Read(DWORD adr);
void FASTCALL RTC_Write(DWORD adr, uint8_t data);
void RTC_Timer(int clock);

#endif /* _X68K_RTC_H */
