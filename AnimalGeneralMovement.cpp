#include "AnimalGeneralMovement.h"
#include "animal.h"

AnimalGeneralMovement :: AnimalGeneralMovement ( animal* source ) 
{
    thisAnimal = source ;                   
                      
}


bool AnimalGeneralMovement :: checkMovedBy ( animal* source, int dy , int dx )
{
     if( source -> getPlayerSide() == getAnimal () -> getPlayerSide()  )
         return false;
     else if (source -> getPower() < thisAnimal -> getPower() )   
         return false ;
     else
         return true ;    
}

bool AnimalGeneralMovement :: movedBy ( animal * source , int dy , int dx)  
{
     if( source -> getPlayerSide() == thisAnimal -> getPlayerSide() )
             return false ;
     else if( source-> getPower() > thisAnimal->getPower () )
     {
             thisAnimal->setAlive(false);
             return true ; 
     }
     else if ( source-> getPower() < thisAnimal->getPower () )
             return false;    
     
}

bool AnimalGeneralMovement :: move (  int dy , int dx )
{
     if( thisAnimal->getBoard () == NULL)
         cout << "NO BOARD ERROR !!" <<endl ; 
         thisAnimal->setX ( thisAnimal->getPosX() + dx ) ; 
         thisAnimal->setY ( thisAnimal->getPosY() + dy ) ;  
} 

