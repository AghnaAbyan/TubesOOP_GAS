#include "Kombo.hpp"
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
/*
Min List
1. High card: 0 + 0.01
2. Pair: 1.39 + 0.01
3. Two pair: 1.39*2 + 0.01
4. Three of kind: 1.39*3 + 0.01
5. Straight: 1.39*4 + 0.01
6. Flush: 1.39*5 + 0.01
7. Full House: 1.39*6 + 0.01
8. Four of kind: 1.39*7 + 0.01
9. Straight Flush: 1.39*8 + 0.01
10. Max value: 1.39*9

If for all players best card is table card (All players has same score),
resolve with gettin second best pick.
To implement add max value (Not yet implemented)
*/

Kombo::Kombo(vector<AngkaCard> _card, vector<AngkaCard> mainDeck){
    temp.clear();
    card = _card;
    for(int i=0; i<card.size(); i++){
        temp.push_back(card[i]);
    }
    for(int i=0; i<mainDeck.size(); i++){
        temp.push_back(mainDeck[i]);
    }
    
    //sort
    
    std::sort(temp.begin(), temp.end(), greater <>());//[](AngkaCard a, AngkaCard b) {
           // return (a>b);
           // }  );
    cout<<"[";
    for(int i = 0; i< temp.size();i++){
        
        cout<<temp[i].getAngka()<<temp[i].getWarna()<<",";
    }
    cout<<"]";
}



double Kombo::highCard(double limit){
    // vector<AngkaCard> temp;
    //sort first
    
    // temp.sortArray(false);
    for(int i =0; i<temp.size() ; i++){
        if(temp[i].valuecard()<limit){
            return temp[i].valuecard();
        }
    }
    return 0;
}

//Pair adalah keadaan ketika kedua kartu sama
double Kombo::pair(double limit){ 
    //sort first
    // temp.sortArray(false);
    for(int i = 0;i<temp.size()-1;i++){
        if(temp[i] == temp[i+1] && (temp[i].valuecard()+ 1.39)<limit){
            return 1.39 + temp[i].valuecard();
        }
    }
    return 0;
}



double Kombo::twoPair(double limit){
    //Mengembalikan true jika terdapat dua pasang pair pada hand
    //When get a pair, hold the pair and continue the loop until found second pair
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);

    for(int i = 0;i<temp.size() -3;i++){
        if(temp[i] == temp[i+1]){
            for(int j = i+2; j<temp.size()-1; j++){
                if(temp[j] == temp[j+1] && (temp[i].valuecard()+ 1.39*2)<limit){
                    return temp[i].valuecard() +1.39*2;
                }
            }
        }
    }

    return 0;
}
//Three of kind kalo ada 3 yang sama 2 sama di pemain dan 1 ada di table, prioritas two pair terlebih dahulu        
double Kombo::threeOfAKind(double limit){
    //3 consecutive check
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0;i<temp.size()-2;i++){
        if((temp[i] == temp[i+1]) && (temp[i+1] == temp[i+2]) && (temp[i].valuecard()+ 1.39*3)<limit){
            return temp[i].valuecard() + 1.39*3;
        }
    }
    return 0;
}

double Kombo::straight(double limit){//need fix
    //Straight terbentuk apabila terdapat 5 kartu yang berurutan dalam hand milik pemain. 
    //Jika terdapat >1 pemain yang memiliki kombinasi straight, maka urutan akan dilihat 
    //dari angka terbesar yang membentuk straight tersebut.'''
    //Maaf ini gimana ya di tangan pemain kan ada 2 card
    //Aku asumsiin digabung sama yang table card
    //5 consecutive check
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0; i<3; i++){//there are only 3 possible straight in 7 cards
        int count = 1;
        int j = i+1;
        bool exceed = false;
        while(j<temp.size() && !exceed){
            if(temp[j].getAngka() - temp[j-1].getAngka() >1){
                exceed = true;
            }
            if(temp[j-1].getAngka()-1 == temp[j].getAngka()){
                count++;
            }
            j++;
        }
        if(count>=5 && ((temp[i].valuecard()+ 1.39*4)<limit)){
            return temp[i].valuecard() + 1.39*4;
        }
        
       

    }

    return 0;
}
double Kombo::flush(double limit){
    //Flush terbentuk apabila terdapat 5 kartu dengan warna yang sama dalam hand milik pemain. 
    //terbesar yang membentuk flush tersebut.
    //Asumsi Sama membandingkan antara meja aja deh jadinya
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0; i<3; i++){
        int count = 1;
        for(int j = i+1; j<temp.size(); j++){
            if(temp[i].sameColour(temp[j])){
                count++;
            }
        }
        if(count>=5 && ((temp[i].valuecard()+ 1.39*5)<limit)){
            return temp[i].valuecard() + 1.39*5;
        }
    }
    return 0;
}
double Kombo::fullHouse(double limit){
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i = 0;i<3;i++){
        if(temp[i] == temp[i+1] && !(temp[i+1] == temp[i+2])){
            //find three of kind
            for(int j = i+2 ; j<temp.size()-2; j++){
                if(temp[j] == temp[j+1] && temp[j+1] == temp[j+2] && ((temp[j].valuecard()+ 1.39*6)<limit)){
                    return temp[j].valuecard() + 1.39*6;
                }
            }
        }
        else if(temp[i] == temp[i+1] && temp[i+1] == temp[i+2]){
            //find pair
            for(int j = i+3 ; j<temp.size()-1; j++){
                if(temp[j] == temp[j+1] && ((temp[i].valuecard()+ 1.39*6)<limit)){
                    return temp[i].valuecard() + 1.39*6;;
                }
            }

        }
    }
    return 0;
}
double Kombo::fourOfAKind(double limit){
    //4 consecutive check
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0;i<temp.size()-3;i++){
        if((temp[i] == temp[i+1]) && (temp[i+1] == temp[i+2]) && (temp[i+2] == temp[i+3]) && ((temp[i].valuecard()+ 1.39*7)<limit)){
            return temp[i].valuecard()+1.39*7;
        }
    }
    return 0;
}
double Kombo::straightFlush(double limit){//need fix
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    //8*1.39
    for(int i =0; i<3; i++){//there are only 3 possible straight in 7 cards
        int count = 1;
        int j = i+1;
        bool exceed = false;
        while(j<temp.size() && !exceed){
            if(temp[j].getAngka() - temp[j-1].getAngka() >1){//check straight
                exceed = true;
            }
            if(temp[j-1].getAngka()-1 == temp[j].getAngka() && temp[j].sameColour(temp[j-1])){  
                count++;
            }
            j++;
        }
        if(count>=5 && ((temp[i].valuecard()+ 1.39*8)<limit)){
            return temp[i].valuecard() + 1.39*8;
        }      

    }
    return 0;
}
double Kombo::value(double limit){
    //start with 1.39*9 + 0.01 limit
    if(straightFlush(limit) > 0){
        //
        cout<<"straightFlush ";
        return straightFlush(limit);
    }
    if(fourOfAKind(limit) > 0){
        //
        cout<<"four ";
        return fourOfAKind(limit);
    }
    if(fullHouse(limit) >0){
        //
        cout<<"full ";
        return fullHouse(limit);
    }
    if(flush(limit) >0){
        //
        cout<< "flush ";
        return flush(limit);
    }
    if(straight(limit) > 0){
        //
        cout<<"straight ";
        return straight(limit);
    }
    if(threeOfAKind(limit) > 0){
        //
        cout<< "three ";
        return threeOfAKind(limit);
    }
    if(twoPair(limit) > 0){
        //two pair calculation formula
        //2.78 + 
        cout<<"two ";
        return twoPair(limit);
    }
    if(pair(limit) > 0){
        //pair calculation formula
        //1.39 + card value
        //max 1.39*2
        cout<<"pair ";
         return pair(limit);
    }
    cout<<"highcard ";
    return highCard(limit);
}
