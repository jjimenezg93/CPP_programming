#pragma once

#include "Animal.h"

class Horse : public Animal {
public:
	virtual void move();

	virtual void breath();
};