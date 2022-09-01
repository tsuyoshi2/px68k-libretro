//	$fmgen-Id: file.h,v 1.6 1999/11/26 10:14:09 cisc Exp $

#ifndef _WIN32_FILE_H
#define _WIN32_FILE_H

#include <stdint.h>

class FileIO
{
public:
	enum Flags
	{
		open		= 0x000001,
		readonly	= 0x000002,
		create		= 0x000004,
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
	FileIO(const char* filename, uint32_t flg);
	virtual ~FileIO();

	bool Open(const char* filename, uint32_t flg);
	void Close();

	void Read(void* dest, int32_t len);
	bool Seek(int32_t fpos, int method);

private:
	void *hfile;
	uint32_t flags;
	
	FileIO(const FileIO&);
	const FileIO& operator=(const FileIO&);
};

#endif /* _WIN32_FILE_H */
