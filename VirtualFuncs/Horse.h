#ifndef _HORSE_H
#define _HORSE_H

#include "Animal.h"

class Horse : public Animal {
public:
	virtual void move();

	virtual void run();

	virtual void breath();

	void jump();
};

#endif