/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <stdio.h>
#include <cstdlib>
#include "TFile.h"

int main() {
	TFile file = TFile("file.txt");

	file.openFile("r");

	short int fSize = file.fileSize();

	char * buffer = (char *)malloc((static_cast<size_t>(sizeof(char) * fSize) + 1));

	file.readFile(fSize, buffer);

	buffer[fSize] = '\0';
	file.closeFile();

	unsigned short int i = 0;

	while (buffer[i] != '\0') {
		buffer[i] = 'X';
		i++;
	}

	file.openFile("r+");								//must be opened in r/w mode for the next fileSize()
	file.writeFile(fSize, buffer);
	//file.closeFile();			//commented to check in debug that destructor works fine
	free(buffer);
}