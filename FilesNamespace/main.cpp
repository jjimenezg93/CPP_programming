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
	unsigned int fileId = FileAccess::openFile("file.txt", "r");

	printf_s("Searching for: \"hola\"\n");
	printf_s("Occurrences of \"hola\": %d\n", FileUtils::countString(fileId, "hola"));
	printf("closeFile(fileWrittenId) (0 ok)= %x\n", FileAccess::closeFile(fileId));

	//addIntegers
	unsigned int fileIntegersId = FileAccess::openFile("fileIntegers.txt", "r");

	int resIntegersFile = FileUtils::addIntegers(fileIntegersId);

	printf_s("resIntegersFile = %d\n", resIntegersFile);
}