#ifndef KOMBO_HPP
#define KOMBO_HPP
#include <iostream>
#include "../../Game.hpp"
#include "../Kartu/Kartu.hpp"
#include "../../array.hpp"
using namespace std;

class Kombo: public Kartu{
    private:
        vector<AngkaCard> temp;
    public:
        Kombo(vector<AngkaCard>, vector<AngkaCard>);
        bool greater(AngkaCard, AngkaCard);
        double highCard();
        double pair();
        double twoPair();
        double threeOfAKind();
        double straight();
        double flush();
        double fullHouse();
        double fourOfAKind();
        double straightFlush();
        double value();
};

#endif