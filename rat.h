/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "animal.h"
#ifndef RAT_H
#define RAT_H

class rat : public animal 
{
      public:
             rat() ;
             rat ( int player_s , int Y , int X ) ; 
             bool moved_by_other (animal* ani , int dy , int dx )  ; 
             bool check_moved (animal* source  , int dy, int dx );
};

#endif
