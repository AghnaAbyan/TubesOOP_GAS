#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "src\Kartu\Kartu.hpp"
#include "array.hpp"

using namespace std;

class InventoryHolder{
    public:
        InventoryHolder();
        virtual void newGame(); 
        virtual void newRound();
        void changeDirection();
};

class TableCard: public InventoryHolder, AngkaCard{
    private:
        vector<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        vector<AngkaCard> tumpukan;

    public:
        TableCard();
        void randomTableDeck();
        void setMainDeck();
        AngkaCard infoTableCard(int);
        AngkaCard takeCard();
        // AngkaCard Randomize();
        void readFileTumpukan(string namaFile);
        // vector<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

class Player: public InventoryHolder{
    // friend class Game;
    // friend class TableCard;
    private:
        int id;
        int poin;
        vector<AngkaCard> card; /* Kartu card (pakai array jumlahnya 2)*/
        AbilityCard infoCardAbility;
        bool usedAbility;
    public:
        Player(int);
        bool operator==(const Player&);
        Player& operator=(const Player&);
        void newCard(AngkaCard, AngkaCard);
        int getPoin();
        void display();
        void setAbility(AbilityCard);
        AbilityCard getAbility();
        void useAbility();

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

class Ability{
    public:
        void reroll();
        void quadruple();
        void quarter();
        void reverse();
        void swapCard();
        void switchCard();
        void abilityless();
};

class Game: public InventoryHolder{
    // friend class Player;
    // friend class TableCard;
    private:
        int gameDirection; /* 0 clockwise, 1 counter clockwise */
        int game;
        int round;
        int poinTotal;
        vector<Player> players;
        TableCard table;
        int currentPlayerId;

    public:
        Game();
        AngkaCard takeCardTable();
        void newRound();
        void newGame();
        void showPoin();
        void commandParser(int, string);
        void start();
        void showUrutan();
};

#endif