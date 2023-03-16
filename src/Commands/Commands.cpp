#include "Commands.hpp"
#include <iostream>

//Commands
Commands::~Commands(){
    delete game;
    delete player;
}

// Next
Next::Next(){
    //Nothing
}
void Next::action(){}

//Reroll
Reroll::Reroll(Game* _game, Player* _player){
    Commands::game = _game;
    Commands::player = _player;
}
void Reroll::action(){
    /* Buang 2 kartu dari tangan */
    /* Ambil 2 kartu baru dari deck*/
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

    AngkaCard c1, c2;
    *game = *game - c1 - c2;
    (*player).clearCards();
    *player = *player + c1 + c2;


    cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
    cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;
}

//Multiply
Multiply::Multiply(Player* _player, int _multiplier): multiplier(_multiplier){
    Commands::player = _player;
}
void Multiply::action(){
    player->setPoin(player->getPoin()*multiplier);

    string prompt;
    if(multiplier==2) prompt = "DOUBLE!";
    else if(multiplier==4) prompt = "QUADRUPLE";

    cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah naik  " << " menjadi " << player->getPoin() << "!" << endl;
}

Double::Double(Player* _player): Multiply(_player, 2){}
Quadruple::Quadruple(Player* _player): Multiply(_player, 4){}

//Divide
Divide::Divide(Player* _player, int _divisor): divisor(_divisor){
    Commands::player = _player;
}
void Divide::action(){
    if(player->getPoin() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

    player->setPoin(player->getPoin()/divisor);
    string prompt;
    if(divisor==2) prompt = "HALF!";
    else if(divisor==4) prompt = "QUARTER";

    cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah turun  " << " menjadi " << player->getPoin() << "!" << endl;
}

Half::Half(Player* _player): Divide(_player, 2){}
Quarter::Quarter(Player* _player): Divide(_player, 4){}

//Reverse
Reverse::Reverse(Game* _game){
    Commands::game = _game;
}
void Reverse::action(){
    cout << player->getId() << "melakukan REVERSE!" << endl;
    cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
    game->changeDirection();
    cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
}

//Swap
Swap::Swap(){}
void Swap::action(){
    cout << player->getId() << "melakukan SWAP!" << endl;
}

//Switch
Switch::Switch(Player* _player){
    Commands::player = _player;
}
void Switch::action(){
    
}

//Abilityless
Abilityless::Abilityless(){}
void Abilityless::action(){

}