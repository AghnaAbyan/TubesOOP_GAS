#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.hpp"
#include "exception.hpp"

TableCard::TableCard(){}


void TableCard::setMainDeck(vector<AngkaCard> _cards){
    cards = _cards;
}

AngkaCard TableCard::infoTableCard(int i){
    return cards[i];
}

// AngkaCard TableCard::takeCard(){
//     AngkaCard c = tumpukan[tumpukan.size()-1];
//     tumpukan.pop_back();
//     return c;
// }

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

// void TableCard::resetNewGame(){
//     mainDeck.clear();
//     tumpukan.clear();
// }

void TableCard::showInRound(int N){
    for(int i = 0; i < N; i++){
        cout << i+1 << ". " << infoTableCard(i).getAngka() << " " << infoTableCard(i).getWarna() << endl;
    }
}
    
// vector<AngkaCard> TableCard::getMainDeck(){
//     return mainDeck;
// }