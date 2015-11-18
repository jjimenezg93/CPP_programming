/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include "Tlist.h"
#include "TNode.h"

int main() {
	TList *list = new TList();
	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Pop() = %s\n", list->Pop());

	list->Push("Hola");
	printf_s("Pushed \"Hola\"!\n");
	list->Push("Holita");
	printf_s("Pushed \"Holita\"!\n");
	list->Push("Que tal?");
	printf_s("Pushed \"Que tal?\"!\n");

	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());
	printf_s("list.Next() = %s\n", list->Next());

	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Pop() = %s\n", list->Pop());
	printf_s("list.First() = %s\n", list->First());

	list->Push("Hola");

	list->Reset();
	printf_s("list reset!\n");

	printf_s("list.First() = %s\n", list->First());
	printf_s("list.Next() = %s\n", list->Next());

	delete list;

	getchar();
}