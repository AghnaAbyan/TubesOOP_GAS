#include "../../Game.hpp"
#include "../Kartu/Kartu.hpp"
#include "../../array.hpp"
using namespace std;
#ifndef KOMBO_HPP
#define KOMBO_HPP


class Kombo: public Kartu{
    private:
        vector<AngkaCard> temp;
        vector<AngkaCard> card;
    public:
        Kombo(vector<AngkaCard>, vector<AngkaCard>);
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