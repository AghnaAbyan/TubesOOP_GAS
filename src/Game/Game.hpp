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
// #include "../Commands/Command.hpp"
// #include "../Commands/Commands.hpp"
#include "../Player/Player.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../TableCard/TableCard.hpp"
#include "../Utils/Utils.hpp"

using namespace std;

class Player;
class Game;

class Commands{ // ABC
    protected:
        Game* game;
        Player* player;
        vector<Player*> players;

        bool used;
        bool disabled;
    public:
        Commands(Game* _game);
        ~Commands(){    
            players.clear();
        };

        void use(){
            used = true;
        }
        void disable(){
            disabled = true;
        }

        bool isUsed(){return used;}
        bool isDisabled(){return disabled;}

        virtual void action()=0;
};

class Next: public Commands{
    public:
        Next(Game* _game);
        void action(){}
};

class Reroll: public Commands{
    public:
        Reroll(Game* _game);
        void action();
};

class Multiply: public Commands{
    protected:
        long long multiplier;
    public:
        Multiply(Game* _game, long long _multiplier);
        void action();
};

class Double: public Multiply{
    public:
        Double(Game* _game);
};

class Quadruple: public Multiply{
    public:
        Quadruple(Game* _game);
};


class Divide: public Commands{
    protected:
        int divisor;
    public:
        Divide(Game* _game, int _divisor): Commands(_game), divisor(_divisor){}
        void action();
};

class Half: public Divide{
    public:
        Half(Game* _game);
};

class Quarter: public Divide{
    public:
        Quarter(Game* _game);
};

class Reverse: public Commands{
    public:
        Reverse(Game* _game);
        void action();
};


class Swap: public Commands{
    public:
        Swap(Game* _game);
        void action();
        AngkaCard& chooseCard(Player* target);
};

class Switch: public Commands{
    public:
        Switch(Game* _game);
        void action();
};


class Abilityless: public Commands{
    public:
        Abilityless(Game* _game);
        void action();
};


class Game: public InventoryHolder{
    // friend class Player;
    // friend class TableCard;
    private:
        int gameDirection; /* 1 maju, -1 mundur */
        int game;
        int round;
        int currentTurn;
        long long poinTotal;
        vector<Player*> players;
        Player* currentPlayer;
        TableCard table;
        int firstPlayerId;
        vector<int> urutan;
        // vector<string> abilities {"QUADRUPLE", "QUARTER", "REVERSE"};
        vector<string> abilities {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};

        void assignAbility(Player&);

    public:
        Game();
        AngkaCard takeCardTable();

        vector<Player*> getPlayers();

        Player* getCurrentPlayer();
        Player* chooseOtherPlayer();

        /**
         * @brief Mendapatkan currentTurn
         * 
         * @return int currentTurn
         */
        int getCurrentTurn(){
            return currentTurn;
        }
        /**
         * @brief Mengatur ulang currentTurn
         * 
         */
       void resetCurrentTurn(){
            currentTurn = 0;
       }
        /**
        * @brief Mendapatkan index pada vector<Player*> players untuk turn ke-i
        * 
        * @param i Turn saat ini
        * @return Index vector<Player*> players
        */
        int getIdxOfTurn(int i);

        /**
         * @brief Mendapatkan index dari turn selanjutnya
         * 
         * @return index turn selanjutnya
         */
        void nextTurn();
        /**
        * @brief Mendapatkan Player pada turn ke-i
        * 
        * @param i Turn saat ini
        * @return Player pada turn ke-i
        */
        Player* getPlayerAtTurn(int i);

        // Commands* getCommand(string comamndType, Game& game);

        long long getPoinTotal(){return poinTotal;}
        void setPoinTotal(long long _poinTotal){poinTotal = _poinTotal;}

        void randomTableDeck();

        void assignCommand(string, Player&);

        void newRound();
        void showPoin();

        /*
        * @brief Men-invoke action untuk command sesuai masukan pada Player saat ini
        * @param command Command yang ingin di-invoke
        */
        void commandParser(string command);
        void start();

        /**
         * @brief Menampilkan urutan turn dari start
         * 
         * @param start mulainya pencetakan
         */
        void showUrutan(int start);
        /**
         * @brief Menampilkan urutan turn dari 0
         * 
         */
        void showUrutan();
        bool endGame();
        void showMain(int);
        // void reverseEffect(int); // untuk di ronde itu saja
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