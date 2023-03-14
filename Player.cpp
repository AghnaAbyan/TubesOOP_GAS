#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player(int _id){
    id = _id;
    poin = 0;
    Array<AngkaCard> *buff = new Array<AngkaCard>();
    card = *buff;
    usedAbility = false;
}

int Player::playerSum(){
    return Player::playerCount;
}

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