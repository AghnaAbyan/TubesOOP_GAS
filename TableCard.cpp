#include "Game.hpp"

TableCard::TableCard(){
    Array<AngkaCard> *buff2 = new Array<AngkaCard>();
    tumpukan = *buff2;
    /* Isi tumpukan kartu */

    Array<AngkaCard> *buff1 = new Array<AngkaCard>();
    mainDeck = *buff1;
    /* Isi mainDeck dari tumpukan */
    for(int i = 0; i < 5; i++){
        mainDeck+tumpukan.operator--();
    }
}

const AngkaCard& TableCard::infoTableCard(int i){
    return mainDeck.get(i);
}

AngkaCard TableCard::takeCard(){
    AngkaCard buf = tumpukan.operator--();
    return buf;
}