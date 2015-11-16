#pragma warning(disable: 4514)
#pragma warning(disable: 4710)
#pragma warning(disable: 4668)
#pragma warning(disable: 4820)

#include <cstdio>
#include <windows.h>
#include "CFile.h"

CFile::CFile() {
	printf_s("Creating CFile\n");
}

int CFile::openStream(unsigned int idStream)
{
	UNREFERENCED_PARAMETER(idStream);
	printf_s("Opening CFile with idStream (saving it in m_fileId)\n");
	return 0;
}

int CFile::closeStream()
{
	printf_s("Closing CFile allocated in m_fileId\n");
	return 0;
}

int CFile::readStream()
{
	printf_s("Reading characters from file m_fileId\n");
	return 0;
}

int CFile::writeStream(char * buffer)
{
	UNREFERENCED_PARAMETER(buffer);
	printf_s("Writting characters from buffer in m_fileId\n");
	return 0;
}
