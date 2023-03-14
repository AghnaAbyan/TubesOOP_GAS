#include "Game.hpp"

void Player::next()
{
    //Nothing
}

void Player::reroll(TableCard *table)
{
    /* Buang 2 kartu dari tangan */
    /* Ambil 2 kartu baru dari deck*/
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

    card.operator--();
    card.operator--();
    AngkaCard c1 = table->takeCard();
    AngkaCard c2 = table->takeCard();
    card+c1;
    card+c2;

    cout << "1. " << c1.getAngka() << " " << c1.getWarna() << endl;
    cout << "2. " << c2.getAngka() << " " << c2.getWarna() << endl;
}

void Player::doublePoin()
{
    if (infoCardAbility.getNamaAbility() == "doublePoin")
    {
        poinTotal = poinTotal * 2;
        cout << this->id << "melakukan DOUBLE! Poin hadiah naik  " << " menjadi " << poinTotal << "!" << endl;
    }   
}

void Player::quadruple()
{
    if (infoCardAbility.getNamaAbility() == "quadruple")
    {
        poinTotal = poinTotal*4;
        cout << this->id << "melakukan QUADRUPLE! Poin hadiah naik " << " menjadi " << poinTotal << "!" << endl;
    }
    else
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
        /* Pemain tetap main */
    }
}

void Player::half()
{
    if (infoCardAbility.getNamaAbility() == "half")
    {
        poinTotal = poinTotal * 0.5;
        cout << this->id << "melakukan HALF! Poin hadiah turun " << " menjadi " << poinTotal << "!" << endl;
    }
    if (poin == 1)
    {
        cout << this->id << "melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
}

void Player::quarter()
{
    if (infoCardAbility.getNamaAbility() == "quarter")
    {
        poinTotal = poinTotal * 0.25;
        cout << this->id << "melakukan QUARTER! Poin hadiah turun "  << " menjadi " << poinTotal << "!" << endl;
    }
    else
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER.";
        /* Pemain tetap main */
    }
}

void Player::reverse()
{
    if (infoCardAbility.getNamaAbility() == "reverse")
    {
        InventoryHolder::changeDirection();
        cout << this->id << "melakukan reverse!" << endl;
        cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
        cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
    }
    else
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE. Silahkan lakukan perintah lain." << endl;
    }
}

void Player::swapCard(Array<Player> *players)
{
   /* Menukar salah satu kartu X dengan salah satu karty Y*/
    int chosenPlayer, chosenPlayer2;
    cout << this->id <<  "melakukan SWAPCARD." << endl;
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
    for (int i = 0; i < playerSum(); i++ )
    {
        if (i != id)
        {
            cout << i << ". " << this->id << endl;
        }
    }
    cin >> chosenPlayer;
    cout << endl;
    for (int i = 0; i < playerSum(); i++ )
    {
        if (i != id && i != chosenPlayer)
        {
            cout << i << ". " << this->id << endl;
        }
    }
    cin >> chosenPlayer2;
    cout << endl;
    int input;
    AngkaCard val;
    Player a = players->get(chosenPlayer);
    Player b = players->get(chosenPlayer2);
    cout << "Silakan pilih kartu kanan/kiri " << chosenPlayer << ":";
    cout << "   1. Kanan";
    cout << "   2. Kiri";
    cin >> input;
    if(input == 1){
        val = a.card.get(0);
    }
    else if(input == 2){
        val = a.card.get(1);
    }
    
    AngkaCard val2;
    int input2;
    cin >> input2;
    cout << "Silakan pilih kartu kanan/kiri " << chosenPlayer2 << ":";
    cout << "   1. Kanan";
    cout << "   2. Kiri";
    if(input == 1){
        val2 = b.card.get(0);
    }
    else if(input == 2){
        val2 = b.card.get(1);
    }

    //Input AngkaCard val2 ke chosenPlayer 1
    a.card-val;
    a.card+val2;
    b.card-val2;
    b.card+val2;
}

void Player::switchCard(Array<Player> *players)
{
    cout << " Pilih player yang ingin kamu tukar kartunya : " << endl;
    int input; 
    cin >> input;
    Player a = players->get(input);
    AngkaCard val1 = card.get(0);
    AngkaCard val2 = card.get(1);
    AngkaCard val3 = a.card.get(0);
    AngkaCard val4 = a.card.get(1);

    card-val1;
    card-val2;
    card+val3;
    card+val4;

    a.card-val3;
    a.card-val4;
    a.card+val1;
    a.card+val2;
}

void Player::abilityless()
{
    /* CASE 1 */
    int chosenPlayer;
    cout << /* nama pemain */ "akan mematikan kartu ablity lawan!" << endl;
    cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
    for (int i = 0; i < playerSum(); i++)
    {
        if (i != id)
        {
            cout << i << ". " << /* nama pemain */ endl;
        }
    }
    cin >> chosenPlayer;
    cout << endl;
    cout << "Kartu ability " << /*nama pemain*/ "telah dimatikan." << endl;

    /* CASE 2 */

    /* CASE 3 */
    if (infoCardAbility.getNamaAbility() != "abilityless")
    {
        cout << "Eits, kamu tidak punya kartunya 😛" << endl;
    }

}