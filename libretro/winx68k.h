#ifndef _WINX68K_WINCORE_H
#define _WINX68K_WINCORE_H

#include <stdint.h>
#include "common.h"

#define vline HOGEvline /* workaround for redefinition of 'vline' */

#define TOSTR(s) #s
#define PX68KVERSTR TOSTR(PX68K_VERSION)

extern	uint8_t*	FONT;

extern	WORD	VLINE_TOTAL;
extern	DWORD	VLINE;
extern	DWORD	vline;

extern	char	winx68k_dir[MAX_PATH];
extern	char	winx68k_ini[MAX_PATH];
extern	int	BIOS030Flag;

int WinX68k_Reset(void);
int pmain(int argc, char *argv[]);
void end_loop_retro(void);
void exec_app_retro(void);

#endif /* _WINX68K_WINCORE_H */
