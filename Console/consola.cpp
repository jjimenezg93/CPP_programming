#pragma warning(disable: 4668)
#pragma warning(disable: 4820)

#include <windows.h>

// ***************************************************************************************
// FUNCIONES AUXILIARES DE PINTADO
// ***************************************************************************************
void gotoxy(short int x, short int y)
{ 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
	system("cls");
}