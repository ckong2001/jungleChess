/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#ifndef SETTING_INTERFACE_H
#define SETTING_INTERFACE_H
#include "GameInterface.h"
#include "playerSettingInterface.h"

class settingInterface : public GameInterface 
{
      public:
             settingInterface () ;
             settingInterface ( GameController* Controller );

             virtual void display () ; 
             virtual int  getInput () ;
             
             void performDisplay ()   ; 
             int performGetInput()  ;
             virtual void performInterface () ;
             
             ~settingInterface () {;} ;
      

} ; 
#endif
