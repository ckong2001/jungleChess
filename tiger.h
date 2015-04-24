/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef TIGER_H
#define TIGER_H
#include "animal.h"
#include "GameBoard.h"

class tiger : public animal 
{
      public:
             tiger();      
             tiger ( int player_s , int Y , int X  ) ; 
             virtual bool move (  int dy , int dx ) ;
};


#endif
