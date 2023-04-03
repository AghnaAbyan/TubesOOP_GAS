#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <math.h>
#include "../Kartu/Kartu.hpp"
#include "../Kombo/Kombo.hpp"
#include <algorithm>
// #include "../Commands/Commands.hpp"
#include "../Player/Player.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../TableCard/TableCard.hpp"

using namespace std;

class Player;
class Next;

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

        vector<Player*> getPlayers();

        Player* getCurrentPlayer();
        Player* chooseOtherPlayer();

        Commands* getCommand(string comamndType, Game& game);

        void randomTableDeck();

        void assignCommand(string, Player*);

        void newRound();
        void showPoin();
        void commandParser(int, string);
        void start();
        void showUrutan();
        bool endGame();
        void showMain(int);
        void reverseEffect(int); // untuk di ronde itu saja
        // void displayCards(){}
        void setTable();
        // void testCom();
        void changeDirection();

        void action(string);
        void resetNewGame();

        // Game& operator=(const InventoryHolder&);
        void readFromFile(string namaFile);

};


#endif