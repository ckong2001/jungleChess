/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "den.h"
#include "animal.h"

den :: den()
      : landscape ( 3 , -1 , -1 ) 
{} 
den :: den ( int y,  int x) 
                   : landscape ( 3 ,  y , x )
{}  

//any animal with player number other than it's number would turn game's state into false , then end 
bool den :: moved_by_other ( animal* source  , int dy , int dx  )
{
     if(  source -> getPlayerSide() == this->owner_no )  
          return false ;      
     else 
          game -> setGameState(false) ; 
}

bool den :: check_moved (animal* source , int dy , int dx )
{
     if( source -> getPlayerSide() == this-> owner_no ) 
         return false;
     else
         return true ;     
}

void den :: setGame ( Game* game )
{
     this->game = game ;      
}

void den :: setOwnerNo (int owner_no )
{
     this->owner_no = owner_no ;    
}
