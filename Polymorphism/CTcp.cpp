#pragma warning(disable: 4514)
#pragma warning(disable: 4710)
#pragma warning(disable: 4668)
#pragma warning(disable: 4820)

#include <cstdio>
#include <windows.h>
#include "CTcp.h"

CTcp::CTcp() {
	printf_s("Creating CTcp\n");
}

int CTcp::openStream(unsigned int idStream) {
	UNREFERENCED_PARAMETER(idStream);
	printf_s("Opening CTcp with idStream (saving it in m_tcpSocketId)\n");
	return 0;
}

int CTcp::closeStream() {
	printf_s("Closing CTcp with m_tcpSocketId\n");
	return 0;
}

int CTcp::readStream() {
	printf_s("Reading characters from m_tcpSocketId\n");
	return 0;
}

int CTcp::writeStream(char * buffer) {
	UNREFERENCED_PARAMETER(buffer);
	printf_s("Writting characters from buffer in m_tcpSocketId\n");
	return 0;
}
