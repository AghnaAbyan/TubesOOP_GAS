#include "Kombo.hpp"
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
/*
Min List
1. High card: 0 + 1
2. Pair: 139 + 1
3. Two pair: 139*2 + 1
4. Three of kind: 139*3 + 1
5. Straight: 139*4 + 1
6. Flush: 139*5 + 1
7. Full House: 139*6 + 1
8. Four of kind: 139*7 + 1
9. Straight Flush: 139*8 + 1
10. Max value: 139*9

If for all players best card is table card (All players has same score),
resolve with gettin second best pick.
To implement add max value (Not yet implemented)
*/

Kombo::Kombo(vector<AngkaCard> _card, vector<AngkaCard> mainDeck){
    temp.clear();
    combination.clear();
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
AngkaCard Kombo::get(int i){
    return combination[i];
}


int Kombo::highCard(int limit){
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
int Kombo::pair(int limit){ 
    //sort first
    // temp.sortArray(false);
    for(int i = 0;i<temp.size()-1;i++){
        if(temp[i] == temp[i+1] && (temp[i].valuecard()+ 139)<limit){
            combination.push_back(temp[i]);
            combination.push_back(temp[i+1]);
            return 139 + temp[i].valuecard();
        }
    }
    return 0;
}



int Kombo::twoPair(int limit){
    //Mengembalikan true jika terdapat dua pasang pair pada hand
    //When get a pair, hold the pair and continue the loop until found second pair
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);

    for(int i = 0;i<temp.size() -3;i++){
        if(temp[i] == temp[i+1]){
            for(int j = i+2; j<temp.size()-1; j++){
                if(temp[j] == temp[j+1] && (temp[i].valuecard()+ 139*2)<limit){
                    combination.push_back(temp[i]);
                    combination.push_back(temp[i+1]);
                    combination.push_back(temp[j]);
                    combination.push_back(temp[j+1]);
                    return temp[i].valuecard() +139*2;
                }
            }
        }
    }

    return 0;
}
//Three of kind kalo ada 3 yang sama 2 sama di pemain dan 1 ada di table, prioritas two pair terlebih dahulu        
int Kombo::threeOfAKind(int limit){
    //3 consecutive check
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0;i<temp.size()-2;i++){
        if((temp[i] == temp[i+1]) && (temp[i+1] == temp[i+2]) && (temp[i].valuecard()+ 139*3)<limit){
            for(int k =0; k<3; k++){combination.push_back(temp[i+k]);}
            return temp[i].valuecard() + 139*3;
        }
    }
    return 0;
}

int Kombo::straight(int limit){//need fix
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
        combination.push_back(temp[i]);
        int j = i+1;
        bool exceed = false;
        while(j<temp.size() && !exceed){
            if(temp[j-1].getAngka() - temp[j].getAngka() >1){
                exceed = true;
            }
            if(temp[j-1].getAngka()-1 == temp[j].getAngka()){
                count++;
                combination.push_back(temp[j]);
            }
            j++;
        }
        if(count>=5 && ((temp[i].valuecard()+ 139*4)<limit)){
            return temp[i].valuecard() + 139*4;
        }else{combination.clear();}
        
       

    }
    
    return 0;
}
int Kombo::flush(int limit){
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
                combination.push_back(temp[j]);
            }
        }
        if(count>=5 && ((temp[i].valuecard()+ 139*5)<limit)){
            return temp[i].valuecard() + 139*5;
        }else{combination.clear();}
    }
    return 0;
}
int Kombo::fullHouse(int limit){
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i = 0;i<3;i++){
        if(temp[i] == temp[i+1] && !(temp[i+1] == temp[i+2])){
            //find three of kind
            for(int j = i+2 ; j<temp.size()-2; j++){
                if(temp[j] == temp[j+1] && temp[j+1] == temp[j+2] && ((temp[j].valuecard()+ 139*6)<limit)){
                    for(int k =0; k<3;k++){
                        combination.push_back(temp[j+k]);
                    }
                    for(int k =0; k<2; k++){
                        combination.push_back(temp[i+k]);
                    }
                    return temp[j].valuecard() + 139*6;
                }
            }
        }
        else if(temp[i] == temp[i+1] && temp[i+1] == temp[i+2]){
            //find pair
            for(int j = i+3 ; j<temp.size()-1; j++){
                if(temp[j] == temp[j+1] && ((temp[i].valuecard()+ 139*6)<limit)){
                    for(int k =0; k<3;k++){
                        combination.push_back(temp[i+k]);
                    }
                    for(int k =0; k<2; k++){
                        combination.push_back(temp[j+k]);
                    }
                    return temp[i].valuecard() + 139*6;;
                }
            }

        }
    }
    return 0;
}
int Kombo::fourOfAKind(int limit){
    //4 consecutive check
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    for(int i =0;i<temp.size()-3;i++){
        if((temp[i] == temp[i+1]) && (temp[i+1] == temp[i+2]) && (temp[i+2] == temp[i+3]) && ((temp[i].valuecard()+ 139*7)<limit)){
            for(int k =0; k<4;k++){
                combination.push_back(temp[i+k]);
            }
            return temp[i].valuecard()+139*7;
        }
    }
    return 0;
}
int Kombo::straightFlush(int limit){//need fix
    // Array<AngkaCard> temp(card);
    // temp.merge(mainDeck);
    //sort first
    // temp.sortArray(false);
    //8*139
    for(int i =0; i<3; i++){//there are only 3 possible straight in 7 cards
        int count = 1;
        combination.push_back(temp[i]);
        int j = i+1;
        bool exceed = false;
        while(j<temp.size() && !exceed){
            if(temp[j-1].getAngka() - temp[j].getAngka() >1){//check straight
                exceed = true;
            }
            if(temp[j-1].getAngka()-1 == temp[j].getAngka() && temp[j].sameColour(temp[j-1])){  
                count++;
                combination.push_back(temp[j]);
            }
            j++;
        }
        if(count>=5 && ((temp[i].valuecard()+ 139*8)<limit)){//count is same streak, not incrementing number
            return temp[i].valuecard() + 139*8;
        }else{
            combination.clear();
        }      

    }
    return 0;
}
int Kombo::value(int limit){
    //start with 139*9 + 1 limit
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
        //139 + card value
        //max 139*2
        cout<<"pair ";
         return pair(limit);
    }
    cout<<"highcard ";
    return highCard(limit);
}
