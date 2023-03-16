#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player(int _id){
    id = _id;
    poin = 0;
    vector<AngkaCard> buff;
    card = buff;
    usedAbility = false;
}

bool Player::operator==(const Player &p){
    if (id == p.id){
        return true;
    }
    else{
        return false;
    }
}

Player& Player::operator=(const Player& p){
    id = p.id;
    poin = p.poin;
    card = p.card;
    infoCardAbility = p.infoCardAbility;
    usedAbility = p.usedAbility;
    return *this;
}

void Player::newCard(AngkaCard c1, AngkaCard c2){
    card.push_back(c1);
    card.push_back(c2);
}

int Player::getPoin(){
    return poin;
}

void Player::addPoin(int p){
    poin = poin + p;
}

void Player::displayCard(){
    cout << "Jumlah kartu: " << card.size() << endl;
    for(int i = 0; i < card.size(); i++){
        cout << i+1 << ". " << card[i].getAngka() << " " << card[i].getWarna() << endl;
    }
    cout << "Done display card" << endl;
    }

void Player::setAbility(AbilityCard a){
    infoCardAbility = a;
}

AbilityCard Player::getAbility(){
    return infoCardAbility;
}

void Player::useAbility(){
    usedAbility = true;
}

void Player::resetNewGame(){
    card.clear();
    usedAbility = false;
}

vector<AngkaCard> Player::getCard(){
    return card;
}