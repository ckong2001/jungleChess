/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include "rat.h"

rat :: rat () 
       : animal ( 4 ,  0 ,  -1  , -1  , false  , true )
{}

rat :: rat ( int player_s , int Y , int X )
       : animal ( 4 ,  player_s , Y , X , false, true )
{}

bool rat ::  moved_by_other (animal* source, int dx , int dy )
{
         if( source -> getPlayerSide() == this->getPlayerSide() )
             return false ; 
         else if( source -> getPower () == 8  )
             return false;
         else if( source -> getPower() > this -> getPower () )
         {
              setAlive(false) ; 
              return true ; 
         } 
                
}
  

bool rat ::  check_moved (animal* source , int dx , int dy )
{
         if( source -> getPlayerSide() == this->getPlayerSide() || source -> getPower () == 8 )
             return false ; 
         else
             return true ;
}  

