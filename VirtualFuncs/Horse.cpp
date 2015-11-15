#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdio>
#include "Horse.h"

void Horse::move() {
	printf_s("Walking like a horse!\n");
}

void Horse::run() {
	printf_s("Running like a horse!\n");
}

void Horse::breath() {
	printf_s("Fresh air!\n");
}