#include "Kartu.hpp"
#include <vector>
/***********/
/*AngkaCard*/
/***********/

AngkaCard::AngkaCard(){
    angka = 0;
    warna = "x";
}

AngkaCard::AngkaCard(int _angka, string _warna){
    angka = _angka;
    warna = _warna;
}

/*Get*/
int AngkaCard::getAngka() const{
    return this->angka;
}

string AngkaCard::getWarna() const{
    return this->warna;
}

bool AngkaCard::sameColour(const AngkaCard& other){
    return this->warna == other.getWarna();
}

int AngkaCard::valuecard() const{
    return this->priorityCardAngka()+this->priorityCardWarna();
}

/*Assignment Operator*/
AngkaCard& AngkaCard::operator=(const AngkaCard& other){
    angka = other.angka;
    warna = other.warna;
    return *this;
}

/*Comparison operator*/
/*Dibasikan valuecard sendiri*/
bool AngkaCard::operator==(const AngkaCard& other){
    return (this->angka == other.angka);
}
bool AngkaCard::operator<(const AngkaCard& other){
    return this->valuecard() < other.valuecard();
}
bool AngkaCard::operator>(const AngkaCard& other){
    return this->valuecard() > other.valuecard();
}
void AngkaCard::setAngka(int a){
    this->angka = a;
}
void AngkaCard::setWarna(string b){
    this->warna = b;
}

int AngkaCard::priorityCardWarna() const{
            if(this->warna == "Merah"){
                return 9;
            }
            else if(this->warna == "Kuning"){
                return 6;
            }
            else if(this->warna == "Biru"){
                return 3;
            }
            else{
                return 0;
            }
}
int AngkaCard::priorityCardAngka() const{
            return this->angka*10;
}
/*Output Operator*/
std::ostream& operator<<(ostream& os,const AngkaCard& kartu);
//Not yet, need to discuss output format first

/*Input Operator*/
/*  (For File)  */
std::ifstream& operator>>(ifstream& os, AngkaCard& inputan){
    os >> inputan.warna >> inputan.angka;
    return os;
}
/*************/
/*AbilityCard*/
/*************/

int AbilityCard::getIdAbility(){
    return this->idAbility;
}

string AbilityCard::getNamaAbility(){
    return this->namaAbility;
}


AbilityCard :: AbilityCard(int id, string name){
    this->idAbility = id; 
    this->namaAbility = name;
}

AbilityCard :: AbilityCard(){
    this->idAbility = 0;
    this->namaAbility = "none";
}

void AbilityCard::setAbility(int a){
    this->idAbility = a;
}

void AbilityCard::SetNamaAbility(string b){
    this->namaAbility = b;
}

