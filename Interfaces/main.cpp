/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdlib>
#include <stdio.h>
#include "Tlist.h"
#include "TApple.h"
#include "TPear.h"

int main() {
	int * intPtr = (int *)malloc(sizeof(int));
	*intPtr = 7;

	char * charPtr = "hola";
	TApple *ta = new TApple(intPtr);
	TPear *tp = new TPear(charPtr);

	TList list;

	list.Push(ta);
	list.Push(tp);

	list.First()->printElement();
	list.Next()->printElement();
	list.Next()->printElement();

	free(intPtr);
	free(ta);
	free(tp);

	getchar();
}