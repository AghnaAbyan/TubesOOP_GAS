#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include "src/Kartu/Kartu.hpp"
#include "src/Kombo/Kombo.hpp"
// #include "array.hpp"


using namespace std;

class InventoryHolder{
    protected:
        vector<AngkaCard> cards;

    public:
        // InventoryHolder();

        vector<AngkaCard> getCards() const {return cards;}

        AngkaCard& takeCard();
        AngkaCard& takeCard(int);
        // AngkaCard& takeCard(int, string);
        void pushCard(const AngkaCard);
        void clearCards();
        virtual void readFromFile(string namaFile);

        virtual InventoryHolder& operator=(const InventoryHolder&);
        virtual InventoryHolder& operator+(const AngkaCard);
        virtual InventoryHolder& operator-(AngkaCard&);

        virtual void displayCards() = 0;
};

class TableCard: public InventoryHolder{
    private:
        // vector<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        // vector<AngkaCard> tumpukan;

    public:
        TableCard();
        void setMainDeck(vector<AngkaCard> cards);
        AngkaCard infoTableCard(int);
        // AngkaCard takeCard();
        // AngkaCard Randomize();
        // void resetNewGame();
        void displayCards();
        void showInRound(int);
        // vector<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

class Player: public InventoryHolder{
    // friend class Game;
    // friend class TableCard;
    private:
        int id;
        long long int poin;
        // vector<AngkaCard> card; /* Kartu card (pakai array jumlahnya 2)*/
        map<string, Commands*> playerActions;
        // AbilityCard infoCardAbility;
        // bool usedAbility;
    public:
        Player(int);
        bool operator==(const Player&);
        void newCard(AngkaCard, AngkaCard);
        int getPoin();
        int getId();
        void addPoin(int);
        void setPoin(int);

        map<string, Commands*> getPlayerActions();
        void assignCommand(string, Game&);
        void insertPlayerAction(pair<string, Commands*>);

        void action(string);

        void displayCards();

        // Player& operator=(const Player&);
        Player& operator=(const InventoryHolder&);

        /* PlayerAction */
        // void next();
        // void reroll(TableCard*);
        // void doublePoin();
        // void quadruple();
        // void half();
        // void quarter();
        // void reverse();
        // void swapCard(Array<Player>*);
        // void switchCard(Array<Player>*);
        // void abilityless();
};

// class Ability{
//     public:
//         void reroll();
//         void quadruple();
//         void quarter();
//         void reverse();
//         void swapCard();
//         void switchCard();
//         void abilityless();
// };

class Game: public InventoryHolder{
    // friend class Player;
    // friend class TableCard;
    private:
        int gameDirection; /* 0 maju, 1 mundur */
        int game;
        int round;
        int poinTotal;
        vector<Player*> players;
        Player* currentPlayer;
        TableCard table;
        int firstPlayerId;
        vector<int> urutan;

    public:
        Game();
        AngkaCard takeCardTable();

        vector<Player*> getPlayers() const;
        Player* getCurrentPlayer();

        void randomTableDeck();

        void newRound();
        void showPoin();
        void commandParser(int, string);
        void start();
        void showUrutan();
        bool endGame();
        void showMain(int);
        void reverseEffect(int); // untuk di ronde itu saja
        void displayCards();
        void setTable();
        void testCom();
        void changeDirection();

        void action(string);

        Game& operator=(const InventoryHolder&);
        void readFromFile(string namaFile);

};

#endif