#ifndef BOARD_H
#define BOARD_H

#include <Rcpp.h>
#include <list>
#include <vector>
#include <random>     // for random shuffle
#include <memory>

#include <algorithm>
#include <string>
#include "Space.h"
#include "Die.h"
#include "Camel.h"

using namespace std;

class Board {
private:
  int nSpaces;
  std::vector<std::shared_ptr<Space>> spaces;
  std::vector<Die> dice;
  // std::vector<Camel> camels;
  std::map<std::string, std::shared_ptr<Camel>> camels;
  std::vector<std::string> colors;
  bool debug;
  std::vector<std::string> ranking;
public:
  Board();

  Board(int n, bool d = false);

  Board(const Board & b);

  ~Board(){}

  void shuffleDice();

  int getNDiceRemaining();

  void resetDice();

  void initCamels();

  int getNCamels();

  void fillCamelPosArrays(Rcpp::CharacterVector *camelColors, Rcpp::IntegerVector *spaceArray, Rcpp::IntegerVector *heightArray, int start);

  Rcpp::DataFrame getCamelDF();

  std::string moveTurn();

  void generateRanking();

  std::vector<std::string> getRanking();

  std::shared_ptr<Camel> getCamel(std::string color);

  void placePlusTile(int n, std::shared_ptr<Player> p);

  void placeMinusTile(int n, std::shared_ptr<Player> p);

  std::shared_ptr<Space> getSpaceN(int n);

  std::vector<Die> getDice();

  void setDice(std::vector<Die>);

  int getFirstPlaceSpace();

  void progressToEndLeg();

  void progressToEndGame();

  void clearBoard();

  void createAddCamel(std::string color, int space);

  void addCustomCamel(std::string color, int space, bool diePresent, int nBetsLeft);

  // DataFrame getDiceDF();
};

RCPP_EXPOSED_CLASS(Board)
#endif
