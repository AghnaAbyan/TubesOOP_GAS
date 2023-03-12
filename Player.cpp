#include "Game.hpp"

Player::Player(int _id){
    id = _id;
    poin = 0;
}

int Player::playerSum(){
    return Player::playerCount;
}

void Player::newGame(){
    newCard();
}


void Player::newRound(){
    if (InventoryHolder::round == 2){
        // tambahin kartu ability
    }
}


bool Player::operator==(const Player &p){
    if (id == p.id){
        return true;
    }
    else{
        return false;
    }
}

void Player::newCard(){
    if (InventoryHolder::round == 1){
        // tambahin 2 kartu awal
    }
}

