/*
	Juli�n Jim�nez Gonz�lez
*/

#pragma warning(disable: 4514)		//el compilador elimina funciones inline que no se utilizan (en este caso de la librer�a stdio)
#pragma warning(disable: 4710)		//la funci�n dada est� pensada para ser optimizada por el compilador mediante inlining. el warning indica que no se est� produciendo la optimizaci�n

#include <stdio.h>
#include <cstdlib>

// Ejemplo de informaci�n empaquetada.
// en un entero de 32 bits tenemos:
// 8 bits mayor peso la vida
// siguientes 8 bits: n�mero de balas.
// Siguientes 4 bits: n�mero de compa�eros.
// bit 0: invulnerable
// bit 1: balas infinitas.
// bit 2: escudo.
// bit 3: berseker mode.

// Hacer la siguiente pr�ctica.
// Para almacenar el estado de un personaje se utiliza la variable
// que est� empaquetada seg�n el formato de arriba.
// 1.- Hacer una funci�n que pasado un valor retorne el n�mero de balas
// 2.- Hacer una funci�n que a�ada un n�mero de balas a las ya existentes.
// 3.- Hacer una funci�n que pasado un valor retorne si se tienen balas infinitas
// 4.- Hacer una funci�n ponga modo de balas infinitas.

unsigned char returnAmmo(int player) {
	unsigned char toRet;
	toRet = static_cast<unsigned char>((player & 0x00FF0000) >> 16);	//warning "possible loss of data" en la conversi�n de int a unsigned char.
													//al desplazar el byte a las posiciones de menor peso, son �stas las posiciones que quedan en el paso a unsigned char, el cast es seguro
	return toRet;
}

int addAmmo(int &player, unsigned int ammoToAdd) {	//unsigned para evitar que pueda meterse un n�mero negativo, que restar�a ammo
	unsigned char currentAmmo = returnAmmo(player);
	ammoToAdd += currentAmmo;

	// 8bits ammo -> 0 < ammo < 255
	if (ammoToAdd >= 255)
		ammoToAdd = 255;
	ammoToAdd <<= 16;

	player &= 0xFF00FFFF;	//primero se borran las balas que hubiera
	player |= ammoToAdd;	//ammoToAdd es un unsigned int para que esta operaci�n sea m�s sencilla, aunque su informaci�n cabr�a en un unsigned char

	return player;
}

bool infiniteAmmo(const int &player) {
	int infinite = player & 0x00000002;
	if (!infinite)
		return false;
	else return true;
}

int activateInfiniteAmmo(int &player) {
	player |= 0x00000002;
	return player;
}

using namespace std;

int main()
{
	unsigned char flag = 1;
	unsigned char option;

	int playerInfo;
	unsigned char ammo = 0;		//ammo s�lo ocupa 1byte en playerInfo

	printf_s("Introduce datos de player (hexadecimal): 0x");
	scanf_s("%x", &playerInfo);			//scanf_s guarda en una posici�n de memoria, por eso hay que pasarle referencia
	
	fseek(stdin, 0, SEEK_END);			//limpieza del buffer de scanf, para evitar que al meter un car�cter hexadecimal no v�lido, el switch entre en bucle por default

	while (flag) {
		printf_s("---MENU---\n");
		printf_s("Info de player: 0x%x\n", playerInfo);
		printf_s("1 - Retornar numero de balas\n");
		printf_s("2 - Anadir 10 balas\n");
		printf_s("3 - Balas infinitas?\n");
		printf_s("4 - Activar balas infinitas\n");
		printf_s("5 - Salir\n");

		scanf_s("%hhu", &option);		//%hhu para que recoja el valor como un unsigned char

		switch (option)
		{
		case 1:
			system("CLS");

			ammo = returnAmmo(playerInfo);

			printf_s("Numero de balas: %hhu\n", ammo);
			break;

		case 2:
			system("CLS");

			if (returnAmmo(playerInfo) < 255) {
				playerInfo = addAmmo(playerInfo, 10);
				ammo = returnAmmo(playerInfo);

				printf_s("Balas anadidas!\n");
				printf_s("Numero de balas: %hhu\n", ammo);
			} else
				printf_s("Maximo de balas alcanzado\n");

			break;

		case 3:
			system("CLS");

			printf_s("Balas infinitas (0=false, 1=true)? %d\n", infiniteAmmo(playerInfo));
			break;

		case 4:
			system("CLS");

			if (!infiniteAmmo(playerInfo)) {
				playerInfo = activateInfiniteAmmo(playerInfo);

				printf_s("Balas infinitas activadas!\n");
				printf_s("Balas infinitas? %d\n", infiniteAmmo(playerInfo));
			} else
				printf_s("Modo balas infinitas ya activado\n");

			break;

		case 5:
			system("CLS");

			flag = 0;
			break;

		default:
			system("CLS");

			break;
		}
	}

	return 0;
}