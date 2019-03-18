#include "ply.h"
using namespace std;

/**  
  board initState;
  vector<legalMoves> possibleMoves;
  board nextState;
  **/

  ply::ply();
  ply::~ply();
  
  //Purpose: Given a state of current board, generate all a vector containing all legal moves for the player
  //Parameters: Board object containing current piece positions
  void ply::generateMoves(board m)
  {
    legalMoves n;
    
    for(int i=0;i<31;i++)
    {
      if(m.B[i]==1 || 3) // if white piece
      {
        if(m.B[i+4]==0 && ((i+4)<32)) // move to empty place
        {
          n.from = i;
          n.to = i+4;
          n.value = 0;
          possibleMoves.push(n);
        }
        if(m.B[i+4] == (2||4) && ((i+8)<32) && m.B[i+8] == 0) // Capture
        {
          n.from = i;
          n.to = i+8;
          (m.B[i+4]==2)? n.value=1:n.value=2; 
            
          m.B[i+4] = empty;           
          possibleMoves.push(n);
          
        }
        if(i%8 != 1 && i%8 !=4 && i%8 != 0) //position is not on left side or right side of board
        {
          if(m.B[i+3]==0)
          {
            n.from = i;
            n.to = i+3;
            n.value = 0;
            possibleMoves.push(n);
          }
          if(m.B[i+3] == (2||4) && ((i+6)<32) && m.B[i+6] == 0) // Capture
          {
            
            n.from = i;
            n.to = i+6; 
            
            (m.B[i+3]==2)? n.value=1:n.value=2; 
            
             m.B[i+3] = empty;           
             possibleMoves.push(n);
          }
	}
	if( (i%8) >=1 && (i%8)<=3)
	  {
	    //move to empty space
	    if(m.B[i+5]==0)
	      {
		n.from = i;
		  n.to = i+5;
		  n.value = 0;
		  possibleMove.push(n);
	      }
	    
	  }
	  
        if(m.B[i]==3) // white king
        {
	  // Diagnol Up&Left 
	  if(i%8!=5 && i>4) && m.B[i-4]==0)
	    {
	      if(m.B[i-4]==0) //Move to empty space
		{
		  n.from =i;
		  n.to = i-4;
		  n.value = 0;
		  possibleMoves.push(n);
		}
	      else if(m.B[i-4]%2==0 && m.B[i-7]==0 && i-7 >=1) // Capture
		{
		  n.from = i;
		  n.to = i-7;
		  n.value = 1;
		  possibleMoves.push(n);
		  
		}
	    }

	    
	  if(i%!=4 && i>4 && m.B[i-3]==0)
	    {
	      n.from =i;
	      n.to = i-3;
	      n.value = 0;
	      possibleMoves.push(n);
	    }
          
        }
      }
      
      }
      
    }
    
    
    
  }
  

  //Purpose: Rank legal moves vector in ascending order based on evaluation of each move
  //Parameters: None
  void ply::rankMoves()
  {
    
    
    
  }


  //Purpose: Update state of game with a given move
  //Parameters: Board object and legalMoves object
void ply::getNextState(board n, legalMoves *m)
{ 
  
}



  //Purpose: Function to be called to find ply and update the board
  //Parameters: Current board state is updated via pass by reference
void search(board& b)
{
  
  depth--;

  if(depth==0)
    return
  
  generateMoves(b);
  rankMoves();

  if(agent)
    m=&legalMoves.back();

  else 
    m=&legalMoves.front();
  
  getNextState(b, move);
  
  if(depth!=0)
  search(b);  
  
}

int miniMax(int depth, board B, bool comp)
{
  if(depth==0)
    return evalF(B);


  if(comp)
    {

      int bestMove = -99999;
      

      while(depth!=0)
	{
	  bestMove = fmax(bestMove, miniMax(--depth,B,!comp));
	}
      return bestMove;
    }



}
