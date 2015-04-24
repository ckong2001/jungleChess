/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#ifndef ANIMAL_DATA 
#define ANIMAL_DATA
#include "animal.h"
class animalData
{
     private:
             int   animalNumber ; 
             int   cordX ; 
             int   cordY ;
             int   power ;
             bool  isAlive ;
     public: 
             animalData () ; 
             void initialise ( animal* source ) ;  
             int getAnimalNumber() { return animalNumber ; } ; 
             int getCordX ()       { return cordX ; }; 
             int getCordY ()       { return cordY ; }; 
             int getPower ()       { return power ; };
             bool getAlive ()      { return isAlive ; }; 
} ;
#endif
