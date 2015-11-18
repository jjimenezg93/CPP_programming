/*
Julián Jiménez González
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <stdlib.h>

char * stringExists(const char * const * tablePtr, char * sExist, const unsigned short int tableSize, const unsigned short int index) {
	if (index < tableSize) {
		char flag = 'a';
		unsigned short int stringSize = 0;

		const char * ptr = tablePtr[0];

		const char *charTablePtr = tablePtr[index];

		while (flag) {
			if (*charTablePtr != '\0') {
				stringSize++;
				charTablePtr++;
			} else
				flag = '\0';
		}

		ptr = tablePtr[index];

		for (unsigned short int i = 0; i < stringSize; i++) {
			sExist[i] = *ptr;
			ptr++;
		}

		sExist[stringSize] = '\0';
	} else {
		char ret[] = "Index invalido";

		char * ptr = ret;

		for (unsigned short int i = 0; i < sizeof(ret); i++) {
			sExist[i] = *ptr;
			ptr++;
		}
	}

	return sExist;
}

char * invString(const char * const * origTablePtr, char * invTable, const unsigned short int index) {
	char flag = 'a';
	unsigned short int stringSize = 0;		//it doesn't count '\0'

	const char *charTablePtr = origTablePtr[index];

	while (flag) {
		if (*charTablePtr != '\0') {
			stringSize++;
			charTablePtr++;
		} else
			flag = '\0';
	}

	charTablePtr--;
	
	for (unsigned short int i = 0; i < stringSize; i++){
		invTable[i] = *charTablePtr;
		charTablePtr--;
	}
	
	invTable[stringSize] = '\0';

	return invTable;
}

int main() {
	char *table[] = { "hola", "que", "tal"};
	const unsigned short int tableSize = sizeof(table) / sizeof(*table);
	printf_s("tableSize = %d\n", tableSize);
	
	char * sExist = (char*)malloc(40);
	sExist = stringExists(table, sExist, tableSize, 2);
	printf_s("stringExists = %s\n", sExist);

	char * invS = (char*)malloc(20);
	invS = invString(table, invS, 0);
	printf_s("invString = %s\n", invS);
	free(invS);
	free(sExist);
}