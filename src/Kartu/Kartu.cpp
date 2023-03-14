#include "Kartu.hpp"

/***********/
/*AngkaCard*/
/***********/

/*Get*/
int AngkaCard::getAngka() const{
    return this->angka;
}

string AngkaCard::getWarna() const{
    return this->warna;
}



double AngkaCard::valuecard() const{
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
    return (this->angka == other.angka) && (this->warna == other.warna);
}
bool AngkaCard::operator<(const AngkaCard& other){
    return this->valuecard() < other.valuecard();
}
bool AngkaCard::operator>(const AngkaCard& other){
    return this->valuecard() < other.valuecard();
}
void AngkaCard::setAngka(int a){
    this->angka = a;
}
void AngkaCard::setWarna(string b){
    this->warna = b;
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
template <typename T> void randomizeDeck(vector<T> &vec, int size){
    int index, secondIndex;
    T temp;
    srand((unsigned) time(NULL));
    for(index = 0; index<size; index++){
        secondIndex = rand() % size;
        temp = vec[index];
        vec[index] = vec[secondIndex];
        vec[secondIndex] = temp;
        
    }
    
}