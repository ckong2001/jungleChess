/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "GameBoard.h"
#include "direction.h"
#include "Game.h"
#include <list>
class animalDataSet ; 
class GameController 
{
      private:
	  		GameBoard* board ;
            int round ;
            Game* game ; 
            list<animalDataSet> listOfStep  ;     
	  public:    
	  		GameController () ; 
            void initialise () ;   
      		int IntInput ( int min , int max ) ;
      		bool IntInput ( int& inputNumber , int min , int max ) ; 
      		direction* checkOutBound (animal* , direction* , int ) ; 
			string StrInput () ; 
			animal* searchAnimal( int , player* ) ; 
			direction* checkMove ( animal* ) ; 
			void Control () ; 
			void displayPlayerAnimal (int player_no); 
			direction* displayAnimalDirection(direction* set)const;  
			bool move ( int animal_no , int player_no  , int direc    ) ;
            void setBoard (GameBoard*  a); 
            GameBoard* getBoard () ; 
            int getRound () { return round  ; }
            void setRound (int round ) { this->round = round ;  } 
            void addRound () { round %= 2 ; round ++ ; }
            void setGame ( Game* game ) { this->game = game ;  }
            Game* getGame () { return game ; }
            bool saveGame () ; 
            bool loadGame () ;
            void changePlayerColor( int playerNo , int Color ) ;
            bool SaveStep ( GameBoard* sourceBoard ) ;  
            bool undo () ; 
            void test () ;  
            ~GameController () ;      
      
};


#endif
