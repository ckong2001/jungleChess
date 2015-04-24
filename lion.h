/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#ifndef LION_H
#define LION_H
#include "GameBoard.h"
class animal;
class lion : public animal 
{
      public:
             lion();      
             lion ( int player_s , int X , int Y  ) ; 
             virtual bool move (  int dy , int dx ) ;
      
};


#endif
