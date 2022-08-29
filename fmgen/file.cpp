//	$fmgen-Id: file.cpp,v 1.6 1999/12/28 11:14:05 cisc Exp $

#include "common.h"

#include "file.h"
#include "../libretro/dosio.h"

FileIO::FileIO()
{
	flags = 0;
}

FileIO::FileIO(const char* filename, uint32_t flg)
{
	flags = 0;
	Open(filename, flg);
}

FileIO::~FileIO()
{
	Close();
}

bool FileIO::Open(const char* filename, uint32_t flg)
{
	Close();

	DWORD access   = (flg & readonly  ? 0 : GENERIC_WRITE) | GENERIC_READ;
	DWORD creation = (flg & create)   ? CREATE_ALWAYS : OPEN_EXISTING;

	hfile          = create_file(filename, access, creation);
	
	flags = (flg & readonly) | (hfile == INVALID_HANDLE_VALUE ? 0 : open);
	return !!(flags & open);
}

void FileIO::Close()
{
	uint32_t flags = GetFlags();
	if (flags & open)
	{
		file_close(hfile);
		flags = 0;
	}
}

void FileIO::Read(void* dest, int32_t size)
{
	size_t readsize;
	uint32_t flags = GetFlags();
	if ((flags & open))
		read_file(hfile, dest, size, &readsize);
}

bool FileIO::Seek(int32_t pos, int method)
{
   uint32_t flags = GetFlags();
	if (!(flags & open))
		return false;
	
	switch (method)
	{
		case 0:	
		case 1:	
		case 2:		
			return 0xffffffff != file_seek(hfile, pos, method);
		default:
         break;
	}
   return false;
}
