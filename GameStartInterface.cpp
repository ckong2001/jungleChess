/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/




#include "GameStartInterface.h"
#include "player.h"
GameStartInterface :: GameStartInterface ( GameController* Controller  )
{ 
     setController(Controller);
     setInterface(this) ; 
     initialise ("jungleChessGameStartMenu.txt")  ;  
}

GameStartInterface :: GameStartInterface ()
{
     setController(NULL);
     setInterface(this) ;           
     initialise ("jungleChessGameStartMenu.txt");                
}

void GameStartInterface :: display ()
{
     changeColour(15) ;
     cout << getInfo () ;     
}


void GameStartInterface :: performDisplay ()
{
     getInterface() ->  display () ;    
} 

int GameStartInterface :: getInput ()
{
    
    
    
    
    
} 
int GameStartInterface :: performGetInput ()
{  
      getInterface() ->  getInput () ;    
} 
void GameStartInterface :: performInterface () 
{
     system("cls");
     getController () -> getBoard() ->  update () ; 
     getController () -> getBoard() ->  displayBoard() ;  
     changeColour( getController () -> getBoard () -> getPlayer ( getController () -> getRound() ) -> getColor() ) ; 
     cout << "||\t\t" <<getController () -> getBoard () -> getPlayer ( getController () -> getRound() ) -> getPlayerName() << "'s turn\t\t||" << endl ; ; 
     changeColour(15) ; 
     this->display () ;  
     int choic ; 
     choic = askChoice ( 30 , 40 , 1 , 7  ) ;
     int AnimalChoice ;  
     int AnimalDirectionChoice ; 
     direction* directionSet = NULL ; 
     Game* newGame  ;
     
     switch ( choic )
     {
            case 1 :    
                 cleanBoard () ;
                 displayAnimal (30,39)  ;  
                 AnimalChoice =  askChoice( 30 , 48 , 0 , 7 ) ; 
                 directionSet = getValidAnimalDirection( AnimalChoice ) ;
                 displayAnimalDirection( directionSet , 50 , 39 ) ;
                 AnimalDirectionChoice = askChoice( 30 , 48 , 0 , 3 ) ;  
                 while( directionSet[AnimalDirectionChoice].getValid() == false )
                 {
                      AnimalDirectionChoice = askChoice( 30 , 48 , 0 , 4 ) ;          
                 }  
                 getController()-> move ( AnimalChoice , getController()->getRound()  , AnimalDirectionChoice   ) ; 
                 getController()->addRound() ;
                 if(getController() -> getGame() -> getGameState() == false ) 
                 {
                                    getController() ->initialise () ; 
                                    getController () -> getBoard() -> initialise () ; 
                                    setInterface ( new GameFinishInterface ( getController () ) ) ;      
                 }                   
                 getInterface()->performInterface () ; 
                 break ;
            case 2 :
                 getController () -> undo() ; 
                 this->performInterface () ; 
                 break ;
            case 3 :
                 if( getController () -> saveGame() )
                 {
                     cleanBoard () ; 
                     gotoXY(30,40);
                     cout << "Game saved " ;  
                 }
                 else
                 {
                    cleanBoard () ; 
                    gotoXY(30,40);
                    cout << "failed to  save game "  ; 

                 }
                 Sleep(1000);
                 this-> performInterface () ;
                 break ; 
            case 4 :
                 delete this ; 
                 setInterface(new settingInterface (getController () ) ) ; 
                 getInterface() -> performInterface () ; 
                 break; 
            case 5 :
                 delete this ; 
                 setInterface ( new startInterface (getController () ) ) ; 
                 getInterface() -> performInterface () ; 
                 break;
            case 6 : 
                 newGame = new Game () ;  
                 getController() -> initialise () ;   
                 getInterface()-> setGame ( newGame ) ;  
                 getController() -> setGame( newGame ) ;    
                 getInterface() -> performInterface ()  ; 
                 break ; 
            case 7 :
                 delete this ; 
                 getController () -> ~GameController() ; 
                 exit (EXIT_FAILURE);
                 break; 
            default:
                 break ;
     } 
     
     
     
}


int GameStartInterface :: askChoice ( int X , int Y  , int min , int max ) 
{

    int input;
    if( X < 30 || X > 79 ) 
        X = 30 ; 
    if( Y > 55 || Y < 30 )
        Y = 40 ; 
    do { 
       for(int i = X ; i < 77 ; i ++ )
       {
               gotoXY(i,Y) ;         
               cout << " " ; 
       } 
       gotoXY( X , Y ) ;
       cout << "Which choice would you chose (0-7) ? " ; 
    
    } while ( getController() -> IntInput ( input , min , max ) == false || 
              getController() -> getBoard() -> getPlayer(getController()->getRound()) -> getAnimal(input) -> getAlive() == false  ) ;
    
    for( int i = X ; i < 78 ; i ++ )
    {
         gotoXY(X,Y) ;    
         cout << " " ; 
    }
    
    return input ;   
}

void GameStartInterface :: cleanBoard ()
{
     for( int  x = 30 ;  x < 77 ; x ++ )
     {
          gotoXY ( x , 40 ) ; 
          cout << " " ; 
     }
}

void GameStartInterface :: displayAnimal (int X , int Y )
{
     int line = Y ; 
     GameController* contol = getController () ; 
     int turn = getController () ->   getRound ()  ;  
     gotoXY(X,Y) ; 
     cout << "Number\tAnimal" ; 
     X++ ;  
     line ++ ;      
     for( int i = 0 ; i < 8 ; i ++ )
     {
          if( contol -> getBoard() -> getPlayer( turn ) -> getAnimal(i)->getAlive() )
          {
              gotoXY(X,line);
              cout << i << "\t" ; 
              changeColour(getController () -> getBoard() -> getPlayer(turn)->getColor() ) ; 
              cout << getController () -> getBoard() ->getPlayer(turn)->getAnimal(i)->getName();
              changeColour(15);
              line ++ ; 
              
          }
     }   
}


void GameStartInterface :: displayAnimalDirection ( direction* directionList  , int X , int Y )
{
     string directionName[4] = { "Up" , "Right" ,"Down","left"} ;
     int line = Y ;
     gotoXY(X,Y) ; 
     X++ ;
     line++;
     cout << "Avaliable Move :";   

     for(int i = 0  ; i  < 4 ; i ++ )
     {
             if( directionList[i].getValid() == true)
             {    
                  gotoXY(X,line) ;    
                  cout << i << "\t" ;  
                  cout << directionName[i] <<endl ;
                  line ++ ; 
             }          

     } 
     
}

direction* GameStartInterface :: getValidAnimalDirection  ( int AnimalChoice  ) 
{
     direction* set = NULL ; 
     int turn = getController ()-> getRound () ;        
     set = getController () -> checkMove( getController () -> getBoard () -> getPlayer (turn) -> getAnimal(AnimalChoice)) ;      
     return set ; 
}


