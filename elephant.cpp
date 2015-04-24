/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#include "elephant.h"
#include <typeinfo>

elephant :: elephant ()
            : animal ( 11 ,  -1  , -1  , false  , false )
{
        
}

elephant :: elephant ( int player_s , int X , int Y ) 
            : animal( 11 , player_s ,  X ,  Y , false  , false )
{
  
}




bool elephant :: moved_by_other (animal* source , int dy , int dx  )
{
     
       if( source -> getPlayerSide() == this->getPlayerSide() )
         return false;
       else if(  (source -> getPower () == 1 || source -> getPower() >= this->getPower() ) && source -> getAlive() == true  )
       {
         setAlive(false) ; 
         return true ;
       }
       else
         return false ;                  
}

bool elephant :: check_moved (animal* source, int dy , int dx  )
{
      if( source -> getPlayerSide() == this->getPlayerSide() )
         return false;
       else if(  source -> getPower () == 1)   
         return true ;
       
       else if( source -> getPower() > this->getPower() ) 
         return true ;
       else
         return false ;    
     
     
}
