#include "movementInterface.h"
#ifndef LANDMOVEMENT_H
#define LANDMOVEMENT_H
class landscape ;  
#include "landscape.h"
class landMovement 
{
      private:
                   landscape* thisLand ; 
      public:      
                   landMovement(landscape* thisLand ) { this->thisLand = thisLand; }
                   landMovement() { thisLand = NULL ; }
                   virtual bool checkMovedBy ( animal* source, int dy , int dx ) { return true ;} ; 
                   virtual bool movedBy ( animal * source , int dy , int dx)  { return true ;}; 
                   virtual bool move ( animal * source , int dy , int dx ) { return true ; } ;
                   virtual bool left_by_animal ( animal* source ) { return true; };  
                   void setland (landscape* thisItem ) { this->thisLand = thisItem; }   ;
                   landscape* getland() { return thisLand ; } ;         
};
#endif
