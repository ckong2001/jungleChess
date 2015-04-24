/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/

#include "item.h"


item :: item () 
     : item_no(0) , pos_x(-1) , pos_y(-1)
{
     color = 0 ;
     setName();
}

//Constructor contain item no for setting board name (display name) , name , position x , position y 
item :: item( int item_No , int y,  int x ) 
{
     if( item_No < 0 || item_No > 11)
     cout << "ITEM NUMBER ERROR" <<endl;
     else
     setItemNo(item_No) ;
     
     setName(); 
     setX( x ) ; 
     setY ( y ) ;
     setColor(15); 
     //toName();    
}

int item :: getItemNo () { return item_no ;}
void item :: setItemNo ( int item) { item_no = item ; } 

string item ::getName() { return name ;}

void item :: setName (  )  
{ 
     
     string name_set[12] = { "" , "RIVER" , "TRAP" , "DEN" , "RAT" , "CAT" , "WOLF" , "DOG" , "LEOPARD" , "TIGER" , "LION" , "ELEPHANT"};               
     this->name = name_set[item_no];
     //toName() execution time error 
     
     int lengthN = name.length() ;       
     int space = 9 ;
     stringstream a ;
     int left , right ; 
     if( (space - lengthN ) % 2 == 0 )
     {
              left = right = ( space - lengthN ) / 2 ;
     } 
     else
     {
              left = ( space - lengthN ) /2 + 1 ;     
              right = (space - lengthN ) /2 ; 
     }
              
     for(int i = 0 ; i < left ; i ++ )
             a<<" " ; 
     a<<name;
    
     for(int i = 0 ; i < right ; i ++ )
             a<<" " ; 
                  
     boardName = a.str() ;

}; 

string item :: getBName() {return boardName ; } 

int item ::getPosX () { return pos_x; } 
int item ::getPosY () { return pos_y; }


                  
void item ::setX ( int X ) { 
     if( X < 0 || X > 6)
         cout << "SET POSITION X ERROR OUTBOUND"<<endl ; 
     else
         pos_x = X ;
     
     }
void item ::setY ( int Y ) {
     if( Y < 0 || Y > 8)
         cout << "SET POSITION X ERROR OUTBOUND"<<endl ; 
     else 
         pos_y = Y; 
     
     
     } 
void item ::setXY ( int X , int Y ) { setX(X) ; setY(Y) ;}


string item :: toName () 
{
       
          int lengthN = name.length() ;       
          int space = 9 ;
          stringstream a ;
          int left , right ; 
          if( (space - lengthN ) % 2 == 0 )
          {
              left = right = ( space - lengthN ) / 2 ;
          } 
          else
          {
              left = ( space - lengthN ) /2 + 1 ;     
              right = (space - lengthN ) /2 ; 
          }
              
          for(int i = 0 ; i < left ; i ++ )
                  a<<" " ; 
          a<<name;
    
          for(int i = 0 ; i < right ; i ++ )
                  a<<" " ; 
                  
          boardName = a.str() ;
                           
}

int item :: getColor () 
{
	return color ; 	  
}

void item :: setColor ( int color ) 
{
	this -> color = color ;
}



/*
bool item ::  check_moved ( animal* source )
{     
          return true ;    
} */


