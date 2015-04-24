/*#include "Board.h" 

Board :: Board(unsigned int i , unsigned int j  )
                             : col(i) , row(j)
{
 m = new auto_ptr <T> [ col * row ] ; 
 for(int i = 0 ; i < col ; i ++ )
         for( int j = 0 ; j < row ; j ++ )
              set( i , j , new T () ) ;                 
}
 
Board :: ~Board() 
{ 
  delete[] m ;
}
 
T* Board ::  get( unsigned int i , unsigned int j ) ;
{
  return m[translate( i , j )].get() ;        
}

unsigned int Board :: translate(unsigned int i , unsigned int j ) ; 
{ 
  return ( col * i ) + j ;
}

void Board :: set ( unsigned int i , unsigned int j , T* it)
{
  m[translate(i,j)].reset(it);     
}
*/
