#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.hpp"
#include "exception.hpp"
#include <ctime>

TableCard::TableCard(){}
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
void Game::randomTableDeck(){
    this->clearCards();
    /* Isi tumpukan kartu */
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Merah");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Hijau");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Kuning");
        pushCard(c);
    }
    for(int i = 1; i <= 13; i++){
        AngkaCard c;
        c.setAngka(i);
        c.setWarna("Biru");
        pushCard(c);
    }
    randomizeDeck(cards,52);
    // for(int i = 0; i < tumpukan.size();i++){
    //     cout << tumpukan[i].getAngka()<<tumpukan[i].getWarna() << endl;
    // }

    vector<AngkaCard> tablecards;
    for(int i = 0; i<5; i++){
        tablecards.push_back(cards.back());
        cards.pop_back();
    }

    table.setMainDeck(cards);
}

void TableCard::setMainDeck(vector<AngkaCard> _cards){
    cards = _cards;
}

AngkaCard TableCard::infoTableCard(int i){
    return cards[i];
}

AngkaCard TableCard::takeCard(){
    AngkaCard c = tumpukan[tumpukan.size()-1];
    tumpukan.pop_back();
    return c;
}

//Merandom untuk dibagikan ke pemain
// AngkaCard TableCard::Randomize(){
//     int i = rand()%52;
//     AngkaCard val = tumpukan.get(i);
//     tumpukan.operator-(val);
//     return val;
// }

// void TableCard::readFileTumpukan(string namaFile){
    
//     ifstream file(namaFile);
//     try{
//         if(!file.is_open()){
//         throw TestException();
//         }
        
//             vector<AngkaCard> a;
//             AngkaCard b;
//             string line;
//             while(getline(file,line)){
//                 cout<<line<<endl;
//                 size_t pos = line.find(",");
//                 b.setAngka(stoi(line.substr(0, pos)));
//                 line.erase(0, pos + 1);
//                 b.setWarna(line);
//                 a.push_back(b);    
//             }
//             tumpukan = a;
            
//             setMainDeck();
        
//     }
//     catch(exception& e){
//         cout<<e.what()<<endl;

//     }
// }

void TableCard::resetNewGame(){
    mainDeck.clear();
    tumpukan.clear();
}

void TableCard::showInRound(int N){
    for(int i = 0; i < N; i++){
        cout << i+1 << ". " << infoTableCard(i).getAngka() << " " << infoTableCard(i).getWarna() << endl;
    }
}
    
vector<AngkaCard> TableCard::getMainDeck(){
    return mainDeck;
}