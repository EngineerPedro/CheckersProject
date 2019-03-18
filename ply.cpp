#include "ply.h"
using namespace std;

/**  
  board initState;
  vector<legalMoves> possibleMoves;
  board nextState;
  **/

ply::ply() {};
ply::~ply() {};
  
  //Purpose: Given a state of current board, generate all a vector containing all legal moves for the player
  //Parameters: Board object containing current piece positions
void ply::generateMoves(board m,bool comp)
{
  legalMoves n;
    
  for(int i=0;i<31;i++)
    {
      
      (comp)? continue: goto black_piece;
      
      if(m.B[i]==(1 || 3)) // if white piece
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
		  possibleMoves.push(n);
		}
	    }
	  if( ((i%8) >=1) && ((i%8)<=3))
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
	    if(i%8!=5 && i>4)
	      {
		if(m.B[i-4]==0) //Move to empty space
		  {
		    n.from =i;
		    n.to = i-4;
		    n.value = 0;
		    possibleMoves.push(n);
		  }
		else if(m.B[i-4]==(2||4) && m.B[i-7]==0 && (i-7 >=1)) // Capture
		  {
		    n.from = i;
		    n.to = i-7;
		    (m.B[i-4]==2)? n.value=1: n.value =2;
		    possibleMoves.push(n);
		    
		  }
	      }
	    
	  //Move king to empty space/capture
	    if(i%!=4 && i>4)
	      {//empty space
		if(m.B[i-3]==0)
		  {
		    n.from =i;
		    n.to = i-3;
		    n.value = 0;
		    possibleMoves.push(n);
		}
		//Captures piece
		else if(m.B[i-3]==(2 || 4))
		  {
		    if(i<=31 && i>=9 && i%8!=0 && m.B[i-7]==0)
		      {
			n.from = i;
			n.to = i-7;
			(m.B[i-3]==2)? n.value=1: n.value=2;
			possibleMoves.push(n);
		      }
		  }
	      }
	  }

	}
	//End of white piece/white king section

    }
  return;

  
  
  //Black piece
 black_piece:
  for(int i=0;i<32;i++)
    {
      
      if(m.B[i]==(2||4))
	{
	  if(i>4)
		{
		  if( m.B[i-4]==0)
		    {
		      n.from=i;
		      n.to=i-4;
		      n.value=0;
		      possibleMoves.push(n);
		    }
		  
		  else if(m.B[i-4]==(1||3)
		    {
		      //Diagnol up and to the left
		      if((i%8)<=4 && (i%8)>1)
			{
			  if(m.B[i-9]==0)
			    {
			      n.from=i;
			      n.to = i-9;
			      (m.B[i-4]==1)? n.value = -1: n.value=-2;
			      possibleMoves.push(n);
			    }
			}
		      //Diagnol up and to the right
		      else if((i%8)<=1 || (i%8)>=5)
			{
			  if(m.B[i-8]==0)
			    {
			      n.from=i;
			      n.to=i-8;
			      (m.B[i-4]==1)? n.value=-1: n.value=-2;
			    }
			}
		    }
		    
		    if((i>8) && (i%8)!=(5||4))
		      {
			if(m.B[i-3]==0)
			  {
			    n.from=i;
			    n.to=i-3;
			    n.value=0;
			    possibleMoves.push(n);
			  }
			else if(m.B[i-3]==(1||3))
			  {
			    if((i%8)>=1 && (i%8)<=4 && m.B[i-7]==0)
			      {
				n.from = i;
				n.to = i-7;
				(m.B[i-3]==1)? n.value=-1: n.value=-2;
				possibleMoves.push(n);
			      }
			  }
			
		      }
		    if(i%8==(6 || 7 || 0))
		      {
			if(m.B[i-5]==0)
			  {
			    n.from=i;
			    n.to=i-5;
			    n.value=0;
			    possibleMoves.push(n);
			  }
			else if(m.B[i-5]==0 && i>=14)
			  {
			    if(m.B[i-5] == (1||3) && (m.B[i-9]==0))
			      {
				n.from=i;
				n.to=i-9;
				(m.B[i-5]==1)? n.value=-1:n.value=-2;
				possibleMoves.push(n);
			      }
			    
			  }
		      }
		    
		    
		    //Black King
		    if(m.B[i]==4)
		      {
			
			if(m.B[i+4]==0 && ((i+4)<32)) // move to empty place
			  {
			    n.from = i;
			    n.to = i+4;
			    n.value = 0;
			    possibleMoves.push(n);
			  }
			
			else if(m.B[i+4] == (1||3) && ((i+8)<32) && m.B[i+8] == 0) // Capture
			  {
			    n.from = i;
			    n.to = i+8;
			    (m.B[i+4]==1)? n.value=-1:n.value=-2;
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
			    if(m.B[i+3] == (1||3) && ((i+6)<32) && m.B[i+6] == 0) // Capture
			      {
				
				n.from = i;
				n.to = i+6; 
				
				(m.B[i+3]==1)? n.value=-1:n.value=-2; 
				
				           
				possibleMoves.push(n);
			      }
			  }
			
			if( ((i%8) >=1) && ((i%8)<=3))
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
		      }
		    }
		    
		    
		    
		    
		  
		}
	}
    }
}

		    
		    

