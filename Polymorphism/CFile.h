#ifndef _CFILE_H
#define _CFILE_H

#include "CStream.h"

struct CFile : CStream {
public:

	CFile();

	virtual int openStream(unsigned int idStream);		//returns 1 if ok, 0 if error

	virtual int closeStream();		//returns 1 if ok, 0 if error

	virtual int readStream();		//returns number of chars read from m_fileId

	virtual int writeStream(char * buffer);		//returns number of chars written in m_fileId from buffer

private:
	unsigned int m_fileId;		//memory address of file (e.g. TFile * file = m_fileId)
};

#endif