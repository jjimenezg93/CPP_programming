/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <stdio.h>
#include "Tlist.h"

TList GetReverseList(TList lstSrc) {
	TList copy;
	const char * ptr;

	if (lstSrc.Size() > 0) {
		for (unsigned int l = 0; l < lstSrc.Size(); l++) {
			for (unsigned int i = 0; i < lstSrc.Size() - 2; i++) {
				lstSrc.Next();

			}
			ptr = lstSrc.Next();
			copy.Push(ptr);
		}
	}
	return copy;
}

TList * GetReverseList(TList &lstSrc, TList *listCopy) {
	const char * ptr;
	if (lstSrc.Size() > 0) {
		for (unsigned int l = 0; l < lstSrc.Size(); l++) {
			for (unsigned int i = 0; i < lstSrc.Size() - 2; i++) {
				lstSrc.Next();
			}
			ptr = lstSrc.Next();
			listCopy->Push(ptr);
		}
	}
	return listCopy;
}

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

	//copy constructor
	list->Push("Hola");
	list->Push("que");

	TList *list2 = new TList(*list);

	printf_s("list2.First() = %s\n", list2->First());
	printf_s("list2.Next() = %s\n", list2->Next());

	list2->Push("tal?");
	printf_s("list2.Next() = %s\n", list2->Next());

	delete list2;

	list->Push("tal");
	list->Push("estas?");

	//TList GetReverseList(TList lstSrc)
	TList listRev = GetReverseList(*list);

	printf_s("listRev.First() = %s\n", listRev.First());
	printf_s("listRev.Next() = %s\n", listRev.Next());
	printf_s("listRev.Next() = %s\n", listRev.Next());
	printf_s("listRev.Next() = %s\n", listRev.Next());

	//TList * GetReverseList(TList &lstSrc, TList *listCopy)
	//this is the way to avoid returning an object in the Stack
	TList * listInv = new TList();

	GetReverseList(*list, listInv);
	printf_s("listInv.First() = %s\n", listInv->First());
	printf_s("listInv.Next() = %s\n", listInv->Next());
	printf_s("listInv.Next() = %s\n", listInv->Next());
	printf_s("listInv.Next() = %s\n", listInv->Next());

	delete list;
	delete listInv;

	getchar();
}