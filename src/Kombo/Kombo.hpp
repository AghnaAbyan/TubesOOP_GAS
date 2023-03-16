#include "../../Game.hpp"
#include "../Kartu/Kartu.hpp"
using namespace std;
#ifndef KOMBO_HPP
#define KOMBO_HPP


class Kombo: public Kartu{
    private:
        vector<AngkaCard> temp;
        vector<AngkaCard> combination;
        vector<AngkaCard> card;
    public:
        Kombo(vector<AngkaCard>, vector<AngkaCard>);
        AngkaCard get(int);// return combination[i] 
        int highCard(int);
        int pair(int);
        int twoPair(int);
        int threeOfAKind(int);
        int straight(int);
        int flush(int);
        int fullHouse(int);
        int fourOfAKind(int);
        int straightFlush(int);
        int value(int);
};

#endif