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

void Player::newCard(AngkaCard c1, AngkaCard c2){
    card.push_back(c1);
    card.push_back(c2);
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

void Player::useAbility(){
    usedAbility = true;
}