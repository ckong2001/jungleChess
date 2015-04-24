/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef RIVER_H
#define RIVER_H

#include "landscape.h"
#include "animal.h"
#include "GameBoard.h"
 class GameBoard ;
class river : public landscape 
{
      public:
             river ()  ;
             river ( int y,  int x) ;
             virtual bool moved_by_other ( animal*  , int dy , int dx  ) ;
             virtual bool check_moved (animal* , int dy , int dx )  ; 
             virtual bool left_by_animal ( animal* source ) ; 
             virtual ~river () {} ;
};



#endif

