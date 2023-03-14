#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.hpp"
#include "src\Kartu\Kartu.cpp"

TableCard::TableCard(){
    vector<AngkaCard> buf;
    tumpukan = buf;
    /* Isi tumpukan kartu */
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Merah");
        tumpukan.push_back(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Hijau");
        tumpukan.push_back(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Kuning");
        tumpukan.push_back(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Biru");
        tumpukan.push_back(c);
    }
    randomizeDeck(tumpukan, 52);

    vector<AngkaCard> buf1;
    mainDeck = buf1;
    
    /* Isi mainDeck dari tumpukan */
    for(int i = 0; i < 5; i++){
        AngkaCard c = tumpukan[tumpukan.size()];
        tumpukan.pop_back();
        mainDeck.push_back(c);
    }
}

AngkaCard TableCard::infoTableCard(int i){
    return mainDeck.at(i);
}

AngkaCard TableCard::takeCard(){
    AngkaCard c = tumpukan[tumpukan.size()];
    tumpukan.pop_back();
    return ;
}

//Merandom untuk dibagikan ke pemain
// AngkaCard TableCard::Randomize(){
//     int i = rand()%52;
//     AngkaCard val = tumpukan.get(i);
//     tumpukan.operator-(val);
//     return val;
// }

vector<AngkaCard> TableCard::readFileTumpukan(string namaFile){
    ifstream file("namafile.txt");
    if(file.is_open()){
        vector<AngkaCard> a;
        AngkaCard b;
        string line;
        while(getline(file,line)){

            size_t pos = line.find(",");
            b.setAngka(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
            b.setWarna(line);
            a.push_back(b);    
        }
        return a;
    }
}

template <class T>
void randomizeDeck(vector<T> &vec, int size){
    int index, secondIndex;
    T temp;
    srand((unsigned) time(NULL));
    for(index = 0; index<size; index++){
        secondIndex = rand() % size;
        temp = vec[index];
        vec[index] = vec[secondIndex];
        vec[secondIndex] =  temp;
    }
}