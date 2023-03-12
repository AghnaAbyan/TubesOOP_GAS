#include "Game.hpp"

TableCard::TableCard(){
    /* Isi main deck pake kartu */
}

const Kartu& TableCard::infoTableCard(int i){
    return mainDeck.get(i);
}