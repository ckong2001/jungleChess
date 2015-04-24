/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/
#pragma once
#include "landscape.h"
#include "land.h"
#include "river.h"
#include "den.h"
#include <windows.h>
#include <memory>
#define WIDTH 7
#define HEIGHT 9 

class player ; 
 
class GameBoard 
{
      private:
              landscape*** landMap ;      
              animal*** animalMap ;       
              item*** land_ani_Map ;      
              player* player1 ;         
              player* player2 ;         
              int displayMap[HEIGHT][WIDTH] ; 
      public:
              GameBoard () ; 
              void initialise () ; 
              void setlandMap (landscape* , int , int ) ; 
              void setAnimalMap (animal* , int , int ) ; 
              
              item*** getLandAniMap() ;     
              void setItem ( int Y , int X , item* ) ;
              item* getItem( int Y , int X );
              
              landscape*** getLandMap ();   
              void setLand ( int Y , int X , landscape* );              
              landscape* getLandscape ( int Y , int X ) ;
              
              animal*** getAnimlaMap () ;     
              void setAnimal ( int Y , int X , animal* )  ;
              animal* getAnimal ( int Y , int X ); 
               
              void displayBoard() ;
              void update () ; 
              
              player* getPlayer ( int ) ;  
              void setPlayer ( player* , int  ) ; 
              
              virtual ~GameBoard ()   ;  
};

//#endif
