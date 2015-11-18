/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstdlib>
#include "FileAccess.h"

int main() {
	//OPEN FILE
	unsigned int fileId = openFile("file.txt", "rb");		//fileId = 0 if file could not be opened. memory address in other case

	fseek(reinterpret_cast<FILE *>(fileId), 0, SEEK_END);

	short int numChars = static_cast<short int>(ftell(reinterpret_cast<FILE *>(fileId)));		//ftell returns -1L if fails -> signed
																								//up to 32KB files
	char * table = (char *)malloc(static_cast<size_t>(numChars + 1));

	printf_s("numChars = %d\n", numChars);

	fseek(reinterpret_cast<FILE *>(fileId), 0, SEEK_SET);

	table[numChars] = '\0';

	//READ FILE
	unsigned int charRead = readFile(fileId, numChars, table);

	printf_s("Number of chars read = %d\n", charRead);
	printf("closeFile(fileId) (0 ok)= %x\n", closeFile(fileId));		//closeFile = 0 -> OK

	//WRITE FILE
	unsigned int fileWrittenId = openFile("fileWritten.txt", "wt");

	printf_s("Number of chars written = %d\n", writeFile(fileWrittenId, numChars, table));

	//CLOSE FILE
	printf("closeFile(fileWrittenId) (0 ok)= %x\n", closeFile(fileWrittenId));

	free(table);
}