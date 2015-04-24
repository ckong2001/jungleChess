#include "textControl.h"
void ClearConsole()
{
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coordinate = {0,0};
     DWORD count;
     CONSOLE_SCREEN_BUFFER_INFO info;
     if(GetConsoleScreenBufferInfo(hStdOut,&info))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, info.dwSize.X * info.dwSize.Y, coordinate, &count);
          FillConsoleOutputAttribute(hStdOut, info.wAttributes, info.dwSize.X * info.dwSize.Y, coordinate, &count);
          SetConsoleCursorPosition(hStdOut, coordinate);
     }
}

extern void gotoXY(int x, int y)
{
     COORD coordinate = {x,y};     
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

extern void changeColour(int colour)
{
      
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,colour);
}
