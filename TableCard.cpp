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

#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
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

//Merandom untuk dibagikan ke pemain
AngkaCard TableCard::Randomize(){
    int i = rand()%52;
    AngkaCard val = tumpukan.get(i);
    tumpukan.operator-(val);
    return val;
}

Array<AngkaCard> TableCard::readFileTumpukan(string namaFile){
    ifstream file("namafile.txt");
    if(file.is_open()){
        Array<AngkaCard> a;
        AngkaCard b;
        string line;
        while(getline(file,line)){

            size_t pos = line.find(",");
            b.setAngka(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
            b.setWarna(line);
            a.addfirst(b);    
        }
        return a;
    }
}


