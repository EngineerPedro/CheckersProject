#include <iostream>
#include <vector>
//#include "checkers.h"

using namespace std;

struct legalMoves
{
  int from;
  int to;
  int value;
};


class ply
{
  board B[32];
  vector<legalMoves> possibleMoves;
  bool comp;

 public:
  ply();
  ~ply();

  
  generateMoves(board, comp);

  //private:
  //convertBoard(board);

};
