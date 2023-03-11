#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
using namespace std;

class InventoryHolder{
    protected:
        int gameDirection;
        int round;
        int poinTotal;

    public:
        template <class T>
        T Winner(T[]);
};

class Player: public InventoryHolder{
    protected:
        int id;
        int poin;
        /* Kartu card (pakai array jumlahnya 2)*/
    public:
        /* void Kartu[] operator+(const Kartu&) */
        /* void Kartu[] operator-(const Kartu&) */
};

class TableCard: public InventoryHolder{
    protected:
        /* Kartu mainDeck (pakai vector)*/ 
    public:
        /* void Kartu[] operator+(const Kartu&) */
};

class Ability: public Player{
    private:
        /* Kartu infoCardAbility */
    public:
        virtual void reroll() = 0;
        virtual void quadruple() = 0;
        virtual void quarter() = 0;
        virtual void reverse() = 0;
        virtual void swapCard() = 0;
        virtual void switchCard() = 0;
        virtual void abilityless() = 0;
};

class PlayerAction: public Ability{
    private:
        
    public:
        void next();
        void reroll();
        void doublePoin();
        void quadruple();
        void half();
        void quarter();
        void reverse();
        void swapCard();
        void switchCard();
        void abilityless();
};

class Kombo: public Player, TableCard{
    public:
        bool highCard();
        bool pair();
        bool twoPair();
        bool threeOfAKind();
        bool straight();
        bool flush();
        bool fullHouse();
        bool fourOfAKind();
        bool straightFlush();
        int value();
        /* bool Kartu operator<(Kartu) */
        /* bool Kartu operator>(Kartu) */
        /* bool Kartu operator==(Kartu) */
};

#endif