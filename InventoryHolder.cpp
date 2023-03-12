#include "Game.hpp"

InventoryHolder::InventoryHolder(){
    gameDirection = 0;
    game = 0;
    round = 0;
    poinTotal = 0;
}

void InventoryHolder::newGame(){
    poinTotal = 0;
    round = 0;
    game++;
}

void InventoryHolder::newRound(){
    round++;
}

void InventoryHolder::changeDirection(){
    if(gameDirection == 0){
        gameDirection = 1;
    }
    else{
        gameDirection = 0;
    }
}