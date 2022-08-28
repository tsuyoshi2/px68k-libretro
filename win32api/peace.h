/*	$Id: peace.h,v 1.1.1.1 2003/04/28 18:06:55 nonaka Exp $	*/

#ifndef	__NP2_PEACE_H__
#define	__NP2_PEACE_H__

#ifdef __cplusplus
extern "C" {
#endif

DWORD	FAKE_GetTickCount(void);

int	read_file(HANDLE, PVOID, DWORD, size_t*);
int	write_file(HANDLE, PCVOID, DWORD, size_t*);
HANDLE	CreateFile(const char*, DWORD, DWORD, LPSECURITY_ATTRIBUTES,
		DWORD, DWORD, HANDLE);
DWORD	SetFilePointer(HANDLE, LONG, PLONG, DWORD);
int	FAKE_CloseHandle(HANDLE);

size_t	GetPrivateProfileString(const char *, const char*, const char*, char*,
		size_t, const char*);
UINT	GetPrivateProfileInt(const char*, const char*, INT, const char*);

#ifdef __cplusplus
};
#endif

#endif	/* __NP2_PEACE_H__ */
