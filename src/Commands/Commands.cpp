#include "Commands.hpp"
#include <iostream>

//Commands
Commands::~Commands(){
    // delete player;
}

void Commands::use(){
    used = true;
}

void Commands::disable(){
    disabled = true;
}

Player* Commands::chooseOtherPlayer(){
    int i = 1;
    for(Player* j : players){
        cout<<i<<". <pemain_"<<j->getId()<<">"<<endl;
    }
    int temp;
    
    cin>>temp;
    if(temp<=0 || temp>players.size()) throw "Batas";

    return players[temp];
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
}

//Multiply
void Multiply::action(){
    player->setPoin(player->getPoin()*multiplier);

    string prompt;
    if(multiplier==2) prompt = "DOUBLE!";
    else if(multiplier==4)prompt = "QUADRUPLE";

    cout << player->getId() << "melakukan "<< prompt <<" Poin hadiah naik  " << " menjadi " << player->getPoin() << "!" << endl;
}

//Divide
void Divide::action(){
    if(player->getPoin() == 1) throw "Poin hadiah sudah bernilai 1. Poin hadiah tidak berubah. Giliran berlanjut!";

    player->setPoin(player->getPoin()/divisor);
    string prompt;
    if(divisor==2) prompt = "HALF!";
    else if(divisor==4)prompt = "QUARTER";

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

    players.erase(find(players.begin(), players.end(), player));
    cout<<"Pilih pemain yang mau kamu tukar kartunya:"<<endl;
    Player* playerA = chooseOtherPlayer();
    players.erase(find(players.begin(), players.end(), playerA));
    cout<<"Pilih pemain lain yang mau kamu tukar kartunya:"<<endl;
    Player* playerB = chooseOtherPlayer();
    players.erase(find(players.begin(), players.end(), playerB));

    AngkaCard& c1 = chooseCard(playerA);
    AngkaCard& c2 = chooseCard(playerB);

    *playerA = *playerA + c2;
    *playerB = *playerB + c1;
}

AngkaCard& Swap::chooseCard(Player* target){
    cout<<"Pilih kartu kanan/kiri milik pemain_"<<target->getId()<<endl;
    cout<<"1. Kanan"<<endl<<"2. Kiri"<<endl;
    int temp;
    cin>>temp;

    return target->takeCard(temp);
}

//Switch
void Switch::action(){
    cout<<"<pemain_"<<player->getId()<<"> melakukan SWITCH!"<<endl;
    cout<<"Kartumu sekarang adalah:"<<endl;
    player->displayCards();

    cout<<"Pilih pemain yang mau kamu tukar kartunya"<<endl;
    players.erase(find(players.begin(), players.end(), player));
    Player* other = chooseOtherPlayer();

    AngkaCard c1, c2, c3, c4;
    *other = *other - c1 - c2;
    *player = *player - c3 - c4;

    *player = *player + c1 + c2;
    *other = *other + c3 + c4;

    cout<<"Kedua kartumu berhasil ditukar dengan kartu milik <pemain_"<<other->getId()<<">!"<<endl;
    cout<<"Kartumu sekarang adalah:"<<endl;
    player->displayCards();
}

//Abilityless
void Abilityless::action(){
    cout<<"<pemain_"<<player->getId()<<"> melakukan ABILITYLESS!"<<endl;
    cout<<"Pilih pemain yang abilitynya mau dimatikan"<<endl;
    Player* other = chooseOtherPlayer();
    map<string, Commands*> actions = other->getPlayerActions();

    string keys[] = {"REROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH"};
    for(string key : keys){
        if(actions.find(key) != actions.end()){
            actions[key]->disable();
        }
    }
}