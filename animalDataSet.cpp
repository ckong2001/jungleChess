/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/
#include "animalDataSet.h"
#include "player.h"

animalDataSet :: animalDataSet () 
{
     NoOfPlayer = 2 ; 
     NoOfAnimal = 8 ;               
     animalDataSetOfplayer = new animalData[NoOfPlayer * 8 ] ; 
              
              
}

void animalDataSet :: initialise(GameBoard* sourceBoard ) 
{
     for(int playerNo = 1 ; playerNo < NoOfPlayer+1 ; playerNo ++ )
             for(int animalNo = 0 ; animalNo < NoOfAnimal ; animalNo ++ )
     {
           animalDataSetOfplayer[ (playerNo-1)*NoOfAnimal+animalNo] = animalData () ;   
           animalDataSetOfplayer[ (playerNo-1)*NoOfAnimal+animalNo].initialise( sourceBoard -> getPlayer( playerNo ) -> getAnimal(animalNo) );  
     }    
     
}

animalData animalDataSet :: getAnimalDataAt( int playerNo , int i ) 
{
    if(playerNo <0 || playerNo > NoOfPlayer )
                throw "Index out bound in getting animal data Set " ; 
    else
                return  animalDataSetOfplayer[(playerNo-1) * 8 + i] ;            
}

