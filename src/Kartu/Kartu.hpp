#ifndef KARTU_H
#define KARTU_H
/* Nanti kalo kartu dah diimplementasiin ini hapus aja */
/* Ini buat implementasi sementara game aja ehehe */
/* Etapi kalo mau jadiin template hpp sabi */
// #include "../../Game.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class Kartu{
    
};

class AngkaCard : public Kartu {
    private:
        int angka;
        string warna;
    public:
        AngkaCard();
        AngkaCard(int, string);
        int getAngka() const;
        string getWarna() const;
        AngkaCard& operator=(const AngkaCard& );
        void setAngka(int a);
        void setWarna(string b);
        bool sameColour(const AngkaCard&);
        /*Hati-hati, == dan < atau > berbeda implementasinya
        == berdasarkan angka (not affected by colour)
        > dan < berdasarkan value (affected by colour)*/
        bool operator==(const AngkaCard&);
        bool operator<(const AngkaCard&);
        bool operator>(const AngkaCard&);
        friend std::ostream& operator<<(ostream& os,const AngkaCard&);
        friend std::ifstream& operator>>(ifstream& os, AngkaCard& inputan);
        void printValue();
        int priorityCardWarna() const{
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

        int priorityCardAngka() const{
            return this->angka*10;
        }

        int valuecard() const;        

        
};

class AbilityCard: public Kartu{
    private:
        int idAbility;
        string namaAbility;
    public:
        AbilityCard();
        AbilityCard(int id, string name);
        int getIdAbility();
        string getNamaAbility();
        void setAbility(int a);
        void SetNamaAbility(string b);
        
};

#endif

