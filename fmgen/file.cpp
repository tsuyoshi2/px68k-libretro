//	$fmgen-Id: file.cpp,v 1.6 1999/12/28 11:14:05 cisc Exp $

#include "common.h"

#include "file.h"
#include "../libretro/fileio.h"

// ---------------------------------------------------------------------------
//	構築/消滅
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
//	ファイルを開く
// ---------------------------------------------------------------------------

bool FileIO::Open(const char* filename, uint32_t flg)
{
	Close();

	DWORD access   = (flg & readonly  ? 0 : GENERIC_WRITE) | GENERIC_READ;
	DWORD creation = (flg & create)   ? CREATE_ALWAYS : OPEN_EXISTING;

	hfile          = create_file(filename, access, creation);
	
	flags = (flg & readonly) | (hfile == INVALID_HANDLE_VALUE ? 0 : open);
	return !!(flags & open);
}

// ---------------------------------------------------------------------------
//	ファイルを閉じる
// ---------------------------------------------------------------------------

void FileIO::Close()
{
	uint32_t flags = GetFlags();
	if (flags & open)
	{
		file_close(hfile);
		flags = 0;
	}
}

// ---------------------------------------------------------------------------
//	ファイル殻の読み出し
// ---------------------------------------------------------------------------

void FileIO::Read(void* dest, int32_t size)
{
	size_t readsize;
	uint32_t flags = GetFlags();
	if ((flags & open))
		read_file(hfile, dest, size, &readsize);
}

// ---------------------------------------------------------------------------
//	ファイルへの書き出し
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//	ファイルをシーク
// ---------------------------------------------------------------------------

bool FileIO::Seek(int32_t pos, SeekMethod method)
{
        uint32_t flags = GetFlags();
	if (!(flags & open))
		return false;
	
	DWORD wmethod;
	switch (method)
	{
	case begin:	
		wmethod = FILE_BEGIN; 
		break;
	case current:	
		wmethod = FILE_CURRENT; 
		break;
	case end:		
		wmethod = FILE_END; 
		break;
	default:
		return false;
	}

	return 0xffffffff != set_file_pointer(hfile, pos, wmethod);
}
