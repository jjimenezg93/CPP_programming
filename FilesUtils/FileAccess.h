#pragma once

unsigned int openFile(const char * fileName, const char * fileMode);

unsigned int closeFile(unsigned int &fileId);

unsigned int readFile(const unsigned int &fileId, const short int numCharToRead, char * buffer);

unsigned int writeFile(unsigned int &fileId, const short int numCharToWrite, const char * buffer);