#pragma once

#include "Animal.h"

class Fish : public Animal {
public:
	virtual void move();

	virtual void breath();
};