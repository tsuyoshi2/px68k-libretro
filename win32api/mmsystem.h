/*	$Id: mmsystem.h,v 1.1.1.1 2003/04/28 18:06:55 nonaka Exp $	*/

#ifndef	MMSYSTEM_H__
#define	MMSYSTEM_H__

#include "windows.h"

typedef HANDLE          HMIDIOUT;
typedef HMIDIOUT *      LPHMIDIOUT;

#ifdef __cplusplus
extern "C" {
#endif

void midi_out_short_msg(DWORD dwMsg);
void midi_out_long_msg(char *s, size_t len);
int midi_out_open(LPHMIDIOUT phmo);

#ifdef __cplusplus
};
#endif

#endif	/* MMSYSTEM_H__ */
