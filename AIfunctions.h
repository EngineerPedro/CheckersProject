#ifndef AIFunctions_H
#define AIFunctions_H

#include <bitset>
#include <vector>
#include <cstdint>
#include <string>

class Move;

enum PLayer {W,B};

class  AIFunctions{
  public :
  
  //AI 
  size_t iterative_deep(std::vector <Move> &moves,Move &bestop, bool &keyturn, Player Maximize);
  bool alpha_beta_start(std::vector<Move> &move,bool &keyturn,size_t depth,Move &bestop ,Player maximize, );
  int64_t alpha_beta(size_t depth, int64_t alpha, int64_t beta, PLayer maximize, Play current, bool  );
  
  
  
  
}
#endif