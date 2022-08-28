#ifndef winx68k_fileio_h
#define winx68k_fileio_h

#include <stdint.h>
#include "common.h"
#include "dosio.h"

#define	FSEEK_SET	0
#define	FSEEK_CUR	1
#define	FSEEK_END	2

void *	File_Open(uint8_t *filename);
void *	File_Create(uint8_t *filename);
DWORD	File_Seek(void *handle, long pointer, int16_t mode);
DWORD	File_Read(void *handle, void *data, DWORD length);
DWORD	File_Write(void *handle, void *data, DWORD length);
int16_t	File_Close(void *handle);
#define	File_Open	file_open
#define	File_Create	file_create
#define	File_Seek	file_seek
#define	File_Read	file_lread
#define	File_Write	file_lwrite
#define	File_Close	file_close

#endif
