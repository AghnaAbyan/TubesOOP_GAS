#ifndef COMMANDS_HPP
#define COMMANDS_HPP

// #include "../../Game.hpp"
// #include "../Kartu/Kartu.hpp"
// #include "../Player/Player.hpp"
#include "Command.hpp"
#include "../Game/Game.hpp"
#include <algorithm>
#include <string>

using namespace std;

class Next: public Commands{
    public:
        Next(Game& _game): Commands(_game){
            player = game.getCurrentPlayer();
            players = game.getPlayers();
        }
        void action(){}
};

// Commands* Game::getCommand(string commandType, Game& _game){
//     if(commandType == "NEXT"){
//         return new Next(_game);
//     }
// }

// class Reroll: public Commands{
//     public:
//         Reroll(Game& _game): Commands(_game){}
//         void action(){
//             // /* Buang 2 kartu dari tangan */
//             // /* Ambil 2 kartu baru dari deck*/
//             // cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
//             // cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

//             // AngkaCard c1 = game.takeCard();
//             // AngkaCard c2 = game.takeCard();
//             // (*player).clearCards();
//             // *player + c1 + c2;


//             // cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
//             // cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;
//         }
// };

// class Multiply: public Commands{
//     protected:
//         int multiplier;
//     public:
//         Multiply(Game& _game, int _multiplier): Commands(_game), multiplier(_multiplier){}
//         void action(){
//             player->setPoin(player->getPoin()*multiplier);

//             string prompt;
//             if(multiplier==2) prompt = "DOUBLE!";
//             else if(multiplier==4)prompt = "QUADRUPLE";

//             cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah naik  " << " menjadi " << player->getPoin() << "!" << endl;
//         }
// };

// class Double: public Multiply{
//     public:
//         Double(Game& _game): Multiply(_game, 2){}
// };

// class Quadruple: public Multiply{
//     public:
//         Quadruple(Game& _game): Multiply(_game, 4){}
// };

// class Divide: public Commands{
//     protected:
//         int divisor;
//     public:
//         Divide(Game& _game, int _divisor): Commands(_game), divisor(_divisor){}
//         void action(){
//             if(player->getPoin() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

//             player->setPoin(player->getPoin()/divisor);
//             string prompt;
//             if(divisor==2) prompt = "HALF!";
//             else if(divisor==4)prompt = "QUARTER";

//             cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah turun  " << " menjadi " << player->getPoin() << "!" << endl;
//         }
// };

// class Half: public Divide{
//     public:
//         Half(Game& _game): Divide(_game, 2){}
// };

// class Quarter: public Divide{
//     public:
//         Quarter(Game& _game): Divide(_game, 4){}
// };

// class Reverse: public Commands{
//     public:
//         Reverse(Game& _game): Commands(_game){}
//         void action(){
//             cout << player->getId() << "melakukan REVERSE!" << endl;
//             cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
//             game.changeDirection();
//             cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
//         }
// };

// class Swap: public Commands{
//     public:
//         Swap(Game& _game): Commands(_game){}
//         void action(){
//             // cout << player->getId() << "melakukan SWAP!" << endl;

//             // players.erase(find(players.begin(), players.end(), player));
//             // cout<<"Pilih pemain yang mau kamu tukar kartunya:"<<endl;
//             // Player* playerA = chooseOtherPlayer();
//             // players.erase(find(players.begin(), players.end(), playerA));
//             // cout<<"Pilih pemain lain yang mau kamu tukar kartunya:"<<endl;
//             // Player* playerB = chooseOtherPlayer();
//             // players.erase(find(players.begin(), players.end(), playerB));

//             // AngkaCard& c1 = chooseCard(playerA);
//             // AngkaCard& c2 = chooseCard(playerB);

//             // *playerA + c2;
//             // *playerB + c1;
//         }
//         AngkaCard& chooseCard(Player* target){
//             cout<<"Pilih kartu kanan/kiri milik pemain_"<<target->getId()<<endl;
//             cout<<"1. Kanan"<<endl<<"2. Kiri"<<endl;
//             int temp;
//             cin>>temp;

//             return target->takeCard(temp);
//         }
// };

// class Switch: public Commands{
//     public:
//         Switch(Game& _game): Commands(_game){}
//         void action(){
//             // cout<<"<pemain_"<<player->getId()<<"> melakukan SWITCH!"<<endl;
//             // cout<<"Kartumu sekarang adalah:"<<endl;
//             // player->displayCards();

//             // cout<<"Pilih pemain yang mau kamu tukar kartunya"<<endl;
//             // players.erase(find(players.begin(), players.end(), player));
//             // Player* other = chooseOtherPlayer();

//             // // AngkaCard c1, c2, c3, c4;
//             // AngkaCard c1 = other->takeCard();
//             // AngkaCard c2 = other->takeCard();
//             // AngkaCard c3 = player->takeCard();
//             // AngkaCard c4 = player->takeCard();

//             // *player + c1 + c2;
//             // *other + c3 + c4;

//             // cout<<"Kedua kartumu berhasil ditukar dengan kartu milik <pemain_"<<other->getId()<<">!"<<endl;
//             // cout<<"Kartumu sekarang adalah:"<<endl;
//             // player->displayCards();
//         }
// };

// class Abilityless: public Commands{
//     public:
//         Abilityless(Game& _game): Commands(_game){}
//         void action(){
//             cout<<"<pemain_"<<player->getId()<<"> melakukan ABILITYLESS!"<<endl;
//             cout<<"Pilih pemain yang abilitynya mau dimatikan"<<endl;
//             Player* other = chooseOtherPlayer();
//             map<string, Commands*> actions = other->getPlayerActions();

//             string keys[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH"};
//             for(string key : keys){
//                 if(actions.find(key) != actions.end()){
//                     actions[key]->disable();
//                 }
//             }
//         }
// };

#endif