#include "Player.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player(int _id){
    id = _id;
    poin = 0;
    doneTurn = false;
    // vector<AngkaCard> buff;
    // cards = buff;
}

bool Player::operator==(const Player &p){
    if (id == p.id){
        return true;
    }
    else{
        return false;
    }
}

// Player& Player::operator=(const Player& p){
//     id = p.id;
//     poin = p.poin;
//     cards = p.cards;
//     playerActions
//     return *this;
// }

void Player::newCard(AngkaCard c1, AngkaCard c2){
    pushCard(c1);
    pushCard(c2);
}

long long Player::getPoin(){
    return poin;
}

int Player::getId(){
    return id;
}

void Player::addPoin(long long p){
    poin = poin + p;
}

void Player::setPoin(long long int p){
    poin = p;
}

string Player::getAbility(){
    return ability;
}

void Player::setAbility(string _ability){
    ability = _ability;
}

map<string, Commands*> Player::getPlayerActions(){
    return playerActions;
}

void Player::newTurn(){
    doneTurn = false;
}

void Player::endTurn(){
    doneTurn = true;
}

bool Player::hasDoneTurn(){
    return doneTurn;
}

void Player::action(string key){
    if(playerActions.find(key) == playerActions.end()) throw "Ga punya";
    if(playerActions[key]->isDisabled()) throw "kena disable euy";
    if(playerActions[key]->isUsed()) throw "udah kepake";

    playerActions[key]->action();
    
    string abilities[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};
    for(string ability : abilities){
        if(key == ability) playerActions[key]->use();
    }


}

void Player::displayCards(){
    cout << "Jumlah kartu: " << cards.size() << endl;
    for(int i = 0; i < cards.size(); i++){
        cout << i+1 << ". " << cards[i].getAngka() << " " << cards[i].getWarna() << endl;
    }
    // cout << "Done display card" << endl;
    }


