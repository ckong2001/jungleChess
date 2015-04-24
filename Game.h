/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#ifndef GAME_H
#define GAME_H

class GameController ; 
class Game
{
      private:
              bool gameState;
              GameController* controller;
      public:
              Game() ; 
              void start() ; 
              bool getGameState () ; 
              void setGameState (bool) ; 
              GameController* getController () { return controller; };
              ~Game () ;        
} ; 






#endif 
