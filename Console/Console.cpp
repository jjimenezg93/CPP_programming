/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4668)
#pragma warning(disable: 4820)
#pragma warning(disable: 4710)

#include <stdio.h>
#include "consola.h"
#include <WinNT.h>

struct TEntity;
typedef void(*funcEntity)(TEntity *);

unsigned int randomNum;				//used for random movement of entity 3

// ***************************************************************************************
// ENTITY
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	const funcEntity *m_funcs;

	short int m_ox;	//origin x
	short int m_oy;	//origin y
	short int m_dx;	//direction x flag. 0 = right, 1 = left
	short int m_dy;	//direction y flag. 0 = down, 1 = up
	unsigned short int m_stringSize;
	TEntity(const funcEntity *funcs, unsigned short int sSize, int x, int y, short int dx = 0, short int dy = 0)		//dirección es 0,0 por defecto
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;

		m_ox = static_cast<short int>(x);
		m_oy = static_cast<short int>(y);
		m_dx = dx;
		m_dy = dy;
		m_stringSize = sSize;
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
	if (static_cast<short int>(ent->m_oy - ent->m_iy) >= static_cast<short int>(22)) {
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

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main(int argc, char* argv[])
{
	//WARNING C4100
	UNREFERENCED_PARAMETER(argc);	//WinNT.h
	UNREFERENCED_PARAMETER(argv);

	//fish
	TEntity * const entity1 = new TEntity(NULL, (sizeof(">-<==^=:>") - 1), 0, 0);
	
	const funcEntity tableFuncEntity1[] = { &Entity1_print, &Entity1_move };
	entity1->m_funcs = tableFuncEntity1;
	
	//bird
	TEntity * const entity2 = new TEntity(NULL, (sizeof("/<'()'>\\") - 1), 0, 23);

	const funcEntity tableFuncEntity2[] = { &Entity2_print, &Entity2_move };
	entity2->m_funcs = tableFuncEntity2;
	
	//fox
	TEntity * const entity3 = new TEntity(NULL, (sizeof("-^^,--,~") - 1), 72, 10, 1);

	const funcEntity tableFuncEntity3[] = { &Entity3_print, &Entity3_move };
	entity3->m_funcs = tableFuncEntity3;

	//elephant
	TEntity * const entity4 = new TEntity(NULL, (sizeof("</>ooo\\") - 1), 76, 23, 1, 1);

	const funcEntity tableFuncEntity4[] = { &Entity4_print, &Entity4_move };
	entity4->m_funcs = tableFuncEntity4;

	//tableEntities
	TEntity tableEntities[] = { *entity1, *entity2, *entity3, *entity4 };

	TEntity *ptrEntities;		//ptrEntities is initialized inside the loop, no need to do it here

#pragma warning(disable: 4127)		//warning conditional expression is constant
	//action loop
	while (1) {			
		clear();

		ptrEntities = tableEntities;

		randomNum = static_cast<unsigned int>(rand() % 100 + 1);

		for (unsigned short int i = 0; i < sizeof(tableEntities)/sizeof(tableEntities[0]); i++) {
			(ptrEntities->m_funcs[0])(ptrEntities);
			(ptrEntities->m_funcs[1])(ptrEntities);

			ptrEntities++;
		}

		Sleep(300);
	}
#pragma warning(default: 4127)
}