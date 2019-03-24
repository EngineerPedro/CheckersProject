#include "ply.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;


void updateBoard(int b[], moves m)
{
  b[m.to]=b[m.from];

  if(b[m.from]==1 && m.to>=28)
    b[m.to]=2;
    
  else if(b[m.from]==-1 && m.to <=3)
    b[m.to]=-2;




  if(abs(m.from-m.to) <6)
    {
      b[m.from]=0;
      return;

    }
  else
    {
      if(m.from-m.to == 7)
	{
	 if(m.from%8<4)
	   {
	     b[m.from-3]=0;
	     b[m.from]=0;
	   }
	 else
	   {
	     b[m.from-4]=0;
	     b[m.from]=0;
	   }
	 
	}
      else if(m.from-m.to == -7)
	{
	  if(m.from%8<4)
	    {
	      b[m.from+4]=0;
	      b[m.from]=0;
	    }
	  else
	    {
	      b[m.from+3]=0;
	      b[m.from]=0;
	    }

        }
      else if(m.from-m.to == 9)

	{
	  if(m.from%8<4)
	    {
	      b[m.from-4]=0;
	      b[m.from]=0;
	    }
	  else
	    {
	      b[m.from-5]=0;
	      b[m.from]=0;
	    }
	}
      else
	{ 
	  if(m.from%8<4)
            {
              b[m.from+5]=0;
              b[m.from]=0;
            }
          else
            {
              b[m.from+4]=0;
              b[m.from]=0;
            }
        }

    }
}




int main()
{

  ply turn;
  int Board[32];
  bool max=true;
  vector<moves> moveList;
  int input;
  
  for(int i=0;i<12;i++)
    {
      Board[i]=1;
      Board[23-i]=0;
      Board[31-i]=-1;
    }
  
  int timer=100;
  cout << endl;

  while(timer>0)
    {
      for(int i=0;i<32;i++)
	{
	  
	  
	  if(i%8<4)
	    cout << setw(3) << "|__|" << setw(3) << Board[i];
	  else
	    cout << setw(3) << Board[i] << "|__|" ;
	  
	  if(i%4==3)
	    cout << endl;
				     
	}
      
      cout << endl<< endl;
      for(int i=0;i<32;i++)
	{
	  if(i%8<4)
            cout << setw(3) << "|__|" << setw(3) << i;
          else
            cout << setw(3) << i  << "|__|" ;

          if(i%4==3)
            cout << endl;

	  
	}  
      
      
      turn.generateMoves(Board, moveList, max);
      
      
      for(int i=0;i<moveList.size();i++)
	{
      
	  cout << "\nMove " << i+1 << " : " ;
	  cout << "From: " << moveList[i].from << " \tTo: " << moveList[i].to;
	  cout << "\tValue: " << moveList[i].value ;
	  
	  
	}
      cout << endl;
      
      cout << "Max's turn: " << max<< endl;
      cout << "Turn number: " << 101-timer << endl;
      cout << "Select move number to update board: ";
      cin >> input;
      
      updateBoard(Board, moveList[input-1]);

      if(moveList.size()==0)
	{
	  cout << "No moves left! Game over! " << endl;
	  return 0;
	}
      
      moveList.erase(moveList.begin(),moveList.end());

      timer--;
      
      if(max)
	max=false;
      else
	max=true;

    }

  turn.~ply();
  return 0;
}
