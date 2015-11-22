
#include "Fish.h"
#include "Horse.h"

int main() {
	Fish f = Fish();
	Fish f2 = Fish();
	Horse h = Horse();

	Animal *pAnimal = &f;
	Animal *pAnimalH = &h;
	Fish   *pFish = &f;
	Horse *pHorse = &h;
	pAnimal->run();
	pFish->run();
	pFish->jump();
	pHorse->jump();
}