/*
	Julián Jiménez González
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstring>		//strstr
#include <cstdlib>		//malloc-atoi
#include <cctype>		//isdigit
#include "FileAccess.h"
#include "TList.h"

namespace FileUtils {
	unsigned int countString(const unsigned int &fileId, const char * string) {
		FILE * file = reinterpret_cast<FILE *>(fileId);
		char * ptr;
		unsigned short int count = 0;

		fseek(file, 0, SEEK_END);

		short int numChars = static_cast<short int>(ftell(file));

		fseek(file, 0, SEEK_SET);

		ptr = (char*)malloc(static_cast<size_t>(numChars + 1));

		fread_s(ptr, static_cast<size_t>(numChars), sizeof(*ptr), static_cast<size_t>(numChars), file);
		*(ptr + numChars) = '\0';

		while (ptr) {
			ptr = strstr(ptr, string);
			if (ptr) {
				count++;
				ptr++;
			} else
				break;
		}
		delete ptr;
		return count;
	}

	int addIntegers(const unsigned int &fileId) {
		int sum = 0;
		FILE * file = reinterpret_cast<FILE *>(fileId);
		char *ptr;			//debería ser const, pero entonces no es aceptado por fread_s

		fseek(file, 0, SEEK_END);

		short int numChars = static_cast<short int>(ftell(file));

		fseek(file, 0, SEEK_SET);

		ptr = (char*)malloc(static_cast<size_t>(numChars) + 1);

		fread_s(ptr, static_cast<size_t>(numChars), sizeof(*ptr), static_cast<size_t>(numChars), file);
		*(ptr + numChars) = '\0';

		for (unsigned short int i = 0; i < numChars; i++) {
			if (*ptr != ',' && isdigit(*ptr)) {
				sum += atoi(ptr);
				ptr = strstr(ptr, ",");
				if (!ptr)
					break;
			} else if (*ptr == '-') {
				ptr++;
				sum -= atoi(ptr);
				ptr = strstr(ptr, ",");
			} else if (*ptr == ',')
				ptr++;
		}
		delete ptr;
		return sum;
	}

	TList * numsList(const unsigned int fileId, TList *nums) {
		FILE * file = reinterpret_cast<FILE *>(fileId);
		char *ptr;
		char *aux;
		char *filePtr;

		fseek(file, 0, SEEK_END);

		short int numChars = static_cast<short int>(ftell(file));

		fseek(file, 0, SEEK_SET);

		filePtr = (char*)malloc(static_cast<size_t>(numChars) + 1);

		fread_s(filePtr, static_cast<size_t>(numChars), sizeof(*filePtr), static_cast<size_t>(numChars), file);
		*(filePtr + numChars) = '\0';
		aux = ptr = filePtr;

		for (unsigned short int i = 0; i < numChars; i++) {
			aux = strstr(aux, ",");
			if (!aux) {
				break;
			} else {
				*aux = '\0';
				nums->Push(ptr);
				printf_s("Pushed %s\n", ptr);

				ptr = aux;
				aux++;
				ptr++;
			}
		}

		nums->Push(ptr);
		printf_s("Pushed %s\n", ptr);

		free(filePtr);

		return nums;
	}
}

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

	//numsList

	TList * nums = new TList();

	FileUtils::numsList(fileIntegersId, nums);

	delete nums;

	getchar();
}