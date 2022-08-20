/*
 *  IRQH.C - IRQ Handler (架空のデバイスにょ)
 */

#include "common.h"
#include "../m68000/m68000.h"
#include "irqh.h"

#if defined (HAVE_CYCLONE)
extern struct Cyclone m68k;
typedef signed int  FASTCALL C68K_INT_CALLBACK(signed int level);
#elif defined (HAVE_MUSASHI)
typedef signed int  FASTCALL C68K_INT_CALLBACK(signed int level);
#endif /* HAVE_CYCLONE */ /* HAVE_MUSASHI */

	uint8_t	IRQH_IRQ[8];
	void	*IRQH_CallBack[8];

void IRQH_Init(void)
{
	memset(IRQH_IRQ, 0, 8);
}

DWORD FASTCALL IRQH_DefaultVector(uint8_t irq)
{
	IRQH_IRQCallBack(irq);
	return -1;
}


void IRQH_IRQCallBack(uint8_t irq)
{
	IRQH_IRQ[irq&7] = 0;
	int i;

#if defined (HAVE_CYCLONE)
	m68k.irq =0;
#elif defined (HAVE_C68K)
	C68k_Set_IRQ(&C68K, 0);
#elif defined (HAVE_MUSASHI)
	m68k_set_irq(0);
#endif /* HAVE_C68K */ /* HAVE_MUSASHI */

	for (i=7; i>0; i--)
	{
		if (IRQH_IRQ[i])
		{
#if defined (HAVE_CYCLONE)
			m68k.irq = i;
#elif defined (HAVE_C68K)
			C68k_Set_IRQ(&C68K, i);
#elif defined (HAVE_MUSASHI)
			m68k_set_irq(i);
#endif /* HAVE_C68K */ /* HAVE_MUSASHI */
			return;
		}
	}
}

void IRQH_Int(uint8_t irq, void* handler)
{
	int i;
	IRQH_IRQ[irq&7] = 1;
	if (handler==NULL)
		IRQH_CallBack[irq&7] = &IRQH_DefaultVector;
	else
		IRQH_CallBack[irq&7] = handler;
	for (i=7; i>0; i--)
	{
		if (IRQH_IRQ[i])
		{
#if defined (HAVE_CYCLONE)

			m68k.irq = i;
#elif defined (HAVE_C68K)
			C68k_Set_IRQ(&C68K, i);
#elif defined (HAVE_MUSASHI)
			m68k_set_irq(i);
#endif /* HAVE_C68K */ /* HAVE_MUSASHI */
			return;
		}
	}
}

signed int my_irqh_callback(signed int  level)
{
	int i;
	C68K_INT_CALLBACK *func = IRQH_CallBack[level&7];
	int vect = (func)(level&7);

	for (i=7; i>0; i--)
	{
		if (IRQH_IRQ[i])
		{
#if defined (HAVE_CYCLONE)
			m68k.irq = i;
#elif defined (HAVE_C68K)
			C68k_Set_IRQ(&C68K, i);
#elif defined (HAVE_MUSASHI)
			m68k_set_irq(i);
#endif /* HAVE_C68K */ /* HAVE_MUSASHI */
			break;
		}
	}

	return (signed int )vect;
}
