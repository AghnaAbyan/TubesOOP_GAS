#include "Commands.hpp"
#include <iostream>

//Commands
Commands::~Commands(){
    // delete player;
}

// Next
void Next::action(){}

//Reroll
void Reroll::action(){
    /* Buang 2 kartu dari tangan */
    /* Ambil 2 kartu baru dari deck*/
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

    AngkaCard c1, c2;
    game = game - c1 - c2;
    (*player).clearCards();
    *player = *player + c1 + c2;


    cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
    cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;

    delete this;
}

//Multiply
void Multiply::action(){
    player->setPoin(player->getPoin()*multiplier);

    string prompt;
    if(multiplier==2) prompt = "DOUBLE!";
    else if(multiplier==4) prompt = "QUADRUPLE";

    cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah naik  " << " menjadi " << player->getPoin() << "!" << endl;
}

//Divide
void Divide::action(){
    if(player->getPoin() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

    player->setPoin(player->getPoin()/divisor);
    string prompt;
    if(divisor==2) prompt = "HALF!";
    else if(divisor==4) prompt = "QUARTER";

    cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah turun  " << " menjadi " << player->getPoin() << "!" << endl;
}

//Reverse
void Reverse::action(){
    cout << player->getId() << "melakukan REVERSE!" << endl;
    cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
    game.changeDirection();
    cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
}

//Swap
void Swap::action(){
    cout << player->getId() << "melakukan SWAP!" << endl;

    // TODO
}

//Switch
void Switch::action(){
    Player* other = chooseOtherPlayer();

    AngkaCard c1, c2, c3, c4;
    *other = *other - c1 - c2;
    *player = *player - c3 - c4;

    *player = *player + c1 + c2;
    *other = *other + c3 + c4;
}

//Abilityless
void Abilityless::action(){
    Player* other = chooseOtherPlayer();

    string keys[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH"};
    for(string key : keys){
        other->removePlayerAction(key);
    }
}