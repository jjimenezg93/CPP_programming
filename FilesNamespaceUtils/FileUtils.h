/*
Julián Jiménez González
*/

#pragma once

#include "TList.h"

namespace FileUtils {
	unsigned int countString(const unsigned int &fileId, const char * string);

	int addIntegers(const unsigned int &fileId);

	TList * numsList(const unsigned int &fileId, TList * nums);
}