#pragma once

#include <stdio.h>

struct TFile {
public:
	TFile(const char * fileName);

	unsigned int openFile(const char * fileMode);

	int closeFile();

	unsigned int readFile(const short int numCharToRead, char * buffer);

	unsigned int writeFile(const short int numCharToWrite, char * buffer);

	//función extra para main()
	short int fileSize();

private:
	const char * m_fileName;
	FILE * m_file;					//debería ser FILE * const, pero las funciones fopen, fread... no lo aceptan
};