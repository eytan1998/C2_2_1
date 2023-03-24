#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
//using namespace ariel;


TEST_CASE("Testing player name initialize") {
    Player p1("Alice");
    Player p2("Bob");
    CHECK_EQ(p1.getName(), "Alice");
    CHECK_EQ(p2.getName(), "Bob");
}

TEST_CASE("Testing player initialize deck size") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(&p1, &p2);
    CHECK_EQ(p1.stacksize(), 26);
    CHECK_EQ(p2.stacksize(), 26);
}

TEST_CASE("Testing player deck size throughout game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(&p1, &p2);
    game.playTurn();
    CHECK_EQ(p1.stacksize(), 25);
    CHECK_EQ(p2.stacksize(), 25);
    for (int i = 0; i < 9; ++i) {
        game.playTurn();
    }
    CHECK_EQ(p1.stacksize(), 16);
    CHECK_EQ(p2.stacksize(), 16);
    game.playAll();
    //game end when both dont have cards in hand
    CHECK_EQ(p1.stacksize(), 0);
    CHECK_EQ(p2.stacksize(), 0);
}

TEST_CASE("Testing cards taken") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(&p1, &p2);
    //start with 0
    CHECK_EQ(p1.cardesTaken(), 0);
    CHECK_EQ(p2.cardesTaken(), 0);

    game.playAll();

    //end with between 0 to 52
    CHECK_GE(p1.cardesTaken(), 0);
    CHECK_LE(p1.cardesTaken(), 52);
    CHECK_GE(p2.cardesTaken(), 0);
    CHECK_LE(p2.cardesTaken(), 52);
}

TEST_CASE("Testing winner") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(&p1, &p2);
    //start with draw
    CHECK_EQ(game.whoWinner(), 0);
    //after game the available answers are 0,1,2
    game.playAll();
    CHECK_GE(game.whoWinner(), 0);
    CHECK_LE(game.whoWinner(), 2);
}

TEST_CASE("Testing one player with two games") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charly");

    //start both not in games so good
    CHECK_NOTHROW(Game game(&p1, &p2););

    //one or more in game throw exeption
    CHECK_THROWS_AS(Game game1(&p3, &p2), const std::invalid_argument&);
    CHECK_THROWS_AS(Game game2(&p1, &p3), const std::invalid_argument&);
    CHECK_THROWS_AS(Game game3(&p1, &p2), const std::invalid_argument&);

}

TEST_CASE("Testing one player with two games after game ended") {
    Player p4("Alice");
    Player p5("Bob");
    Game game1(&p4, &p5);
    game1.playAll();
    CHECK_NOTHROW(Game game(&p4, &p5););

}
