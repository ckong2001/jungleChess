/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "river.h"

river :: river()
      : landscape ( 1 , -1 , -1 ) 
{} ;
river :: river ( int y,  int x) 
                   : landscape ( 1 ,  y , x )
{}  

bool river :: moved_by_other ( animal* source , int dy , int dx )//
{
     if( source -> getSwim () == true )
     {
         source -> setPower(-1) ; 
         return true ;
     } 
     else
         return false;
} 

bool river :: left_by_animal ( animal* source )
{
     source -> toPower () ; 
     source -> setPower ( source -> getPower () ) ; 
     return true ;
}


/*
     Two ways to move on river : jump == true or swim == true
         for jump == true
             check whether there is rat on the river 
                   check whether the oppsite platform is viable



*/
bool river :: check_moved (animal* source , int dy , int dx  ) //
{
    
     int y = this->getPosY() ;
     int x = this->getPosX();

     bool animalFlag = true ;
     bool boardFlag = true ;
     
     if(getBoard() == NULL )
     {
               cout << "RIVER ANIMAL NULL ERROR" << endl ;
               animalFlag = false ; 
     }
     if(getBoard() == NULL )
     {
               cout << "RIVER BOARD NULL ERROR" << endl ;
               boardFlag = false  ; 
     }
     
     bool flag = true ; 
     if( animalFlag && boardFlag )
     {
         
         if( source -> getJump() == true  ) // for tiger and lion 
         { 
                   if( dy != 0 && dx == 0 )                         // if the move direction is down or up 
                   {
                     for( int i = 0 ; i < 2  ; i++ )                // check if the following 3 grid is river (item No : 1) ,if not , it means there is a rat blocking 
                     {
                          y += (dy) ; 
                          if( getBoard()->getItem( y  , x  )-> getItemNo() != 1 )
                             return false;

                     }   
                          
                     return getBoard()->getItem(  y + (dy) , x ) -> check_moved(source , dy , dx ) ; // check if the opposite platform is reachable
                   }
                   else if ( dy == 0 && dx != 0 )                  // if the move direction is right or left 
                   {
                     for(int i = 0 ; i < 1 ; i ++ )                // check if the following 2 grid is river (item No : 1), if not , it means there is a rat blocking 
                     {
                          x+=dx ;    
                          if( getBoard()->getItem( y , x  ) -> getItemNo () != 1 )
                              return false;
                     }                
                     return getBoard()->getItem( y , x + dx) -> check_moved(source , dy , dx ) ;
                      
                   }
         }
                 
                 
         else if ( source -> getSwim())
                           return true ; 
                 
                 
                 return false;
     }
    
}
/*
void river :: setBoard (GameBoard* Map )
{
     board = Map ; 
} 
*/
