/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef LANDSCAPE_H
#define LANDSCAPE_H
#include "item.h"

class GameBoard ; 
class landscape : public item
{
      private:
             GameBoard* board ; 
      public:
             landscape () ;
             landscape (int item_No , int y,  int x) ; 
             virtual bool moved_by_other ( animal* ) ;
             virtual bool left_by_animal ( animal* )    ;
             virtual bool check_moved (animal* , int dy , int dx )  ; 
             void setBoard (GameBoard*  a) ;
             GameBoard* getBoard() ; 
             virtual ~landscape () {} ;             
             
};
#endif
