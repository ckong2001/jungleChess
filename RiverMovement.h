
#ifndef RIVERMOVEMENT_H
#define RIVERMOVEMENT_H
#include "landMovement.h"

class RiverMovement : public landMovement 
{
        public:    
                RiverMovement() :  landMovement() {;} ;   
                RiverMovement(landscape* thisLand) { setland(thisLand) ; } ;  
                virtual bool movedBy ( animal * source , int dy , int dx ) ; 
                virtual bool checkMovedBy (animal* source, int dy , int dx);
      
};
#endif
