/* Nanti kalo kartu dah diimplementasiin ini hapus aja */
/* Ini buat implementasi sementara game aja ehehe */
/* Etapi kalo mau jadiin template hpp sabi */
#include <iostream>
#include <string>
using namespace std;

class Kartu{
    public:
        virtual int value() = 0;
        virtual bool operator= (const Kartu&);
        virtual bool operator== (const Kartu&);
};

class AngkaCard: public Kartu{
    private:
        int angka;
        string warna;
    public:
        int getAngka();
        string getWarna();
        int value();
        bool operator= (const Kartu&);
        bool operator== (const Kartu&);
        bool operator< (const Kartu&);
        bool operator> (const Kartu&);
        float priorityCardWarna(){
            if(this->warna == "Merah"){
                return 0.19;
            }
            else if(this->warna == "Kuning"){
                return 0.16;
            }
            else if(this->warna == "Biru"){
                return 0.13;
            }
            else{
                return 0.1;
            }
        }

        float priorityCardAngka(){
            return this->angka*0.1;
        }

        float valuecard(){
            return priorityCardAngka()+priorityCardWarna();
        }
};

class AbilityCard: public Kartu{
    private:
        int idAbility;
        string namaAbility;
    public:
        int getIdAbility();
        string getNamaAbility();
        int value();
};