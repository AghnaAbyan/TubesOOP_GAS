#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Kartu.hpp"
#include "array.hpp"
using namespace std;

class InventoryHolder{
    protected:
        int gameDirection; /* 0 clockwise, 1 counter clockwise */
        int game;
        int round;
        int poinTotal;

    public:
        InventoryHolder();
        virtual void newGame(); 
        virtual void newRound();
        void changeDirection();
};

class Player: public InventoryHolder{
    private:
        static int playerCount;
    protected:
        int id;
        int poin;
        Array<Kartu> card; /* Kartu card (pakai array jumlahnya 2)*/
    public:
        Player(int);
        int playerSum();
        void newGame();
        void newRound();
        bool operator==(const Player&);
        void newCard();
};

class TableCard: public InventoryHolder{
    protected:
        Array<Kartu> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
    public:
        TableCard();
        const Kartu& infoTableCard(int);

        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

class Ability: public Player{
    private:
        Array<Kartu> infoCardAbility; /* Kartu infoCardAbility */
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
    private:
        string namaKombo;
        Array<Kartu> combo;

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
        /* bool operator==(Kombo) */ 
};



#endif