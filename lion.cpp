/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#include "lion.h"
lion :: lion() 
      : animal ( 10 ,  0 ,  -1  , -1  , true  , false )
{}      

lion :: lion ( int player_s , int Y , int X  ) 
         : animal ( 10 ,  player_s , Y , X , true , false ) 
{
    setJump(true);     
}

bool lion :: move ( int dy , int dx )
{
     if( getBoard() == NULL )
         cout << "BOARD NULL ERROR !" <<endl ; 
     else
     {
          int x = getPosX() ; 
          int y = getPosY() ; 
     
          if( y + dy < 0 || y + dy > 8 || x + dx < 0 || x + dx > 8   )
              return false ; 
         
          
            if( getBoard() -> getItem( getPosY() + dy , getPosX() + dx ) -> getItemNo() == 1 )
             {
                 if( dy != 0 && dx == 0)
                 {
                 setX ( this->getPosX() + dx * 4 ) ; 
                 setY ( this->getPosY() + dy * 4 ) ;
                 }
                 else if ( dy == 0 && dx != 0 )
                 {
                 setX ( this->getPosX() + dx * 3  ) ; 
                 setY ( this->getPosY() + dy * 3  ) ;
                 }
                 
             }               
             else if( getBoard() -> getItem( getPosY() + dy , getPosX() + dx ) -> getItemNo() != 1)
             {
                 setX ( this->getPosX() + dx ) ; 
                 setY ( this->getPosY() + dy ) ;
                  
             }
             
     }
     
} 
