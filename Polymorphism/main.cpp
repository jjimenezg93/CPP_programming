#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdio>

#include "CTcp.h"
#include "CFile.h"
#include "CCom.h"

int main() {

	CFile file1 = CFile();
	CFile file2 = CFile();

	CTcp tcp1 = CTcp();
	CTcp tcp2 = CTcp();

	CCom com1 = CCom();
	CCom com2 = CCom();

	CStream * table[] = { &file1, &file2, &tcp1, &tcp2, &com1, &com2 };

	for (unsigned int i = 0; i < sizeof(table) / sizeof(*table[0]); i++) {
		table[i]->readStream();
	}

	for (unsigned int i = 0; i < sizeof(table) / sizeof(*table[0]); i++) {
		table[i]->closeStream();
	}

	getchar();

	return 0;
}