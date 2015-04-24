/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#include <iostream>
using namespace std ; 

#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once 
#include <string>
#include "GameBoard.h" 
#include "item.h"



class item ; 
 

class animal : public item
{
      private:
              int power ; 
              int player_side ;
              bool is_alive ; 
              bool jump_able ; 
              bool swim_able ;
              GameBoard* board ; 
      public:
              animal () ; 
              animal (int item_no , int player_s , int pos_y , int pos_x , bool jump_able = false , bool swim_able = false);
              
              bool getAlive () ;
              void setAlive ( bool ) ;
              
              int getPower () ;
              void setPower (int ) ;
              
              void setPlayerSide ( int ) ;
              int getPlayerSide () ; 
              
              bool getJump () ; 
              void setJump (bool) ;
              
              bool getSwim () ; 
              void setSwim ( bool ) ; 
                
              virtual bool moved_by_other (animal* source  , int dy , int dx )   ;  
              virtual bool check_moved (animal* source, int dy , int dx  ) ;        
              virtual bool move ( int dy , int dx ) ; 
              void toPower () ; 
              
              void setBoard ( GameBoard* board ) ; // Problem!
              GameBoard* getBoard () { return board ; }
              
              virtual ~animal() { };       
      
};
#endif

