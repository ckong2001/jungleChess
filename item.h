/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




/*
    Item No :
         Landscape:
                   land : 0 
                   River : 1  
                   Trap : 2  
                   Den : 3 
         Animal :
                   Rat : 4       Leopard : 8 
                   Cat : 5       Tiger : 9 
                   Wolf : 6      Lion : 10
                   Dog : 7       Elephant : 11

*/




#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std ; 




#ifndef ITEM_H
#define ITEM_H

class animal ; 
//#include "animal.h" 
class item 
{
      private:      
                    int item_no ;
                    string name ; 
                    int pos_x ; 
                    int pos_y ;
                    string boardName ;
                    int color ;  
      public:
                    item() ;
                    item( int item_no , int y ,  int x ) ; 
                    
                    int getItemNo () ; 
                    void setItemNo ( int ) ;
                    
     
                    void setName () ;
                    string getName() ;
                    
                    int getColor () ; 
                    void setColor ( int color ) ; 
                    
                    int getPosX () ; 
                    int getPosY () ;
                    virtual void setX ( int X ) ;
                    virtual void setY ( int Y ) ; 
                    void setXY ( int X , int Y ) ;
      
                    string toName ()  ;
                    
                    string getBName() ;
               
                    virtual bool check_moved (animal* a , int dy , int dx  ) {  return true ; }           
                    virtual bool moved_by_other (animal* a , int dy , int dx  ) { return true ; }  
                    virtual bool left_by_animal ( animal* ) { return true ; } ; 
                    
                    virtual ~item() { } ; 
                     
} ;
 
#endif
