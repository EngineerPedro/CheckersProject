#include "ply.h"
#include <vector>

using namespace std;

/**  

   //to handle double jumps: create doubleJump flag, if flag is true treat the vector as a string of jumps,
   //if doubleJump is false treat the vector as a list of alternative moves

   
  **/

ply::ply(){};
ply::~ply(){};
  
void ply::getWmoves(const int B[32], vector<moves>& movesList, int i)
{
  moves n;
  n.capture=0;
  int t; //var for King
  (B[i]==-2)? t=1: t=-1;
  
  //Even row and not empty space
  if(i%8>=4 && B[i]!=0 && B[i]!=-1 && i<28)
    {
      
	  if(i%8!=4)
	    {//Check for Down and Left moves
	      if(B[i+3]==0)//move to empty space
		{
		  n.from = i;
		  n.to = i+3;
		  n.value=0;
		  movesList.push_back(n);
		}
	      else if(i<24 && B[i+3]!=B[i] && B[i+3]!=(2*B[i]))//check if occupied space is opponent's piece
		{
		  if(B[i+7]==0)//if jump is available
		    {
		      n.from = i;
		      n.to = i+7;
		      (B[i+3]==(t*B[i]))? n.value=B[i+3]: n.value=B[i+3]*3;
		      n.value *=-1;
		      n.capture=i+3;
		      movesList.push_back(n);

		    }
		}
	      
	    }
	  
	  //Check for Down and Right moves
          if(B[i+4]==0 )//move to empty space
            {
              n.from = i;
              n.to = i+4;
              n.value=0;
              movesList.push_back(n);
            }
          else if(i<23 && (i%8!=7) &&  B[i+4]!=B[i] && B[i+4]!=(2*B[i]))//check if occupied space is opponent's piece
            {
	      
              if(B[i+9]==0)//if jump is available
                {
                  n.from = i;
                  n.to = i+9;
		  (B[i+4]==(t*B[i]))? n.value=B[i+4]: n.value=B[i+4]*3;
		  n.value *=-1;
                  n.capture=i+4;
		  movesList.push_back(n);
		  
                }
            }
    }

  //Odd Row and not empty space
  else if(i%8<4 && B[i]!=0 && B[i]!=-1 && i<28)
        {
	  
          
	  //Check for Down and Left moves
	  if(B[i+4]==0 )//move to empty space
	    {
	      n.from = i;
	      n.to = i+4;
	      n.value=0;
	      movesList.push_back(n);
	    }
	  //If not left side of board and occupied space is opponents piece
	  else if(i<23 && (i%8!=0) &&  B[i+4]!=B[i] && B[i+4]!=(2*B[i])) 
	    {
	      if(B[i+7]==0)//if jump is available
		{
		  n.from = i;
		  n.to = i+7;
		  (B[i+4]==(t*B[i]))? n.value=B[i+4]: n.value=B[i+4]*3;
		  n.value *=-1;
		  n.capture=i+4;
		  movesList.push_back(n);
		  
		}
	    }
	  
	  
	  //Check for Down and Right moves
	  if(i%8!=3)//exclude right side of Board
	    {    
	      if(B[i+5]==0)//move to empty space
		{
		  n.from = i;
		  n.to = i+5;
		  n.value=0;
		  movesList.push_back(n);
		}
	      else if( i<23 &&  B[i+5]!=B[i] && B[i+5]!=(2*B[i]))//check if occupied space is opponent's piece
		{
		  
		  if(B[i+9]==0)//if jump is available
		    {
		      n.from = i;
		      n.to = i+9;
		      (B[i+5]==(t*B[i]))? n.value=B[i+5]: n.value=B[i+5]*3;
		      n.value *=-1;
		      n.capture=i+5;
		      movesList.push_back(n);
		      
		    }
		}
	    }
	}

 
  

}


void ply::getBmoves(const int B[32], vector<moves>& movesList, int i)
{
  moves n;
  int t;

  (B[i]==2)? t=1: t=-1;
  
  //Even row and not empty space
  if(i%8>=4 && B[i]!=0 && B[i]!=1 && i>3)
    {

      if(i%8!=4)
	{//Check for Up and Left moves
	  if(B[i-5]==0)//move to empty space
	    {
	      n.from = i;
	      n.to = i-5;
	      n.value=0;
	      movesList.push_back(n);
	    }
	  else if(i>=12 && B[i-5]!=B[i] && B[i-5]!=(2*B[i]))//check if occupied space is opponent's piece
	    {
	      if(B[i-9]==0)//if jump is available
		{
		  n.from = i;
		  n.to = i-9;
		  (B[i-5]==(t*B[i]))? n.value=B[i-5]: n.value=B[i-5]*3;
		  n.value *=-1;
		  n.capture=i-5;
		  movesList.push_back(n);
		  
		}
	    }
	}
      
      //Check for Up and Right moves
      if(B[i-4]==0)//move to empty space
	{
	  n.from = i;
	  n.to = i-4;
	  n.value=0;
	  movesList.push_back(n);
	}
      else if((i>=12) && (i%8!=7) && B[i-4]!=B[i] && B[i-4]!=(2* B[i]))//check if occupied space is opponent's piece
	{

	  if(B[i-7]==0)//if jump is available
	    {
	      n.from = i;
	      n.to = i-7;
	      (B[i-4]==(t*B[i]))? n.value=B[i-4]: n.value=B[i-4]*3;
	      n.value *=-1;
	      n.capture=i-4;
	      movesList.push_back(n);
	      
	    }
	}
    }
  
  //Odd Row and not empty space
  if(i%8<4 && B[i]!=0 && B[i]!=1 && i>3)
    {
      //Check for Up and Left moves
      if(B[i-4]==0)//move to empty space
	{
	  n.from = i;
	  n.to = i-4;
	  n.value=0;
	  movesList.push_back(n);
	}
      //If not left side of board and occupied space is opponents piece
      else if((i>=8)&& (i%8!=0) && B[i-4]!=B[i] && B[i-4]!=(2*B[i]))
	{
	  if(B[i-9]==0)//if jump is available
	    {
	      n.from = i;
	      n.to = i-9;
	      (B[i-4]==(t*B[i]))? n.value=B[i-4]: n.value=B[i-4]*3;
	      n.value *=-1;
	      n.capture=-4;
	      movesList.push_back(n);
	      
	    }
	}
      
      
      //Check for Up and Right moves
      if(i%8!=3)//exclude right side of Board
	{
	  if(B[i-3]==0)//move to empty space
	    {
	      n.from = i;
	      n.to = i-3;
	      n.value=0;
	      movesList.push_back(n);
	    }
	  else if((i>=8) &&  B[i-3]!=B[i] && B[i-3]!=(2*B[i]))//check if occupied space is opponent's piece
	    {
	      
	      if(B[i-7]==0)//if jump is available
		{
		  n.from = i;
		  n.to = i-7;
		  (B[i-3]==(t*B[i]))? n.value=B[i-3]: n.value=B[i-3]*3;
		  n.value *=-1;
		  n.capture=i-3;
		  movesList.push_back(n);
		  
		}
	    }
	}
    }
}







  //Purpose: Given a state of current board, generate all a vector containing all legal moves for the player
  //Parameters: Board object containing current piece positions
void ply::generateMoves(const int B[], vector<moves>& pMoves, bool max)
{
  int M[32];//copy of board
  int k=0;//size
  int temp=0;
  int trimIndex=0;

  //clear vector array
  pMoves.erase(pMoves.begin(),pMoves.end());
  /**
  //Convert to 1=white piece, 2= white king, -1=black piece, -2=black king
  for(int i=0;i<32;i++)
    {
     
      if(B[i]==2)
	M[i]=-1;
      else if(B[i]==4)
	M[i]=-2;
      else if(B[i]==3)
	M[i]=2;
      else if(B[i]==1)
	M[i]=1;
      else
	M[i]=0;
    }
  **/
  
  //testing loop
  for(int i=0;i<32;i++)
    {
      M[i]=B[i];
    }



      if(max)
	{
	  for(int i=0; i<32;i++)
	    {
	      if(M[i]>=1)
		{
		  getWmoves(M,pMoves,i);
		  if(M[i]==2)
		    getBmoves(M,pMoves,i);
		}
	    }
	}
      else
	{
	  for(int i=0;i<32;i++)
	    {
	      
	      if(M[i]<=-1)
		{
		  getBmoves(M,pMoves,i);
		      if(M[i]==-2)
			getWmoves(M,pMoves,i);
		}
	    }
	  
	}
      
  
      //Sort vector before finishing
      for(int i=0;i<pMoves.size();i++)
	{
	  for(int j=1; j<pMoves.size(); j++)
	    {
	      k=pMoves.size()-j;
	      temp=pMoves[k].value;
	      
	      
	      if(pMoves[k-1].value > temp)
		{
		  
		  pMoves[k].value=pMoves[k-1].value;
		  pMoves[k-1].value=temp;
		  temp=pMoves[k].from;
		  pMoves[k].from=pMoves[k-1].from;
		  pMoves[k-1].from=temp;
		  temp=pMoves[k].to;
		  pMoves[k].to=pMoves[k-1].to;
		  pMoves[k-1].to=temp;
		}
	    }
	}
    
      k=pMoves.size()-1;
      //if captures exist in pMoves, remove non-capture moves
      if(max && pMoves[k].value>0)
	{
	  while(pMoves[k].value>0 && k>0)
	    k--;

	  pMoves.erase(pMoves.begin(), pMoves.begin()+k+1);
	}
      else if(!max && pMoves[0].value<0)
	{
	  while(pMoves[k--].value>pMoves[0].value)
	    pMoves.pop_back();
	
	}
}      
      /**
  
  //check if capture is available for Max
  if(max)
    {
      if((pMoves.back()).value>=1 && pMoves.size()>1)
	{
	  //if so, trim vector to allow only capture moves
	  for(int i=0;i<pMoves.size();i++)
	    {
	      if(pMoves[i].value>=1)
		{
		  trimIndex=i-1;
		  break;
		}
	    }
	  if(trimIndex>=0)
	    pMoves.erase(pMoves.begin(),pMoves.begin()+trimIndex);
	  
	}
    }
  
  else
    {
      if((pMoves.front()).value<=-1 && pMoves.size()>1)
        {
	  while(pMoves[k-1].value>=0)
	    {
	      pMoves.pop_back();
	      
	    }
	  /**
          //if so, trim vector to allow only capture moves
	  for(int i=k-1;i>=0;i--)
	    {
	      if(pMoves[i].value<=-1)
		{
		  trimIndex=i+1;
		  break;
		}
	    }
	  pMoves.erase(pMoves.begin()+trimIndex,pMoves.end());
	  }**/
    
  

	




