/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstdlib>
#include "FileAccess.h"
#include "FileUtils.h"

int main() {
	//countString
	unsigned int fileId = openFile("file.txt", "r");

	printf_s("Searching for: \"hola\"\n");
	printf_s("Occurrences of \"hola\": %d\n", countString(fileId, "hola"));
	printf("closeFile(file.txt) (0 ok)= %x\n", closeFile(fileId));

	//addIntegers
	unsigned int fileIntegersId = openFile("fileIntegers.txt", "r");

	int resIntegersFile = addIntegers(fileIntegersId);

	printf_s("resIntegersFile = %d\n", resIntegersFile);
	printf("closeFile(fileIntegers.txt) (0 ok)= %x\n", closeFile(fileId));
}