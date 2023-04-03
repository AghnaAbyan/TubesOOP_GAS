#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include "../Kartu/Kartu.hpp"
#include "../exception.hpp"
#include <vector>

using namespace std;

class InventoryHolder{
    protected:
        vector<AngkaCard> cards;

    public:
        // InventoryHolder();

        vector<AngkaCard> getCards() {return cards;}

        AngkaCard& takeCard();
        AngkaCard& takeCard(int);
        // AngkaCard& takeCard(int, string);
        void pushCard(const AngkaCard);
        void clearCards();
        virtual void readFromFile(string namaFile);

        virtual InventoryHolder& operator=(const InventoryHolder&);
        virtual InventoryHolder& operator+(const AngkaCard);
        virtual InventoryHolder& operator-(AngkaCard&);

        // virtual void displayCards();
};

#endif