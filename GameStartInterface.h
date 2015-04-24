/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#ifndef GAMESTARTINTERFACE_H
#define GAMESTARTINTERFACE_H

#include "textControl.h"
#include "GameInterface.h"
#include "settingInterface.h"
#include "startInterface.h"
#include "GameFinishInterface.h"

class GameStartInterface : public GameInterface
{
      public:
          GameStartInterface () ; 
          GameStartInterface ( GameController * controller ) ;      
          virtual void display () ; 
          virtual void performDisplay () ; 
          virtual int getInput () ;
          virtual int performGetInput () ; 
          virtual void performInterface () ; 
          int askChoice ( int X , int Y ,  int min , int max ) ; 
          void cleanBoard () ; 
          void displayAnimal ( int X , int Y) ;  
          void displayAnimalDirection ( direction* directionList  ,  int X , int Y ) ; 
          direction* getValidAnimalDirection  ( int AnimalChoice  ) ;  
        
}; 

#endif
