/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _FILEACCESS_H
#define _FILEACCESS_H

namespace FileAccess {
	unsigned int openFile(const char * fileName, const char * fileMode);

	unsigned int closeFile(const unsigned int fileId);

	unsigned int readFile(const unsigned int fileId, const short int numCharToRead, char * buffer);

	unsigned int writeFile(const unsigned int fileId, const short int numCharToWrite, const char * buffer);
}

#endif