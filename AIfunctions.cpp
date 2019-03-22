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

int AIfunctions :: iterative_deep(std::vector <Move> &moves,Move &bestop, bool &keyturn, Player Maximize)
{

  int depth = 1;
  int finished =0;
  Move k;
  bool maxDepthReached;
  while(!keyturn)
  {
    maxDepthReached = alpha_beta_start(depth,k,keyturn,maximize);
    if(!keyturn)
    {
      bestop = k;
      finished = depth;
    }
    if(!maxDepthReached)
      keyturn = true;
      depth + = 2;
  }
  return finished;
}

bool AIfunctions :: alpha_beta_start(std::vector<Move> &move,bool &keyturn,int depth,Move &bestop ,Player maximize)
{
  int beta = std::value_limits<int > :: max();
  int alpha = std::value_limits<int > :: min();
  int best = std::value_limits<int > :: min();
  bool maxDepthReached = false;
  for(auto move : moves){
   int k =move.board -> alpha_beta(alp,beta,depth-1,maximize,other_player(maximize),maxDepthReached,keyturn); 
   if(best<k){
      bestop = move;
      alpha = k;
      best= k;
   }
    if(beta <= alpha)
      break;
  }
  return maxDepthReached;
}

int AIfunctions :: alpha_beta(size_t depth, int alpha, int beta, PLayer maximize, Play current, bool &maxDepthReached, bool & keyturn )
{
  if (keyturn){return 0;}
  
  if (depth==0)
  {
    maxDepthReached =true;
    return score(maximize);
  }
  std::vector<Move> moves;
  possible_moves(current, moves);
  seperated_moves(moves, false);
  
  if (moves.size() == 0){
    if(current ==  maximize)
      return std::value_limits<int> :: lowest();
    return std::value_limits<int> ::max();
  }
  
  if(current == maximize){
    for(auto move : moves){
      int v = move.AIfunctions->alpha_beta(depth-1,alpha,beta,maximize,other_player(current), keyturn, maxDepthReached)
      alpha = std :: max(alpha,v);
      if (beta <= alpha)
        break; 
    }
    return alpha;
  }
  else
  {
    for (auto move : move)
    {
      int v = move.AIfunctions->alpha_beta(depth-1,alpha,beta,maximize, other_player(current),keyturn,maxDepthReached);
      beta = std ::min(beta, v);
      
      if(beta<=alpha)
        break;
    }
    return beta;
  }
}
/*
int64_t AIfunctions :: score(Player p)
{
  int cadence = 0;
  cadence+= score_0()* 1e12;
  cadence+= score_1()* 1e9;
  cadence+= score_2()* 1e6;
  cadence+= score_3()* 1e3;
  
  cadence += rand() % 100;
  
  return p == White ? cadence : -cadence;
}

int64_t AIfunctions ::  score_0()
{
  const int k_mass = 2;
  const int b_mass = 3;
  return k_mass w_kings-count()
        -k_mass * b_kings ->count()
        +b_mass * w_pieces ->count()
        -b_masst * b_pieces ->count();
}

int64_t AIfunctions :: score_1()
{
  return w_pieces->count() - b_pieces->count;
}

int64_t AIfunctions :: score_2
{
int64_t cadence = 0;
if (w_pieces->count()< 4 || b_pieces->count() < 4)
  {
  if((w_pieces->count()<b_pieces->count() ) )
  {
  if((*w_pieces)[0] || (*w_pieces)[4])
  {
  cadence += 9;
  cadence -= (*b_pieces)[0] * 3;
  cadence -= (*b_pieces)[4] * 3;
  cadence -= (*b_pieces)[1] * 1;
  cadence -= (*b_pieces)[5] * 1;
  cadence -= (*b_pieces)[8] * 1;
  cadence -= (*b_pieces)[12] * 1;
  }
  if ((*w_pieces)[27] || (*w_pieces)[31])
    {
     cadence += 9;
     cadence -= (*b_pieces)[27] * 3 ;
     cadence -= (*b_pieces)[31] * 3 ;
     cadence -= (*b_pieces)[19] * 1 ;
     cadence -= (*b_pieces)[]23 * 1 ;
     cadence -= (*b_pieces)[26] * 1 ;
     cadence -= (*b_pieces)[30] * 1 ;
     
    }  
   }
   if((b_pieces->count() < w_pieces->()))
   {
    if((*w_pieces)[27] || (*w_pieces)[31])
    {
    cadence -= 9;
    cadence += (*w_pieces)[0] *3 ;
    cadence += (*w_pieces)[4] *3 ;
    cadence += (*w_pieces)[1] *1 ;
    cadence += (*w_pieces)[5] *1 ;
    cadence += (*w_pieces)[8] *1 ;
    cadence += (*w_pieces)[12] *1;
    }
    if ((*b_pieces)[27] || (*b_pieces)[31])
    {
    cadence -= 9;
    cadence += (*w_pieces)[27]* 3;
    cadence += (*w_pieces)[31]* 3;
    cadence += (*w_pieces)[19]* 1;
    cadence += (*w_pieces)[23]* 1;
    cadence += (*w_pieces)[26]* 1;
    cadence += (*w_pieces)[30]* 1;
    }
   }
  }
return cadence;
}

*/