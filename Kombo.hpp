#ifndef KOMBO_HPP
#define KOMBO_HPP
#include <iostream>
#include "Game.hpp"
#include "src/Kartu/Kartu.hpp"
using namespace std;

class Kombo: public Player, TableCard{
    public:
        double highCard();
        bool pair();
        bool twoPair();
        bool threeOfAKind();
        bool straight();
        bool flush();
        bool fullHouse();
        bool fourOfAKind();
        bool straightFlush();
        double value();
};

#endif