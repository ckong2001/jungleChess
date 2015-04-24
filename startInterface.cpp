/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "StartInterface.h"
#include "GameStartInterface.h"
#include <fstream>


startInterface :: startInterface ( GameController* Controller  )
{ 
     setController(Controller);
     setInterface(this) ; 
     initialise ("jungleChessStartMenu.txt")  ;  
}

startInterface :: startInterface ()
{
     setController(NULL);
     setInterface(NULL) ;           
     initialise ("jungleChessStartMenu.txt");                
}


void startInterface :: display ()
{
     system("cls");
     cout << getInfo () ;     
}

int  startInterface :: getInput ()
{
     
     int choice ;
     int X = 10 ; 
     int Y = 23 ; 
     do {
      gotoXY(X,Y) ; 
      for(int i = 2 ; i < 77 ; i ++ )
      {
              gotoXY(i,23) ; 
              cout << " " ;         
      }
      
      gotoXY( 10, 23 ) ;  
      cout << "Enter Number between 1 to 4 "  ; 
     } while ( getController() -> IntInput(choice , 1,4) == false ) ; 
     return choice ;     
}

void startInterface :: performInterface ()
{
     int choice ; 
     performDisplay () ;      
     choice = performGetInput() ; 
     switch (choice)
      {
            case  1 :
                  setInterface ( new GameStartInterface ( getController () ) ) ; 
                  free(this) ; 
                  getInterface() -> performInterface () ;
                  break;
            case  2 :
                  setInterface( new settingInterface( getController () ) ) ; 
                  free(this) ; 
                  getInterface() -> performInterface () ; 
                  break ; 
            case  3 :
                  
                  getController () -> loadGame() ; 
                  free(this) ; 
                  setInterface ( new GameStartInterface ( getController () ) ) ; 
                  getInterface() -> performInterface () ; 
                  break;
            case  4:
                  free(this) ;
                  getController () -> ~GameController() ; 
                  exit (EXIT_FAILURE); 
                  break;  
            default:
                  break ; 
                  
            
      }
     
     
}

void startInterface :: performDisplay ()
{
     getInterface() ->  display () ;    
}

int startInterface :: performGetInput()
{
     getInterface() -> getInput () ;   
}


