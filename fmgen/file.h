//	$fmgen-Id: file.h,v 1.6 1999/11/26 10:14:09 cisc Exp $

#if !defined(win32_file_h)
#define win32_file_h

#include <stdint.h>

// ---------------------------------------------------------------------------

class FileIO
{
public:
	enum Flags
	{
		open		= 0x000001,
		readonly	= 0x000002,
		create		= 0x000004,
	};

	enum SeekMethod
	{
		begin = 0, current = 1, end = 2,
	};

	enum Error
	{
		success = 0,
		file_not_found,
		sharing_violation,
		unknown = -1
	};

public:
	FileIO();
	FileIO(const char* filename, uint32_t flg = 0);
	virtual ~FileIO();

	bool Open(const char* filename, uint32_t flg = 0);
	bool CreateNew(const char* filename);
	void Close();
	Error GetError() { return error; }

	int32_t Read(void* dest, int32_t len);
	int32_t Write(const void* src, int32_t len);
	bool Seek(int32_t fpos, SeekMethod method);

	uint32_t GetFlags() { return flags; }
	void SetLogicalOrigin(int32_t origin) { lorigin = origin; }

private:
	HANDLE hfile;
	uint32_t flags;
	uint32_t lorigin;
	Error error;
	char path[MAX_PATH];
	
	FileIO(const FileIO&);
	const FileIO& operator=(const FileIO&);
};

#endif // 
