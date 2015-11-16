#pragma once

#include "CStream.h"

struct CCom: CStream {
public:

	CCom();

	virtual int openStream(unsigned int idStream);		//returns 1 if ok, 0 if error

	virtual int closeStream();		//returns 1 if ok, 0 if error

	virtual int readStream();		//returns number of chars read from m_fileId

	virtual int writeStream(char * buffer);		//returns number of chars written in m_fileId from buffer

private:
	unsigned int m_comId;		//memory address of SerialPort buffer
};