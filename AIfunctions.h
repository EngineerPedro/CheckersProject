#ifndef AIFunctions_H
#define AIFunctions_H

#include <bitset>
#include <vector>
#include <cstdint>
#include <string>

class Move;

enum Player {W,B};

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
  inline int score_0();
  inline int score_1();
  inline int score_2();
  inline int score_4();
  
    std::bitset<32> *w_pieces,
                    *b_pieces,
                    *w_kings,
                    *b_kings;

    static constexpr int endgame_weights[] = {  9,  3,  0,  0,
                                              9,  3,  0,  0,
                                                3,  0,  0,  0,
                                              3,  0,  0,  0,
                                                0,  0,  0,  3,
                                              0,  0,  0,  3,
                                                0,  0,  3,  9,
                                              0,  0,  3,  9  };
private;
};
#endif