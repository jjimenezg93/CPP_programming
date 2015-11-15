#pragma once

#include "Animal.h"

class Fish : public Animal {
public:
	Fish();
	
	virtual void move();

	virtual void run();

	virtual void breath();

	void jump();
};