/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/





#include<iostream>
#include "item.h"
#include "landscape.h"
#include "player.h"
#ifndef TRAP_H
#define TRAP_H

class trap : public landscape 
{
      private:
             int owner_no ; 
      public:
             trap();
             trap( int X , int Y , player* );
             virtual bool check_moved (animal* , int dx , int dy ) ; 
             virtual bool moved_by_other ( animal* a , int dy , int dx ) ;
             virtual bool left_by_animal ( animal* ) ;
             virtual ~trap () {} ; 
};



#endif
