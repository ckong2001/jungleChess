/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include "direction.h"
direction :: direction ()
{
          dy = 0 ; 
          dx = 0 ;    
                 
}

direction :: direction ( int dy , int dx ) 
{
          this->dy = dy ;
          this->dx = dx  ; 
              
}

bool direction :: getValid  () { return valid ; } 
void direction :: setValid ( bool Valid ) { this -> valid = Valid ; }

direction :: ~direction () {}

void direction :: setDy ( int y )
{
     dy = y ;
} 

void direction :: setDx ( int x )
{
     dx = x ;
} 

int direction :: getDx () { return dx ; }
int direction :: getDy () { return dy ; }
