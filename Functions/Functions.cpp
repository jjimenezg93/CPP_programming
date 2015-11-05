/*
Julián Jiménez González
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include <stdlib.h>

char * stringExists(char ** const tablePtr, char * &sExist, const unsigned short int tableSize, const unsigned short int index) {
	if (index < tableSize) {
		char flag = 'a';
		unsigned short int stringSize = 0;

		char * ptr = tablePtr[0];

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

char * invString(char ** const origTablePtr, char * &invTable, const unsigned short int index) {
	char flag = 'a';
	unsigned short int stringSize = 0;		//tamaño del string, no cuenta '\0'

	const char *charTablePtr = origTablePtr[index];		//charTablePtr apunta al primer carácter de la cadena indicada con index

	//se cuenta el número de caracteres del string, y se guardan en stringSize
	while (flag) {
		if (*charTablePtr != '\0') {
			stringSize++;
			charTablePtr++;
		} else
			flag = '\0';
	}

	//cuando el bucle termina, charTablePtr está apuntando a '\0'
	//se aprovecha para recorrer a la inversa, también se podría restaurar a tablePtr[index]
	charTablePtr--;		//si no se disminuye, lo que se hará en el for será meter un '\0' de primero,
					//con lo que siempre devolverá una cadena vacía
	
	for (unsigned short int i = 0; i < stringSize; i++){
		invTable[i] = *charTablePtr;
		charTablePtr--;
	}
	
	invTable[stringSize] = '\0';		//hay que introducir el caráter de fin de cadena

	return invTable;
}

int main() {
	char *table[] = { "hola", "que", "tal"};
	const unsigned short int tableSize = sizeof(table) / sizeof(*table);
	printf_s("tableSize = %d\n", tableSize);
	
	char * sExist = (char*)malloc(40);
	sExist = stringExists(table, sExist, tableSize, 2);	//puntero a zona de malloc, que se sobreescribe aquí
	printf_s("stringExists = %s\n", sExist);

	char * invS = (char*)malloc(20);
	invS = invString(table, invS, 0);
	printf_s("invString = %s\n", invS);
	free(invS);
	free(sExist);
}