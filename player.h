/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "rat.h"
#include "lion.h"
#include "tiger.h"
#include "elephant.h"
using namespace std;  

class player 
{
      private :
              int player_no ;
              string playerName ; 
              animal** animal_set ; 
              int playerColor ; 
      public:     
             player () ; 
             player ( int player_no ) ;
             
             void initialise () ; 
              
             int getPlayerNo () ; 
             animal* getAnimal (int) ;
             
             void setPlayerName ( string name ) { playerName = name ;   }; 
             string getPlayerName ()  {   return playerName ; }; 
             
             void setColor ( int color ) { playerColor = color ; }
             int getColor () { return playerColor ; } 
             ~player () ;              
};

#endif
