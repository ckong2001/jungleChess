/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "settingInterface.h"
#include "startInterface.h"
#include "GameStartInterface.h"

#include <fstream>

settingInterface :: settingInterface ( GameController* Controller  )
{ 
     setController(Controller);
     setInterface(this) ; 
     initialise ("jungleChessSettingMenu.txt")  ;  
}

settingInterface :: settingInterface ()
{
     setController(NULL);
     setInterface(this) ;           
     initialise ("jungleChessSettingMenu.txt");                
}

void settingInterface :: display ()
{
     system("cls");
     cout << getInfo () ;     
}

int  settingInterface :: getInput ()
{
     
     int choice ; 
     cout << "Enter Number between 1 to 4 " <<endl ; 
     choice = getController() -> IntInput(1,4);
}

void settingInterface :: performInterface ()
{
     int choice ; 
     performDisplay () ;      
     choice = performGetInput() ; 
     switch (choice)
      {
            case  1 :
                  setInterface( new playerSettingInterface ( getController() ) )  ;
                  free(this) ; 
                  getInterface() -> performInterface () ;
                  break ; 
            case  2 :
                  setInterface( new settingInterface ( getController ()  ) ) ; 
                  free(this) ; 
                  getInterface() -> performInterface () ; 
                  break ; 
            case  3 :
                  setInterface( new GameStartInterface ( getController () ) ) ;
                  free(this) ; 
                  getInterface() -> performInterface () ;  
                  break;
            case  4 :
                  setInterface( new startInterface ( getController () ) ) ; 
                  free(this) ; 
                  getInterface() -> performInterface () ; 
                  break ;  
            default:
                  break ; 
                  
            
      }     
     
     
}



void settingInterface :: performDisplay ()
{
     getInterface() ->  display () ;    
}

int settingInterface :: performGetInput()
{
     getInterface() -> getInput () ;   
}


