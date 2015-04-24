#include <iostream>
using namespace std ;
#ifndef OWNABLE_H
#define OWNABLE_H
#include "movementInterface.h"
class ownable
{
      private:
              movementInterface* moveInter ;
      public:
              virtual void setPlayerSide ( int playerNo) = 0  ;
              virtual int getPlayerSide () = 0 ;
              virtual void setMovementInterface (movementInterface* source) { moveInter = source ; } ;
              virtual movementInterface* getMovementInterface () { return moveInter ; } ;
} ;
#endif
