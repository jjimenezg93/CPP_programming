#ifndef _CTCP_H
#define _CTCP_H

#include "CStream.h"

struct CTcp : CStream {
public:

	CTcp();

	virtual int openStream(unsigned int idStream);		//returns 1 if ok, 0 if error

	virtual int closeStream();		//returns 1 if ok, 0 if error

	virtual int readStream();		//returns number of chars read from m_tcpSocketId

	virtual int writeStream(char * buffer);		//returns number of chars written in m_tcpSocketId from buffer

private:
	unsigned int m_tcpSocketId;		//memory address of socket structure, can be assigned to a pointer (e.g. CTcpSocket * ptr = m_tcpSocketId)
};

#endif