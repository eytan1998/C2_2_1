
#ifndef GAME_H
#define GAME_H
#include "player.hpp"

class Game {

    Player *player1;
    Player *player2;
public:
    Game(Player &player1, Player &player2);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();
};

#endif
