#include "AnimalGeneralMovement.h"
#ifndef JUMPABLEMOVEMENT_H
#define JUMPABLEMOVEMENT_H
class JumpableMovement : public AnimalGeneralMovement 
{
     public:      
                   JumpableMovement ( animal* source ) { setAnimal(source) ;} ; 
                   JumpableMovement () {setAnimal(NULL);} ; 
                   bool move ( int dy , int dx ) ;    
};
#endif
