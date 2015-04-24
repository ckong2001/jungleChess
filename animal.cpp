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
#include "animal.h"


animal :: animal ()
          :item() , player_side(0) , jump_able(false) , swim_able(false)   
{
          is_alive = true ;
          toPower ();
          setColor(0);           
}

animal :: animal (int item_n , int play_s ,  int Y , int X , bool jump_a  , bool swim_a )
          :item( item_n , Y ,  X )  , player_side(play_s) , jump_able(jump_a) ,swim_able(swim_a)  
{
          if( (getItemNo() < 4 && getItemNo()!= 0  ) || getItemNo() > 11 )
          {
              cout << "SET ANIMAL ERROR"<<endl ;
              setItemNo(4) ; 
          } 
          setColor(player_side);
          toPower ();
          is_alive = true ;      
}

bool animal :: getAlive () { return is_alive ; } ;
void animal :: setAlive ( bool alive) { is_alive = alive; }

int animal :: getPower () { return power; };
void animal :: setPower ( int pow ) { power = pow ; }
              
void animal :: setPlayerSide ( int side ) { player_side = side ; };
int animal :: getPlayerSide () { return  player_side ; }; 

bool animal :: getJump () {return jump_able ;} ; 
void animal :: setJump (bool jump){ jump_able = jump ;} ;
              
bool animal :: getSwim () {return swim_able;} ; 
void animal :: setSwim ( bool swim) { swim_able = swim ; }  ;
 

//This function will would turn this animal into different status based on the type of the animal 

bool animal :: moved_by_other (animal* source  , int dy , int dx )
{
     //
     if( source -> getPlayerSide() == this-> player_side )
             return false ;
     else if( source-> getPower() >= this->power )
     {
             this->setAlive(false);
             return true ; 
     }
     else if ( source-> getPower() < this->power )
             return false; 
     
}

// check whether the another animal would move to this animal 
bool  animal :: check_moved (animal* source , int dy , int dx  )//
{
     
     if( source -> getPlayerSide() == this -> player_side  )
         return false;
     else if ( source -> getPower() < this->power)  
         return false ;
     else if ( source -> getPower() >= this->power && source -> getAlive() == true )
         return true ; 
     
}


bool animal :: move ( int dy , int dx  ) 
{
     
     if( board == NULL ) 
     {
         cout << "BOARD NULL ERROR" <<endl ;     
     }

         setX ( this->getPosX() + dx ) ; 
         setY ( this->getPosY() + dy ) ;
             
}

void animal :: toPower ()
{
     power = getItemNo() - 3 ;      
     
}


void animal :: setBoard ( GameBoard* Board ) 
{
   board = Board ;   
} 


