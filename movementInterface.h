#include <iostream>
#include "item.h"

#ifndef MOVEMENTINTERFACE_H
#define MOVEMENTINTERFACE_H
using namespace std ; 

class movementInterface 
{      
      public:      
                   virtual bool checkMovedBy ( animal* source, int dy , int dx ) = 0 ; 
                   virtual bool movedBy ( animal * source , int dy , int dx) = 0 ; 
                   virtual bool move (int dy , int dx ) = 0 ; 
                   virtual bool left_by_other ( animal* ) = 0  ; 
};
#endif
