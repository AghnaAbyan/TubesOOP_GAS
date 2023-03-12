#ifndef KARTU_H
#define KARTU_H
/* Nanti kalo kartu dah diimplementasiin ini hapus aja */
/* Ini buat implementasi sementara game aja ehehe */
/* Etapi kalo mau jadiin template hpp sabi */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Kartu{
    public:
        virtual bool operator== (const Kartu&);
};

class AngkaCard: public Kartu{
    private:
        int angka;
        string warna;
    public:
        int getAngka() const;
        string getWarna() const;
        AngkaCard& operator=(const AngkaCard& );
        bool operator==(const AngkaCard&);
        bool operator<(const AngkaCard&);
        bool operator>(const AngkaCard&);
        friend std::ostream& operator<<(ostream& os,const AngkaCard&);
        friend std::ifstream& operator>>(ifstream& os, AngkaCard& inputan);
        double priorityCardWarna() const{
            if(this->warna == "Merah"){
                return 0.09;
            }
            else if(this->warna == "Kuning"){
                return 0.06;
            }
            else if(this->warna == "Biru"){
                return 0.03;
            }
            else{
                return 0;
            }
        }

        double priorityCardAngka() const{
            return this->angka*0.1;
        }

        double valuecard() const;        

        
};

class AbilityCard: public Kartu{
    private:
        int idAbility;
        string namaAbility;
    public:
        int getIdAbility();
        string getNamaAbility();
        void virtual action();
};

#endif

