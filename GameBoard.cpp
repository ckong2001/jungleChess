/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include "GameBoard.h"
#include "player.h" 
#include "trap.h"

GameBoard :: GameBoard () 
{
          landMap = new landscape ** [HEIGHT] ; 
          animalMap = new animal ** [HEIGHT] ; 
          land_ani_Map = new item** [HEIGHT] ; 
          
          for(int i = 0 ; i < HEIGHT ; i ++ )
          {
                  landMap[i] = new landscape *[WIDTH] ; 
                  animalMap[i] = new animal *[WIDTH] ; 
                  land_ani_Map[i] = new item *[WIDTH] ;         
                  
                    
          }
          
          player1 =  new player(1);
          player2 =  new player(2);
          
           
          
          initialise () ; 
}

void GameBoard :: initialise () 
{
     
          for(int i = 0 ; i < HEIGHT ; i ++ )
          {
                  for(int j = 0 ; j < WIDTH ; j ++ )
                  {
                         landMap[i][j] = new land(i,j) ;          
                         animalMap[i][j] = NULL ; 
                         land_ani_Map[i][j] = landMap[i][j] ; 
                  } 
          } 
          
          //setting river 
          for(int i = 0 ; i < 3 ; i ++ )
          {
                  delete landMap[3+i][1];
                  delete landMap[3+i][2];
                  delete landMap[3+i][4];
                  delete landMap[3+i][5];
                  
                  landMap[3+i][1] = new river ( 3 + i  , 1 ) ;
                  landMap[3+i][1] -> setBoard(this) ; 

                  landMap[3+i][2] = new river ( 3 + i  , 2 ) ; 
                  landMap[3+i][2] -> setBoard(this) ; 
                  
                  landMap[3+i][4] = new river ( 3 + i  , 4 ) ; 
                  landMap[3+i][4] -> setBoard(this) ; 
                  
                  landMap[3+i][5] = new river ( 3 + i  , 5 ) ;
                  landMap[3+i][5] -> setBoard(this) ; 
                  
          }
          //setting trap
          for( int i = 0 ; i < 2 ; i ++ )
          {
                  landMap[0+i*8][2] = new trap ( 0+i*8 , 2 , getPlayer(i+1) ) ; 
                  landMap[0+i*8][4] = new trap ( 0+i*8 , 4 , getPlayer(i+1) ) ; 
                  landMap[1+i*6][3] = new trap ( 0+i*6 , 3 , getPlayer(i+1) ) ;     
               
          }
          
         
                  
          
          update ();
                              
}

//Display the board
void GameBoard :: displayBoard() 
{
     int space = 9 ; 
     int line  = 79 ;  
     for(int i = 0; i < line ; i ++ ) cout <<"=" ; 
     cout <<endl ; 
     HANDLE cHandle;
     cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     
     for(int i = 0 ; i < HEIGHT ; i ++ ) 
     {
             
             for(int j = 0; j < WIDTH ; j++ )
             {
                     cout << "||" ;
                     for(int k = 0 ; k < space ; k ++)
                             cout << " " ;          
             }
             cout << "||";
             cout <<endl;
             
             
             for(int j = 0; j < 7 ; j++ )
             {
                     cout << "||";
                     if( land_ani_Map[i][j] != NULL)
                     {
                     SetConsoleTextAttribute(cHandle, land_ani_Map[i][j] -> getColor () );    
                     cout << land_ani_Map[i][j]->getBName() ;
                     }
                     else
                     cout << "         ";
                     SetConsoleTextAttribute(cHandle, 15);
         
             }
             cout << "||";
             cout <<endl;
             
             
             for(int j = 0; j < 7 ; j++ )
             {
                     cout << "||" ;
                     for(int k = 0 ; k < space ; k ++)
                             cout << " " ;          
             }
             cout << "||";
             cout <<endl;
             
             cout <<"|";
             for(int j = 0 ; j < line-2 ; j ++) cout <<"=";
             cout <<"|" ;
             cout <<endl; 

     }
         
}

//update the board 
void GameBoard :: update ()
{
     for( int i = 0 ; i < HEIGHT ; i ++ )
     {
               for( int j = 0 ; j < WIDTH ; j++ ) 
               {
                   animalMap[i][j] = NULL ;  
                    
               }     
               
     }
     
     for(int i = 0 ; i < 8 ; i ++ )
     {
             if(player1 -> getAnimal(i)->getAlive())
                  animalMap[player1 -> getAnimal(i) -> getPosY()][player1 -> getAnimal(i) -> getPosX()] = player1 -> getAnimal(i) ;
             if(player2 -> getAnimal(i) -> getAlive()) 
                  animalMap[player2  -> getAnimal(i) -> getPosY()][player2  -> getAnimal(i) -> getPosX()] = player2  -> getAnimal(i) ;
                  player1 -> getAnimal(i) -> setBoard (this) ; 
                  player2 -> getAnimal(i) -> setBoard (this) ;         
                 
     }
           
    for( int i = 0 ; i < HEIGHT ; i ++ )
          {
               for( int j = 0 ; j < WIDTH ; j++ ) 
               {
                    land_ani_Map[i][j] = landMap[i][j] ; 
                                       if( animalMap[i][j] != NULL && animalMap[i][j]->getAlive()  )
                                           
                                           land_ani_Map[i][j] = animalMap[i][j] ;  
               }     
               
          }      
     
}


item*** GameBoard :: getLandAniMap()
{
        return land_ani_Map ;         
}


void GameBoard :: setItem ( int Y , int X , item* source) 
{
     land_ani_Map[Y][X] =   source ;      
}

item* GameBoard :: getItem( int y , int x )
{
      return land_ani_Map[y][x] ;       
      
}

void GameBoard :: setLand ( int Y , int X , landscape* source )
{
      landMap[Y][X] = source ;       
}

landscape* GameBoard :: getLandscape ( int y , int x) 
{
      return landMap[y][x] ;            
}


void GameBoard :: setAnimal ( int Y , int X , animal* source )
{
     animalMap[Y][X] = source ; 
}

player*  GameBoard :: getPlayer ( int playerNo )
{
     if(playerNo == 1)
         return player1 ; 
     else if (playerNo == 2)
         return player2 ;
     else
         cout << "PLAYER NUMBER  ERROR " <<endl ;                            
         
} 

void GameBoard :: setPlayer ( player* player ,  int number )
{
    if(number == 1)      
          player1 = player ; 
    else if ( number == 2)
          player2 = player ; 
    else
          cout << "PLAYER NUMBER  ERROR " <<endl ;  
     
     
}


GameBoard :: ~GameBoard ()
{
          
     for(int y = 0 ; y < HEIGHT ; y ++ )
             for( int x = 0 ; x <WIDTH ; x ++ )
     {
             if(landMap[y][x] != NULL )
             {
             free(landMap[y][x]);
             landMap[y][x] = NULL ;
             }
             
             if(landMap[y][x] != NULL )
             {
             free(animalMap[y][x]);
             animalMap[y][x] = NULL ;
             }
             
             if(land_ani_Map[y][x] != NULL)
             {
             free(land_ani_Map[y][x]) ;   
             land_ani_Map[y][x] = NULL ;
             }
                  
     }          
     
     for( int y = 0 ; y < HEIGHT ; y ++ )
     {
          if( landMap[y] != NULL )
          {
          free(landMap[y]) ;
          landMap[y] = NULL ; 
          }
          
          if( animalMap[y] != NULL )
          {
           free(animalMap[y]);
           animalMap[y] = NULL ; 
          }
          
          if(land_ani_Map[y] != NULL)
          {
          free(land_ani_Map[y]);
          land_ani_Map[y] = NULL ;
          } 
     }     
     
     if( landMap != NULL)
     {
     free(landMap); 
     landMap = NULL ; 
     }
     
     if(animalMap != NULL)
     {
     free(animalMap); 
     animalMap =  NULL ; 
     }
     
     if(land_ani_Map != NULL)
     {
     free(land_ani_Map) ;
     land_ani_Map = NULL ;  
     }
     
     
     if(player1 != NULL)
     {
     free(player1) ;
     player1 = NULL ; 
     }
     
     if(player2 != NULL)
     { 
     free(player2) ; 
     player2 = NULL ; 
     }
         
                    
}
