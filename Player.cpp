#include "Game.hpp"

Player::Player(int _id){
    id = _id;
    poin = 0;
    Array<AngkaCard> *buff = new Array<AngkaCard>();
    card = *buff;
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

void Player::newCard(AngkaCard c1, AngkaCard c2){
    if (InventoryHolder::round == 1){
        card+c1;
        card+c2;
    }
}

int Player::getPoin(){
    return poin;
}