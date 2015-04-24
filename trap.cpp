/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "trap.h"

trap :: trap() : 
     landscape ( 2 , -1 , -1 )
{}

trap :: trap(int X , int Y , player* owner )
        : landscape ( 2  , X , Y ) 
{
          owner_no = owner -> getPlayerNo () ; 
}

bool trap ::  moved_by_other (animal* source , int dy , int dx )
{
     if(  source -> getPlayerSide() != this->owner_no  )  
          source -> setPower(0) ; 
           
          return true ; 
}

bool trap :: check_moved (animal* source , int dx , int dy  )
{    
          return true ; 
}

bool trap :: left_by_animal ( animal* source) 
{
     if ( source -> getPower() == 0 )
     {
        source -> setPower(  source -> getItemNo() - 3 )  ;
        return true ; 
     }
     
}

