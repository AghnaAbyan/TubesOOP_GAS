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
        Array<AngkaCard> card; /* Kartu card (pakai array jumlahnya 2)*/
        AbilityCard infoCardAbility;
        int ncard;
    public:
        Player(int);
        int playerSum();
        // void Player::newRoundFile(Player A, Player B, Player C, Player D, Player E, Player F, Player G);
        bool operator==(const Player&);
        void newCard(AngkaCard, AngkaCard);
        int getPoin();
        void display();
        void setAbility(AbilityCard);

        /* PlayerAction */
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

class TableCard: public InventoryHolder, AngkaCard{
    protected:
        Array<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        Array<AngkaCard> tumpukan;

    public:
        TableCard();
        const AngkaCard& infoTableCard(int);
        AngkaCard takeCard();
        AngkaCard Randomize();
        Array<AngkaCard> readFileTumpukan(string namaFile);
        Array<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

// class Ability: public Player{
//     private:
        
//     public:
//         virtual void reroll() = 0;
//         virtual void quadruple() = 0;
//         virtual void quarter() = 0;
//         virtual void reverse() = 0;
//         virtual void swapCard() = 0;
//         virtual void switchCard() = 0;
//         virtual void abilityless() = 0;
// };

// class PlayerAction: public Ability{
//     private:
//         AbilityCard infoCardAbility; /* Kartu infoCardAbility */
//     public:
//         void next();
//         void reroll();
//         void doublePoin();
//         void quadruple();
//         void half();
//         void quarter();
//         void reverse();
//         void swapCard();
//         void switchCard();
//         void abilityless();
        
// };

class Game: public InventoryHolder{
    private:
        Array<Player> players;
        TableCard table;
        int currentPlayerId;

    public:
        Game();
        void newRound();
        void newGame();
        void showPoin();
        void commandParser(int, string);
        void start();
        void showUrutan();
};

#endif