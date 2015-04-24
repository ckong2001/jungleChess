/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#include "Game.h"
#include "GameController.h"

Game :: Game() 
{
     controller = new GameController() ;
     for(int i = 0 ; i < 2 ; i ++ )
     {
      den* den1 = new den (0 + 8 * i ,3) ; 
      den1 -> setOwnerNo(i+1) ;
      den1 -> setGame(this) ; 
      controller -> getBoard () -> setLand(0+8*i,3,den1) ;
     } 
              
}

void Game :: start()
{
    system("cls");
    do{ 
    controller -> Control () ; 
    }while(this->gameState != false) ; 
      
      
}


bool Game :: getGameState () { return gameState ; } 
void Game :: setGameState (bool gameState ) { this->gameState = gameState ; }  
Game :: ~Game () 
{
   if( controller != NULL ) 
   { 
       controller -> ~GameController()  ;
       controller = NULL ;   
   }  
     
     
     
     
}
