#ifndef AIFunctions_H
#define AIFunctions_H
#include <vector>
#include <cstdint>
#include <iostream>
#include <string>

#include "ply.h"
const int MAX_DEPTH = 20;


class  AIFunctions
{
  public :
  AIFunctions();
  ~AIFunctions();
  
  //AI Functions 
  int DLS(int src, int target,int limit);
  int Alpha_Beta(int alpha, int beta, int depth,bool Maximizing_Player,int Node_Index,int values[][]);
  int Iterative_Deepening_DFS(int src, int target,int max_depth);
};
#endif