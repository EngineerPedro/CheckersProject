#include <iostream>
#include <vector>

#include "AIfunctions.h"
using namespace std;

struct moves
{
  int from;
  int to;
  int value;
  int capture;
};


class ply
{
  protected:
  
  vector<moves> pMoves;
  
  //Utility Functions        <same board passed to both>
                              //VVVVVVVVVVVVVVVVVVVVVVV
  void getWmoves(const int[]/*position of white pieces */,vector<moves>&/*possible moves*/,int/**/);
  void getBmoves(const int[]/*position of black peices */,vector<moves>&/*possible moves*/,int/**/);
  void doubleJump(int []/**/, moves&/**/, int/**/);  

  
 public:
    
    ply();
    ~ply();
    //Purpose: Given a state of current board, generate all a vector containing all legal moves for the player
    //Parameters: Board object containing current piece positions
    void generateMoves(const int[]/*current state of board*/,vector<moves>&/*possible moves */, bool/*whos turn it is */);
    
    
    
};

  
