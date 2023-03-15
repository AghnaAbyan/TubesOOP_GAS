#include "Game.hpp"

Game::Game():InventoryHolder(){
    // inisialissasi atribut
    gameDirection = 0;
    game = 1;
    round = 1;
    poinTotal = 0;

    // inisialisasi table
    TableCard *buf = new TableCard();
    table = *buf;

    // inisialisasi player
    players.clear();
    for(int i = 0; i < 7; i++){
        Player p(i);
        AngkaCard c1 = takeCardTable();
        AngkaCard c2 = takeCardTable();
        p.newCard(c1,c2);
    }
    firstPlayerId = 1;
    urutan.clear();
    for(int i = 1; i <= 7; i++){
        urutan.push_back(i);
    }
}


AngkaCard Game::takeCardTable(){
    return table.takeCard();
}

void Game::newRound(){
    // if (InventoryHolder::round == 2){
    //     Array<AbilityCard> L; 
    //     AbilityCard a(1,"Reverse");
    //     AbilityCard b(2, "Re-Roll");
    //     AbilityCard c(3, "Quarter");
    //     AbilityCard d(4, "Reverse Direction");
    //     AbilityCard e(5, "Swap Card");
    //     AbilityCard f(6, "Switch");
    //     AbilityCard g(7, "Abilityless");

    //     L.addfirst(a);
    //     L.addfirst(b);
    //     L.addfirst(c);
    //     L.addfirst(d);
    //     L.addfirst(e);
    //     L.addfirst(f);
    //     L.addfirst(g);

    //     int M = rand()%6;
    //     players.get(0).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    //     M = rand()%5;

    //     players.get(1).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    //     M = rand()%4;

    //     players.get(2).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%3;
    //     players.get(3).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%2;
    //     players.get(4).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = rand()%1;
    //     players.get(5).setAbility(L.get(M));
    //     L.operator-(L.get(M));

    //     M = 0;
    //     players.get(6).setAbility(L.get(M));
    //     L.operator-(L.get(M));
    // }
}

void Game::showPoin(){
    cout << "Poin pemain saat ini: " << endl;
    for(int i = 0; i < players.size(); i++){
        cout << i+1 << ". <p" << i+1 << "> memiliki poin " << players[i].getPoin() << endl;
    }
}

void Game::commandParser(int i, string command){
    // if (command == "next"){
    //     players.get(i).next();
    // }
    // else if(command == "reroll"){
    //     players.get(i).reroll(&table);
    // }
    // else if(command == "double"){
    //     players.get(i).doublePoin();
    // }
    // else if(command == "quadruple"){
    //     players.get(i).quadruple();
    // }
    // else if(command == "half"){
    //     players.get(i).half();
    // }
    // else if(command == "quarter"){
    //     players.get(i).quarter();
    // }
    // else if(command == "reverse"){
    //     players.get(i).reverse();
    // }
    // else if(command == "swap"){
    //     players.get(i).swapCard(&players);
    // }
    // else if (command == "switch"){
    //     players.get(i).swapCard(&players);
    // }
    // else if(command == "abilityless"){
    //     players.get(i).abilityless();
    // }
    // else{
    //     /* exception */
    // }
}

void Game::start(){
    cout << "START" << endl;
    // isi table
    table.resetNewGame();
    setTable();

    while (!endGame()){
        setTable();
        while (round <= 6){
            cout << "Sekarang adalah permainan ke " << game << " ronde ke " << round << "." << endl;
            cout << "Putaran permainan: ";
            showUrutan();

            // iterasi command tiap pemain
            int i = 0;
            while(i < 7){
                if (round == 6){
                    showMain(5);
                }
                else{
                    showMain(round);
                }
                cout << "Giliran pemain <p" << urutan[i] << "> !" << endl;
                cout << "Kartu yang anda miliki: " << endl;
                players[urutan[i]].displayCard();
                cout << "Masukkan command Anda: ";
                // lakukan command, jangan lupa exception
                // kalau ada efek reverse sekalian panggil reverseEffect(int urutan[i])


                i++;
            }
            // atur urutan lagi
            urutan.clear();
            firstPlayerId = (firstPlayerId+1)%7;
            if(gameDirection == 0){
                for(int i = 0; i < 7; i++){
                    urutan.push_back((firstPlayerId+i) % 7);
                }
            }
            else{
                for(int i = 7; i <= 0; i--){
                    urutan.push_back((firstPlayerId+i) % 7);
                }
            }
            round++;
        }
        // akumulasikan poin pemain ke poin total
        for(int i = 0; i < players.size(); i++){
            poinTotal = poinTotal + players[i].getPoin();
        }
        // cari pemenang
        

        // berikan poin total pada pemenang
        int id; // .....
        players[id-1].addPoin(poinTotal);
        
        // reset untuk game berikutnya
        for(int i = 0; i < players.size(); i++){
            players[i].resetNewGame();
        }
        poinTotal = 0;
        table.resetNewGame();
        round = 1;
        game++;
        
    }
}

void Game::showUrutan(){
    for(int i = 0; i < urutan.size(); i++){
        cout << "<p" << urutan[i] << "> ";
    }
    cout << endl;
}

bool Game::endGame(){
    bool end = false;
    while(!end){
        for(int i = 0; i < players.size(); i++){
            if(players[i].getPoin() >= pow(2,32)){
                end = true;
            }
        }
    }
    return end;
}

void Game::showMain(int N){
    cout << "Kartu pada meja sekarang: " << endl;
    table.showInRound(N);
}

void Game::reverseEffect(int currPlayer){
    vector<int> buff;
    for(int i = 0; i < currPlayer; i++){
        buff.push_back(urutan[i]);
        urutan.erase(urutan.begin());
    }
    while(!urutan.empty()){
        buff.push_back(urutan.size()-1);
        urutan.pop_back();
    }
}

void Game::setTable(){
    cout << "Tumpukan kartu pakai randomizer atau file?" << endl;
    cout << "1. Randomizer" << endl << "2. File" << endl;
    bool valid = false;
    char inp;
    while(!valid){
        try{
            cout << "Masukkan pilihan: ";
            cin >> inp;
            if (inp != '1' && inp != '2'){
                throw "Input tidak valid";
            }
            else{
                valid = true;
            }
        }
        catch(string e){
            cout << e << endl;
        }
    }
    cout << endl;
    if (inp == '1'){
        table.randomTableDeck();
    }
    else{
        cout << "Masukkan nama file: " << endl;
        // exception ....
        string filename;
        table.readFileTumpukan(filename);
    }
}