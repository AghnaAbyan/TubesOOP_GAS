#include "Game.hpp"

Game::Game():InventoryHolder(){
    string filename;
    cout << "File tumpukan kartu: " << endl;
    cin >> filename;
    

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

void Game::newRound(){
    if (InventoryHolder::round == 2){
        Array<AbilityCard> L; 
        AbilityCard a(1,"Reverse");
        AbilityCard b(2, "Re-Roll");
        AbilityCard c(3, "Quarter");
        AbilityCard d(4, "Reverse Direction");
        AbilityCard e(5, "Swap Card");
        AbilityCard f(6, "Switch");
        AbilityCard g(7, "Abilityless");

        L.addfirst(a);
        L.addfirst(b);
        L.addfirst(c);
        L.addfirst(d);
        L.addfirst(e);
        L.addfirst(f);
        L.addfirst(g);

        int M = rand()%6;
        players.get(0).setAbility(L.get(M));
        L.operator-(L.get(M));
        M = rand()%5;

        players.get(1).setAbility(L.get(M));
        L.operator-(L.get(M));
        M = rand()%4;

        players.get(2).setAbility(L.get(M));
        L.operator-(L.get(M));

        M = rand()%3;
        players.get(3).setAbility(L.get(M));
        L.operator-(L.get(M));

        M = rand()%2;
        players.get(4).setAbility(L.get(M));
        L.operator-(L.get(M));

        M = rand()%1;
        players.get(5).setAbility(L.get(M));
        L.operator-(L.get(M));

        M = 0;
        players.get(6).setAbility(L.get(M));
        L.operator-(L.get(M));
    }
}

void Game::showPoin(){
    cout << "Poin pemain saat ini: " << endl;
    for(int i = 0; i < players.size(); i++){
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players.get(i).getPoin() << endl;
    }
}

void Game::commandParser(int i, string command){
    if (command == "next"){
        players.get(i).next();
    }
    else if(command == "reroll"){
        players.get(i).reroll();
    }
    else if(command == "double"){
        players.get(i).doublePoin();
    }
    else if(command == "quadruple"){
        players.get(i).quadruple();
    }
    else if(command == "half"){
        players.get(i).half();
    }
    else if(command == "quarter"){
        players.get(i).quarter();
    }
    else if(command == "reverse"){
        players.get(i).reverse();
    }
    else if(command == "swap"){
        players.get(i).swapCard();
    }
    else if (command == "switch"){
        players.get(i).swapCard();
    }
    else if(command == "abilityless"){
        players.get(i).abilityless();
    }
    else{
        /* exception */
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

            // 
            string input;
            int cur;
            for(int i = 0; i < 7; i++){
                cur = (i+currentPlayerId)%7;
                cout << "Giliran <p" << cur << "> masukkan command: " << endl;
                cin >> input;
                commandParser(cur, input);
            }

            showPoin();
        }
    }
}

void Game::showUrutan(){
    for(int i = 0; i < 7; i++){
        cout << "<p" << (i+currentPlayerId)%7 << ">";
    }
}