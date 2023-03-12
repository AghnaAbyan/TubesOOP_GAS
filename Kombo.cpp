#include "Kombo.hpp"
#include <math.h>


int Kombo::highCard(){
    float hasil = card.get(0).valuecard()+card.get(1).valuecard();
    return hasil;
}
//Pair adalah keadaan ketika kedua kartu sama
bool Kombo::pair(){ 
    return card.get(0).getAngka() == card.get(1).getAngka();
}
//Two pair kalo misal di table ada 2 nilai yang sama dan 2 lagi di pemain
bool Kombo::twoPair(){
    bool valid = false;
    if(pair){
        for(int i = 0; i < ncard ; i++){
            for(int j = 0; j < ncard ; j++){
                if(i != j){
                    if((mainDeck.get(i).getAngka() == mainDeck.get(j).getAngka()) && (mainDeck.get(i).getAngka() != card.get(0).getAngka())){
                        valid = true;
                    }
                }
            }
        }
    }
    return valid;
}
//Three of kind kalo ada 3 yang sama 2 sama di pemain dan 1 ada di table, prioritas two pair terlebih dahulu        
bool Kombo::threeOfAKind(){
    int count = 0;
    int val = 0;
    if(pair){
        val = card.get(0).getAngka();
    }
    for(int i = 0; i < ncard ; i++){
        if(mainDeck.get(i).getAngka() == val){
            count++;
        }
    }
    if(count == 1){
        return true;
    }
    else{
        return false;
    }

}

bool Kombo::straight(){
    //Straight terbentuk apabila terdapat 5 kartu yang berurutan dalam hand milik pemain. 
    //Jika terdapat >1 pemain yang memiliki kombinasi straight, maka urutan akan dilihat 
    //dari angka terbesar yang membentuk straight tersebut.'''
    //Maaf ini gimana ya di tangan pemain kan ada 2 card
    //Aku asumsiin digabung sama yang table card
    int count = 0;
    if(card.get(0).getAngka()-card.get(1).getAngka() == 1){
        for(int i = 0; i < ncard; i++){
            for(int j = 0; j < 2 ; j++){
                if(abs(card.get(j).getAngka()-mainDeck.get(i).getAngka()) == 1){
                    count++;
                }
            }
        }
        if(count == 3){
            return true;
        }
        else{
            return false;
        }
    }
    else if(card.get(1).getAngka()-card.get(0).getAngka() == 1){
        for(int i = 0; i < ncard; i++){
            for(int j = 0; j < 2 ; j++){
                if(abs(card.get(j).getAngka()-mainDeck.get(i).getAngka()) == 1){
                    count++;
                }
            }
        }
        if(count == 3){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Kombo::flush(){
    //Flush terbentuk apabila terdapat 5 kartu dengan warna yang sama dalam hand milik pemain. 
    //Jika terdapat >1 pemain yang memiliki kombinasi flush, maka urutan akan dilihat dari angka 
    //terbesar yang membentuk flush tersebut.
    //Asumsi Sama membandingkan antara meja aja deh jadinya
    if(card.get(0).getWarna() == card.get(1).getWarna()){
        int count = 0;
        for(int i = 0; i < ncard; i++){
            if(mainDeck.get(i).getWarna() == card.get(0).getWarna())
            {
                count++;
            }
        }
        if(count == 3){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Kombo::fullHouse(){
    bool valid = false;
    if(threeOfAKind()){
        for(int i = 0; i < ncard ; i++){
            for(int j = 0; j < ncard ; j++){
                if(i != j){
                    if((mainDeck.get(i).getAngka() == mainDeck.get(j).getAngka()) && (mainDeck.get(i).getAngka() != card.get(0).getAngka())){
                        valid = true;
                    }
                }
            }
        }
    }
    return valid;
}
bool Kombo::fourOfAKind(){
    int count = 0;
    int val = 0;
    if(pair){
        val = card.get(0).getAngka();
    }
    for(int i = 0; i < ncard ; i++){
        if(mainDeck.get(i).getAngka() == val){
            count++;
        }
    }
    if(count == 2){
        return true;
    }
    else{
        return false;
    }
}
bool Kombo::straightFlush(){
    return flush() && straight();

}
float Kombo::value(){
    if(straightFlush()){
        return 9+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(fourOfAKind()){
        return 8+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(fullHouse()){
        return 7+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(flush()){
        return 6+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(straight()){
        return 5+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(threeOfAKind()){
        return 4+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(twoPair()){
        return 3+card.get(0).valuecard()+card.get(1).valuecard();
    }
    else if(pair()){
         return 3+card.get(0).valuecard()+card.get(1).valuecard();
    }
}
