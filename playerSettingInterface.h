/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef PLAYERSETTINGINTERFACE_H
#define PLAYERSETTINGINTERFACE_H
#include "GameInterface.h"
#include "textControl.h"


class playerSettingInterface : public GameInterface
{
      public:
             playerSettingInterface () ;
             playerSettingInterface ( GameController* Controller ) ;
             virtual void display () ; 
             virtual int  getInput () ;
             
             void performDisplay ()   ; 
             int performGetInput()  ;
             
             void cleanBottomBoard () ; 
             
             void askPlayerNo () ;
             void askPlayerName () ;
             void askPlayerColor () ; 
             void changePlayerColor(int playerNo , int Color ) ;   
             
             virtual void performInterface () ;
             
             ~playerSettingInterface () {;} ;
      
      
};

#endif
