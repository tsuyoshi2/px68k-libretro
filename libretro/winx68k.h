#ifndef _WINX68K_WINCORE_H
#define _WINX68K_WINCORE_H

#include <stdint.h>
#include "common.h"

#define vline HOGEvline /* workaround for redefinition of 'vline' */

#define TOSTR(s) #s
#define PX68KVERSTR TOSTR(PX68K_VERSION)

enum {
   menu_out,
   menu_enter,
   menu_in
};

extern	uint8_t*	FONT;

extern	WORD	VLINE_TOTAL;
extern	DWORD	VLINE;
extern	DWORD	vline;

extern	char	winx68k_dir[MAX_PATH];
extern	char	winx68k_ini[MAX_PATH];
extern	int	BIOS030Flag;
extern   int menu_mode;

void WinX68k_Reset(void);

#endif /* _WINX68K_WINCORE_H */
