#include <iostream>
#include "item.h"

#ifndef ANIMALGENERALMOVEMENTINTERFACE_H
#define ANIMALGENERALMOVEMENTINTERFACE_H
#include "CheckMoveInterface.h"
using namespace std ; 

class AnimalGeneralMovement
{      
      private:
              ;
      public:      
                   virtual bool checkMovedBy ( animal* source, int dy , int dx ) = 0; 
                   virtual bool movedBy ( animal * source , int dy , int dx) = 0 ; 
                   virtual bool move (int dy , int dx ) = 0 ; 
                   virtual bool left_by_other ( animal* ) = 0  ; 
};
#endif
