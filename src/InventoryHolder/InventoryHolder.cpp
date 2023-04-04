#include "InventoryHolder.hpp"

AngkaCard& InventoryHolder::takeCard(){
    AngkaCard& temp = cards.back();
    cards.pop_back();
    return temp;
}

AngkaCard& InventoryHolder::takeCard(int idx){
    AngkaCard& temp = cards[idx];
    cards.erase(cards.begin()+idx-1);
    return temp;
}

// AngkaCard& InventoryHolder::takeCard(int angka, string warna){
//     vector<AngkaCard>::iterator itr = cards.begin();
//     while(itr!=cards.end()){
//         if(itr->getAngka() == angka && itr->getWarna() == warna){
//             return *itr;
//         }
//         itr++;
//     }
//     throw "Kartu ga ketemu";
// }

void InventoryHolder::pushCard(const AngkaCard c){
    cards.push_back(c);
}

void InventoryHolder::clearCards(){
    cards.clear();
}

// InventoryHolder& InventoryHolder::operator=(const InventoryHolder& other){
//     cards = other.cards;

//     return *this;
// }

// InventoryHolder InventoryHolder::operator+(const AngkaCard c){
//     pushCard(c);
//     return *this;
// }

// InventoryHolder InventoryHolder::operator-(AngkaCard& c){
    // vector<AngkaCard>::iterator itr = cards.begin();
    // while(itr!=cards.end()){
    //     if(c == *itr){
    //         AngkaCard& temp = takeCard(itr-cards.begin());
    //         break;
    //     }
    //     itr++;
    // }
    // return *this;
// }

void InventoryHolder::readFromFile(string namaFile){
    ifstream file(namaFile);
    try{
        if(!file.is_open()){
        throw TestException();
        }
        
            vector<AngkaCard> a;
            AngkaCard b;
            string line;
            while(getline(file,line)){
                cout<<line<<endl;
                size_t pos = line.find(",");
                b.setAngka(stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
                b.setWarna(line);
                a.push_back(b);    
            }
            cards = a;
            file.close();
    }
    catch(exception& e){
        cout<<e.what()<<endl;

    }
}
