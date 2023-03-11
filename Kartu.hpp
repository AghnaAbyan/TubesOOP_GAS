/* Nanti kalo kartu dah diimplementasiin ini hapus aja */
/* Ini buat implementasi sementara game aja ehehe */
/* Etapi kalo mau jadiin template hpp sabi */
#include <iostream>
#include <string>
using namespace std;

class Kartu{
    public:
        virtual int value() = 0;
};

class Angka: public Kartu{
    private:
        int angka;
        string warna;
    public:
        int getAngka();
        string getWarna();
};

class Ability: public Kartu{
    private:
        int idAbility;
        string namaAbility;
    public:
        int getIdAbility();
        string getNamaAbility();
};