#include <cstdlib>
#include <bitset>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <cstdint>

#include "AIfunctions.h"

AIfunctions:: AIfunctions
{
}

AIfunctions :: ~AIfunctions
{
}

size_t AIfunctions :: iterative_deep(std::vector <Move> &moves,Move &bestop, bool &keyturn, Player Maximize)
{
  
}
bool AIfunctions :: alpha_beta_start(std::vector<Move> &move,bool &keyturn,size_t depth,Move &bestop ,Player maximize)
{
  
}
int AIfunctions :: alpha_beta(size_t depth, int alpha, int beta, PLayer maximize, Play current, bool &maxDepthReached, bool & keyturn )
{
  if (keyturn){return 0;}
  
  if (depth==0)
  {
    maxDepthReached =true;
    return score(maximize);
  }
  std :: vector<Move> moves;
  possible_moves(moves, false);
  seperated_moves(moves, false);
  
  if (moves.size() == 0){
    if(current ==  maximize)
      return std::numeric_limits< >:: lowest();
    return std::numeric_limits< > ::max();
  }
  
}
int score(Player p)
{
  
}