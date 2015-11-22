/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _FILEUTILS_H
#define _FILEUTILS_H

#include "TList.h"

namespace FileUtils {
	unsigned int countString(const unsigned int fileId, const char * string);

	int addIntegers(const unsigned int fileId);

	//returns parameter TList * modified
	TList * numsList(const unsigned int fileId, TList * nums);
}

#endif