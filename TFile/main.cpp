/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstdlib>
#include "TFile.h"

int main() {
	TFile file = TFile("file.txt");

	char * buffer = (char *)malloc(static_cast<size_t>(100));

	file.openFile("r");
	file.readFile(file.fileSize(), buffer);

	buffer[file.fileSize()] = '\0';
	file.closeFile();

	unsigned short int i = 0;

	while (buffer[i] != '\0') {
		buffer[i] = 'X';		//modificamos el mismo buffer, con el que luego reescribiremos
		i++;
	}

	file.openFile("r+");								//cuidado con abrirlo en modo r/w para el fileSize() siguiente
	file.writeFile(file.fileSize(), buffer);
	file.closeFile();
	free(buffer);
}