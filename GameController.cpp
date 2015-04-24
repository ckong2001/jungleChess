/*
      CCCU 21105
      Object-Oriented Programming Assignment : Jungle Chess Game
      Team Number : 39
      Team member : Lo Ka Ming                     54063815
                    Tse Shing Kung                 54049126
                    Michael Romano                 54073009 
                    Tung Ka Lok                    54059120

*/


#include "GameController.h"
#include "player.h" 
#include "direction.h"
#include <sstream>
#include <fstream>
#include "animalDataSet.h"
GameController :: GameController () 
{
  			  board = new GameBoard () ; 
  			  round = 1 ; 
  			  initialise () ; 

}

void GameController :: initialise () 
{
     round = 1 ; 
     if( getBoard () -> getPlayer(1) != NULL )
     {
         delete  getBoard () -> getPlayer(1) ; 
         getBoard() ->setPlayer ( NULL , 1 ) ; 
         getBoard () -> setPlayer ( new player(1) , 1) ;    
     }     
     if( getBoard () -> getPlayer(2) != NULL  )
     {
         delete  getBoard () -> getPlayer(2) ;
         getBoard() ->setPlayer ( NULL  ,2 ) ;  
         getBoard () -> setPlayer ( new player(2) , 2 ) ;
     }
     while(!listOfStep.empty())
         listOfStep.pop_back();                        

     
}

// integer validation based on the minimum value and maximum value 
int GameController :: IntInput ( int min , int max ) 
{	
    int input ; 
  
	do
	{
        //cout << "Please enter a number"<<endl ; 
        cin >> input ; 
        if(cin.fail() || ( input < min || input > max )) {
                      cin.clear(); 
                      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                      }
        
        
        }while ( cin.fail() || ( input < min || input > max ) );
        
    return input;
        
}

bool GameController :: IntInput ( int& inputNumber , int min , int max ) 
{
     int input ;      
     cin >> input ; 
     if ( cin.fail() || ( input < min || input > max ) )
     {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        return false;
     }
     else
     {
        inputNumber = input ;      
        return true ;  
     }
}

//check whether the directions of the animal in the direction set is out bound
direction* GameController :: checkOutBound (animal* source , direction* directionSet , int arrSize )
{
           int posX = source -> getPosX () ; 
           int posY = source -> getPosY () ;
            
           for(int i = 0 ; i < arrSize ; i ++ )
                   if(  posX + directionSet[i] . getDx() < 0 ||  posX + directionSet[i] . getDx() > WIDTH-1 ||
                        posY + directionSet[i] . getDy() < 0 ||  posY + directionSet[i] . getDy() > HEIGHT-1 )
                               directionSet[i].setValid(false) ;
                   else 
                               directionSet[i].setValid(true) ;
                               
           return directionSet ; 
                   
           
                      
}



animal* GameController :: searchAnimal ( int index , player* source )
{
        return source -> getAnimal ( index ) ;         
}

//check whether the move is valid  
direction* GameController :: checkMove ( animal* source ) 
{
     /*
       four direction:
            
       1:up        (-1,0)
       2:right     (0,1)
       3:down      (1,0)
       4:left      (0,-1)
     
     */
     int posX = source -> getPosX () ;
     int posY = source -> getPosY () ;
     
     direction* choicOfAnimal = new direction[4] ;
      
     choicOfAnimal[0] = direction ( -1 , 0 );
     choicOfAnimal[1] = direction ( 0 , 1 );
     choicOfAnimal[2] = direction ( 1 , 0 );
     choicOfAnimal[3] = direction ( 0 , -1 );
     
     checkOutBound( source , choicOfAnimal  , 4 ) ; 
     for( int i = 0 ; i < 4 ; i ++ )
     {
          //If that direction is valid
          //check whtether the nearby grid is reachable
           
          if( choicOfAnimal[i].getValid() == true ) 
          {
              
              bool flag =  board -> getItem( posY + choicOfAnimal[i].getDy() , posX + choicOfAnimal[i].getDx()) -> check_moved ( source , choicOfAnimal[i].getDy() , choicOfAnimal[i].getDx() ) ;
              bool landFlag = board -> getLandscape( posY + choicOfAnimal[i].getDy() , posX + choicOfAnimal[i].getDx()) -> check_moved ( source , choicOfAnimal[i].getDy() , choicOfAnimal[i].getDx() ) ;
              
              if(flag == false || landFlag == false)
                    choicOfAnimal[i].setValid(false) ;   
              else if ( flag == true)
                    choicOfAnimal[i].setValid(true) ;
          
               
          }   
     }
     
     
     return choicOfAnimal ; 
}




void GameController :: test ()
{
    Control () ;  
    
}

void GameController :: setBoard (GameBoard*  a)
{
    board = a ;  
}

// animal move 
bool GameController :: move ( int animal_no , int player_no  , int direc   )
{
    SaveStep (board) ;  
    animal* ani = board -> getPlayer (player_no) -> getAnimal(animal_no);  
    direction* set = checkMove(ani) ;
   
   
            if( set[direc].getValid() == false)
            {        
                  cout << " not valid" <<endl ;    
                  return false;
            }     
    
    direction choice = set[direc] ; 
    
    int y = ani -> getPosY () ; 
    int x = ani -> getPosX ();
    int dy = choice.getDy() ; 
    int dx = choice.getDx() ;  
    
    board -> setItem ( y , x , board -> getLandscape(y,x)) ;
    board -> setAnimal ( ani -> getPosY()  ,  ani -> getPosX() , NULL ) ;
    board -> getItem( y , x ) -> left_by_animal ( ani )  ;  
    ani->move( dy , dx ) ;
    board -> getItem ( ani -> getPosY() , ani -> getPosX() ) ->  moved_by_other ( ani , dy , dx  ) ;
    board -> setAnimal( ani -> getPosY() , ani -> getPosX() , ani ) ;   
    board->update();
    
}

//game control , used to start game
//Not useful now , but for debugging 
void GameController :: Control ()
{
     board -> update () ;
     board -> displayBoard() ;
     int a = 1 ;
     direction* set = NULL ; 
     int direc =  0 ;  
     while(1)
     {   
       cout << board->getPlayer(a)->getPlayerName() << "'s turn " << endl ;     
       displayPlayerAnimal (a);
       cout << " Please enter a number between 0 to 7 " <<endl ;     
       int choice = IntInput(0,7) ;
       set =  displayAnimalDirection( checkMove( board -> getPlayer(a) -> getAnimal(choice) ) ) ;
       cout << " Please enter a number between 0 to 3 " <<endl ; 
       direc = IntInput(0,4) ;  
       
       if(!move(choice,a,direc)) ;
                                 cout << "UNABLE TO MOVE" <<endl;  
       system("cls");      
       board -> update () ; 
       board -> displayBoard() ; 
       a = a % 2 ; 
       a++ ; 
             
             
     }     
     
     
     
}

//display animal list
//Not useful now 
void GameController :: displayPlayerAnimal (int player_no )
{
    cout << "Number\tAnimal Name " <<endl;
    HANDLE cHandle;
    cHandle = GetStdHandle(STD_OUTPUT_HANDLE);   
    for(int i = 0 ; i < 8 ; i ++ )
               if( board->getPlayer(player_no)->getAnimal(i)->getAlive() )
    {
                   cout << i << "\t";
                   SetConsoleTextAttribute(cHandle, board->getPlayer(player_no)->getColor ()  );
                   cout << board->getPlayer(player_no)->getAnimal(i)->getName();  
                   cout <<endl ;
                   SetConsoleTextAttribute(cHandle, 15 );
    }  
     
     
}

//display animal's valid direction 
direction*  GameController :: displayAnimalDirection(direction* set) const
{
   string directionName[4] = { "Up" , "Right" ,"Down","left"} ;
   cout << "Avaliable direction"<<endl ;     
   for(int i = 0  ; i  < 4 ; i ++ )
   {
             if( set[i].getValid() == true)
             {       
                  cout << i << "\t" ;    
                  cout << directionName[i] <<endl ;
             }      
   }  
     
}

GameBoard* GameController :: getBoard () { return this->board ; }

GameController :: ~GameController ()
{
        if( board != NULL )  
        {     
                free(board);
                board = NULL ;  
        }                            
               
}

//Save game 's stat including round , name of players , position x and y of animals 
bool GameController :: saveGame () 
{
    ofstream fout;
    fout.open("jungleChessSaveGame.txt");
    fout << round << "\n" ; 
    fout << board -> getPlayer(1) -> getPlayerName ()  << " " << board -> getPlayer(1) -> getColor () << "\n" ;
    fout << board ->getPlayer(2) -> getPlayerName () << " " << board -> getPlayer(2) -> getColor () << "\n" ;   
    for( int i = 0 ; i < 8 ; i ++ )
    {
         fout << board -> getPlayer(1) -> getAnimal (i) -> getPosX () << " "; 
         fout << board -> getPlayer(1) -> getAnimal (i) -> getPosY () << " ";
         fout << board -> getPlayer(1) -> getAnimal (i) -> getAlive() << " " ; 
         fout << board -> getPlayer(1) -> getAnimal (i) -> getPower() << "\n" ; 
         
    } 
    
    for( int i = 0 ; i < 8 ; i ++ )
    {
         fout << board -> getPlayer(2) -> getAnimal (i) -> getPosX () << " "; 
         fout << board -> getPlayer(2) -> getAnimal (i) -> getPosY () << " ";
         fout << board -> getPlayer(2) -> getAnimal (i) -> getAlive() << " " ; 
         fout << board -> getPlayer(2) -> getAnimal (i) -> getPower() << "\n" ; 
    } 
     
    fout.close() ; 
    return fout.good() ;  
}

bool GameController :: loadGame () 
{
    ifstream fin;
    fin.open("jungleChessSaveGame.txt");
    int theRound ;   
    string Player1name  , Player2name ;
    int color1 , color2 ;
     
    fin >> theRound ; 
    
    fin >> Player1name ; 
    fin >> color1 ; 
    
    fin >> Player2name ; 
    fin >> color2 ; 
    
    setRound(theRound) ; 
    
    board -> getPlayer(1) ->setPlayerName(Player1name) ;
    board -> getPlayer(1) ->setColor(color1) ; 
     
    board -> getPlayer(2) ->setPlayerName(Player2name); 
    board -> getPlayer(2) -> setColor(color2) ; 
    
    changePlayerColor(1,color1);
    changePlayerColor(2,color2);
          
    for( int i = 0 ; i < 8 ; i++ ) 
    {
         int X ; 
         int Y ; 
         bool Alive ;
         int power ;  
         fin >> X ; 
         fin >> Y ; 
         fin >> Alive ; 
         fin >> power ; 
         board -> getPlayer(1) -> getAnimal (i) -> setX (X) ; 
         board -> getPlayer(1) -> getAnimal (i) -> setY (Y) ;
         board -> getPlayer(1) -> getAnimal (i) -> setAlive(Alive) ; 
         board -> getPlayer(1) -> getAnimal (i) -> setPower(power) ;
    } 
    
    for( int i = 0 ; i < 8 ; i++ ) 
    {
         int X ; 
         int Y ; 
         bool Alive ; 
         int power ;
         fin >> X ; 
         fin >> Y ; 
         fin >> Alive ; 
         fin >> power ;
         board -> getPlayer(2) -> getAnimal (i) -> setX (X) ; 
         board -> getPlayer(2) -> getAnimal (i) -> setY (Y) ;
         board -> getPlayer(2) -> getAnimal (i) -> setAlive(Alive) ; 
         board -> getPlayer(2) -> getAnimal (i) -> setPower(power) ;
    } 
    board -> update () ; 
    fin.close() ; 
    
     
}
/*
     Save step should be done before move


*/
bool GameController :: SaveStep ( GameBoard* sourceBoard )
{
     
   animalDataSet theStep = animalDataSet() ;
   theStep.initialise(sourceBoard);   
   listOfStep.push_back(theStep) ; 
   return true ;    
}

bool GameController :: undo ()
{
     if( listOfStep.empty() == true || listOfStep.size() == 1 ) 
        return false;
         
     /*
         Odd number turn's player (Player1) should be configured with node with odd number
             therefore , if size of list == even number  , then pop one node  , else pop two node 
         Even number turn's player (Player2) should be configured with node with even number
             therefore , if size of list == odd number  , then pop one node  , else pop two node 
             
         Special case : when undo many times , player1 should be finally configured with first node 
                        when undo many times , player2 should be finally configured with second node      
            
     */
     if(listOfStep.size() % 2 == round % 2 )
     {
            if( round % 2 == 1 ) 
            {             
              for(int i = 0 ; i < 2 ; i ++ )
              {
                      if( listOfStep.empty() == false || listOfStep.size() > 1 ) 
                         listOfStep.pop_back() ;       
              }
            }
            else
            {
                      if( listOfStep.size() == 2)       
                          return false ; 
                      else
                      {
                         for(int i = 0 ; i < 2 ; i ++ )
                         {
                          if( listOfStep.empty() == false || listOfStep.size() > 2 ) 
                              listOfStep.pop_back() ;       
                         } 
                          
                      }
                
            } 
                                 
     }
     else
     {
              if( listOfStep.empty() == false || listOfStep.size() > 1 ) 
                         listOfStep.pop_back() ; 
     }
     
     //If the list is empty or size not equal to the properties of the turn (e.g size = even , round = odd ... )
     if( listOfStep.empty() == true || listOfStep.size() % 2 != round % 2  )
         return false;                 
     
     for( int playerNo = 1 ; playerNo < 3 ; playerNo ++ )
     {
          for( int animalNo = 0 ; animalNo < 8 ; animalNo ++  )
          {  
           board->getPlayer(playerNo)->getAnimal(animalNo)->setX( listOfStep.back().getAnimalDataAt(playerNo,animalNo).getCordX () ) ;     
           board->getPlayer(playerNo)->getAnimal(animalNo)->setY( listOfStep.back().getAnimalDataAt(playerNo,animalNo).getCordY () ) ;
           board->getPlayer(playerNo)->getAnimal(animalNo)->setPower( listOfStep.back().getAnimalDataAt(playerNo,animalNo).getPower() ) ;
           board->getPlayer(playerNo)->getAnimal(animalNo)->setAlive( listOfStep.back().getAnimalDataAt(playerNo,animalNo).getAlive () ) ;
           }
     }
     return true ; 
     
}


void GameController :: changePlayerColor( int playerNo , int Color ) 
{
     for( int i = 0 ; i < 8 ; i ++ )
          getBoard() -> getPlayer(playerNo) -> getAnimal(i) -> setColor (Color) ;
     getBoard() -> getPlayer(playerNo) -> setColor(Color) ;

}



