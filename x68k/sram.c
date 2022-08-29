/*
 *  SRAM.C - SRAM (16kb)
 */

#include	"common.h"
#include	"../libretro/dosio.h"
#include	"prop.h"
#include	"winx68k.h"
#include	"sysport.h"
#include	"x68kmemory.h"
#include	"sram.h"

uint8_t	SRAM[0x4000];

void SRAM_VirusCheck(void)
{
	if ( (cpu_readmem24_dword(0xed3f60)==0x60000002)
	   &&(cpu_readmem24_dword(0xed0010)==0x00ed3f60) )
	{
		SRAM_Cleanup();
		SRAM_Init();
	}
}

void SRAM_Init(void)
{
	int i;
	uint8_t tmp;
	void *fp;

	for (i=0; i<0x4000; i++)
		SRAM[i] = 0xFF;

	if ((fp = file_open_c("sram.dat")))
	{
		file_lread(fp, SRAM, 0x4000);
		file_close(fp);
		for (i=0; i<0x4000; i+=2)
		{
			tmp = SRAM[i];
			SRAM[i] = SRAM[i+1];
			SRAM[i+1] = tmp;
		}
	}
}

void SRAM_Cleanup(void)
{
   int i;
   uint8_t tmp;
   void *fp;

   for (i=0; i<0x4000; i+=2)
   {
      tmp       = SRAM[i];
      SRAM[i]   = SRAM[i+1];
      SRAM[i+1] = tmp;
   }

   if (!(fp = file_open_c("sram.dat")))
      if (!(fp = file_create_c("sram.dat")))
         return;

   file_write(fp, SRAM, 0x4000);
   file_close(fp);
}

uint8_t FASTCALL SRAM_Read(DWORD adr)
{
	adr &= 0xffff;
	adr ^= 1;
	if (adr<0x4000)
		return SRAM[adr];
	return 0xff;
}


void FASTCALL SRAM_Write(DWORD adr, uint8_t data)
{
	if ( (SysPort[5]==0x31)&&(adr<0xed4000) )
	{
		adr       &= 0xffff;
		adr       ^= 1;
		SRAM[adr]  = data;
	}
}
