/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4668)
#pragma warning(disable: 4820)
#pragma warning(disable: 4710)

#include <list>
#include <stdio.h>
#include <Windows.h>
#include "consola.h"

#define MINWIDTH 10
#define MAXWIDTH 70
#define MINHEIGHT 5
#define MAXHEIGHT 20
#define MAXLIFE 255
#define MINLIFE 1

struct TEntity;
typedef void(*funcEntity)(TEntity *);

unsigned int randomNum;				//used for random movement of entity 3

// ***************************************************************************************
// ENTITY
// ***************************************************************************************
struct TEntity {
	int m_ix;
	int m_iy;
	const funcEntity *m_funcs;

	unsigned char life;

	short int m_ox;	//origin x
	short int m_oy;	//origin y
	short int m_dx;	//direction x flag. 0 = right, 1 = left
	short int m_dy;	//direction y flag. 0 = down, 1 = up
	unsigned short int m_stringSize;
	TEntity(const funcEntity *funcs, unsigned short int sSize, int x, int y, short int dx = 0, short int dy = 0) {
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;

		life = static_cast<unsigned char>(rand() % (MAXLIFE - MINLIFE + 1));

		m_ox = static_cast<short int>(x);
		m_oy = static_cast<short int>(y);
		m_dx = dx;
		m_dy = dy;
		m_stringSize = sSize;
	}

	~TEntity() {
		printf_s("DESTRUCTOR");
	}
};

//entity1 -> fish
void Entity1_print(TEntity * const ent) {
	gotoxy(static_cast<short int>(ent->m_ix), static_cast<short int>(ent->m_iy));
	printf_s(">-<==^=:>");
}

void Entity1_move(TEntity * const ent) {
	//set x direction
	if (static_cast<short int>(ent->m_ix - ent->m_ox) >= static_cast<short int>(80 - ent->m_stringSize)) {
		ent->m_dx = 1;
	} else if (static_cast<short int>(ent->m_ix - ent->m_ox) <= static_cast<short int>(0 + ent->m_stringSize)) {
		ent->m_dx = 0;
	}

	//x movement
	if (!(ent->m_dx))
		ent->m_ix++;
	else
		ent->m_ix--;
}

//entity2 -> bird
void Entity2_print(TEntity * const ent) {
	gotoxy(static_cast<short int>(ent->m_ix), static_cast<short int>(ent->m_iy));
	printf_s("/<'()'>\\");
}

void Entity2_move(TEntity * const ent) {
	//set y direction
	if (static_cast<short int>(ent->m_oy - ent->m_iy) >= static_cast<short int>(10)) {
		ent->m_dy = 0;
	} else if (static_cast<short int>(ent->m_oy - ent->m_iy) <= static_cast<short int>(0)) {
		ent->m_dy = 1;
	}

	//y movement
	if (!(ent->m_dy))
		ent->m_iy++;
	else
		ent->m_iy--;
}

//entity3 -> fox
void Entity3_print(TEntity * const ent) {
	gotoxy(static_cast<short int>(ent->m_ix), static_cast<short int>(ent->m_iy));
	printf_s("-^^,--,~");
}

void Entity3_move(TEntity * const ent) {
	//set x direction
	if (static_cast<short int>(ent->m_ox - ent->m_ix) >= static_cast<short int>(80 - ent->m_stringSize)) {
		ent->m_dx = 0;
	} else if (static_cast<short int>(ent->m_ox - ent->m_ix) <= static_cast<short int>(0 + ent->m_stringSize)) {
		ent->m_dx = 1;
	}

	//x movement
	if (!(ent->m_dx)) {
		ent->m_ix += 3;
	} else {
		ent->m_ix -= 3;
	}

	//random direction change
	if (randomNum % 2 == 0) {
		if (ent->m_dx == 0) {
			ent->m_dx = 1;
		} else
			ent->m_dx = 0;
	}

	//random jump
	if (randomNum >= 20 && randomNum <= 50) {
		ent->m_dy = 1;
		ent->m_iy -= (randomNum / 20);
	} else
		ent->m_iy = ent->m_oy;

}

//entity4 -> elephant
void Entity4_print(TEntity * const ent) {
	gotoxy(static_cast<short int>(ent->m_ix), static_cast<short int>(ent->m_iy));
	printf_s("</>ooo\\");
}

void Entity4_move(TEntity * const ent) {
	//set x direction
	if (static_cast<short int>(ent->m_ox - ent->m_ix) >= static_cast<short int>(80 - ent->m_stringSize)) {
		ent->m_dx = 0;
	} else if (static_cast<short int>(ent->m_ox - ent->m_ix) <= static_cast<short int>(0 + ent->m_stringSize)) {
		ent->m_dx = 1;
	}

	//x movement
	if (!(ent->m_dx)) {
		ent->m_ix += 4;
	} else {
		ent->m_ix -= 4;
	}

	if (static_cast<short int>(ent->m_oy - ent->m_iy) >= static_cast<short int>(2)) {
		ent->m_dy = 0;
	} else if (static_cast<short int>(ent->m_oy - ent->m_iy) <= static_cast<short int>(0)) {
		ent->m_dy = 1;
	}

	//y movement
	if (!(ent->m_dy)) {
		ent->m_iy++;
	} else {
		ent->m_iy--;
	}

}

const funcEntity tableFuncEntity1[] = { &Entity1_print, &Entity1_move };
const funcEntity tableFuncEntity2[] = { &Entity2_print, &Entity2_move };
const funcEntity tableFuncEntity3[] = { &Entity3_print, &Entity3_move };
const funcEntity tableFuncEntity4[] = { &Entity4_print, &Entity4_move };

//MEMORY MUST BE DEALLOCATED BY USER
TEntity * spawnNewEntity() {
	unsigned short int randSpawn = static_cast<unsigned short int>(rand());

	int randX = rand() % (MAXWIDTH - MINWIDTH + 1) + MINWIDTH;
	int randY = rand() % (MAXHEIGHT - MINHEIGHT + 1) + MINHEIGHT;

	if (!randSpawn) {
		//func entity
		TEntity * const newEntity = new TEntity(NULL, (sizeof(">-<==^=:>") - 1), randX, randY);

		newEntity->m_funcs = tableFuncEntity1;
		return newEntity;
	} else if (randSpawn % 6) {
		TEntity * const newEntity = new TEntity(NULL, (sizeof("/<'()'>\\") - 1), randX, randY);

		newEntity->m_funcs = tableFuncEntity2;
		return newEntity;
	} else if (randSpawn % 5) {
		TEntity * const newEntity = new TEntity(NULL, (sizeof("-^^,--,~") - 1), randX, randY, 1);

		newEntity->m_funcs = tableFuncEntity3;
		return newEntity;
	} else {
		TEntity * const newEntity = new TEntity(NULL, (sizeof("</>ooo\\") - 1), randX, randY, 1, 1);

		newEntity->m_funcs = tableFuncEntity4;
		return newEntity;
	}
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main(int argc, char* argv[]) {
	//WARNING C4100
	UNREFERENCED_PARAMETER(argc);	//WinNT.h
	UNREFERENCED_PARAMETER(argv);

	//fish
	TEntity * const entity1 = new TEntity(NULL, (sizeof(">-<==^=:>") - 1), 0, 0);
	entity1->m_funcs = tableFuncEntity1;

	//const funcEntity tableFuncEntity1[] = { &Entity1_print, &Entity1_move };

	//bird
	TEntity * const entity2 = new TEntity(NULL, (sizeof("/<'()'>\\") - 1), 0, 23);
	entity2->m_funcs = tableFuncEntity2;

	//const funcEntity tableFuncEntity2[] = { &Entity2_print, &Entity2_move };

	//fox
	TEntity * const entity3 = new TEntity(NULL, (sizeof("-^^,--,~") - 1), 72, 10, 1);
	entity3->m_funcs = tableFuncEntity3;

	//const funcEntity tableFuncEntity3[] = { &Entity3_print, &Entity3_move };

	//elephant
	TEntity * const entity4 = new TEntity(NULL, (sizeof("</>ooo\\") - 1), 76, 23, 1, 1);
	entity4->m_funcs = tableFuncEntity4;

	//const funcEntity tableFuncEntity4[] = { &Entity4_print, &Entity4_move };

	std::list<TEntity *> listEntity;
	std::list<TEntity *>::iterator itEntities;

	listEntity.push_back(entity1);
	listEntity.push_back(entity2);
	listEntity.push_back(entity3);
	listEntity.push_back(entity4);

#pragma warning(disable: 4127)		//warning conditional expression is constant
	//action loop
	while (1) {
		clear();

		if (listEntity.size() < 5) {
			listEntity.push_back(spawnNewEntity());
		}

		randomNum = static_cast<unsigned int>(rand() % 100 + 1);

		for (itEntities = listEntity.begin(); itEntities != listEntity.end(); itEntities++) {
			(*itEntities)->m_funcs[0](*itEntities);
			(*itEntities)->m_funcs[1](*itEntities);
			
			if ((*itEntities)->life <= 0) {
				delete *itEntities;
				itEntities = listEntity.erase(itEntities);
				if (itEntities == listEntity.end())	//if it is the last element and we don't break, it will try to execute itEntities++ and break
					break;
			} else
				(*itEntities)->life--;
		}

		Sleep(300);
	}
#pragma warning(default: 4127)
}