#ifndef _TFILE_H
#define _TFILE_H

#include <stdio.h>

struct TFile {
public:
	//CARE deallocating memory of fileName. It doesn't create a copy
	TFile(const char * fileName);

	//returns ptr to the file (casted into unsigned int) if OK, 0 if file isn't opened
	unsigned int openFile(const char * fileMode);	

	//returns 0 if OK, EOF if fclose failure, 1 if file isn't opened
	int closeFile();

	//IF numCharToRead != 0 -> returns number of elements read if OK, != numCharToRead if ERROR, 0 if file isn't opened
	//ELSE returns 0
	unsigned int readFile(const short int numCharToRead, char * buffer);

	//IF numCharToRead != 0 -> returns number of elements read if OK, != numCharToWrite if ERROR, 0 if file isn't opened
	//ELSE returns 0
	unsigned int writeFile(const short int numCharToWrite, char * buffer);

	//NEEDS FILE OPENED, if not returns 0
	short int fileSize();

	~TFile();

private:
	const char * m_fileName;
	bool fileOpened;
	FILE * m_file;					//should be FILE * const, but fopen, fread... don't accept it
};

#endif