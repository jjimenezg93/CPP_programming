 /*
	Julián Jiménez González
*/

#pragma warning(disable: 4514)		//el compilador elimina funciones inline que no se utilizan (en este caso de la librería stdio)
#pragma warning(disable: 4710)		//la función dada está pensada para ser optimizada por el compilador mediante inlining. el warning indica que no se está produciendo la optimización

#include <stdio.h>

// PRÁCTICAS.
// 1.- Dado un entero obtener por separado cada uno de sus bytes usando operaciones de punteros. 
// 2.- Dada la tabla de enteros int tabla[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2}
//		 Realizar código que obtenga el entero mayor usando aritmética de punteros.
// 3.- Dada la tabla de caracteres char tabla[] = {'a', 'z', 'f', 'g', '2'}
//		 Realizar código que obtenga el caracter mayor usando aritmética de punteros.
// 4.- Igual que el 2 pero que obtenga la posición del byte mayor.
// 5.- Generar código que dada una cadena le de la vuelta: ejmp "hola" -> "aloh"

int main() {
	
	//1

	printf_s("\n---- 1 ----\n");

	unsigned int int1 = 2607000;	//si se hace const, no se puede crear un puntero void apuntando a él	

	void *ptr = &int1;

	unsigned char *ptrChar = static_cast<unsigned char *>(ptr);
	const unsigned char byte0 = *ptrChar;

	ptrChar = static_cast<unsigned char *>(ptr)+1;
	const unsigned char byte1 = *ptrChar;

	ptrChar = static_cast<unsigned char *>(ptr) + 2;
	const unsigned char byte2 = *ptrChar;

	ptrChar = static_cast<unsigned char *>(ptr) + 3;
	const unsigned char byte3 = *ptrChar;

	printf_s("int1 = 0x%x\n", int1);
	printf_s("byte0 = 0x%x\n", byte0);
	printf_s("byte1 = 0x%x\n", byte1);
	printf_s("byte2 = 0x%x\n", byte2);
	printf_s("byte3 = 0x%x\n", byte3);

	//2

	printf_s("\n---- 2 ----\n");

	int table2[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };			//0xFFFFFFFF se traduce en -1

	const int *ptr2 = table2;	//evitar que ptr2 modifique la tabla
	int max2 = table2[0];
	unsigned short int tableSize2 = sizeof(table2) / sizeof(table2[0]);		//el tamaño que devuelve sizeof(tabla) es la cantidad de bytes de todos sus elementos

	printf_s("tableSize2 = %d\n", tableSize2);

	for (int i = 0; i < tableSize2; i++) {
		if (*ptr2 > max2)
			max2 = *ptr2;
		ptr2++;
	}

	printf_s("Mayor2 = %d\n", max2);

	//3

	printf_s("\n---- 3 ----\n");

	char table3[] = { 'a', 'z', 'f', 'g', '2' };		//el código ASCII más alto es el de 'z', 122

	const char *ptr3 = table3;	//evitar que ptr3 modifique la tabla
	char max3 = table3[0];
	unsigned short int tableSize3 = sizeof(table3)/sizeof(table3[0]);		//el tamaño que se guarda es la cantidad de bytes de todos los elementos de la tabla

	for (int i = 0; i < tableSize3; i++) {
		if (*ptr3 > max3)	//0xFFFFFFFF se traduce en -1
			max3 = *ptr3;
		ptr3++;
	}

	printf_s("Mayor3 = %c\n", max3);

	//4

	printf_s("\n---- 4 ----\n");

	int table4[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };			//0xFFFFFFFF se traduce en -1

	unsigned char *ptr4 = reinterpret_cast<unsigned char *>(table4);			//evitar que ptr2 modifique la tabla

	unsigned char *max4;
	unsigned int maxValue4 = 0;
	unsigned char tableSize4 = sizeof(table4);		//hay que comprobar byte a byte

	for (int i = 0; i < tableSize4; i++) {
		unsigned char *ptrChar4 = ptr4 + i;
		/*	comprobación de posición/valor de cada byte
		printf_s("posicion -> %x\n", ptrChar4);
		printf_s("Valor = 0x%x\n", *ptrChar4); */
		if (*ptrChar4 > maxValue4) {
			maxValue4 = *ptrChar4;
			max4 = ptrChar4;
		}
	}

	printf_s("Valor Byte mayor4 = 0x%x\n", *max4);
	printf_s("Posicion Byte mayor4 = 0x%x\n", reinterpret_cast<unsigned int>(max4));

	//5

	printf_s("\n---- 5 ----\n");

	const char table5[] = "hola";
	unsigned char tableSize = sizeof(table5);
	char invTable5[sizeof(table5)];		//problema si hay alguna intercalación entre las instrucciones -> solución?

	printf_s("tableSize = %d\n", tableSize);
	printf_s("invTableSize = %d\n", tableSize);

	invTable5[tableSize - 1] = '\0';

	//relleno de invTable
	for (unsigned short int i = 0; i < tableSize; i++) {
		if (table5[i])
			invTable5[tableSize - i - 1] = table5[i];
	}

	printf_s("table = ");

	//display de table
	for (unsigned short int i = 0; i < tableSize - 1; i++) {
		printf_s("%c", table5[i]);
	}

	printf_s("\ninvTable = ");
	
	//display de invTable
	for (unsigned short int i = 1; i < tableSize; i++) {
		printf_s("%c", invTable5[i]);
	}
	printf_s("\n");
	
	getchar();

	return 0;
}