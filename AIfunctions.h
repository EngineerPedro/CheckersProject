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

ply node;
//vector <node> tree;

const int MAX_DEPTH = 20;

//list <int> *adj;

moves *adj;

struct Tree_Node{
  Tree_Node *parent;
  moves m;
  //State s;
  //Tree_node *c [];
};

class  AIfunctions
{
  public :
  AIfunctions();
  ~AIfunctions();
  //the PASS
  //auto pass_the_code(spacestate *PTR);
  //AI Functions 
  bool DLS(int src, int target,int limit);
  int Alpha_Beta(int alpha, int beta, int depth,bool Maximizing_Player,int Node_Index,int values[]);
  bool Iterative_Deepening_DFS(int src, int target,int max_depth);
};
#endif