#include "../../Game.hpp"
#include "../Kartu/Kartu.hpp"
using namespace std;
#ifndef KOMBO_HPP
#define KOMBO_HPP


class Kombo: public Kartu{
    private:
        vector<AngkaCard> temp;
        vector<AngkaCard> card;
    public:
        Kombo(vector<AngkaCard>, vector<AngkaCard>);
        double highCard(double);
        double pair(double);
        double twoPair(double);
        double threeOfAKind(double);
        double straight(double);
        double flush(double);
        double fullHouse(double);
        double fourOfAKind(double);
        double straightFlush(double);
        double value(double);
};

#endif