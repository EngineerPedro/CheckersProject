#ifndef AIFunctions_H
#define AIFunctions_H

#include <bitset>
#include <vector>
#include <cstdint>
#include <string>

class Move;

enum PLayer {W,B};

constexpr Player other_player(Player p) 
{
  return (p == W) ? B : W; 
};

class  AIFunctions
{
  public :
  
  //AI 
  size_t iterative_deep(std::vector <Move> &moves,Move &bestop, bool &keyturn, Player Maximize);  
  bool alpha_beta_start(std::vector<Move> &move,bool &keyturn,size_t depth,Move &bestop ,Player maximize, );
  int alpha_beta(size_t depth, int alpha, int beta, PLayer maximize, Play current, bool &maxDepthReached, bool &keyturn  );
  int score(Player p);
  
  int score_0();
  int score_1();
  int score_2();
  int score_4();
  
    
}
#endif