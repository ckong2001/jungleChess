/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include <iostream>
using namespace std;
#ifndef DIRECTION_H
#define DIRECTION_H  
class direction 
{
      private:      
                    int dy ; 
                    int dx ; 
                    bool valid ; 
      public:
                    direction () ;
                    direction ( int , int ) ;  
                    ~direction () ; 
                    
                    int getDy () ; 
                    int getDx () ;
                    bool getValid  () ; 
                    
                    void setDy ( int ) ; 
                    void setDx ( int ) ;
                    void setValid ( bool ) ;   
};

#endif
