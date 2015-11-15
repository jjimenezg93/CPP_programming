#pragma warning(disable: 4514)
#pragma warning(disable: 4710)

#pragma once
#include <cstdio>

class Animal {
public:
	Animal() { this->run(); }

	virtual void move() { printf_s("WALKING AS AN ANIMAL\n"); }	//pure virtual function

	virtual void run() { printf_s("RUNNING AS AN ANIMAL\n"); }

	virtual void breath() = 0;		//pure virtual function
};