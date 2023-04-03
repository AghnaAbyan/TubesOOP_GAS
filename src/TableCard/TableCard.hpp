#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include <vector>

using namespace std;

class TableCard: public InventoryHolder{
    private:
        // vector<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        // vector<AngkaCard> tumpukan;

    public:
        TableCard();
        void setMainDeck(vector<AngkaCard> cards);
        AngkaCard infoTableCard(int);
        AngkaCard takeCard();
        // AngkaCard Randomize();
        // void resetNewGame();
        // void displayCards(){}
        void showInRound(int);
        // vector<AngkaCard> TableCard::getMainDeck();
        // vector<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

#endif