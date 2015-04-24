#include "RiverMovement.h"
#include "animal.h"
bool RiverMovement :: movedBy ( animal * source , int dy , int dx ) 
{
      return ( source -> getSwim () ) ;         
}

bool RiverMovement :: checkMovedBy (animal* source, int dy , int dx)
{
     int y = getland()->getPosY() ;
     int x = getland()->getPosX();
         
         if( source -> getJump()  ) // for tiger and lion 
         { 
                   if( dy != 0 && dx == 0 )                         // if the move direction is down or up 
                   {
                     for( int i = 0 ; i < 2  ; i++ )                // check if the following 3 grid is river (item No : 1) ,if not , it means there is a rat blocking 
                     {
                          y += (dy) ; 
                          if( getland()->getBoard()->getItem( y  , x  )-> getItemNo() != 1 )
                             return false;

                     }   
                          
                     return getland()->getBoard()->getItem(  y + (dy) , x ) -> check_moved(source , dy , dx ) ; // check if the opposite platform is reachable
                   }
                   else if ( dy == 0 && dx != 0 )                  // if the move direction is right or left 
                   {
                     for(int i = 0 ; i < 1 ; i ++ )                // check if the following 2 grid is river (item No : 1), if not , it means there is a rat blocking 
                     {
                          x+=dx ;    
                          if( getland()->getBoard()->getItem( y , x  ) -> getItemNo () != 1 )
                              return false;
                     }                
                     return getland()->getBoard()->getItem( y , x + dx) -> check_moved(source , dy , dx ) ;
                      
                   }
         }
                 
                 
         else if ( source -> getSwim() )
                           return true ; 
             
         return false;

}
