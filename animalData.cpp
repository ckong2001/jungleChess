#include "animalData.h"
/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/
animalData :: animalData ( )
{
           animalNumber = 0 ; 
           cordX = 0 ; 
           cordY = 0 ;
           power = 0 ; 
           isAlive  = 0 ;    
}


void animalData :: initialise ( animal* source ) 
{
           animalNumber = source -> getItemNo() ; 
           cordX = source -> getPosX () ; 
           cordY = source -> getPosY () ;
           power = source -> getPower () ; 
           isAlive  = source -> getAlive() ;     
     
     
}
