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
#include <algorithm>
// #include "array.hpp"
// #include "src/Commands/Commands.hpp"


using namespace std;

class InventoryHolder{
    protected:
        vector<AngkaCard> cards;

    public:
        // InventoryHolder();

        vector<AngkaCard> getCards() {return cards;}

        AngkaCard& takeCard();
        AngkaCard& takeCard(int);
        // AngkaCard& takeCard(int, string);
        void pushCard(const AngkaCard);
        void clearCards();
        virtual void readFromFile(string namaFile);

        virtual InventoryHolder& operator=(const InventoryHolder&);
        virtual InventoryHolder& operator+(const AngkaCard);
        virtual InventoryHolder& operator-(AngkaCard&);

        // virtual void displayCards();
};

class TableCard: public InventoryHolder{
    private:
        // vector<AngkaCard> mainDeck; /* Kartu mainDeck (pakai array, isinya bakal 5, dibuka per ronde)*/ 
        // vector<AngkaCard> tumpukan;

    public:
        TableCard();
        void setMainDeck(vector<AngkaCard> cards);
        AngkaCard infoTableCard(int);
        AngkaCard takeCard();
        // AngkaCard Randomize();
        // void resetNewGame();
        // void displayCards(){}
        void showInRound(int);
        // vector<AngkaCard> TableCard::getMainDeck();
        // vector<AngkaCard> getTumpukan();
        /* void Kartu[] operator+(const Kartu&) (kayaknya ini mending diimplementasi di kartu) */
};

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
        int getPoin();
        int getId();
        void addPoin(int);
        void setPoin(int);

        map<string, Commands*> getPlayerActions();
        // void assignCommand(string, Game&);
        // void insertPlayerAction(pair<string, Commands*>);

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

        vector<Player*> getPlayers(){return players;}
        Player* getCurrentPlayer() {return currentPlayer;}

        void randomTableDeck();

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

class Commands{ // ABC
    protected:
        Game& game;
        Player* player;
        vector<Player*> players;

        bool used;
        bool disabled;
    public:
        Commands(Game& _game): game(_game), player(_game.getCurrentPlayer()), players(game.getPlayers()), used(false), disabled(false){}
        ~Commands();
        Player* chooseOtherPlayer(){
            int i = 1;
            for(Player* j : players){
                cout<<i<<". <pemain_"<<j->getId()<<">"<<endl;
            }
            int temp;
            
            cin>>temp;
            if(temp<=0 || temp>players.size()) throw "Batas";

            return players[temp];
        }
        void use(){
            used = true;
        }
        void disable(){
            disabled = true;
        }

        bool isUsed(){return used;}
        bool isDisabled(){return disabled;}

        virtual void action();
};

class Next: public Commands{
    public:
        Next(Game& _game): Commands(_game){}
        void action(){}
};

class Reroll: public Commands{
    public:
        Reroll(Game& _game): Commands(_game){}
        void action(){
            // /* Buang 2 kartu dari tangan */
            // /* Ambil 2 kartu baru dari deck*/
            // cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
            // cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

            // AngkaCard c1 = game.takeCard();
            // AngkaCard c2 = game.takeCard();
            // (*player).clearCards();
            // *player + c1 + c2;


            // cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
            // cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;
        }
};

class Multiply: public Commands{
    protected:
        int multiplier;
    public:
        Multiply(Game& _game, int _multiplier): Commands(_game), multiplier(_multiplier){}
        void action(){
            player->setPoin(player->getPoin()*multiplier);

            string prompt;
            if(multiplier==2) prompt = "DOUBLE!";
            else if(multiplier==4)prompt = "QUADRUPLE";

            cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah naik  " << " menjadi " << player->getPoin() << "!" << endl;
        }
};

class Double: public Multiply{
    public:
        Double(Game& _game): Multiply(_game, 2){}
};

class Quadruple: public Multiply{
    public:
        Quadruple(Game& _game): Multiply(_game, 4){}
};

class Divide: public Commands{
    protected:
        int divisor;
    public:
        Divide(Game& _game, int _divisor): Commands(_game), divisor(_divisor){}
        void action(){
            if(player->getPoin() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

            player->setPoin(player->getPoin()/divisor);
            string prompt;
            if(divisor==2) prompt = "HALF!";
            else if(divisor==4)prompt = "QUARTER";

            cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah turun  " << " menjadi " << player->getPoin() << "!" << endl;
        }
};

class Half: public Divide{
    public:
        Half(Game& _game): Divide(_game, 2){}
};

class Quarter: public Divide{
    public:
        Quarter(Game& _game): Divide(_game, 4){}
};

class Reverse: public Commands{
    public:
        Reverse(Game& _game): Commands(_game){}
        void action(){
            cout << player->getId() << "melakukan REVERSE!" << endl;
            cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
            game.changeDirection();
            cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
        }
};

class Swap: public Commands{
    public:
        Swap(Game& _game): Commands(_game){}
        void action(){
            // cout << player->getId() << "melakukan SWAP!" << endl;

            // players.erase(find(players.begin(), players.end(), player));
            // cout<<"Pilih pemain yang mau kamu tukar kartunya:"<<endl;
            // Player* playerA = chooseOtherPlayer();
            // players.erase(find(players.begin(), players.end(), playerA));
            // cout<<"Pilih pemain lain yang mau kamu tukar kartunya:"<<endl;
            // Player* playerB = chooseOtherPlayer();
            // players.erase(find(players.begin(), players.end(), playerB));

            // AngkaCard& c1 = chooseCard(playerA);
            // AngkaCard& c2 = chooseCard(playerB);

            // *playerA + c2;
            // *playerB + c1;
        }
        AngkaCard& chooseCard(Player* target){
            cout<<"Pilih kartu kanan/kiri milik pemain_"<<target->getId()<<endl;
            cout<<"1. Kanan"<<endl<<"2. Kiri"<<endl;
            int temp;
            cin>>temp;

            return target->takeCard(temp);
        }
};

class Switch: public Commands{
    public:
        Switch(Game& _game): Commands(_game){}
        void action(){
            // cout<<"<pemain_"<<player->getId()<<"> melakukan SWITCH!"<<endl;
            // cout<<"Kartumu sekarang adalah:"<<endl;
            // player->displayCards();

            // cout<<"Pilih pemain yang mau kamu tukar kartunya"<<endl;
            // players.erase(find(players.begin(), players.end(), player));
            // Player* other = chooseOtherPlayer();

            // // AngkaCard c1, c2, c3, c4;
            // AngkaCard c1 = other->takeCard();
            // AngkaCard c2 = other->takeCard();
            // AngkaCard c3 = player->takeCard();
            // AngkaCard c4 = player->takeCard();

            // *player + c1 + c2;
            // *other + c3 + c4;

            // cout<<"Kedua kartumu berhasil ditukar dengan kartu milik <pemain_"<<other->getId()<<">!"<<endl;
            // cout<<"Kartumu sekarang adalah:"<<endl;
            // player->displayCards();
        }
};

class Abilityless: public Commands{
    public:
        Abilityless(Game& _game): Commands(_game){}
        void action(){
            cout<<"<pemain_"<<player->getId()<<"> melakukan ABILITYLESS!"<<endl;
            cout<<"Pilih pemain yang abilitynya mau dimatikan"<<endl;
            Player* other = chooseOtherPlayer();
            map<string, Commands*> actions = other->getPlayerActions();

            string keys[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH"};
            for(string key : keys){
                if(actions.find(key) != actions.end()){
                    actions[key]->disable();
                }
            }
        }
};

#endif