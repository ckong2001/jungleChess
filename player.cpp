/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include "player.h"

player :: player ()
{
       initialise () ;       
}


player :: player ( int playerNo )
{
       player_no = playerNo ;  
       stringstream ss;  
       ss << "Player" << player_no ; 
       setPlayerName(ss.str() )   ;
       setColor(player_no) ;     
       initialise () ; 
}

void player :: initialise ()
{
     /*
      Animal :
                   Rat : 4       Leopard : 8 
                   Cat : 5       Tiger : 9 
                   Wolf : 6      Lion : 10
                   Dog : 7       Elephant : 11
                   */
                   
     /*
      Animal set :
                   Rat : 0       Leopard : 4 
                   Cat : 1       Tiger : 5
                   Wolf : 2      Lion : 6
                   Dog : 3       Elephant : 7
      */
                   
    animal_set = new animal* [8] ;
    
    if(player_no == 1)
    {
                 
                 animal_set[0] = new rat ( player_no , 2 , 0 );  
                 animal_set[1] = new animal ( 5 , player_no , 1 , 5 ) ; 
                 animal_set[2] = new animal ( 6 , player_no , 2 , 4 ) ; 
                 animal_set[3] = new animal ( 7 , player_no , 1 , 1 ) ; 
                 
                 animal_set[4] = new animal ( 8 , player_no , 2 , 2 ) ; 
                 animal_set[5] = new tiger  ( player_no , 0 , 6 ) ; 
                 animal_set[6] = new lion ( player_no , 0 , 0 ) ; 
                 animal_set[7] = new elephant ( player_no , 2 , 6 ) ; 
                 
    }
    else if ( player_no == 2 )
    {
                 animal_set[0] = new rat ( player_no , 6 , 6 );  
                 animal_set[1] = new animal ( 5 , player_no , 7 , 1 ) ; 
                 animal_set[2] = new animal ( 6 , player_no , 6 , 2 ) ; 
                 animal_set[3] = new animal ( 7 , player_no , 7 , 5 ) ; 
                 
                 animal_set[4] = new animal ( 8 , player_no , 6 , 4 ) ; 
                 animal_set[5] = new tiger  ( player_no , 8 , 0 ) ; 
                 animal_set[6] = new lion ( player_no , 8 , 6 ) ; 
                 animal_set[7] = new elephant ( player_no , 6 , 0 ) ; 
                      
    }
    else
    {
        for(int i = 0 ; i < 8 ;  i ++)
                          animal_set[i] = new animal() ;
                          } 
                                          
    for( int i = 0 ; i < 8 ; i ++ )
         animal_set[i] -> setColor( this -> getColor () ) ;   

}



int  player :: getPlayerNo () { return player_no ; }

animal* player :: getAnimal ( int index )
{
       return animal_set[index] ;        
       
}


player :: ~player ()
{
    for( int i = 0 ; i < 8 ; i ++ )
    {
         if( animal_set[i] != NULL )
         {
         free(animal_set[i]) ; 
         animal_set[i] = NULL ; 
         }
    }
    if(animal_set != NULL)
    {
    free(animal_set) ;   
    animal_set = NULL ;
    }    
}

