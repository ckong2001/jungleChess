/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#ifndef ANIMAL_DATA_SET_H
#define ANIMAL_DATA_SET_H
#include "animalData.h"
#include "GameController.h"

class animalDataSet
{
      private:
              int NoOfPlayer ; 
              int NoOfAnimal ; 
              animalData* animalDataSetOfplayer ; 
      public:
              animalDataSet () ; 
              void initialise(GameBoard* sourceBoard ) ;
              animalData getAnimalDataAt( int playerNo , int i ) ;
              
};
#endif
