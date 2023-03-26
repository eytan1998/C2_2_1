#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{
    std::string name;
public:
    Player(std::string name);
    int stacksize();
    int cardesTaken();
};
#endif