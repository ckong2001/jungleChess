/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef DEN_H
#define DEN_H
#include "item.h"
#include "landscape.h"
#include "Game.h"

class den : public landscape 
{
       private:
             Game* game ; 
             int owner_no ;
       public:
             den ()  ;
             den ( int y,  int x) ;
             void setGame ( Game* game ) ;
             void setOwnerNo (int ) ; 
             virtual bool moved_by_other ( animal*  , int dy , int dx  ) ;
             virtual bool check_moved (animal* , int dy , int dx )  ; 
             virtual ~den () {} ;      
      
      
      
      
} ; 


#endif
