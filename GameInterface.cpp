/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/






#include "GameInterface.h"
#include <fstream>


void GameInterface :: initialise ( string filename )
{
     ifstream fin; 
     fin.open(filename.c_str() );
     string line ; 
     string fileContent ; 
     while(getline(fin,line))
     {  
            fileContent+= line ;  
            fileContent.push_back('\n') ;        
     }  
     setInfo(fileContent);
     fin.close(); 
          
}
