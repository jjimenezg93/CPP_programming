#pragma warning(disable: 4710)
#pragma warning(disable: 4668)
#pragma warning(disable: 4820)

#include <cstdio>
#include <windows.h>
#include "CCom.h"

CCom::CCom() {
	printf_s("Creating CCom\n");
}

int CCom::openStream(unsigned int idStream)
{
	UNREFERENCED_PARAMETER(idStream);
	printf_s("Opening SerialPort with idStream (saving it in m_comId)\n");
	return 0;
}

int CCom::closeStream()
{
	printf_s("Closing SerialPort allocated in m_comId\n");
	return 0;
}

int CCom::readStream()
{
	printf_s("Reading characters from SerialPort stored in m_comId\n");
	return 0;
}

int CCom::writeStream(char * buffer)
{
	UNREFERENCED_PARAMETER(buffer);
	printf_s("Writting characters from buffer in m_comId\n");
	return 0;
}
