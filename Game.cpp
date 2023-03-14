#include "Game.hpp"

Game::Game():InventoryHolder(){
    //inisialisasi table
    TableCard *buf = new TableCard();
    table = *buf;

    // inisialisasi player
    Array<Player> *buff = new Array<Player>();
        players = *buff;
    for(int i = 1; i <= 7; i++){
        Player p(i);
        AngkaCard c1 = table.takeCard();
        AngkaCard c2 = table.takeCard();
        // tambahin kartu dari tumpukan
        p.newCard(c1,c2);
        players+p;
    }
    currentPlayerId = 1;
}

void Game::showPoin(){
    for(int i = 0; i < players.size(); i++){
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players.get(i).getPoin() << endl;
    }
}

void Game::commandParser(int i, string command){
    if (command == "next"){
        
    }
}

void Game::start(){
    cout << "START" << endl;
    newGame();
    newRound();
    while (InventoryHolder::game <= 6){
        while (InventoryHolder::round <= 7){
            cout << "Sekarang adalah permainan ke " << InventoryHolder::game << " ronde ke " << InventoryHolder::round << "." << endl;
            cout << "Putaran permainan: ";
            for(int i = 0; i < 7; i++){
                cout << "<p" << (i+currentPlayerId)%7 << ">";
            }
            cout << endl;

            string input;
            for(int i = 0; i < 7; i++){
                cout << "Giliran <p" << (i+currentPlayerId)%7 << "> masukkan command: " << endl;
                cin >> input;

            }
        }
    }
}