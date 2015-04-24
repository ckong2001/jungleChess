/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/





#include "landscape.h"
landscape :: landscape () 
             :item()
{
        
}

landscape :: landscape ( int item_No  , int y ,  int x ) 
          : item( item_No , y , x  ) 
{}

bool landscape :: moved_by_other (animal* source )
{
          return true ;      
}

bool landscape :: left_by_animal (animal* source )
{
          return true ; 
} 

bool landscape :: check_moved (animal* source , int dy , int dx )
{
          return true ;      
}

void landscape :: setBoard (GameBoard* Map )
{
     board = Map ; 
} 

GameBoard* landscape :: getBoard() { return board ; }
