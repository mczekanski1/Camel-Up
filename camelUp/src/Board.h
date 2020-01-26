#ifndef BOARD_H
#define BOARD_H

#include <Rcpp.h>
#include <list>
#include <vector>


#include <algorithm>
#include <string>
#include "Space.h"
#include "Die.h"
#include "Camel.h"

class Board {
private:
  int nSpaces;
  std::vector<Space*> spaces;
  std::vector<Die> dice;
  // std::vector<Camel> camels;
  std::map<std::string, Camel*> camels;
  std::vector<std::string> colors;
  bool debug;
  std::vector<std::string> ranking;
public:
  Board(int n, bool d = false);

  int getNDiceRemaining();

  void resetDice();

  void initCamels();

  int getNCamels();

  Rcpp::DataFrame getCamelDF();

  int moveTurn();

  void generateRanking();

  std::vector<std::string> getRanking();
};

#endif
