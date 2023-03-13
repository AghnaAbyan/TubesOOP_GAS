#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Player::Player(int _id){
    id = _id;
    poin = 0;
    Array<AngkaCard> *buff = new Array<AngkaCard>();
    card = *buff;
}

int Player::playerSum(){
    return Player::playerCount;
}

void Player::newGame(){
    newCard();
}


void Player::newRound(Player A, Player B, Player C, Player D, Player E, Player F, Player G){
    if (InventoryHolder::round == 2){
        Array<AbilityCard> L; 
        AbilityCard a(1,"Reverse");
        AbilityCard b(2, "Re-Roll");
        AbilityCard c(3, "Quarter");
        AbilityCard d(4, "Reverse Direction");
        AbilityCard e(5, "Swap Card");
        AbilityCard f(6, "Switch");
        AbilityCard g(7, "Abilityless");

        L.addfirst(a);
        L.addfirst(b);
        L.addfirst(c);
        L.addfirst(d);
        L.addfirst(e);
        L.addfirst(f);
        L.addfirst(g);

        int M = rand()%6;
        A.infoCardAbility = L.get(M);
        L.operator-(L.get(M));
        int M = rand()%5;

        B.infoCardAbility = L.get(M);
        L.operator-(L.get(M));
        int M = rand()%4;

        C.infoCardAbility = L.get(M);
        L.operator-(L.get(M));

        int M = rand()%3;
        D.infoCardAbility = L.get(M);
        L.operator-(L.get(M));

        int M = rand()%2;
        E.infoCardAbility = L.get(M);
        L.operator-(L.get(M));

        int M = rand()%1;
        F.infoCardAbility = L.get(M);
        L.operator-(L.get(M));

        int M = 0;
        G.infoCardAbility = L.get(M);
        L.operator-(L.get(M));
    }
}

/*void Player::newRoundFile(Player A, Player B, Player C, Player D, Player E, Player F, Player G){
    ifstream file("namafile.txt");
    if(file.is_open()){
        Array<AbilityCard> a;
        AbilityCard b;
        string line;
        while(getline(file,line)){
            size_t pos = line.find(",");
            b.setAbility(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
            b.SetNamaAbility(line);
            a.addfirst(b);    
        }
        newRound(A,B,C,D,E,F,G);
    }
}*/


bool Player::operator==(const Player &p){
    if (id == p.id){
        return true;
    }
    else{
        return false;
    }
}

void Player::newCard(AngkaCard c1, AngkaCard c2){
    if (InventoryHolder::round == 1){
        card+c1;
        card+c2;
    }
}

int Player::getPoin(){
    return poin;
}




