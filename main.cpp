/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/



#include <cstdlib>
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{

    Game* game = new Game() ; 
    game-> getController () -> setGame( game ) ; 
    GameInterface* test1 = new startInterface( game -> getController ()  );
    test1 -> setGame ( game ) ; 
    test1 -> performInterface ( ) ; 


    system("PAUSE");
    return 0;
}
