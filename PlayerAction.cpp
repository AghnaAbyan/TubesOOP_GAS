#include "Game.hpp"

void Player::next()
{

}

void Player::reroll()
{
    /* Buang 2 kartu dari tangan */
    /* Ambil 2 kartu baru dari deck*/
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

    delete& card;
    Array<Kartu> *cards = new Array<Kartu>();



}

void Player::doublePoin()
{
    if (infoCardAbility.getNamaAbility() == "doublePoin")
    {
        cout << /* nama pemain*/ "melakukan DOUBLE! Poin hadiah naik dari " << Player::poin << " menjadi " << Player::poin * 2 << "!" << endl;
        poin = poin * 2;
    }   
}

void Player::quadruple()
{
    if (infoCardAbility.getNamaAbility() == "quadruple")
    {
        cout << /* nama pemain*/ "melakukan QUADRUPLE! Poin hadiah naik dari " << Player::poin << " menjadi " << Player::poin * 4 << "!" << endl;
        poin = poin * 4;
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
        cout << /* nama pemain*/ "melakukan HALF! Poin hadiah turun dari " << Player::poin << " menjadi " << Player::poin * 0.5 << "!" << endl;
        poin = poin * 0.5;
    }
    if (poin == 1)
    {
        cout << /* nama_pemain */ "melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
}

void Player::quarter()
{
    if (infoCardAbility.getNamaAbility() == "quarter")
    {
        cout << /* nama pemain*/ "melakukan QUARTER! Poin hadiah turun dari " << Player::poin << " menjadi " << Player::poin * 0.25 << "!" << endl;
        poin = poin * 0.25;
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
        cout << /*<nama_pemain>*/ "melakukan reverse!" << endl;
        cout << "(sisa) urutan eksekusi giliran ini : " /* Urutannya */ << endl;
        cout << "urutan eksekusi giliran selanjutnya : " /* Urutan baru */ << endl;
    }
    else
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE. Silahkan lakukan perintah lain." << endl;
    }
}

void Player::swapCard()
{
    /* Menukar salah satu kartu X dengan salah satu karty Y*/
    int chosenPlayer, chosenPlayer2;
    cout << /* nama pemain */ "melakukan SWAPCARD." << endl;
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
    for (int i = 0; i < playerSum(); i++ )
    {
        if (i != id)
        {
            cout << i << ". " << /* nama pemain */ endl;
        }
    }
    cin >> chosenPlayer;
    cout << endl;
    for (int i = 0; i < playerSum(); i++ )
    {
        if (i != id && i != chosenPlayer)
        {
            cout << i << ". " << /* nama pemain */ endl;
        }
    }
    cin >> chosenPlayer2;
    cout << endl;

    cout << "Silakan pilih kartu kanan/kiri " << chosenPlayer << ":";
    cout << "   1. Kanan";
    cout << "   2. Kiri";
    
    /* If kanan/kiri ambil */

    cout << "Silakan pilih kartu kanan/kiri " << chosenPlayer2 << ":";
    cout << "   1. Kanan";
    cout << "   2. Kiri";

    /* If kanan/kiri ambil */
}

void Player::switchCard()
{
    /* Menukar set kartu sendiri dengan set kartu lawan */
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