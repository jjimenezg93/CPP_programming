/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <cstring>		//strstr
#include <cstdlib>		//malloc-atoi
#include <cctype>		//isdigit
#include "FileAccess.h"

unsigned int countString(const unsigned int fileId, const char * string) {
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

int addIntegers(const unsigned int fileId) {
	int sum = 0;
	FILE * file = reinterpret_cast<FILE *>(fileId);
	char *ptr;			//this should be const char *, but fread_s doesn't accept it

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