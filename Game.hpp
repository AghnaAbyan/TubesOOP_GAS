#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "src/Kartu/Kartu.hpp"
#include "src/Kombo/Kombo.hpp"
#include "array.hpp"

using namespace std;

class InventoryHolder{
    public:
        InventoryHolder();
};

class TableCard: public InventoryHolder{
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
        void resetNewGame();
        void showInRound(int);
        vector<AngkaCard> getMainDeck();
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
        int getId();
        void addPoin(int);
        void displayCard();
        void setAbility(AbilityCard);
        AbilityCard getAbility();
        void useAbility();
        void resetNewGame();
        vector<AngkaCard> getCard();

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
        int gameDirection; /* 0 maju, 1 mundur */
        int game;
        int round;
        int poinTotal;
        vector<Player> players;
        TableCard table;
        int firstPlayerId;
        vector<int> urutan;

    public:
        Game();
        AngkaCard takeCardTable();
        void newRound();
        void showPoin();
        void commandParser(int, string);
        void start();
        void showUrutan();
        bool endGame();
        void showMain(int);
        void reverseEffect(int); // untuk di ronde itu saja
        void setTable();
};

#endif