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
#ifndef ELEPHANT_H
#define ELEPHANT_H

class elephant : public animal 
{
      public:      
                   elephant() ; 
                   elephant(int player_s , int Y , int X ) ; 
                   bool moved_by_other (animal* , int dy , int dx ) ;
                   virtual bool check_moved (animal* source, int dy , int dx  ) ;
                   virtual ~elephant () {} ;  
};

#endif
