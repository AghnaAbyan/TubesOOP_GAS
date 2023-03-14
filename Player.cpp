#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player(int _id){
    id = _id;
    poin = 0;
    Array<AngkaCard> *buff = new Array<AngkaCard>();
    card = *buff;
}

int Player::playerSum(){
    return Player::playerCount;
}

// void Player::newRoundFile(Player A, Player B, Player C, Player D, Player E, Player F, Player G){
//     ifstream file("namafile.txt");
//     if(file.is_open()){
//         Array<AbilityCard> a;
//         AbilityCard b;
//         string line;
//         while(getline(file,line)){
//             size_t pos = line.find(",");
//             b.setAbility(stoi(line.substr(0, pos)));
//             line.erase(0, pos + 1);
//             b.SetNamaAbility(line);
//             a.addfirst(b);    
//         }
//         newRound(A,B,C,D,E,F,G);
//     }
// }


bool Player::operator==(const Player &p){
    if (id == p.id){
        return true;
    }
    else{
        return false;
    }
}

void Player::newCard(AngkaCard c1, AngkaCard c2){
    if (InventoryHolder::round == 1){
        card+c1;
        card+c2;
    }
}

int Player::getPoin(){
    return poin;
}

void Player::setAbility(AbilityCard a){
    infoCardAbility = a;
}

AbilityCard Player::getAbility(){
    return infoCardAbility;
}