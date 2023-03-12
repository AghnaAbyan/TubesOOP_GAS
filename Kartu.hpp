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