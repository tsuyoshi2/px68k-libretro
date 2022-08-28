/*	$Id: peace.h,v 1.1.1.1 2003/04/28 18:06:55 nonaka Exp $	*/

#ifndef	__NP2_PEACE_H__
#define	__NP2_PEACE_H__

#ifdef __cplusplus
extern "C" {
#endif

DWORD	FAKE_GetTickCount(void);

int	read_file(void*, void *, size_t, size_t*);
int	write_file(void*, const void *, size_t, size_t*);
void *  create_file(const char*, DWORD, DWORD);
DWORD	set_file_pointer(void*, LONG, DWORD);
int	FAKE_CloseHandle(void*);

size_t	GetPrivateProfileString(const char *, const char*, const char*, char*,
		size_t, const char*);
UINT	GetPrivateProfileInt(const char*, const char*, INT, const char*);

#ifdef __cplusplus
};
#endif

#endif	/* __NP2_PEACE_H__ */
