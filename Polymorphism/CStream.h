#pragma once

struct CStream {
public:
	virtual int openStream(unsigned int idStream) = 0;

	virtual int closeStream() = 0;

	virtual int readStream() = 0;

	virtual int writeStream(char * buffer) = 0;
};