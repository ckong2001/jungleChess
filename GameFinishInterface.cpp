/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/







#include "GameFinishInterface.h"
#include "textControl.h"
GameFinishInterface :: GameFinishInterface () 
{
     setController(NULL);
     setInterface(this) ; 
     initialise ("jungleChessGameFinishMenu.txt")  ;                                
}




GameFinishInterface :: GameFinishInterface ( GameController* controller )
{
     setController(controller);
     setInterface(this) ; 
     initialise ("jungleChessGameFinishMenu.txt")  ;                                  
                    
}



void GameFinishInterface :: display ()  
{
     changeColour(15) ;
     cout << getInfo () ; 
}


  
void GameFinishInterface :: performDisplay ()
{
     getInterface() ->  display () ;
     
}

  
int GameFinishInterface :: getInput ()
{
    
    
    
    
    
} 
int GameFinishInterface :: performGetInput ()
{
    getInterface() ->  getInput () ;  
}
   
void GameFinishInterface ::  performInterface ()    
{
    char choice ;  
    system("cls"); 
    display() ;
    gotoXY ( 10 , 30 ) ; 
    cout << "Would you play again ?(y/n) :" ; 
    do
    {    
      cin >> choice  ; 
      if( choice == 'y' || choice == 'n' )
          break;
      else
      {
          gotoXY(10,30);
          cout << "    Invalid Input , input again : "  ;      
          
      }
      
    }while ( choice != 'y' || choice != 'n' ) ;  
    
    switch ( choice )
    {
           case 'y' :
                delete this ;
                setInterface( new startInterface ( getController () ) ) ; 
                getInterface ()  -> performInterface () ; 
                break;       
           case 'n' :
                delete this ;
                getController () -> ~GameController() ; 
                exit (EXIT_FAILURE);
                break;
           default :
                delete this ; 
                getController () -> ~GameController() ; 
                exit (EXIT_FAILURE);
                break;
           
    } 
     
     
     
}
