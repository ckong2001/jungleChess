/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#ifndef BOARD_H
#define BOARD_H



#include <iostream>
#include <vector>
#include <memory>
/*
         template to store a board

*/
template <class T>
class Board{
      private:
              unsigned int col ; 
              unsigned int row ; 
              auto_ptr<T> *m;  
      public:
              Board(unsigned int i , unsigned int j  )
                             : col(i) , row(j)
              {
                   m = new auto_ptr <T> [ col * row ] ; 
                   for(int i = 0 ; i < col ; i ++ )
                           for( int j = 0 ; j < row ; j ++ )
                                set( i , j , new T () ) ;                 
              }
              
              ~Board() 
              { delete[] m ;}
              
              T* get( unsigned int i , unsigned int j )
              {
                 return m[translate( i , j )].get() ;        
              }
              
              void set(unsigned int i , unsigned int j , T* it )
              {
                 m[translate(i,j)].reset(it) ;         
              }
              
              
              unsigned int translate(unsigned int i , unsigned int j )
              { return ( col * i ) + j ;}
      
};


#endif
