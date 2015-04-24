/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include "settingInterface.h"
#include "startInterface.h"
#include "playerSettingInterface.h"
#include "player.h"
#include "GameStartInterface.h"

#include <fstream>


playerSettingInterface :: playerSettingInterface ( GameController* Controller  )
{ 
     setController(Controller);
     setInterface(this) ; 
     initialise ("jungleChessPlayerSettingMenu.txt")  ;  
}

playerSettingInterface :: playerSettingInterface ()
{
     setController(NULL);
     setInterface(this) ;           
     initialise ("jungleChessPlayerSettingMenu.txt");                
}




void playerSettingInterface :: display ()
{
     system("cls");
     changeColour(15) ;
     cout << getInfo () ;     
}

int  playerSettingInterface :: getInput ()
{
     
     int choice ; 
     cout << "Enter Number between 1 to 4 " <<endl ; 
     choice = getController() -> IntInput(1,4);
}

void playerSettingInterface :: performInterface ()
{
     int choice ; 
     performDisplay () ;
     cleanBottomBoard ();

     
     for(int i = 0 ; i < 2 ; i ++ )
     {
             changeColour(15) ; 
             gotoXY( 5 + 50 * i , 23 ) ;       
             cout << " Player " << i + 1 ; 
             gotoXY( 8 + 50 * i , 24 );
             cout << "Name :";
             cout << getController() -> getBoard() -> getPlayer(i+1) -> getPlayerName () ; 
             gotoXY( 8 + 50 * i ,25); 
             cout << "Color : " ; 
             changeColour( getController() -> getBoard() ->getPlayer(i+1) -> getColor() ) ; 
             cout << getController() -> getBoard() ->getPlayer(i+1) -> getColor() ; 
             
             
     }
     changeColour(15) ;
     
     
     
     gotoXY(0,29);       
     choice = performGetInput() ; 
     string name ; 
     int choic ;
     int ColorChoice;  
     switch (choice)
      {
            case  1 :
                  cleanBottomBoard ();
                  askPlayerNo () ; 
                  choic = getController() -> IntInput(1,2) ;
                  cleanBottomBoard ();
                  askPlayerName ();
                  cin >> name ;
                  getController() -> getBoard() -> getPlayer(choic) -> setPlayerName(name);   
                  getInterface() -> performInterface () ;
                  break ; 
            case  2 :
                  cleanBottomBoard ();
                  askPlayerNo () ; 
                  choic = getController() -> IntInput(1,2) ;
                  cleanBottomBoard ();
                  askPlayerColor () ; 
                  ColorChoice = getController() -> IntInput(1,15)  ; 
                  changePlayerColor( choic , ColorChoice  ) ; 
                  getInterface() -> performInterface () ; 
                  break ; 
            case  3 :
                  delete this ; 
                  setInterface ( new GameStartInterface (getController () ) ) ;
                  getInterface() -> performInterface () ;  
                  break;
            case  4 :
                  delete this ; 
                  setInterface( new settingInterface ( getController () ) ) ; 
                  getInterface() -> performInterface () ; 
                  break ;  
            default:
                  break ; 
                  
            
      }        
}

void playerSettingInterface :: performDisplay ()
{
     getInterface() ->  display () ;    
}

int playerSettingInterface :: performGetInput()
{
     getInterface() -> getInput () ;   
}

void playerSettingInterface :: cleanBottomBoard ()
{

     for( int y = 22 ; y < 28 ; y ++ )
          for ( int x = 2 ; x < 77 ; x ++ )
          {   
              gotoXY(x,y);
              cout << " " ; 
          }
    /*
    for( int y = 29 ; y < 32 ; y ++ )
         for ( int x = 0 ; x < 78 ; x ++ )
         {
             gotoXY(x,y);
             cout << " " ; 
         }
    */
}

void playerSettingInterface :: askPlayerNo () 
{
          gotoXY( 5 , 25 ) ; 
          cout << " Which player would you chose ? " ; 
}

void playerSettingInterface :: askPlayerName () 
{
          gotoXY( 5 , 25 ) ; 
          cout << " What is the new name ? " ;  
}

void playerSettingInterface :: askPlayerColor () 
{
     
     gotoXY( 5 , 23 );     
     for( int y = 0 ; y < 3 ; y ++ )
          for( int x = 0 ; x < 5 ; x ++   )
     {
               gotoXY( 5 + 15 * x , 23 + y ) ; 
               changeColour(5*y+x) ;      
               cout << "Color : " << (5*y+x) ; 
     }
     changeColour(15);
     cout <<endl ; 
     gotoXY(5,26);
     cout << "Which color would you chose ? "  ;
}

void playerSettingInterface :: changePlayerColor( int playerNo , int Color ) 
{
     for( int i = 0 ; i < 8 ; i ++ )
         getController() -> getBoard() -> getPlayer(playerNo) -> getAnimal(i) -> setColor (Color) ;
      getController() -> getBoard() -> getPlayer(playerNo) -> setColor(Color) ;  
}


