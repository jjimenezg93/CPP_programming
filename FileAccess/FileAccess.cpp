/*
	Julián Jiménez González
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

	return fread(buffer, sizeof(*buffer), static_cast<size_t>(numCharToRead), fileToRead);	//size_t 4 bytes, short int 2 bytes -> conversión segura
}

unsigned int writeFile(unsigned int &fileId, short int numCharToWrite, const char * buffer) {
	FILE * fileToWrite = reinterpret_cast<FILE *>(fileId);

	return fwrite(buffer, sizeof(*buffer), static_cast<size_t>(numCharToWrite), fileToWrite);		//size_t 4 bytes, short int 2 bytes -> conversión segura
}

int main() {
	//OPEN FILE
	unsigned int fileId = openFile("file.txt", "rb");		//si no se ha podido abrir el fichero, fileId = 0. si no, la dirección del fichero abierto

	fseek(reinterpret_cast<FILE *>(fileId), 0, SEEK_END);

	short int numChars = static_cast<short int>(ftell(reinterpret_cast<FILE *>(fileId)));		//ftell retorna -1L si falla -> tiene que ser signed
																								//siendo signed short puede leer ficheros de hasta 32KB
	char * table = (char *)malloc(static_cast<size_t>(numChars + 1));

	printf_s("numChars = %d\n", numChars);

	fseek(reinterpret_cast<FILE *>(fileId), 0, SEEK_SET);
	
	table[numChars] = '\0';					//hay que meter el \0 manualmente al final

	//READ FILE
	unsigned int charRead = readFile(fileId, numChars, table);

	printf_s("Number of chars read = %d\n", charRead);
	printf("closeFile(fileId) (0 ok)= %x\n", closeFile(fileId));		//closeFile = 0 -> fichero correctamente cerrado

	//WRITE FILE
	unsigned int fileWrittenId = openFile("fileWritten.txt", "wt");

	printf_s("Caracteres escritos = %d\n", writeFile(fileWrittenId, numChars, table));

	//CLOSE FILE
	printf("closeFile(fileWrittenId) (0 ok)= %x\n", closeFile(fileWrittenId));

	free(table);
}