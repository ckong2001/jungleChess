/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#ifndef TEXTCONTROL_H
#define TEXTCONTROL_H
#include <windows.h>

// This function clears the console screen

inline void ClearConsole()
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

// This function sets the position of the cursor
inline void gotoXY(int x, int y)
{
     COORD coordinate = {x,y};     
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

// This function changes the colour of text and background
inline void changeColour(int colour)
{
      
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,colour);
}
#endif
