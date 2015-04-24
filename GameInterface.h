/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/





#include <iostream>
using namespace std;  
#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H
#include "GameController.h"
#include "Game.h"
#include <memory>
#include <string>

class GameInterface
{
      private:
            GameController* controller ; 
            GameInterface* gameInter;
            Game* game;  
            string displayInfo ; 
      public:
            virtual void display () = 0  ; 
            virtual void performDisplay () = 0 ; 
            virtual int getInput () = 0 ;
            virtual int performGetInput () = 0 ; 
            virtual void performInterface () =  0 ; 
            
            
             
            void setController (GameController* Controller) { controller = Controller ; }
            GameController* getController () { return controller ; } 
             
            void setInterface ( GameInterface* GameInter ) { gameInter = GameInter ; }
            GameInterface* getInterface () { return gameInter ; }
             
            void setInfo ( string Info ) { displayInfo = Info ;  }
            string getInfo () { return displayInfo ; }
            
            void setGame ( Game* G ) { game = G ;  }
            Game* getGame () { return game  ; }
            
            void initialise ( string filename  ) ;  
            
             

};

#endif 

