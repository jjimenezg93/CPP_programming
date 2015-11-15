#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#include <cstdio>
#include "Fish.h"

Fish::Fish() {
	this->move();
}

void Fish::move() {
	printf_s("Swimming in the ocean!\n");
}

void Fish::run() {
	printf_s("I can't run!\n");
}

void Fish::breath() {
	printf_s("Glugluglu\n");
}

void Fish::jump() {
	printf_s("Jumping in the sea\n");
}