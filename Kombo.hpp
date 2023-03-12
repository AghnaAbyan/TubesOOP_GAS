#ifndef KOMBO_HPP
#define KOMBO_HPP
#include <iostream>
#include "Game.hpp"
#include "Kartu.hpp"
using namespace std;

class Kombo: public Player, TableCard{
    public:
        int highCard();
        bool pair();
        bool twoPair();
        bool threeOfAKind();
        bool straight();
        bool flush();
        bool fullHouse();
        bool fourOfAKind();
        bool straightFlush();
        float value();
};

#endif