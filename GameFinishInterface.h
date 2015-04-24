/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/





#ifndef GAME_FINISH_INTERFACE_H
#define GAME_FINISH_INTERFACE_H
#include "GameInterface.h"
#include "StartInterface.h"
class GameFinishInterface : public GameInterface 
{
      public:
            GameFinishInterface () ; 
            GameFinishInterface ( GameController* controller ) ; 
            virtual void display ()   ; 
            virtual void performDisplay () ; 
            virtual int getInput () ;
            virtual int performGetInput ()  ; 
            virtual void performInterface ()  ;   
};
#endif
