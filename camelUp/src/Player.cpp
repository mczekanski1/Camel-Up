#include <Rcpp.h>
#include <string>
#include "Player.h"

using namespace Rcpp;

//' @name Player
//' @title Encapsulates a double
//' @description Type the name of the class to see its
//' @field new Constructor
//' @field mult Multiply by another Double object \itemize{
//' \item Paramter: other - The other Double object
//' \item Returns: product of the values
//' }
//' @export
//'
Player::Player(std::string n){
  name = n;
  coins = 0;
}

void Player::addCoins(int n){
  coins += n;
}

std::string Player::getName(){
  return name;
}

int Player::getCoins(){
  return coins;
}



// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Player)
  RCPP_MODULE(player_cpp) {

    class_<Player>("Player")
    .constructor<std::string>()
    .method("addCoins", &Player::addCoins)
    .method("getName", &Player::getName)
    .method("getCoins", &Player::getCoins)
    ;
  }
