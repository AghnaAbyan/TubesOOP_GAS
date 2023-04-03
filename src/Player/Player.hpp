#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Game/Game.hpp"
// #include "../Commands/Commands.hpp"
#include <map>
#include <algorithm>

using namespace std;

class Commands;

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
        long long getPoin();
        int getId();
        void addPoin(long long);
        void setPoin(long long int);

        map<string, Commands*> getPlayerActions();
        void insertPlayerAction(pair<string, Commands*> action){
            playerActions.insert(action);
        }

        void action(string);

        void displayCards();

        // Player& operator=(const Player&);
        // Player& operator=(const InventoryHolder&);

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

#endif