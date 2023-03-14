#include "Kombo.hpp"
#include <math.h>
#include <algorithm>
#include "../../array.cpp"
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

double Kombo::highCard(){
    vector<Kartu> temp;
    for(int i=0; i<card.size(); i++){
        temp.push_back(card.get(i));
    }
    for(int i=0; i<mainDeck.size(); i++){
        temp.push_back(mainDeck.get(i));
    }
    //sort first
    temp.sortArray(false);
    return temp.get(0).valuecard();
}
//Pair adalah keadaan ketika kedua kartu sama
double Kombo::pair(){ 
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i = 0;i<temp.size()-1;i++){
        if(temp.get(i) == temp.get(i+1)){
            return 1.39 + temp.get(i).valuecard();
        }
    }
    return 0;
}



double Kombo::twoPair(){
    //Mengembalikan true jika terdapat dua pasang pair pada hand
    //When get a pair, hold the pair and continue the loop until found second pair
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);

    for(int i = 0;i<temp.size() -3;i++){
        if(temp.get(i) == temp.get(i+1)){
            for(int j = i+2; j<temp.size()-1; j++){
                if(temp.get(j) == temp.get(j+1)){
                    return temp.get(i).valuecard() +1.39*2;
                }
            }
        }
    }

    return 0;
}
//Three of kind kalo ada 3 yang sama 2 sama di pemain dan 1 ada di table, prioritas two pair terlebih dahulu        
double Kombo::threeOfAKind(){
    //3 consecutive check
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i =0;i<temp.size()-2;i++){
        if((temp.get(i) == temp.get(i+1)) && (temp.get(i+1) == temp.get(i+2))){
            return temp.get(i).valuecard() + .39*3;
        }
    }
    return 0;
}

double Kombo::straight(){
    //Straight terbentuk apabila terdapat 5 kartu yang berurutan dalam hand milik pemain. 
    //Jika terdapat >1 pemain yang memiliki kombinasi straight, maka urutan akan dilihat 
    //dari angka terbesar yang membentuk straight tersebut.'''
    //Maaf ini gimana ya di tangan pemain kan ada 2 card
    //Aku asumsiin digabung sama yang table card
    //5 consecutive check
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i =0; i<3; i++){//there are only 3 possible straight in 7 cards
        if((temp.get(i).getAngka() == temp.get(i+1).getAngka()+1) && (temp.get(i+1).getAngka() == temp.get(i+2).getAngka()+1)
       && (temp.get(i+2).getAngka() == temp.get(i+3).getAngka()+1)&& (temp.get(i+4).getAngka() == temp.get(i+5).getAngka()+1)){
        return temp.get(i).valuecard() + 1.39*4;
       }

    }

    return 0;
}
double Kombo::flush(){
    //Flush terbentuk apabila terdapat 5 kartu dengan warna yang sama dalam hand milik pemain. 
    //terbesar yang membentuk flush tersebut.
    //Asumsi Sama membandingkan antara meja aja deh jadinya
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i =0; i<3; i++){
        int count = 0;
        for(int j = i+1; j<temp.size(); j++){
            if(temp.get(i).sameColour(temp.get(j))){
                count++;
            }
        }
        if(count>=5){
            return temp.get(i).valuecard() + 1.39*5;
        }
    }
    return 0;
}
double Kombo::fullHouse(){
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i = 0;i<3;i++){
        if(temp.get(i) == temp.get(i+1) && !(temp.get(i+1) == temp.get(i+2))){
            //find three of kind
            for(int j = i+2 ; j<temp.size()-2; j++){
                if(temp.get(j) == temp.get(j+1) && temp.get(j+1) == temp.get(j+2)){
                    return temp.get(j).valuecard() + 1.39*6;
                }
            }
        }
        else if(temp.get(i) == temp.get(i+1) && temp.get(i+1) == temp.get(i+2)){
            //find pair
            for(int j = i+3 ; j<temp.size()-1; j++){
                if(temp.get(j) == temp.get(j+1)){
                    return temp.get(i).valuecard();
                }
            }

        }
    }
    return 0;
}
double Kombo::fourOfAKind(){
    //4 consecutive check
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i =0;i<temp.size()-3;i++){
        if((temp.get(i) == temp.get(i+1)) && (temp.get(i+1) == temp.get(i+2)) && (temp.get(i+2) == temp.get(i+3))){
            return temp.get(i).valuecard()+1.39*7;
        }
    }
    return 0;
}
double Kombo::straightFlush(){
    Array<AngkaCard> temp(card);
    temp.merge(mainDeck);
    //sort first
    temp.sortArray(false);
    for(int i =0; i<3; i++){//there are only 3 possible straight in 7 cards
        if((temp.get(i).getAngka() == temp.get(i+1).getAngka()+1) && (temp.get(i+1).getAngka() == temp.get(i+2).getAngka()+1)
        && (temp.get(i+2).getAngka() == temp.get(i+3).getAngka()+1)&& (temp.get(i+4).getAngka() == temp.get(i+5).getAngka()+1)){
            if(temp.get(i).sameColour(temp.get(i+1)) && temp.get(i+1).sameColour(temp.get(i+2)) && temp.get(i+2).sameColour(temp.get(i+3))
            && temp.get(i+3).sameColour(temp.get(i+4))){
                return temp.get(i).valuecard();
            }
        }

    }
    return 0;
}
double Kombo::value(){
    if(straightFlush()){
        //
        return 9+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(fourOfAKind()){
        //
        return 8+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(fullHouse()){
        //
        return 7+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(flush()){
        //
        return 6+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(straight()){
        //
        return 5+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(threeOfAKind()){
        //
        return 4+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(twoPair()){
        //two pair calculation formula
        //2.78 + 
        return card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(pair()){
        //pair calculation formula
        //1.39 + card value
        //max 1.39*2
         return 1.39+card.get(0).valuecard()+card.get(1).valuecard();
    }
    return highCard();
}