#include"ConsolParameter.h"

void Consol_parameter::SetColor(int text, int background) {

	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Consol_parameter::SetPosition(int x, int y) {

    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(hStdOut, point);
}

HANDLE Consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

