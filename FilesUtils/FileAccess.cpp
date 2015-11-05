/*
	Juli�n Jim�nez Gonz�lez
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstdlib>		//malloc-atoi

unsigned int openFile(const char * fileName, const char * fileMode) {
	FILE *file;

	fopen_s(&file, fileName, fileMode);

	return reinterpret_cast<unsigned int>(file);
}

unsigned int closeFile(unsigned int &fileId) {
	FILE * file = reinterpret_cast<FILE *>(fileId);
	return static_cast<unsigned int>(fclose(file));
}

unsigned int readFile(const unsigned int &fileId, const short int numCharToRead, char * buffer) {
	FILE *fileToRead = reinterpret_cast<FILE *>(fileId);

	return fread(buffer, sizeof(*buffer), static_cast<size_t>(numCharToRead), fileToRead);	//size_t 4 bytes, short int 2 bytes -> conversi�n segura
}

unsigned int writeFile(unsigned int &fileId, short int numCharToWrite, const char * buffer) {
	FILE * fileToWrite = reinterpret_cast<FILE *>(fileId);

	return fwrite(buffer, sizeof(*buffer), static_cast<size_t>(numCharToWrite), fileToWrite);		//size_t 4 bytes, short int 2 bytes -> conversi�n segura
}