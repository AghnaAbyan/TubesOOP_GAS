#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include "src\Kartu\Kartu.hpp"
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

class TableCard: public InventoryHolder, AngkaCard{
    protected:
        Array<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        Array<AngkaCard> tumpukan;

    public:
        TableCard();
        AngkaCard infoTableCard(int);
        AngkaCard takeCard();
        AngkaCard Randomize();
        Array<AngkaCard> readFileTumpukan(string namaFile);
        Array<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

class Player: public InventoryHolder{
    friend class Game;
    friend class TableCard;
    private:
        static int playerCount;
    protected:
        int id;
        int poin;
        Array<AngkaCard> card; /* Kartu card (pakai array jumlahnya 2)*/
        AbilityCard infoCardAbility;
        int ncard;
        bool usedAbility;
    public:
        Player(int);
        int playerSum();
        // void Player::newRoundFile(Player A, Player B, Player C, Player D, Player E, Player F, Player G);
        bool operator==(const Player&);
        void newCard(AngkaCard, AngkaCard);
        int getPoin();
        void display();
        void setAbility(AbilityCard);
        AbilityCard getAbility();

        /* PlayerAction */
        void next();
        void reroll(TableCard*);
        void doublePoin();
        void quadruple();
        void half();
        void quarter();
        void reverse();
        void swapCard(Array<Player>*);
        void switchCard(Array<Player>*);
        void abilityless();
};

class Game: public InventoryHolder{
    friend class Player;
    friend class TableCard;
    protected:
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