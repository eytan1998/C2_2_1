

#include "player.hpp"


Player::Player(std::string name){
    this->name = std::move(name);
}

int Player::stacksize() {
    return 0;
}

int Player::cardesTaken() {
    return 0;
}

