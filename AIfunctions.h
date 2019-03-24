#ifndef AIfunctions_H
#define AIfunctions_H
#include <vector>
#include <cstdint>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <limits>
#include <bits/stdc++.h>

#define INFINITE 30000

#include "ply.h"

using namespace std;

const int MAX_DEPTH = 20;

list <int> *adj;


class  AIfunctions
{
  public :
  AIfunctions();
  ~AIfunctions();
  
  //AI Functions 
  bool DLS(int src, int target,int limit);
  int Alpha_Beta(int alpha, int beta, int depth,bool Maximizing_Player,int Node_Index,int values[8][8]);
  bool Iterative_Deepening_DFS(int src, int target,int max_depth);
};
#endif