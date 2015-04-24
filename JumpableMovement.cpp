#include "JumpableMovement.h"
#include "animal.h"



bool JumpableMovement :: move (  int dy , int dx )
{
     if( getAnimal()->getBoard() == NULL )
         cout << "BOARD NULL ERROR !" <<endl ; 
     else
     {
          int x = getAnimal()->getPosX() ; 
          int y = getAnimal()->getPosY() ; 
     
          if( y + dy < 0 || y + dy > 8 || x + dx < 0 || x + dx > 8   )
              return false ; 
         
          
            if( getAnimal()->getBoard() -> getItem( y + dy , x + dx ) -> getItemNo() == 1 )
             {
                 if( dy != 0 && dx == 0)
                 {
                   getAnimal()->setX ( x + dx * 4 ) ; 
                   getAnimal()->setY ( y + dy * 4 ) ;
                 }
                 else if ( dy == 0 && dx != 0 )
                 {
                   getAnimal()->setX ( x + dx * 3  ) ; 
                   getAnimal()->setY ( y + dy * 3  ) ;
                 }
                 
             }               
             else if( getAnimal()->getBoard() -> getItem( y + dy , x + dx ) -> getItemNo() != 1)
             {
                  getAnimal()->setX ( x + dx ) ; 
                  getAnimal()->setY ( y + dy ) ;
                  
             }
             
     }  
} 
